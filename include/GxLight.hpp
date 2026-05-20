#ifndef GXLIGHT_HPP
#define GXLIGHT_HPP

#include "typedefs.h"

struct GxLight {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 2
    byte _padding_0xc[12];
    float field_0x18; // accesses: 4
    float field_0x1c; // accesses: 4
    float field_0x20; // accesses: 4
    float field_0x24; // accesses: 3
    float field_0x28; // accesses: 2
    float field_0x2c; // accesses: 2
    float field_0x30; // accesses: 2
    float field_0x34; // accesses: 2

    // Member Functions
    GmVec3 __thiscall GetIntensRGB(GxLight *this,GxLight *param_1);
    void __thiscall SetBaseRGB(GxLight *this,GxLight *param_1,GmVec3 *param_2);
    void __thiscall SetIntensity(GxLight *this,GxLight *param_1,float param_2);
};

#endif // GXLIGHT_HPP
