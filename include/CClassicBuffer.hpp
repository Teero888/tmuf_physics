#ifndef CCLASSICBUFFER_HPP
#define CCLASSICBUFFER_HPP

#include "typedefs.h"

struct CClassicBuffer {
    void** vftable; // accesses: 39
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[4];
    uint field_0x10; // accesses: 1

    // Member Functions
    /* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */ /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ int __thiscall IsEqualBuffer (CClassicBuffer *this,CClassicBufferMemory *param_1,CClassicBufferMemory *param_2);
    /* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */ /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ ulong __thiscall Skip(CClassicBuffer *this,CClassicBuffer *param_1,ulong param_2);
    /* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */ /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall CopyFrom(CClassicBuffer *this,SParam_Set *param_1,SParam *param_2);
    /* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */ void __thiscall AddCompressedBlock (CClassicBuffer *this,CClassicBuffer *param_1,CClassicBufferMemory *param_2);
    CClassicBufferMemory * __thiscall CreateUncompressedBlock(CClassicBuffer *this,CClassicBuffer *param_1);
    int __thiscall ReadAll(CClassicBuffer *this,CClassicBuffer *param_1,void *param_2,ulong param_3);
    int __thiscall WriteAll(CClassicBuffer *this,CClassicBuffer *param_1,void *param_2,ulong param_3);
    void __thiscall CClassicBuffer(CClassicBuffer *this,CClassicBuffer *param_1);
    void __thiscall ~CClassicBuffer(CClassicBuffer *this,CClassicBuffer *param_1);
};

#endif // CCLASSICBUFFER_HPP
