#ifndef GMLOCFREEVAL_HPP
#define GMLOCFREEVAL_HPP

#include "typedefs.h"

struct GmIso4;

struct GmLocFreeVal {
    void** vftable; // accesses: 2
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    GmIso4 * field_0xc; // accesses: 2
    GmIso4 * field_0x10; // accesses: 2
    GmIso4 * field_0x14; // accesses: 2
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[8];
    GmLocFreeVal * field_0x38; // accesses: 1

    // Member Functions
    void __thiscall GetLocVal(void *this,GmLocFreeVal *param_1,GmLocVal *param_2);
    void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
};

#endif // GMLOCFREEVAL_HPP
