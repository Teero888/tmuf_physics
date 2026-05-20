#ifndef CDX9VERTEXBUFFER_HPP
#define CDX9VERTEXBUFFER_HPP

#include "typedefs.h"

struct CDx9VertexBuffer {
    byte _padding_0x0[540];
    int field_0x21c; // accesses: 4

    // Member Functions
    void __thiscall Create(void *this,CDx9VertexBuffer *param_1);
    void __thiscall Release(void *this,CDx9VStreamKeeper *param_1);
    void __thiscall ~CDx9VertexBuffer(void *this,CDx9VertexBuffer *param_1);
};

#endif // CDX9VERTEXBUFFER_HPP
