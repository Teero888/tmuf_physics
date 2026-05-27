#ifndef CFUNCTIONENGINE_HPP
#define CFUNCTIONENGINE_HPP

#include "typedefs.h"

struct CFunctionEngine {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall CFunctionEngine(CFunctionEngine *this,CFunctionEngine *param_1);
};

#endif // CFUNCTIONENGINE_HPP
