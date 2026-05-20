#ifndef SHMSSPHEREBUFFERCONTACT_HPP
#define SHMSSPHEREBUFFERCONTACT_HPP

#include "typedefs.h"

struct SHmsSphereBufferContact {
    byte _padding_0x0[16];
    undefined4 field_0x10; // accesses: 1
    byte _padding_0x14[8];
    float field_0x1c; // accesses: 2
    float field_0x20; // accesses: 2
    float field_0x24; // accesses: 2
    byte _padding_0x28[16];
    int field_0x38; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall MergeAndAddToCollisions (void *this,SHmsSphereBufferContact *param_1,CHmsCollisionBuffer *param_2);
    void __thiscall SHmsSphereBufferContact(void *this,SHmsSphereBufferContact *param_1);
};

#endif // SHMSSPHEREBUFFERCONTACT_HPP
