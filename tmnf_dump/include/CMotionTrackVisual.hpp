#ifndef CMOTIONTRACKVISUAL_HPP
#define CMOTIONTRACKVISUAL_HPP

#include "typedefs.h"

struct CMotionTrackVisual {
    void** vftable; // accesses: 1
    byte _padding_0x4[40];
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    byte _final_padding[0x4]; // Total size: 0x3c

    // Member Functions
    void __thiscall CMotionTrackVisual(CMotionTrackVisual *this,CMotionTrackVisual *param_1);
};

#endif // CMOTIONTRACKVISUAL_HPP
