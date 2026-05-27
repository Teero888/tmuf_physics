#ifndef CMOTIONENGINE_HPP
#define CMOTIONENGINE_HPP

#include "typedefs.h"

struct CMotionEngine {
    void** vftable; // accesses: 1

    // Member Functions
    CMotion * __cdecl CreateMotionFromNod(CMwNod *param_1,CMwNod *param_2);
    void __thiscall CMotionEngine(CMotionEngine *this,CMotionEngine *param_1);
};

#endif // CMOTIONENGINE_HPP
