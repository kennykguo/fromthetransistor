// TX pin of UART

// assuming a 50mhz clock, and 9600 baud rate config
module uart_tx(
    input clk,           // Baud rate clock
    input [7:0] data,    // Data to send
    input data_valid,    // Signal to start transmission
    output reg tx,       // TX line
    output reg tx_busy   // Indicates transmission in progress
);
    // 1. Wait for data_valid in IDLE
    // 2. Send start bit (logic 0)
    // 3. Send 8 data bits LSB first
    // 4. Send stop bit (logic 1)
    // 5. Return to IDLE
    parameter IDLE = 2'b00, START_BIT = 2'b01, DATA_BITS = 2'b10, STOP_BIT = 2'b11;
    reg [8:0] baud_counter = 0; // 50mhz / (9600 * 16) = 326
    reg [3:0] sample_counter = 0; // counting up to 16 for oversampling
    reg [2:0] bit_counter = 0; // count up to 8 bits total data
    reg [1:0] state_cur = IDLE, state_prev = IDLE; // 2 bits for state (4 total -> 2^2)
    reg [7:0] data_register;    // Store the data to transmit
    parameter DIVISOR = 9'd326; // correct divisor for 9600 baud
    
    always @(posedge clk) begin
        state_prev <= state_cur; // cur state becomes prev state
        baud_counter <= baud_counter + 1;
        
        case(state_cur)
            IDLE: begin
                // wait for data_valid to be asserted
                tx <= 1;
                tx_busy <= 0;

                if (data_valid) begin
                    // reset counters and interal registers
                    state_cur <= START_BIT;
                    baud_counter <= 0;
                    bit_counter <= 0;
                    sample_counter <= 0;
                    data_register <= data;
                    tx_busy<= 1;
                end 
            end
            
            START_BIT: begin
                // set tx low for one bit period
                tx <= 0;

                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;

                    if (sample_counter == 4'd15) begin
                        sample_counter <= 0;
                        state_cur <= DATA_BITS;
                    end
                end
            end
            
            DATA_BITS: begin
                tx <= data_register[bit_counter];

                // send each bit of data
                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;

                    if (sample_counter == 4'd15) begin
                        sample_counter <= 0;

                        if (bit_counter == 3'd7) begin
                            state_cur <= STOP_BIT;
                        end
                        else begin
                            bit_counter <= bit_counter + 1;
                        end
                    end
                end
            end
            
            STOP_BIT: begin
                // set tx high for one bit period
                tx <= 1;

                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;

                    if (sample_counter == 4'd15) begin
                        sample_counter <= 0;
                        state_cur <= IDLE;
                    end
                end
            end
        endcase
    end
endmodule