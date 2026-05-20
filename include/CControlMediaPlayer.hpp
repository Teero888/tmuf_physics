#ifndef CCONTROLMEDIAPLAYER_HPP
#define CCONTROLMEDIAPLAYER_HPP

#include "typedefs.h"

struct CAudioPort;
struct CAudioSound;
struct CControlButton;
struct CMwNod;

struct CControlMediaPlayer {
    byte _padding_0x0[24];
    CMwNod * field_0x18; // accesses: 4
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
    undefined4 field_0x28; // accesses: 2
    byte _padding_0x2c[16];
    undefined4 field_0x3c; // accesses: 1
    byte _padding_0x40[4];
    CMwCmdAffectParamBool * field_0x44; // accesses: 1
    byte _padding_0x48[40];
    CControlMediaPlayer * field_0x70; // accesses: 4
    byte _padding_0x74[32];
    undefined4 field_0x94; // accesses: 2
    undefined4 field_0x98; // accesses: 2
    undefined4 field_0x9c; // accesses: 2
    float field_0xa0; // accesses: 2
    float field_0xa4; // accesses: 2
    undefined4 field_0xa8; // accesses: 2
    byte _padding_0xac[96];
    undefined4 field_0x10c; // accesses: 1
    byte _padding_0x110[8];
    int field_0x118; // accesses: 2
    byte _padding_0x11c[68];
    undefined4 field_0x160; // accesses: 1
    undefined4 field_0x164; // accesses: 1
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 1
    undefined4 field_0x170; // accesses: 1
    int field_0x174; // accesses: 3
    float field_0x178; // accesses: 1
    float field_0x17c; // accesses: 1
    undefined4 field_0x180; // accesses: 2
    undefined4 field_0x184; // accesses: 2
    int field_0x188; // accesses: 7
    CControlMediaPlayer * field_0x18c; // accesses: 12
    undefined4 field_0x190; // accesses: 5
    CAudioPort * field_0x194; // accesses: 8
    int field_0x198; // accesses: 2
    undefined4 field_0x19c; // accesses: 5
    int field_0x1a0; // accesses: 5
    CMwNod * field_0x1a4; // accesses: 36
    CMwNod * field_0x1a8; // accesses: 27

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CreateMediaButton(CControlMediaPlayer *this,CControlMediaPlayer *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall MediaPlay(CControlMediaPlayer *this,CControlMediaPlayer *param_1);
    void __thiscall CControlMediaPlayer(CControlMediaPlayer *this,CControlMediaPlayer *param_1);
    void __thiscall MediaStop(CControlMediaPlayer *this,CControlMediaPlayer *param_1);
    void __thiscall SetMediaData (CControlMediaPlayer *this,CControlMediaPlayer *param_1,CSystemData *param_2);
    void __thiscall SetMediaFileFid (CControlMediaPlayer *this,CControlMediaPlayer *param_1,CSystemFid *param_2);
};

#endif // CCONTROLMEDIAPLAYER_HPP
