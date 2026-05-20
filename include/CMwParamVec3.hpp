#ifndef CMWPARAMVEC3_HPP
#define CMWPARAMVEC3_HPP

#include "typedefs.h"

struct CMwParamVec3 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[4];
    int field_0x10; // accesses: 1
    byte _padding_0x14[4];
    int field_0x18; // accesses: 2

    // Member Functions
    GmVec3 __thiscall GetValue(CMwParamVec3 *this,CFuncColorGradient *param_1,float param_2);
    void __thiscall SetValue(CMwParamVec3 *this,CMwCmdAffectParamBool *param_1);
};

#endif // CMWPARAMVEC3_HPP
