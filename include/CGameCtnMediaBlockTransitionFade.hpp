#ifndef CGAMECTNMEDIABLOCKTRANSITIONFADE_HPP
#define CGAMECTNMEDIABLOCKTRANSITIONFADE_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockTransitionFade {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    byte _padding_0x8[28];
    int field_0x24; // accesses: 1
    byte _padding_0x28[36];
    float field_0x4c; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockTransitionFade *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKTRANSITIONFADE_HPP
