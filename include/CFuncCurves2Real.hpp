#ifndef CFUNCCURVES2REAL_HPP
#define CFUNCCURVES2REAL_HPP

#include "typedefs.h"

struct CFuncCurvesReal;

struct CFuncCurves2Real {
    byte _padding_0x0[4];
    CFuncCurvesReal * field_0x4; // accesses: 2
    byte _padding_0x8[16];
    int field_0x18; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue(CFuncCurves2Real *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CFUNCCURVES2REAL_HPP
