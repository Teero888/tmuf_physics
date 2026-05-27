#ifndef GMBOXORIENTED_HPP
#define GMBOXORIENTED_HPP

#include "typedefs.h"

struct GmBoxOriented {
    float field_0x0; // accesses: 1
    float field_0x4; // accesses: 1
    float field_0x8; // accesses: 1
    float field_0xc; // accesses: 1
    float field_0x10; // accesses: 1
    float field_0x14; // accesses: 1
    float field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    byte _final_padding[0x1c]; // Total size: 0x40

    // Member Functions
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
};

#endif // GMBOXORIENTED_HPP
