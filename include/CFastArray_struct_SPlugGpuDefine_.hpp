#ifndef CFASTARRAY_STRUCT_SPLUGGPUDEFINE__HPP
#define CFASTARRAY_STRUCT_SPLUGGPUDEFINE__HPP

#include "typedefs.h"

struct SPackedDesc;

struct CFastArray<struct_SPlugGpuDefine> {
    void** vftable; // accesses: 2
    int field_0x4; // accesses: 2

    // Member Functions
    SPackedDesc * __thiscall AddNewTailElem (void *this,CFastArray<struct_CDx9StateBlock::SPackedDesc> *param_1);
};

#endif // CFASTARRAY_STRUCT_SPLUGGPUDEFINE__HPP
