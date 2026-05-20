#ifndef CGAMECTNMEDIABLOCKFXBLOOM_HPP
#define CGAMECTNMEDIABLOCKFXBLOOM_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockFxBloom {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    byte _padding_0xc[40];
    int field_0x34; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockFxBloom *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKFXBLOOM_HPP
