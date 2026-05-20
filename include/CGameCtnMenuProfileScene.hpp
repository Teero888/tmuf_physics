#ifndef CGAMECTNMENUPROFILESCENE_HPP
#define CGAMECTNMENUPROFILESCENE_HPP

#include "typedefs.h"

struct CGameCtnMenuProfileScene {
    void** vftable;
    byte _padding_0x4[24];
    int * field_0x1c; // accesses: 2
    int * field_0x20; // accesses: 2
    float field_0x24; // accesses: 1
    byte _padding_0x28[4];
    float field_0x2c; // accesses: 1
    float field_0x30; // accesses: 3
    float field_0x34; // accesses: 4
    float field_0x38; // accesses: 3

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x0072d097) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CGameCtnMenuProfileScene::UpdateAsync(CGameCtnMenuProfileScene *this,CInputPortDx8 *param_1);
};

#endif // CGAMECTNMENUPROFILESCENE_HPP
