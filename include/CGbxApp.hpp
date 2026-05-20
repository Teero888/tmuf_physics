#ifndef CGBXAPP_HPP
#define CGBXAPP_HPP

#include "typedefs.h"

struct CSystemEngine;

struct CGbxApp {
    void** vftable; // accesses: 1
    byte _padding_0x4[40];
    CSystemEngine * field_0x2c; // accesses: 1
    byte _padding_0x30[72];
    int field_0x78; // accesses: 2
    byte _padding_0x7c[56];
    int field_0xb4; // accesses: 1
    byte _padding_0xb8[52];
    undefined4 field_0xec; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Init(CGbxApp *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CGBXAPP_HPP
