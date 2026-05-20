#ifndef CDX9PIXELSHADER_HPP
#define CDX9PIXELSHADER_HPP

#include "typedefs.h"

struct CDx9PixelShader {
    byte _padding_0x0[200];
    int field_0xc8; // accesses: 2

    // Member Functions
    void __thiscall UndirtyAndSetPixelShader(void *this,CDx9PixelShader *param_1);
};

#endif // CDX9PIXELSHADER_HPP
