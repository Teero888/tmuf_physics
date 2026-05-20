#ifndef CFASTBUFFER_STRUCT_SMESHOCTREECELL__HPP
#define CFASTBUFFER_STRUCT_SMESHOCTREECELL__HPP

#include "typedefs.h"

struct CFastBuffer<struct_SMeshOctreeCell> {
    void** vftable; // accesses: 6
    void * field_0x4; // accesses: 4
    undefined4 field_0x8; // accesses: 2

    // Member Functions
    void __thiscall ArchiveCount (void *this,CFastArray<class_CPlugFileSnd*> *param_1,CClassicArchive *param_2);
    void __thiscall ArchiveFastBuffer (void *this,CFastBuffer<class_CGameCtnChallengeGroup*> *param_1,CClassicArchive *param_2);
};

#endif // CFASTBUFFER_STRUCT_SMESHOCTREECELL__HPP
