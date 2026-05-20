#ifndef CGAMEOUTLINEBOX_HPP
#define CGAMEOUTLINEBOX_HPP

#include "typedefs.h"

struct CPlugTree;

struct CGameOutlineBox {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    CPlugTree * field_0x14; // accesses: 8
    CPlugTree * field_0x18; // accesses: 8
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[12];
    float field_0x3c; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ /* WARNING: Restarted to delay deadcode elimination for space: stack */ void __thiscall UpdateBox (CGameOutlineBox *this,CGameOutlineBox *param_1,CFastBuffer<int> *param_2,GmNat3 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CGameOutlineBox(CGameOutlineBox *this,CGameOutlineBox *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Init (CGameOutlineBox *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CGAMEOUTLINEBOX_HPP
