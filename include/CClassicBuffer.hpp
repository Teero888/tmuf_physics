#ifndef CCLASSICBUFFER_HPP
#define CCLASSICBUFFER_HPP

#include "typedefs.h"

struct CClassicBuffer {
    void** vftable; // accesses: 16
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1

    // Member Functions
    CClassicBufferMemory * __thiscall CreateUncompressedBlock(CClassicBuffer *this,CClassicBuffer *param_1);
    int __thiscall IsEqualBuffer (CClassicBuffer *this,CClassicBufferMemory *param_1,CClassicBufferMemory *param_2);
    int __thiscall ReadAll(CClassicBuffer *this,CClassicBuffer *param_1,void *param_2,ulong param_3);
    int __thiscall WriteAll(CClassicBuffer *this,CClassicBuffer *param_1,void *param_2,ulong param_3);
    ulong __thiscall Skip(CClassicBuffer *this,CClassicBuffer *param_1,ulong param_2);
    void __thiscall AddCompressedBlock (CClassicBuffer *this,CClassicBuffer *param_1,CClassicBufferMemory *param_2);
    void __thiscall CClassicBuffer(CClassicBuffer *this,CClassicBuffer *param_1);
    void __thiscall CopyFrom(CClassicBuffer *this,SParam_Set *param_1,SParam *param_2);
    void __thiscall ~CClassicBuffer(CClassicBuffer *this,CClassicBuffer *param_1);
};

#endif // CCLASSICBUFFER_HPP
