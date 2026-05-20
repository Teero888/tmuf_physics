#ifndef GXBGRACOLOR_HPP
#define GXBGRACOLOR_HPP

#include "typedefs.h"

struct GxBGRAColor {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
    float field_0x8; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetRealRGBA (void *this,GxBGRAColor *param_1,float param_2,float param_3,float param_4,float param_5);
};

#endif // GXBGRACOLOR_HPP
