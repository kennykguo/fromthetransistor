#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vuart_tx.h"
#include <iostream>
#include <bitset>
#include <vector>

class UartTxTester {
private:
    Vuart_tx* dut;
    VerilatedVcdC* tfp;
    uint64_t sim_time;
    
    // uart timing parameters - match the receiver configuration
    static const int BAUD_DIVISOR = 326;  // 50mhz / (9600 * 16)
    static const int SAMPLES_PER_BIT = 16;
    static const int CLOCKS_PER_BIT = BAUD_DIVISOR * SAMPLES_PER_BIT;  // 5216 clocks per bit
    
    // transmission monitoring state
    bool in_transmission;
    int bit_clock_counter;
    int current_bit_index;
    uint8_t received_byte;
    uint8_t expected_byte;
    std::vector<bool> captured_bits;
    
public:
    UartTxTester() {
        dut = new Vuart_tx;
        Verilated::traceEverOn(true);
        tfp = new VerilatedVcdC;
        dut->trace(tfp, 99);
        tfp->open("uart_tx_trace.vcd");
        sim_time = 0;
        
        // initialize signals
        dut->clk = 0;
        dut->data = 0;
        dut->data_valid = 0;
        dut->eval();
        
        // initialize monitoring state
        in_transmission = false;
        bit_clock_counter = 0;
        current_bit_index = -1;  // -1 = waiting for start bit
        received_byte = 0;
        expected_byte = 0;
        captured_bits.clear();
    }
    
    ~UartTxTester() {
        tfp->close();
        delete dut;
        delete tfp;
    }
    
    void clock_tick() {
        // rising edge
        dut->clk = 1;
        dut->eval();
        tfp->dump(sim_time++);
        
        // monitor tx output during rising edge
        monitor_uart_output();
        
        // falling edge  
        dut->clk = 0;
        dut->eval();
        tfp->dump(sim_time++);
    }
    
    void monitor_uart_output() {
        // sample tx line at the center of each bit period for verification
        if (in_transmission) {
            bit_clock_counter++;
            
            // sample at the center of the bit period (like the receiver would)
            if (bit_clock_counter == CLOCKS_PER_BIT / 2) {
                bool bit_value = dut->tx;
                captured_bits.push_back(bit_value);
                
                if (current_bit_index == -1) {
                    // expecting start bit
                    if (!bit_value) {
                        std::cout << "detected start bit: 0" << std::endl;
                        current_bit_index = 0;
                    } else {
                        std::cout << "error: expected start bit (0), got " << bit_value << std::endl;
                    }
                } else if (current_bit_index < 8) {
                    // data bits (lsb first)
                    std::cout << "data bit " << current_bit_index << ": " << bit_value << std::endl;
                    if (bit_value) {
                        received_byte |= (1 << current_bit_index);
                    }
                    current_bit_index++;
                } else if (current_bit_index == 8) {
                    // stop bit
                    if (bit_value) {
                        std::cout << "detected stop bit: 1" << std::endl;
                        std::cout << "received byte: 0x" << std::hex << (int)received_byte 
                                 << " (0b" << std::bitset<8>(received_byte) << ")" << std::endl;
                        std::cout << "expected byte: 0x" << std::hex << (int)expected_byte 
                                 << " (0b" << std::bitset<8>(expected_byte) << ")" << std::endl;
                        
                        if (received_byte == expected_byte) {
                            std::cout << "✓ transmission successful!" << std::endl;
                        } else {
                            std::cout << "✗ transmission error!" << std::endl;
                        }
                    } else {
                        std::cout << "error: expected stop bit (1), got " << bit_value << std::endl;
                    }
                    
                    // reset for next transmission
                    in_transmission = false;
                    current_bit_index = -1;
                    received_byte = 0;
                }
            }
            
            // advance to next bit period
            if (bit_clock_counter >= CLOCKS_PER_BIT) {
                bit_clock_counter = 0;
            }
        } else {
            // not in transmission - check for start bit
            if (!dut->tx && dut->tx_busy) {
                std::cout << "starting transmission detection" << std::endl;
                in_transmission = true;
                bit_clock_counter = 0;
                current_bit_index = -1;
                received_byte = 0;
                captured_bits.clear();
            }
        }
    }
    
    void send_byte(uint8_t byte_to_send) {
        expected_byte = byte_to_send;
        std::cout << "\n=== sending byte: 0x" << std::hex << (int)byte_to_send 
                  << " (0b" << std::bitset<8>(byte_to_send) << ") ===" << std::endl;
        
        // wait for tx to be not busy
        while (dut->tx_busy) {
            clock_tick();
        }
        
        // assert data_valid with data for one clock cycle
        dut->data = byte_to_send;
        dut->data_valid = 1;
        clock_tick();
        
        // deassert data_valid
        dut->data_valid = 0;
        clock_tick();
        
        // monitor tx_busy signal timing
        if (!dut->tx_busy) {
            std::cout << "error: tx_busy should be asserted after data_valid" << std::endl;
        } else {
            std::cout << "tx_busy asserted correctly" << std::endl;
        }
        
        // wait for transmission to complete
        while (dut->tx_busy) {
            clock_tick();
        }
        
        std::cout << "transmission complete, tx_busy deasserted" << std::endl;
        
        // add some idle time between transmissions
        for (int i = 0; i < CLOCKS_PER_BIT; i++) {
            clock_tick();
        }
    }
    
    void run_tests() {
        std::cout << "=== uart tx testbench ===" << std::endl;
        std::cout << "clock frequency: 50mhz" << std::endl;
        std::cout << "baud rate: 9600" << std::endl;
        std::cout << "oversampling factor: 16x" << std::endl;
        std::cout << "clocks per bit: " << CLOCKS_PER_BIT << std::endl << std::endl;
        
        // initial idle period
        for (int i = 0; i < 1000; i++) {
            clock_tick();
        }
        
        // verify initial state
        if (dut->tx != 1) {
            std::cout << "error: tx should be high in idle state" << std::endl;
        }
        if (dut->tx_busy != 0) {
            std::cout << "error: tx_busy should be low in idle state" << std::endl;
        }
        
        // test various byte patterns
        send_byte(0x55);  // alternating pattern 01010101
        send_byte(0xaa);  // alternating pattern 10101010  
        send_byte(0x00);  // all zeros
        send_byte(0xff);  // all ones
        send_byte(0x42);  // ascii 'b'
        send_byte(0xa5);  // pattern 10100101
        
        // final idle period
        for (int i = 0; i < 1000; i++) {
            clock_tick();
        }
        
        std::cout << "\ntest complete. check uart_tx_trace.vcd for detailed timing analysis" << std::endl;
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    UartTxTester tester;
    tester.run_tests();
    
    return 0;
}