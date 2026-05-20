#ifndef GMCAMFREEVAL_HPP
#define GMCAMFREEVAL_HPP

#include "typedefs.h"

struct GmCamFreeVal {
    byte _padding_0x0[24];
    float field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    float field_0x24; // accesses: 1
    float field_0x28; // accesses: 1

    // Member Functions
    void __thiscall GetCamVal(void *this,GmCamFreeVal *param_1,GmCamVal *param_2);
};

#endif // GMCAMFREEVAL_HPP
