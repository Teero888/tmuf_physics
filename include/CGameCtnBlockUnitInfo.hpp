#ifndef CGAMECTNBLOCKUNITINFO_HPP
#define CGAMECTNBLOCKUNITINFO_HPP

#include "typedefs.h"

struct CGameCtnBlockInfo;

struct CGameCtnBlockUnitInfo {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[8];
    CGameCtnBlockInfoClip * field_0x28; // accesses: 1
    CGameCtnBlockInfoClip * field_0x2c; // accesses: 1
    CGameCtnBlockInfo * field_0x30; // accesses: 1
    byte _padding_0x34[4];
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[12];
    undefined4 field_0x50; // accesses: 1

    // Member Functions
    void __thiscall CGameCtnBlockUnitInfo (CGameCtnBlockUnitInfo *this,CGameCtnBlockUnitInfo *param_1,GmNat3 param_2,ulong param_3, ulong param_4,CGameCtnBlockInfoClip *param_5,CGameCtnBlockInfoClip *param_6, CGameCtnBlockInfoClip *param_7,CGameCtnBlockInfoClip *param_8,CGameCtnBlockInfo *param_9);
};

#endif // CGAMECTNBLOCKUNITINFO_HPP
