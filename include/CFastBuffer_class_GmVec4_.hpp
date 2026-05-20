#ifndef CFASTBUFFER_CLASS_GMVEC4__HPP
#define CFASTBUFFER_CLASS_GMVEC4__HPP

#include "typedefs.h"

struct CFastBuffer<class_GmVec4> {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1

    // Member Functions
    void __thiscall AllocSetCount (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2);
    void __thiscall FillWith (void *this,CFixedArray<unsigned_char,8,unsigned_long> *param_1,uchar *param_2);
};

#endif // CFASTBUFFER_CLASS_GMVEC4__HPP
