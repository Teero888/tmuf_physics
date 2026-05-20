#ifndef SVEHICLESIMPLESTATE_REPLAYAFTER040104_HPP
#define SVEHICLESIMPLESTATE_REPLAYAFTER040104_HPP

#include "typedefs.h"

struct SVehicleSimpleState_ReplayAfter040104 {
    ushort field_0x0; // accesses: 1
    ushort field_0x2; // accesses: 1
    ushort field_0x4; // accesses: 1
    byte field_0x6; // accesses: 1
    byte field_0x7; // accesses: 1
    byte field_0x8; // accesses: 1
    byte field_0x9; // accesses: 1
    byte field_0xa; // accesses: 1
    byte field_0xb; // accesses: 1
    byte field_0xc; // accesses: 1
    byte field_0xd; // accesses: 1
    byte field_0xe; // accesses: 1
    byte field_0xf; // accesses: 1
    byte field_0x10; // accesses: 1
    byte field_0x11; // accesses: 1
    byte field_0x12; // accesses: 1
    byte field_0x13; // accesses: 1
    uint field_0x14; // accesses: 13
    byte field_0x16; // accesses: 1
    byte _padding_0x17[1];
    byte field_0x18; // accesses: 1
    byte field_0x19; // accesses: 1
    byte field_0x1a; // accesses: 1

    // Member Functions
    void __thiscall RestoreFromStruct (void *this,SVehicleSimpleState_ReplayAfter040104 *param_1,SVehicleCarState *param_2, SState *param_3,SState *param_4,SState *param_5,SState *param_6);
};

#endif // SVEHICLESIMPLESTATE_REPLAYAFTER040104_HPP
