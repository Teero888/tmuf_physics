#ifndef CSCENEMOBILSNOW_HPP
#define CSCENEMOBILSNOW_HPP

#include "typedefs.h"

struct CSceneMobilSnow {
    void** vftable; // accesses: 1
    byte _padding_0x4[36];
    int field_0x28; // accesses: 1
    byte _padding_0x2c[28];
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    byte _padding_0x54[8];
    CLoadGeomDynaSprite * field_0x5c; // accesses: 2
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1

    // Member Functions
    void __thiscall CSceneMobilSnow(CSceneMobilSnow *this,CSceneMobilSnow *param_1);
    void __thiscall Init (CSceneMobilSnow *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CSCENEMOBILSNOW_HPP
