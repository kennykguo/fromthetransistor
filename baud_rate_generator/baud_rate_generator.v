// clock divider module
// takes a clk signal, then stretches it out based on desired baud rate
module baud_rate_generator(
    input clk,          // System clock
    output reg baud_clk // UART clock
);
    parameter DIVISOR = 10'd2604; // half of 5208
    reg [9:0] counter = 0; // counter variable

    always @(posedge clk)
    begin
        if (counter >= DIVISOR - 1)
        begin
            counter <= 0;
            baud_clk <= ~baud_clk
        end 
        else
        begin
            counter <= counter + 1;
        end 
    end
    // divisor = 50,000,000 / 9600 ≈ 5209
    // implement counter to divide clock
    // toggle baud_clk when counter reaches half the divisor
    // a baud rate is a measure of data transmission speed in a communication channel
endmodule