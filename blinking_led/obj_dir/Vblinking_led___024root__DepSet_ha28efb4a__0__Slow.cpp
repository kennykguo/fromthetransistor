// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblinking_led.h for the primary calling header

#include "Vblinking_led__pch.h"
#include "Vblinking_led___024root.h"

VL_ATTR_COLD void Vblinking_led___024root___eval_static__TOP(Vblinking_led___024root* vlSelf);

VL_ATTR_COLD void Vblinking_led___024root___eval_static(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___eval_static\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vblinking_led___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vblinking_led___024root___eval_static__TOP(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___eval_static__TOP\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.blinking_led__DOT__count = 0U;
}

VL_ATTR_COLD void Vblinking_led___024root___eval_initial__TOP(Vblinking_led___024root* vlSelf);

VL_ATTR_COLD void Vblinking_led___024root___eval_initial(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___eval_initial\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vblinking_led___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vblinking_led___024root___eval_initial__TOP(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___eval_initial__TOP\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.led = 0U;
}

VL_ATTR_COLD void Vblinking_led___024root___eval_final(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___eval_final\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vblinking_led___024root___eval_settle(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___eval_settle\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vblinking_led___024root___dump_triggers__act(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___dump_triggers__act\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vblinking_led___024root___dump_triggers__nba(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___dump_triggers__nba\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vblinking_led___024root___ctor_var_reset(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___ctor_var_reset\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->led = VL_RAND_RESET_I(1);
    vlSelf->blinking_led__DOT__count = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
