#ifndef CCLASSICBUFFERMEMORY_HPP
#define CCLASSICBUFFERMEMORY_HPP

#include "typedefs.h"

struct CClassicBufferMemory {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    int field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 8
    undefined4 field_0x10; // accesses: 8
    undefined4 field_0x14; // accesses: 12
    undefined4 field_0x18; // accesses: 7
    undefined4 field_0x1c; // accesses: 9

    // Member Functions
    int __thiscall IsEqualBuffer (CClassicBufferMemory *this,CClassicBufferMemory *param_1,CClassicBufferMemory *param_2);
    ulong __thiscall WriteVoid (CClassicBufferMemory *this,CClassicBufferMemory *param_1,ulong param_2);
    void __thiscall AdvanceOffset (CClassicBufferMemory *this,CClassicBufferMemory *param_1,ulong param_2);
    void __thiscall Attach (CClassicBufferMemory *this,CClassicBufferMemory *param_1,void *param_2,ulong param_3);
    void __thiscall CClassicBufferMemory(CClassicBufferMemory *this,CClassicBufferMemory *param_1);
    void __thiscall Empty(CClassicBufferMemory *this,CClassicBufferMemory *param_1);
    void __thiscall PreAlloc (CClassicBufferMemory *this,CClassicBufferMemory *param_1,ulong param_2);
    void __thiscall Reset(CClassicBufferMemory *this,GmFrustumIso4 *param_1);
    void __thiscall ~CClassicBufferMemory (CClassicBufferMemory *this,CClassicBufferMemory *param_1);
};

#endif // CCLASSICBUFFERMEMORY_HPP
