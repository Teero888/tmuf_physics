#ifndef GXCOLOR_HPP
#define GXCOLOR_HPP

#include "typedefs.h"

struct GmVec3;

struct GxColor {
    GxColor * field_0x0; // accesses: 19
    GxColor * field_0x4; // accesses: 17
    GxColor * field_0x8; // accesses: 17
    GmVec3 * field_0xc; // accesses: 7

    // Member Functions
    void __thiscall GetHLS(void *this,GxColor *param_1,GmVec3 *param_2);
    void __thiscall GetHSV(void *this,GxColor *param_1,GmVec3 *param_2);
    void __thiscall SetFromBGRA(void *this,GmVec3 *param_1,uchar *param_2,ulong param_3);
    void __thiscall SetHLS(void *this,GxColor *param_1,GmVec3 *param_2,float param_3);
    void __thiscall SetHSV(void *this,GxColor *param_1,GmVec3 *param_2,float param_3);
};

#endif // GXCOLOR_HPP
