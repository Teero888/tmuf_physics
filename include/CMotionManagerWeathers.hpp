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
struct CSceneLight;
struct CSceneSector;
struct GmVec4;
struct GxFog;
struct GxLight;

struct CMotionManagerWeathers {
    void** vftable; // accesses: 3
    byte _padding_0x4[16];
    int field_0x14; // accesses: 2
    byte _padding_0x18[4];
    CMotionTimerLoop * field_0x1c; // accesses: 2
    CMwCmdScriptVarBool * field_0x20; // accesses: 1
    float field_0x24; // accesses: 5
    float field_0x28; // accesses: 6
    float field_0x2c; // accesses: 7
    byte _padding_0x30[48];
    int field_0x60; // accesses: 2
    byte _padding_0x64[12];
    CMotionManagerWeathers * field_0x70; // accesses: 6
    byte _padding_0x74[60];
    CMotionWeather * field_0xb0; // accesses: 7
    CFuncWeather * field_0xb4; // accesses: 13
    CHmsZoneVPacker * field_0xb8; // accesses: 15
    int field_0xbc; // accesses: 4
    GxLight * field_0xc0; // accesses: 2
    GxLight * field_0xc4; // accesses: 32
    int * field_0xc8; // accesses: 7
    byte _padding_0xcc[32];
    float * field_0xec; // accesses: 3
    CSceneSector * field_0xf0; // accesses: 12
    CHmsViewport * field_0xf4; // accesses: 2
    uint field_0xf8; // accesses: 3
    CMwNod * field_0xfc; // accesses: 14
    CPlugBitmapAddress * field_0x100; // accesses: 4
    undefined4 field_0x104; // accesses: 4
    undefined4 field_0x108; // accesses: 3
    int field_0x10c; // accesses: 2
    int field_0x110; // accesses: 1
    int field_0x114; // accesses: 2
    undefined4 field_0x118; // accesses: 2
    undefined4 field_0x11c; // accesses: 2
    undefined4 field_0x120; // accesses: 2
    undefined4 field_0x124; // accesses: 1
    byte _final_padding[0x8]; // Total size: 0x130

    // Member Functions
    int __thiscall ChangeWeatherAt (CMotionManagerWeathers *this,CMotionManagerWeathers *param_1,ulong param_2);
    void __thiscall UpdateAsync(CMotionManagerWeathers *this,CInputPortDx8 *param_1);
};

#endif // CMOTIONMANAGERWEATHERS_HPP
