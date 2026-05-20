#ifndef SPLUGFACECULL_HPP
#define SPLUGFACECULL_HPP

#include "typedefs.h"

struct SPlugFaceCull {
    void** vftable; // accesses: 33
    float field_0x4; // accesses: 33
    float field_0x8; // accesses: 33
    float field_0xc; // accesses: 32
    float field_0x10; // accesses: 19
    float field_0x14; // accesses: 19
    float field_0x18; // accesses: 13
    float field_0x1c; // accesses: 13
    float field_0x20; // accesses: 13
    float field_0x24; // accesses: 6
    float field_0x28; // accesses: 6
    float field_0x2c; // accesses: 6

    // Member Functions
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
};

#endif // SPLUGFACECULL_HPP
