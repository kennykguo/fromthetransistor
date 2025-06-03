#include <iostream>
#include <string>
#include <verilated.h>
#include "Vuart_top.h"  // verilator generates this from your uart_top.v

class UARTTestbench {
private:
    Vuart_top* uart;        // verilator-generated class for your uart_top module
    uint64_t cycle_count;   // track simulation time
    
    // register addresses matching your uart_mmio implementation
    static const uint32_t STATUS_REG = 0x00;
    static const uint32_t DATA_REG = 0x04;
    
    // advance simulation by one clock cycle
    void tick() {
        uart->clk = 0;
        uart->eval();       // evaluate combinational logic
        uart->clk = 1; 
        uart->eval();       // evaluate on rising edge
        cycle_count++;
    }
    
    // write a byte to specified register address
    void write_register(uint32_t addr, uint8_t data) {
        uart->addr = addr;
        uart->write_data = data;
        uart->write_enable = 1;
        uart->read_enable = 0;
        tick();                    // perform the write on rising edge
        uart->write_enable = 0;    // clear write strobe
        tick();                    // complete the transaction
    }
    
    // read a byte from specified register address
    uint8_t read_register(uint32_t addr) {
        uart->addr = addr;
        uart->write_enable = 0;
        uart->read_enable = 1;
        tick();                    // perform the read on rising edge
        uint8_t result = uart->read_data;
        uart->read_enable = 0;     // clear read strobe
        tick();                    // complete the transaction
        return result;
    }
    
    // check if transmitter is ready for new data
    bool tx_ready() {
        uint8_t status = read_register(STATUS_REG);
        return (status & 0x01) != 0;  // bit 0 = tx_available
    }
    
    // check if received data is available
    bool rx_available() {
        uint8_t status = read_register(STATUS_REG);
        return (status & 0x02) != 0;  // bit 1 = rx_data_available
    }
    
    // send a byte through uart (with flow control)
    void send_byte(uint8_t data) {
        // wait for transmitter to be ready
        while (!tx_ready()) {
            tick();  // keep clocking until space available
        }
        write_register(DATA_REG, data);
        std::cout << "sent: 0x" << std::hex << (int)data 
                  << " ('" << (char)data << "')" << std::endl;
    }
    
    // receive a byte from uart (with timeout)
    uint8_t receive_byte(int timeout_cycles = 100000) {
        int wait_count = 0;
        // wait for data to arrive
        while (!rx_available() && wait_count < timeout_cycles) {
            tick();
            wait_count++;
        }
        
        if (wait_count >= timeout_cycles) {
            std::cout << "timeout waiting for rx data!" << std::endl;
            return 0;
        }
        
        uint8_t data = read_register(DATA_REG);
        std::cout << "received: 0x" << std::hex << (int)data 
                  << " ('" << (char)data << "')" << std::endl;
        return data;
    }

public:
    UARTTestbench() {
        // verilator initialization - creates the uart_top instance
        uart = new Vuart_top;
        cycle_count = 0;
        
        // start with reset asserted
        uart->reset = 1;
        uart->clk = 0;
        uart->addr = 0;
        uart->write_data = 0;
        uart->write_enable = 0;
        uart->read_enable = 0;
        
        // hold reset for several cycles
        for (int i = 0; i < 10; i++) {
            tick();
        }
        
        // release reset and let system stabilize
        uart->reset = 0;
        for (int i = 0; i < 10; i++) {
            tick();
        }
        
        std::cout << "uart testbench initialized" << std::endl;
    }
    
    ~UARTTestbench() {
        delete uart;  // cleanup verilator-generated object
    }
    
    // test sending and receiving a single character
    void test_single_char(char c) {
        std::cout << "\n--- testing character: '" << c << "' ---" << std::endl;
        send_byte((uint8_t)c);
        
        // wait for transmission to complete and data to be received
        // uart operates at 9600 baud: 10 bits × 16 samples × 326 cycles = 52,160 cycles per frame
        // add extra margin for safety
        for (int i = 0; i < 60000; i++) {
            tick();
        }
        
        uint8_t received = receive_byte();
        
        if (received == (uint8_t)c) {
            std::cout << "✓ loopback successful!" << std::endl;
        } else {
            std::cout << "✗ loopback failed! expected: " << c 
                      << ", got: " << (char)received << std::endl;
        }
    }
    
    // test sending an entire string
    void test_string(const std::string& message) {
        std::cout << "\n--- testing string: \"" << message << "\" ---" << std::endl;
        
        // send each character
        for (char c : message) {
            send_byte((uint8_t)c);
            // give uart time to transmit and receive each byte  
            // uart frame takes ~52,160 cycles, add margin for safety
            for (int i = 0; i < 60000; i++) {
                tick();
            }
        }
        
        // receive and verify each character
        std::string received = "";
        for (size_t i = 0; i < message.length(); i++) {
            uint8_t byte = receive_byte();
            received += (char)byte;
        }
        
        std::cout << "sent:     \"" << message << "\"" << std::endl;
        std::cout << "received: \"" << received << "\"" << std::endl;
        
        if (received == message) {
            std::cout << "✓ string loopback successful!" << std::endl;
        } else {
            std::cout << "✗ string loopback failed!" << std::endl;
        }
    }
    
    // interactive mode - type characters and see them loop back
    void interactive_mode() {
        std::cout << "\n--- interactive mode ---" << std::endl;
        std::cout << "type characters and press enter (or 'quit' to exit):" << std::endl;
        
        std::string input;
        while (std::getline(std::cin, input) && input != "quit") {
            for (char c : input) {
                send_byte((uint8_t)c);
                // wait for complete transmission and reception
                for (int i = 0; i < 60000; i++) {
                    tick();
                }
                receive_byte();
            }
            std::cout << "type more (or 'quit'):" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    // verilator setup - parse command line arguments
    Verilated::commandArgs(argc, argv);
    
    std::cout << "uart loopback testbench starting..." << std::endl;
    
    // create testbench instance
    UARTTestbench testbench;
    
    // run basic tests
    testbench.test_single_char('A');
    testbench.test_single_char('x'); 
    testbench.test_single_char('7');
    
    // test string transmission
    testbench.test_string("Hello");
    testbench.test_string("UART!");
    testbench.test_string("123456");
    
    // interactive mode for real-time testing
    testbench.interactive_mode();
    
    std::cout << "testbench complete!" << std::endl;
    return 0;
}