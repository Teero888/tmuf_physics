#ifndef GMOCTREE_STRUCT_SMESHOCTREECELL__HPP
#define GMOCTREE_STRUCT_SMESHOCTREECELL__HPP

#include "typedefs.h"

struct GmOctree<struct_SMeshOctreeCell> {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 20
    undefined4 field_0x8; // accesses: 10
    undefined4 field_0xc; // accesses: 11
    undefined4 field_0x10; // accesses: 10
    undefined4 field_0x14; // accesses: 11
    undefined4 field_0x18; // accesses: 11
    undefined4 field_0x1c; // accesses: 9

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall BuildOctreeRecurse (void *this,GmOctree<struct_SMeshOctreeCell> *param_1,ulong param_2, SMeshOctreeCell *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Build (void *this,NvStripInfo *param_1, vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> *param_2, vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *param_3);
    void __thiscall Archive (void *this,CFastCrypt<unsigned_long> *param_1,CClassicArchive *param_2);
};

#endif // GMOCTREE_STRUCT_SMESHOCTREECELL__HPP
