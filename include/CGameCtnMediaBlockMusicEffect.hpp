#ifndef CGAMECTNMEDIABLOCKMUSICEFFECT_HPP
#define CGAMECTNMEDIABLOCKMUSICEFFECT_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockMusicEffect {
    byte _padding_0x0[36];
    int field_0x24; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockMusicEffect *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKMUSICEFFECT_HPP
