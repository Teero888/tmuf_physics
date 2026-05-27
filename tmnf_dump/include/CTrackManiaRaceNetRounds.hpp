#ifndef CTRACKMANIARACENETROUNDS_HPP
#define CTRACKMANIARACENETROUNDS_HPP

#include "typedefs.h"

struct CTrackManiaRaceNetRounds {
    void** vftable;
    byte _padding_0x4[1668];
    undefined4 field_0x688; // accesses: 1
    byte _final_padding[0x4]; // Total size: 0x690

    // Member Functions
    void __thiscall SwitchToRace (CTrackManiaRaceNetRounds *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3);
    void __thiscall UpdateAsync(CTrackManiaRaceNetRounds *this,CInputPortDx8 *param_1);
};

#endif // CTRACKMANIARACENETROUNDS_HPP
