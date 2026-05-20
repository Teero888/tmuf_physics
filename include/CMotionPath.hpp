#ifndef CMOTIONPATH_HPP
#define CMOTIONPATH_HPP

#include "typedefs.h"

struct CMwNod;

struct CMotionPath {
    void** vftable; // accesses: 1
    byte _padding_0x4[40];
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 2
    CMotionPath * field_0x38; // accesses: 5
    undefined4 field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1

    // Member Functions
    void __thiscall CMotionPath(CMotionPath *this,CMotionPath *param_1);
    void __thiscall InternalSetPath(CMotionPath *this,CMotionPath *param_1,CScenePath *param_2);
    void __thiscall SetPath(CMotionPath *this,CSceneToySubway *param_1,CScenePath *param_2);
};

#endif // CMOTIONPATH_HPP
