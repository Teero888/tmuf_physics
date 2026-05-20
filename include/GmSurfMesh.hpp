#ifndef GMSURFMESH_HPP
#define GMSURFMESH_HPP

#include "typedefs.h"

struct GmSurfMesh {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 38
    undefined4 field_0x8; // accesses: 40
    undefined4 field_0xc; // accesses: 7
    undefined4 field_0x10; // accesses: 5
    undefined4 field_0x14; // accesses: 6
    undefined4 field_0x18; // accesses: 5
    undefined2 field_0x1c; // accesses: 1
    byte _padding_0x1e[6];
    int field_0x24; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall ClipSegment (GmSurfMesh *this,GmSurfSphere *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4, float *param_5);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall ClipSegment2 (GmSurfMesh *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,int param_4, float *param_5,GmVec3 *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall ClipSegment3 (GmSurfMesh *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,float *param_4, ushort *param_5);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall TriangleClipSegment2NearerThanT (GmSurfMesh *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4, int param_5,float *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall TriangleClipSegmentNearerThanT (GmSurfMesh *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4, float *param_5,SPointInTri *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall BuildOctree(GmSurfMesh *this,GmSurfMesh *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetMeshBoundingBox(GmSurfMesh *this,GmSurfMesh *param_1,GmBoxAligned *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall TransformByNOMat(GmSurfMesh *this,GmSurfMesh *param_1,GmIso4 *param_2);
    void __thiscall Archive(GmSurfMesh *this,CFastCrypt<unsigned_long> *param_1,CClassicArchive *param_2);
    void __thiscall GmSurfMesh(GmSurfMesh *this,GmSurfMesh *param_1);
};

#endif // GMSURFMESH_HPP
