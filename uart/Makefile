# combined makefile for uart rx and tx testbenches with verilator
# supports building and testing both modules independently or together

# verilator configuration
VERILATOR = verilator
VERILATOR_FLAGS = -Wall --cc --trace --exe --build -j 0

# source files for each module
RX_VERILOG_SRC = uart_rx.v
RX_CPP_TB = rx_testbench.cpp
RX_TARGET = obj_dir/Vuart_rx
RX_VCD = uart_rx_trace.vcd

TX_VERILOG_SRC = uart_tx.v
TX_CPP_TB = tx_testbench.cpp
TX_TARGET = obj_dir/Vuart_tx
TX_VCD = uart_tx_trace.vcd

# default target builds both modules
all: rx tx

# individual module targets
rx: $(RX_TARGET)
tx: $(TX_TARGET)

# build rules for each module
$(RX_TARGET): $(RX_VERILOG_SRC) $(RX_CPP_TB)
	@echo "=== building uart rx testbench ==="
	$(VERILATOR) $(VERILATOR_FLAGS) $(RX_VERILOG_SRC) $(RX_CPP_TB)

$(TX_TARGET): $(TX_VERILOG_SRC) $(TX_CPP_TB)
	@echo "=== building uart tx testbench ==="
	$(VERILATOR) $(VERILATOR_FLAGS) $(TX_VERILOG_SRC) $(TX_CPP_TB)

# run individual simulations
run-rx: $(RX_TARGET)
	@echo "=== running uart rx simulation ==="
	./$(RX_TARGET)

run-tx: $(TX_TARGET)
	@echo "=== running uart tx simulation ==="
	./$(TX_TARGET)

# run both simulations sequentially
run-all: run-rx run-tx

# convenience alias for running both (most common use case)
run: run-all

# view waveforms for each module
waves-rx: $(RX_VCD)
	@echo "=== opening rx waveforms in gtkwave ==="
	gtkwave $(RX_VCD)

waves-tx: $(TX_VCD)
	@echo "=== opening tx waveforms in gtkwave ==="
	gtkwave $(TX_VCD)

# view both waveforms simultaneously in separate gtkwave windows
waves-all: $(RX_VCD) $(TX_VCD)
	@echo "=== opening both waveforms in gtkwave ==="
	gtkwave $(RX_VCD) &
	gtkwave $(TX_VCD) &

# convenience alias for viewing waveforms
waves: waves-all

# clean targets for individual modules
clean-rx:
	@echo "=== cleaning rx build artifacts ==="
	rm -rf obj_dir/Vuart_rx*
	rm -f $(RX_VCD)

clean-tx:
	@echo "=== cleaning tx build artifacts ==="
	rm -rf obj_dir/Vuart_tx*
	rm -f $(TX_VCD)

# clean everything
clean: clean-rx clean-tx
	@echo "=== cleaning shared build artifacts ==="
	rm -rf obj_dir
	rm -f *.vcd

# help target to show available commands
help:
	@echo "uart testbench makefile - available targets:"
	@echo ""
	@echo "building:"
	@echo "  all      - build both rx and tx testbenches (default)"
	@echo "  rx       - build only rx testbench"
	@echo "  tx       - build only tx testbench"
	@echo ""
	@echo "running simulations:"
	@echo "  run      - run both rx and tx simulations"
	@echo "  run-all  - run both rx and tx simulations"
	@echo "  run-rx   - run only rx simulation"
	@echo "  run-tx   - run only tx simulation"
	@echo ""
	@echo "viewing waveforms:"
	@echo "  waves    - open both rx and tx waveforms"
	@echo "  waves-all- open both rx and tx waveforms"
	@echo "  waves-rx - open only rx waveforms"
	@echo "  waves-tx - open only tx waveforms"
	@echo ""
	@echo "cleaning:"
	@echo "  clean    - remove all build artifacts and vcd files"
	@echo "  clean-rx - remove only rx build artifacts"
	@echo "  clean-tx - remove only tx build artifacts"
	@echo ""
	@echo "other:"
	@echo "  help     - show this help message"

# declare phony targets (targets that don't correspond to files)
.PHONY: all rx tx run-rx run-tx run-all run waves-rx waves-tx waves-all waves
.PHONY: clean-rx clean-tx clean help