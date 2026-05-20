#ifndef GMSPRING_FLOAT__HPP
#define GMSPRING_FLOAT__HPP

#include "typedefs.h"

struct GmSpring<float> {
    void** vftable; // accesses: 2
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 4
    float field_0xc; // accesses: 2
    float field_0x10; // accesses: 4

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GmSpring<float>(void *this,GmSpring<float> *param_1);
    void __thiscall ClearVals(void *this,GmSpring<float> *param_1);
    void __thiscall Integrate(void *this,SRealTimeState *param_1,float param_2);
};

#endif // GMSPRING_FLOAT__HPP
