#ifndef CFASTBUFFER_CLASS_CMWID__HPP
#define CFASTBUFFER_CLASS_CMWID__HPP

#include "typedefs.h"

struct CFastBuffer<class_CMwId> {

    // Member Functions
    void __thiscall Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
    void __thiscall ResetAndFreeMemory (void *this,CFastBuffer<struct_SInputActionDesc_const*> *param_1);
    void __thiscall SetBuffer (void *this,CFastBuffer<class_GxVertex> *param_1,ulong param_2,GxVertex *param_3);
    void __thiscall ~CFastBuffer<class_CMwId>(void *this,CFastBuffer<class_CMwId> *param_1);
};

#endif // CFASTBUFFER_CLASS_CMWID__HPP
