#ifndef CGAMECTNMEDIABLOCKFXCOLORS_HPP
#define CGAMECTNMEDIABLOCKFXCOLORS_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockFxColors {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    byte _padding_0x8[44];
    int field_0x34; // accesses: 1
    byte _padding_0x38[48];
    float field_0x68; // accesses: 3
    float field_0x6c; // accesses: 3
    SParam * field_0x70; // accesses: 2

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockFxColors *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKFXCOLORS_HPP
