#ifndef CFASTMAPTABLE_UNSIGNED_CHAR__HPP
#define CFASTMAPTABLE_UNSIGNED_CHAR__HPP

#include "typedefs.h"

struct CFastMapTable<unsigned_char> {
    byte _padding_0x0[4];
    void * field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1
    int field_0xc; // accesses: 4

    // Member Functions
    void __thiscall ClearAndShrink (CFastMapTable<unsigned_char> *this,CFastMapTable<unsigned_char> *param_1,ulong param_2);
};

#endif // CFASTMAPTABLE_UNSIGNED_CHAR__HPP
