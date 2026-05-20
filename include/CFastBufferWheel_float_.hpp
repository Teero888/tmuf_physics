#ifndef CFASTBUFFERWHEEL_FLOAT__HPP
#define CFASTBUFFERWHEEL_FLOAT__HPP

#include "typedefs.h"

struct CFastBufferWheel<float> {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    byte _padding_0x8[4];
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1

    // Member Functions
    SHistoryPoint * __thiscall InsertNewElemFromStart (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2);
    int __thiscall Pull(void *this,CFastBufferWheel<float> *param_1,float *param_2);
    void __thiscall CFastBufferWheel<float>(void *this,CFastBufferWheel<float> *param_1);
    void __thiscall CopyFromWheel (void *this, CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_1, CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_2);
    void __thiscall Push(void *this,CFastBufferWheel<float> *param_1,float *param_2);
    void __thiscall SetCountLimit(void *this,CFastBufferWheel<float> *param_1,ulong param_2);
};

#endif // CFASTBUFFERWHEEL_FLOAT__HPP
