#ifndef GMSURFELLIPSOID_HPP
#define GMSURFELLIPSOID_HPP

#include "typedefs.h"

struct GmSurfEllipsoid {
    void** vftable; // accesses: 2
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 3
    undefined4 field_0x10; // accesses: 3
    undefined4 field_0x14; // accesses: 1

    // Member Functions
    void __thiscall CreateEllipsoidDefaultData(GmSurfEllipsoid *this,GmSurfEllipsoid *param_1);
    void __thiscall GetEllipsoidBoundingBox (GmSurfEllipsoid *this,GmSurfEllipsoid *param_1,GmBoxAligned *param_2);
    void __thiscall GmSurfEllipsoid(GmSurfEllipsoid *this,GmSurfEllipsoid *param_1);
};

#endif // GMSURFELLIPSOID_HPP
