#ifndef CMWPARAM_HPP
#define CMWPARAM_HPP

#include "typedefs.h"

struct CMwParam {
    void** vftable; // accesses: 4

    // Member Functions
    int __thiscall IsIndexed(CMwParam *this,CMwParam *param_1);
};

#endif // CMWPARAM_HPP
