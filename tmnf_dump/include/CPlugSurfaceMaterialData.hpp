#ifndef CPLUGSURFACEMATERIALDATA_HPP
#define CPLUGSURFACEMATERIALDATA_HPP

#include "typedefs.h"

struct CPlugSurfaceMaterialData {
    void** vftable;
    float field_0x4; // accesses: 4

    // Member Functions
    float __thiscall GetRestitutionCoefWith (void *this,CPlugSurfaceMaterialData *param_1,CPlugSurfaceMaterialData *param_2);
};

#endif // CPLUGSURFACEMATERIALDATA_HPP
