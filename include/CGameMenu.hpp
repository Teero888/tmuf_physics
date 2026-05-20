#ifndef CGAMEMENU_HPP
#define CGAMEMENU_HPP

#include "typedefs.h"

struct CGameMenu {
    byte _padding_0x0[124];
    CGameMenu * field_0x7c; // accesses: 1
    byte _padding_0x80[48];
    uint field_0xb0; // accesses: 1

    // Member Functions
    void __thiscall SetGame(CGameMenu *this,CGameMenu *param_1,CGameApp *param_2);
};

#endif // CGAMEMENU_HPP
