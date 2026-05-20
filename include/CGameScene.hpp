#ifndef CGAMESCENE_HPP
#define CGAMESCENE_HPP

#include "typedefs.h"

struct CGameScene {
    byte _padding_0x0[20];
    int * field_0x14; // accesses: 2
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 2
    byte _padding_0x20[4];
    int * field_0x24; // accesses: 1
    byte _padding_0x28[8];
    int field_0x30; // accesses: 2

    // Member Functions
    CGameMobil * __thiscall GameMobilGetFromId(CGameScene *this,CGameScene *param_1,ulong param_2);
    void __thiscall GameMobilRemove(CGameScene *this,CGameScene *param_1,CGameMobil *param_2);
};

#endif // CGAMESCENE_HPP
