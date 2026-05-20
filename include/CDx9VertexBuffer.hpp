#ifndef CDX9VERTEXBUFFER_HPP
#define CDX9VERTEXBUFFER_HPP

#include "typedefs.h"

struct CDx9VertexBuffer {
    void** vftable; // accesses: 1
    int field_0x4; // accesses: 1
    int field_0x8; // accesses: 1
    uint field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    int * field_0x14; // accesses: 4

    // Member Functions
    void __thiscall Create(void *this,CDx9VertexBuffer *param_1);
    void __thiscall Release(void *this,CDx9VStreamKeeper *param_1);
    void __thiscall ~CDx9VertexBuffer(void *this,CDx9VertexBuffer *param_1);
};

#endif // CDX9VERTEXBUFFER_HPP
