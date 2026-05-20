#ifndef GMCAMFREEVAL_HPP
#define GMCAMFREEVAL_HPP

#include "typedefs.h"

struct GmCamFreeVal {
    byte _padding_0x0[48];
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1

    // Member Functions
    void __thiscall GetCamVal(void *this,GmCamFreeVal *param_1,GmCamVal *param_2);
};

#endif // GMCAMFREEVAL_HPP
