#ifndef CSCENEPOC_HPP
#define CSCENEPOC_HPP

#include "typedefs.h"

struct CScenePoc {
    void** vftable; // accesses: 1
    byte _padding_0x4[36];
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    int * field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 1

    // Member Functions
    void __thiscall CScenePoc(CScenePoc *this,CScenePoc *param_1);
    void __thiscall SwitchOn(CScenePoc *this,CGameCtnMediaBlockTransitionFade *param_1);
};

#endif // CSCENEPOC_HPP
