#ifndef GMISO3_HPP
#define GMISO3_HPP

#include "typedefs.h"

struct GmIso3 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 3
    undefined4 field_0x10; // accesses: 6
    undefined4 field_0x14; // accesses: 6

    // Member Functions
    void __thiscall ArchiveGmIso3(void *this,GmIso3 *param_1,CClassicArchive *param_2);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall MultInverse(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetIdentity(void *this,GmMat43 *param_1);
    void __thiscall SetInverse(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
};

#endif // GMISO3_HPP
