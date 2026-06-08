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
    GmVec3 m_normal;           // 0x10, 0x14, 0x18
    GmVec3 m_pos;              // 0x1C, 0x20, 0x24
    GmVec3 m_value28;          // 0x28, 0x2C, 0x30
    uint16_t m_matId1;         // 0x34
    uint16_t m_matId2;         // 0x36
    uint32_t m_field38;        // 0x38
    uint32_t m_field3c;        // 0x3C
    uint32_t m_field40;        // 0x40
    uint32_t m_field44;        // 0x44
    uint32_t* m_ptr48;         // 0x48
};

#endif // SHMSPHYSICALCOLLISION_HPP
