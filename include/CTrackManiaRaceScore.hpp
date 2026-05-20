#ifndef CTRACKMANIARACESCORE_HPP
#define CTRACKMANIARACESCORE_HPP

#include "typedefs.h"

struct CMwNod;
struct CTrackManiaPlayerInfo;

struct CTrackManiaRaceScore {
    void** vftable; // accesses: 1
    byte _final_padding[0x8]; // Total size: 0xc

    // Member Functions
    int __thiscall IsNullScore(CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1);
    int __thiscall IsPureSpectator(CTrackManiaRaceScore *this,CTrackManiaPlayerInfo *param_1);
    uchar __thiscall GetPlayerUid(CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1);
    void __thiscall CTrackManiaRaceScore(CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1);
    void __thiscall InitScores (CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1,CTrackManiaPlayerInfo *param_2, int param_3);
};

#endif // CTRACKMANIARACESCORE_HPP
