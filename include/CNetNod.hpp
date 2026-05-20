#ifndef CNETNOD_HPP
#define CNETNOD_HPP

#include "typedefs.h"

struct CNetNod {
    void** vftable; // accesses: 7
    byte _padding_0x4[16];
    undefined4 * field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 1

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x00508ae9) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CNetNod::DumpToBuffer (CNetNod *this,CNetNod *param_1,CClassicBufferMemory *param_2,SNetConfig *param_3, ulong *param_4);
    void __thiscall CNetNod(CNetNod *this,CNetNod *param_1);
    void __thiscall ~CNetNod(CNetNod *this,CNetNod *param_1);
};

#endif // CNETNOD_HPP
