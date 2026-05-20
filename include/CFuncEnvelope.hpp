#ifndef CFUNCENVELOPE_HPP
#define CFUNCENVELOPE_HPP

#include "typedefs.h"

struct CFuncEnvelope {
    void** vftable;
    byte _padding_0x4[44];
    float field_0x30; // accesses: 1
    int field_0x34; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ GmVec3 __thiscall GetValue(CFuncEnvelope *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CFUNCENVELOPE_HPP
