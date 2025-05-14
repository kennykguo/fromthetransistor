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

    // create instance of blinkingled design
    // verilator expects header as V<module_name>.h, importing the module directly as the name suggets
    VerilatedVcdC* tfp = new VerilatedVcdC;
    Vblinking_led* top = new Vblinking_led;
    
    // initialize VCD tracing and open VCD file
    top->trace(tfp, 99);  // trace 99 levels of hierarchy
    tfp->open("waveform.vcd");
    
    // initialize simulation inputs
    // simulation time
    // simulation variables
    top->clk = 0;
    const int sim_time = 200;
    int tick = 0;
    int last_led_state = top->led;
    
    // simulation loop
    for (int i = 0; i < sim_time; i++) {
        // dump variables into VCD file
        tfp->dump(i);
        
        // toggle clock
        top->clk = !top->clk;
        
        // evaluate model (check the signals again)
        top->eval();
        
        // check for changes to led state (only on positive clock edge)
        if (top->clk && top->led != last_led_state) {
            std::cout << "time " << std::setw(3) << i  << ": LED changed to " << (top->led ? "ON" : "OFF")  << std::endl;
            last_led_state = top->led;
        }
        
        // print simulation ticks (only on positive edges)
        if (top->clk) {
            tick++;
            if (tick % 1 == 0) {
                // visual representation of LED state
                char led_visual = top->led ? '*' : ' ';
                std::cout << "tick " << std::setw(3) << tick  << ": [" << led_visual << "]" << std::endl;
            }
        }
    }
    // clean up
    tfp->close();
    delete tfp;
    delete top;
    
    return 0;
}