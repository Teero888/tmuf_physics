#ifndef CGAMECTNCHAPTER_HPP
#define CGAMECTNCHAPTER_HPP

#include "typedefs.h"

struct CGameCtnChapter {
    void** vftable;
    byte _final_padding[0x104]; // Total size: 0x108

    // Member Functions
    CPlugMusic * __thiscall LoadNextMusic (CGameCtnChapter *this,CGameCtnChapter *param_1,EDecorationMusic param_2);
};

#endif // CGAMECTNCHAPTER_HPP
