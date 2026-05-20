#ifndef GMSCALETRANS2_HPP
#define GMSCALETRANS2_HPP

#include "typedefs.h"

struct GmScaleTrans2 {
    void** vftable; // accesses: 18
    float field_0x4; // accesses: 15
    float field_0x8; // accesses: 15
    float field_0xc; // accesses: 15
    float field_0x10; // accesses: 2
    float field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    float field_0x24; // accesses: 1
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetRect_ConvTo_Rectm1p1(void *this,GmScaleTrans2 *param_1,GmRectAligned *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetRect_MoveTo_Rect (void *this,GmScaleTrans2 *param_1,GmRectAligned *param_2,GmRectAligned *param_3);
    void __thiscall LeftMult(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2);
    void __thiscall SetInverse(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2);
};

#endif // GMSCALETRANS2_HPP
