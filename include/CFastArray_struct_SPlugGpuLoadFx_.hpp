#ifndef CFASTARRAY_STRUCT_SPLUGGPULOADFX__HPP
#define CFASTARRAY_STRUCT_SPLUGGPULOADFX__HPP

#include "typedefs.h"

struct CFastArray<struct_SPlugGpuLoadFx> {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2

    // Member Functions
    int __thiscall AreEqual (void *this,CDx9StateBlock *param_1,CDx9StateBlock *param_2);
    ulong __thiscall GetIndexFromAdr (void *this,CFastArray<struct_SPlugGpuLoadFx> *param_1,SPlugGpuLoadFx *param_2);
    void __thiscall CopyFromFastArray (void *this,CFastArray<class_GmVec4> *param_1,CFastArray<class_GmVec4> *param_2);
    void __thiscall SetArray (void *this,CFastArray<struct_SPlugGpuLoadFx> *param_1,ulong param_2, SPlugGpuLoadFx *param_3);
    void __thiscall SetCount (void *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2);
};

#endif // CFASTARRAY_STRUCT_SPLUGGPULOADFX__HPP
