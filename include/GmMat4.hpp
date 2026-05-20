#ifndef GMMAT4_HPP
#define GMMAT4_HPP

#include "typedefs.h"

struct GmFrustum;
struct GmVec4;

struct GmMat4 {
    void** vftable; // accesses: 20
    float field_0x4; // accesses: 19
    float field_0x8; // accesses: 19
    float field_0xc; // accesses: 19
    float field_0x10; // accesses: 19
    float field_0x14; // accesses: 19
    float field_0x18; // accesses: 16
    float field_0x1c; // accesses: 13
    float field_0x20; // accesses: 13
    float field_0x24; // accesses: 13
    GmFrustum * field_0x28; // accesses: 13
    float field_0x2c; // accesses: 13
    float field_0x30; // accesses: 13
    float field_0x34; // accesses: 13
    float field_0x38; // accesses: 13
    float field_0x3c; // accesses: 13

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetFrustumProjection(void *this,GmMat4 *param_1,GmFrustum *param_2,ulong param_3);
    void __thiscall ArchiveGmMat4(void *this,GmMat4 *param_1,CClassicArchive *param_2);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetIdentity(void *this,GmMat43 *param_1);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
    void __thiscall SetShadowPlaneProjection(void *this,GmMat4 *param_1,GmVec4 *param_2,GmVec4 *param_3);
    void __thiscall SetShadowPlaneProjectionDirectional (void *this,GmMat4 *param_1,GmVec3 *param_2,GmVec4 *param_3);
    void __thiscall SetShadowPlaneProjectionPoint(void *this,GmMat4 *param_1,GmVec3 *param_2,GmVec4 *param_3);
    void __thiscall SetTranspose(void *this,GmMat2 *param_1,GmMat2 *param_2);
    void __thiscall SetTransposeXY(void *this,GmMat4 *param_1,GmIso3 *param_2);
    void __thiscall SetTransposeXY_TransZ(void *this,GmMat4 *param_1,GmIso3 *param_2);
    void __thiscall SetXY(void *this,GmMat4 *param_1,GmIso3 *param_2);
    void __thiscall Transpose(void *this,GmMat4 *param_1);
};

#endif // GMMAT4_HPP
