// Pseudocode - implement the top-level structure yourself from skeleton code
module uart_top(
    input clk,
    input reset,
    input [32-1:0] addr,
    input [8-1:0] write_data,
    input write_enable,
    output [8-1:0] read_data,
    input read_enable
);
    wire tx_busy; // driven by uart_tx, used by uart_mmio
    wire [7:0] rx_data; // driven by uart_rx, used by uart_mmio  
    wire rx_data_valid; // driven by uart_rx, used by uart_mmio
    wire [7:0] tx_data; // driven by uart_mmio, used by by uart_tx
    wire tx_data_valid; // driven by uart_mmio, used by by uart_tx
    wire tx, rx;
    assign rx = tx; // drive eachother - loopback connection

    // uart_tx - transmits data
    // uart_mmio - handles the register interface
    // uart_rx - receives data
    uart_tx uart_tx_inst(
    .clk(clk),
    .data(tx_data),
    .data_valid(tx_data_valid),
    .tx(tx),
    .tx_busy(tx_busy)
    );

    uart_mmio uart_mmio_inst(
        .clk(clk),
        .reset(reset),
        .addr(addr),
        .write_data(write_data),
        .write_enable(write_enable),
        .read_data(read_data),
        .read_enable(read_enable),
        .rx_data(rx_data),
        .rx_data_valid(rx_data_valid),
        .tx_data(tx_data),
        .tx_data_valid(tx_data_valid),
        .tx_busy(tx_busy)
    );

    uart_rx uart_rx_inst(
        .clk(clk),
        .rx(rx),
        .data(rx_data),
        .data_valid(rx_data_valid)
    );
    

endmodule
