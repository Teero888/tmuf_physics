#ifndef CVISIONVISUALKEEPER_HPP
#define CVISIONVISUALKEEPER_HPP

#include "typedefs.h"

struct CVisionVisualKeeper {
    byte _padding_0x0[4];
    CVisionVisualKeeper * field_0x4; // accesses: 1

    // Member Functions
    void __thiscall SetVisual (CVisionVisualKeeper *this,CVisionVisualKeeper *param_1,CPlugVisual *param_2);
};

#endif // CVISIONVISUALKEEPER_HPP
