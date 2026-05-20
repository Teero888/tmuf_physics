#ifndef CFASTBUFFER_CLASS_GMINT4__HPP
#define CFASTBUFFER_CLASS_GMINT4__HPP

#include "typedefs.h"

struct CFastBuffer<class_GmInt4> {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1

    // Member Functions
    /* WARNING: Control flow encountered bad instruction data */ SLoadedLight * __thiscall AddNewElem (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1);
    void __thiscall SetSizeAtLeast (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2);
};

#endif // CFASTBUFFER_CLASS_GMINT4__HPP
