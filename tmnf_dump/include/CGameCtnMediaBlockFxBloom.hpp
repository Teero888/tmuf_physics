#ifndef CGAMECTNMEDIABLOCKFXBLOOM_HPP
#define CGAMECTNMEDIABLOCKFXBLOOM_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockFxBloom {
    void** vftable;
    byte _padding_0x4[48];
    int field_0x34; // accesses: 1
    byte _final_padding[0xc]; // Total size: 0x44

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockFxBloom *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKFXBLOOM_HPP
