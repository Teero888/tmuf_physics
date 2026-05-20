#ifndef CGAMECTNCHAPTER_HPP
#define CGAMECTNCHAPTER_HPP

#include "typedefs.h"

struct CMwNod;

struct CGameCtnChapter {
    byte _padding_0x0[12];
    undefined4 field_0xc; // accesses: 4
    byte _padding_0x10[8];
    CMwNod * field_0x18; // accesses: 4
    byte _padding_0x1c[8];
    int field_0x24; // accesses: 1

    // Member Functions
    CPlugMusic * __thiscall LoadNextMusic (CGameCtnChapter *this,CGameCtnChapter *param_1,EDecorationMusic param_2);
};

#endif // CGAMECTNCHAPTER_HPP
