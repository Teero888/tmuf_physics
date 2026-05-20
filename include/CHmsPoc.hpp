#ifndef CHMSPOC_HPP
#define CHMSPOC_HPP

#include "typedefs.h"

struct CHmsPoc {
    void** vftable; // accesses: 4
    byte _padding_0x4[68];
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 3

    // Member Functions
    ulong __thiscall VirtualParam_Set(CHmsPoc *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    void __thiscall CHmsPoc(CHmsPoc *this,CHmsPoc *param_1);
    void __thiscall ~CHmsPoc(CHmsPoc *this,CHmsPoc *param_1);
};

#endif // CHMSPOC_HPP
