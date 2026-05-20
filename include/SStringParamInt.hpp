#ifndef SSTRINGPARAMINT_HPP
#define SSTRINGPARAMINT_HPP

#include "typedefs.h"

struct CFastStringInt;

struct SStringParamInt {
    void** vftable; // accesses: 4
    CFastStringInt * field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1

    // Member Functions
    void __thiscall SStringParamInt(void *this,SStringParamInt *param_1,wchar_t *param_2);
};

#endif // SSTRINGPARAMINT_HPP
