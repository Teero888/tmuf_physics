#ifndef SSURFACEID_HPP
#define SSURFACEID_HPP

#include "typedefs.h"

struct SSurfaceId {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
};

#endif // SSURFACEID_HPP
