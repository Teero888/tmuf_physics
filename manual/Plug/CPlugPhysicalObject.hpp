#ifndef CPLUGPHYSICALOBJECT_HPP
#define CPLUGPHYSICALOBJECT_HPP

#include "GmMat3.hpp"
#include "GmVec3.hpp"
#include <cstddef>
#include <cstdint>
#include <type_traits>

// Plain native value embedded at CPlugSolid +0x18. It has no vtable; the old
// generated header mistook the mass bit pattern (1.0f) for a pointer.
struct CPlugPhysicalObject {
    float m_mass;                       // 0x00
    GmMat3 m_inverseInertia;            // 0x04
    float m_linearDamping;              // 0x28
    float m_angularDampingX;            // 0x2C
    union {
        float m_maxDistancePerStep;      // 0x30: collision substep distance
        float m_angularDampingY;         // compatibility with the old name
    };
    union {
        float m_forceFieldCoef;         // 0x34: force-field/gravity scale
        float m_inertiaScale;           // compatibility with the old name
    };
    GmVec3 m_centerOfMass;               // 0x38
    uint32_t m_tree32;                   // 0x44

    CPlugPhysicalObject();

    void SetCenterOfMass(const GmVec3& centerOfMass);
    void SetInertiaMatrixBox(float mass, const GmVec3& halfExtents);
    void SetInertiaMatrixSphere(float radius);
};

static_assert(sizeof(CPlugPhysicalObject) == 0x48);
static_assert(offsetof(CPlugPhysicalObject, m_inverseInertia) == 0x04);
static_assert(offsetof(CPlugPhysicalObject, m_linearDamping) == 0x28);
static_assert(offsetof(CPlugPhysicalObject, m_centerOfMass) == 0x38);
static_assert(offsetof(CPlugPhysicalObject, m_tree32) == 0x44);
static_assert(std::is_standard_layout<CPlugPhysicalObject>::value);
static_assert(std::is_trivially_copyable<CPlugPhysicalObject>::value);

#endif // CPLUGPHYSICALOBJECT_HPP
