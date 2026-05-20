#ifndef CGAMECTNMEDIATRACKER_HPP
#define CGAMECTNMEDIATRACKER_HPP

#include "typedefs.h"

struct CControlSimi2;
struct CControlTimeLine2;
struct CGameControlCamera;
struct CGameCtnChallenge;
struct CGameCtnCursor;
struct CGameCtnMediaClip;
struct CGameCtnMediaClipPlayer;
struct CGameSafeFrame;

struct CGameCtnMediaTracker {
    byte _padding_0x0[32];
    CGameCtnChallenge * field_0x20; // accesses: 2
    byte _padding_0x24[8];
    int field_0x2c; // accesses: 1
    byte _padding_0x30[112];
    CGameSafeFrame * field_0xa0; // accesses: 4
    byte _padding_0xa4[8];
    CGameCtnMediaClip * field_0xac; // accesses: 1
    byte _padding_0xb0[4];
    CGameCtnMediaClipPlayer * field_0xb4; // accesses: 16
    byte _padding_0xb8[20];
    CControlTimeLine2 * field_0xcc; // accesses: 9
    byte _padding_0xd0[12];
    int field_0xdc; // accesses: 1
    byte _padding_0xe0[28];
    undefined4 field_0xfc; // accesses: 2
    byte _padding_0x100[24];
    undefined4 field_0x118; // accesses: 2
    int field_0x11c; // accesses: 7
    int * field_0x120; // accesses: 2
    byte _padding_0x124[108];
    undefined4 field_0x190; // accesses: 10
    int field_0x194; // accesses: 1
    int field_0x198; // accesses: 5
    byte _padding_0x19c[116];
    undefined4 field_0x210; // accesses: 2
    byte _padding_0x214[20];
    CControlSimi2 * field_0x228; // accesses: 3
    byte _padding_0x22c[92];
    int * field_0x288; // accesses: 7
    int * field_0x28c; // accesses: 3
    byte _padding_0x290[96];
    int * field_0x2f0; // accesses: 3
    byte _padding_0x2f4[212];
    int field_0x3c8; // accesses: 1
    byte _padding_0x3cc[32];
    undefined4 field_0x3ec; // accesses: 1
    byte _padding_0x3f0[92];
    int field_0x44c; // accesses: 4
    int * field_0x450; // accesses: 4

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateAsync(CGameCtnMediaTracker *this,CInputPortDx8 *param_1);
    CFastBufferRef<class_CGameCtnMediaTrack> * __thiscall GetTracks(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlock * __thiscall GetSelBlock(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlock3dStereo * __thiscall GetSelBlock<class_CGameCtnMediaBlock3dStereo> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockCameraCustom * __thiscall GetSelBlock<class_CGameCtnMediaBlockCameraCustom> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockCameraEffectShake * __thiscall GetSelBlock<class_CGameCtnMediaBlockCameraEffectShake> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockCameraPath * __thiscall GetSelBlock<class_CGameCtnMediaBlockCameraPath> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockFxBloom * __thiscall GetSelBlock<class_CGameCtnMediaBlockFxBloom> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockFxBlurDepth * __thiscall GetSelBlock<class_CGameCtnMediaBlockFxBlurDepth> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockFxColors * __thiscall GetSelBlock<class_CGameCtnMediaBlockFxColors> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockImage * __thiscall GetSelBlock<class_CGameCtnMediaBlockImage> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockMusicEffect * __thiscall GetSelBlock<class_CGameCtnMediaBlockMusicEffect> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockSound * __thiscall GetSelBlock<class_CGameCtnMediaBlockSound> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockText * __thiscall GetSelBlock<class_CGameCtnMediaBlockText> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockTime * __thiscall GetSelBlock<class_CGameCtnMediaBlockTime> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaBlockTransitionFade * __thiscall GetSelBlock<class_CGameCtnMediaBlockTransitionFade> (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaClip * __thiscall ClipGet(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    CGameCtnMediaTrack * __thiscall GetSelTrack(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    SBlockEditInfo * __thiscall FindBlockEditInfoFromClassId (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1,ulong param_2);
    int __thiscall IsBlockingMode(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    void __thiscall ButFrameKeyAdvanced(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
    void __thiscall UpdateControlsState_FrameBlockFxBlurDepth (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1);
};

#endif // CGAMECTNMEDIATRACKER_HPP
