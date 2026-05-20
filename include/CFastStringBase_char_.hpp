#ifndef CFASTSTRINGBASE_CHAR__HPP
#define CFASTSTRINGBASE_CHAR__HPP

#include "typedefs.h"

struct CClassicBufferMemory;

struct CFastStringBase<char> {
    void** vftable; // accesses: 6
    void * field_0x4; // accesses: 9

    // Member Functions
    void __thiscall AllocAtLeast (CFastStringBase<char> *this,CFastStringBase<wchar_t> *param_1,ulong param_2,int param_3, SOldChars *param_4);
    void __thiscall Clear(CFastStringBase<char> *this,TiXmlNode *param_1);
    void __thiscall PreAlloc (CFastStringBase<char> *this,CClassicBufferMemory *param_1,ulong param_2);
    wchar_t * __cdecl HeapAllocGetChars(ulong param_1);
};

#endif // CFASTSTRINGBASE_CHAR__HPP
