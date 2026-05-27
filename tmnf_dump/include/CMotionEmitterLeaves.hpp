#ifndef CMOTIONEMITTERLEAVES_HPP
#define CMOTIONEMITTERLEAVES_HPP

#include "typedefs.h"

struct CMotionEmitterLeaves {
    void** vftable;
    byte _padding_0x4[32];
    undefined4 field_0x24; // accesses: 1
    byte _final_padding[0x1c]; // Total size: 0x44

    // Member Functions
    void __thiscall OnAbsorbContact (CMotionEmitterLeaves *this,CMotions *param_1,CHmsPhysicalContact *param_2);
};

#endif // CMOTIONEMITTERLEAVES_HPP
