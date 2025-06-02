// Pseudocode - design your own interface
module uart_mmio(
    input clk,
    input reset,
    
    // bus interface
    input [32-1:0] addr,
    input [8-1:0] write_data,
    input write_enable,

    output reg [8-1:0] read_data,
    input read_enable,
    
    // uart signals
    input [7:0] rx_data,
    input rx_data_valid,

    output [7:0] tx_data,
    output tx_data_valid,
    input tx_busy
);
    // register map:
    // 0x00: status register (read-only)
    // 0x08: control register

    // internal counters for counting - lets say the buffer sizes are ten for input and output buffers

    // the cpu and the uart interface are separately operating. this is why we have the mmio (memory managed input output)

    // input buffer (put into buffer when user writes. taken out of buffer, when uart wants to write it out)

    // output buffer (received from tx, and put into buffer. taken out from buffer when user wants to read)
    
    parameter WAITING = 2'b00, RECEIVED_BIT = 2'b01, SENDING_BIT = 2'b10;

    reg [1:0] state_cur = IDLE, state_prev = IDLE; // 2 bits for state (4 total -> 2^2)

    always @(posedge clk) begin

        case (state_cur)
            WAITING: begin
               // check current state of rx
            end

            RECEIVED_BIT: begin
            
            end

            SENDING_BIT: begin
            
            end
        
        endcase

    end


endmodule


// Bus Interface Signals
// input [ADDR_WIDTH-1:0] addr - this carries the byte address that the cpu wants to access. the width is parameterized, but typically 32 bits. when the cpu executes something like *(volatile uint32_t*)0x1000 = data, that 0x1000 becomes the value on this addr bus. your logic needs to decode this address to determine which internal register is being targeted.
// input [DATA_WIDTH-1:0] write_data - this carries the actual data value the cpu wants to write. if cpu does *(volatile uint32_t*)0x1004 = 0x41, then write_data will be 0x41. this data needs to be captured and processed based on which register the addr is pointing to.
// input write_enable - this is the strobe signal indicating the cpu is performing a write operation. it's typically asserted for one clock cycle. your logic should only act on write_data when both write_enable is high and the address decode matches a writable register.
// input read_enable - similar strobe for read operations. when high, the cpu expects valid data on read_data. your mux logic needs to select the correct register contents based on addr.
// output reg [DATA_WIDTH-1:0] read_data - this is what gets driven back to the cpu during reads. you need combinational or registered logic that selects between different register values based on the addr input.
// UART Hardware Interface Signals
// input [7:0] rx_data - this is the 8-bit data that your uart_rx module has received and decoded. it's only valid when rx_data_valid is asserted.
// input rx_data_valid - this is a pulse signal from uart_rx indicating that rx_data contains a newly received byte. this pulse typically lasts one clock cycle. your mmio needs to capture rx_data during this pulse and store it for later cpu access.
// output [7:0] tx_data - this feeds into your uart_tx module. when the cpu writes transmit data, you need to route that 8-bit value to this output.
// output tx_data_valid - this is the pulse signal that tells uart_tx to start transmitting tx_data. your mmio generates this pulse when the cpu writes to the transmit data register.
// input tx_busy - this comes from uart_tx indicating whether a transmission is currently in progress. your status register needs to reflect this state so the cpu can poll before sending the next byte.

// your mmio acts as the temporal bridge - it captures asynchronous uart events and presents them through a synchronous register interface that the cpu can access at any time.