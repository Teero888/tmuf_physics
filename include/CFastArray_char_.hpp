#ifndef CFASTARRAY_CHAR__HPP
#define CFASTARRAY_CHAR__HPP

#include "typedefs.h"

struct CFastArray<char> {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 4

    // Member Functions
    void __thiscall SetCount (CFastArray<char> *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2);
};

#endif // CFASTARRAY_CHAR__HPP
