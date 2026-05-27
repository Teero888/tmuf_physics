#ifndef CMWPARAMFASTBUFFER_CLASS_CMWPARAMCLASS__HPP
#define CMWPARAMFASTBUFFER_CLASS_CMWPARAMCLASS__HPP

#include "typedefs.h"

struct CMwParamFastBuffer<class_CMwParamClass> {
    void** vftable;

    // Member Functions
    ulong __cdecl SubValue (CFastBufferCat<class_GmVec2,struct_SFastCat> *param_1,CMwStack *param_2,void *param_3);
    void __thiscall AddValue (CMwParamFastBuffer<class_CMwParamClass> *this,CMwStatsValue *param_1,float param_2);
};

#endif // CMWPARAMFASTBUFFER_CLASS_CMWPARAMCLASS__HPP
