#ifndef CGBXGAME_HPP
#define CGBXGAME_HPP

#include "typedefs.h"

struct CMwEngine;
struct CMwNod;
struct CSystemConfig;

struct CGbxGame {
    void** vftable; // accesses: 1
    byte _padding_0x4[40];
    HINSTANCE field_0x2c; // accesses: 1
    CSystemConfig * field_0x30; // accesses: 8
    byte _padding_0x34[8];
    int field_0x3c; // accesses: 1
    byte _padding_0x40[16];
    HWND field_0x50; // accesses: 1
    byte _padding_0x54[40];
    undefined4 field_0x7c; // accesses: 1
    wchar_t * field_0x80; // accesses: 3
    byte _padding_0x84[124];
    int field_0x100; // accesses: 2
    int field_0x104; // accesses: 1
    byte _padding_0x108[4];
    int field_0x10c; // accesses: 1
    byte _padding_0x110[12];
    int field_0x11c; // accesses: 1

    // Member Functions
    int __thiscall CheckNetwork(CGbxGame *this,CGbxGame *param_1);
    int __thiscall IsForceWindowed(CGbxGame *this,CGbxGame *param_1);
    void __thiscall Init(CGbxGame *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CGBXGAME_HPP
