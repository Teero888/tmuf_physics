#ifndef GMVEC3_HPP
#define GMVEC3_HPP

#include "typedefs.h"

struct GmVec3 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 31
    undefined4 field_0x8; // accesses: 31
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 3
    float field_0x14; // accesses: 3
    float field_0x18; // accesses: 3
    float field_0x1c; // accesses: 3
    float field_0x20; // accesses: 3
    float field_0x24; // accesses: 4
    float field_0x28; // accesses: 4
    float field_0x2c; // accesses: 4

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __cdecl GetAngle(GmVec3 *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __cdecl GetInnerAngle(GmVec3 *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __cdecl DoesRayIntersectTriangle (GmVec3 *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,GmVec3 *param_5, float *param_6,float *param_7,float *param_8);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __cdecl DoesRayIntersectTriangleCull (GmVec3 *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,GmVec3 *param_5, float *param_6,float *param_7,float *param_8);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall IsNearlyEqual(void *this,GmVec2 *param_1,GmVec2 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetFromBGRA(void *this,GmVec3 *param_1,uchar *param_2,ulong param_3);
    int __cdecl ComputeTriangleTangentUV(STri_PosTexTgt *param_1);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall MultInverse(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall MultTranspose(void *this,GmMat3 *param_1,GmMat3 *param_2);
    void __thiscall SetInverseTranslation(void *this,GmVec3 *param_1,GmIso4 *param_2);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
    void __thiscall SetMultTranspose(void *this,GmVec3 *param_1,GmVec3 *param_2,GmMat3 *param_3);
};

#endif // GMVEC3_HPP
