#ifndef CGAMECTNMEDIACLIPPLAYER_HPP
#define CGAMECTNMEDIACLIPPLAYER_HPP

#include "typedefs.h"

struct CGameControlCameraMaster;
struct CGameCtnMediaClip;
struct CGameCtnMediaClipViewer;
struct CGameScene;
struct CMwCmd;
struct CMwNod;
struct CScene2d;
struct ulong;

struct CGameCtnMediaClipPlayer {
    void** vftable; // accesses: 4
    byte _padding_0x4[16];
    CGameCtnMediaClipPlayer * field_0x14; // accesses: 17
    CGameCtnMediaClipViewer * field_0x18; // accesses: 19
    CGameControlCameraMaster * field_0x1c; // accesses: 12
    CGameCtnMediaClipPlayer * field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 4
    undefined4 field_0x28; // accesses: 4
    undefined4 field_0x2c; // accesses: 4
    CMwNod * field_0x30; // accesses: 11
    undefined4 field_0x34; // accesses: 4
    CGameCtnMediaClipPlayer * field_0x38; // accesses: 2
    CMwNod * field_0x3c; // accesses: 2
    CGameCtnMediaClipPlayer * field_0x40; // accesses: 4
    undefined4 field_0x44; // accesses: 2
    CMwNod * field_0x48; // accesses: 10
    CGameCtnMediaClipPlayer * field_0x4c; // accesses: 3
    undefined4 field_0x50; // accesses: 2
    CMwNod * field_0x54; // accesses: 19
    undefined4 field_0x58; // accesses: 1
    ulong field_0x5c; // accesses: 8
    CMwNod * field_0x60; // accesses: 12
    byte _padding_0x64[12];
    undefined4 field_0x70; // accesses: 2
    CGameCtnMediaClipViewer * field_0x74; // accesses: 2
    undefined4 field_0x78; // accesses: 1
    CGameCtnMediaClipPlayer * field_0x7c; // accesses: 2
    byte _padding_0x80[60];
    undefined4 field_0xbc; // accesses: 2
    byte _padding_0xc0[96];
    undefined4 field_0x120; // accesses: 2
    float field_0x124; // accesses: 1
    float field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CGameCtnMediaClipPlayer (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall EndClipTimeSetFromClip (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1);
    CGameMobil * __thiscall LocalPlayerGameMobilGet (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1);
    SGameCamVal * __thiscall GetCamValDefined (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1);
    float __thiscall ClipTimeGet(CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1);
    int __thiscall IsPlaying(CGameCtnMediaClipPlayer *this,COalAudioSound *param_1);
    ulong __thiscall GhostIdToGameMobilId (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,ulong param_2);
    void __cdecl InternalUpdateBlocks (float param_1,float param_2,CFastBuffer<class_CGameCtnMediaBlock*> *param_3);
    void __cdecl InternalUpdateBlocksGhosts (float param_1,float param_2,float param_3,CFastBuffer<class_CGameCtnMediaBlock*> *param_4 );
    void __thiscall CacheUpdate(CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1);
    void __thiscall ClipPreClean (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,CGameCtnMediaClip *param_2 );
    void __thiscall ClipPreload (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,CGameCtnMediaClip *param_2 );
    void __thiscall ClipSet (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,CGameCtnMediaClip *param_2 );
    void __thiscall ClipTimeSet (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,float param_2);
    void __thiscall CompatConvertOldCameraBlocks (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1);
    void __thiscall ContextSet (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipViewer *param_1, CGameCtnMediaContext *param_2);
    void __thiscall Create(CGameCtnMediaClipPlayer *this,CDx9VertexBuffer *param_1);
    void __thiscall Destroy(CGameCtnMediaClipPlayer *this,CGameAdvertisingNadeo *param_1);
    void __thiscall DrawRectSet (CGameCtnMediaClipPlayer *this,CControlField2 *param_1,GmRectAligned *param_2);
    void __thiscall EndClipCallBackSet (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,CMwNod *param_2, _func___cdecl_void *param_3);
    void __thiscall InternalBlockInstall (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1, CGameCtnMediaBlock *param_2);
    void __thiscall InternalBlockUninstall (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1, CGameCtnMediaBlock *param_2);
    void __thiscall LocalPlayerGameMobilIdSet (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,ulong param_2);
    void __thiscall LocalPlayerGhostSet (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,CGameCtnGhost *param_2);
    void __thiscall Play (CGameCtnMediaClipPlayer *this,CPlugFileVideo *param_1,EPlugVideoTimer param_2,int param_3 ,ulong param_4);
    void __thiscall PrioritySet (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,ulong param_2);
    void __thiscall Stop(CGameCtnMediaClipPlayer *this,STmRaceLowFps *param_1);
    void __thiscall TracksUpdate (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,float param_2, float param_3);
    void __thiscall UpdateTracksCmd (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1);
};

#endif // CGAMECTNMEDIACLIPPLAYER_HPP
