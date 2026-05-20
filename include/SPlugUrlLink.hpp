#ifndef SPLUGURLLINK_HPP
#define SPLUGURLLINK_HPP

#include "typedefs.h"

struct SPlugUrlLink {
    void** vftable; // accesses: 3
    undefined2 * field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 1
    undefined * field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2

    // Member Functions
    void __thiscall Clear(void *this,TiXmlNode *param_1);
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall ~SPlugUrlLink(void *this,SPlugUrlLink *param_1);
};

#endif // SPLUGURLLINK_HPP
