module uart_tx(
    input clk,
    input [7:0] data,
    input data_valid,
    output reg tx,
    output reg tx_busy
);
    parameter IDLE = 2'b00, START_BIT = 2'b01, DATA_BITS = 2'b10, STOP_BIT = 2'b11;
    parameter DIVISOR = 9'd326;
    
    reg [8:0] baud_counter = 0;
    reg [3:0] sample_counter = 0;  // keep for compatibility with rx
    reg [2:0] bit_counter = 0;
    reg [1:0] state_cur = IDLE;
    reg [7:0] data_register;
    
    always @(posedge clk) begin
        case(state_cur)
            IDLE: begin
                tx <= 1;
                tx_busy <= 0;
                if (data_valid) begin
                    state_cur <= START_BIT;
                    baud_counter <= 0;
                    bit_counter <= 0;
                    sample_counter <= 0;
                    data_register <= data;
                    tx_busy <= 1;
                end 
            end
            
            START_BIT: begin
                tx <= 0;  // start bit
                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;
                    if (sample_counter == 4'd15) begin  // match rx timing
                        sample_counter <= 0;
                        state_cur <= DATA_BITS;
                    end
                end else begin
                    baud_counter <= baud_counter + 1;
                end
            end
            
            DATA_BITS: begin
                tx <= data_register[bit_counter];  // lsb first
                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;
                    if (sample_counter == 4'd15) begin  // match rx timing
                        sample_counter <= 0;
                        if (bit_counter == 3'd7) begin
                            state_cur <= STOP_BIT;
                        end else begin
                            bit_counter <= bit_counter + 1;
                        end
                    end
                end else begin
                    baud_counter <= baud_counter + 1;
                end
            end
            
            STOP_BIT: begin
                tx <= 1;  // stop bit
                if (baud_counter == DIVISOR - 1) begin
                    baud_counter <= 0;
                    sample_counter <= sample_counter + 1;
                    if (sample_counter == 4'd15) begin  // match rx timing
                        sample_counter <= 0;
                        state_cur <= IDLE;
                    end
                end else begin
                    baud_counter <= baud_counter + 1;
                end
            end
        endcase
    end
endmodule
