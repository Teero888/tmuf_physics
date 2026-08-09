#include "CPlugPhysicalObject.hpp"

namespace {

void SetZeroOffDiagonal(GmMat3& matrix) {
    matrix.m01 = 0.0f;
    matrix.m02 = 0.0f;
    matrix.m10 = 0.0f;
    matrix.m12 = 0.0f;
    matrix.m20 = 0.0f;
    matrix.m21 = 0.0f;
}

} // namespace

CPlugPhysicalObject::CPlugPhysicalObject()
    : m_mass(1.0f),
      m_linearDamping(0.1f),
      m_angularDampingX(0.3f),
      m_maxDistancePerStep(0.3f),
      m_inertiaScale(1.0f),
      m_centerOfMass{0.0f, 0.0f, 0.0f},
      m_tree32(0u) {
    SetInertiaMatrixSphere(1.0f);
}

void CPlugPhysicalObject::SetCenterOfMass(const GmVec3& centerOfMass) {
    m_centerOfMass = centerOfMass;
}

void CPlugPhysicalObject::SetInertiaMatrixBox(
    float mass, const GmVec3& halfExtents) {
    const float width = halfExtents.x * 2.0f;
    const float height = halfExtents.y * 2.0f;
    const float depth = halfExtents.z * 2.0f;
    const double scale = (1.0 / static_cast<double>(mass)) * 12.0;
    SetZeroOffDiagonal(m_inverseInertia);
    m_inverseInertia.m00 = static_cast<float>(
        scale / (height * height + depth * depth));
    m_inverseInertia.m11 = static_cast<float>(
        scale / (width * width + depth * depth));
    m_inverseInertia.m22 = static_cast<float>(
        scale / (width * width + height * height));
}

void CPlugPhysicalObject::SetInertiaMatrixSphere(float radius) {
    // Exact constants loaded by 0x8A12F0: 3.0 and the single-precision value
    // of 4*pi promoted to double by the executable.
    constexpr double kThree = 3.0;
    constexpr double kFourPiFromExecutable = 12.566370964050293;
    const double radiusDouble = radius;
    const float volumeInverse = static_cast<float>(
        kThree /
        (kFourPiFromExecutable * radiusDouble * radiusDouble * radiusDouble));
    const float inverseMass = 1.0f / m_mass;
    SetZeroOffDiagonal(m_inverseInertia);
    const float diagonal = volumeInverse * inverseMass;
    m_inverseInertia.m00 = diagonal;
    m_inverseInertia.m11 = diagonal;
    m_inverseInertia.m22 = diagonal;
}
