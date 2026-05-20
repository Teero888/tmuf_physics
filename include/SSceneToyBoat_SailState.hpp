#ifndef SSCENETOYBOAT_SAILSTATE_HPP
#define SSCENETOYBOAT_SAILSTATE_HPP

#include "typedefs.h"

struct SSceneToyBoat_SailState {
    SSceneToyBoat_SailState * field_0x0; // accesses: 1
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    SSceneToyBoat_SailState * field_0x10; // accesses: 1
    SSceneToyBoat_SailState * field_0x14; // accesses: 1

    // Member Functions
    void __thiscall SetFromSail (void *this,SSceneToyBoat_SailState *param_1,ESailType param_2,CBoatSailState *param_3);
};

#endif // SSCENETOYBOAT_SAILSTATE_HPP
