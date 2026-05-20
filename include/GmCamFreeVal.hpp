#ifndef GMCAMFREEVAL_HPP
#define GMCAMFREEVAL_HPP

#include "typedefs.h"

struct GmCamFreeVal {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    byte _padding_0x2c[4];
    float field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    float field_0x3c; // accesses: 4
    float field_0x40; // accesses: 3

    // Member Functions
    void __thiscall GetCamVal(void *this,GmCamFreeVal *param_1,GmCamVal *param_2);
};

#endif // GMCAMFREEVAL_HPP
