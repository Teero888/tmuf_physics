#pragma once

#include "GmVec3.hpp"
#include "TmForeverPhysicsConstants.hpp"

#include <cstdint>

class CHmsItem;
class CHmsZoneDynamic;
class CSceneVehicleCar;
class CSceneVehicleCarTuning;
class GmSurfMesh;

// Diagnostics captured immediately before CHmsZoneDynamic advances the body.
// They expose the contact state needed by visual and replay test programs.
struct VehicleTrackStepDiagnostics {
    bool onGround = false;
    int wheelCount = 0;
    int groundedWheelCount = 0;
    GmVec3 groundNormal{0.0f, 1.0f, 0.0f};
    GmVec3 position{0.0f, 0.0f, 0.0f};
    GmVec3 velocity{0.0f, 0.0f, 0.0f};
    GmVec3 accumulatedForce{0.0f, 0.0f, 0.0f};
    bool wheelGroundFound[TmForeverPhysicsConstants::kStadiumWheelCount]{};
    float wheelGroundY[TmForeverPhysicsConstants::kStadiumWheelCount]{};
    float wheelTireGap[TmForeverPhysicsConstants::kStadiumWheelCount]{};
    GmVec3 wheelGroundNormals[TmForeverPhysicsConstants::kStadiumWheelCount]{};
    uint16_t wheelMaterial[TmForeverPhysicsConstants::kStadiumWheelCount]{};
};

// Runs one visual-test physics frame against a standalone TMNF collision mesh.
// CHmsZoneDynamic currently models the original 100 Hz step, so dt must be
// 0.01 seconds until its hard-coded timestep has been decompiled.
VehicleTrackStepDiagnostics StepVehicleOnTrack(
    CSceneVehicleCar& car,
    CHmsItem& item,
    CHmsZoneDynamic& dynamicZone,
    GmSurfMesh& worldMesh,
    CSceneVehicleCarTuning& tuning,
    float dt = 0.01f);
