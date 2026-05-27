#ifndef CFUNC_HPP
#define CFUNC_HPP

#include "typedefs.h"

struct CFunc {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall CFunc(CFunc *this,CFunc *param_1);
};

#endif // CFUNC_HPP
