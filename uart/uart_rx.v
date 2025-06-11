module uart_rx(
    input clk,
    input rx,
    output reg [7:0] data,
    output reg data_valid
);
    parameter IDLE = 2'b00, START_BIT = 2'b01, DATA_BITS = 2'b10, STOP_BIT = 2'b11;
    parameter DIVISOR = 9'd326;
    
    reg [8:0] baud_counter = 0;
    reg [3:0] sample_counter = 0;
    reg [2:0] bit_counter = 0;
    reg [1:0] state_cur = IDLE;  // removed state_prev
    reg start_bit;  // removed end_bit
    
    always @(posedge clk) begin
        data_valid <= 0;
        
        case(state_cur)
            IDLE: begin
                if (!rx) begin
                    state_cur <= START_BIT;
                    baud_counter <= 0;
                    bit_counter <= 0;
                    sample_counter <= 0;
                end 
            end
            
            START_BIT: begin
                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;

                    if (sample_counter == 4'd15) begin
                        sample_counter <= 0;
                        if (!start_bit) begin
                            state_cur <= DATA_BITS;
                        end else begin
                            state_cur <= IDLE;
                        end
                    end else if (sample_counter == 4'd7) begin
                        start_bit <= rx;
                    end
                end else begin
                    baud_counter <= baud_counter + 1;  // conditional increment
                end
            end
            
            DATA_BITS: begin
                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;

                    if (sample_counter == 4'd15) begin
                        sample_counter <= 0;
                        if (bit_counter == 3'd7) begin
                            state_cur <= STOP_BIT;
                        end else begin
                            bit_counter <= bit_counter + 1;
                        end
                    end else if (sample_counter == 4'd7) begin
                        data[0] <= data[1];
                        data[1] <= data[2];
                        data[2] <= data[3];
                        data[3] <= data[4];
                        data[4] <= data[5];
                        data[5] <= data[6];
                        data[6] <= data[7];
                        data[7] <= rx;
                    end
                end else begin
                    baud_counter <= baud_counter + 1;
                end
            end
            
            STOP_BIT: begin
                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;

                    if (sample_counter == 4'd15) begin
                        sample_counter <= 0;
                        state_cur <= IDLE;
                    end else if (sample_counter == 4'd7) begin
                        if (rx) begin
                            data_valid <= 1;
                        end
                    end
                end else begin
                    baud_counter <= baud_counter + 1;
                end
            end
        endcase
    end
endmodule
