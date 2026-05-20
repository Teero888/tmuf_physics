#ifndef CVISIONVIEWPORTNULL_HPP
#define CVISIONVIEWPORTNULL_HPP

#include "typedefs.h"

struct CVisionViewportNull {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1

    // Member Functions
    void __thiscall CVisionViewportNull(CVisionViewportNull *this,CVisionViewportNull *param_1);
    void __thiscall SetFullScreenGammaRamp (CVisionViewportNull *this,CVisionViewportNull *param_1,float param_2,float param_3, float param_4);
};

#endif // CVISIONVIEWPORTNULL_HPP
