#ifndef CFUNCCURVESREAL_HPP
#define CFUNCCURVESREAL_HPP

#include "typedefs.h"

struct CFuncCurvesReal {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue(CFuncCurvesReal *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CFUNCCURVESREAL_HPP
