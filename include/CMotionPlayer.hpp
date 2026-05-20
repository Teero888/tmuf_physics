#ifndef CMOTIONPLAYER_HPP
#define CMOTIONPLAYER_HPP

#include "typedefs.h"

struct CMotionTrackTree;
struct CMwCmd;
struct CMwNod;
struct CTrackManiaEditorIcon;

struct CMotionPlayer {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    int * field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 1
    ulong field_0x28; // accesses: 6
    undefined4 field_0x2c; // accesses: 1
    CMwNod * field_0x30; // accesses: 8
    CMwCmd * field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 1
    byte _padding_0x3c[12];
    int field_0x48; // accesses: 2
    undefined4 field_0x4c; // accesses: 1

    // Member Functions
    int __thiscall IsPlaying(CMotionPlayer *this,COalAudioSound *param_1);
    ulong __thiscall AddTrack(CMotionPlayer *this,CMotionPlayer *param_1,CMotionTrack *param_2);
    void __thiscall CMotionPlayer(CMotionPlayer *this,CMotionPlayer *param_1);
    void __thiscall ConnectTrack(CMotionPlayer *this,CMotionPlayer *param_1,CMotionTrack *param_2);
    void __thiscall SetIsPhysics(CMotionPlayer *this,CMotionTrackTree *param_1,int param_2);
    void __thiscall UpdateTimeBaseParams(CMotionPlayer *this,CMotionPlayer *param_1);
};

#endif // CMOTIONPLAYER_HPP
