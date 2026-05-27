#ifndef CFASTBUFFERWHEEL_CLASS_GMVEC2__HPP
#define CFASTBUFFERWHEEL_CLASS_GMVEC2__HPP

#include "typedefs.h"

struct CFastBufferWheel<class_GmVec2> {
    void** vftable; // accesses: 6
    int field_0x4; // accesses: 3
    uint field_0x8; // accesses: 6
    int field_0xc; // accesses: 12
    int field_0x10; // accesses: 3

    // Member Functions
    SHistoryPoint * __thiscall InsertNewElemFromStart (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2);
    int __thiscall Pull(void *this,CFastBufferWheel<float> *param_1,float *param_2);
    void __thiscall CFastBufferWheel<class_GmVec2> (void *this,CFastBufferWheel<class_GmVec2> *param_1,ulong param_2);
    void __thiscall Push(void *this,CFastBufferWheel<float> *param_1,float *param_2);
    void __thiscall SetCountLimit (void *this,CFastBufferWheel<float> *param_1,ulong param_2);
};

#endif // CFASTBUFFERWHEEL_CLASS_GMVEC2__HPP
