#ifndef GMSURFPOLYGON_HPP
#define GMSURFPOLYGON_HPP

#include "typedefs.h"

struct GmSurfPolygon {
    void** vftable; // accesses: 1
    byte _padding_0x4[68];
    undefined4 field_0x48; // accesses: 1

    // Member Functions
    void __thiscall GmSurfPolygon(GmSurfPolygon *this,GmSurfPolygon *param_1,uchar param_2);
};

#endif // GMSURFPOLYGON_HPP
