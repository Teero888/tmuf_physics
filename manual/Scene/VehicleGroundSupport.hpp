#pragma once

#include "GmVec3.hpp"

// World directions of the three native car-local axes, in local X/Y/Z order.
//
// Naming caution: `right` is the local +X axis, and in the native car frame
// local +X points to the car's *left*. TmForeverPhysicsConstants places
// `FLSurf` (front left) at +0.863 and `FRSurf` (front right) at -0.863, so
// `right * localX` only lands the wheels on their correct sides because both
// carry that convention. The engine's world is left-handed with +Y up, so the
// direction an observer would call right is Cross(forward, up), which is the
// negation of this field. Anything that maps the world onto a screen wants
// that vector, not this one; using `right` there mirrors the whole scene.
struct VehicleChassisBasis {
    GmVec3 right;
    GmVec3 up;
    GmVec3 forward;
};

struct VehicleWheelGroundSample {
    bool usable;
    GmVec3 groundPoint;
    GmVec3 localWheelCenter;
    float radius;
};

struct VehicleGroundSupportResult {
    bool valid;
    int sampleCount;
    float rootY;
    VehicleChassisBasis basis;
};

VehicleChassisBasis BuildVehicleChassisBasis(
    const GmVec3& chassisUp, float yaw);

VehicleGroundSupportResult ComputeVehicleGroundSupport(
    const VehicleWheelGroundSample* samples, int sampleCount, float yaw);

GmVec3 RemoveInwardSupportVelocity(
    const GmVec3& velocity, const GmVec3& supportNormal);
