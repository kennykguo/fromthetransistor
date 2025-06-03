// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vuart_top__pch.h"

//============================================================
// Constructors

Vuart_top::Vuart_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vuart_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , write_data{vlSymsp->TOP.write_data}
    , write_enable{vlSymsp->TOP.write_enable}
    , read_data{vlSymsp->TOP.read_data}
    , read_enable{vlSymsp->TOP.read_enable}
    , addr{vlSymsp->TOP.addr}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vuart_top::Vuart_top(const char* _vcname__)
    : Vuart_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vuart_top::~Vuart_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vuart_top___024root___eval_debug_assertions(Vuart_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vuart_top___024root___eval_static(Vuart_top___024root* vlSelf);
void Vuart_top___024root___eval_initial(Vuart_top___024root* vlSelf);
void Vuart_top___024root___eval_settle(Vuart_top___024root* vlSelf);
void Vuart_top___024root___eval(Vuart_top___024root* vlSelf);

void Vuart_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vuart_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vuart_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vuart_top___024root___eval_static(&(vlSymsp->TOP));
        Vuart_top___024root___eval_initial(&(vlSymsp->TOP));
        Vuart_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vuart_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vuart_top::eventsPending() { return false; }

uint64_t Vuart_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vuart_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vuart_top___024root___eval_final(Vuart_top___024root* vlSelf);

VL_ATTR_COLD void Vuart_top::final() {
    Vuart_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vuart_top::hierName() const { return vlSymsp->name(); }
const char* Vuart_top::modelName() const { return "Vuart_top"; }
unsigned Vuart_top::threads() const { return 1; }
void Vuart_top::prepareClone() const { contextp()->prepareClone(); }
void Vuart_top::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vuart_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vuart_top::trace()' called on model that was Verilated without --trace option");
}
