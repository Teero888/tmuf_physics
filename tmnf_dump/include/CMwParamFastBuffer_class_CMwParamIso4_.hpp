#ifndef CMWPARAMFASTBUFFER_CLASS_CMWPARAMISO4__HPP
#define CMWPARAMFASTBUFFER_CLASS_CMWPARAMISO4__HPP

#include "typedefs.h"

struct CMwParamFastBuffer<class_CMwParamIso4> {
    void** vftable;

    // Member Functions
    GmVec3 __thiscall GetValue (CMwParamFastBuffer<class_CMwParamIso4> *this,CFuncColorGradient *param_1,float param_2);
    void __thiscall SetValue (CMwParamFastBuffer<class_CMwParamIso4> *this,CMwCmdAffectParamBool *param_1);
};

#endif // CMWPARAMFASTBUFFER_CLASS_CMWPARAMISO4__HPP
