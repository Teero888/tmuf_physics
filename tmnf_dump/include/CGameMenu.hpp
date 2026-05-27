#ifndef CGAMEMENU_HPP
#define CGAMEMENU_HPP

#include "typedefs.h"

struct CGameMenu {
    void** vftable;
    byte _padding_0x4[120];
    CGameMenu * field_0x7c; // accesses: 1
    byte _padding_0x80[48];
    uint field_0xb0; // accesses: 1
    byte _final_padding[0x34]; // Total size: 0xe8

    // Member Functions
    void __thiscall SetGame(CGameMenu *this,CGameMenu *param_1,CGameApp *param_2);
};

#endif // CGAMEMENU_HPP
