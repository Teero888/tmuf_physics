#ifndef CGAMEADVERTISING_HPP
#define CGAMEADVERTISING_HPP

#include "typedefs.h"

struct CFastString;
struct CMwNod;
struct CPlugShaderGeneric;
struct CPlugTree;
struct CPlugVisualIndexedLines;
struct CSceneMobil;
struct CSceneObject;
struct GmIso3;

struct CGameAdvertising {
    byte _padding_0x0[4];
    CFastString * field_0x4; // accesses: 2
    float field_0x8; // accesses: 1
    uint field_0xc; // accesses: 2
    byte _padding_0x10[4];
    int field_0x14; // accesses: 2
    int field_0x18; // accesses: 3
    uint field_0x1c; // accesses: 6
    byte _padding_0x20[8];
    int field_0x28; // accesses: 3
    byte _padding_0x2c[4];
    ulong field_0x30; // accesses: 1
    CPlugVisualIndexedLines * field_0x34; // accesses: 1
    CPlugVisualIndexedLines * field_0x38; // accesses: 1
    float field_0x3c; // accesses: 2
    byte _padding_0x40[8];
    float field_0x48; // accesses: 1
    float field_0x4c; // accesses: 1
    float field_0x50; // accesses: 1
    byte _padding_0x54[4];
    CGameAdvertisingRadial * field_0x58; // accesses: 1
    byte _padding_0x5c[28];
    CPlugTree * field_0x78; // accesses: 1
    float field_0x7c; // accesses: 1
    float field_0x80; // accesses: 1
    int field_0x84; // accesses: 1
    byte _padding_0x88[8];
    float field_0x90; // accesses: 2
    CPlugShaderGeneric * field_0x94; // accesses: 1
    int field_0x98; // accesses: 1
    uint field_0x9c; // accesses: 6
    byte _padding_0xa0[40];
    int field_0xc8; // accesses: 3
    undefined4 field_0xcc; // accesses: 17
    GmIso3 * field_0xd0; // accesses: 6

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ImpressionHelpers_Update(CGameAdvertising *this,CGameAdvertising *param_1);
    int __thiscall IsInit(CGameAdvertising *this,SVisualHandler *param_1);
    void __thiscall SetAdvertisingZone (CGameAdvertising *this,CGameAdvertising *param_1,CFastString *param_2, CFastString *param_3,CFastString *param_4,CFastString *param_5,CFastString *param_6, CFastString *param_7,CFastString *param_8);
};

#endif // CGAMEADVERTISING_HPP
