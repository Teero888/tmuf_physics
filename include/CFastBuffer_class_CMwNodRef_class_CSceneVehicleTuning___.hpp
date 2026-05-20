#ifndef CFASTBUFFER_CLASS_CMWNODREF_CLASS_CSCENEVEHICLETUNING____HPP
#define CFASTBUFFER_CLASS_CMWNODREF_CLASS_CSCENEVEHICLETUNING____HPP

#include "typedefs.h"

struct CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_> {
    void** vftable; // accesses: 5
    int field_0x4; // accesses: 3

    // Member Functions
    SLoadedLight * __thiscall AddNewElem (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1);
    void __thiscall ArchiveFastBufferNodRef (void *this,CFastBuffer<class_CMwNodRef<class_CMwNod>_> *param_1,CClassicArchive *param_2);
};

#endif // CFASTBUFFER_CLASS_CMWNODREF_CLASS_CSCENEVEHICLETUNING____HPP
