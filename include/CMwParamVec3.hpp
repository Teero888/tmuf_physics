#ifndef CMWPARAMVEC3_HPP
#define CMWPARAMVEC3_HPP

#include "typedefs.h"

struct CMwParamVec3 {

    // Member Functions
    GmVec3 __thiscall GetValue(CMwParamVec3 *this,CFuncColorGradient *param_1,float param_2);
    void __thiscall SetValue(CMwParamVec3 *this,CMwCmdAffectParamBool *param_1);
};

#endif // CMWPARAMVEC3_HPP
