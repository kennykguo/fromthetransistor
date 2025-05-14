module blinking_led (input clk, output reg led);

    // Use inline initialization for better compatibility
    reg [31:0] count = 0;
    
    // Initialize LED to 0
    initial led = 0;

    always @ (posedge clk)
        begin
            if (count == 31) // Modified to match new observed behavior (32 ticks)
                begin
                    count <= 0;
                    led <= ~led;
                end
            else
                begin
                    count <= count + 1;
                end
        end

endmodule
