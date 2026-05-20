#ifndef CSCENEFXVISIONK_HPP
#define CSCENEFXVISIONK_HPP

#include "typedefs.h"

struct CSceneFxVisionK {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 16
    undefined4 field_0x8; // accesses: 16
    undefined4 field_0xc; // accesses: 23
    undefined4 field_0x10; // accesses: 25
    undefined4 field_0x14; // accesses: 25
    undefined4 field_0x18; // accesses: 7
    undefined4 field_0x1c; // accesses: 7
    undefined4 field_0x20; // accesses: 7
    undefined4 field_0x24; // accesses: 9
    byte _padding_0x28[132];
    float field_0xac; // accesses: 2
    byte _padding_0xb0[4];
    float field_0xb4; // accesses: 1
    float field_0xb8; // accesses: 1
    float field_0xbc; // accesses: 1
    int field_0xc0; // accesses: 1
    byte _padding_0xc4[4];
    float field_0xc8; // accesses: 2
    byte _padding_0xcc[76];
    int field_0x118; // accesses: 3
    byte _padding_0x11c[8];
    undefined4 field_0x124; // accesses: 4
    byte _padding_0x128[4];
    int field_0x12c; // accesses: 7
    ulong field_0x130; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall BranchingArc_Step(CSceneFxVisionK *this,CSceneFxVisionK *param_1);
};

#endif // CSCENEFXVISIONK_HPP
