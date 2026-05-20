#ifndef CCONTROLFRAME_HPP
#define CCONTROLFRAME_HPP

#include "typedefs.h"

struct CControlFrame {
    void** vftable; // accesses: 2
    byte _padding_0x4[140];
    undefined4 field_0x90; // accesses: 1
    byte _padding_0x94[116];
    undefined4 field_0x108; // accesses: 1
    undefined4 field_0x10c; // accesses: 1

    // Member Functions
    void __thiscall CControlFrame(CControlFrame *this,CControlFrame *param_1);
};

#endif // CCONTROLFRAME_HPP
