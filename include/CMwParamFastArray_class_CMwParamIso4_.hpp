#ifndef CMWPARAMFASTARRAY_CLASS_CMWPARAMISO4__HPP
#define CMWPARAMFASTARRAY_CLASS_CMWPARAMISO4__HPP

#include "typedefs.h"

struct CMwParamFastArray<class_CMwParamIso4> {
    byte _padding_0x0[4];
    ulong * field_0x4; // accesses: 1
    byte _padding_0x8[8];
    int field_0x10; // accesses: 1
    int field_0x14; // accesses: 1
    int field_0x18; // accesses: 2

    // Member Functions
    GmVec4 * __cdecl GetElemFromStack (CFastBufferCat<class_GmVec4,struct_SFastCat> *param_1,CMwStack *param_2);
};

#endif // CMWPARAMFASTARRAY_CLASS_CMWPARAMISO4__HPP
