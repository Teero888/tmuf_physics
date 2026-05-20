#ifndef GMMAT43_HPP
#define GMMAT43_HPP

#include "typedefs.h"

struct GmMat43 {
    void** vftable; // accesses: 2
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2

    // Member Functions
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetIdentity(void *this,GmMat43 *param_1);
};

#endif // GMMAT43_HPP
