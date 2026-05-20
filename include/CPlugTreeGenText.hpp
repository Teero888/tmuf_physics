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
    /* WARNING: Removing unreachable block (ram,0x00857074) */ /* WARNING: Removing unreachable block (ram,0x0085707a) */ /* WARNING: Removing unreachable block (ram,0x0085710d) */ /* WARNING: Removing unreachable block (ram,0x00857135) */ /* WARNING: Removing unreachable block (ram,0x0085715a) */ /* WARNING: Removing unreachable block (ram,0x00857179) */ /* WARNING: Removing unreachable block (ram,0x0085715e) */ /* WARNING: Removing unreachable block (ram,0x0085716d) */ /* WARNING: Removing unreachable block (ram,0x0085716f) */ /* WARNING: Removing unreachable block (ram,0x00857185) */ /* WARNING: Removing unreachable block (ram,0x008571ba) */ /* WARNING: Removing unreachable block (ram,0x008571c0) */ /* WARNING: Removing unreachable block (ram,0x008571da) */ /* WARNING: Removing unreachable block (ram,0x008571eb) */ /* WARNING: Removing unreachable block (ram,0x008571f6) */ /* WARNING: Removing unreachable block (ram,0x00857200) */ /* WARNING: Removing unreachable block (ram,0x0085720c) */ /* WARNING: Removing unreachable block (ram,0x00857215) */ /* WARNING: Removing unreachable block (ram,0x00857233) */ /* WARNING: Removing unreachable block (ram,0x00857248) */ /* WARNING: Removing unreachable block (ram,0x00857250) */ /* WARNING: Removing unreachable block (ram,0x00857266) */ /* WARNING: Removing unreachable block (ram,0x00857272) */ /* WARNING: Removing unreachable block (ram,0x00857284) */ /* WARNING: Removing unreachable block (ram,0x0085728d) */ /* WARNING: Removing unreachable block (ram,0x008572a1) */ /* WARNING: Removing unreachable block (ram,0x008572a4) */ /* WARNING: Removing unreachable block (ram,0x008572d2) */ /* WARNING: Removing unreachable block (ram,0x008572ea) */ /* WARNING: Removing unreachable block (ram,0x0085731e) */ /* WARNING: Removing unreachable block (ram,0x00857325) */ /* WARNING: Removing unreachable block (ram,0x0085733d) */ /* WARNING: Removing unreachable block (ram,0x00857346) */ /* WARNING: Removing unreachable block (ram,0x0085735c) */ /* WARNING: Removing unreachable block (ram,0x00857365) */ /* WARNING: Removing unreachable block (ram,0x00857375) */ /* WARNING: Removing unreachable block (ram,0x00857397) */ /* WARNING: Removing unreachable block (ram,0x008573b2) */ /* WARNING: Removing unreachable block (ram,0x0085739b) */ /* WARNING: Removing unreachable block (ram,0x008573ae) */ /* WARNING: Removing unreachable block (ram,0x008573b0) */ /* WARNING: Removing unreachable block (ram,0x008573c2) */ /* WARNING: Removing unreachable block (ram,0x008573e9) */ /* WARNING: Removing unreachable block (ram,0x008573ca) */ /* WARNING: Removing unreachable block (ram,0x008573e4) */ /* WARNING: Removing unreachable block (ram,0x008573cf) */ /* WARNING: Removing unreachable block (ram,0x008573d4) */ /* WARNING: Removing unreachable block (ram,0x008573f7) */ /* WARNING: Removing unreachable block (ram,0x00857400) */ /* WARNING: Removing unreachable block (ram,0x00857437) */ /* WARNING: Removing unreachable block (ram,0x00857448) */ /* WARNING: Removing unreachable block (ram,0x00857457) */ /* WARNING: Removing unreachable block (ram,0x0085745f) */ /* WARNING: Removing unreachable block (ram,0x00857462) */ /* WARNING: Removing unreachable block (ram,0x0085747c) */ /* WARNING: Removing unreachable block (ram,0x00857484) */ /* WARNING: Removing unreachable block (ram,0x0085748c) */ /* WARNING: Removing unreachable block (ram,0x0085748f) */ /* WARNING: Recovered jumptable eliminated as dead code */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall CPlugTreeGenText::InternalGenerateTreeMultiLine (CPlugTreeGenText *this,CPlugTreeGenText *param_1,CPlugTree *param_2,CUrlLinks *param_3, CEditionData **param_4,int param_5);
    ulong __thiscall ComputeLineCount(CPlugTreeGenText *this,CPlugTreeGenText *param_1);
};

#endif // CPLUGTREEGENTEXT_HPP
