#ifndef CFUNCPATHMESH_HPP
#define CFUNCPATHMESH_HPP

#include "typedefs.h"

struct CMwNod;
struct CPfmMeshInterface;
struct CVisionVisualKeeper;

struct CFuncPathMesh {
    void** vftable;
    byte _padding_0x4[36];
    int * field_0x28; // accesses: 7
    CPfmMeshInterface * field_0x2c; // accesses: 2

    // Member Functions
    void __thiscall BuildMesh(CFuncPathMesh *this,CFuncPathMesh *param_1);
    void __thiscall SetVisual(CFuncPathMesh *this,CVisionVisualKeeper *param_1,CPlugVisual *param_2);
};

#endif // CFUNCPATHMESH_HPP
