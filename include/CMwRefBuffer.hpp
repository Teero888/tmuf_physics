#ifndef CMWREFBUFFER_HPP
#define CMWREFBUFFER_HPP

#include "typedefs.h"

struct CMwRefBuffer {
    byte _padding_0x0[32];
    int field_0x20; // accesses: 2
    int field_0x24; // accesses: 3

    // Member Functions
    CMwNod * __thiscall GetFromId(CMwRefBuffer *this,CMwRefBuffer *param_1,CMwId *param_2);
    CMwNod * __thiscall GetFromIndex(CMwRefBuffer *this,CMwRefBuffer *param_1,ulong param_2);
    ulong __thiscall GetCount(CMwRefBuffer *this,CFastBuffer<class_CCrystalFace*> *param_1);
    void __thiscall AddTail (CMwRefBuffer *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,SFormat *param_2);
    void __thiscall CMwRefBuffer(CMwRefBuffer *this,CMwRefBuffer *param_1);
};

#endif // CMWREFBUFFER_HPP
