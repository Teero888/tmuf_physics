#ifndef GMSCALETRANS2_HPP
#define GMSCALETRANS2_HPP

#include "typedefs.h"

struct GmScaleTrans2 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 8
    float field_0x8; // accesses: 8
    float field_0xc; // accesses: 8

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetRect_ConvTo_Rectm1p1(void *this,GmScaleTrans2 *param_1,GmRectAligned *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetRect_MoveTo_Rect (void *this,GmScaleTrans2 *param_1,GmRectAligned *param_2,GmRectAligned *param_3);
    void __thiscall LeftMult(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2);
    void __thiscall SetInverse(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2);
};

#endif // GMSCALETRANS2_HPP
