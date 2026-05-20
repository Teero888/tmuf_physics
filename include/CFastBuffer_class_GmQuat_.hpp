#ifndef CFASTBUFFER_CLASS_GMQUAT__HPP
#define CFASTBUFFER_CLASS_GMQUAT__HPP

#include "typedefs.h"

struct CFastBuffer<class_GmQuat> {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2

    // Member Functions
    void __thiscall Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
    void __thiscall RemoveAt (void *this,CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *param_1, ulong param_2,ulong param_3);
};

#endif // CFASTBUFFER_CLASS_GMQUAT__HPP
