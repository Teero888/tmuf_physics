#ifndef CSCENEPOC_HPP
#define CSCENEPOC_HPP

#include "typedefs.h"

struct CScenePoc {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall CScenePoc(CScenePoc *this,CScenePoc *param_1);
    void __thiscall SwitchOn(CScenePoc *this,CGameCtnMediaBlockTransitionFade *param_1);
};

#endif // CSCENEPOC_HPP
