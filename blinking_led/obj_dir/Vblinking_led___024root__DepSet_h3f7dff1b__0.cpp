// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblinking_led.h for the primary calling header

#include "Vblinking_led__pch.h"
#include "Vblinking_led__Syms.h"
#include "Vblinking_led___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vblinking_led___024root___dump_triggers__act(Vblinking_led___024root* vlSelf);
#endif  // VL_DEBUG

void Vblinking_led___024root___eval_triggers__act(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___eval_triggers__act\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vblinking_led___024root___dump_triggers__act(vlSelf);
    }
#endif
}
