#ifndef CGAMECTNREPLAYRECORD_HPP
#define CGAMECTNREPLAYRECORD_HPP

#include "typedefs.h"

struct CFastString;
struct CFastStringInt;

struct CGameCtnReplayRecord {
    byte _padding_0x0[4];
    CGameCtnReplayRecord * field_0x4; // accesses: 1
    byte _padding_0x8[12];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[12];
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[132];
    CFastStringInt * field_0xd0; // accesses: 1
    CGameCtnReplayRecord * field_0xd4; // accesses: 1
    byte _padding_0xd8[16];
    undefined4 field_0xe8; // accesses: 1
    ulong field_0xec; // accesses: 1
    ulong field_0xf0; // accesses: 1
    byte _padding_0xf4[4];
    int field_0xf8; // accesses: 1
    byte _padding_0xfc[16];
    undefined * field_0x10c; // accesses: 2

    // Member Functions
    CGameCtnGhost * __thiscall GetBestGhostStunts(CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1);
    CGameCtnGhost * __thiscall GhostGetByPlayerUid (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1,uchar param_2);
    EReplayGhostVersion __thiscall GetVersion(CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1);
    int __thiscall IsAlmostEmpty(CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1);
    ulong __thiscall ComputeReplayDuration (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1);
    ulong __thiscall GetBestGhostStuntsScore (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1);
    ulong __thiscall GhostGetIndexByPlayerUid (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1,uchar param_2);
    void __cdecl GetVersionString(EReplayGhostVersion param_1,CFastString *param_2);
    void __thiscall BuildReplayDefaultFileName (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1,CFastStringInt *param_2, int param_3,int param_4,CFastString *param_5);
    void __thiscall CGameCtnReplayRecord(CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1);
    void __thiscall GetBestGhostRaceTime (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1,ulong *param_2,ulong *param_3);
};

#endif // CGAMECTNREPLAYRECORD_HPP
