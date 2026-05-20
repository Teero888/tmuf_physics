#ifndef GXFOGBLENDER_HPP
#define GXFOGBLENDER_HPP

#include "typedefs.h"

struct GxFogBlender {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 * field_0x1c; // accesses: 1

    // Member Functions
    void __thiscall BlendFogAtX_Wrap01 (GxFogBlender *this,GxFogBlender *param_1,GxFog *param_2,float param_3);
};

#endif // GXFOGBLENDER_HPP
