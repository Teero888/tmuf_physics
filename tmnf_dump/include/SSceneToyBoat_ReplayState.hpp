#ifndef SSCENETOYBOAT_REPLAYSTATE_HPP
#define SSCENETOYBOAT_REPLAYSTATE_HPP

#include "typedefs.h"

struct SSceneToyBoat_ReplayState {
    byte _padding_0x0[120];
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1

    // Member Functions
    void __thiscall SetFromBoat (void *this,SSceneToyBoat_NetState *param_1,CSceneToyBoat *param_2);
};

#endif // SSCENETOYBOAT_REPLAYSTATE_HPP
