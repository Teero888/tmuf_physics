#ifndef CINPUTENGINE_HPP
#define CINPUTENGINE_HPP

#include "typedefs.h"

struct CInputEngine {
    void** vftable; // accesses: 1
    byte _padding_0x4[28];
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1

    // Member Functions
    void __thiscall CInputEngine(CInputEngine *this,CInputEngine *param_1);
};

#endif // CINPUTENGINE_HPP
