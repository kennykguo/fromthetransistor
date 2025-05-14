// Pseudocode - create your own implementation
module uart_rx(
    input clk,           // Oversampled baud clock (typically 16x)
    input rx,            // RX line
    output reg [7:0] data,    // Received data
    output reg data_valid     // Indicates new data available
);
    // States: IDLE, START_BIT, DATA_BITS, STOP_BIT
    
    // Implement state machine to:
    // 1. Monitor for start bit (falling edge)
    // 2. Sample in middle of each bit time 
    // 3. Collect 8 data bits
    // 4. Verify stop bit
    // 5. Assert data_valid when complete

endmodule