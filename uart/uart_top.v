// Pseudocode - implement your own top-level structure
module uart_top(
    input clk,
    input reset,
    
    // Bus interface
    input [ADDR_WIDTH-1:0] addr,
    input [DATA_WIDTH-1:0] write_data,
    input write_enable,
    input read_enable,
    output [DATA_WIDTH-1:0] read_data,
    
    // UART external pins
    output tx,
    input rx
);
    // Instantiate and connect submodules

endmodule
