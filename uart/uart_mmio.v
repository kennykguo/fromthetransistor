// Pseudocode - design your own interface
module uart_mmio(
    input clk,
    input reset,
    
    // Bus interface
    input [ADDR_WIDTH-1:0] addr,
    input [DATA_WIDTH-1:0] write_data,
    input write_enable,
    input read_enable,
    output reg [DATA_WIDTH-1:0] read_data,
    
    // UART signals
    input [7:0] rx_data,
    input rx_data_valid,
    output [7:0] tx_data,
    output tx_data_valid,
    input tx_busy
);
    // Register map:
    // 0x00: Status register (read-only)
    // 0x04: Data register (write: transmit, read: receive)
    // 0x08: Control register
    
    // Implement register read/write logic

endmodule
