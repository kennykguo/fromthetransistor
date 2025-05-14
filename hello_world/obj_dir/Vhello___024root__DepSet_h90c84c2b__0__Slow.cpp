// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhello.h for the primary calling header

#include "Vhello__pch.h"
#include "Vhello___024root.h"

VL_ATTR_COLD void Vhello___024root___eval_static(Vhello___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___024root___eval_static\n"); );
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vhello___024root___eval_initial__TOP(Vhello___024root* vlSelf);

VL_ATTR_COLD void Vhello___024root___eval_initial(Vhello___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___024root___eval_initial\n"); );
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vhello___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vhello___024root___eval_initial__TOP(Vhello___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___024root___eval_initial__TOP\n"); );
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("Hello World!\n",0);
}

VL_ATTR_COLD void Vhello___024root___eval_final(Vhello___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___024root___eval_final\n"); );
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vhello___024root___eval_settle(Vhello___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___024root___eval_settle\n"); );
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhello___024root___dump_triggers__act(Vhello___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___024root___dump_triggers__act\n"); );
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhello___024root___dump_triggers__nba(Vhello___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___024root___dump_triggers__nba\n"); );
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vhello___024root___ctor_var_reset(Vhello___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___024root___ctor_var_reset\n"); );
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
