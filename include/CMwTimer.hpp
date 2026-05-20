#ifndef CMWTIMER_HPP
#define CMWTIMER_HPP

#include "typedefs.h"

struct CMwTimer {
    void** vftable; // accesses: 2
    uint field_0x4; // accesses: 2
    ulong field_0x8; // accesses: 3
    uint field_0xc; // accesses: 7
    float field_0x10; // accesses: 5
    float field_0x14; // accesses: 1
    uint field_0x18; // accesses: 3
    int field_0x1c; // accesses: 5
    int field_0x20; // accesses: 6
    int field_0x24; // accesses: 6
    undefined4 field_0x28; // accesses: 5
    int field_0x2c; // accesses: 5

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __cdecl SecondsToMwTime(float param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ChopTime(void *this,CMwTimer *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SimulateDeltaTime(void *this,CMwTimer *param_1,ulong param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Tick(void *this,CNetIPC *param_1);
    int __cdecl GetMwTimeFromHhMmSsTimeString(char *param_1,ulong *param_2);
    int __cdecl GetMwTimeFromHhMmTimeString(char *param_1,ulong *param_2);
    int __cdecl GetMwTimeFromMmSsCcTimeString(char *param_1,ulong *param_2);
    int __cdecl GetMwTimeFromMmSsTimeString(char *param_1,ulong *param_2);
    ulong * __thiscall GetTickTime(void *this,CMwTimerAdapter *param_1);
    ulong __thiscall GetElapsedTimeSinceInit(void *this,CMwTimer *param_1);
    void __cdecl GetHhMmSsTime24StringFromMwTime(ulong param_1,CFastString *param_2);
    void __cdecl GetHhMmSsTimeStringFromMwTime(ulong param_1,CFastString *param_2);
    void __cdecl GetHhMmTimeStringFromMwTime(ulong param_1,CFastString *param_2);
    void __cdecl GetMmSsCcTimeStringFromMwTime(ulong param_1,CFastString *param_2);
    void __cdecl GetMmSsTimeStringFromMwTime(ulong param_1,CFastString *param_2);
    void __thiscall InitTimer(void *this,CMwTimerAdapter *param_1,CMwTimer *param_2,float param_3);
};

#endif // CMWTIMER_HPP
