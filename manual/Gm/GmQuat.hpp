#ifndef GMQUAT_HPP
#define GMQUAT_HPP

#include "typedefs.h"

struct GmQuat {
    float field_0x0; // accesses: 13
    float field_0x4; // accesses: 14
    float field_0x8; // accesses: 15
    float field_0xc; // accesses: 15

    // Member Functions
    void __thiscall ArchiveGmQuat(void *this,GmQuat *param_1,CClassicArchive *param_2);
    void __thiscall ArchiveGmQuatCompact(void *this,GmQuat *param_1,CClassicArchive *param_2);
    void __thiscall ComputeSquad (void *this,GmQuat *param_1,GmQuat *param_2,GmQuat *param_3,GmQuat *param_4, GmQuat *param_5,float param_6);
    void __thiscall GetRotation(void *this,GmQuat *param_1,float *param_2,GmVec3 *param_3);
    void __thiscall GetYawPitchRoll(void *this,GmQuat *param_1,float *param_2,float *param_3,float *param_4);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall Normalize(void *this,GmQuat *param_1);
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetIdentity(void *this,GmMat43 *param_1);
    void __thiscall SetInverse(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
    void __thiscall SetRotation(void *this,GmMat2 *param_1,float param_2);
    void __thiscall SetSlerp(void *this,GmQuat *param_1,GmQuat param_2,GmQuat *param_3,float param_4);
    void __thiscall SetSquad(void *this,GmQuat *param_1,GmQuat param_2,GmQuat *param_3,GmQuat *param_4, GmQuat *param_5,float param_6);
    void __thiscall SetYawPitchRoll(void *this,GmQuat *param_1,float param_2,float param_3,float param_4);
};

#endif // GMQUAT_HPP
