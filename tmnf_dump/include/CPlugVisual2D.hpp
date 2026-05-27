#ifndef CPLUGVISUAL2D_HPP
#define CPLUGVISUAL2D_HPP

#include "typedefs.h"

struct CPlugVisual2D {
    void** vftable; // accesses: 1
    byte _padding_0x4[24];
    uint field_0x1c; // accesses: 2

    // Member Functions
    void __thiscall CPlugVisual2D(CPlugVisual2D *this,CPlugVisual2D *param_1);
};

#endif // CPLUGVISUAL2D_HPP
