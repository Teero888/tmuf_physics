#ifndef CAUDIOENGINE_HPP
#define CAUDIOENGINE_HPP

#include "typedefs.h"

struct CAudioEngine {
    void** vftable; // accesses: 1
    byte _padding_0x4[40];
    undefined4 field_0x2c; // accesses: 1

    // Member Functions
    void __thiscall CAudioEngine(CAudioEngine *this,CAudioEngine *param_1);
};

#endif // CAUDIOENGINE_HPP
