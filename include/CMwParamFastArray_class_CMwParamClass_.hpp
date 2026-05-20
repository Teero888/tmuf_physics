#ifndef CMWPARAMFASTARRAY_CLASS_CMWPARAMCLASS__HPP
#define CMWPARAMFASTARRAY_CLASS_CMWPARAMCLASS__HPP

#include "typedefs.h"

struct CMwParamFastArray<class_CMwParamClass> {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 2

    // Member Functions
    ulong __cdecl SubValue (CFastBufferCat<class_GmVec2,struct_SFastCat> *param_1,CMwStack *param_2,void *param_3);
};

#endif // CMWPARAMFASTARRAY_CLASS_CMWPARAMCLASS__HPP
