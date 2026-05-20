#ifndef CMOTIONENGINE_HPP
#define CMOTIONENGINE_HPP

#include "typedefs.h"

struct CMotionCmdBase;

struct CMotionEngine {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[16];
    CMotionCmdBase * field_0x30; // accesses: 4

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CMotion * __cdecl CreateMotionFromNod(CMwNod *param_1,CMwNod *param_2);
    void __thiscall CMotionEngine(CMotionEngine *this,CMotionEngine *param_1);
};

#endif // CMOTIONENGINE_HPP
