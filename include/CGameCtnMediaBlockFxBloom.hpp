#ifndef CGAMECTNMEDIABLOCKFXBLOOM_HPP
#define CGAMECTNMEDIABLOCKFXBLOOM_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockFxBloom {
    byte _padding_0x0[52];
    int field_0x34; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockFxBloom *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKFXBLOOM_HPP
