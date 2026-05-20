#ifndef CGAMECTNMEDIABLOCKFXCOLORS_HPP
#define CGAMECTNMEDIABLOCKFXCOLORS_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockFxColors {
    byte _padding_0x0[52];
    int field_0x34; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockFxColors *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKFXCOLORS_HPP
