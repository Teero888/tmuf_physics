#ifndef CPLUGSHADERLOADIDS_HPP
#define CPLUGSHADERLOADIDS_HPP

#include "typedefs.h"

struct CPlugShaderLoadIds {
    byte _padding_0x0[8];
    ELoadId field_0x8; // accesses: 2

    // Member Functions
    GmVec4 * __thiscall FindOrAddLoadId(void *this,CPlugShaderLoadIds *param_1,ELoadId param_2);
};

#endif // CPLUGSHADERLOADIDS_HPP
