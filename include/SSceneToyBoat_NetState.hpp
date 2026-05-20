#ifndef SSCENETOYBOAT_NETSTATE_HPP
#define SSCENETOYBOAT_NETSTATE_HPP

#include "typedefs.h"

struct CPlugAudio;
struct CSceneToyBoat;
struct GmVec3;

struct SSceneToyBoat_NetState {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
    byte _padding_0x8[8];
    float field_0x10; // accesses: 1
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[4];
    CSceneToyBoat * field_0x1c; // accesses: 1
    byte _padding_0x20[8];
    int field_0x28; // accesses: 1
    byte _padding_0x2c[140];
    GmVec3 * field_0xb8; // accesses: 1
    GmVec3 * field_0xbc; // accesses: 1
    byte _padding_0xc0[28];
    undefined4 field_0xdc; // accesses: 1
    byte _padding_0xe0[44];
    undefined4 field_0x10c; // accesses: 1
    byte _padding_0x110[8];
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 1
    byte _padding_0x120[224];
    undefined4 field_0x200; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ApplyExtrapolatedStateToBoat (void *this,SSceneToyBoat_NetState *param_1,CSceneToyBoat *param_2,ulong param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RestoreFromBuffer (void *this,SSceneToyBoat_NetState *param_1,CClassicBufferMemory *param_2,ulong param_3);
};

#endif // SSCENETOYBOAT_NETSTATE_HPP
