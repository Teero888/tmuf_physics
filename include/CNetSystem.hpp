#ifndef CNETSYSTEM_HPP
#define CNETSYSTEM_HPP

#include "typedefs.h"

struct CNetSystem {
    struct CNetSystemError {
        void** vftable; // accesses: 1
        byte _padding_0x4[8];
        undefined4 field_0xc; // accesses: 1

        // Member Functions
        void __thiscall CNetSystemError (CNetSystemError *this,CNetSystemError *param_1,CNetSystemError *param_2);
    };

    void** vftable;

    // Member Functions
    void __thiscall Init(void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CNETSYSTEM_HPP
