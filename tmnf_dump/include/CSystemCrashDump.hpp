#ifndef CSYSTEMCRASHDUMP_HPP
#define CSYSTEMCRASHDUMP_HPP

#include "typedefs.h"

struct CSystemCrashDump {
    void** vftable; // accesses: 4
    byte _padding_0x4[36];
    uint field_0x28; // accesses: 2

    // Member Functions
    int __thiscall IsValid(CSystemCrashDump *this,CGameScoresVersion *param_1);
    int __thiscall IsValid_DumpFidAndMwId (CSystemCrashDump *this,CSystemCrashDump *param_1,CFastString *param_2,char *param_3, CMwNod *param_4,int param_5);
    void __thiscall ContextPop(CSystemCrashDump *this,CSystemCrashDump *param_1);
    void __thiscall ContextPush(CSystemCrashDump *this,CSystemCrashDump *param_1,char *param_2);
    void __thiscall StringCatVec3 (CSystemCrashDump *this,CSystemCrashDump *param_1,CFastString *param_2,GmVec3 *param_3);
};

#endif // CSYSTEMCRASHDUMP_HPP
