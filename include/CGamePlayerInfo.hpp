#ifndef CGAMEPLAYERINFO_HPP
#define CGAMEPLAYERINFO_HPP

#include "typedefs.h"

struct CGamePlayerInfo {
    byte _padding_0x0[388];
    undefined4 field_0x184; // accesses: 1
    undefined * field_0x188; // accesses: 1
    byte _padding_0x18c[20];
    undefined4 field_0x1a0; // accesses: 1
    undefined4 field_0x1a4; // accesses: 1
    undefined4 field_0x1a8; // accesses: 1
    undefined4 field_0x1ac; // accesses: 1
    undefined4 field_0x1b0; // accesses: 1
    undefined4 field_0x1b4; // accesses: 1
    undefined4 field_0x1b8; // accesses: 1
    byte _padding_0x1bc[8];
    undefined4 field_0x1c4; // accesses: 1
    undefined4 field_0x1c8; // accesses: 1
    undefined4 field_0x1cc; // accesses: 1
    CGamePlayerInfo * field_0x1d0; // accesses: 1
    byte _padding_0x1d4[8];
    undefined4 field_0x1dc; // accesses: 1
    undefined4 field_0x1e0; // accesses: 1
    undefined4 field_0x1e4; // accesses: 1
    undefined4 field_0x1e8; // accesses: 1
    undefined4 field_0x1ec; // accesses: 1
    undefined4 field_0x1f0; // accesses: 1
    undefined4 field_0x1f4; // accesses: 1
    undefined * field_0x1f8; // accesses: 1
    byte _padding_0x1fc[8];
    undefined4 field_0x204; // accesses: 1
    byte _padding_0x208[36];
    undefined4 field_0x22c; // accesses: 1
    undefined * field_0x230; // accesses: 1
    undefined4 field_0x234; // accesses: 1
    undefined4 field_0x238; // accesses: 1

    // Member Functions
    int __thiscall PlayerTags_IsLoaded(CGamePlayerInfo *this,CGamePlayerInfo *param_1);
    void __thiscall CGamePlayerInfo(CGamePlayerInfo *this,CGamePlayerInfo *param_1);
};

#endif // CGAMEPLAYERINFO_HPP
