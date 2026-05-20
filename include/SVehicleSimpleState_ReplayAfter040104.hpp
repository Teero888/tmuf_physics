#ifndef SVEHICLESIMPLESTATE_REPLAYAFTER040104_HPP
#define SVEHICLESIMPLESTATE_REPLAYAFTER040104_HPP

#include "typedefs.h"

struct SVehicleSimpleState_ReplayAfter040104 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 5
    undefined4 field_0x8; // accesses: 5
    ushort field_0xc; // accesses: 5
    byte _padding_0xe[2];
    uint field_0x10; // accesses: 5
    uint field_0x14; // accesses: 5
    float field_0x18; // accesses: 1
    uint field_0x1c; // accesses: 1
    byte _padding_0x20[68];
    uint field_0x64; // accesses: 1
    uint field_0x68; // accesses: 1
    byte _padding_0x6c[20];
    float field_0x80; // accesses: 1
    byte _padding_0x84[4];
    uint field_0x88; // accesses: 1
    uint field_0x8c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RestoreFromStruct (void *this,SVehicleSimpleState_ReplayAfter040104 *param_1,SVehicleCarState *param_2, SState *param_3,SState *param_4,SState *param_5,SState *param_6);
};

#endif // SVEHICLESIMPLESTATE_REPLAYAFTER040104_HPP
