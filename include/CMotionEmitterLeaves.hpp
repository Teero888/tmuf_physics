#ifndef CMOTIONEMITTERLEAVES_HPP
#define CMOTIONEMITTERLEAVES_HPP

#include "typedefs.h"

struct CMotionEmitterLeaves {
    byte _padding_0x0[8];
    short field_0x8; // accesses: 1
    byte _padding_0xa[26];
    undefined4 field_0x24; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall OnAbsorbContact (CMotionEmitterLeaves *this,CMotions *param_1,CHmsPhysicalContact *param_2);
};

#endif // CMOTIONEMITTERLEAVES_HPP
