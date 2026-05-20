#ifndef CHMSPOC_HPP
#define CHMSPOC_HPP

#include "typedefs.h"

struct CHmsPoc {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    byte _padding_0x8[8];
    int field_0x10; // accesses: 1
    byte _padding_0x14[4];
    int field_0x18; // accesses: 3
    byte _padding_0x1c[44];
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    int field_0x54; // accesses: 3

    // Member Functions
    ulong __thiscall VirtualParam_Set(CHmsPoc *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    void __thiscall CHmsPoc(CHmsPoc *this,CHmsPoc *param_1);
    void __thiscall ~CHmsPoc(CHmsPoc *this,CHmsPoc *param_1);
};

#endif // CHMSPOC_HPP
