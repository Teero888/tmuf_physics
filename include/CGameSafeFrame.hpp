#ifndef CGAMESAFEFRAME_HPP
#define CGAMESAFEFRAME_HPP

#include "typedefs.h"

struct CScene2d;
struct CSceneCamera;

struct CGameSafeFrame {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    byte _padding_0x14[4];
    int field_0x18; // accesses: 2
    float field_0x1c; // accesses: 4
    float field_0x20; // accesses: 2
    float field_0x24; // accesses: 2
    int field_0x28; // accesses: 2
    float field_0x2c; // accesses: 1
    float field_0x30; // accesses: 1
    float field_0x34; // accesses: 1
    float field_0x38; // accesses: 1
    int field_0x3c; // accesses: 1
    CScene2d * field_0x40; // accesses: 1
    int field_0x44; // accesses: 2
    CScene2d * field_0x48; // accesses: 2
    byte _padding_0x4c[204];
    int field_0x118; // accesses: 1
    byte _padding_0x11c[8];
    float field_0x124; // accesses: 2
    byte _padding_0x128[8];
    float field_0x130; // accesses: 1
    byte _padding_0x134[368];
    int field_0x2a4; // accesses: 2
    int field_0x2a8; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ GmVec2 __thiscall GetWindowSize(CGameSafeFrame *this,CGameSafeFrame *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetAspectViewport (CGameSafeFrame *this,CGameSafeFrame *param_1,GmRectAligned *param_2);
    void __thiscall GetLensVal(CGameSafeFrame *this,CGameSafeFrame *param_1,GmLensVal *param_2);
    void __thiscall SetVisible(CGameSafeFrame *this,CScene2d *param_1,int param_2);
    void __thiscall UpdateCameraFrustum(CGameSafeFrame *this,CGameSafeFrame *param_1);
};

#endif // CGAMESAFEFRAME_HPP
