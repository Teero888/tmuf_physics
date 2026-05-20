#ifndef CPLUGFILEGEN_HPP
#define CPLUGFILEGEN_HPP

#include "typedefs.h"

struct CMwCmdBufferCore;
struct CPlugFileImg;
struct GxColor;

struct CPlugFileGen {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 6
    undefined4 field_0x8; // accesses: 7
    undefined4 field_0xc; // accesses: 4
    byte _padding_0x10[8];
    undefined4 field_0x18; // accesses: 19
    undefined4 field_0x1c; // accesses: 19
    int field_0x20; // accesses: 1
    uint field_0x24; // accesses: 32
    undefined1 * field_0x28; // accesses: 9
    byte _padding_0x2c[8];
    undefined4 field_0x34; // accesses: 7

    // Member Functions
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall GenChecker(CPlugFileGen *this,CPlugFileGen *param_1,ulong param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GenCubeNormals (CPlugFileGen *this,CPlugFileGen *param_1,ulong param_2,ulong param_3,GxColor *param_4, GxColor *param_5);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GenSLGradient(CPlugFileGen *this,CPlugFileGen *param_1,GmNat2 param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GenSpecularCubeVect (CPlugFileGen *this,CPlugFileGen *param_1,GmVec3 *param_2,ulong param_3,float param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GenSpecularCubeVectRgb (CPlugFileGen *this,CPlugFileGen *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4, float param_5);
    /* WARNING: Removing unreachable block (ram,0x00877bd3) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CPlugFileGen::GenHueGradient (CPlugFileGen *this,CPlugFileGen *param_1,GmNat2 param_2,float param_3,float param_4, float param_5,float param_6);
    void __thiscall CPlugFileGen(CPlugFileGen *this,CPlugFileGen *param_1);
    void __thiscall GenRenderCube(CPlugFileGen *this,CPlugFileGen *param_1,ulong param_2,ulong param_3);
};

#endif // CPLUGFILEGEN_HPP
