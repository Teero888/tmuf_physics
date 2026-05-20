#ifndef CMOTIONLIGHT_HPP
#define CMOTIONLIGHT_HPP

#include "typedefs.h"

struct CMwNod;
struct GxLight;

struct CMotionLight {
    void** vftable; // accesses: 1
    byte _padding_0x4[40];
    CMwNod * field_0x2c; // accesses: 4
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1

    // Member Functions
    void __thiscall CMotionLight(CMotionLight *this,CMotionLight *param_1);
    void __thiscall SetLight(CMotionLight *this,CMotionLight *param_1,GxLight *param_2);
};

#endif // CMOTIONLIGHT_HPP
