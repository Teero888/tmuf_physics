#ifndef CTRACKMANIAPLAYERINFO_HPP
#define CTRACKMANIAPLAYERINFO_HPP

#include "typedefs.h"

struct ulong;

struct CTrackManiaPlayerInfo {
    struct SRpcPlayerQuickInfo {
        void** vftable; // accesses: 1
        undefined1 field_0x1; // accesses: 1
        undefined2 field_0x2; // accesses: 1
        byte _padding_0x4[16];
        undefined4 field_0x14; // accesses: 1
        undefined4 field_0x18; // accesses: 1

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    void** vftable; // accesses: 2
    byte _padding_0x4[104];
    int field_0x6c; // accesses: 1
    int field_0x70; // accesses: 1
    byte _padding_0x74[20];
    int field_0x88; // accesses: 1
    byte _padding_0x8c[4];
    int field_0x90; // accesses: 1
    byte _padding_0x94[328];
    int field_0x1dc; // accesses: 1
    byte _padding_0x1e0[88];
    undefined4 field_0x238; // accesses: 1
    byte _padding_0x23c[4];
    undefined4 field_0x240; // accesses: 1
    byte _padding_0x244[96];
    undefined4 field_0x2a4; // accesses: 1
    undefined4 field_0x2a8; // accesses: 1
    undefined4 field_0x2ac; // accesses: 1
    byte _padding_0x2b0[4];
    undefined4 field_0x2b4; // accesses: 2
    undefined4 field_0x2b8; // accesses: 1
    byte _padding_0x2bc[4];
    undefined4 field_0x2c0; // accesses: 1
    undefined4 field_0x2c4; // accesses: 1
    undefined4 field_0x2c8; // accesses: 1
    undefined4 field_0x2cc; // accesses: 1
    undefined4 field_0x2d0; // accesses: 1
    undefined4 field_0x2d4; // accesses: 1
    byte _padding_0x2d8[8];
    undefined4 field_0x2e0; // accesses: 2
    undefined4 field_0x2e4; // accesses: 1
    undefined4 field_0x2e8; // accesses: 1
    undefined4 field_0x2ec; // accesses: 1
    undefined4 field_0x2f0; // accesses: 1
    undefined4 field_0x2f4; // accesses: 1
    byte _padding_0x2f8[16];
    undefined4 field_0x308; // accesses: 1
    undefined4 field_0x30c; // accesses: 1
    undefined * field_0x310; // accesses: 1
    ulong field_0x314; // accesses: 2
    undefined4 field_0x318; // accesses: 1
    undefined4 field_0x31c; // accesses: 1
    undefined4 field_0x320; // accesses: 1
    byte _padding_0x324[12];
    undefined4 field_0x330; // accesses: 1
    undefined4 field_0x334; // accesses: 1
    undefined4 field_0x338; // accesses: 1
    undefined4 field_0x33c; // accesses: 1
    undefined4 field_0x340; // accesses: 1
    undefined4 field_0x344; // accesses: 1
    undefined4 field_0x348; // accesses: 1
    undefined4 field_0x34c; // accesses: 1
    byte _padding_0x350[80];
    undefined4 field_0x3a0; // accesses: 1
    undefined * field_0x3a4; // accesses: 1
    undefined4 field_0x3a8; // accesses: 1
    undefined * field_0x3ac; // accesses: 1

    // Member Functions
    int __thiscall IsPureSpectator(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall CTrackManiaPlayerInfo (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall ChangeRaceState (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1,ulong param_2, ERaceState param_3);
    void __thiscall InitBestCheckpoints (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall InitCheckpoints(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall ResetAverageRank(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall ResetPerformance(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall SetNbCheckpoints (CTrackManiaPlayerInfo *this,CGameCtnGhost *param_1,ulong param_2);
    void __thiscall SetSpawnLoc (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1,GmIso4 *param_2,int param_3);
};

#endif // CTRACKMANIAPLAYERINFO_HPP
