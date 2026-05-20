#ifndef SVEHICLESIMPLENETSTATE_HPP
#define SVEHICLESIMPLENETSTATE_HPP

#include "typedefs.h"

struct SVehicleSimpleNetState {
    byte _padding_0x0[12];
    undefined2 field_0xc; // accesses: 8
    byte _padding_0xe[2];
    undefined4 field_0x10; // accesses: 12
    undefined4 field_0x14; // accesses: 12
    byte _padding_0x18[4];
    int field_0x1c; // accesses: 4
    byte _padding_0x20[68];
    uint field_0x64; // accesses: 1
    byte _padding_0x68[24];
    float field_0x80; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RestoreFromStruct (void *this,SVehicleSimpleState_ReplayAfter040104 *param_1,SVehicleCarState *param_2, SState *param_3,SState *param_4,SState *param_5,SState *param_6);
    void __thiscall SaveToStruct (void *this,SVehicleSimpleNetState *param_1,SVehicleCarState *param_2,float param_3, ulong param_4,int param_5,SState *param_6,int param_7,SState *param_8,int param_9, SState *param_10,int param_11,SState *param_12,int param_13);
};

#endif // SVEHICLESIMPLENETSTATE_HPP
