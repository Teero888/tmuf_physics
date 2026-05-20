#ifndef CFASTBUFFER_CLASS_CFASTSTRING__HPP
#define CFASTBUFFER_CLASS_CFASTSTRING__HPP

#include "typedefs.h"

struct ulong;

struct CFastBuffer<class_CFastString> {
    void** vftable; // accesses: 10
    void * field_0x4; // accesses: 5

    // Member Functions
    SLoadedLight * __thiscall AddNewElem (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1);
    void __thiscall InitSize (void *this,CFastBuffer<struct_SMeshOctreeCell> *param_1,ulong param_2);
    void __thiscall RemoveAt (void *this,CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *param_1, ulong param_2,ulong param_3);
    void __thiscall ~CFastBuffer<class_CFastString> (void *this,CFastBuffer<class_CFastString> *param_1);
};

#endif // CFASTBUFFER_CLASS_CFASTSTRING__HPP
