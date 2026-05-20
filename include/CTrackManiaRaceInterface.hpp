#ifndef CTRACKMANIARACEINTERFACE_HPP
#define CTRACKMANIARACEINTERFACE_HPP

#include "typedefs.h"

struct CControlBase;
struct CControlContainer;
struct CControlEntry;
struct CControlLabel;
struct CControlText;
struct CFastString;
struct CGameApp;
struct CGameNetwork;
struct CGamePlayerCameraSet;
struct CGameRace;
struct CInputPort;
struct CPlugAudio;
struct CTrackManiaControlScores2;
struct CTrackManiaNetwork;
struct CTrackManiaRaceNet;
struct SStringParam;

struct CTrackManiaRaceInterface {
    byte _padding_0x0[4];
    CFastString * field_0x4; // accesses: 4
    CFastString * field_0x8; // accesses: 3
    byte _padding_0xc[4];
    int field_0x10; // accesses: 1
    int field_0x14; // accesses: 7
    int field_0x18; // accesses: 2
    CFastString * field_0x1c; // accesses: 4
    int field_0x20; // accesses: 3
    byte _padding_0x24[4];
    int field_0x28; // accesses: 3
    byte _padding_0x2c[32];
    ulong field_0x4c; // accesses: 1
    ulong field_0x50; // accesses: 1
    byte _padding_0x54[24];
    int field_0x6c; // accesses: 4
    int field_0x70; // accesses: 10
    int field_0x74; // accesses: 9
    byte _padding_0x78[4];
    int field_0x7c; // accesses: 1
    uint field_0x80; // accesses: 4
    byte _padding_0x84[4];
    int field_0x88; // accesses: 1
    byte _padding_0x8c[4];
    int field_0x90; // accesses: 1
    byte _padding_0x94[8];
    int field_0x9c; // accesses: 2
    CGameRace * field_0xa0; // accesses: 59
    byte _padding_0xa4[4];
    int field_0xa8; // accesses: 37
    int field_0xac; // accesses: 1
    int * field_0xb0; // accesses: 8
    int field_0xb4; // accesses: 4
    uint field_0xb8; // accesses: 1
    uint field_0xbc; // accesses: 2
    int field_0xc0; // accesses: 5
    int field_0xc4; // accesses: 2
    undefined4 field_0xc8; // accesses: 2
    CControlBase * field_0xcc; // accesses: 1
    byte _padding_0xd0[8];
    int field_0xd8; // accesses: 2
    CControlBase * field_0xdc; // accesses: 9
    CControlBase * field_0xe0; // accesses: 1
    CControlBase * field_0xe4; // accesses: 1
    CControlBase * field_0xe8; // accesses: 1
    CControlBase * field_0xec; // accesses: 1
    CControlBase * field_0xf0; // accesses: 1
    CControlBase * field_0xf4; // accesses: 1
    CControlBase * field_0xf8; // accesses: 1
    int * field_0xfc; // accesses: 3
    CControlBase * field_0x100; // accesses: 1
    CControlBase * field_0x104; // accesses: 1
    CTrackManiaControlScores2 * field_0x108; // accesses: 14
    CTrackManiaControlScores2 * field_0x10c; // accesses: 6
    int field_0x110; // accesses: 5
    int * field_0x114; // accesses: 3
    CControlBase * field_0x118; // accesses: 1
    byte _padding_0x11c[12];
    CControlBase * field_0x128; // accesses: 2
    CControlBase * field_0x12c; // accesses: 2
    CControlBase * field_0x130; // accesses: 2
    byte _padding_0x134[4];
    CControlBase * field_0x138; // accesses: 1
    int field_0x13c; // accesses: 3
    int * field_0x140; // accesses: 6
    uint field_0x144; // accesses: 3
    CControlBase * field_0x148; // accesses: 5
    CControlBase * field_0x14c; // accesses: 5
    CControlBase * field_0x150; // accesses: 2
    ulong field_0x154; // accesses: 3
    int field_0x158; // accesses: 3
    CMwCmdScriptVarBool * field_0x15c; // accesses: 2
    CControlBase * field_0x160; // accesses: 1
    byte _padding_0x164[4];
    int field_0x168; // accesses: 1
    int field_0x16c; // accesses: 2
    int field_0x170; // accesses: 1
    byte _padding_0x174[4];
    CControlBase * field_0x178; // accesses: 1
    CControlBase * field_0x17c; // accesses: 1
    CControlBase * field_0x180; // accesses: 1
    CControlBase * field_0x184; // accesses: 1
    int field_0x188; // accesses: 3
    byte _padding_0x18c[12];
    int field_0x198; // accesses: 2
    CControlBase * field_0x19c; // accesses: 1
    int field_0x1a0; // accesses: 6
    CControlBase * field_0x1a4; // accesses: 1
    byte _padding_0x1a8[4];
    CControlBase * field_0x1ac; // accesses: 1
    CControlBase * field_0x1b0; // accesses: 1
    CControlBase * field_0x1b4; // accesses: 1
    CControlBase * field_0x1b8; // accesses: 1
    CControlBase * field_0x1bc; // accesses: 1
    CControlBase * field_0x1c0; // accesses: 1
    CControlBase * field_0x1c4; // accesses: 1
    CControlBase * field_0x1c8; // accesses: 1
    CControlBase * field_0x1cc; // accesses: 1
    float field_0x1d0; // accesses: 1
    float field_0x1d4; // accesses: 1
    float field_0x1d8; // accesses: 1
    float field_0x1dc; // accesses: 1
    float field_0x1e0; // accesses: 1
    float field_0x1e4; // accesses: 1
    byte _padding_0x1e8[4];
    CControlBase * field_0x1ec; // accesses: 2
    byte _padding_0x1f0[4];
    CControlBase * field_0x1f4; // accesses: 2
    CControlBase * field_0x1f8; // accesses: 2
    byte _padding_0x1fc[4];
    int field_0x200; // accesses: 8
    CControlBase * field_0x204; // accesses: 1
    byte _padding_0x208[8];
    int field_0x210; // accesses: 6
    int * field_0x214; // accesses: 11
    int * field_0x218; // accesses: 3
    ulong field_0x21c; // accesses: 5
    byte _padding_0x220[56];
    CControlBase * field_0x258; // accesses: 1
    int field_0x25c; // accesses: 7
    int * field_0x260; // accesses: 3
    CControlBase * field_0x264; // accesses: 1
    int field_0x268; // accesses: 2
    byte _padding_0x26c[4];
    uint field_0x270; // accesses: 1
    byte _padding_0x274[20];
    int field_0x288; // accesses: 2
    byte _padding_0x28c[12];
    int field_0x298; // accesses: 2
    int field_0x29c; // accesses: 2
    int field_0x2a0; // accesses: 1
    ulong field_0x2a4; // accesses: 4
    byte _padding_0x2a8[4];
    int field_0x2ac; // accesses: 4
    int * field_0x2b0; // accesses: 4
    int field_0x2b4; // accesses: 1
    byte _padding_0x2b8[28];
    CFastString * field_0x2d4; // accesses: 1
    byte _padding_0x2d8[8];
    int field_0x2e0; // accesses: 1
    byte _padding_0x2e4[12];
    ulong field_0x2f0; // accesses: 3
    float field_0x2f4; // accesses: 2
    float field_0x2f8; // accesses: 2
    float field_0x2fc; // accesses: 3
    ulong field_0x300; // accesses: 5
    float field_0x304; // accesses: 1
    float field_0x308; // accesses: 1
    int field_0x30c; // accesses: 2
    undefined4 field_0x310; // accesses: 1
    int field_0x314; // accesses: 1
    byte _padding_0x318[744];
    int field_0x600; // accesses: 1
    byte _padding_0x604[8];
    int field_0x60c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateDownloadProgress (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateNoMoveMessage (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdatePodium (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateRaceMessage (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    /* WARNING: Removing unreachable block (ram,0x004c0282) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CTrackManiaRaceInterface::UpdateScores (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    /* WARNING: Removing unreachable block (ram,0x004c2f89) */ /* WARNING: Removing unreachable block (ram,0x004c30b3) */ /* WARNING: Removing unreachable block (ram,0x004c30b7) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl CTrackManiaRaceInterface::GetStuntMessages (int param_1,SEventStunt *param_2,CFastStringInt *param_3,CFastStringInt *param_4, CFastStringInt *param_5);
    CTrackMania * __thiscall GetGame (CTrackManiaRaceInterface *this,CTrackManiaEnvironmentManager *param_1);
    CTrackManiaRaceNet * __thiscall GetRace(CTrackManiaRaceInterface *this,CTrackManiaNetwork *param_1);
    int __thiscall IsMeaningFulPosition (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall CallVoteMessage_Hide (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall GetKeyFromActionIndex (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1, SInputActionDesc *param_2,CFastStringInt *param_3);
    void __thiscall NoMoveMessage_Start (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1,CFastStringInt *param_2);
    void __thiscall NoMoveMessage_Stop (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall OnNetSpectatorCameraChange (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall OnServerInfoChange (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall OnStuntEvent (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1,SEventStunt *param_2);
    void __thiscall OnStuntTimeOverMessage (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall SetAvatarIconChat (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1,CGamePlayerInfo *param_2 ,CFastStringInt *param_3);
    void __thiscall UpdateAsync(CTrackManiaRaceInterface *this,CInputPortDx8 *param_1);
    void __thiscall UpdateCallVoteMessage (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateChat (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateChatIcon (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateCheckpointInfo (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateEndMatchCountdown (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateLapsCounter (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateMainFramesVisibility (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateMultiCountdown (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdatePleaseWaitMessage (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateRaceCountdown (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateRefereesWorkingMessage (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateSpectatorCounter (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateStuntMessage (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
    void __thiscall UpdateTimeColor (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1);
};

#endif // CTRACKMANIARACEINTERFACE_HPP
