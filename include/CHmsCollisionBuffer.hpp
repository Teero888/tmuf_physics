#ifndef CHMSCOLLISIONBUFFER_HPP
#define CHMSCOLLISIONBUFFER_HPP

#include "typedefs.h"

struct CHmsCollisionBuffer {

    // Member Functions
    GmCollision * __thiscall AddCollision(CHmsCollisionBuffer *this,CHmsCollisionBuffer *param_1);
    GmCollision * __thiscall GetCollision (CHmsCollisionBuffer *this,CHmsCollisionBuffer *param_1,ulong param_2);
    void __thiscall CHmsCollisionBuffer(CHmsCollisionBuffer *this,CHmsCollisionBuffer *param_1);
};

#endif // CHMSCOLLISIONBUFFER_HPP
