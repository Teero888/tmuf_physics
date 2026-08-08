#include "CHmsCollisionBuffer.hpp"

CHmsCollisionBuffer::CHmsCollisionBuffer() {
    m_collisions.SetSizeAtLeast(50u);
}

CHmsCollisionBuffer::~CHmsCollisionBuffer() {}

GmCollision* CHmsCollisionBuffer::AddCollision() {
    const uint32_t index = m_collisions.m_count;
    m_collisions.SetSizeAtLeast(index + 1u);
    ++m_collisions.m_count;
    return reinterpret_cast<GmCollision*>(&m_collisions[index].m_normal);
}

GmCollision* CHmsCollisionBuffer::GetCollision(uint32_t index) {
    return reinterpret_cast<GmCollision*>(&m_collisions[index].m_normal);
}

uint32_t CHmsCollisionBuffer::GetCount() const {
    return m_collisions.GetCount();
}
