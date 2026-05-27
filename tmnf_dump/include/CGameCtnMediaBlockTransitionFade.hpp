#ifndef CGAMECTNMEDIABLOCKTRANSITIONFADE_HPP
#define CGAMECTNMEDIABLOCKTRANSITIONFADE_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockTransitionFade {
    void** vftable;
    byte _padding_0x4[32];
    int field_0x24; // accesses: 1
    byte _padding_0x28[36];
    float field_0x4c; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockTransitionFade *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKTRANSITIONFADE_HPP
