#ifndef CGAMEMENUFRAME_HPP
#define CGAMEMENUFRAME_HPP

#include "typedefs.h"

struct CGameMenuFrame {
    void** vftable;
    byte _padding_0x4[356];
    CGameMenuFrame * field_0x168; // accesses: 1
    byte _final_padding[0x1c]; // Total size: 0x188

    // Member Functions
    void __thiscall SetMenu(CGameMenuFrame *this,CGameMenuFrame *param_1,CGameMenu *param_2);
};

#endif // CGAMEMENUFRAME_HPP
