#ifndef CTRACKMANIARACETRIGGERABSORBCONTACT_HPP
#define CTRACKMANIARACETRIGGERABSORBCONTACT_HPP

#include "typedefs.h"

struct CTrackManiaRace;

struct CTrackManiaRaceTriggerAbsorbContact {
    void** vftable; // accesses: 1
    CTrackManiaRace * field_0x4; // accesses: 8

    // Member Functions
    void __thiscall AbsorbContact (CTrackManiaRaceTriggerAbsorbContact *this,CSceneMobilAbsorbContact *param_1, CHmsItem *param_2,CHmsPhysicalContact *param_3);
    void __thiscall CTrackManiaRaceTriggerAbsorbContact (CTrackManiaRaceTriggerAbsorbContact *this,CTrackManiaRaceTriggerAbsorbContact *param_1, CTrackManiaRace *param_2);
};

#endif // CTRACKMANIARACETRIGGERABSORBCONTACT_HPP
