#ifndef CSCENEMOBILSNOW_HPP
#define CSCENEMOBILSNOW_HPP

#include "typedefs.h"

struct CPlugAudio;
struct CPlugVisualSprite;
struct GmVec3;

struct CSceneMobilSnow {
    byte _padding_0x0[4];
    CPlugVisualSprite * field_0x4; // accesses: 1
    GmVec3 * field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[4];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[4];
    uint field_0x1c; // accesses: 6
    byte _padding_0x20[8];
    int field_0x28; // accesses: 2
    byte _padding_0x2c[28];
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    byte _padding_0x54[8];
    undefined4 field_0x5c; // accesses: 2
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1

    // Member Functions
    void __thiscall CSceneMobilSnow(CSceneMobilSnow *this,CSceneMobilSnow *param_1);
    void __thiscall Init (CSceneMobilSnow *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CSCENEMOBILSNOW_HPP
