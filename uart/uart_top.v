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

    // uart_mmio - handles the register interface
    // uart_tx - transmits data
    // uart_rx - receives data
    // baud_rate_generator - creates timing signals
    

    uart_rx(
        input clk, // oversampled baud clock (typically 16x)
        input rx, // RX line
        output reg [7:0] data, // received data
        output reg data_valid // indicates new data available
    );

    uart_tx(
        input clk,           // Baud rate clock
        input [7:0] data,    // Data to send
        input data_valid,    // Signal to start transmission
        output reg tx,       // TX line
        output reg tx_busy   // Indicates transmission in progress
    );
    

endmodule
