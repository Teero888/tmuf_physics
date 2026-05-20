#ifndef CMWSTATSVALUE_HPP
#define CMWSTATSVALUE_HPP

#include "typedefs.h"

struct CMwStatsValue {
    void** vftable;
    byte _final_padding[0x11]; // Total size: 0x15

    // Member Functions
    void __thiscall SetSize(CMwStatsValue *this,CMwStatsValue *param_1,ulong param_2);
};

#endif // CMWSTATSVALUE_HPP
