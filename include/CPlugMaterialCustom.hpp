#ifndef CPLUGMATERIALCUSTOM_HPP
#define CPLUGMATERIALCUSTOM_HPP

#include "typedefs.h"

struct CPlugMaterialCustom {
    void** vftable;
    byte _final_padding[0x8c]; // Total size: 0x90

    // Member Functions
    CPlugShader * __cdecl ShaderLoadFromFidParam(CSystemFid *param_1,CPlugMaterialCustom *param_2);
};

#endif // CPLUGMATERIALCUSTOM_HPP
