#ifndef CFASTBUFFER_CLASS_CSYSTEMFIDPARAMETERS__HPP
#define CFASTBUFFER_CLASS_CSYSTEMFIDPARAMETERS__HPP

#include "typedefs.h"

struct CFastBuffer<class_CSystemFidParameters> {
    void** vftable; // accesses: 4
    undefined4 * field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1

    // Member Functions
    SLoadedLight * __thiscall AddNewElem (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1);
    void __thiscall ResetAndFreeMemory (void *this,CFastBuffer<struct_SInputActionDesc_const*> *param_1);
};

#endif // CFASTBUFFER_CLASS_CSYSTEMFIDPARAMETERS__HPP
