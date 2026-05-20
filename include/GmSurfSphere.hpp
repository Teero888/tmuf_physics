#ifndef GMSURFSPHERE_HPP
#define GMSURFSPHERE_HPP

#include "typedefs.h"

struct GmSurfSphere {
    float field_0x0; // accesses: 1
    byte _padding_0x4[4];
    float field_0x8; // accesses: 5

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall ClipSegment (GmSurfSphere *this,GmSurfSphere *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4, float *param_5);
    void __thiscall GetSphereBoundingBox(GmSurfSphere *this,GmSurfSphere *param_1,GmBoxAligned *param_2);
    void __thiscall GmSurfSphere(GmSurfSphere *this,GmSurfSphere *param_1);
};

#endif // GMSURFSPHERE_HPP
