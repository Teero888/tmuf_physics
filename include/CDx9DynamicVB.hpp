#ifndef CDX9DYNAMICVB_HPP
#define CDX9DYNAMICVB_HPP

#include "typedefs.h"

struct CDx9DynamicVB {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    uint field_0x8; // accesses: 1
    int field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 2
    int * field_0x14; // accesses: 2

    // Member Functions
    void __thiscall Lock(void *this,CDx9DynamicVB *param_1,ulong param_2,ulong param_3,uchar **param_4, ulong *param_5);
};

#endif // CDX9DYNAMICVB_HPP
