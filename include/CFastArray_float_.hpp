#ifndef CFASTARRAY_FLOAT__HPP
#define CFASTARRAY_FLOAT__HPP

#include "typedefs.h"

struct CFastArray<float> {

    // Member Functions
    void __thiscall AddTail (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,SFormat *param_2);
    void __thiscall InsertAt (void *this,CFastArray<class_CControlBase*> *param_1,ulong param_2,CControlBase **param_3);
    void __thiscall SetCount(void *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2);
};

#endif // CFASTARRAY_FLOAT__HPP
