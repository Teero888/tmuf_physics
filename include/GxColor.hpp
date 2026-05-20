#ifndef GXCOLOR_HPP
#define GXCOLOR_HPP

#include "typedefs.h"

struct GmVec3;

struct GxColor {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 16
    GxColor * field_0x8; // accesses: 19
    GmVec3 * field_0xc; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetHLS(void *this,GxColor *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetHSV(void *this,GxColor *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetHLS(void *this,GxColor *param_1,GmVec3 *param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetHSV(void *this,GxColor *param_1,GmVec3 *param_2,float param_3);
    /* WARNING: Removing unreachable block (ram,0x0071d12a) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GxColor::SetFromBGRA(void *this,GmVec3 *param_1,uchar *param_2,ulong param_3);
};

#endif // GXCOLOR_HPP
