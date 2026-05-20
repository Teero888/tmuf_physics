#ifndef SGRIDADDCHILDCONTEXT_HPP
#define SGRIDADDCHILDCONTEXT_HPP

#include "typedefs.h"

struct SGridAddChildContext {
    byte _padding_0x0[504];
    code * field_0x1f8; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CControlBase * __thiscall AddChild (void *this,SGridAddChildContext *param_1,char *param_2,CMwNod *param_3,char *param_4, ulong param_5);
};

#endif // SGRIDADDCHILDCONTEXT_HPP
