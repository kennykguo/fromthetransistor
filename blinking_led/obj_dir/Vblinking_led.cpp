// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vblinking_led__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vblinking_led::Vblinking_led(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vblinking_led__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , led{vlSymsp->TOP.led}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vblinking_led::Vblinking_led(const char* _vcname__)
    : Vblinking_led(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vblinking_led::~Vblinking_led() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vblinking_led___024root___eval_debug_assertions(Vblinking_led___024root* vlSelf);
#endif  // VL_DEBUG
void Vblinking_led___024root___eval_static(Vblinking_led___024root* vlSelf);
void Vblinking_led___024root___eval_initial(Vblinking_led___024root* vlSelf);
void Vblinking_led___024root___eval_settle(Vblinking_led___024root* vlSelf);
void Vblinking_led___024root___eval(Vblinking_led___024root* vlSelf);

void Vblinking_led::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vblinking_led::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vblinking_led___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vblinking_led___024root___eval_static(&(vlSymsp->TOP));
        Vblinking_led___024root___eval_initial(&(vlSymsp->TOP));
        Vblinking_led___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vblinking_led___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vblinking_led::eventsPending() { return false; }

uint64_t Vblinking_led::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vblinking_led::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vblinking_led___024root___eval_final(Vblinking_led___024root* vlSelf);

VL_ATTR_COLD void Vblinking_led::final() {
    Vblinking_led___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vblinking_led::hierName() const { return vlSymsp->name(); }
const char* Vblinking_led::modelName() const { return "Vblinking_led"; }
unsigned Vblinking_led::threads() const { return 1; }
void Vblinking_led::prepareClone() const { contextp()->prepareClone(); }
void Vblinking_led::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vblinking_led::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vblinking_led___024root__trace_decl_types(VerilatedVcd* tracep);

void Vblinking_led___024root__trace_init_top(Vblinking_led___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vblinking_led___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vblinking_led___024root*>(voidSelf);
    Vblinking_led__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vblinking_led___024root__trace_decl_types(tracep);
    Vblinking_led___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vblinking_led___024root__trace_register(Vblinking_led___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vblinking_led::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vblinking_led::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vblinking_led___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
