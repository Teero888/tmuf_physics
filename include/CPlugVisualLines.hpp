#ifndef CPLUGVISUALLINES_HPP
#define CPLUGVISUALLINES_HPP

#include "typedefs.h"

struct CPlugVisualLines {
    void** vftable; // accesses: 1
    byte _final_padding[0x94]; // Total size: 0x98

    // Member Functions
    void __thiscall AddLine (CPlugVisualLines *this,CPlugVisualLines2D *param_1,GmVec2 *param_2,GmVec2 *param_3, GxColor *param_4);
    void __thiscall CPlugVisualLines(CPlugVisualLines *this,CPlugVisualLines *param_1);
};

#endif // CPLUGVISUALLINES_HPP
