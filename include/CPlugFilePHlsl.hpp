#ifndef CPLUGFILEPHLSL_HPP
#define CPLUGFILEPHLSL_HPP

#include "typedefs.h"

struct CPlugFilePHlsl {
    byte _padding_0x0[16];
    int field_0x10; // accesses: 1
    uint field_0x14; // accesses: 3
    byte _padding_0x18[8];
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[164];
    undefined4 field_0xc8; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ApplyFidParameter_Crypted (CPlugFilePHlsl *this,CPlugFilePHlsl *param_1,SParam_Id *param_2);
    void __cdecl LoadCommonPHlsl(void);
    void __thiscall CPlugFilePHlsl(CPlugFilePHlsl *this,CPlugFilePHlsl *param_1);
};

#endif // CPLUGFILEPHLSL_HPP
