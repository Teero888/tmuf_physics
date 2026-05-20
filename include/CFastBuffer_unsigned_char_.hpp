#ifndef CFASTBUFFER_UNSIGNED_CHAR__HPP
#define CFASTBUFFER_UNSIGNED_CHAR__HPP

#include "typedefs.h"

struct ulong;

struct CFastBuffer<unsigned_char> {
    void** vftable; // accesses: 5
    void * field_0x4; // accesses: 4
    uint field_0x8; // accesses: 1

    // Member Functions
    void __thiscall RemoveAt (void *this,CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *param_1, ulong param_2,ulong param_3);
    void __thiscall SetSizeAtLeast (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2);
};

#endif // CFASTBUFFER_UNSIGNED_CHAR__HPP
