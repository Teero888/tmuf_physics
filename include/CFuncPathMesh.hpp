#ifndef CFUNCPATHMESH_HPP
#define CFUNCPATHMESH_HPP

#include "typedefs.h"

struct CMwNod;
struct CPfmMeshInterface;
struct CVisionVisualKeeper;

struct CFuncPathMesh {
    byte _padding_0x0[40];
    int * field_0x28; // accesses: 7
    CPfmMeshInterface * field_0x2c; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall BuildMesh(CFuncPathMesh *this,CFuncPathMesh *param_1);
    void __thiscall SetVisual(CFuncPathMesh *this,CVisionVisualKeeper *param_1,CPlugVisual *param_2);
};

#endif // CFUNCPATHMESH_HPP
