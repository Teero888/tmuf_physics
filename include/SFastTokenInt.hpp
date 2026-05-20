#ifndef SFASTTOKENINT_HPP
#define SFASTTOKENINT_HPP

#include "typedefs.h"

struct SFastTokenInt {
    void** vftable; // accesses: 1
    undefined4 field_0x4; // accesses: 2
    undefined * field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined * field_0x1c; // accesses: 2

    // Member Functions
    void __thiscall SFastTokenInt(void *this,SFastTokenInt *param_1,char *param_2,int param_3);
    void __thiscall ~SFastTokenInt(void *this,SFastTokenInt *param_1);
};

#endif // SFASTTOKENINT_HPP
