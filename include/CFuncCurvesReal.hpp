#ifndef CFUNCCURVESREAL_HPP
#define CFUNCCURVESREAL_HPP

#include "typedefs.h"

struct CFuncKeysReal;

struct CFuncCurvesReal {
    byte _padding_0x0[4];
    CFuncKeysReal * field_0x4; // accesses: 2
    byte _padding_0x8[16];
    int field_0x18; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue(CFuncCurvesReal *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CFUNCCURVESREAL_HPP
