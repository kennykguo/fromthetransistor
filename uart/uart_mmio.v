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
    output reg [7:0] tx_data,
    output reg tx_data_valid,
    input tx_busy
);
    // circular buffers
    reg [7:0] tx_buffer [0:9];
    reg [3:0] tx_write_ptr = 0;
    reg [3:0] tx_read_ptr = 0;
    reg [3:0] tx_count = 0;

    reg [7:0] rx_buffer [0:9];
    reg [3:0] rx_write_ptr = 0;
    reg [3:0] rx_read_ptr = 0;
    reg [3:0] rx_count = 0;

    // simple fix: delay buffer advancement by one cycle
    reg tx_data_sent = 0;      // tracks when we've sent data to uart_tx

    parameter STATUS_REG = 32'h00, DATA_REG = 32'h04;
    wire rx_data_read = read_enable && (addr == DATA_REG);
    wire tx_data_write = write_enable && (addr == DATA_REG);

    always @(posedge clk) begin
        if (reset) begin
            tx_write_ptr <= 0;
            tx_read_ptr <= 0;
            tx_count <= 0;
            rx_write_ptr <= 0;
            rx_read_ptr <= 0;
            rx_count <= 0;
            tx_data_valid <= 0;
            tx_data_sent <= 0;
        end else begin
            tx_data_valid <= 0;  // default to 0 (single cycle pulse)
            
            // cpu writes to tx buffer
            if (tx_data_write && tx_count < 4'd10) begin
                tx_buffer[tx_write_ptr] <= write_data;
                tx_count <= tx_count + 1;
                if (tx_write_ptr == 4'd9) begin
                    tx_write_ptr <= 0;
                end else begin
                    tx_write_ptr <= tx_write_ptr + 1;
                end
            end

            // cpu reads from rx buffer
            if (rx_data_read && rx_count > 0) begin
                if (rx_read_ptr == 4'd9) begin
                    rx_read_ptr <= 0;
                end else begin
                    rx_read_ptr <= rx_read_ptr + 1;
                end
                rx_count <= rx_count - 1;
            end

            // send data to uart_tx when available
            if (tx_count > 0 && ~tx_busy && ~tx_data_sent) begin
                tx_data <= tx_buffer[tx_read_ptr];
                tx_data_valid <= 1;  // single cycle pulse
                tx_data_sent <= 1;   // mark that we sent data
            end

            // advance buffer when uart becomes busy (confirms it received data)
            if (tx_data_sent && tx_busy) begin
                tx_data_sent <= 0;
                if (tx_read_ptr == 4'd9) begin
                    tx_read_ptr <= 0;
                end else begin
                    tx_read_ptr <= tx_read_ptr + 1;
                end
                tx_count <= tx_count - 1;
            end

            // uart_rx to rx buffer
            if (rx_data_valid && rx_count < 4'd10) begin
                rx_buffer[rx_write_ptr] <= rx_data;
                if (rx_write_ptr == 4'd9) begin
                    rx_write_ptr <= 0;
                end else begin
                    rx_write_ptr <= rx_write_ptr + 1;
                end
                rx_count <= rx_count + 1;
            end
        end
    end
    
    // combinational read logic
    always @(*) begin
        if (read_enable && addr == STATUS_REG) begin
            read_data = {6'b0, rx_count > 0, tx_count < 4'd10};  // fixed width
        end else if (read_enable && addr == DATA_REG && rx_count > 0) begin
            read_data = rx_buffer[rx_read_ptr];
        end else begin
            read_data = 8'h00;
        end
    end
endmodule



// CPU to uart_mmio through bus interface
// uart_mmio to tx buffer
// tx buffer to uart_tx
// uart_tx to uart_rx - loop back automatically implemented
// uart_rx to uart_mmio
// uart_mmio to rx buffer
// rx buffer eventually to user through bus interface
// bus interface signals
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
// mmio acts as the temporal bridge - it captures asynchronous uart events and presents them through a synchronous register interface that the cpu can access at any time.
// https://claude.ai/chat/4b112408-5598-4c92-9510-3a6b4fce4b49