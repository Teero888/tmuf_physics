#ifndef GXFOGBLENDER_HPP
#define GXFOGBLENDER_HPP

#include "typedefs.h"

struct GxFogBlender {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    byte _padding_0x8[12];
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    float field_0x1c; // accesses: 4
    float field_0x20; // accesses: 3
    float field_0x24; // accesses: 3
    float field_0x28; // accesses: 3
    float field_0x2c; // accesses: 3
    float field_0x30; // accesses: 3
    float field_0x34; // accesses: 3
    float field_0x38; // accesses: 3
    float field_0x3c; // accesses: 3

    // Member Functions
    void __thiscall BlendFogAtX_Wrap01 (GxFogBlender *this,GxFogBlender *param_1,GxFog *param_2,float param_3);
};

#endif // GXFOGBLENDER_HPP
