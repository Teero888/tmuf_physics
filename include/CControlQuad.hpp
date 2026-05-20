#ifndef CCONTROLQUAD_HPP
#define CCONTROLQUAD_HPP

#include "typedefs.h"

struct CMwRefBuffer;

struct CControlQuad {
    byte _padding_0x0[60];
    float field_0x3c; // accesses: 1
    byte _padding_0x40[12];
    CMwRefBuffer * field_0x4c; // accesses: 2
    byte _padding_0x50[172];
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
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CControlQuad(CControlQuad *this,CControlQuad *param_1);
    void __thiscall AddMargin(CControlQuad *this,CControlQuad *param_1,GmBoxAligned *param_2);
};

#endif // CCONTROLQUAD_HPP
