#ifndef CPLUGSHADERLOADIDS_HPP
#define CPLUGSHADERLOADIDS_HPP

#include "typedefs.h"

struct CPlugShaderLoadIds {
    byte _padding_0x0[16];
    int field_0x10; // accesses: 1

    // Member Functions
    GmVec4 * __thiscall FindOrAddLoadId(void *this,CPlugShaderLoadIds *param_1,ELoadId param_2);
};

#endif // CPLUGSHADERLOADIDS_HPP
