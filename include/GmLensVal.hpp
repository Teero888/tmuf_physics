#ifndef GMLENSVAL_HPP
#define GMLENSVAL_HPP

#include "typedefs.h"

struct GmLensVal {
    void** vftable; // accesses: 5
    float field_0x4; // accesses: 5
    float field_0x8; // accesses: 5
    float field_0xc; // accesses: 14
    float field_0x10; // accesses: 16

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetLinearInterp (void *this,GmLensVal *param_1,GmLensVal *param_2,GmLensVal *param_3,float param_4);
};

#endif // GMLENSVAL_HPP
