#ifndef CGBXAPP_HPP
#define CGBXAPP_HPP

#include "typedefs.h"

struct CSystemConfig;
struct CSystemEngine;
struct CSystemFids;
struct CVisionViewportDx9;

struct CGbxApp {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 13
    byte _padding_0x18[4];
    int field_0x1c; // accesses: 1
    int field_0x20; // accesses: 1
    int field_0x24; // accesses: 2
    int field_0x28; // accesses: 1
    CSystemFids * field_0x2c; // accesses: 2
    CSystemConfig * field_0x30; // accesses: 2
    byte _padding_0x34[68];
    int field_0x78; // accesses: 2
    byte _padding_0x7c[56];
    int field_0xb4; // accesses: 1
    byte _padding_0xb8[52];
    undefined4 field_0xec; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Init(CGbxApp *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CGBXAPP_HPP
