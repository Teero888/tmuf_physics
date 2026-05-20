#ifndef CFASTBUFFER_STRUCT_SHMSVPACKEROBJECT__HPP
#define CFASTBUFFER_STRUCT_SHMSVPACKEROBJECT__HPP

#include "typedefs.h"

struct ulong;

struct CFastBuffer<struct_SHmsVPackerObject> {
    void** vftable; // accesses: 8
    int field_0x4; // accesses: 3

    // Member Functions
    void __thiscall Add (void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
    void __thiscall ReplaceByLastAt (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3);
};

#endif // CFASTBUFFER_STRUCT_SHMSVPACKEROBJECT__HPP
