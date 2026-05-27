#ifndef CPLUGENGINE_HPP
#define CPLUGENGINE_HPP

#include "typedefs.h"

struct CPlugEngine {
    void** vftable; // accesses: 1
    byte _padding_0x4[28];
    undefined4 field_0x20; // accesses: 1

    // Member Functions
    void __thiscall CPlugEngine(CPlugEngine *this,CPlugEngine *param_1);
};

#endif // CPLUGENGINE_HPP
