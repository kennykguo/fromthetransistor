// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart_top.h for the primary calling header

#include "Vuart_top__pch.h"
#include "Vuart_top__Syms.h"
#include "Vuart_top___024root.h"

void Vuart_top___024root___ctor_var_reset(Vuart_top___024root* vlSelf);

Vuart_top___024root::Vuart_top___024root(Vuart_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vuart_top___024root___ctor_var_reset(this);
}

void Vuart_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vuart_top___024root::~Vuart_top___024root() {
}
