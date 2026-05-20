#ifndef CFASTARRAY_CLASS_GMVEC3__HPP
#define CFASTARRAY_CLASS_GMVEC3__HPP

#include "typedefs.h"

struct CControlBase;

struct CFastArray<class_GmVec3> {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2

    // Member Functions
    void __thiscall AllocateMore (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,ulong param_2);
    void __thiscall InsertAt (void *this,CFastArray<class_CControlBase*> *param_1,ulong param_2,CControlBase **param_3);
    void __thiscall SetArray (void *this,CFastArray<struct_SPlugGpuLoadFx> *param_1,ulong param_2, SPlugGpuLoadFx *param_3);
    void __thiscall SetCount (void *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2);
};

#endif // CFASTARRAY_CLASS_GMVEC3__HPP
