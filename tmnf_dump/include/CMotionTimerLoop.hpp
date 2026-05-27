#ifndef CMOTIONTIMERLOOP_HPP
#define CMOTIONTIMERLOOP_HPP

#include "typedefs.h"

struct CMotionTimerLoop {
    void** vftable;
    byte _padding_0x4[20];
    int field_0x18; // accesses: 2
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 2
    byte _final_padding[0x10]; // Total size: 0x34

    // Member Functions
    float __thiscall GetNormedTime(CMotionTimerLoop *this,CMotionTimerLoop *param_1);
};

#endif // CMOTIONTIMERLOOP_HPP
