#ifndef CTRACKMANIACONTROLSCORES2_HPP
#define CTRACKMANIACONTROLSCORES2_HPP

#include "typedefs.h"

struct CControlBase;
struct CFastString;

struct CTrackManiaControlScores2 {
    void** vftable; // accesses: 1
    byte _padding_0x4[408];
    CFastString * field_0x19c; // accesses: 1
    undefined * field_0x1a0; // accesses: 1
    byte _padding_0x1a4[28];
    CTrackManiaControlScores2 * field_0x1c0; // accesses: 2
    int field_0x1c4; // accesses: 1
    int field_0x1c8; // accesses: 1
    byte _padding_0x1cc[24];
    int field_0x1e4; // accesses: 4
    CControlBase * field_0x1e8; // accesses: 2
    CControlBase * field_0x1ec; // accesses: 2
    byte _padding_0x1f0[4];
    CControlBase * field_0x1f4; // accesses: 1
    byte _padding_0x1f8[4];
    CControlBase * field_0x1fc; // accesses: 1
    byte _padding_0x200[20];
    int field_0x214; // accesses: 5
    int field_0x218; // accesses: 4
    uint field_0x21c; // accesses: 4
    int field_0x220; // accesses: 1
    undefined4 field_0x224; // accesses: 3

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
