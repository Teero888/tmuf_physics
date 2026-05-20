#ifndef CGAMESCENE_HPP
#define CGAMESCENE_HPP

#include "typedefs.h"

struct CGameScene {
    void** vftable;
    byte _padding_0x4[16];
    int * field_0x14; // accesses: 1
    byte _final_padding[0x10]; // Total size: 0x28

    // Member Functions
    CGameMobil * __thiscall GameMobilGetFromId(CGameScene *this,CGameScene *param_1,ulong param_2);
    void __thiscall GameMobilRemove(CGameScene *this,CGameScene *param_1,CGameMobil *param_2);
};

#endif // CGAMESCENE_HPP
