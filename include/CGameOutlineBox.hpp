#ifndef CGAMEOUTLINEBOX_HPP
#define CGAMEOUTLINEBOX_HPP

#include "typedefs.h"

struct CPlugTree;
struct CPlugVisual;

struct CGameOutlineBox {
    byte _padding_0x0[4];
    CGameOutlineBox * field_0x4; // accesses: 7
    CPlugVisual * field_0x8; // accesses: 9
    byte _padding_0xc[4];
    CGameOutlineBox * field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 9
    undefined4 field_0x18; // accesses: 9
    undefined4 field_0x1c; // accesses: 5
    undefined4 field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 4
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    CPlugVisual * field_0x30; // accesses: 3
    CPlugVisual * field_0x34; // accesses: 3
    CPlugVisual * field_0x38; // accesses: 3
    CPlugVisual * field_0x3c; // accesses: 3
    byte _padding_0x40[92];
    uint field_0x9c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ /* WARNING: Restarted to delay deadcode elimination for space: stack */ void __thiscall UpdateBox (CGameOutlineBox *this,CGameOutlineBox *param_1,CFastBuffer<int> *param_2,GmNat3 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CGameOutlineBox(CGameOutlineBox *this,CGameOutlineBox *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Init (CGameOutlineBox *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CGAMEOUTLINEBOX_HPP
