#ifndef CPLUGFILEPSH_HPP
#define CPLUGFILEPSH_HPP

#include "typedefs.h"

struct CPlugFilePsh {
    byte _padding_0x0[32];
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[164];
    undefined4 field_0xc8; // accesses: 1

    // Member Functions
    void __thiscall CPlugFilePsh(CPlugFilePsh *this,CPlugFilePsh *param_1);
};

#endif // CPLUGFILEPSH_HPP
