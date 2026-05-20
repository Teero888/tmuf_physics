#ifndef CPLUGVISUALLINES_HPP
#define CPLUGVISUALLINES_HPP

#include "typedefs.h"

struct CPlugVisualLines {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 6
    undefined4 field_0x8; // accesses: 6
    undefined4 field_0xc; // accesses: 4
    undefined4 field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2

    // Member Functions
    void __thiscall AddLine (CPlugVisualLines *this,CPlugVisualLines2D *param_1,GmVec2 *param_2,GmVec2 *param_3, GxColor *param_4);
    void __thiscall CPlugVisualLines(CPlugVisualLines *this,CPlugVisualLines *param_1);
};

#endif // CPLUGVISUALLINES_HPP
