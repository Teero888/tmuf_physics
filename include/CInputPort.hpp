#ifndef CINPUTPORT_HPP
#define CINPUTPORT_HPP

#include "typedefs.h"

struct ulong;

struct CInputPort {
    void** vftable; // accesses: 2
    byte _padding_0x4[28];
    int field_0x20; // accesses: 5
    byte _padding_0x24[4];
    float field_0x28; // accesses: 1
    byte _padding_0x2c[8];
    int field_0x34; // accesses: 1
    ulong field_0x38; // accesses: 2
    byte _padding_0x3c[80];
    undefined4 field_0x8c; // accesses: 4
    undefined4 field_0x90; // accesses: 5
    int field_0x94; // accesses: 1
    undefined4 field_0x98; // accesses: 3
    byte _padding_0x9c[44];
    ulong field_0xc8; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ SInputEvent * __thiscall GetActionState(CInputPort *this,CInputPort *param_1,SInputActionDesc *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ReadCurMapLatestEventsFromHarware(CInputPort *this,CInputPort *param_1,int param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RumbleAdd (CInputPort *this,CInputDevice *param_1,ulong param_2,float param_3,float param_4);
    int __thiscall FindDevice (CInputPort *this,CInputPort *param_1,CMwId *param_2,ulong *param_3,CInputDevice **param_4 );
    void __thiscall ClearInputs(CInputPort *this,CInputPort *param_1,int param_2);
    void __thiscall InternalGatherLatestInputs(CInputPort *this,CInputPort *param_1);
    void __thiscall OnFocusChanged(CInputPort *this,CInputPort *param_1);
    void __thiscall UpdateAsync(CInputPort *this,CInputPortDx8 *param_1);
};

#endif // CINPUTPORT_HPP
