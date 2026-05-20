#ifndef CFUNCKEYSREAL_HPP
#define CFUNCKEYSREAL_HPP

#include "typedefs.h"

struct CFuncKeysReal {
    void** vftable; // accesses: 1
    byte _padding_0x4[36];
    float * field_0x28; // accesses: 2

    // Member Functions
    GmVec3 __thiscall GetValue(CFuncKeysReal *this,CFuncColorGradient *param_1,float param_2);
    ulong __thiscall InsertKeyReal(CFuncKeysReal *this,CFuncKeysReal *param_1,float param_2,float param_3);
    void __thiscall CFuncKeysReal(CFuncKeysReal *this,CFuncKeysReal *param_1);
    void __thiscall GetRealAt (CFuncKeysReal *this,CFuncKeysReal *param_1,float param_2,float *param_3,ulong *param_4, ulong *param_5,float *param_6,ERealInterp param_7,int param_8);
};

#endif // CFUNCKEYSREAL_HPP
