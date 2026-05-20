#ifndef CDX9VERTEXSHADER_HPP
#define CDX9VERTEXSHADER_HPP

#include "typedefs.h"

struct CDx9VertexShader {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[204];
    code * field_0xdc; // accesses: 1

    // Member Functions
    int __cdecl FilterSetVertexShader(CDx9VertexShader *param_1);
    int __thiscall UndirtyAndSetVertexShader(void *this,CDx9VertexShader *param_1);
    void __cdecl UpdateClipPlaneEqs(void);
};

#endif // CDX9VERTEXSHADER_HPP
