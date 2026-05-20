#ifndef CTRACKMANIARACETRIGGERABSORBCONTACT_HPP
#define CTRACKMANIARACETRIGGERABSORBCONTACT_HPP

#include "typedefs.h"

struct CTrackManiaRace;

struct CTrackManiaRaceTriggerAbsorbContact {
    byte _padding_0x0[4];
    CTrackManiaRace * field_0x4; // accesses: 8
    byte _padding_0x8[56];
    int field_0x40; // accesses: 2

    // Member Functions
    void __thiscall AbsorbContact (CTrackManiaRaceTriggerAbsorbContact *this,CSceneMobilAbsorbContact *param_1, CHmsItem *param_2,CHmsPhysicalContact *param_3);
    void __thiscall CTrackManiaRaceTriggerAbsorbContact (CTrackManiaRaceTriggerAbsorbContact *this,CTrackManiaRaceTriggerAbsorbContact *param_1, CTrackManiaRace *param_2);
};

#endif // CTRACKMANIARACETRIGGERABSORBCONTACT_HPP
