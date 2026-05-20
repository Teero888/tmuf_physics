#ifndef CMOTIONTIMERLOOP_HPP
#define CMOTIONTIMERLOOP_HPP

#include "typedefs.h"

struct CMotionTimerLoop {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 2
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall GetNormedTime(CMotionTimerLoop *this,CMotionTimerLoop *param_1);
};

#endif // CMOTIONTIMERLOOP_HPP
