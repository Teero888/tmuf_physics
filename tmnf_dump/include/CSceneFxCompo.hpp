#ifndef CSCENEFXCOMPO_HPP
#define CSCENEFXCOMPO_HPP

#include "typedefs.h"

struct CSceneFxCompo {
    void** vftable;

    // Member Functions
    int __thiscall ShaderAdd(CSceneFxCompo *this,CVisionViewport *param_1,CPlugShader *param_2);
};

#endif // CSCENEFXCOMPO_HPP
