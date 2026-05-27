#ifndef CPLUGFILEGEN_HPP
#define CPLUGFILEGEN_HPP

#include "typedefs.h"

struct CPlugFileImg;
struct GxColor;

struct CPlugFileGen {
    void** vftable; // accesses: 1
    byte _padding_0x4[20];
    CPlugFileImg * field_0x18; // accesses: 19
    CPlugFileGen * field_0x1c; // accesses: 19
    int field_0x20; // accesses: 1
    uint field_0x24; // accesses: 32
    int * field_0x28; // accesses: 9
    byte _padding_0x2c[8];
    undefined4 field_0x34; // accesses: 7
    byte _final_padding[0x18]; // Total size: 0x50

    // Member Functions
    void __thiscall CPlugFileGen(CPlugFileGen *this,CPlugFileGen *param_1);
    void __thiscall GenChecker(CPlugFileGen *this,CPlugFileGen *param_1,ulong param_2);
    void __thiscall GenCubeNormals (CPlugFileGen *this,CPlugFileGen *param_1,ulong param_2,ulong param_3,GxColor *param_4, GxColor *param_5);
    void __thiscall GenHueGradient (CPlugFileGen *this,CPlugFileGen *param_1,GmNat2 param_2,float param_3,float param_4, float param_5,float param_6);
    void __thiscall GenRenderCube(CPlugFileGen *this,CPlugFileGen *param_1,ulong param_2,ulong param_3);
    void __thiscall GenSLGradient(CPlugFileGen *this,CPlugFileGen *param_1,GmNat2 param_2,float param_3);
    void __thiscall GenSpecularCubeVect (CPlugFileGen *this,CPlugFileGen *param_1,GmVec3 *param_2,ulong param_3,float param_4);
    void __thiscall GenSpecularCubeVectRgb (CPlugFileGen *this,CPlugFileGen *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4, float param_5);
};

#endif // CPLUGFILEGEN_HPP
