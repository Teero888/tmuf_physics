#ifndef CMOTIONSKELSIMPLE_HPP
#define CMOTIONSKELSIMPLE_HPP

#include "typedefs.h"

struct CMotionSkelSimple {
    void** vftable; // accesses: 1
    byte _padding_0x4[40];
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1

    // Member Functions
    void __thiscall CMotionSkelSimple(CMotionSkelSimple *this,CMotionSkelSimple *param_1);
};

#endif // CMOTIONSKELSIMPLE_HPP
