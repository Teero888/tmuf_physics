#ifndef CGAMENETPLAYERINFO_HPP
#define CGAMENETPLAYERINFO_HPP

#include "typedefs.h"

struct CGameNetPlayerInfo {
    byte _padding_0x0[36];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined * field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined * field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined * field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 2
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 2
    undefined4 field_0x74; // accesses: 2
    byte _padding_0x78[4];
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 1
    byte _padding_0x98[32];
    undefined4 field_0xb8; // accesses: 1
    undefined4 field_0xbc; // accesses: 1
    byte _padding_0xc0[4];
    undefined4 field_0xc4; // accesses: 1
    byte _padding_0xc8[12];
    undefined4 field_0xd4; // accesses: 1
    undefined4 field_0xd8; // accesses: 1
    undefined4 field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    byte _padding_0xe4[36];
    ulong field_0x108; // accesses: 1
    undefined4 field_0x10c; // accesses: 1
    undefined4 field_0x110; // accesses: 1
    undefined4 field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 1
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    undefined4 field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 1
    undefined2 field_0x130; // accesses: 1
    undefined2 field_0x132; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    byte _padding_0x138[8];
    undefined2 field_0x140; // accesses: 1
    byte _padding_0x142[2];
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 2
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    undefined4 field_0x15c; // accesses: 1
    undefined4 field_0x160; // accesses: 1
    undefined4 field_0x164; // accesses: 1
    byte _padding_0x168[12];
    undefined4 field_0x174; // accesses: 1

    // Member Functions
    int __thiscall IsSpectator(CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1);
    void __thiscall CGameNetPlayerInfo(CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1);
    void __thiscall RemoveNetStateSending (CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1,uchar param_2);
    void __thiscall SetDirty(CGameNetPlayerInfo *this,CPlugVertexStream *param_1,int param_2);
    void __thiscall SetGeneratedPlayerUId (CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1,uchar param_2);
};

#endif // CGAMENETPLAYERINFO_HPP
