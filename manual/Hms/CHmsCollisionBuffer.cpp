#include "CHmsCollisionBuffer.hpp"

CHmsCollisionBuffer::CHmsCollisionBuffer() {
    m_collisions.SetSizeAtLeast(50u);
}

CHmsCollisionBuffer::CHmsCollisionBuffer(
    CFastBuffer<SHmsPhysicalCollision>* externalCollisions)
    : m_externalCollisions(externalCollisions) {}

CHmsCollisionBuffer::~CHmsCollisionBuffer() {}

GmCollision* CHmsCollisionBuffer::AddCollision() {
    CFastBuffer<SHmsPhysicalCollision>& collisions = Storage();
    const uint32_t index = collisions.m_count;
    collisions.SetSizeAtLeast(index + 1u);
    collisions[index] = SHmsPhysicalCollision{};
    ++collisions.m_count;
    return reinterpret_cast<GmCollision*>(&collisions[index].m_normal);
}

GmCollision* CHmsCollisionBuffer::GetCollision(uint32_t index) {
    return reinterpret_cast<GmCollision*>(&Storage()[index].m_normal);
}

uint32_t CHmsCollisionBuffer::GetCount() const {
    return Storage().GetCount();
}

SHmsPhysicalCollision& CHmsCollisionBuffer::GetPhysicalCollision(
    uint32_t index) {
    return Storage()[index];
}

CFastBuffer<SHmsPhysicalCollision>& CHmsCollisionBuffer::Storage() {
    return m_externalCollisions != nullptr
        ? *m_externalCollisions
        : m_collisions;
}

const CFastBuffer<SHmsPhysicalCollision>&
CHmsCollisionBuffer::Storage() const {
    return m_externalCollisions != nullptr
        ? *m_externalCollisions
        : m_collisions;
}
