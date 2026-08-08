#ifndef CHMSCOLLISIONBUFFER_HPP
#define CHMSCOLLISIONBUFFER_HPP

#include "GmCollision.hpp"
#include "SHmsPhysicalCollision.hpp"
#include "CFastBuffer.hpp"
#include <cstdint>

class CHmsCollisionBuffer : public CGmCollisionBuffer {
public:
    CHmsCollisionBuffer();
    ~CHmsCollisionBuffer();

    GmCollision* AddCollision() override;
    GmCollision* GetCollision(uint32_t index) override;
    uint32_t GetCount() const override;

    // Native offset +0x04 on 32-bit builds. The executable preallocates space
    // for 50 physical contacts in the constructor.
    CFastBuffer<SHmsPhysicalCollision> m_collisions;
};

#endif // CHMSCOLLISIONBUFFER_HPP
