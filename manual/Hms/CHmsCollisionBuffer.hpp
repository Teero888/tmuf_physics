#ifndef CHMSCOLLISIONBUFFER_HPP
#define CHMSCOLLISIONBUFFER_HPP

#include "GmCollision.hpp"
#include <cstdint>

class CHmsCollisionBuffer {
public:
    virtual ~CHmsCollisionBuffer(); // 0x00

    // Member Functions
    virtual GmCollision* AddCollision();
    virtual GmCollision* GetCollision(uint32_t index);
};

#endif // CHMSCOLLISIONBUFFER_HPP
