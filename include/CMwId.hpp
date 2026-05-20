#ifndef CMWID_HPP
#define CMWID_HPP

#include "typedefs.h"

struct CMwId {
    void** vftable; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetLocalName(void *this,CMwId *param_1,CFastStringInt *param_2);
    CFastString __thiscall GetName(void *this,CTrackManiaEditorIconPage *param_1);
    CMwId __cdecl CreateFromLocalIndex(ulong param_1);
    CMwId __cdecl CreateFromLocalName(char *param_1);
    void __cdecl StaticInit(void);
    void __thiscall CMwId(void *this,CMwId *param_1);
    void __thiscall GetString(void *this,CMwStatsValue *param_1,CFastString *param_2);
};

#endif // CMWID_HPP
