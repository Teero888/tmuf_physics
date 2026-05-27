#ifndef CPLUGFILETEXT_HPP
#define CPLUGFILETEXT_HPP

#include "typedefs.h"

struct CPlugFileText {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    undefined * field_0x18; // accesses: 1

    // Member Functions
    void __thiscall CPlugFileText(CPlugFileText *this,CPlugFileText *param_1);
};

#endif // CPLUGFILETEXT_HPP
