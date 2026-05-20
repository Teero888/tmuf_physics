#ifndef CGAMERACE_HPP
#define CGAMERACE_HPP

#include "typedefs.h"

struct CGameApp;
struct CGameCtnApp;
struct CGameCtnMediaClipPlayer;
struct CGameNetPlayerInfo;
struct CGamePlayer;
struct CGamePlayerCameraSet;
struct CGameScene;
struct CMwNod;

struct CGameRace {
    struct SCameraPreset {

        // Member Functions
        void __thiscall SCameraPreset(void *this,SCameraPreset *param_1);
    };

    struct SPlayerInfosForTargetting {

        // Member Functions
        void __thiscall SPlayerInfosForTargetting (void *this,SPlayerInfosForTargetting *param_1);
        void __thiscall ~SPlayerInfosForTargetting (void *this,SPlayerInfosForTargetting *param_1);
    };

    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[4];
    int field_0x10; // accesses: 2
    int * field_0x14; // accesses: 2
    int * field_0x18; // accesses: 17
    int field_0x1c; // accesses: 2
    CMwNod * field_0x20; // accesses: 13
    int field_0x24; // accesses: 3
    CGameRace * field_0x28; // accesses: 11
    CGameNetPlayerInfo * field_0x2c; // accesses: 1
    CGameScene * field_0x30; // accesses: 5
    CMwNod * field_0x34; // accesses: 4
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    byte _padding_0x40[4];
    undefined4 field_0x44; // accesses: 3
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[4];
    CGameRace * field_0x50; // accesses: 2
    undefined4 field_0x54; // accesses: 3
    CGameCtnMediaClipPlayer * field_0x58; // accesses: 8
    undefined4 field_0x5c; // accesses: 3
    CGameCtnMediaClipPlayer * field_0x60; // accesses: 15
    byte _padding_0x64[8];
    int field_0x6c; // accesses: 6
    CGameRace * field_0x70; // accesses: 7
    int field_0x74; // accesses: 7
    undefined4 field_0x78; // accesses: 1
    CGameRace * field_0x7c; // accesses: 2
    CGamePlayerCameraSet * field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    byte _padding_0x8c[4];
    int field_0x90; // accesses: 1
    byte _padding_0x94[4];
    CGameRace * field_0x98; // accesses: 6
    undefined4 field_0x9c; // accesses: 2
    CGameCtnMediaClipPlayer * field_0xa0; // accesses: 25
    CGameCtnMediaClipPlayer * field_0xa4; // accesses: 26
    int field_0xa8; // accesses: 4
    int field_0xac; // accesses: 2
    CGameRace * field_0xb0; // accesses: 10
    undefined4 field_0xb4; // accesses: 6
    byte _padding_0xb8[184];
    CMwNod * field_0x170; // accesses: 1
    CMwNod * field_0x174; // accesses: 1
    byte _padding_0x178[8];
    CGameCtnMediaClipPlayer * field_0x180; // accesses: 5
    byte _padding_0x184[180];
    CGamePlayer * field_0x238; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall MediaClipStart(CGameRace *this,CGameRace *param_1,CGameCtnMediaClip *param_2,int param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall VirtualParam_Get (CGameRace *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall MediaClipStartCutScene (CGameRace *this,CGameRace *param_1,EChallengeCutScene param_2,float param_3,int param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SwitchFromRace(CGameRace *this,CGameRace *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SwitchToRace(CGameRace *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3);
    CGamePlayer * __thiscall GetLocalPlayer(CGameRace *this,CGameRace *param_1);
    CGamePlayer * __thiscall SpectatorGetTargetPlayer(CGameRace *this,CGameRace *param_1);
    CGamePlayerInfo * __thiscall GetLocalPlayerInfo(CGameRace *this,CGameRace *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CGameRace *this,CFuncSegment *param_1);
    int __thiscall LoadPreset(CGameRace *this,CGameRace *param_1,ulong param_2,GmCamFreeVal *param_3);
    int __thiscall MediaClipIsPlaying(CGameRace *this,CGameRace *param_1);
    int __thiscall MediaClipIsPlayingGlobal(CGameRace *this,CGameRace *param_1);
    int __thiscall MediaClipIsPlayingIntro(CGameRace *this,CGameRace *param_1);
    int __thiscall MwIsKindOf(CGameRace *this,CMwCmdAffectParam *param_1,ulong param_2);
    int __thiscall NetPlayerIsPlaying(CGameRace *this,CGameRace *param_1,CGamePlayerInfo *param_2);
    ulong __thiscall FindSpecPlayerInfoFromPlayerInfo (CGameRace *this,CGameRace *param_1,CGamePlayerInfo *param_2);
    ulong __thiscall FindSpecPlayerInfoFromUid(CGameRace *this,CGameRace *param_1,uchar param_2);
    ulong __thiscall GetChunkInfo(CGameRace *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CGameRace *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex(CGameRace *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall VirtualParam_Set(CGameRace *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    void * __thiscall _scalar_deleting_destructor_(CGameRace *this,CPfmHeap *param_1,uint param_2);
    void __thiscall ApplyProfileInputSettings(CGameRace *this,CGameRace *param_1);
    void __thiscall CGameRace(CGameRace *this,CGameRace *param_1);
    void __thiscall Chunk(CGameRace *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall Clean(CGameRace *this,CHmsOcclusion *param_1);
    void __thiscall Init(CGameRace *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
    void __thiscall MediaClipCheckInGameTriggers (CGameRace *this,CGameRace *param_1,CGamePlayer *param_2,CGameCtnMediaClipGroup *param_3);
    void __thiscall MediaClipStartGlobal(CGameRace *this,CGameRace *param_1);
    void __thiscall MediaClipStop(CGameRace *this,CGameRace *param_1);
    void __thiscall MediaClipStopGlobal(CGameRace *this,CGameRace *param_1);
    void __thiscall OnLocalPlayerSpectatorChange(CGameRace *this,CGameRace *param_1);
    void __thiscall SavePreset(CGameRace *this,CGameRace *param_1,ulong param_2,GmCamFreeVal *param_3);
    void __thiscall SetReplayRecord(CGameRace *this,CGameRace *param_1,CGameCtnReplayRecord *param_2);
    void __thiscall SetStatus(CGameRace *this,CGameRace *param_1,EStatus param_2);
    void __thiscall SpectatorMode_Set (CGameRace *this,CGameRace *param_1,CGamePlayerInfo *param_2,ESpectatorCameraType param_3);
    void __thiscall SpectatorSetCameraTarget (CGameRace *this,CGameRace *param_1,ESpectatorCameraTarget param_2);
    void __thiscall SpectatorSetCameraType(CGameRace *this,CGameRace *param_1,ESpectatorCameraType param_2);
    void __thiscall UpdateAsync(CGameRace *this,CInputPortDx8 *param_1);
    void __thiscall ~CGameRace(CGameRace *this,CGameRace *param_1);
};

#endif // CGAMERACE_HPP
