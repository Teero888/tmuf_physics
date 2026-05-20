#ifndef GMFRUSTUM_HPP
#define GMFRUSTUM_HPP

#include "typedefs.h"

struct GmVec3;

struct GmFrustum {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 9
    undefined4 field_0x8; // accesses: 10
    undefined4 field_0xc; // accesses: 9
    undefined4 field_0x10; // accesses: 8
    undefined4 field_0x14; // accesses: 9
    undefined4 field_0x18; // accesses: 3
    float field_0x1c; // accesses: 3
    undefined4 field_0x20; // accesses: 3
    undefined4 field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 3
    float field_0x2c; // accesses: 3
    undefined4 field_0x30; // accesses: 2
    float field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    float field_0x3c; // accesses: 2
    undefined4 field_0x40; // accesses: 2
    undefined4 field_0x44; // accesses: 2
    undefined4 field_0x48; // accesses: 2
    float field_0x4c; // accesses: 2
    undefined4 field_0x50; // accesses: 2
    undefined4 field_0x54; // accesses: 2
    undefined4 field_0x58; // accesses: 2
    float field_0x5c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall GetFovY(void *this,GmFrustum *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall IsValid(void *this,CGameScoresVersion *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetPlaneEqs6(void *this,GmFrustum *param_1,GmVec4 *param_2,GmIso4 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetFovX(void *this,GmFrustum *param_1,float param_2,float param_3,float param_4, float param_5);
    float __thiscall GetFarZ(void *this,GmFrustum *param_1);
    float __thiscall GetNearZ(void *this,GmFrustum *param_1);
    float __thiscall GetRatioXY(void *this,GmFrustum *param_1);
    int __thiscall TestInter(void *this,CPlugVolumeProjector *param_1,GmBoxAligned *param_2,GmIso4 *param_3);
    void __thiscall GetAspect(void *this,GmFrustum *param_1,GmRectAligned *param_2);
    void __thiscall GetBBox(void *this,GmFrustum *param_1,GmBoxAligned *param_2);
    void __thiscall GetRectZ(void *this,GmFrustum *param_1,float param_2,GmRectAligned *param_3);
    void __thiscall GetVertices4AtZ(void *this,GmFrustum *param_1,GmVec3 *param_2,float param_3);
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetFarZ(void *this,CHmsCamera *param_1,float param_2);
    void __thiscall SetFovY(void *this,GmFrustum *param_1,float param_2,float param_3,float param_4, float param_5);
    void __thiscall SetOrtho(void *this,GmFrustum *param_1,GmBoxAligned *param_2);
};

#endif // GMFRUSTUM_HPP
