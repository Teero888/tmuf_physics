#ifndef CMWPARAMFASTBUFFER_CLASS_CMWPARAMREAL__HPP
#define CMWPARAMFASTBUFFER_CLASS_CMWPARAMREAL__HPP

#include "typedefs.h"

struct CMwParamFastBuffer<class_CMwParamReal> {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 1

    // Member Functions
    void __thiscall SetValue (CMwParamFastBuffer<class_CMwParamReal> *this,CMwCmdAffectParamBool *param_1);
};

#endif // CMWPARAMFASTBUFFER_CLASS_CMWPARAMREAL__HPP
