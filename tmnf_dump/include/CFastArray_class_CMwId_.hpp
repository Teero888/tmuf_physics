#ifndef CFASTARRAY_CLASS_CMWID__HPP
#define CFASTARRAY_CLASS_CMWID__HPP

#include "typedefs.h"

struct CFastArray<class_CMwId> {
    void** vftable; // accesses: 3
    undefined4 * field_0x4; // accesses: 6

    // Member Functions
    void __thiscall AddTail (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,SFormat *param_2);
    void __thiscall SetCount (void *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2);
};

#endif // CFASTARRAY_CLASS_CMWID__HPP
