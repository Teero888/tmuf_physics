#ifndef GMSURF_HPP
#define GMSURF_HPP

#include "typedefs.h"

struct GmSurf {
    void** vftable; // accesses: 2
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 4
    undefined4 field_0xc; // accesses: 3
    undefined4 field_0x10; // accesses: 3
    undefined4 field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2

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
