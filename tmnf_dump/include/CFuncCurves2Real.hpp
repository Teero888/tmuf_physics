#ifndef CFUNCCURVES2REAL_HPP
#define CFUNCCURVES2REAL_HPP

#include "typedefs.h"

struct CFuncCurves2Real {
    void** vftable;
    byte _padding_0x4[20];
    int field_0x18; // accesses: 1
    byte _final_padding[0xc]; // Total size: 0x28

    // Member Functions
    GmVec3 __thiscall GetValue(CFuncCurves2Real *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CFUNCCURVES2REAL_HPP
