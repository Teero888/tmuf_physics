#ifndef CMOTIONTRACK_HPP
#define CMOTIONTRACK_HPP

#include "typedefs.h"

struct CMotionTrack {
    byte _padding_0x0[36];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1

    // Member Functions
    void __thiscall CMotionTrack(CMotionTrack *this,CMotionTrack *param_1);
};

#endif // CMOTIONTRACK_HPP
