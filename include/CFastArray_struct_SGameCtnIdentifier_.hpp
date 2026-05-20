#ifndef CFASTARRAY_STRUCT_SGAMECTNIDENTIFIER__HPP
#define CFASTARRAY_STRUCT_SGAMECTNIDENTIFIER__HPP

#include "typedefs.h"

struct CFastArray<struct_SGameCtnIdentifier> {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2

    // Member Functions
    int __thiscall IsEmpty(void *this,SShaderCustom *param_1);
    void __thiscall AddTail (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,SFormat *param_2);
};

#endif // CFASTARRAY_STRUCT_SGAMECTNIDENTIFIER__HPP
