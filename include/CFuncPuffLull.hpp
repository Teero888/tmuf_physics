#ifndef CFUNCPUFFLULL_HPP
#define CFUNCPUFFLULL_HPP

#include "typedefs.h"

struct CFuncPuffLull {
    void** vftable;
    byte _final_padding[0x88]; // Total size: 0x8c

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateStateCurrent (CFuncPuffLull *this,CFuncPuffLull *param_1,ulong param_2,EState param_3,float param_4);
};

#endif // CFUNCPUFFLULL_HPP
