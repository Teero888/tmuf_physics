#ifndef SVEHICLESIMPLESTATE_REPLAYAFTER170806_HPP
#define SVEHICLESIMPLESTATE_REPLAYAFTER170806_HPP

#include "typedefs.h"

struct uchar;

struct SVehicleSimpleState_ReplayAfter170806 {
    byte _padding_0x0[34];
    byte field_0x22; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RestoreFromStruct (void *this,SVehicleSimpleState_ReplayAfter040104 *param_1,SVehicleCarState *param_2, SState *param_3,SState *param_4,SState *param_5,SState *param_6);
    void __thiscall SaveToStruct (void *this,SVehicleSimpleNetState *param_1,SVehicleCarState *param_2,float param_3, ulong param_4,int param_5,SState *param_6,int param_7,SState *param_8,int param_9, SState *param_10,int param_11,SState *param_12,int param_13);
};

#endif // SVEHICLESIMPLESTATE_REPLAYAFTER170806_HPP
