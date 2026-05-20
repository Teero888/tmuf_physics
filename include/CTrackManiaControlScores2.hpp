#ifndef CTRACKMANIACONTROLSCORES2_HPP
#define CTRACKMANIACONTROLSCORES2_HPP

#include "typedefs.h"

struct CControlBase;
struct CControlLabel;
struct CFastString;
struct CFastStringInt;
struct CMwId;
struct CTrackManiaRaceScore;

struct CTrackManiaControlScores2 {
    byte _padding_0x0[4];
    int * field_0x4; // accesses: 14
    byte _padding_0x8[4];
    int * field_0xc; // accesses: 4
    int * field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    CFastString * field_0x24; // accesses: 1
    undefined * field_0x28; // accesses: 6
    undefined4 field_0x2c; // accesses: 2
    int field_0x30; // accesses: 2
    int field_0x34; // accesses: 4
    int field_0x38; // accesses: 2
    CControlBase * field_0x3c; // accesses: 1
    int * field_0x40; // accesses: 5
    CControlBase * field_0x44; // accesses: 1
    CFastStringInt * field_0x48; // accesses: 1
    CControlBase * field_0x4c; // accesses: 1
    CControlBase * field_0x50; // accesses: 1
    int field_0x54; // accesses: 3
    int * field_0x58; // accesses: 4
    CControlBase * field_0x5c; // accesses: 1
    CFastStringInt * field_0x60; // accesses: 2
    int * field_0x64; // accesses: 3
    byte _padding_0x68[216];
    undefined * field_0x140; // accesses: 2
    byte _padding_0x144[36];
    int field_0x168; // accesses: 1
    int field_0x16c; // accesses: 1
    int field_0x170; // accesses: 1
    int field_0x174; // accesses: 1
    int field_0x178; // accesses: 1
    int field_0x17c; // accesses: 1
    int field_0x180; // accesses: 1
    int field_0x184; // accesses: 2
    int field_0x188; // accesses: 2
    int field_0x18c; // accesses: 1
    int field_0x190; // accesses: 1
    byte _padding_0x194[8];
    CFastString * field_0x19c; // accesses: 1
    undefined * field_0x1a0; // accesses: 1
    byte _padding_0x1a4[12];
    ulong field_0x1b0; // accesses: 1
    byte _padding_0x1b4[12];
    int field_0x1c0; // accesses: 5
    int field_0x1c4; // accesses: 1
    int field_0x1c8; // accesses: 1
    byte _padding_0x1cc[16];
    undefined * field_0x1dc; // accesses: 2
    undefined * field_0x1e0; // accesses: 1
    int field_0x1e4; // accesses: 4
    CControlBase * field_0x1e8; // accesses: 2
    CControlBase * field_0x1ec; // accesses: 2
    byte _padding_0x1f0[4];
    CControlBase * field_0x1f4; // accesses: 1
    byte _padding_0x1f8[4];
    CControlBase * field_0x1fc; // accesses: 1
    int field_0x200; // accesses: 10
    byte _padding_0x204[16];
    int field_0x214; // accesses: 7
    int field_0x218; // accesses: 7
    int field_0x21c; // accesses: 8
    int field_0x220; // accesses: 3
    int field_0x224; // accesses: 3
    byte _padding_0x228[12];
    undefined4 field_0x234; // accesses: 1
    byte _padding_0x238[8];
    int field_0x240; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall Update (CTrackManiaControlScores2 *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3);
    int __thiscall FinishShouldBeVisible (CTrackManiaControlScores2 *this,CTrackManiaControlScores2 *param_1, CFastBuffer<class_CTrackManiaRaceScore*> *param_2);
    int __thiscall IsDirty (CTrackManiaControlScores2 *this,CTrackManiaControlScores2 *param_1);
    void __thiscall Clean(CTrackManiaControlScores2 *this,CHmsOcclusion *param_1);
    void __thiscall SetDisplayScoreElseLadderScore (CTrackManiaControlScores2 *this,CTrackManiaControlScores2 *param_1,int param_2);
    void __thiscall SetListTitle (CTrackManiaControlScores2 *this,CTrackManiaControlScores2 *param_1,ulong param_2, CFastStringInt *param_3);
    void __thiscall UpdatePageButtons (CTrackManiaControlScores2 *this,CTrackManiaControlScores2 *param_1);
};

#endif // CTRACKMANIACONTROLSCORES2_HPP
