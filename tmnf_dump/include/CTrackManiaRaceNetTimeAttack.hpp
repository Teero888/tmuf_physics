#ifndef CTRACKMANIARACENETTIMEATTACK_HPP
#define CTRACKMANIARACENETTIMEATTACK_HPP

#include "typedefs.h"

struct CTrackManiaRaceInterface;

struct CTrackManiaRaceNetTimeAttack {
    void** vftable;
    byte _padding_0x4[492];
    uint field_0x1f0; // accesses: 3
    byte _padding_0x1f4[804];
    CTrackManiaRaceInterface * field_0x518; // accesses: 2
    byte _final_padding[0x174]; // Total size: 0x690

    // Member Functions
    void __thiscall UpdateAsync(CTrackManiaRaceNetTimeAttack *this,CInputPortDx8 *param_1);
};

#endif // CTRACKMANIARACENETTIMEATTACK_HPP
