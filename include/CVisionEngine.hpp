#ifndef CVISIONENGINE_HPP
#define CVISIONENGINE_HPP

#include "typedefs.h"

struct CVisionEngine {
    byte _padding_0x0[144];
    int field_0x90; // accesses: 1

    // Member Functions
    CHmsViewport * __thiscall FindOrCreateViewport (CVisionEngine *this,CVisionEngine *param_1,CSystemWindow *param_2);
    void __thiscall CVisionEngine(CVisionEngine *this,CVisionEngine *param_1);
};

#endif // CVISIONENGINE_HPP
