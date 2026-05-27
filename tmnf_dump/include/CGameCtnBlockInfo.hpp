#ifndef CGAMECTNBLOCKINFO_HPP
#define CGAMECTNBLOCKINFO_HPP

#include "typedefs.h"

struct CGameCtnBlockInfo {
    void** vftable; // accesses: 1
    byte _padding_0x4[44];
    undefined4 field_0x30; // accesses: 1
    byte _padding_0x34[36];
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    byte _padding_0x80[36];
    float field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    float field_0xac; // accesses: 1
    byte _padding_0xb0[36];
    float field_0xd4; // accesses: 1
    undefined4 field_0xd8; // accesses: 1
    float field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 1
    undefined4 field_0xe8; // accesses: 1
    byte _padding_0xec[32];
    undefined4 field_0x10c; // accesses: 1
    undefined4 field_0x110; // accesses: 1
    undefined4 field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 1
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    byte _padding_0x128[4];
    undefined4 field_0x12c; // accesses: 1

    // Member Functions
    CFastBuffer<class_CSceneMobil*> * __thiscall GetMobilBuffer (CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1,int param_2,ulong param_3);
    CGameCtnBlockUnitInfo * __thiscall GetBlockUnitInfo (CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1,ulong param_2,int param_3);
    CSceneMobil * __thiscall GetMobil (CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1,int param_2,ulong param_3, ulong param_4);
    ulong __thiscall GetNbBlockUnitInfos (CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1,int param_2);
    void __thiscall AddBlock (CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1,GmNat3 param_2,int param_3, ulong param_4,int param_5);
    void __thiscall CGameCtnBlockInfo(CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1);
};

#endif // CGAMECTNBLOCKINFO_HPP
