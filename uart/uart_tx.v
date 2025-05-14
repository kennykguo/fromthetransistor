// Pseudocode - implement your own logic
module uart_tx(
    input clk,           // Baud rate clock
    input [7:0] data,    // Data to send
    input data_valid,    // Signal to start transmission
    output reg tx,       // TX line
    output reg tx_busy   // Indicates transmission in progress
);
    // States: IDLE, START_BIT, DATA_BITS, STOP_BIT
    
    // Implement state machine to:
    // 1. Wait for data_valid in IDLE
    // 2. Send start bit (logic 0)
    // 3. Send 8 data bits LSB first
    // 4. Send stop bit (logic 1)
    // 5. Return to IDLE

endmodule
