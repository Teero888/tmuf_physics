#ifndef CMOTIONSKEL_HPP
#define CMOTIONSKEL_HPP

#include "typedefs.h"

struct CMotionSkel {
    void** vftable; // accesses: 1
    byte _padding_0x4[60];
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1

    // Member Functions
    void __thiscall CMotionSkel(CMotionSkel *this,CMotionSkel *param_1);
};

#endif // CMOTIONSKEL_HPP
