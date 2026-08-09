#ifndef SHMSPHYSICALCOLLISION_HPP
#define SHMSPHYSICALCOLLISION_HPP

#include "GmVec3.hpp"
#include <cstdint>

struct SHmsPhysicalCollision {
public:
    class CHmsCorpus* m_body2; // 0x00
    uint32_t m_value04;        // 0x04
    class CHmsCorpus* m_body1; // 0x08
    uint32_t m_value0C;        // 0x0C
    // The 0x10 tail is layout-compatible with GmCollision. Earlier manual
    // names called both of the first vectors normals; their actual roles are
    // the penetration replacement, contact normal, and contact point.
    GmVec3 m_normal;           // 0x10: replacement (GmCollision::m_vec1)
    GmVec3 m_pos;              // 0x1C: contact normal (GmCollision::m_vec2)
    GmVec3 m_value28;          // 0x28: contact point (GmCollision::m_vec3)
    uint16_t m_matId1;         // 0x34
    uint16_t m_matId2;         // 0x36
    uint32_t m_field38;        // 0x38
    uint32_t m_field3c;        // 0x3C
    uint32_t m_field40;        // 0x40
    uint32_t m_field44;        // 0x44
    uint32_t* m_ptr48;         // 0x48

    GmVec3& Replacement() { return m_normal; }
    const GmVec3& Replacement() const { return m_normal; }
    GmVec3& ContactNormal() { return m_pos; }
    const GmVec3& ContactNormal() const { return m_pos; }
    GmVec3& ContactPoint() { return m_value28; }
    const GmVec3& ContactPoint() const { return m_value28; }
};

#endif // SHMSPHYSICALCOLLISION_HPP
