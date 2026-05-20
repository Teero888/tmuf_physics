#ifndef CGAMECONTROLCARD_HPP
#define CGAMECONTROLCARD_HPP

#include "typedefs.h"

struct CGameControlCard {
    byte _padding_0x0[252];
    uint field_0xfc; // accesses: 3
    byte _padding_0x100[124];
    undefined4 field_0x17c; // accesses: 1
    byte _padding_0x180[60];
    int * field_0x1bc; // accesses: 3
    byte _padding_0x1c0[8];
    CGameControlCard * field_0x1c8; // accesses: 1

    // Member Functions
    void __thiscall CardSetReadOnly(CGameControlCard *this,CGameControlCard *param_1,int param_2);
    void __thiscall ForceReconfig(CGameControlCard *this,CGameControlCard *param_1);
};

#endif // CGAMECONTROLCARD_HPP
