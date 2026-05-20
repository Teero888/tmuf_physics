#ifndef CFASTBUFFER_INT__HPP
#define CFASTBUFFER_INT__HPP

#include "typedefs.h"

struct CFastBuffer<int> {
    void** vftable; // accesses: 5
    int field_0x4; // accesses: 5
    uint field_0x8; // accesses: 1

    // Member Functions
    ulong __thiscall FindAfter(void *this,CFastBuffer<int> *param_1,int *param_2,ulong param_3);
    void __thiscall FillWith (void *this,CFixedArray<unsigned_char,8,unsigned_long> *param_1,uchar *param_2);
    void __thiscall SetSizeAtLeast (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2);
};

#endif // CFASTBUFFER_INT__HPP
