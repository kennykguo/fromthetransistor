// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vblinking_led__pch.h"
#include "Vblinking_led.h"
#include "Vblinking_led___024root.h"

// FUNCTIONS
Vblinking_led__Syms::~Vblinking_led__Syms()
{
}

Vblinking_led__Syms::Vblinking_led__Syms(VerilatedContext* contextp, const char* namep, Vblinking_led* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(19);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
