// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblinking_led.h for the primary calling header

#include "Vblinking_led__pch.h"
#include "Vblinking_led__Syms.h"
#include "Vblinking_led___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vblinking_led___024root___dump_triggers__stl(Vblinking_led___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vblinking_led___024root___eval_triggers__stl(Vblinking_led___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root___eval_triggers__stl\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vblinking_led___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
