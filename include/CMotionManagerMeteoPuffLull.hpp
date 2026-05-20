#ifndef CMOTIONMANAGERMETEOPUFFLULL_HPP
#define CMOTIONMANAGERMETEOPUFFLULL_HPP

#include "typedefs.h"

struct CFuncPuffLull;

struct CMotionManagerMeteoPuffLull {
    byte _padding_0x0[24];
    CFuncPuffLull * field_0x18; // accesses: 1

    // Member Functions
    void __thiscall UpdateAsync(CMotionManagerMeteoPuffLull *this,CInputPortDx8 *param_1);
};

#endif // CMOTIONMANAGERMETEOPUFFLULL_HPP
