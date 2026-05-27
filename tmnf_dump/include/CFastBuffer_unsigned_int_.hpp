#ifndef CFASTBUFFER_UNSIGNED_INT__HPP
#define CFASTBUFFER_UNSIGNED_INT__HPP

#include "typedefs.h"

struct CFastBuffer<unsigned_int> {
    void** vftable;

    // Member Functions
    void __thiscall RemoveIfFound (void *this,CFastBuffer<unsigned_int> *param_1,uint *param_2);
};

#endif // CFASTBUFFER_UNSIGNED_INT__HPP
