#ifndef CGAMERACE_HPP
#define CGAMERACE_HPP

#include "typedefs.h"

struct CGameApp;
struct CGameCtnApp;
struct CGameCtnMediaClipPlayer;
struct CGamePlayerCameraSet;
struct CGameScene;
struct CMwNod;

struct CGameRace {
    struct SCameraPreset {
        void** vftable; // accesses: 1

        // Member Functions
        void __thiscall SCameraPreset(void *this,SCameraPreset *param_1);
    };

    struct CMwNod;

    struct SPlayerInfosForTargetting {
        void** vftable; // accesses: 3

        // Member Functions
        void __thiscall SPlayerInfosForTargetting (void *this,SPlayerInfosForTargetting *param_1);
        void __thiscall ~SPlayerInfosForTargetting (void *this,SPlayerInfosForTargetting *param_1);
    };

    void** vftable; // accesses: 21
    byte _final_padding[0x6]; // Total size: 0xa

    // Member Functions
    CGamePlayer * __thiscall GetLocalPlayer(CGameRace *this,CGameRace *param_1);
    CGamePlayer * __thiscall SpectatorGetTargetPlayer(CGameRace *this,CGameRace *param_1);
    CGamePlayerInfo * __thiscall GetLocalPlayerInfo(CGameRace *this,CGameRace *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CGameRace *this,CFuncSegment *param_1);
    int __thiscall LoadPreset(CGameRace *this,CGameRace *param_1,ulong param_2,GmCamFreeVal *param_3);
    int __thiscall MediaClipIsPlaying(CGameRace *this,CGameRace *param_1);
    int __thiscall MediaClipIsPlayingGlobal(CGameRace *this,CGameRace *param_1);
    int __thiscall MediaClipIsPlayingIntro(CGameRace *this,CGameRace *param_1);
    int __thiscall MediaClipStart(CGameRace *this,CGameRace *param_1,CGameCtnMediaClip *param_2,int param_3);
    int __thiscall MwIsKindOf(CGameRace *this,CMwCmdAffectParam *param_1,ulong param_2);
    int __thiscall NetPlayerIsPlaying(CGameRace *this,CGameRace *param_1,CGamePlayerInfo *param_2);
    ulong __thiscall FindSpecPlayerInfoFromPlayerInfo (CGameRace *this,CGameRace *param_1,CGamePlayerInfo *param_2);
    ulong __thiscall FindSpecPlayerInfoFromUid(CGameRace *this,CGameRace *param_1,uchar param_2);
    ulong __thiscall GetChunkInfo(CGameRace *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CGameRace *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex(CGameRace *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall VirtualParam_Get (CGameRace *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    ulong __thiscall VirtualParam_Set(CGameRace *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    void * __thiscall _scalar_deleting_destructor_(CGameRace *this,CPfmHeap *param_1,uint param_2);
    void __thiscall ApplyProfileInputSettings(CGameRace *this,CGameRace *param_1);
    void __thiscall CGameRace(CGameRace *this,CGameRace *param_1);
    void __thiscall Chunk(CGameRace *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall Clean(CGameRace *this,CHmsOcclusion *param_1);
    void __thiscall Init(CGameRace *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
    void __thiscall MediaClipCheckInGameTriggers (CGameRace *this,CGameRace *param_1,CGamePlayer *param_2,CGameCtnMediaClipGroup *param_3);
    void __thiscall MediaClipStartCutScene (CGameRace *this,CGameRace *param_1,EChallengeCutScene param_2,float param_3,int param_4);
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
    void __thiscall SwitchFromRace(CGameRace *this,CGameRace *param_1);
    void __thiscall SwitchToRace(CGameRace *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3);
    void __thiscall UpdateAsync(CGameRace *this,CInputPortDx8 *param_1);
    void __thiscall ~CGameRace(CGameRace *this,CGameRace *param_1);
};

#endif // CGAMERACE_HPP
