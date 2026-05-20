#ifndef CGAMEENGINE_HPP
#define CGAMEENGINE_HPP

#include "typedefs.h"

struct CGameEngine {
    void** vftable; // accesses: 1
    byte _final_padding[0x1c]; // Total size: 0x20

    // Member Functions
    void __thiscall CGameEngine(CGameEngine *this,CGameEngine *param_1);
};

#endif // CGAMEENGINE_HPP
