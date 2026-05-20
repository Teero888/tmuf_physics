#ifndef CHMSCOLLISIONBUFFER_HPP
#define CHMSCOLLISIONBUFFER_HPP

#include "typedefs.h"

struct CSystemData;

struct CHmsCollisionBuffer {
    void** vftable; // accesses: 3
    byte _padding_0x4[68];
    int field_0x48; // accesses: 2
    byte _padding_0x4c[8];
    CSystemData * field_0x54; // accesses: 1
    int field_0x58; // accesses: 2

    // Member Functions
    GmCollision * __thiscall AddCollision(CHmsCollisionBuffer *this,CHmsCollisionBuffer *param_1);
    GmCollision * __thiscall GetCollision (CHmsCollisionBuffer *this,CHmsCollisionBuffer *param_1,ulong param_2);
    void __thiscall CHmsCollisionBuffer(CHmsCollisionBuffer *this,CHmsCollisionBuffer *param_1);
};

#endif // CHMSCOLLISIONBUFFER_HPP
