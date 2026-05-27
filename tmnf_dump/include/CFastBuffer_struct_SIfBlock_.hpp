#ifndef CFASTBUFFER_STRUCT_SIFBLOCK__HPP
#define CFASTBUFFER_STRUCT_SIFBLOCK__HPP

#include "typedefs.h"

struct CFastBuffer<struct_SIfBlock> {
    void** vftable; // accesses: 3
    int field_0x4; // accesses: 1

    // Member Functions
    SLoadedLight * __thiscall AddNewElem (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1);
};

#endif // CFASTBUFFER_STRUCT_SIFBLOCK__HPP
