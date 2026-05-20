#ifndef CPLUGINDEXBUFFER_HPP
#define CPLUGINDEXBUFFER_HPP

#include "typedefs.h"

struct CPlugIndexBuffer {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 3

    // Member Functions
    void __thiscall CPlugIndexBuffer(CPlugIndexBuffer *this,CPlugIndexBuffer *param_1);
};

#endif // CPLUGINDEXBUFFER_HPP
