#ifndef GMQUADTREE_STRUCT_SQUADTREEMESHUV__HPP
#define GMQUADTREE_STRUCT_SQUADTREEMESHUV__HPP

#include "typedefs.h"

struct TiXmlAttributeSet;

struct GmQuadTree<struct_SQuadTreeMeshUv> {
    byte _padding_0x0[4];
    TiXmlAttributeSet * field_0x4; // accesses: 13
    undefined4 field_0x8; // accesses: 8
    float field_0xc; // accesses: 8
    TiXmlAttributeSet * field_0x10; // accesses: 8
    undefined4 field_0x14; // accesses: 10

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall BuildBintreeRecurse (void *this,GmQuadTree<struct_SQuadTreeMeshUv> *param_1,ulong param_2, SQuadTreeMeshUv *param_3,ulong param_4,ulong param_5,ulong param_6,float param_7);
};

#endif // GMQUADTREE_STRUCT_SQUADTREEMESHUV__HPP
