#ifndef CFASTBUFFER_CLASS_CMWNODREF_CLASS_CPLUGMATERIAL____HPP
#define CFASTBUFFER_CLASS_CMWNODREF_CLASS_CPLUGMATERIAL____HPP

#include "typedefs.h"

struct CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_> {
    void** vftable; // accesses: 7
    void * field_0x4; // accesses: 5
    undefined4 field_0x8; // accesses: 2

    // Member Functions
    SLoadedLight * __thiscall AddNewElem (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1);
    void __thiscall AllocSetCount (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2);
    void __thiscall ArchiveCount (void *this,CFastArray<class_CPlugFileSnd*> *param_1,CClassicArchive *param_2);
    void __thiscall ResetAndFreeMemory (void *this,CFastBuffer<struct_SInputActionDesc_const*> *param_1);
};

#endif // CFASTBUFFER_CLASS_CMWNODREF_CLASS_CPLUGMATERIAL____HPP
