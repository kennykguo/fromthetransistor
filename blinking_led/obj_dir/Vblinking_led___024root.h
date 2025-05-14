// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vblinking_led.h for the primary calling header

#ifndef VERILATED_VBLINKING_LED___024ROOT_H_
#define VERILATED_VBLINKING_LED___024ROOT_H_  // guard

#include "verilated.h"


class Vblinking_led__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vblinking_led___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_OUT8(led,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ blinking_led__DOT__count;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vblinking_led__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vblinking_led___024root(Vblinking_led__Syms* symsp, const char* v__name);
    ~Vblinking_led___024root();
    VL_UNCOPYABLE(Vblinking_led___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
