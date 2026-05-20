#ifndef CMWTIMERADAPTER_HPP
#define CMWTIMERADAPTER_HPP

#include "typedefs.h"

struct CMwTimer;

struct CMwTimerAdapter {
    void** vftable; // accesses: 8
    int field_0x4; // accesses: 6
    CMwTimer * field_0x8; // accesses: 5
    CMwTimerAdapter * field_0xc; // accesses: 4
    uint field_0x10; // accesses: 5
    ulong field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall GetAsyncPeriodMwTime(void *this,CMwTimerAdapter *param_1);
    float __thiscall GetAsyncPeriod(void *this,CMwTimerAdapter *param_1);
    float __thiscall GetRelativeSpeed(void *this,CMwTimerAdapter *param_1);
    ulong * __thiscall GetTickTime(void *this,CMwTimerAdapter *param_1);
    ulong __thiscall ConvertHumanToGame(void *this,CMwTimerAdapter *param_1,ulong param_2);
    ulong __thiscall GetTime(void *this,CMwTimerAdapter *param_1);
    ulong __thiscall GetTimeAtPreviousHumanTick(void *this,CMwTimerAdapter *param_1);
    void __thiscall ComputeTimeAtHumanTick(void *this,CMwTimerAdapter *param_1);
    void __thiscall InitTimer(void *this,CMwTimerAdapter *param_1,CMwTimer *param_2,float param_3);
    void __thiscall Resync(void *this,CMwTimerAdapter *param_1);
    void __thiscall SetCurrentTimeAtHumanTick(void *this,CMwTimerAdapter *param_1,ulong param_2);
    void __thiscall SetRelativeSpeed(void *this,CMwTimerAdapter *param_1,float param_2);
};

#endif // CMWTIMERADAPTER_HPP
