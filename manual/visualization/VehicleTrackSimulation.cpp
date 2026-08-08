#include "VehicleTrackSimulation.hpp"

#include "CSceneVehicleCar.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include "VehicleGroundSupport.hpp"
#include "CHmsDyna.hpp"
#include "CHmsItem.hpp"
#include "CHmsZoneDynamic.hpp"
#include "GmIso4.hpp"
#include "GmSurf.hpp"

#include <algorithm>
#include <limits>

extern float g_carYaw;
extern GmVec3 g_stub_forces;
extern GmVec3 g_stub_torques;

VehicleTrackStepDiagnostics StepVehicleOnTrack(
    CSceneVehicleCar& car,
    CHmsItem& item,
    CHmsZoneDynamic& dynamicZone,
    GmSurfMesh& worldMesh,
    CSceneVehicleCarTuning& tuning,
    float dt) {
    VehicleTrackStepDiagnostics diagnostics;

    // Force and torque accumulators belong to one native 100 Hz frame.
    g_stub_forces = GmVec3(0.0f, 0.0f, 0.0f);
    g_stub_torques = GmVec3(0.0f, 0.0f, 0.0f);
    GmVec3 zero(0.0f, 0.0f, 0.0f);
    item.SetForce(&item, &zero);

    GmIso4 worldMeshTransform;
    worldMeshTransform.SetIdentity();
    const VehicleChassisBasis queryBasis =
        BuildVehicleChassisBasis(car.m_chassisUp, g_carYaw);
    GmVec3 groundNormal(0.0f, 0.0f, 0.0f);
    float supportedRootY = -std::numeric_limits<float>::infinity();
    VehicleWheelGroundSample supportSamples[
        TmForeverPhysicsConstants::kStadiumWheelCount]{};
    const int wheelCount = std::min(
        static_cast<int>(car.m_wheels.GetCount()),
        TmForeverPhysicsConstants::kStadiumWheelCount);
    diagnostics.wheelCount = wheelCount;

    for (int wheelIndex = 0; wheelIndex < wheelCount; ++wheelIndex) {
        CSceneVehicleCar::SSimulationWheel& wheel = car.m_wheels[wheelIndex];
        const float localX =
            TmForeverPhysicsConstants::kStadiumWheelLocalX[wheelIndex];
        const float localY =
            TmForeverPhysicsConstants::kStadiumWheelLocalY[wheelIndex];
        const float localZ =
            TmForeverPhysicsConstants::kStadiumWheelLocalZ[wheelIndex];
        const GmVec3 localWheelCenter(localX, localY, localZ);
        const GmVec3 wheelOffset =
            queryBasis.right * localX + queryBasis.up * localY +
            queryBasis.forward * localZ;
        const GmVec3 wheelCenter = g_stub_pos + wheelOffset;

        const GmVec3 rayPosition =
            wheelCenter + GmVec3(0.0f, 0.25f, 0.0f);
        const GmVec3 rayDirection(
            0.0f, -(wheel.m_radius + 0.75f), 0.0f);
        float groundHitT = 1.0f;
        GmVec3 wheelGroundNormal(0.0f, 1.0f, 0.0f);
        const bool foundGround = worldMesh.ClipSegment2(
            rayPosition, rayDirection, worldMeshTransform,
            groundHitT, wheelGroundNormal) != 0;
        const float groundY = foundGround
            ? rayPosition.y + rayDirection.y * groundHitT
            : -std::numeric_limits<float>::infinity();
        const float tireGap =
            wheelCenter.y - wheel.m_radius - groundY;
        const bool wheelOnGround =
            foundGround && tireGap <= 0.02f && tireGap >= -0.5f;

        diagnostics.wheelGroundFound[wheelIndex] = foundGround;
        diagnostics.wheelGroundY[wheelIndex] = groundY;
        diagnostics.wheelTireGap[wheelIndex] = tireGap;
        diagnostics.wheelGroundNormals[wheelIndex] = wheelGroundNormal;
        supportSamples[wheelIndex].usable =
            foundGround && tireGap <= tuning.m_absorbingValRest &&
            tireGap >= -0.5f;
        supportSamples[wheelIndex].groundPoint =
            GmVec3(wheelCenter.x, groundY, wheelCenter.z);
        supportSamples[wheelIndex].localWheelCenter = localWheelCenter;
        supportSamples[wheelIndex].radius = wheel.m_radius;

        uint16_t material = 0xffff;
        if (foundGround) {
            float materialHitT = 1.0f;
            worldMesh.ClipSegment3(
                rayPosition, rayDirection, worldMeshTransform,
                materialHitT, material);
        }
        wheel.m_hasGroundContact = wheelOnGround ? 1 : 0;
        wheel.m_groundMaterial = material;
        diagnostics.wheelMaterial[wheelIndex] = material;

        if (wheelOnGround) {
            ++diagnostics.groundedWheelCount;
            groundNormal += wheelGroundNormal;
            supportedRootY = std::max(
                supportedRootY, groundY + wheel.m_radius - localY);
        }
    }

    diagnostics.onGround = diagnostics.groundedWheelCount != 0;
    if (diagnostics.onGround) {
        groundNormal.Normalize();
    } else {
        groundNormal = GmVec3(0.0f, 1.0f, 0.0f);
    }
    const VehicleGroundSupportResult support = ComputeVehicleGroundSupport(
        supportSamples, wheelCount, g_carYaw);
    if (diagnostics.onGround && support.valid) {
        groundNormal = support.basis.up;
        supportedRootY = support.rootY;
    }
    car.m_chassisUp = groundNormal;
    diagnostics.groundNormal = groundNormal;

    GmVec3 gravityForce(
        0.0f,
        TmForeverPhysicsConstants::kDefaultUniformGravity *
            tuning.m_gravityCoef * tuning.m_mass,
        0.0f);
    GmVec3 groundReaction(0.0f, 0.0f, 0.0f);
    if (diagnostics.onGround) {
        GmVec3 velocity;
        item.GetLinearSpeed(&item, &velocity);
        g_stub_pos.y = supportedRootY;
        GmVec3 resolvedVelocity =
            RemoveInwardSupportVelocity(velocity, groundNormal);
        if (resolvedVelocity.x != velocity.x ||
            resolvedVelocity.y != velocity.y ||
            resolvedVelocity.z != velocity.z) {
            item.SetLinearSpeed(&item, &resolvedVelocity);
        }
        const float normalGravity =
            GmVec3::Dot(gravityForce, groundNormal);
        groundReaction = groundNormal * -normalGravity;
    }
    item.AddForce(&item, &gravityForce, nullptr);

// The vehicle callback observes contact and gravity. Track support is
    // added afterwards, before CHmsZoneDynamic integrates velocity and pose.
    car.IntegrateVehicle(nullptr, dt);
    item.AddForce(&item, &groundReaction, nullptr);

    diagnostics.position = g_stub_pos;
    item.GetLinearSpeed(&item, &diagnostics.velocity);
    diagnostics.accumulatedForce = g_stub_forces;
    dynamicZone.PhysicsStep2();
    return diagnostics;
}
