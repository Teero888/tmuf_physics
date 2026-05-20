#ifndef CSCENEFXVISIONK_HPP
#define CSCENEFXVISIONK_HPP

#include "typedefs.h"

struct ulong;

struct CSceneFxVisionK {
    byte _padding_0x0[172];
    float field_0xac; // accesses: 1
    byte _padding_0xb0[4];
    float field_0xb4; // accesses: 1
    float field_0xb8; // accesses: 1
    float field_0xbc; // accesses: 1
    int field_0xc0; // accesses: 1
    byte _padding_0xc4[84];
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
