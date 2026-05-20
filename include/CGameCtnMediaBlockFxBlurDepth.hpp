#ifndef CGAMECTNMEDIABLOCKFXBLURDEPTH_HPP
#define CGAMECTNMEDIABLOCKFXBLURDEPTH_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockFxBlurDepth {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    int field_0x8; // accesses: 2
    float field_0xc; // accesses: 2
    byte _padding_0x10[36];
    int field_0x34; // accesses: 1

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x00738da8) */ /* WARNING: Removing unreachable block (ram,0x00738daa) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ GmVec3 __thiscall CGameCtnMediaBlockFxBlurDepth::GetValue (CGameCtnMediaBlockFxBlurDepth *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKFXBLURDEPTH_HPP
