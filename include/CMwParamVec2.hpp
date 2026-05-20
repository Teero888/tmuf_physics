#ifndef CMWPARAMVEC2_HPP
#define CMWPARAMVEC2_HPP

#include "typedefs.h"

struct CMwParamVec2 {
    void** vftable;
    byte _final_padding[0x10]; // Total size: 0x14

    // Member Functions
    GmVec3 __thiscall GetValue(CMwParamVec2 *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CMWPARAMVEC2_HPP
