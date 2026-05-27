#ifndef CMOTIONSKELBLENDER_HPP
#define CMOTIONSKELBLENDER_HPP

#include "typedefs.h"

struct CMwCmd;
struct CMwNod;

struct CMotionSkelBlender {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    CMwNod * field_0x14; // accesses: 2

    // Member Functions
    void __cdecl StaticAddRef(void);
    void __thiscall CMotionSkelBlender(CMotionSkelBlender *this,CMotionSkelBlender *param_1);
};

#endif // CMOTIONSKELBLENDER_HPP
