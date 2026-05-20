#ifndef GMMAT3_HPP
#define GMMAT3_HPP

#include "typedefs.h"

struct GmMat3 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 34
    undefined4 field_0x8; // accesses: 35
    undefined4 field_0xc; // accesses: 9
    undefined4 field_0x10; // accesses: 9
    undefined4 field_0x14; // accesses: 9
    undefined4 field_0x18; // accesses: 9
    undefined4 field_0x1c; // accesses: 9
    undefined4 field_0x20; // accesses: 9

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall SetDOVInverse(void *this,GmMat3 *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall IsIndirect(void *this,GmMat3 *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall IsOrthogonal(void *this,GmMat3 *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall IsOrthonormal(void *this,GmMat3 *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall OrthoNormalize(void *this,GmMat3 *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetBlend(void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetDOV(void *this,GmMat3 *param_1,GmVec3 *param_2,ulong param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetDOVandLeftV(void *this,GmMat3 *param_1,GmVec3 *param_2,GmVec3 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetDOVandUpV(void *this,GmMat3 *param_1,GmVec3 *param_2,GmVec3 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetUpVandDOV(void *this,GmMat3 *param_1,GmVec3 *param_2,GmVec3 *param_3);
    ulong __thiscall IsNearlyEqual(void *this,GmVec2 *param_1,GmVec2 *param_2);
    void __thiscall ArchiveGmMat3(void *this,GmMat3 *param_1,CClassicArchive *param_2);
    void __thiscall GetLine(void *this,GmMat3 *param_1,ulong param_2,GmVec3 *param_3);
    void __thiscall Inverse(void *this,GmIso4 *param_1);
    void __thiscall LeftMult(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall MultTranspose(void *this,GmMat3 *param_1,GmMat3 *param_2);
    void __thiscall RotateX(void *this,GmIso4 *param_1,float param_2);
    void __thiscall RotateY(void *this,GmIso4 *param_1,float param_2);
    void __thiscall RotateZ(void *this,GmIso4 *param_1,float param_2);
    void __thiscall SetIdentity(void *this,GmMat43 *param_1);
    void __thiscall SetLine(void *this,GmMat3 *param_1,ulong param_2,GmVec3 *param_3);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
    void __thiscall SetRotateQuarterY(void *this,GmMat3 *param_1,ulong param_2);
    void __thiscall SetTranspose(void *this,GmMat2 *param_1,GmMat2 *param_2);
    void __thiscall Transpose(void *this,GmMat4 *param_1);
};

#endif // GMMAT3_HPP
