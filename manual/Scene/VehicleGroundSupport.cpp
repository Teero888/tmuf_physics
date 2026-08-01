#include "VehicleGroundSupport.hpp"

#include "TmForeverPhysicsConstants.hpp"

#include <cmath>

namespace {

GmVec3 LocalToWorld(const VehicleChassisBasis& basis, const GmVec3& local) {
    return basis.right * local.x +
           basis.up * local.y +
           basis.forward * local.z;
}

} // namespace

VehicleChassisBasis BuildVehicleChassisBasis(
    const GmVec3& chassisUp, float yaw) {
    GmVec3 up = chassisUp;
    if (GmVec3::Dot(up, up) <=
        TmForeverPhysicsConstants::kNormalizeSquaredEpsilon) {
        up = GmVec3(0.0f, 1.0f, 0.0f);
    } else {
        up.Normalize();
    }

    const GmVec3 yawForward(std::sin(yaw), 0.0f, std::cos(yaw));
    GmVec3 right = GmVec3::Cross(up, yawForward);
    if (GmVec3::Dot(right, right) <=
        TmForeverPhysicsConstants::kNormalizeSquaredEpsilon) {
        right = GmVec3(std::cos(yaw), 0.0f, -std::sin(yaw));
    } else {
        right.Normalize();
    }

    GmVec3 forward = GmVec3::Cross(right, up);
    forward.Normalize();
    return {right, up, forward};
}

VehicleGroundSupportResult ComputeVehicleGroundSupport(
    const VehicleWheelGroundSample* samples, int sampleCount, float yaw) {
    VehicleGroundSupportResult result{};
    result.basis = BuildVehicleChassisBasis(GmVec3(0.0f, 1.0f, 0.0f), yaw);
    if (samples == nullptr || sampleCount < 3) return result;

    double meanX = 0.0;
    double meanY = 0.0;
    double meanZ = 0.0;
    for (int i = 0; i < sampleCount; ++i) {
        if (!samples[i].usable) continue;
        const GmVec3& point = samples[i].groundPoint;
        meanX += point.x;
        meanY += point.y;
        meanZ += point.z;
        ++result.sampleCount;
    }
    if (result.sampleCount < 3) return result;
    meanX /= result.sampleCount;
    meanY /= result.sampleCount;
    meanZ /= result.sampleCount;

    double sumXX = 0.0;
    double sumXZ = 0.0;
    double sumZZ = 0.0;
    double sumXY = 0.0;
    double sumZY = 0.0;
    for (int i = 0; i < sampleCount; ++i) {
        if (!samples[i].usable) continue;
        const GmVec3& point = samples[i].groundPoint;
        const double x = point.x - meanX;
        const double y = point.y - meanY;
        const double z = point.z - meanZ;
        sumXX += x * x;
        sumXZ += x * z;
        sumZZ += z * z;
        sumXY += x * y;
        sumZY += z * y;
    }
    const double determinant = sumXX * sumZZ - sumXZ * sumXZ;
    if (std::abs(determinant) <= 1.0e-10) return result;
    const float slopeX = static_cast<float>(
        (sumXY * sumZZ - sumZY * sumXZ) / determinant);
    const float slopeZ = static_cast<float>(
        (sumZY * sumXX - sumXY * sumXZ) / determinant);

    GmVec3 supportUp(-slopeX, 1.0f, -slopeZ);
    supportUp.Normalize();
    result.basis = BuildVehicleChassisBasis(supportUp, yaw);

    float rootYSum = 0.0f;
    for (int i = 0; i < sampleCount; ++i) {
        if (!samples[i].usable) continue;
        const GmVec3 wheelOffset =
            LocalToWorld(result.basis, samples[i].localWheelCenter);
        rootYSum += samples[i].groundPoint.y + samples[i].radius - wheelOffset.y;
    }
    result.rootY = rootYSum / static_cast<float>(result.sampleCount);
    result.valid = true;
    return result;
}

GmVec3 RemoveInwardSupportVelocity(
    const GmVec3& velocity, const GmVec3& supportNormal) {
    const float normalLengthSquared =
        GmVec3::Dot(supportNormal, supportNormal);
    if (normalLengthSquared <=
        TmForeverPhysicsConstants::kNormalizeSquaredEpsilon) {
        return velocity;
    }

    const float normalVelocity = GmVec3::Dot(velocity, supportNormal);
    if (normalVelocity >= 0.0f) return velocity;

    // The normal collision impulse cancels only motion entering the support
    // plane.  In particular, a downhill tangent velocity has a negative
    // world-Y component that must survive contact resolution.
    return velocity -
           supportNormal * (normalVelocity / normalLengthSquared);
}
