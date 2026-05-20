#ifndef STMVALIDATEPARAM_HPP
#define STMVALIDATEPARAM_HPP

#include "typedefs.h"

struct STmValidateParam {
    byte _padding_0x0[232];
    uint field_0xe8; // accesses: 2
    byte _padding_0xec[4];
    uint field_0xf0; // accesses: 2
    byte _padding_0xf4[24];
    undefined4 field_0x10c; // accesses: 1
    byte _padding_0x110[96];
    undefined4 field_0x170; // accesses: 1

    // Member Functions
    void __thiscall Clear(void *this,TiXmlNode *param_1);
    void __thiscall STmValidateParam(void *this,STmValidateParam *param_1);
};

#endif // STMVALIDATEPARAM_HPP
