#ifndef CDX9VERTEXDECLARATION_HPP
#define CDX9VERTEXDECLARATION_HPP

#include "typedefs.h"

struct CDx9VertexDeclaration {
    byte _padding_0x0[2];
    short field_0x2; // accesses: 1
    int field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[1348];
    byte field_0x550; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl StaticSetStream01Decl(SStreamDecl param_1,SStreamDecl param_2);
    void __cdecl AddDeclarationStream (CFastBuffer<struct__D3DVERTEXELEMENT9> *param_1,ulong param_2,SStreamDecl param_3);
    void __cdecl StaticSetStream0Decl(SStreamDecl param_1);
};

#endif // CDX9VERTEXDECLARATION_HPP
