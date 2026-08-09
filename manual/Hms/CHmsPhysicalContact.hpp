#ifndef CHMSPHYSICALCONTACT_HPP
#define CHMSPHYSICALCONTACT_HPP

#include "GmVec3.hpp"
#include <cstddef>
#include <cstdint>
#include <type_traits>

struct CHmsPhysicalContact {
    // Native pointer token. It remains 32-bit so this value record retains its
    // executable layout in the standalone 64-bit build.
    uint32_t m_corpus32;       // 0x00
    uint32_t m_collisionData;  // 0x04
    uint16_t m_materialId;     // 0x08
    uint16_t m_reserved0A;     // 0x0A
    GmVec3 m_localNormal;      // 0x0C
    GmVec3 m_localPoint;       // 0x18
    GmVec3 m_relativeSpeed;    // 0x24
    GmVec3 m_replacement;      // 0x30
    uint32_t m_isActive;       // 0x3C
    // The receiving side occupies +0x00..+0x08. These final fields describe
    // the opposite side of the same collision. Vehicle contact code uses the
    // receiving collision data to identify a wheel and the opposite material
    // as the ground/body material it struck.
    uint32_t m_otherCorpus32;       // 0x40
    uint32_t m_otherCollisionData;  // 0x44
    uint16_t m_otherMaterialId;     // 0x48
    uint16_t m_reserved4A;          // 0x4A
};

static_assert(sizeof(CHmsPhysicalContact) == 0x4C);
static_assert(offsetof(CHmsPhysicalContact, m_localNormal) == 0x0C);
static_assert(offsetof(CHmsPhysicalContact, m_localPoint) == 0x18);
static_assert(offsetof(CHmsPhysicalContact, m_relativeSpeed) == 0x24);
static_assert(offsetof(CHmsPhysicalContact, m_replacement) == 0x30);
static_assert(offsetof(CHmsPhysicalContact, m_isActive) == 0x3C);
static_assert(offsetof(CHmsPhysicalContact, m_otherCorpus32) == 0x40);
static_assert(offsetof(CHmsPhysicalContact, m_otherCollisionData) == 0x44);
static_assert(offsetof(CHmsPhysicalContact, m_otherMaterialId) == 0x48);
static_assert(std::is_standard_layout<CHmsPhysicalContact>::value);
static_assert(std::is_trivially_copyable<CHmsPhysicalContact>::value);

#endif // CHMSPHYSICALCONTACT_HPP
