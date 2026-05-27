#ifndef CVISIONVISUALKEEPER_HPP
#define CVISIONVISUALKEEPER_HPP

#include "typedefs.h"

struct CVisionVisualKeeper {
    void** vftable;
    CVisionVisualKeeper * field_0x4; // accesses: 1

    // Member Functions
    void __thiscall SetVisual (CVisionVisualKeeper *this,CVisionVisualKeeper *param_1,CPlugVisual *param_2);
};

#endif // CVISIONVISUALKEEPER_HPP
