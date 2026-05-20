#ifndef CTRACKMANIARACENETTIMEATTACK_HPP
#define CTRACKMANIARACENETTIMEATTACK_HPP

#include "typedefs.h"

struct CPlugAudio;
struct CTrackManiaRaceInterface;

struct CTrackManiaRaceNetTimeAttack {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[472];
    undefined4 field_0x1f0; // accesses: 3
    byte _padding_0x1f4[804];
    CTrackManiaRaceInterface * field_0x518; // accesses: 2

    // Member Functions
    void __thiscall UpdateAsync(CTrackManiaRaceNetTimeAttack *this,CInputPortDx8 *param_1);
};

#endif // CTRACKMANIARACENETTIMEATTACK_HPP
