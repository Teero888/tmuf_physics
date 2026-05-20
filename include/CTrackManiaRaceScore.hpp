#ifndef CTRACKMANIARACESCORE_HPP
#define CTRACKMANIARACESCORE_HPP

#include "typedefs.h"

struct CMwNod;
struct CTrackManiaPlayerInfo;

struct CTrackManiaRaceScore {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    int field_0x14; // accesses: 1
    int field_0x18; // accesses: 1
    int field_0x1c; // accesses: 1
    byte _padding_0x20[44];
    undefined4 field_0x4c; // accesses: 3
    undefined4 field_0x50; // accesses: 2
    CMwNod * field_0x54; // accesses: 7
    undefined4 field_0x58; // accesses: 1

    // Member Functions
    int __thiscall IsNullScore(CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1);
    int __thiscall IsPureSpectator(CTrackManiaRaceScore *this,CTrackManiaPlayerInfo *param_1);
    uchar __thiscall GetPlayerUid(CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1);
    void __thiscall CTrackManiaRaceScore(CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1);
    void __thiscall InitScores (CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1,CTrackManiaPlayerInfo *param_2, int param_3);
};

#endif // CTRACKMANIARACESCORE_HPP
