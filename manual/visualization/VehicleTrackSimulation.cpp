#include "VehicleTrackSimulation.hpp"

#include "CSceneVehicleCar.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include "VehicleGroundSupport.hpp"
#include "CHmsCorpus.hpp"
#include "CHmsDyna.hpp"
#include "CHmsItem.hpp"
#include "CHmsZoneDynamic.hpp"
#include "GmIso4.hpp"
#include "GmSurf.hpp"

#include <algorithm>
#include <limits>

VehicleTrackStepDiagnostics StepVehicleOnTrack(
    CSceneVehicleCar& car,
    CHmsItem& item,
    CHmsZoneDynamic& dynamicZone,
    GmSurfMesh& worldMesh,
    CSceneVehicleCarTuning& tuning,
    float dt) {
    VehicleTrackStepDiagnostics diagnostics;
    if (item.m_corpuses.GetCount() == 0u ||
        item.m_corpuses[0] == nullptr ||
        item.m_corpuses[0]->m_dyna == nullptr) {
        return diagnostics;
    }
    CHmsDyna& dyna = *item.m_corpuses[0]->m_dyna;

    GmIso4 worldMeshTransform;
    worldMeshTransform.SetIdentity();
    const VehicleChassisBasis queryBasis =
        BuildVehicleChassisBasis(car.m_chassisUp, dyna.GetYaw());
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
        const GmVec3 wheelCenter = dyna.Position() + wheelOffset;

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
        supportSamples, wheelCount, dyna.GetYaw());
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
        dyna.GetLinearSpeed(nullptr, &velocity);
        dyna.Position().y = supportedRootY;
        GmVec3 resolvedVelocity =
            RemoveInwardSupportVelocity(velocity, groundNormal);
        if (resolvedVelocity.x != velocity.x ||
            resolvedVelocity.y != velocity.y ||
            resolvedVelocity.z != velocity.z) {
            dyna.SetLinearSpeed(nullptr, &resolvedVelocity);
        }
        const float normalGravity =
            GmVec3::Dot(gravityForce, groundNormal);
        groundReaction = groundNormal * -normalGravity;
    }
    // Native force preparation resets the accumulators, evaluates gravity and
    // damping, and invokes the vehicle callback. Track support is
    // added afterwards, before CHmsZoneDynamic integrates velocity and pose.
    dynamicZone.PrepareForPhysicsStep(dt);
    dyna.AddForce(nullptr, &groundReaction, nullptr);

    diagnostics.position = dyna.Position();
    dyna.GetLinearSpeed(nullptr, &diagnostics.velocity);
    diagnostics.accumulatedForce = dyna.Force();
    dynamicZone.PhysicsStep2(dt);
    return diagnostics;
}
