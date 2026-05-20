#ifndef SSCENETOYBOAT_NETSTATE_HPP
#define SSCENETOYBOAT_NETSTATE_HPP

#include "typedefs.h"

struct CSceneToyBoat;

struct SSceneToyBoat_NetState {
    void** vftable; // accesses: 3
    byte _padding_0x4[8];
    float field_0xc; // accesses: 1
    byte _padding_0x10[20];
    float field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 2
    float field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    float field_0x34; // accesses: 3
    float field_0x38; // accesses: 4
    float field_0x3c; // accesses: 2
    float field_0x40; // accesses: 2
    uint field_0x44; // accesses: 3
    uint field_0x48; // accesses: 3
    byte _padding_0x4c[60];
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    byte _padding_0x90[40];
    undefined4 field_0xb8; // accesses: 1
    undefined4 field_0xbc; // accesses: 1
    byte _padding_0xc0[28];
    undefined4 field_0xdc; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ApplyExtrapolatedStateToBoat (void *this,SSceneToyBoat_NetState *param_1,CSceneToyBoat *param_2,ulong param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RestoreFromBuffer (void *this,SSceneToyBoat_NetState *param_1,CClassicBufferMemory *param_2,ulong param_3);
};

#endif // SSCENETOYBOAT_NETSTATE_HPP
