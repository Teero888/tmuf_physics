#pragma once

#include "GmVec3.hpp"

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
