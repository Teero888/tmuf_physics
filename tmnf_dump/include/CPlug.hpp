#ifndef CPLUG_HPP
#define CPLUG_HPP

#include "typedefs.h"

struct CPlug {
    void** vftable; // accesses: 2
    byte _final_padding[0x10]; // Total size: 0x14

    // Member Functions
    void __thiscall CPlug(CPlug *this,CPlug *param_1);
    void __thiscall ~CPlug(CPlug *this,CPlug *param_1);
};

#endif // CPLUG_HPP
