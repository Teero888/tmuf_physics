#ifndef CCONTROLQUAD_HPP
#define CCONTROLQUAD_HPP

#include "typedefs.h"

struct CControlQuad {
    void** vftable; // accesses: 1
    byte _padding_0x4[248];
    uint field_0xfc; // accesses: 2
    byte _padding_0x100[32];
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    undefined4 field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 1
    undefined4 field_0x130; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    int field_0x140; // accesses: 1

    // Member Functions
    void __thiscall AddMargin(CControlQuad *this,CControlQuad *param_1,GmBoxAligned *param_2);
    void __thiscall CControlQuad(CControlQuad *this,CControlQuad *param_1);
};

#endif // CCONTROLQUAD_HPP
