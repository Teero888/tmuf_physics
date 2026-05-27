#ifndef CDX9VERTEXSHADER_HPP
#define CDX9VERTEXSHADER_HPP

#include "typedefs.h"

struct SPlugFaceCull;

struct CDx9VertexShader {
    void** vftable;
    SPlugFaceCull * field_0x4; // accesses: 2

    // Member Functions
    int __cdecl FilterSetVertexShader(CDx9VertexShader *param_1);
    int __thiscall UndirtyAndSetVertexShader(void *this,CDx9VertexShader *param_1);
    void __cdecl UpdateClipPlaneEqs(void);
};

#endif // CDX9VERTEXSHADER_HPP
