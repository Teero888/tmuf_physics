#ifndef CHMSPHYSICALCONTACT_HPP
#define CHMSPHYSICALCONTACT_HPP

#include "GmVec3.hpp"
#include <cstdint>

struct CHmsPhysicalContact {
    uint8_t m_padding[36];     // 0x00
    GmVec3 m_contactPoint;     // 0x24
    GmVec3 m_normal;           // 0x30
    uint32_t m_isActive;       // 0x3C
};

#endif // CHMSPHYSICALCONTACT_HPP
