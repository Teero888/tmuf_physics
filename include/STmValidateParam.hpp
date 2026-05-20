#ifndef STMVALIDATEPARAM_HPP
#define STMVALIDATEPARAM_HPP

#include "typedefs.h"

struct CMwNod;

struct STmValidateParam {
    CMwNod * field_0x0; // accesses: 8
    STmValidateParam * field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2

    // Member Functions
    void __thiscall Clear(void *this,TiXmlNode *param_1);
    void __thiscall STmValidateParam(void *this,STmValidateParam *param_1);
};

#endif // STMVALIDATEPARAM_HPP
