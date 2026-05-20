#ifndef CGAMEMENUFRAME_HPP
#define CGAMEMENUFRAME_HPP

#include "typedefs.h"

struct CGameMenuFrame {
    byte _padding_0x0[360];
    CGameMenuFrame * field_0x168; // accesses: 1

    // Member Functions
    void __thiscall SetMenu(CGameMenuFrame *this,CGameMenuFrame *param_1,CGameMenu *param_2);
};

#endif // CGAMEMENUFRAME_HPP
