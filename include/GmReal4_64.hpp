#ifndef GMREAL4_64_HPP
#define GMREAL4_64_HPP

#include "typedefs.h"

struct GmReal4_64 {
    void** vftable; // accesses: 18
    byte _padding_0x4[4];
    double field_0x8; // accesses: 2
    byte _padding_0xc[4];
    double field_0x10; // accesses: 2
    byte _padding_0x14[4];
    double field_0x18; // accesses: 5

    // Member Functions
    void __thiscall GetClipFlag(void *this,GmReal4_64 *param_1,GmClipFlag_HalfCube *param_2);
};

#endif // GMREAL4_64_HPP
