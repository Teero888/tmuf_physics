#ifndef CGAMECONTROLEDIT_HPP
#define CGAMECONTROLEDIT_HPP

#include "typedefs.h"

struct CMwNod;

struct CGameControlEdit {
    byte _padding_0x0[20];
    CMwNod * field_0x14; // accesses: 10
    byte _padding_0x18[4];
    int field_0x1c; // accesses: 5
    int field_0x20; // accesses: 5
    CMwNod * field_0x24; // accesses: 4

    // Member Functions
    void __thiscall Create(CGameControlEdit *this,CDx9VertexBuffer *param_1);
};

#endif // CGAMECONTROLEDIT_HPP
