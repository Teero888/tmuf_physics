#ifndef CPLUGINDEXBUFFER_HPP
#define CPLUGINDEXBUFFER_HPP

#include "typedefs.h"

struct CPlugIndexBuffer {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 3

    // Member Functions
    void __thiscall CPlugIndexBuffer(CPlugIndexBuffer *this,CPlugIndexBuffer *param_1);
};

#endif // CPLUGINDEXBUFFER_HPP
