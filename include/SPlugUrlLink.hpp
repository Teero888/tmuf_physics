#ifndef SPLUGURLLINK_HPP
#define SPLUGURLLINK_HPP

#include "typedefs.h"

struct SStringParam;

struct SPlugUrlLink {
    byte _padding_0x0[4];
    SStringParam * field_0x4; // accesses: 1

    // Member Functions
    void __thiscall Clear(void *this,TiXmlNode *param_1);
    void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall ~SPlugUrlLink(void *this,SPlugUrlLink *param_1);
};

#endif // SPLUGURLLINK_HPP
