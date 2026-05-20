#ifndef CMOTION_HPP
#define CMOTION_HPP

#include "typedefs.h"

struct CMotion {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall CMotion(CMotion *this,CMotion *param_1);
};

#endif // CMOTION_HPP
