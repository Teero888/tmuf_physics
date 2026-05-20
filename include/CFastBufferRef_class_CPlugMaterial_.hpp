#ifndef CFASTBUFFERREF_CLASS_CPLUGMATERIAL__HPP
#define CFASTBUFFERREF_CLASS_CPLUGMATERIAL__HPP

#include "typedefs.h"

struct CFastBufferRef<class_CPlugMaterial> {
    void** vftable; // accesses: 2
    int field_0x4; // accesses: 2

    // Member Functions
    void __thiscall AllocSetCount (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2);
    void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
};

#endif // CFASTBUFFERREF_CLASS_CPLUGMATERIAL__HPP
