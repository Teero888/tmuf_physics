#ifndef GMSPRING_CLASS_GMVEC3__HPP
#define GMSPRING_CLASS_GMVEC3__HPP

#include "typedefs.h"

struct GmSpring<class_GmVec3> {
    float field_0x0; // accesses: 1
    float field_0x4; // accesses: 1
    float field_0x8; // accesses: 4
    float field_0xc; // accesses: 4
    float field_0x10; // accesses: 4
    float field_0x14; // accesses: 2
    float field_0x18; // accesses: 2
    float field_0x1c; // accesses: 2
    float field_0x20; // accesses: 5
    float field_0x24; // accesses: 5
    float field_0x28; // accesses: 5

    // Member Functions
    float __thiscall GetCriticalKa(void *this,GmSpring<class_GmVec3> *param_1);
    void __thiscall ClearVals(void *this,GmSpring<float> *param_1);
    void __thiscall Integrate(void *this,SRealTimeState *param_1,float param_2);
};

#endif // GMSPRING_CLASS_GMVEC3__HPP
