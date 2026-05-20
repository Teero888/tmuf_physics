#ifndef CGAMECTNMEDIABLOCKTIME_HPP
#define CGAMECTNMEDIABLOCKTIME_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockTime {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    byte _padding_0x8[28];
    int field_0x24; // accesses: 1
    byte _padding_0x28[44];
    undefined4 * field_0x54; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockTime *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKTIME_HPP
