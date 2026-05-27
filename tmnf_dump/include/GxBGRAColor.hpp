#ifndef GXBGRACOLOR_HPP
#define GXBGRACOLOR_HPP

#include "typedefs.h"

struct GxBGRAColor {
    undefined1 field_0x0; // accesses: 2
    undefined1 field_0x1; // accesses: 2
    undefined1 field_0x2; // accesses: 2
    undefined1 field_0x3; // accesses: 2

    // Member Functions
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetRealRGBA (void *this,GxBGRAColor *param_1,float param_2,float param_3,float param_4,float param_5);
};

#endif // GXBGRACOLOR_HPP
