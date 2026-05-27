#ifndef CPLUGVISUALINDEXEDLINES_HPP
#define CPLUGVISUALINDEXEDLINES_HPP

#include "typedefs.h"

struct CPlugVisualIndexedLines {
    void** vftable; // accesses: 1
    byte _padding_0x4[148];
    int field_0x98; // accesses: 2
    undefined4 field_0x9c; // accesses: 1

    // Member Functions
    void __thiscall AddNewBox (CPlugVisualIndexedLines *this,CPlugVisualIndexedLines *param_1,GmBoxOriented *param_2, GxColor *param_3);
    void __thiscall AddNewLine (CPlugVisualIndexedLines *this,CPlugVisualIndexedLines *param_1,ushort param_2, GmVec3 *param_3,GxColor *param_4,float param_5,float param_6);
    void __thiscall CPlugVisualIndexedLines (CPlugVisualIndexedLines *this,CPlugVisualIndexedLines *param_1);
};

#endif // CPLUGVISUALINDEXEDLINES_HPP
