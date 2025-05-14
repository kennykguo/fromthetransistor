// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vblinking_led__Syms.h"


VL_ATTR_COLD void Vblinking_led___024root__trace_init_sub__TOP__0(Vblinking_led___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root__trace_init_sub__TOP__0\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"led",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("blinking_led", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"led",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vblinking_led___024root__trace_init_top(Vblinking_led___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root__trace_init_top\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vblinking_led___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vblinking_led___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vblinking_led___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vblinking_led___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vblinking_led___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vblinking_led___024root__trace_register(Vblinking_led___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root__trace_register\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vblinking_led___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vblinking_led___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vblinking_led___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vblinking_led___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vblinking_led___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root__trace_const_0\n"); );
    // Init
    Vblinking_led___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vblinking_led___024root*>(voidSelf);
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vblinking_led___024root__trace_full_0_sub_0(Vblinking_led___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vblinking_led___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root__trace_full_0\n"); );
    // Init
    Vblinking_led___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vblinking_led___024root*>(voidSelf);
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vblinking_led___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vblinking_led___024root__trace_full_0_sub_0(Vblinking_led___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinking_led___024root__trace_full_0_sub_0\n"); );
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.clk));
    bufp->fullBit(oldp+2,(vlSelfRef.led));
    bufp->fullIData(oldp+3,(vlSelfRef.blinking_led__DOT__count),32);
}
