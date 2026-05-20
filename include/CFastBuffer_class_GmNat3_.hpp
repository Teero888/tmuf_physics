#ifndef CFASTBUFFER_CLASS_GMNAT3__HPP
#define CFASTBUFFER_CLASS_GMNAT3__HPP

#include "typedefs.h"

struct CFastBuffer<class_GmNat3> {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    int field_0x8; // accesses: 1

    // Member Functions
    int __thiscall Find (void *this,CFastArray<class_GxTexCoordSet> *param_1,GxTexCoordSet *param_2);
};

#endif // CFASTBUFFER_CLASS_GMNAT3__HPP
