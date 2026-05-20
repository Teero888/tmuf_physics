#ifndef CGAMECTNMEDIABLOCKMUSICEFFECT_HPP
#define CGAMECTNMEDIABLOCKMUSICEFFECT_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockMusicEffect {
    void** vftable;
    byte _padding_0x4[32];
    int field_0x24; // accesses: 1
    byte _final_padding[0x10]; // Total size: 0x38

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockMusicEffect *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKMUSICEFFECT_HPP
