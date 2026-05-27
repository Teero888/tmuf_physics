#ifndef CFUNCCURVESREAL_HPP
#define CFUNCCURVESREAL_HPP

#include "typedefs.h"

struct CFuncCurvesReal {
    void** vftable;
    byte _padding_0x4[20];
    int field_0x18; // accesses: 1
    byte _final_padding[0xc]; // Total size: 0x28

    // Member Functions
    GmVec3 __thiscall GetValue(CFuncCurvesReal *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CFUNCCURVESREAL_HPP
