#ifndef CFUNCCURVES2REAL_HPP
#define CFUNCCURVES2REAL_HPP

#include "typedefs.h"

struct CFuncCurves2Real {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue(CFuncCurves2Real *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CFUNCCURVES2REAL_HPP
