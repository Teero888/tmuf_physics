#ifndef CSCENEMOBILCLOUDS_HPP
#define CSCENEMOBILCLOUDS_HPP

#include "typedefs.h"

struct CHmsItem;
struct CMwNod;
struct CPlugGpuFxLocator;
struct CPlugShader;
struct CPlugTree;
struct CPlugVisualSprite;

struct CSceneMobilClouds {
    byte _padding_0x0[28];
    uint field_0x1c; // accesses: 3
    byte _padding_0x20[8];
    CHmsItem * field_0x28; // accesses: 5
    byte _padding_0x2c[12];
    float field_0x38; // accesses: 1
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[8];
    CLoadGeomDynaSprite * field_0x54; // accesses: 5
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    int field_0x68; // accesses: 2
    undefined4 field_0x6c; // accesses: 1
    int field_0x70; // accesses: 3
    undefined4 field_0x74; // accesses: 2
    undefined4 field_0x78; // accesses: 3
    undefined4 field_0x7c; // accesses: 1
    float field_0x80; // accesses: 1
    int field_0x84; // accesses: 6
    int field_0x88; // accesses: 6
    float field_0x8c; // accesses: 2
    float field_0x90; // accesses: 3
    CPlugShader * field_0x94; // accesses: 7
    int field_0x98; // accesses: 7
    uint field_0x9c; // accesses: 7
    byte _padding_0xa0[16];
    uint field_0xb0; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall BuildInstances(CSceneMobilClouds *this,CSceneMobilClouds *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CSceneMobilClouds(CSceneMobilClouds *this,CSceneMobilClouds *param_1);
    void __thiscall BitmapOccAttach(CSceneMobilClouds *this,CSceneMobilClouds *param_1,int param_2);
    void __thiscall Init (CSceneMobilClouds *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CSCENEMOBILCLOUDS_HPP
