#ifndef CMWCMD_HPP
#define CMWCMD_HPP

#include "typedefs.h"

struct CMwCmd {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 3
    uint field_0x18; // accesses: 2

    // Member Functions
    void __thiscall CMwCmd(CMwCmd *this,CMwCmd *param_1);
    void __thiscall SetSchemeLocation(CMwCmd *this,CMwCmd *param_1,ulong param_2);
};

#endif // CMWCMD_HPP
