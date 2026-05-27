#ifndef CFASTBUFFER_WCHAR_T__HPP
#define CFASTBUFFER_WCHAR_T__HPP

#include "typedefs.h"

struct CFastBuffer<wchar_t> {
    void** vftable;

    // Member Functions
    void __thiscall AllocSetCount(void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2);
};

#endif // CFASTBUFFER_WCHAR_T__HPP
