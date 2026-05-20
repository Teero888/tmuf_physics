#ifndef CMOTIONTRACK_HPP
#define CMOTIONTRACK_HPP

#include "typedefs.h"

struct CMotionTrack {
    void** vftable; // accesses: 1
    byte _padding_0x4[32];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1

    // Member Functions
    void __thiscall CMotionTrack(CMotionTrack *this,CMotionTrack *param_1);
};

#endif // CMOTIONTRACK_HPP
