#ifndef GMFIELD2_HPP
#define GMFIELD2_HPP

#include "typedefs.h"

struct GmField2 {
    byte _padding_0x0[28];
    float field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    float field_0x24; // accesses: 1

    // Member Functions
    void __thiscall GetScaleAt(GmField2 *this,GmField2Compressed *param_1,GmVec2 *param_2,float *param_3);
};

#endif // GMFIELD2_HPP
