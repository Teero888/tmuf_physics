#ifndef CPLUGFILEVSH_HPP
#define CPLUGFILEVSH_HPP

#include "typedefs.h"

struct CPlugFileVsh {
    void** vftable; // accesses: 1
    byte _padding_0x4[28];
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[184];
    undefined4 field_0xdc; // accesses: 1
    byte _padding_0xe0[4];
    undefined4 field_0xe4; // accesses: 1
    undefined4 field_0xe8; // accesses: 1
    undefined * field_0xec; // accesses: 1

    // Member Functions
    void __thiscall CPlugFileVsh(CPlugFileVsh *this,CPlugFileVsh *param_1);
};

#endif // CPLUGFILEVSH_HPP
