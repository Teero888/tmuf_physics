#ifndef CMWPARAMISO3_HPP
#define CMWPARAMISO3_HPP

#include "typedefs.h"

struct CMwParamIso3 {
    void** vftable;
    byte _final_padding[0x10]; // Total size: 0x14

    // Member Functions
    GmVec3 __thiscall GetValue(CMwParamIso3 *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CMWPARAMISO3_HPP
