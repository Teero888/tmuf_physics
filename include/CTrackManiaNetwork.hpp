#ifndef CTRACKMANIANETWORK_HPP
#define CTRACKMANIANETWORK_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CFastString;
struct CFastStringInt;
struct CGameCtnApp;
struct CGameCtnGhost;
struct CGameDialogs;
struct CGameMasterServer;
struct CMwNod;
struct CPlugAudio;
struct CTrackMania;
struct CTrackManiaNetForm;
struct STmValidateParam;

struct CTrackManiaNetwork {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 13
    byte _padding_0x8[4];
    int field_0xc; // accesses: 3
    undefined4 field_0x10; // accesses: 6
    CPlugAudio * field_0x14; // accesses: 8
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[4];
    undefined4 field_0x20; // accesses: 4
    undefined4 field_0x24; // accesses: 8
    undefined4 field_0x28; // accesses: 4
    undefined4 field_0x2c; // accesses: 4
    int field_0x30; // accesses: 4
    byte _padding_0x34[4];
    CFastStringInt * field_0x38; // accesses: 1
    int field_0x3c; // accesses: 2
    byte _padding_0x40[4];
    int field_0x44; // accesses: 2
    byte _padding_0x48[8];
    undefined4 field_0x50; // accesses: 1
    undefined * field_0x54; // accesses: 1
    byte _padding_0x58[24];
    int field_0x70; // accesses: 1
    int field_0x74; // accesses: 1
    byte _padding_0x78[100];
    int field_0xdc; // accesses: 2
    byte _padding_0xe0[48];
    code * field_0x110; // accesses: 1
    byte _padding_0x114[4];
    int field_0x118; // accesses: 4
    byte _padding_0x11c[148];
    CGameMasterServer * field_0x1b0; // accesses: 8
    byte _padding_0x1b4[28];
    int field_0x1d0; // accesses: 3
    byte _padding_0x1d4[44];
    int field_0x200; // accesses: 3
    byte _padding_0x204[4];
    ulong field_0x208; // accesses: 1
    byte _padding_0x20c[48];
    CTrackManiaNetworkServerInfo * field_0x23c; // accesses: 1
    byte _padding_0x240[20];
    int field_0x254; // accesses: 1
    byte _padding_0x258[8];
    undefined4 field_0x260; // accesses: 3
    byte _padding_0x264[72];
    int field_0x2ac; // accesses: 3
    byte _padding_0x2b0[840];
    CGameCtnApp * field_0x5f8; // accesses: 16
    byte _padding_0x5fc[96];
    undefined4 field_0x65c; // accesses: 2
    int field_0x660; // accesses: 8
    byte _padding_0x664[156];
    int field_0x700; // accesses: 1
    byte _padding_0x704[212];
    undefined4 field_0x7d8; // accesses: 4
    byte _padding_0x7dc[68];
    undefined4 field_0x820; // accesses: 4
    byte _padding_0x824[8];
    undefined4 field_0x82c; // accesses: 1
    byte _padding_0x830[32];
    CClassicArchive * field_0x850; // accesses: 2

    // Member Functions
    CTrackManiaMenus * __thiscall GetMenuManager(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1);
    CTrackManiaNetworkServerInfo * __thiscall GetServerInfo(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1);
    int __thiscall ForceEndRound (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CFastString *param_2);
    int __thiscall ForcePlayerTeam (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CGameNetPlayerInfo *param_2, ulong param_3,CFastString *param_4);
    int __thiscall ForceScores (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1, CFastBuffer<struct_CTrackManiaNetwork::SRpcForcedScores> *param_2,int param_3, CFastString *param_4);
    int __thiscall ForceSpectatorTarget (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CGameNetPlayerInfo *param_2, CGameNetPlayerInfo *param_3,ulong param_4,CFastString *param_5);
    int __thiscall GetForceShowAllOpponents (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,int *param_2,int *param_3, CFastString *param_4);
    int __thiscall GetRoundForcedLaps (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,ulong *param_2,ulong *param_3, CFastString *param_4);
    int __thiscall SetForceShowAllOpponents (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,int param_2,CFastString *param_3);
    int __thiscall SetRoundForcedLaps (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,ulong param_2,CFastString *param_3);
    void __thiscall ChallengeNetRoundsFinished (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,int param_2);
    void __thiscall Hack_ResetAfterValidation(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1);
    void __thiscall RefereeDoOneStep (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,SMwFiberContext **param_2, int *param_3);
    void __thiscall RefereeLog (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CFastStringInt *param_2,int param_3);
    void __thiscall SendInvalidReplay (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CFastString *param_2, CGameCtnReplayRecord *param_3,CFastStringInt *param_4);
    void __thiscall SendRefereePlayerScoreCheckResult (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,ulong param_2,CFastString *param_3, ulong param_4,ETmValidateResult param_5,ulong param_6);
    void __thiscall SendScores(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,uchar param_2);
    void __thiscall ValidateReplay (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,SMwFiberContext **param_2, CFastString *param_3,CFastStringInt *param_4,int param_5,CFastString *param_6, CMwNodRef<class_CGameCtnReplayRecord> *param_7,ulong param_8,ulong param_9);
};

#endif // CTRACKMANIANETWORK_HPP
