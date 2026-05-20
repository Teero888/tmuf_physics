#ifndef CFASTARRAY_CLASS_GXTEXCOORDSET__HPP
#define CFASTARRAY_CLASS_GXTEXCOORDSET__HPP

#include "typedefs.h"

struct SFormat;

struct CFastArray<class_GxTexCoordSet> {
    void** vftable; // accesses: 6
    void * field_0x4; // accesses: 8
    int field_0x8; // accesses: 1

    // Member Functions
    void __thiscall AddTail (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,SFormat *param_2);
    void __thiscall SetCount (void *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2);
};

#endif // CFASTARRAY_CLASS_GXTEXCOORDSET__HPP
