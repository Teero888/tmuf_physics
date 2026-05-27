#ifndef GMLENSVAL_HPP
#define GMLENSVAL_HPP

#include "typedefs.h"

struct GmLensVal {
    float field_0x0; // accesses: 2
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 2
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 5

    // Member Functions
    void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    void __thiscall SetLinearInterp (void *this,GmLensVal *param_1,GmLensVal *param_2,GmLensVal *param_3,float param_4);
};

#endif // GMLENSVAL_HPP
