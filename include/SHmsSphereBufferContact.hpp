#ifndef SHMSSPHEREBUFFERCONTACT_HPP
#define SHMSSPHEREBUFFERCONTACT_HPP

#include "typedefs.h"

struct SHmsSphereBufferContact {
    byte _padding_0x0[16];
    undefined4 field_0x10; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall MergeAndAddToCollisions (void *this,SHmsSphereBufferContact *param_1,CHmsCollisionBuffer *param_2);
    void __thiscall SHmsSphereBufferContact(void *this,SHmsSphereBufferContact *param_1);
};

#endif // SHMSSPHEREBUFFERCONTACT_HPP
