#ifndef CGAMECTNMEDIABLOCKSOUND_HPP
#define CGAMECTNMEDIABLOCKSOUND_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockSound {
    void** vftable;
    byte _padding_0x4[32];
    int field_0x24; // accesses: 1
    byte _final_padding[0x2c]; // Total size: 0x54

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockSound *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKSOUND_HPP
