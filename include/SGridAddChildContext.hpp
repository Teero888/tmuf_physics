#ifndef SGRIDADDCHILDCONTEXT_HPP
#define SGRIDADDCHILDCONTEXT_HPP

#include "typedefs.h"

struct CControlContainer;
struct CControlStyle;

struct SGridAddChildContext {
    void** vftable; // accesses: 3
    CControlStyle * field_0x4; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CControlBase * __thiscall AddChild (void *this,SGridAddChildContext *param_1,char *param_2,CMwNod *param_3,char *param_4, ulong param_5);
};

#endif // SGRIDADDCHILDCONTEXT_HPP
