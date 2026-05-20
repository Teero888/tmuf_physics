#ifndef CFASTBUFFERREF_CLASS_CPLUGSOLID__HPP
#define CFASTBUFFERREF_CLASS_CPLUGSOLID__HPP

#include "typedefs.h"

struct CFastBufferRef<class_CPlugSolid> {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1

    // Member Functions
    void __thiscall AllocSetCount (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2);
};

#endif // CFASTBUFFERREF_CLASS_CPLUGSOLID__HPP
