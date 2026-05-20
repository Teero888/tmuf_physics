#ifndef GMSURF_HPP
#define GMSURF_HPP

#include "typedefs.h"

struct GmSurf {
    byte _padding_0x0[4];
    undefined2 field_0x4; // accesses: 7
    byte _padding_0x6[2];
    undefined4 field_0x8; // accesses: 9
    undefined2 field_0x9; // accesses: 2
    byte _padding_0xb[1];
    undefined4 field_0xc; // accesses: 4
    undefined4 field_0x10; // accesses: 4
    undefined4 field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 3
    undefined4 field_0x1c; // accesses: 3
    byte _padding_0x20[4];
    float field_0x24; // accesses: 2
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl StaticInit(void);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CreateDefaultData(GmSurf *this,CCrystal *param_1);
    int __cdecl ComputeCollision(LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3);
    int __thiscall ClipSegment(GmSurf *this,GmSurfSphere *param_1,GmVec3 *param_2,GmVec3 *param_3, GmVec3 *param_4,float *param_5);
    int __thiscall ClipSegment2 (GmSurf *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,int param_4, float *param_5,GmVec3 *param_6);
    int __thiscall ClipSegment3 (GmSurf *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,float *param_4, ushort *param_5);
    void __thiscall GetBoundingBox(GmSurf *this,GmSurf *param_1,GmBoxAligned *param_2);
    void __thiscall GmSurf(GmSurf *this,GmSurf *param_1);
};

#endif // GMSURF_HPP
