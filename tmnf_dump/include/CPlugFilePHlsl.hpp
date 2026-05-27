#ifndef CPLUGFILEPHLSL_HPP
#define CPLUGFILEPHLSL_HPP

#include "typedefs.h"

struct CPlugFilePHlsl {
    void** vftable; // accesses: 1
    byte _padding_0x4[28];
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[164];
    undefined4 field_0xc8; // accesses: 1

    // Member Functions
    void __cdecl LoadCommonPHlsl(void);
    void __thiscall ApplyFidParameter_Crypted (CPlugFilePHlsl *this,CPlugFilePHlsl *param_1,SParam_Id *param_2);
    void __thiscall CPlugFilePHlsl(CPlugFilePHlsl *this,CPlugFilePHlsl *param_1);
};

#endif // CPLUGFILEPHLSL_HPP
