#ifndef CTRACKMANIARACE_HPP
#define CTRACKMANIARACE_HPP

#include "typedefs.h"

struct CAudioSound;
struct CGameApp;
struct CGameCamera;
struct CGameControlCameraMaster;
struct CGameCtnBlock;
struct CGameCtnChallenge;
struct CGameCtnGhost;
struct CGameCtnMediaClipPlayer;
struct CGamePlayerCameraSet;
struct CGameRace;
struct CHmsItem;
struct CInputPort;
struct CMwCmdBufferCore;
struct CMwNod;
struct CPlugAudio;
struct CTrackMania;
struct CTrackManiaPlayerInfo;
struct CTrackManiaRaceInterface;
struct GmMat3;

struct CTrackManiaRace {
    byte _padding_0x0[4];
    CTrackManiaRace * field_0x4; // accesses: 8
    int field_0x8; // accesses: 4
    byte _padding_0xc[8];
    CMwCmdBufferCore * field_0x14; // accesses: 7
    CTrackMania * field_0x18; // accesses: 41
    int field_0x1c; // accesses: 3
    int field_0x20; // accesses: 20
    int field_0x24; // accesses: 11
    CHmsItem * field_0x28; // accesses: 20
    float field_0x2c; // accesses: 6
    int field_0x30; // accesses: 3
    CGameCamera * field_0x34; // accesses: 8
    byte _padding_0x38[8];
    CTrackManiaRace * field_0x40; // accesses: 3
    CTrackManiaRace * field_0x44; // accesses: 1
    CTrackManiaRace * field_0x48; // accesses: 3
    int field_0x4c; // accesses: 1
    int field_0x50; // accesses: 2
    GmMat3 * field_0x54; // accesses: 1
    byte _padding_0x58[8];
    uint field_0x60; // accesses: 4
    byte _padding_0x64[12];
    int field_0x70; // accesses: 6
    int field_0x74; // accesses: 6
    int field_0x78; // accesses: 3
    int field_0x7c; // accesses: 2
    int field_0x80; // accesses: 2
    byte _padding_0x84[4];
    int field_0x88; // accesses: 1
    code * field_0x8c; // accesses: 1
    byte _padding_0x90[8];
    int field_0x98; // accesses: 1
    uint field_0x9c; // accesses: 2
    CGameCtnMediaClipPlayer * field_0xa0; // accesses: 5
    int field_0xa4; // accesses: 2
    int field_0xa8; // accesses: 2
    byte _padding_0xac[4];
    int field_0xb0; // accesses: 2
    CMwNod * field_0xb4; // accesses: 4
    byte _padding_0xb8[12];
    CGameCtnChallenge * field_0xc4; // accesses: 28
    byte _padding_0xc8[4];
    undefined4 field_0xcc; // accesses: 1
    CTrackManiaRace * field_0xd0; // accesses: 4
    byte _padding_0xd4[24];
    ulong field_0xec; // accesses: 11
    int field_0xf0; // accesses: 1
    int field_0xf4; // accesses: 4
    byte _padding_0xf8[4];
    int field_0xfc; // accesses: 4
    undefined4 field_0x100; // accesses: 1
    float field_0x104; // accesses: 4
    CTrackManiaRace * field_0x108; // accesses: 4
    int field_0x10c; // accesses: 5
    CTrackManiaRace * field_0x110; // accesses: 4
    byte _padding_0x114[12];
    int field_0x120; // accesses: 1
    byte _padding_0x124[36];
    int field_0x148; // accesses: 1
    byte _padding_0x14c[28];
    int field_0x168; // accesses: 1
    CGameRace * field_0x16c; // accesses: 1
    byte _padding_0x170[4];
    undefined4 field_0x174; // accesses: 2
    float field_0x178; // accesses: 1
    byte _padding_0x17c[116];
    undefined4 field_0x1f0; // accesses: 1
    byte _padding_0x1f4[20];
    int field_0x208; // accesses: 2
    byte _padding_0x20c[32];
    undefined4 field_0x22c; // accesses: 1
    byte _padding_0x230[8];
    int field_0x238; // accesses: 4
    byte _padding_0x23c[24];
    CGameRace * field_0x254; // accesses: 1
    byte _padding_0x258[12];
    float field_0x264; // accesses: 1
    CTrackManiaRace * field_0x268; // accesses: 1
    undefined4 field_0x26c; // accesses: 1
    int field_0x270; // accesses: 2
    ulong field_0x274; // accesses: 3
    float field_0x278; // accesses: 2
    byte _padding_0x27c[12];
    int field_0x288; // accesses: 3
    byte _padding_0x28c[24];
    CGameRace * field_0x2a4; // accesses: 1
    byte _padding_0x2a8[4];
    CGameRace * field_0x2ac; // accesses: 8
    ulong field_0x2b0; // accesses: 4
    byte _padding_0x2b4[4];
    int field_0x2b8; // accesses: 1
    ulong field_0x2bc; // accesses: 1
    int field_0x2c0; // accesses: 2
    ulong field_0x2c4; // accesses: 6
    byte _padding_0x2c8[12];
    ulong field_0x2d4; // accesses: 3
    byte _padding_0x2d8[4];
    int field_0x2dc; // accesses: 3
    byte _padding_0x2e0[28];
    int field_0x2fc; // accesses: 9
    void * field_0x300; // accesses: 1
    undefined4 field_0x304; // accesses: 2
    void * field_0x308; // accesses: 8
    int field_0x30c; // accesses: 3
    byte _padding_0x310[4];
    int field_0x314; // accesses: 4
    int field_0x318; // accesses: 2
    float field_0x31c; // accesses: 3
    int field_0x320; // accesses: 5
    undefined4 field_0x324; // accesses: 2
    float field_0x328; // accesses: 2
    int field_0x32c; // accesses: 4
    int field_0x330; // accesses: 11
    undefined4 field_0x334; // accesses: 1
    undefined4 field_0x338; // accesses: 1
    int field_0x33c; // accesses: 5
    CTrackManiaRace * field_0x340; // accesses: 4
    byte _padding_0x344[104];
    undefined4 field_0x3ac; // accesses: 1
    byte _padding_0x3b0[124];
    undefined4 field_0x42c; // accesses: 1
    byte _padding_0x430[40];
    undefined4 field_0x458; // accesses: 1
    undefined4 field_0x45c; // accesses: 1
    undefined4 field_0x460; // accesses: 1
    byte _padding_0x464[72];
    undefined4 field_0x4ac; // accesses: 1
    byte _padding_0x4b0[20];
    undefined4 field_0x4c4; // accesses: 1
    undefined4 field_0x4c8; // accesses: 1
    undefined4 field_0x4cc; // accesses: 1
    undefined4 field_0x4d0; // accesses: 1
    undefined4 field_0x4d4; // accesses: 1
    undefined4 field_0x4d8; // accesses: 1
    undefined4 field_0x4dc; // accesses: 1
    undefined4 field_0x4e0; // accesses: 1
    byte _padding_0x4e4[4];
    int field_0x4e8; // accesses: 2
    int field_0x4ec; // accesses: 4
    undefined4 field_0x4f0; // accesses: 2
    undefined4 field_0x4f4; // accesses: 2
    undefined4 field_0x4f8; // accesses: 2
    undefined4 field_0x4fc; // accesses: 2
    CGameCtnChallenge * field_0x500; // accesses: 2
    byte _padding_0x504[12];
    int field_0x510; // accesses: 11
    int field_0x514; // accesses: 5
    CTrackManiaRaceInterface * field_0x518; // accesses: 4
    ECallback field_0x51c; // accesses: 1
    byte _padding_0x520[24];
    int field_0x538; // accesses: 6
    int field_0x53c; // accesses: 1
    int field_0x540; // accesses: 3
    int field_0x544; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Ghosts_UpdateAsync(CTrackManiaRace *this,CTrackManiaRace *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SwitchToRace (CTrackManiaRace *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateAsync(CTrackManiaRace *this,CInputPortDx8 *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateCountDownIndex(CTrackManiaRace *this,CTrackManiaRace *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Validate (CTrackManiaRace *this,CTrackManiaRace *param_1,SMwFiberContext **param_2, STmValidateParam *param_3,ETmValidateResult *param_4,CFastStringInt *param_5,int param_6, int param_7,int param_8);
    CGameCtnBlock * __thiscall GetBlockFromCheckpointMobil (CTrackManiaRace *this,CTrackManiaRace *param_1,CSceneMobil *param_2);
    CTrackManiaPlayer * __thiscall GetPlayerFromMobil (CTrackManiaRace *this,CTrackManiaRace *param_1,CSceneMobil *param_2);
    CTrackManiaPlayer * __thiscall GetPlayingPlayer(CTrackManiaRace *this,CTrackManiaRace *param_1);
    CTrackManiaPlayerInfo * __thiscall GetPlayingPlayerInfo(CTrackManiaRace *this,CTrackManiaRace *param_1);
    int __thiscall IsStuntTimeOver(CTrackManiaRace *this,CTrackManiaRace *param_1,ulong param_2);
    ulong __thiscall GetCurrentStandardTime(CTrackManiaRace *this,CTrackManiaRace *param_1);
    ulong __thiscall GetTimePenalty(CTrackManiaRace *this,CTrackManiaRace *param_1,ulong param_2);
    void __thiscall GetPlayerOrGhosts (CTrackManiaRace *this,CTrackManiaRace *param_1, CFastBuffer<struct_CTrackManiaRace::SPlayerOrGhost> *param_2);
    void __thiscall Ghosts_PreviousRaceGhostsClear(CTrackManiaRace *this,CTrackManiaRace *param_1);
    void __thiscall InitNbLapsAndCheckpoints (CTrackManiaRace *this,CTrackManiaRace *param_1,ulong param_2);
    void __thiscall InternalPrepareEvent (CTrackManiaRace *this,CTrackManiaRace *param_1,CTrackManiaPlayer *param_2);
    void __thiscall PrepareCheckpoints(CTrackManiaRace *this,CTrackManiaRace *param_1);
    void __thiscall StopReplayRecordAndKeepCopy (CTrackManiaRace *this,CTrackManiaRace *param_1,int param_2);
    void __thiscall UnassignCamFreePrimaryActionKeys (CTrackManiaRace *this,CTrackManiaRace *param_1,CTrackManiaPlayer *param_2);
    void __thiscall UpdateCams(CTrackManiaRace *this,CGameCtnMediaClipViewer *param_1);
    void __thiscall ValidateCleanup(CTrackManiaRace *this,CTrackManiaRace *param_1);
};

#endif // CTRACKMANIARACE_HPP
