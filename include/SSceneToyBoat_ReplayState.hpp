#ifndef SSCENETOYBOAT_REPLAYSTATE_HPP
#define SSCENETOYBOAT_REPLAYSTATE_HPP

#include "typedefs.h"

struct SSceneToyBoat_ReplayState {
    byte _padding_0x0[40];
    int field_0x28; // accesses: 1
    byte _padding_0x2c[92];
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    byte _padding_0x90[40];
    undefined4 field_0xb8; // accesses: 1
    undefined4 field_0xbc; // accesses: 1
    byte _padding_0xc0[28];
    undefined4 field_0xdc; // accesses: 1

    // Member Functions
    void __thiscall SetFromBoat (void *this,SSceneToyBoat_NetState *param_1,CSceneToyBoat *param_2);
};

#endif // SSCENETOYBOAT_REPLAYSTATE_HPP
