#ifndef CGAMECTNMEDIABLOCKFXBLURDEPTH_HPP
#define CGAMECTNMEDIABLOCKFXBLURDEPTH_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockFxBlurDepth {
    void** vftable;
    byte _padding_0x4[48];
    int field_0x34; // accesses: 1
    byte _final_padding[0xc]; // Total size: 0x44

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x00738da8) */ /* WARNING: Removing unreachable block (ram,0x00738daa) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ GmVec3 __thiscall CGameCtnMediaBlockFxBlurDepth::GetValue (CGameCtnMediaBlockFxBlurDepth *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKFXBLURDEPTH_HPP
