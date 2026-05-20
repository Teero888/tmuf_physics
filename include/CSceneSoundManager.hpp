#ifndef CSCENESOUNDMANAGER_HPP
#define CSCENESOUNDMANAGER_HPP

#include "typedefs.h"

struct CSceneSoundManager {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1

    // Member Functions
    void __thiscall CSceneSoundManager (CSceneSoundManager *this,CSceneSoundManager *param_1,CScene *param_2);
};

#endif // CSCENESOUNDMANAGER_HPP
