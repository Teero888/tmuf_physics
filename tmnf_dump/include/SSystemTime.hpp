#ifndef SSYSTEMTIME_HPP
#define SSYSTEMTIME_HPP

#include "typedefs.h"

struct SSystemTime {
    uint field_0x0; // accesses: 9
    byte field_0x2; // accesses: 1
    byte _padding_0x3[1];
    uint field_0x4; // accesses: 9

    // Member Functions
    int __thiscall IsInvalid(void *this,SSystemTime *param_1);
    int64 __cdecl GetT2SubT1InMilliseconds(SSystemTime *param_1,SSystemTime *param_2);
    void __thiscall GetAsString_YMD_HMS (void *this,SSystemTime *param_1,CFastString *param_2,CFastString *param_3);
    void __thiscall SSystemTime(void *this,SSystemTime *param_1);
    void __thiscall SetFromFileTime(void *this,SSystemTime *param_1,uint64 param_2);
    void __thiscall SetFromLocalTime(void *this,SSystemTime *param_1);
    void __thiscall SetFromSystemTime(void *this,SSystemTime *param_1);
    void __thiscall SetInvalid(void *this,CGameScoresVersion *param_1);
};

#endif // SSYSTEMTIME_HPP
