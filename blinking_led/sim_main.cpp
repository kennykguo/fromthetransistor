#include "Vblinking_led.h"  // generated header from verilating "blinking_led.v"
#include "verilated.h"    // basic verilator header
#include "verilated_vcd_c.h" // needed for VCD waveform trace
#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
    // initialize verilator
    Verilated::commandArgs(argc, argv);
    
    // create context for waveform tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    
    // create instance of our design
    Vblinking_led* top = new Vblinking_led;
    
    // initialize VCD tracing and open VCD file
    top->trace(tfp, 99);  // trace 99 levels of hierarchy
    tfp->open("waveform.vcd");
    
    // initialize simulation inputs
    top->clk = 0;
    
    // simulation time (much shorter than the real counter for demonstration)
    const int sim_time = 200;
    
    // simulation variables
    int tick = 0;
    int last_led_state = top->led;
    
    // simulation loop
    for (int i = 0; i < sim_time; i++) {
        // dump variables into VCD file
        tfp->dump(i);
        
        // toggle clock
        top->clk = !top->clk;
        
        // evaluate model
        top->eval();
        
        // check for changes to led state (only on positive clock edge)
        if (top->clk && top->led != last_led_state) {
            std::cout << "Time " << std::setw(3) << i 
                      << ": LED changed to " << (top->led ? "ON" : "OFF") 
                      << std::endl;
            last_led_state = top->led;
        }
        
        // print simulation ticks (only on positive edges)
        if (top->clk) {
            tick++;
            if (tick % 10 == 0) {
                // visual representation of LED state
                char led_visual = top->led ? '*' : ' ';
                std::cout << "Tick " << std::setw(3) << tick 
                          << ": [" << led_visual << "]" << std::endl;
            }
        }
    }
    
    // clean up
    tfp->close();
    delete tfp;
    delete top;
    
    return 0;
}