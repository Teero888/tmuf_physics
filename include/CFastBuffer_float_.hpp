#ifndef CFASTBUFFER_FLOAT__HPP
#define CFASTBUFFER_FLOAT__HPP

#include "typedefs.h"

struct CFastBuffer<float> {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1

    // Member Functions
    void __thiscall Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
    void __thiscall AllocSetCount(void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2);
    void __thiscall ArchiveCountAndElems (void *this,CFastArray<struct_SOldLetter> *param_1,CClassicArchive *param_2);
    void __thiscall ReplaceByLastAt (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3);
    void __thiscall SetSizeAtLeast (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2);
};

#endif // CFASTBUFFER_FLOAT__HPP
