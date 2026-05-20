#ifndef CTRACKMANIARACENETROUNDS_HPP
#define CTRACKMANIARACENETROUNDS_HPP

#include "typedefs.h"

struct CPlugAudio;

struct CTrackManiaRaceNetRounds {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[1648];
    undefined4 field_0x688; // accesses: 1

    // Member Functions
    void __thiscall SwitchToRace (CTrackManiaRaceNetRounds *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3);
    void __thiscall UpdateAsync(CTrackManiaRaceNetRounds *this,CInputPortDx8 *param_1);
};

#endif // CTRACKMANIARACENETROUNDS_HPP
