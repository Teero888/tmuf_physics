#ifndef CMOTIONCMDBASE_HPP
#define CMOTIONCMDBASE_HPP

#include "typedefs.h"

struct CMotionCmdBase {
    void** vftable; // accesses: 1
    byte _padding_0x4[24];
    undefined4 field_0x1c; // accesses: 2
    uint field_0x20; // accesses: 3
    CMotionCmdBase * field_0x24; // accesses: 1
    CFuncPlug * field_0x28; // accesses: 5
    CFuncPlug * field_0x2c; // accesses: 7
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 2
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 2
    undefined4 field_0x4c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetPeriod(CMotionCmdBase *this,CFuncPlug *param_1,float param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetPhase(CMotionCmdBase *this,CFuncPlug *param_1,float param_2);
    ulong __thiscall GetBaseTime(CMotionCmdBase *this,CMotionCmdBase *param_1);
    void __thiscall CMotionCmdBase(CMotionCmdBase *this,CMotionCmdBase *param_1);
};

#endif // CMOTIONCMDBASE_HPP
