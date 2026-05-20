#ifndef GMLOCFREEVAL_HPP
#define GMLOCFREEVAL_HPP

#include "typedefs.h"

struct GmIso4;

struct GmLocFreeVal {
    float field_0x0; // accesses: 2
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 2
    GmIso4 * field_0xc; // accesses: 2
    GmIso4 * field_0x10; // accesses: 2
    GmIso4 * field_0x14; // accesses: 2

    // Member Functions
    void __thiscall GetLocVal(void *this,GmLocFreeVal *param_1,GmLocVal *param_2);
    void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
};

#endif // GMLOCFREEVAL_HPP
