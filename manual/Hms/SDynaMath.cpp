#include "SDynaMath.hpp"

namespace {

GmVec3 TransformVector(const GmMat3& matrix, const GmVec3& vector) {
    return GmVec3{
        matrix.m00 * vector.x + matrix.m01 * vector.y + matrix.m02 * vector.z,
        matrix.m10 * vector.x + matrix.m11 * vector.y + matrix.m12 * vector.z,
        matrix.m20 * vector.x + matrix.m21 * vector.y + matrix.m22 * vector.z,
    };
}

} // namespace

void SDynaMath::ComputeImpulse(
    float mass,
    const GmMat3* inverseInertia,
    float restitution,
    const GmVec3* relativeSpeed,
    const GmVec3* normal,
    const GmVec3* lever,
    GmVec3* impulse) {
    if (inverseInertia == nullptr || relativeSpeed == nullptr ||
        normal == nullptr || lever == nullptr || impulse == nullptr) {
        return;
    }

    // Exact vector order at 0x7BD098..0x7BD177. The executable has an
    // ineffective near-zero-denominator store: it writes zero and then falls
    // through to overwrite that result with the division below. Preserve the
    // final observable computation rather than adding an early return.
    const GmVec3 angularNormal = GmVec3::Cross(*lever, *normal);
    const GmVec3 angularResponse =
        TransformVector(*inverseInertia, angularNormal);
    const GmVec3 pointResponse =
        GmVec3::Cross(angularResponse, *lever);
    const float denominator =
        1.0f / mass + GmVec3::Dot(*normal, pointResponse);
    const float scale =
        ((restitution - 1.0f) *
         GmVec3::Dot(*relativeSpeed, *normal)) /
        denominator;
    *impulse = *normal * scale;
}
