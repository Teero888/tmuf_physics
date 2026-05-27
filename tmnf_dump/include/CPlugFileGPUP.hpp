#ifndef CPLUGFILEGPUP_HPP
#define CPLUGFILEGPUP_HPP

#include "typedefs.h"

struct CPlugFileGPUP {
    void** vftable; // accesses: 1
    byte _padding_0x4[184];
    undefined4 field_0xbc; // accesses: 1
    undefined4 field_0xc0; // accesses: 1
    undefined4 field_0xc4; // accesses: 1

    // Member Functions
    void __thiscall CPlugFileGPUP(CPlugFileGPUP *this,CPlugFileGPUP *param_1);
};

#endif // CPLUGFILEGPUP_HPP
