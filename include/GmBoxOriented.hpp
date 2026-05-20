#ifndef GMBOXORIENTED_HPP
#define GMBOXORIENTED_HPP

#include "typedefs.h"

struct GmBoxOriented {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 3
    float field_0x14; // accesses: 3
    float field_0x18; // accesses: 3
    float field_0x1c; // accesses: 3
    float field_0x20; // accesses: 3

    // Member Functions
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
};

#endif // GMBOXORIENTED_HPP
