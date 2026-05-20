#ifndef GMISO4_HPP
#define GMISO4_HPP

#include "typedefs.h"

struct CControlContainer;

struct GmIso4 {
    void** vftable; // accesses: 35
    float field_0x4; // accesses: 30
    float field_0x8; // accesses: 30
    float field_0xc; // accesses: 18
    GmIso4 * field_0x10; // accesses: 16
    float field_0x14; // accesses: 16
    float field_0x18; // accesses: 15
    float field_0x1c; // accesses: 15
    GmIso4 * field_0x20; // accesses: 15
    float field_0x24; // accesses: 24
    float field_0x28; // accesses: 27
    float field_0x2c; // accesses: 24
    byte _padding_0x30[8];
    GmIso4 * field_0x38; // accesses: 1
    byte _padding_0x3c[48];
    int field_0x6c; // accesses: 2
    byte _padding_0x70[44];
    uint field_0x9c; // accesses: 2

    // Member Functions
    CSystemFidsFolder * __thiscall GetDir(void *this,CSystemDataFolders *param_1,ulong param_2,ulong param_3);
    ulong __thiscall IsNearlyEqual(void *this,GmVec2 *param_1,GmVec2 *param_2);
    void __thiscall ArchiveGmIso4(void *this,GmIso4 *param_1,CClassicArchive *param_2);
    void __thiscall GetPlaneEq(void *this,GmIso4 *param_1,ulong param_2,GmVec4 *param_3);
    void __thiscall GetUp(void *this,GmIso4 *param_1,GmVec3 *param_2);
    void __thiscall Inverse(void *this,GmIso4 *param_1);
    void __thiscall LeftMult(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall MultInverse(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall NUGetIso4AndScale(void *this,GmIso4 *param_1,GmIso4 *param_2,GmVec3 *param_3);
    void __thiscall NUScaleSetInverse(void *this,GmIso4 *param_1,GmIso4 *param_2);
    void __thiscall RotateX(void *this,GmIso4 *param_1,float param_2);
    void __thiscall RotateY(void *this,GmIso4 *param_1,float param_2);
    void __thiscall RotateZ(void *this,GmIso4 *param_1,float param_2);
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetBlend(void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4);
    void __thiscall SetColumn(void *this,GmIso4 *param_1,ulong param_2,GmVec4 *param_3);
    void __thiscall SetIdentity(void *this,GmMat43 *param_1);
    void __thiscall SetInverse(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2);
    void __thiscall SetLookAt(void *this,GmIso4 *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
    void __thiscall SetNUScaleTrans(void *this,GmIso4 *param_1,GmVec3 *param_2,GmVec3 *param_3);
    void __thiscall SetRotation(void *this,GmMat2 *param_1,float param_2);
    void __thiscall SetTranslation(void *this,GmIso4 *param_1,GmVec3 *param_2);
    void __thiscall SetUScaleTrans(void *this,GmIso4 *param_1,float param_2,GmVec3 *param_3);
    void __thiscall SetXY(void *this,GmMat4 *param_1,GmIso3 *param_2);
    void __thiscall SymmetryPlane(void *this,GmIso4 *param_1,GmVec4 *param_2);
    void __thiscall UScaleSetInverse(void *this,GmIso4 *param_1,GmIso4 *param_2);
};

#endif // GMISO4_HPP
