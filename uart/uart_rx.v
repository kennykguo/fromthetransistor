// RX pin of UART
// when no data transmitted, line stays high
// start bit - starts with 0 indicating beginning of a frame
// data bits - 8 bits
// stop bit - 1 or 2 high bits marking end of frame

// assuming a 50mhz clock, and 9600 baud rate config
module uart_rx(
    input clk, // oversampled baud clock (typically 16x)
    input rx, // rx line
    output reg [7:0] data, // received data
    output reg data_valid // indicates new data available
);
    // 1. monitor for start bit (falling edge)
    // 2. sample in middle of each bit time 
    // 3. collect 8 data bits
    // 4. verify stop bit
    // 5. assert data_valid when complete
    parameter IDLE = 2'b00, START_BIT = 2'b01, DATA_BITS = 2'b10, STOP_BIT = 2'b11;
    reg [8:0] baud_counter = 0; // 50mhz / (9600 * 16) = 326
    reg [3:0] sample_counter = 0; // counting up to 16 for oversampling
    reg [2:0] bit_counter = 0; // count up to 8 bits total data
    reg [1:0] state_cur = IDLE, state_prev = IDLE; // 2 bits for state (4 total -> 2^2)
    parameter DIVISOR = 9'd326; // correct divisor for 9600 baud
    reg start_bit, end_bit;
    
    always @(posedge clk) begin
        data_valid <= 0;
        state_prev <= state_cur; // cur state becomes prev state
        baud_counter <= baud_counter + 1;
        
        case(state_cur)
            IDLE: begin
                // detect start bit (falling edge on rx line)
                // when detected, move to START_BIT state
                if (!rx) begin
                    state_cur <= START_BIT;
                    // reset counters
                    baud_counter <= 0;
                    bit_counter <= 0;
                    sample_counter <= 0;
                end 
            end
            
            START_BIT: begin
                // validate start bit by sampling in the middle
                // then prepare to receive data bits
                // start counting from 0 bit

                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;

                    if (sample_counter == 4'd15) begin
                        sample_counter <= 0;
                        
                        if (!start_bit) begin
                            state_cur <= DATA_BITS;
                        end
                        else begin
                            state_cur <= IDLE;
                        end
                    end

                    // sample rx if its the middle bit
                    else if (sample_counter == 4'd7) begin
                        start_bit <= rx;
                    end
                end
            end
            
            DATA_BITS: begin
                // sample each data bit in the middle
                // shift data into the data register
                // track which bit you're receiving

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
                        end // removed the erroneous endcur <= STOP_BIT
                    end

                    else if (sample_counter == 4'd7) begin
                        data[0] <= data[1];
                        data[1] <= data[2];
                        data[2] <= data[3];
                        data[3] <= data[4];
                        data[4] <= data[5];
                        data[5] <= data[6];
                        data[6] <= data[7];
                        data[7] <= rx;
                    end
                end
            end
            
            STOP_BIT: begin
                // validate stop bit
                // signal data_valid if stop bit is correct
                // return to IDLE state

                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;

                    if (sample_counter == 4'd15) begin
                        sample_counter <= 0;
                        state_cur <= IDLE;
                    end

                    // sample rx if its the middle bit
                    else if (sample_counter == 4'd7) begin
                        end_bit <= rx;
                        if (rx) begin // check rx directly
                            data_valid <= 1;
                        end
                    end
                end
            end
        endcase
    end
endmodule