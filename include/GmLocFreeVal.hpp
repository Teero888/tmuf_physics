#ifndef GMLOCFREEVAL_HPP
#define GMLOCFREEVAL_HPP

#include "typedefs.h"

struct GmLocFreeVal {
    byte _padding_0x0[36];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1

    // Member Functions
    void __thiscall GetLocVal(void *this,GmLocFreeVal *param_1,GmLocVal *param_2);
    void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
};

#endif // GMLOCFREEVAL_HPP
