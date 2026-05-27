#ifndef CCLASSICBUFFERREF_HPP
#define CCLASSICBUFFERREF_HPP

#include "typedefs.h"

struct CClassicBufferMemory;

struct CClassicBufferRef {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall CClassicBufferRef(void *this,CClassicBufferRef *param_1);
    void __thiscall ~CClassicBufferRef(void *this,CClassicBufferRef *param_1);
};

#endif // CCLASSICBUFFERREF_HPP
