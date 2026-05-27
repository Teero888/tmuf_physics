#ifndef CDX9PIXELSHADER_HPP
#define CDX9PIXELSHADER_HPP

#include "typedefs.h"

struct CDx9PixelShader {
    void** vftable; // accesses: 2
    int * field_0x4; // accesses: 2
    int field_0x8; // accesses: 1

    // Member Functions
    void __thiscall UndirtyAndSetPixelShader(void *this,CDx9PixelShader *param_1);
};

#endif // CDX9PIXELSHADER_HPP
