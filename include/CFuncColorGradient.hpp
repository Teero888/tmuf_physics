#ifndef CFUNCCOLORGRADIENT_HPP
#define CFUNCCOLORGRADIENT_HPP

#include "typedefs.h"

struct CFuncColorGradient {
    void** vftable;
    byte _padding_0x4[16];
    float field_0x14; // accesses: 2
    float field_0x18; // accesses: 2
    float field_0x1c; // accesses: 2
    float field_0x20; // accesses: 3
    float field_0x24; // accesses: 3
    float field_0x28; // accesses: 3
    float field_0x2c; // accesses: 3
    float field_0x30; // accesses: 3
    float field_0x34; // accesses: 3
    float field_0x38; // accesses: 1
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 4
    float field_0x48; // accesses: 4

    // Member Functions
    GmVec3 __thiscall GetValue(CFuncColorGradient *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CFUNCCOLORGRADIENT_HPP
