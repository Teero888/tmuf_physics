#ifndef SVEHICLESIMPLESTATE_REPLAYAFTER081205_HPP
#define SVEHICLESIMPLESTATE_REPLAYAFTER081205_HPP

#include "typedefs.h"

struct SVehicleSimpleState_ReplayAfter081205 {
    ushort field_0x0; // accesses: 2
    ushort field_0x2; // accesses: 2
    ushort field_0x4; // accesses: 2
    ushort field_0x6; // accesses: 2
    ushort field_0x8; // accesses: 2
    ushort field_0xa; // accesses: 2
    ushort field_0xc; // accesses: 2
    byte field_0xe; // accesses: 2
    byte field_0xf; // accesses: 2
    byte field_0x10; // accesses: 2
    undefined1 field_0x11; // accesses: 1
    undefined1 field_0x12; // accesses: 1
    byte field_0x13; // accesses: 2
    byte field_0x14; // accesses: 2
    byte field_0x15; // accesses: 2
    byte field_0x16; // accesses: 2
    byte field_0x17; // accesses: 2
    byte field_0x18; // accesses: 2
    byte field_0x19; // accesses: 2
    byte field_0x1a; // accesses: 2
    byte field_0x1b; // accesses: 2
    uint field_0x1c; // accesses: 16
    byte field_0x1d; // accesses: 2
    byte field_0x1e; // accesses: 2
    byte field_0x1f; // accesses: 1
    byte field_0x20; // accesses: 9
    byte field_0x21; // accesses: 23

    // Member Functions
    void __thiscall RestoreFromStruct (void *this,SVehicleSimpleState_ReplayAfter040104 *param_1,SVehicleCarState *param_2, SState *param_3,SState *param_4,SState *param_5,SState *param_6);
    void __thiscall SaveToStruct (void *this,SVehicleSimpleNetState *param_1,SVehicleCarState *param_2,float param_3, ulong param_4,int param_5,SState *param_6,int param_7,SState *param_8,int param_9, SState *param_10,int param_11,SState *param_12,int param_13);
};

#endif // SVEHICLESIMPLESTATE_REPLAYAFTER081205_HPP
