#ifndef GMFRUSTUM_HPP
#define GMFRUSTUM_HPP

#include "typedefs.h"

struct CHmsCamera;

struct GmFrustum {
    float field_0x0; // accesses: 12
    float field_0x4; // accesses: 21
    float field_0x8; // accesses: 19
    float field_0xc; // accesses: 19
    float field_0x10; // accesses: 22
    float field_0x14; // accesses: 19
    float field_0x18; // accesses: 18
    byte _final_padding[0x44]; // Total size: 0x60

    // Member Functions
    float __thiscall GetFarZ(void *this,GmFrustum *param_1);
    float __thiscall GetFovY(void *this,GmFrustum *param_1);
    float __thiscall GetNearZ(void *this,GmFrustum *param_1);
    float __thiscall GetRatioXY(void *this,GmFrustum *param_1);
    int __thiscall IsValid(void *this,CGameScoresVersion *param_1);
    int __thiscall TestInter(void *this,CPlugVolumeProjector *param_1,GmBoxAligned *param_2,GmIso4 *param_3);
    void __thiscall GetAspect(void *this,GmFrustum *param_1,GmRectAligned *param_2);
    void __thiscall GetBBox(void *this,GmFrustum *param_1,GmBoxAligned *param_2);
    void __thiscall GetPlaneEqs6(void *this,GmFrustum *param_1,GmVec4 *param_2,GmIso4 *param_3);
    void __thiscall GetRectZ(void *this,GmFrustum *param_1,float param_2,GmRectAligned *param_3);
    void __thiscall GetVertices4AtZ(void *this,GmFrustum *param_1,GmVec3 *param_2,float param_3);
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetFarZ(void *this,CHmsCamera *param_1,float param_2);
    void __thiscall SetFovX(void *this,GmFrustum *param_1,float param_2,float param_3,float param_4, float param_5);
    void __thiscall SetFovY(void *this,GmFrustum *param_1,float param_2,float param_3,float param_4, float param_5);
    void __thiscall SetOrtho(void *this,GmFrustum *param_1,GmBoxAligned *param_2);
};

#endif // GMFRUSTUM_HPP
