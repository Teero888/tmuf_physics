#ifndef CTRACKMANIARACENETROUNDS_HPP
#define CTRACKMANIARACENETROUNDS_HPP

#include "typedefs.h"

struct CTrackManiaRaceNetRounds {
    byte _padding_0x0[1672];
    undefined4 field_0x688; // accesses: 1

    // Member Functions
    void __thiscall SwitchToRace (CTrackManiaRaceNetRounds *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3);
    void __thiscall UpdateAsync(CTrackManiaRaceNetRounds *this,CInputPortDx8 *param_1);
};

#endif // CTRACKMANIARACENETROUNDS_HPP
