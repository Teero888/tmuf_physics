#ifndef GMVEC3_HPP
#define GMVEC3_HPP

#include "typedefs.h"

struct GmVec3 {
    float field_0x0; // accesses: 14
    float field_0x4; // accesses: 14
    float field_0x8; // accesses: 14

    // Member Functions
    float __cdecl GetAngle(GmVec3 *param_1,GmVec3 *param_2);
    float __cdecl GetInnerAngle(GmVec3 *param_1,GmVec3 *param_2);
    int __cdecl ComputeTriangleTangentUV(STri_PosTexTgt *param_1);
    int __cdecl DoesRayIntersectTriangle (GmVec3 *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,GmVec3 *param_5, float *param_6,float *param_7,float *param_8);
    int __cdecl DoesRayIntersectTriangleCull (GmVec3 *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,GmVec3 *param_5, float *param_6,float *param_7,float *param_8);
    ulong __thiscall IsNearlyEqual(void *this,GmVec2 *param_1,GmVec2 *param_2);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall MultInverse(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall MultTranspose(void *this,GmMat3 *param_1,GmMat3 *param_2);
    void __thiscall SetFromBGRA(void *this,GmVec3 *param_1,uchar *param_2,ulong param_3);
    void __thiscall SetInverseTranslation(void *this,GmVec3 *param_1,GmIso4 *param_2);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
    void __thiscall SetMultTranspose(void *this,GmVec3 *param_1,GmVec3 *param_2,GmMat3 *param_3);
};

#endif // GMVEC3_HPP
