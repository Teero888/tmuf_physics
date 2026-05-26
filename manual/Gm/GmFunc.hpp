#ifndef GMFUNC_HPP
#define GMFUNC_HPP

#include "typedefs.h"

struct GmFunc {
    // No fields detected

    // Member Functions
    float __cdecl AsinSafe(float param_1);
    float __cdecl ClampReal(float param_1,float param_2,float param_3);
    float __cdecl Mod(float param_1,float param_2,float param_3);
    float __cdecl RandReal(float param_1,float param_2);
    float __cdecl Sign(float param_1,float param_2);
    int __cdecl IsANumber(float param_1);
    uchar __cdecl RealToNat7(float param_1,float param_2,float param_3);
    uchar __cdecl RealToNat8(float param_1,float param_2,float param_3);
    ulong __cdecl AreNearlyEqual(float param_1,float param_2,float param_3);
    ulong __cdecl Div(float *param_1,float param_2,float param_3);
    ulong __cdecl IsZero(float param_1,float param_2);
    ulong __cdecl SolveLinearSystem2 (float *param_1,float *param_2,float param_3,float param_4,float param_5,float param_6, float param_7,float param_8);
    ushort __cdecl RealToNat16(float param_1,float param_2,float param_3);
    void __cdecl ReadUnitVec3(CClassicBuffer *param_1,GmVec3 *param_2);
    void __cdecl SetRandSeed(ulong param_1);
    void __cdecl WriteUnitVec3(CClassicBuffer *param_1,GmVec3 *param_2);
    void __thiscall Max(void *this,GmVector3<unsigned_long> *param_1,GmVector3<unsigned_long> *param_2);
    void __thiscall Min(void *this,GmVector3<unsigned_long> *param_1,GmVector3<unsigned_long> *param_2);
    void __thiscall Saturate(void *this,SParam *param_1);
};

#endif // GMFUNC_HPP
