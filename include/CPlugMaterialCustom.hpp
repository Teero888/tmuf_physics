#ifndef CPLUGMATERIALCUSTOM_HPP
#define CPLUGMATERIALCUSTOM_HPP

#include "typedefs.h"

struct CPlugMaterialCustom {
    void** vftable; // accesses: 1

    // Member Functions
    CPlugShader * __cdecl ShaderLoadFromFidParam(CSystemFid *param_1,CPlugMaterialCustom *param_2);
};

#endif // CPLUGMATERIALCUSTOM_HPP
