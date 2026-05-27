#ifndef GMCOLLISION_HPP
#define GMCOLLISION_HPP

#include "typedefs.h"

struct GmCollision {
    float field_0x0; // accesses: 2
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 2
    float field_0xc; // accesses: 2
    float field_0x10; // accesses: 2
    float field_0x14; // accesses: 2
    byte _padding_0x18[12];
    float field_0x24; // accesses: 2
    float field_0x26; // accesses: 2
    byte _padding_0x2a[2];
    float field_0x2c; // accesses: 2
    float field_0x30; // accesses: 2
    float field_0x34; // accesses: 2

    // Member Functions
    void __thiscall Neg(void *this,GmCollision *param_1);
};

#endif // GMCOLLISION_HPP
