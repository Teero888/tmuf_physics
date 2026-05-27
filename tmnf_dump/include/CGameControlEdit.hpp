#ifndef CGAMECONTROLEDIT_HPP
#define CGAMECONTROLEDIT_HPP

#include "typedefs.h"

struct CMwNod;

struct CGameControlEdit {
    void** vftable;
    byte _padding_0x4[16];
    CMwNod * field_0x14; // accesses: 2
    byte _padding_0x18[4];
    CMwNod * field_0x1c; // accesses: 5
    CMwNod * field_0x20; // accesses: 5
    CMwNod * field_0x24; // accesses: 4

    // Member Functions
    void __thiscall Create(CGameControlEdit *this,CDx9VertexBuffer *param_1);
};

#endif // CGAMECONTROLEDIT_HPP
