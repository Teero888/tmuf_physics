#ifndef CCONTROLTEXT_HPP
#define CCONTROLTEXT_HPP

#include "typedefs.h"

struct CControlText {
    void** vftable; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CControlText(CControlText *this,CControlText *param_1);
    CPlugTreeGenText * __thiscall GetTextGenerator(CControlText *this,CControlText *param_1);
    ulong __thiscall GetLineCount(CControlText *this,CControlText *param_1);
};

#endif // CCONTROLTEXT_HPP
