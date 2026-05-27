#ifndef CHMSENGINE_HPP
#define CHMSENGINE_HPP

#include "typedefs.h"

struct CHmsEngine {
    void** vftable; // accesses: 1
    byte _padding_0x4[28];
    undefined4 field_0x20; // accesses: 1

    // Member Functions
    void __thiscall CHmsEngine(CHmsEngine *this,CHmsEngine *param_1);
};

#endif // CHMSENGINE_HPP
