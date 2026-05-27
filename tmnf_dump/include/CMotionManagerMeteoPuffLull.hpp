#ifndef CMOTIONMANAGERMETEOPUFFLULL_HPP
#define CMOTIONMANAGERMETEOPUFFLULL_HPP

#include "typedefs.h"

struct CFuncPuffLull;

struct CMotionManagerMeteoPuffLull {
    void** vftable;
    byte _padding_0x4[20];
    CFuncPuffLull * field_0x18; // accesses: 1
    byte _final_padding[0x28]; // Total size: 0x44

    // Member Functions
    void __thiscall UpdateAsync(CMotionManagerMeteoPuffLull *this,CInputPortDx8 *param_1);
};

#endif // CMOTIONMANAGERMETEOPUFFLULL_HPP
