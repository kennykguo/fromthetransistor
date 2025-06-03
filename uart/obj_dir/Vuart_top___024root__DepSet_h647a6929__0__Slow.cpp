// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart_top.h for the primary calling header

#include "Vuart_top__pch.h"
#include "Vuart_top___024root.h"

VL_ATTR_COLD void Vuart_top___024root___eval_static__TOP(Vuart_top___024root* vlSelf);

VL_ATTR_COLD void Vuart_top___024root___eval_static(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_static\n"); );
    // Body
    Vuart_top___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vuart_top___024root___eval_static__TOP(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__baud_counter = 0U;
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__sample_counter = 0U;
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__bit_counter = 0U;
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__state_cur = 0U;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr = 0U;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr = 0U;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_count = 0U;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr = 0U;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr = 0U;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count = 0U;
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_data_sent = 0U;
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__baud_counter = 0U;
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter = 0U;
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__bit_counter = 0U;
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__state_cur = 0U;
}

VL_ATTR_COLD void Vuart_top___024root___eval_initial(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vuart_top___024root___eval_final(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__stl(Vuart_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vuart_top___024root___eval_phase__stl(Vuart_top___024root* vlSelf);

VL_ATTR_COLD void Vuart_top___024root___eval_settle(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vuart_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("uart_top.v", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vuart_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__stl(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vuart_top___024root___ico_sequent__TOP__0(Vuart_top___024root* vlSelf);

VL_ATTR_COLD void Vuart_top___024root___eval_stl(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vuart_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vuart_top___024root___eval_triggers__stl(Vuart_top___024root* vlSelf);

VL_ATTR_COLD bool Vuart_top___024root___eval_phase__stl(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vuart_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vuart_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__ico(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__act(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__nba(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vuart_top___024root___ctor_var_reset(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->addr = VL_RAND_RESET_I(32);
    vlSelf->write_data = VL_RAND_RESET_I(8);
    vlSelf->write_enable = VL_RAND_RESET_I(1);
    vlSelf->read_data = VL_RAND_RESET_I(8);
    vlSelf->read_enable = VL_RAND_RESET_I(1);
    vlSelf->uart_top__DOT__tx_busy = VL_RAND_RESET_I(1);
    vlSelf->uart_top__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->uart_top__DOT__rx_data_valid = VL_RAND_RESET_I(1);
    vlSelf->uart_top__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->uart_top__DOT__tx_data_valid = VL_RAND_RESET_I(1);
    vlSelf->uart_top__DOT__tx = VL_RAND_RESET_I(1);
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__baud_counter = VL_RAND_RESET_I(9);
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__sample_counter = VL_RAND_RESET_I(4);
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__bit_counter = VL_RAND_RESET_I(3);
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__state_cur = VL_RAND_RESET_I(2);
    vlSelf->uart_top__DOT__uart_tx_inst__DOT__data_register = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_buffer[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_write_ptr = VL_RAND_RESET_I(4);
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_read_ptr = VL_RAND_RESET_I(4);
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_count = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_buffer[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_write_ptr = VL_RAND_RESET_I(4);
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_read_ptr = VL_RAND_RESET_I(4);
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__rx_count = VL_RAND_RESET_I(4);
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT__tx_data_sent = VL_RAND_RESET_I(1);
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT____Vlvbound_hcc36a258__0 = VL_RAND_RESET_I(8);
    vlSelf->uart_top__DOT__uart_mmio_inst__DOT____Vlvbound_hd9962200__0 = VL_RAND_RESET_I(8);
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__baud_counter = VL_RAND_RESET_I(9);
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__sample_counter = VL_RAND_RESET_I(4);
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__bit_counter = VL_RAND_RESET_I(3);
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__state_cur = VL_RAND_RESET_I(2);
    vlSelf->uart_top__DOT__uart_rx_inst__DOT__start_bit = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
