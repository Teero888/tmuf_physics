#ifndef CFASTARRAY_CLASS_GMVEC4__HPP
#define CFASTARRAY_CLASS_GMVEC4__HPP

#include "typedefs.h"

struct CFastArray<class_GmVec4> {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1

    // Member Functions
    void __thiscall CopyFromFastArray (void *this,CFastArray<class_GmVec4> *param_1,CFastArray<class_GmVec4> *param_2);
};

#endif // CFASTARRAY_CLASS_GMVEC4__HPP
