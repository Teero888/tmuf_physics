#ifndef CGAMECTNMEDIABLOCKSOUND_HPP
#define CGAMECTNMEDIABLOCKSOUND_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockSound {
    byte _padding_0x0[36];
    int field_0x24; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockSound *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKSOUND_HPP
