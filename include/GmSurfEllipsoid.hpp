#ifndef GMSURFELLIPSOID_HPP
#define GMSURFELLIPSOID_HPP

#include "typedefs.h"

struct GmSurfEllipsoid {
    undefined ** field_0x0; // accesses: 1
    byte _padding_0x4[4];
    float field_0x8; // accesses: 2
    float field_0xc; // accesses: 2
    float field_0x10; // accesses: 2

    // Member Functions
    void __thiscall CreateEllipsoidDefaultData(GmSurfEllipsoid *this,GmSurfEllipsoid *param_1);
    void __thiscall GetEllipsoidBoundingBox (GmSurfEllipsoid *this,GmSurfEllipsoid *param_1,GmBoxAligned *param_2);
    void __thiscall GmSurfEllipsoid(GmSurfEllipsoid *this,GmSurfEllipsoid *param_1);
};

#endif // GMSURFELLIPSOID_HPP
