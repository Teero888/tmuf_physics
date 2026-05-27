#ifndef CFASTSTRINGBASE_WCHAR_T__HPP
#define CFASTSTRINGBASE_WCHAR_T__HPP

#include "typedefs.h"

struct CClassicBufferMemory;

struct CFastStringBase<wchar_t> {
    void** vftable; // accesses: 6
    wchar_t * field_0x4; // accesses: 13

    // Member Functions
    void __thiscall AllocAtLeast (void *this,CFastStringBase<wchar_t> *param_1,ulong param_2,int param_3,SOldChars *param_4 );
    void __thiscall CopyAndClear (void *this,CFastStringBase<wchar_t> *param_1,CFastStringBase<wchar_t> *param_2);
    void __thiscall PreAlloc(void *this,CClassicBufferMemory *param_1,ulong param_2);
};

#endif // CFASTSTRINGBASE_WCHAR_T__HPP
