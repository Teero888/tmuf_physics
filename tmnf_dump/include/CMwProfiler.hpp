#ifndef CMWPROFILER_HPP
#define CMWPROFILER_HPP

#include "typedefs.h"

struct CMwProfiler {
    void** vftable; // accesses: 1

    // Member Functions
    float __cdecl GetDurationFromDeltaTimeStamp(int64 param_1);
    int64 __cdecl GetCPUFrequency(void);
    ulong __cdecl GetTimeFromDeltaTimeStamp(int64 param_1);
    void __cdecl GetTimeStamp(int64 *param_1);
    void __thiscall CMwProfiler(CMwProfiler *this,CMwProfiler *param_1);
};

#endif // CMWPROFILER_HPP
