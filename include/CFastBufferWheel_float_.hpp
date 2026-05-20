#ifndef CFASTBUFFERWHEEL_FLOAT__HPP
#define CFASTBUFFERWHEEL_FLOAT__HPP

#include "typedefs.h"

struct ulong;

struct CFastBufferWheel<float> {
    void** vftable; // accesses: 5
    int field_0x4; // accesses: 14
    ulong field_0x8; // accesses: 12
    undefined4 field_0xc; // accesses: 17
    undefined4 field_0x10; // accesses: 3

    // Member Functions
    SHistoryPoint * __thiscall InsertNewElemFromStart (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2);
    int __thiscall Pull(void *this,CFastBufferWheel<float> *param_1,float *param_2);
    void __thiscall CFastBufferWheel<float>(void *this,CFastBufferWheel<float> *param_1);
    void __thiscall CopyFromWheel (void *this, CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_1, CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_2);
    void __thiscall Push(void *this,CFastBufferWheel<float> *param_1,float *param_2);
    void __thiscall SetCountLimit(void *this,CFastBufferWheel<float> *param_1,ulong param_2);
};

#endif // CFASTBUFFERWHEEL_FLOAT__HPP
