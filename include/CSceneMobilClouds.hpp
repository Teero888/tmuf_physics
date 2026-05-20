#ifndef CSCENEMOBILCLOUDS_HPP
#define CSCENEMOBILCLOUDS_HPP

#include "typedefs.h"

struct CHmsItem;
struct CMwNod;
struct CPlugGpuFxLocator;
struct CPlugTree;

struct CSceneMobilClouds {
    void** vftable; // accesses: 2
    byte _padding_0x4[36];
    CHmsItem * field_0x28; // accesses: 5
    byte _padding_0x2c[40];
    CLoadGeomDynaSprite * field_0x54; // accesses: 5
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    int field_0x68; // accesses: 2
    undefined4 field_0x6c; // accesses: 1
    int field_0x70; // accesses: 3
    undefined4 field_0x74; // accesses: 2
    CPlugTree * field_0x78; // accesses: 3
    undefined4 field_0x7c; // accesses: 1
    float field_0x80; // accesses: 1
    int field_0x84; // accesses: 5
    int field_0x88; // accesses: 6
    float field_0x8c; // accesses: 2
    float field_0x90; // accesses: 2
    CMwNod * field_0x94; // accesses: 6
    int field_0x98; // accesses: 3

    // Member Functions
    void __thiscall BitmapOccAttach(CSceneMobilClouds *this,CSceneMobilClouds *param_1,int param_2);
    void __thiscall BuildInstances(CSceneMobilClouds *this,CSceneMobilClouds *param_1);
    void __thiscall CSceneMobilClouds(CSceneMobilClouds *this,CSceneMobilClouds *param_1);
    void __thiscall Init (CSceneMobilClouds *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CSCENEMOBILCLOUDS_HPP
