#ifndef CGAMEMANIALINKFILEENTRY_HPP
#define CGAMEMANIALINKFILEENTRY_HPP

#include "typedefs.h"

struct CGameManialinkFileEntry {
    void** vftable; // accesses: 1
    byte _padding_0x4[32];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 9
    undefined4 field_0x2c; // accesses: 9
    ulong field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 1
    undefined * field_0x38; // accesses: 1

    // Member Functions
    void __thiscall CGameManialinkFileEntry (CGameManialinkFileEntry *this,CGameManialinkFileEntry *param_1);
    void __thiscall SetFileType (CGameManialinkFileEntry *this,CGameManialinkFileEntry *param_1,CFastString *param_2);
    void __thiscall SetFolder (CGameManialinkFileEntry *this,CGameManialinkFileEntry *param_1,CFastStringInt *param_2);
};

#endif // CGAMEMANIALINKFILEENTRY_HPP
