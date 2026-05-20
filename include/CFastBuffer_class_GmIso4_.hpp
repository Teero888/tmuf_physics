#ifndef CFASTBUFFER_CLASS_GMISO4__HPP
#define CFASTBUFFER_CLASS_GMISO4__HPP

#include "typedefs.h"

struct CFastBuffer<class_GmIso4> {
    void** vftable; // accesses: 6
    int field_0x4; // accesses: 3

    // Member Functions
    SLoadedLight * __thiscall AddNewElem (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1);
    void __thiscall Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
    void __thiscall AllocSetCount (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2);
    void __thiscall CopyFromFastBuffer (void *this,CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_1, CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_2);
};

#endif // CFASTBUFFER_CLASS_GMISO4__HPP
