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

    // track uart_tx busy state for proper synchronization
    reg tx_busy_prev = 0;
    
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
            tx_busy_prev <= 0;
        end else begin
            tx_busy_prev <= tx_busy;
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

    // simple state machine for tx buffer management
    reg tx_state = 0;  // 0 = idle, 1 = transmitting
    
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
            tx_state <= 0;
        end else begin
            tx_data_valid <= 0;  // default to 0
            
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

            // tx state machine
            case (tx_state)
                1'b0: begin  // idle state
                    if (tx_count > 0) begin
                        tx_data <= tx_buffer[tx_read_ptr];
                        tx_data_valid <= 1;
                        tx_state <= 1;
                    end
                end
                
                1'b1: begin  // transmitting state
                    if (~tx_busy) begin  // transmission complete
                        tx_state <= 0;
                        // advance buffer
                        if (tx_read_ptr == 4'd9) begin
                            tx_read_ptr <= 0;
                        end else begin
                            tx_read_ptr <= tx_read_ptr + 1;
                        end
                        tx_count <= tx_count - 1;
                    end
                end
            endcase

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