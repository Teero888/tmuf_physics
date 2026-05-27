#ifndef CNETENGINE_HPP
#define CNETENGINE_HPP

#include "typedefs.h"

struct CNetEngine {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall CNetEngine(CNetEngine *this,CNetEngine *param_1);
};

#endif // CNETENGINE_HPP
