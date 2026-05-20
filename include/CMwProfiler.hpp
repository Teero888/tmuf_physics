#ifndef CMWPROFILER_HPP
#define CMWPROFILER_HPP

#include "typedefs.h"

struct CMwProfiler {

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __cdecl GetDurationFromDeltaTimeStamp(int64 param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int64 __cdecl GetCPUFrequency(void);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __cdecl GetTimeFromDeltaTimeStamp(int64 param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl GetTimeStamp(int64 *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CMwProfiler(CMwProfiler *this,CMwProfiler *param_1);
};

#endif // CMWPROFILER_HPP
