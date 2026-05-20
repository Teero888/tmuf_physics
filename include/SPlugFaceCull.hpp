#ifndef SPLUGFACECULL_HPP
#define SPLUGFACECULL_HPP

#include "typedefs.h"

struct SPlugFaceCull {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 5
    float field_0x8; // accesses: 3
    float field_0xc; // accesses: 2
    float field_0x10; // accesses: 2
    float field_0x14; // accesses: 2
    float field_0x18; // accesses: 2
    float field_0x1c; // accesses: 2
    float field_0x20; // accesses: 2
    float field_0x24; // accesses: 1
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 1

    // Member Functions
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
};

#endif // SPLUGFACECULL_HPP
