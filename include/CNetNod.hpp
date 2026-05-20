#ifndef CNETNOD_HPP
#define CNETNOD_HPP

#include "typedefs.h"

struct CNetNod {
    byte _padding_0x0[12];
    int field_0xc; // accesses: 3
    byte _padding_0x10[4];
    undefined4 * field_0x14; // accesses: 4
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[32];
    int field_0x3c; // accesses: 2
    int * field_0x40; // accesses: 1

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x00508ae9) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CNetNod::DumpToBuffer (CNetNod *this,CNetNod *param_1,CClassicBufferMemory *param_2,SNetConfig *param_3, ulong *param_4);
    void __thiscall CNetNod(CNetNod *this,CNetNod *param_1);
    void __thiscall ~CNetNod(CNetNod *this,CNetNod *param_1);
};

#endif // CNETNOD_HPP
