#ifndef CMOTIONMANAGERWEATHERS_HPP
#define CMOTIONMANAGERWEATHERS_HPP

#include "typedefs.h"

struct CHmsViewport;
struct CHmsZoneVPacker;
struct CMotionTimerLoop;
struct CMotionWeather;
struct CMwNod;
struct CPlugFileGen;
struct CPlugFileImg;
struct CPlugMaterial;
struct CPlugShader;
struct CSceneFxNod;
struct CSceneLight;
struct CSceneSector;
struct CSystemFid;
struct GmVec4;
struct GxFog;
struct GxFogBlender;
struct GxLight;

struct CMotionManagerWeathers {
    byte _padding_0x0[2];
    ushort field_0x2; // accesses: 1
    byte _padding_0x4[12];
    undefined4 field_0x10; // accesses: 2
    int field_0x14; // accesses: 3
    byte _padding_0x18[4];
    CMotionTimerLoop * field_0x1c; // accesses: 2
    CMwCmdScriptVarBool * field_0x20; // accesses: 1
    float field_0x24; // accesses: 5
    float field_0x28; // accesses: 6
    float field_0x2c; // accesses: 7
    float field_0x30; // accesses: 2
    int field_0x34; // accesses: 3
    int field_0x38; // accesses: 5
    float field_0x3c; // accesses: 3
    float field_0x40; // accesses: 3
    float field_0x44; // accesses: 2
    undefined4 field_0x48; // accesses: 4
    float field_0x4c; // accesses: 2
    float field_0x50; // accesses: 2
    float field_0x54; // accesses: 1
    float field_0x58; // accesses: 1
    float field_0x5c; // accesses: 1
    int field_0x60; // accesses: 3
    byte _padding_0x64[4];
    GxFogBlender * field_0x68; // accesses: 2
    byte _padding_0x6c[4];
    CMwCmdScriptVarBool * field_0x70; // accesses: 6
    byte _padding_0x74[12];
    float field_0x80; // accesses: 1
    float field_0x84; // accesses: 1
    float field_0x88; // accesses: 1
    int field_0x8c; // accesses: 1
    int field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 2
    undefined4 field_0x98; // accesses: 2
    undefined4 field_0x9c; // accesses: 4
    int field_0xa0; // accesses: 2
    byte _padding_0xa4[4];
    int field_0xa8; // accesses: 2
    uint field_0xac; // accesses: 7
    float field_0xb0; // accesses: 7
    int field_0xb4; // accesses: 13
    CPlugFileGen * field_0xb8; // accesses: 15
    int field_0xbc; // accesses: 6
    int field_0xc0; // accesses: 4
    int field_0xc4; // accesses: 32
    CSceneLight * field_0xc8; // accesses: 7
    byte _padding_0xcc[4];
    undefined4 field_0xd0; // accesses: 1
    float field_0xd4; // accesses: 1
    float field_0xd8; // accesses: 1
    float field_0xdc; // accesses: 1
    float field_0xe0; // accesses: 1
    CLoadGeomDynaSprite * field_0xe4; // accesses: 8
    byte _padding_0xe8[4];
    GmVec4 * field_0xec; // accesses: 3
    CPlugShader * field_0xf0; // accesses: 12
    int field_0xf4; // accesses: 2
    uint field_0xf8; // accesses: 3
    CPlugMaterial * field_0xfc; // accesses: 14
    CPlugBitmapAddress * field_0x100; // accesses: 4
    CHmsZoneVPacker * field_0x104; // accesses: 6
    int field_0x108; // accesses: 3
    int field_0x10c; // accesses: 2
    int field_0x110; // accesses: 1
    int field_0x114; // accesses: 2
    undefined4 field_0x118; // accesses: 2
    undefined4 field_0x11c; // accesses: 2
    undefined4 field_0x120; // accesses: 2
    undefined4 field_0x124; // accesses: 1
    byte _padding_0x128[32];
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 2
    undefined4 field_0x150; // accesses: 2
    undefined4 field_0x154; // accesses: 1
    CSceneFxNod * field_0x158; // accesses: 1
    byte _padding_0x15c[20];
    int field_0x170; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall ChangeWeatherAt (CMotionManagerWeathers *this,CMotionManagerWeathers *param_1,ulong param_2);
    /* WARNING: Removing unreachable block (ram,0x0057400b) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CMotionManagerWeathers::UpdateAsync(CMotionManagerWeathers *this,CInputPortDx8 *param_1);
};

#endif // CMOTIONMANAGERWEATHERS_HPP
