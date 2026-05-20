#ifndef CCONTROLTEXT_HPP
#define CCONTROLTEXT_HPP

#include "typedefs.h"

struct CControlText {
    byte _padding_0x0[288];
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    undefined4 field_0x128; // accesses: 1
    int field_0x12c; // accesses: 4

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CControlText(CControlText *this,CControlText *param_1);
    CPlugTreeGenText * __thiscall GetTextGenerator(CControlText *this,CControlText *param_1);
    ulong __thiscall GetLineCount(CControlText *this,CControlText *param_1);
};

#endif // CCONTROLTEXT_HPP
