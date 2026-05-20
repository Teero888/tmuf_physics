#ifndef CFASTBUFFER_CLASS_GMVEC3__HPP
#define CFASTBUFFER_CLASS_GMVEC3__HPP

#include "typedefs.h"

struct CFastBuffer<class_GmVec3> {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1

    // Member Functions
    void __thiscall SetSizeAtLeast (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2);
};

#endif // CFASTBUFFER_CLASS_GMVEC3__HPP
