#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vuart_rx.h"
#include <iostream>
#include <bitset>

class UartTester {
private:
    Vuart_rx* dut;
    VerilatedVcdC* tfp;
    uint64_t sim_time;
    
    // uart timing parameters
    static const int BAUD_DIVISOR = 326;  // 50mhz / (9600 * 16)
    static const int SAMPLES_PER_BIT = 16;
    static const int CLOCKS_PER_BIT = BAUD_DIVISOR * SAMPLES_PER_BIT;
    
public:
    UartTester() {
        dut = new Vuart_rx;
        Verilated::traceEverOn(true);
        tfp = new VerilatedVcdC;
        dut->trace(tfp, 99);
        tfp->open("uart_rx_trace.vcd");
        sim_time = 0;
        
        // initialize signals - uart idle state is high
        dut->clk = 0;
        dut->rx = 1;  // idle high
        dut->eval();
    }
    
    ~UartTester() {
        tfp->close();
        delete dut;
        delete tfp;
    }
    
    void clock_tick() {
        // rising edge
        dut->clk = 1;
        dut->eval();
        tfp->dump(sim_time++);
        
        // falling edge  
        dut->clk = 0;
        dut->eval();
        tfp->dump(sim_time++);
    }
    
    void send_uart_byte(uint8_t byte_to_send) {
        std::cout << "sending byte: 0x" << std::hex << (int)byte_to_send 
                  << " (0b" << std::bitset<8>(byte_to_send) << ")" << std::endl;
        
        // start bit - drive rx low
        std::cout << "start bit: driving rx low" << std::endl;
        dut->rx = 0;
        for(int i = 0; i < CLOCKS_PER_BIT; i++) {
            clock_tick();
        }
        
        // send 8 data bits (lsb first)
        for(int bit = 0; bit < 8; bit++) {
            bool bit_value = (byte_to_send >> bit) & 1;
            std::cout << "data bit " << bit << ": " << (bit_value ? "1" : "0") << std::endl;
            dut->rx = bit_value ? 1 : 0;
            for(int i = 0; i < CLOCKS_PER_BIT; i++) {
                clock_tick();
            }
        }
        
        // stop bit - drive rx high
        std::cout << "stop bit: driving rx high" << std::endl;
        dut->rx = 1;
        for(int i = 0; i < CLOCKS_PER_BIT; i++) {
            clock_tick();
            // check for data_valid assertion during stop bit
            if(dut->data_valid) {
                std::cout << "data_valid asserted! received: 0x" << std::hex 
                         << (int)dut->data << " (0b" << std::bitset<8>(dut->data) << ")" << std::endl;
            }
        }
        
        // additional idle time
        for(int i = 0; i < CLOCKS_PER_BIT; i++) {
            clock_tick();
        }
    }
    
    void run_tests() {
        std::cout << "=== uart rx testbench ===" << std::endl;
        std::cout << "clock frequency: 50mhz" << std::endl;
        std::cout << "baud rate: 9600" << std::endl;
        std::cout << "oversampling: 16x" << std::endl;
        std::cout << "clocks per bit: " << CLOCKS_PER_BIT << std::endl << std::endl;
        
        // initial idle period
        for(int i = 0; i < 1000; i++) {
            clock_tick();
        }
        
        // test various byte patterns
        send_uart_byte(0x55);  // alternating pattern 01010101
        send_uart_byte(0xaa);  // alternating pattern 10101010  
        send_uart_byte(0x00);  // all zeros
        send_uart_byte(0xff);  // all ones
        send_uart_byte(0x42);  // ascii 'b'
        
        // final idle period
        for(int i = 0; i < 1000; i++) {
            clock_tick();
        }
        
        std::cout << "test complete. check uart_rx_trace.vcd for timing analysis" << std::endl;
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    UartTester tester;
    tester.run_tests();
    
    return 0;
}