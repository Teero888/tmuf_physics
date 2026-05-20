#ifndef GMLOCVAL_HPP
#define GMLOCVAL_HPP

#include "typedefs.h"

struct GmLocVal {
    byte _padding_0x0[36];
    float field_0x24; // accesses: 1
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 1

    // Member Functions
    void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    void __thiscall SetLinearInterp (void *this,GmLensVal *param_1,GmLensVal *param_2,GmLensVal *param_3,float param_4);
};

#endif // GMLOCVAL_HPP
