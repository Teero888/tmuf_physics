#ifndef CPLUGTREEGENTEXT_HPP
#define CPLUGTREEGENTEXT_HPP

#include "typedefs.h"

struct CPlugFont;

struct CPlugTreeGenText {
    void** vftable;
    byte _padding_0x4[56];
    int field_0x3c; // accesses: 1
    float field_0x40; // accesses: 2
    float field_0x44; // accesses: 3
    int field_0x48; // accesses: 1
    uint field_0x4c; // accesses: 2
    uint field_0x50; // accesses: 1
    CPlugFont * field_0x54; // accesses: 4
    byte _final_padding[0x18]; // Total size: 0x70

    // Member Functions
    ulong __thiscall ComputeLineCount(CPlugTreeGenText *this,CPlugTreeGenText *param_1);
    ulong __thiscall InternalGenerateTreeMultiLine (CPlugTreeGenText *this,CPlugTreeGenText *param_1,CPlugTree *param_2,CUrlLinks *param_3, CEditionData **param_4,int param_5);
};

#endif // CPLUGTREEGENTEXT_HPP
