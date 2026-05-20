#ifndef GMVEC2_HPP
#define GMVEC2_HPP

#include "typedefs.h"

struct GmVec2 {
    float field_0x0; // accesses: 21
    float field_0x4; // accesses: 20

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __cdecl IsInTriangle (GmVec2 *param_1,GmVec2 *param_2,GmVec2 *param_3,GmVec2 *param_4,float *param_5, float *param_6,int *param_7);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall IsNearlyEqual(void *this,GmVec2 *param_1,GmVec2 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Normalize(void *this,GmQuat *param_1);
    float __thiscall GetLength(void *this,CPlugFileSnd *param_1);
    void __thiscall ArchiveGmVec2(void *this,GmVec2 *param_1,CClassicArchive *param_2);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall SetBlend(void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4);
    void __thiscall SetBlendTri(void *this,GmVec2 *param_1,GmVec2 *param_2,GmVec2 *param_3,GmVec2 *param_4, float param_5,float param_6);
    void __thiscall SetMultInverse(void *this,GmVec2 *param_1,GmVec2 *param_2,GmIso3 *param_3);
};

#endif // GMVEC2_HPP
