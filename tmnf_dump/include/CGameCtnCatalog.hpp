#ifndef CGAMECTNCATALOG_HPP
#define CGAMECTNCATALOG_HPP

#include "typedefs.h"

struct CGameCtnCatalog {
    void** vftable;
    byte _final_padding[0x2c]; // Total size: 0x30

    // Member Functions
    CGameCtnChapter * __thiscall GetChapter(CGameCtnCatalog *this,CGameCtnChallenge *param_1);
};

#endif // CGAMECTNCATALOG_HPP
