#ifndef CGAMECTNMEDIABLOCKFXCOLORS_HPP
#define CGAMECTNMEDIABLOCKFXCOLORS_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockFxColors {
    void** vftable;
    byte _padding_0x4[48];
    int field_0x34; // accesses: 1
    byte _final_padding[0xc]; // Total size: 0x44

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockFxColors *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKFXCOLORS_HPP
