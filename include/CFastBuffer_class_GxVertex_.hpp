#ifndef CFASTBUFFER_CLASS_GXVERTEX__HPP
#define CFASTBUFFER_CLASS_GXVERTEX__HPP

#include "typedefs.h"

struct ulong;

struct CFastBuffer<class_GxVertex> {
    void** vftable; // accesses: 10
    ulong field_0x4; // accesses: 8
    uint field_0x8; // accesses: 1

    // Member Functions
    void __thiscall Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
    void __thiscall ReplaceByLastAt (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3);
    void __thiscall SetBuffer (void *this,CFastBuffer<class_GxVertex> *param_1,ulong param_2,GxVertex *param_3);
    void __thiscall SetSizeAtLeast (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2);
};

#endif // CFASTBUFFER_CLASS_GXVERTEX__HPP
