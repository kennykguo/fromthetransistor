// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vuart_top.h for the primary calling header

#ifndef VERILATED_VUART_TOP___024ROOT_H_
#define VERILATED_VUART_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vuart_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vuart_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(write_data,7,0);
    VL_IN8(write_enable,0,0);
    VL_OUT8(read_data,7,0);
    VL_IN8(read_enable,0,0);
    CData/*0:0*/ uart_top__DOT__tx_busy;
    CData/*7:0*/ uart_top__DOT__rx_data;
    CData/*0:0*/ uart_top__DOT__rx_data_valid;
    CData/*7:0*/ uart_top__DOT__tx_data;
    CData/*0:0*/ uart_top__DOT__tx_data_valid;
    CData/*0:0*/ uart_top__DOT__tx;
    CData/*3:0*/ uart_top__DOT__uart_tx_inst__DOT__sample_counter;
    CData/*2:0*/ uart_top__DOT__uart_tx_inst__DOT__bit_counter;
    CData/*1:0*/ uart_top__DOT__uart_tx_inst__DOT__state_cur;
    CData/*7:0*/ uart_top__DOT__uart_tx_inst__DOT__data_register;
    CData/*3:0*/ uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr;
    CData/*3:0*/ uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr;
    CData/*3:0*/ uart_top__DOT__uart_mmio_inst__DOT__tx_count;
    CData/*3:0*/ uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr;
    CData/*3:0*/ uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr;
    CData/*3:0*/ uart_top__DOT__uart_mmio_inst__DOT__rx_count;
    CData/*0:0*/ uart_top__DOT__uart_mmio_inst__DOT__tx_sending;
    CData/*7:0*/ uart_top__DOT__uart_mmio_inst__DOT____Vlvbound_hcc36a258__0;
    CData/*7:0*/ uart_top__DOT__uart_mmio_inst__DOT____Vlvbound_hd9962200__0;
    CData/*3:0*/ uart_top__DOT__uart_rx_inst__DOT__sample_counter;
    CData/*2:0*/ uart_top__DOT__uart_rx_inst__DOT__bit_counter;
    CData/*1:0*/ uart_top__DOT__uart_rx_inst__DOT__state_cur;
    CData/*0:0*/ uart_top__DOT__uart_rx_inst__DOT__start_bit;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*8:0*/ uart_top__DOT__uart_tx_inst__DOT__baud_counter;
    SData/*8:0*/ uart_top__DOT__uart_rx_inst__DOT__baud_counter;
    VL_IN(addr,31,0);
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 10> uart_top__DOT__uart_mmio_inst__DOT__tx_buffer;
    VlUnpacked<CData/*7:0*/, 10> uart_top__DOT__uart_mmio_inst__DOT__rx_buffer;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vuart_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vuart_top___024root(Vuart_top__Syms* symsp, const char* v__name);
    ~Vuart_top___024root();
    VL_UNCOPYABLE(Vuart_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
