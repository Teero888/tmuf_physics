#ifndef GMCOLLISION_HPP
#define GMCOLLISION_HPP


#include "GmVec3.hpp"

class GmCollision {
public:
    GmVec3 m_vec1;          // 0x00 - 0x0B
    GmVec3 m_vec2;          // 0x0C - 0x17
    GmVec3 m_vec3;          // 0x18 - 0x23 (Untouched in Neg, acts as the 12-byte padding)
    uint16_t m_id1;   // 0x24 - 0x25
    uint16_t m_id2;   // 0x26 - 0x27
    float m_unknown_0x28;   // 0x28 - 0x2B (Unknown 4 bytes to align next vector to 0x2C)
    GmVec3 m_vec4;          // 0x2C - 0x37

    // Reverses the collision geometry/direction
    void Neg();
};

class CGmCollisionBuffer {
public:
    virtual GmCollision* AddCollision() = 0;
    virtual unsigned int GetCount() const = 0;
    virtual GmCollision* GetCollision(unsigned int index) = 0;
};

#endif // GMCOLLISION_HPP