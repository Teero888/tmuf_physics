#ifndef CMWCLASSINFO_HPP
#define CMWCLASSINFO_HPP

#include "typedefs.h"

struct CMwClassInfo {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    CMwClassInfo * field_0x8; // accesses: 3
    byte _padding_0xc[12];
    CMwClassInfo * field_0x18; // accesses: 1
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 1
    uint field_0x24; // accesses: 1

    // Member Functions
    CMwClassInfo * __cdecl FindFromClassName(CFastString *param_1);
    int __thiscall IsMwParamIdEqualName (CMwClassInfo *this,CMwClassInfo *param_1,ulong param_2,char *param_3,int param_4);
    ulong __thiscall MwGetNearestFather (CMwClassInfo *this,CMwClassInfo *param_1,ulong param_2,ulong *param_3);
    void __thiscall BuildTree(CMwClassInfo *this,CMwClassInfo *param_1);
};

#endif // CMWCLASSINFO_HPP
