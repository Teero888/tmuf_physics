#ifndef CHMSCAMERA_HPP
#define CHMSCAMERA_HPP

#include "typedefs.h"

struct CMwNod;
struct CSceneSector;
struct GmIso3;
struct GmIso4;

struct CHmsCamera {
    void** vftable; // accesses: 4
    byte _padding_0x4[16];
    CSceneSector * field_0x14; // accesses: 1
    byte _padding_0x18[256];
    int field_0x118; // accesses: 7
    CMwCmdScriptVarBool * field_0x11c; // accesses: 5
    float field_0x120; // accesses: 5
    GmIso3 * field_0x124; // accesses: 12
    CMwCmdScriptVarBool * field_0x128; // accesses: 4
    float field_0x12c; // accesses: 5
    GmIso4 * field_0x130; // accesses: 15
    int field_0x134; // accesses: 3
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    undefined4 field_0x15c; // accesses: 1
    undefined4 field_0x160; // accesses: 1
    undefined4 field_0x164; // accesses: 3
    undefined4 field_0x168; // accesses: 2
    float field_0x16c; // accesses: 2
    undefined4 field_0x170; // accesses: 5
    undefined4 field_0x174; // accesses: 3
    CHmsCamera * field_0x178; // accesses: 8
    undefined4 field_0x17c; // accesses: 1
    undefined4 field_0x180; // accesses: 2
    int field_0x184; // accesses: 3
    int field_0x188; // accesses: 3
    undefined4 field_0x18c; // accesses: 2
    undefined4 field_0x190; // accesses: 2
    undefined4 field_0x194; // accesses: 2
    undefined4 field_0x198; // accesses: 2
    float field_0x19c; // accesses: 3
    int * field_0x1a0; // accesses: 3
    byte _padding_0x1a4[12];
    undefined4 field_0x1b0; // accesses: 1
    undefined4 field_0x1b4; // accesses: 1
    undefined4 field_0x1b8; // accesses: 1
    undefined4 field_0x1bc; // accesses: 1
    undefined4 field_0x1c0; // accesses: 1
    undefined4 field_0x1c4; // accesses: 3
    undefined4 field_0x1c8; // accesses: 3
    undefined4 field_0x1cc; // accesses: 3
    undefined4 field_0x1d0; // accesses: 3
    undefined4 field_0x1d4; // accesses: 1
    undefined4 field_0x1d8; // accesses: 4
    undefined4 field_0x1dc; // accesses: 4
    undefined4 field_0x1e0; // accesses: 4
    undefined4 field_0x1e4; // accesses: 1
    undefined4 field_0x1e8; // accesses: 1
    undefined4 field_0x1ec; // accesses: 1
    undefined4 field_0x1f0; // accesses: 1
    int field_0x1f4; // accesses: 3
    undefined4 field_0x1f8; // accesses: 4
    CHmsCamera * field_0x1fc; // accesses: 3
    undefined4 field_0x200; // accesses: 2
    undefined4 field_0x204; // accesses: 2
    undefined4 field_0x208; // accesses: 1
    CMwNod * field_0x20c; // accesses: 8
    undefined4 field_0x210; // accesses: 2

    // Member Functions
    float __thiscall GetFov(CHmsCamera *this,CHmsCamera *param_1);
    void __thiscall CHmsCamera(CHmsCamera *this,CHmsCamera *param_1);
    void __thiscall ForceLocation(CHmsCamera *this,CHmsCamera *param_1,GmIso4 *param_2);
    void __thiscall GetCamVal(CHmsCamera *this,GmCamFreeVal *param_1,GmCamVal *param_2);
    void __thiscall GetRenderFrustum(CHmsCamera *this,CHmsCamera *param_1,GmFrustum *param_2);
    void __thiscall LensUpdateFocalSize(CHmsCamera *this,CHmsCamera *param_1);
    void __thiscall ScissorRectSet(CHmsCamera *this,CHmsCamera *param_1,GmRectAligned *param_2);
    void __thiscall ScissorRectSetEnable(CHmsCamera *this,CHmsCamera *param_1,int param_2);
    void __thiscall SetCamVal (CHmsCamera *this,CSceneCamera *param_1,GmCamVal *param_2,GmVec3 *param_3,int param_4);
    void __thiscall SetDrawRect(CHmsCamera *this,CHmsCamera *param_1,GmRectAligned *param_2);
    void __thiscall SetFov(CHmsCamera *this,CHmsCamera *param_1,float param_2);
    void __thiscall SetFrustum(CHmsCamera *this,CHmsCamera *param_1,GmFrustum *param_2);
    void __thiscall SetLocation(CHmsCamera *this,CPlugTree *param_1,GmIso4 *param_2);
    void __thiscall SetNearZ(CHmsCamera *this,GmFrustum *param_1,float param_2);
    void __thiscall SetZone(CHmsCamera *this,CSceneSector *param_1,CHmsZone *param_2);
    void __thiscall ZClipCompute (CHmsCamera *this,CHmsCamera *param_1,float param_2,GmFrustum *param_3, SHmsRenderRect *param_4);
    void __thiscall ~CHmsCamera(CHmsCamera *this,CHmsCamera *param_1);
};

#endif // CHMSCAMERA_HPP
