#ifndef CGAMECTNBLOCK_HPP
#define CGAMECTNBLOCK_HPP

#include "typedefs.h"

struct CGameCtnBlock {
    void** vftable;
    byte _padding_0x4[32];
    int field_0x24; // accesses: 4
    byte _padding_0x28[56];
    uint field_0x60; // accesses: 1

    // Member Functions
    EBlockType __thiscall GetType(CGameCtnBlock *this,CGameCtnBlock *param_1);
    void __thiscall GetMobilLoc(CGameCtnBlock *this,CGameCtnBlock *param_1,GmIso4 *param_2);
    void __thiscall GetSpawnLoc (CGameCtnBlock *this,CGameCtnBlock *param_1,GmIso4 *param_2,ulong param_3,ulong param_4);
};

#endif // CGAMECTNBLOCK_HPP
