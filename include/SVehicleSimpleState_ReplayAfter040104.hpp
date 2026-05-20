#ifndef SVEHICLESIMPLESTATE_REPLAYAFTER040104_HPP
#define SVEHICLESIMPLESTATE_REPLAYAFTER040104_HPP

#include "typedefs.h"

struct ushort;

struct SVehicleSimpleState_ReplayAfter040104 {
    void** vftable; // accesses: 4
    ushort field_0x2; // accesses: 1
    ushort field_0x4; // accesses: 4
    byte field_0x6; // accesses: 1
    byte field_0x7; // accesses: 1
    byte field_0x8; // accesses: 3
    byte field_0x9; // accesses: 1
    byte field_0xa; // accesses: 1
    byte field_0xb; // accesses: 1
    byte field_0xc; // accesses: 3
    byte field_0xd; // accesses: 1
    byte field_0xe; // accesses: 1
    byte field_0xf; // accesses: 1
    byte field_0x10; // accesses: 3
    byte field_0x11; // accesses: 1
    byte field_0x12; // accesses: 1
    byte field_0x13; // accesses: 1
    uint field_0x14; // accesses: 16
    byte field_0x16; // accesses: 1
    byte _padding_0x17[1];
    byte field_0x18; // accesses: 4
    byte field_0x19; // accesses: 1
    byte field_0x1a; // accesses: 1
    byte _padding_0x1b[1];
    uint field_0x1c; // accesses: 2
    byte _padding_0x20[4];
    float field_0x24; // accesses: 1
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 1
    byte _padding_0x30[52];
    uint field_0x64; // accesses: 4
    uint field_0x68; // accesses: 3
    byte _padding_0x6c[20];
    float field_0x80; // accesses: 4
    byte _padding_0x84[4];
    uint field_0x88; // accesses: 2
    uint field_0x8c; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RestoreFromStruct (void *this,SVehicleSimpleState_ReplayAfter040104 *param_1,SVehicleCarState *param_2, SState *param_3,SState *param_4,SState *param_5,SState *param_6);
};

#endif // SVEHICLESIMPLESTATE_REPLAYAFTER040104_HPP
