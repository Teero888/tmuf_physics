#ifndef GMVEC4_HPP
#define GMVEC4_HPP

#include "typedefs.h"

struct GmIso4;

struct GmVec4 {
    float field_0x0; // accesses: 28
    float field_0x4; // accesses: 27
    float field_0x8; // accesses: 26
    float field_0xc; // accesses: 25

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall PlaneEqInterLine(void *this,GmVec4 *param_1,GmVec3 *param_2,GmVec3 *param_3,float *param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall PlaneEqInterPlane(void *this,GmVec4 *param_1,GmVec4 *param_2,GmLine3 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall PlaneEqIsNearlyEqual(void *this,GmVec4 *param_1,GmVec4 *param_2,float param_3,float param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall PlaneEqSetFrom3Pos (void *this,GmVec4 *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl PolygonClip(CFastBuffer<class_GmVec4> *param_1, CFastBuffer<struct_GmClipFlag_HalfCube> *param_2);
    void __cdecl GetClipFlags(GmVec4 *param_1,GmClipFlag_HalfCube *param_2,ulong param_3);
    void __thiscall Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
    void __thiscall GetClipFlag(void *this,GmReal4_64 *param_1,GmClipFlag_HalfCube *param_2);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall Neg(void *this,GmCollision *param_1);
    void __thiscall PlaneEqMult(void *this,GmVec4 *param_1,GmIso4 *param_2);
    void __thiscall PlaneEqSetMult(void *this,GmVec4 *param_1,GmVec4 *param_2,GmIso4 *param_3);
    void __thiscall PlaneEqSetNormPos(void *this,GmVec4 *param_1,GmVec3 *param_2,GmVec3 *param_3);
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetBlend(void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4);
    void __thiscall SetLeftMult(void *this,GmVec4 *param_1,GmIso4 *param_2,GmVec4 *param_3);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
    void __thiscall SetSub(void *this,GmVec4 *param_1,GmVec4 *param_2,GmVec4 *param_3);
    void __thiscall Sub(void *this,GmVec4 *param_1,GmVec4 param_2);
};

#endif // GMVEC4_HPP
