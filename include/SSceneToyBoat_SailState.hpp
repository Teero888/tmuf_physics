#ifndef SSCENETOYBOAT_SAILSTATE_HPP
#define SSCENETOYBOAT_SAILSTATE_HPP

#include "typedefs.h"

struct SSceneToyBoat_SailState {
    byte _padding_0x0[132];
    SSceneToyBoat_SailState * field_0x84; // accesses: 1
    SSceneToyBoat_SailState * field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    byte _padding_0x94[4];
    undefined4 field_0x98; // accesses: 1

    // Member Functions
    void __thiscall SetFromSail (void *this,SSceneToyBoat_SailState *param_1,ESailType param_2,CBoatSailState *param_3);
};

#endif // SSCENETOYBOAT_SAILSTATE_HPP
