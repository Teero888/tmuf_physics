#ifndef CGAMECONTROLSELECTION_HPP
#define CGAMECONTROLSELECTION_HPP

#include "typedefs.h"

struct CGameControlSelection {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 1
    byte _padding_0x28[12];
    undefined4 field_0x34; // accesses: 1

    // Member Functions
    void __thiscall CGameControlSelection (CGameControlSelection *this,CGameControlSelection *param_1);
};

#endif // CGAMECONTROLSELECTION_HPP
