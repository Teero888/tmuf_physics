#ifndef CHMSOCCLUSION_HPP
#define CHMSOCCLUSION_HPP

#include "typedefs.h"

struct CHmsOcclusion {
    void** vftable;
    float field_0x4; // accesses: 1
    float field_0x8; // accesses: 1
    float field_0xc; // accesses: 1
    byte _padding_0x10[176];
    float field_0xc0; // accesses: 1
    float field_0xc4; // accesses: 1
    float field_0xc8; // accesses: 1

    // Member Functions
    void __thiscall UpdateInput(void *this,CGameCtnPainter *param_1);
};

#endif // CHMSOCCLUSION_HPP
