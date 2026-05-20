#ifndef CFASTBUFFERWHEEL_UNSIGNED_LONG__HPP
#define CFASTBUFFERWHEEL_UNSIGNED_LONG__HPP

#include "typedefs.h"

struct ulong;

struct CFastBufferWheel<unsigned_long> {
    void** vftable; // accesses: 4
    int field_0x4; // accesses: 2
    ulong field_0x8; // accesses: 4
    undefined4 field_0xc; // accesses: 3
    ulong field_0x10; // accesses: 2

    // Member Functions
    GmVec3 * __thiscall Tail(void *this,CFastBufferWheel<class_GmVec3> *param_1);
    int __thiscall Pull(void *this,CFastBufferWheel<float> *param_1,float *param_2);
    void __thiscall CFastBufferWheel<unsigned_long> (void *this,CFastBufferWheel<unsigned_long> *param_1,ulong param_2);
    void __thiscall CopyFromWheel (void *this, CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_1, CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_2);
    void __thiscall SetCountLimit (void *this,CFastBufferWheel<float> *param_1,ulong param_2);
};

#endif // CFASTBUFFERWHEEL_UNSIGNED_LONG__HPP
