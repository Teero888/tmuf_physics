#ifndef CMWPARAMCLASS_HPP
#define CMWPARAMCLASS_HPP

#include "typedefs.h"

struct CMwParamClass {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue(CMwParamClass *this,CFuncColorGradient *param_1,float param_2);
    void __thiscall SetValue(CMwParamClass *this,CMwCmdAffectParamBool *param_1);
};

#endif // CMWPARAMCLASS_HPP
