// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart_top.h for the primary calling header

#include "Vuart_top__pch.h"
#include "Vuart_top___024root.h"

VL_INLINE_OPT void Vuart_top___024root___ico_sequent__TOP__0(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->read_data = (((IData)(vlSelf->read_enable) 
                          & (0U == vlSelf->addr)) ? 
                         (((0U < (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count)) 
                           << 1U) | (0xaU > (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_count)))
                          : ((((IData)(vlSelf->read_enable) 
                               & (4U == vlSelf->addr)) 
                              & (0U < (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count)))
                              ? ((9U >= (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr))
                                  ? vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_buffer
                                 [vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr]
                                  : 0U) : 0U));
}

void Vuart_top___024root___eval_ico(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vuart_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vuart_top___024root___eval_triggers__ico(Vuart_top___024root* vlSelf);

bool Vuart_top___024root___eval_phase__ico(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vuart_top___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vuart_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vuart_top___024root___eval_act(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vuart_top___024root___nba_sequent__TOP__0(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter;
    __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter = 0;
    SData/*8:0*/ __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter;
    __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter = 0;
    CData/*1:0*/ __Vdly__uart_top__DOT__uart_tx_inst__DOT__state_cur;
    __Vdly__uart_top__DOT__uart_tx_inst__DOT__state_cur = 0;
    CData/*0:0*/ __Vdly__uart_top__DOT__tx_busy;
    __Vdly__uart_top__DOT__tx_busy = 0;
    CData/*3:0*/ __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr = 0;
    CData/*3:0*/ __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr = 0;
    CData/*3:0*/ __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_count;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_count = 0;
    CData/*0:0*/ __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_sending;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_sending = 0;
    CData/*3:0*/ __Vdlyvdim0__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0;
    __Vdlyvdim0__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0;
    __Vdlyvval__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0;
    __Vdlyvset__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0 = 0;
    CData/*3:0*/ __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr = 0;
    CData/*3:0*/ __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr = 0;
    CData/*3:0*/ __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_count;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_count = 0;
    CData/*3:0*/ __Vdlyvdim0__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0;
    __Vdlyvdim0__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0;
    __Vdlyvval__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0;
    __Vdlyvset__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0 = 0;
    CData/*3:0*/ __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter;
    __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter = 0;
    SData/*8:0*/ __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter;
    __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter = 0;
    CData/*1:0*/ __Vdly__uart_top__DOT__uart_rx_inst__DOT__state_cur;
    __Vdly__uart_top__DOT__uart_rx_inst__DOT__state_cur = 0;
    // Body
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_sending 
        = vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_sending;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr 
        = vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr 
        = vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr;
    __Vdlyvset__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0 = 0U;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_count 
        = vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_count;
    __Vdly__uart_top__DOT__tx_busy = vlSelf->uart_top__DOT__tx_busy;
    __Vdly__uart_top__DOT__uart_tx_inst__DOT__state_cur 
        = vlSelf->uart_top__DOT__uart_tx_inst__DOT__state_cur;
    __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter 
        = vlSelf->uart_top__DOT__uart_tx_inst__DOT__baud_counter;
    __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter 
        = vlSelf->uart_top__DOT__uart_tx_inst__DOT__sample_counter;
    __Vdly__uart_top__DOT__uart_rx_inst__DOT__state_cur 
        = vlSelf->uart_top__DOT__uart_rx_inst__DOT__state_cur;
    __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter 
        = vlSelf->uart_top__DOT__uart_rx_inst__DOT__baud_counter;
    __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter 
        = vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr 
        = vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_count 
        = vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count;
    __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr 
        = vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr;
    __Vdlyvset__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0 = 0U;
    if (vlSelf->reset) {
        __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr = 0U;
        __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr = 0U;
        __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_count = 0U;
    } else {
        if ((((IData)(vlSelf->read_enable) & (4U == vlSelf->addr)) 
             & (0U < (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count)))) {
            __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr 
                = ((9U == (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr))));
            __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_count 
                = (0xfU & ((IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count) 
                           - (IData)(1U)));
        }
        if (((IData)(vlSelf->uart_top__DOT__rx_data_valid) 
             & (0xaU > (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count)))) {
            vlSelf->uart_top__DOT__uart_mmio_inst__DOT____Vlvbound_hd9962200__0 
                = vlSelf->uart_top__DOT__rx_data;
            __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_count 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count)));
            if ((9U >= (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr))) {
                __Vdlyvval__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0 
                    = vlSelf->uart_top__DOT__uart_mmio_inst__DOT____Vlvbound_hd9962200__0;
                __Vdlyvset__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0 = 1U;
                __Vdlyvdim0__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0 
                    = vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr;
            }
            __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr 
                = ((9U == (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr))));
        }
    }
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr 
        = __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr 
        = __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count 
        = __Vdly__uart_top__DOT__uart_mmio_inst__DOT__rx_count;
    if (__Vdlyvset__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0) {
        vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_buffer[__Vdlyvdim0__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0] 
            = __Vdlyvval__uart_top__DOT__uart_mmio_inst__DOT__rx_buffer__v0;
    }
    vlSelf->uart_top__DOT__rx_data_valid = 0U;
    if ((2U & (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__state_cur))) {
        if ((1U & (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__state_cur))) {
            if ((0x145U == (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__baud_counter))) {
                __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter)));
                __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter = 0U;
                if ((0xfU == (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter))) {
                    __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter = 0U;
                    __Vdly__uart_top__DOT__uart_rx_inst__DOT__state_cur = 0U;
                } else if ((7U == (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter))) {
                    if (vlSelf->uart_top__DOT__tx) {
                        vlSelf->uart_top__DOT__rx_data_valid = 1U;
                    }
                }
            } else {
                __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__baud_counter)));
            }
        } else if ((0x145U == (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__baud_counter))) {
            __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter = 0U;
            __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter)));
            if ((0xfU == (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter))) {
                __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter = 0U;
                if ((7U == (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__bit_counter))) {
                    __Vdly__uart_top__DOT__uart_rx_inst__DOT__state_cur = 3U;
                } else {
                    vlSelf->uart_top__DOT__uart_rx_inst__DOT__bit_counter 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__bit_counter)));
                }
            } else if ((7U == (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter))) {
                vlSelf->uart_top__DOT__rx_data = (((IData)(vlSelf->uart_top__DOT__tx) 
                                                   << 7U) 
                                                  | (0x7fU 
                                                     & ((IData)(vlSelf->uart_top__DOT__rx_data) 
                                                        >> 1U)));
            }
        } else {
            __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__baud_counter)));
        }
    } else if ((1U & (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__state_cur))) {
        if ((0x145U == (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__baud_counter))) {
            __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter = 0U;
            __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter)));
            if ((0xfU == (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter))) {
                __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter = 0U;
                __Vdly__uart_top__DOT__uart_rx_inst__DOT__state_cur 
                    = ((IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__start_bit)
                        ? 0U : 2U);
            } else if ((7U == (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter))) {
                vlSelf->uart_top__DOT__uart_rx_inst__DOT__start_bit 
                    = vlSelf->uart_top__DOT__tx;
            }
        } else {
            __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_rx_inst__DOT__baud_counter)));
        }
    } else if ((1U & (~ (IData)(vlSelf->uart_top__DOT__tx)))) {
        vlSelf->uart_top__DOT__uart_rx_inst__DOT__bit_counter = 0U;
        __Vdly__uart_top__DOT__uart_rx_inst__DOT__state_cur = 1U;
        __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter = 0U;
        __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter = 0U;
    }
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter 
        = __Vdly__uart_top__DOT__uart_rx_inst__DOT__sample_counter;
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__baud_counter 
        = __Vdly__uart_top__DOT__uart_rx_inst__DOT__baud_counter;
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__state_cur 
        = __Vdly__uart_top__DOT__uart_rx_inst__DOT__state_cur;
    if ((2U & (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__state_cur))) {
        if ((1U & (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__state_cur))) {
            vlSelf->uart_top__DOT__tx = 1U;
            if ((0x145U == (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__baud_counter))) {
                __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__sample_counter)));
                __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter = 0U;
                if ((0xfU == (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__sample_counter))) {
                    __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter = 0U;
                    __Vdly__uart_top__DOT__uart_tx_inst__DOT__state_cur = 0U;
                }
            } else {
                __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__baud_counter)));
            }
        } else {
            vlSelf->uart_top__DOT__tx = (1U & ((IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__data_register) 
                                               >> (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__bit_counter)));
            if ((0x145U == (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__baud_counter))) {
                __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter = 0U;
                __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__sample_counter)));
                if ((0xfU == (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__sample_counter))) {
                    __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter = 0U;
                    if ((7U == (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__bit_counter))) {
                        __Vdly__uart_top__DOT__uart_tx_inst__DOT__state_cur = 3U;
                    } else {
                        vlSelf->uart_top__DOT__uart_tx_inst__DOT__bit_counter 
                            = (7U & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__bit_counter)));
                    }
                }
            } else {
                __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__baud_counter)));
            }
        }
    } else if ((1U & (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__state_cur))) {
        vlSelf->uart_top__DOT__tx = 0U;
        if ((0x145U == (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__baud_counter))) {
            __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter = 0U;
            __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__sample_counter)));
            if ((0xfU == (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__sample_counter))) {
                __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter = 0U;
                __Vdly__uart_top__DOT__uart_tx_inst__DOT__state_cur = 2U;
            }
        } else {
            __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_tx_inst__DOT__baud_counter)));
        }
    } else {
        vlSelf->uart_top__DOT__tx = 1U;
        __Vdly__uart_top__DOT__tx_busy = 0U;
        if (vlSelf->uart_top__DOT__tx_data_valid) {
            vlSelf->uart_top__DOT__uart_tx_inst__DOT__bit_counter = 0U;
            __Vdly__uart_top__DOT__uart_tx_inst__DOT__state_cur = 1U;
            __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter = 0U;
            __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter = 0U;
            vlSelf->uart_top__DOT__uart_tx_inst__DOT__data_register 
                = vlSelf->uart_top__DOT__tx_data;
            __Vdly__uart_top__DOT__tx_busy = 1U;
        }
    }
    if (vlSelf->reset) {
        __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr = 0U;
        __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr = 0U;
        __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_count = 0U;
        vlSelf->uart_top__DOT__tx_data_valid = 0U;
        __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_sending = 0U;
    } else {
        vlSelf->uart_top__DOT__tx_data_valid = 0U;
        if ((((IData)(vlSelf->write_enable) & (4U == vlSelf->addr)) 
             & (0xaU > (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_count)))) {
            vlSelf->uart_top__DOT__uart_mmio_inst__DOT____Vlvbound_hcc36a258__0 
                = vlSelf->write_data;
            __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_count 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_count)));
            if ((9U >= (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr))) {
                __Vdlyvval__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0 
                    = vlSelf->uart_top__DOT__uart_mmio_inst__DOT____Vlvbound_hcc36a258__0;
                __Vdlyvset__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0 = 1U;
                __Vdlyvdim0__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0 
                    = vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr;
            }
            __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr 
                = ((9U == (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr))));
        }
        if (((0U < (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_count)) 
             & (~ (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_sending)))) {
            vlSelf->uart_top__DOT__tx_data = ((9U >= (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr))
                                               ? vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_buffer
                                              [vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr]
                                               : 0U);
            vlSelf->uart_top__DOT__tx_data_valid = 1U;
            __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_sending = 1U;
        }
        if (((IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_sending) 
             & (~ (IData)(vlSelf->uart_top__DOT__tx_busy)))) {
            __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr 
                = ((9U == (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr))));
            __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_count 
                = (0xfU & ((IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_count) 
                           - (IData)(1U)));
            __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_sending = 0U;
        }
    }
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__sample_counter 
        = __Vdly__uart_top__DOT__uart_tx_inst__DOT__sample_counter;
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__baud_counter 
        = __Vdly__uart_top__DOT__uart_tx_inst__DOT__baud_counter;
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__state_cur 
        = __Vdly__uart_top__DOT__uart_tx_inst__DOT__state_cur;
    vlSelf->uart_top__DOT__tx_busy = __Vdly__uart_top__DOT__tx_busy;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr 
        = __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr 
        = __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_sending 
        = __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_sending;
    if (__Vdlyvset__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0) {
        vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_buffer[__Vdlyvdim0__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0] 
            = __Vdlyvval__uart_top__DOT__uart_mmio_inst__DOT__tx_buffer__v0;
    }
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_count 
        = __Vdly__uart_top__DOT__uart_mmio_inst__DOT__tx_count;
    vlSelf->read_data = (((IData)(vlSelf->read_enable) 
                          & (0U == vlSelf->addr)) ? 
                         (((0U < (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count)) 
                           << 1U) | (0xaU > (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_count)))
                          : ((((IData)(vlSelf->read_enable) 
                               & (4U == vlSelf->addr)) 
                              & (0U < (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count)))
                              ? ((9U >= (IData)(vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr))
                                  ? vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_buffer
                                 [vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr]
                                  : 0U) : 0U));
}

void Vuart_top___024root___eval_nba(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vuart_top___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vuart_top___024root___eval_triggers__act(Vuart_top___024root* vlSelf);

bool Vuart_top___024root___eval_phase__act(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vuart_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vuart_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vuart_top___024root___eval_phase__nba(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vuart_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__ico(Vuart_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__nba(Vuart_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__act(Vuart_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vuart_top___024root___eval(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vuart_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("uart_top.v", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vuart_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vuart_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("uart_top.v", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vuart_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("uart_top.v", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vuart_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vuart_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vuart_top___024root___eval_debug_assertions(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->write_enable & 0xfeU))) {
        Verilated::overWidthError("write_enable");}
    if (VL_UNLIKELY((vlSelf->read_enable & 0xfeU))) {
        Verilated::overWidthError("read_enable");}
}
#endif  // VL_DEBUG
