#ifndef SSCENETOYBOAT_NETSTATE_HPP
#define SSCENETOYBOAT_NETSTATE_HPP

#include "typedefs.h"

struct CSceneToyBoat;

struct SSceneToyBoat_NetState {
    CSceneToyBoat * field_0x0; // accesses: 3
    byte _padding_0x4[8];
    float field_0xc; // accesses: 1
    byte _padding_0x10[20];
    float field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    float field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    float field_0x34; // accesses: 3
    CSceneToyBoat * field_0x38; // accesses: 4
    undefined4 field_0x3c; // accesses: 2
    CSceneToyBoat * field_0x40; // accesses: 2
    CSceneToyBoat * field_0x44; // accesses: 3
    CSceneToyBoat * field_0x48; // accesses: 3

    // Member Functions
    void __thiscall ApplyExtrapolatedStateToBoat (void *this,SSceneToyBoat_NetState *param_1,CSceneToyBoat *param_2,ulong param_3);
    void __thiscall RestoreFromBuffer (void *this,SSceneToyBoat_NetState *param_1,CClassicBufferMemory *param_2,ulong param_3);
};

#endif // SSCENETOYBOAT_NETSTATE_HPP
