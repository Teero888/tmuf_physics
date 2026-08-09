#include "../../Scene/CSceneVehicleCar.hpp"
#include "../../Scene/CSceneVehicleCarTuning.hpp"
#include "../../Scene/CSceneMobilAbsorbContact.hpp"
#include "../../Scene/TmForeverPhysicsConstants.hpp"
#include "../../Scene/VehicleGroundSupport.hpp"
#include "../../Hms/CHmsCorpus.hpp"
#include "../../Hms/CHmsDyna.hpp"
#include "../../Hms/CHmsItem.hpp"
#include "../../Hms/CHmsPhysicalContact.hpp"
#include "../../Hms/SDynaMath.hpp"
#include "../../Hms/CHmsZoneDynamic.hpp"
#include "../../Hms/CHmsZone.hpp"
#include "../../Plug/CPlugPhysicalObject.hpp"
#include "../../Plug/CPlugTree.hpp"
#include "../../Classic/CClassicBufferMemory.hpp"
#include "../../../TuningData.hpp"

#include <cmath>
#include <cstring>
#include <cstdio>
#include <limits>
#include <type_traits>

CSceneVehicleCarTuning* g_tuning = nullptr;

using Model3Signature = void (CSceneVehicleCar::*)(
    float, GmVec3*, float, float, GmVec3*, GmVec3*, float, int, void*, int*, float*);
static_assert(std::is_same_v<decltype(&CSceneVehicleCar::ComputeForcesModel3_Exact), Model3Signature>,
              "ComputeForcesModel3 must keep the eleven-argument executable ABI");
using WheelSpeedSignature = void (CSceneVehicleCar::*)(
    CSceneVehicleCar::SSimulationWheel*, float, float);
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::WheelUpdateSpeedFromVehicleSpeed),
                   WheelSpeedSignature>,
    "WheelUpdateSpeedFromVehicleSpeed must keep the three-argument executable ABI");
using WheelForceSignature = void (CSceneVehicleCar::*)(
    CSceneVehicleCar::SSimulationWheel*, float);
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::WheelAddForceToVehicle),
                   WheelForceSignature>,
    "WheelAddForceToVehicle must keep the two-argument executable ABI");
using EngineIntegrateSignature = void (CSceneVehicleCar::*)(float, float);
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::EngineIntegrate),
                   EngineIntegrateSignature>,
    "EngineIntegrate must keep the two-argument executable ABI");
using FrictionSignature = void (CSceneVehicleCar::*)(const GmVec3*);
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::ApplyFrictionForces),
                   FrictionSignature>,
    "ApplyFrictionForces must keep the one-argument executable ABI");
using WaterForcesSignature = int (CSceneVehicleCar::*)(const GmVec3*);
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::ApplyWaterForces),
                   WaterForcesSignature>,
    "ApplyWaterForces must keep the one-argument executable ABI");
using Model6Signature = void (CSceneVehicleCar::*)(
    float, GmVec3*, float, float, GmVec3*, GmVec3*, float, int,
    StadiumVehicleMaterials::GroundValues*, int*, float*);
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::ComputeForcesModel6),
                   Model6Signature>,
    "ComputeForcesModel6 must keep the eleven-argument executable ABI");
using AbsorbContactSignature = void (CSceneVehicleCar::*)(
    CHmsPhysicalContact*);
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::AbsorbContact),
                   AbsorbContactSignature>,
    "AbsorbContact must keep the one-argument executable ABI");
using WheelAbsorbContactSignature = void (CSceneVehicleCar::*)(
    CSceneVehicleCar::SSimulationWheel*, CHmsPhysicalContact*);
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::WheelAbsorbContact),
                   WheelAbsorbContactSignature>,
    "WheelAbsorbContact must keep the two-argument executable ABI");
using AddVehicleImpulseSignature = void (CSceneVehicleCar::*)(
    const GmVec3*, const GmVec3*);
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::AddVehicleImpulse),
                   AddVehicleImpulseSignature>,
    "AddVehicleImpulse must keep the two-argument executable ABI");
using AddVehicleCentralImpulseSignature = void (CSceneVehicleCar::*)(
    const GmVec3*);
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::AddVehicleCentralImpulse),
                   AddVehicleCentralImpulseSignature>,
    "AddVehicleCentralImpulse must keep the one-argument executable ABI");
using GroundContactIdSignature = int (CSceneVehicleCar::*)(
    uint8_t, GmVec3*, CHmsCorpus**) const;
static_assert(
    std::is_same_v<decltype(&CSceneVehicleCar::IsGroundContactId),
                   GroundContactIdSignature>,
    "IsGroundContactId must keep the three-argument executable ABI");
using ComputeImpulseSignature = void (*)(
    float, const GmMat3*, float, const GmVec3*, const GmVec3*,
    const GmVec3*, GmVec3*);
static_assert(
    std::is_same_v<decltype(&SDynaMath::ComputeImpulse),
                   ComputeImpulseSignature>,
    "SDynaMath::ComputeImpulse must keep its seven-argument static ABI");

namespace {

bool Expect(const char* name, bool condition) {
    if (condition) return true;
    std::fprintf(stderr, "%s: FAILED\n", name);
    return false;
}

bool Near(float actual, float expected, float tolerance = 1.0e-6f) {
    return std::abs(actual - expected) <= tolerance;
}

bool VecNear(const GmVec3& actual, const GmVec3& expected) {
    return Near(actual.x, expected.x) && Near(actual.y, expected.y) &&
           Near(actual.z, expected.z);
}

bool MatNear(const GmMat3& actual, const GmMat3& expected) {
    const float* actualValues = reinterpret_cast<const float*>(&actual);
    const float* expectedValues = reinterpret_cast<const float*>(&expected);
    for (int i = 0; i < 9; ++i) {
        if (!Near(actualValues[i], expectedValues[i], 2.0e-6f)) return false;
    }
    return true;
}

GmVec3 TransformVector(const GmMat3& matrix, const GmVec3& vector) {
    return GmVec3{
        matrix.m00 * vector.x + matrix.m01 * vector.y + matrix.m02 * vector.z,
        matrix.m10 * vector.x + matrix.m11 * vector.y + matrix.m12 * vector.z,
        matrix.m20 * vector.x + matrix.m21 * vector.y + matrix.m22 * vector.z,
    };
}

} // namespace

int main() {
    CSceneVehicleCar car;
    CSceneVehicleCarTuning tuning;
    tuning.m_mass = 1.0f;
    tuning.m_angularFluidFrictionCoef1 = 0.0f;
    tuning.m_shockModel = 2;
    tuning.m_absorbingValKi = 40.0f;
    tuning.m_absorbingValKa = 1.0f;
    tuning.m_absorbingValMin = 0.0f;
    tuning.m_absorbingValRest = 0.2f;
    tuning.m_absorbTension = 5.0f;
    tuning.m_bodyFrictionCoef = 0.3f;
    tuning.m_bodyFrictionCoefMetal = 0.2f;
    tuning.m_bodyRestCoefMetal = -0.5f;
    tuning.m_bodyRestCoef = -0.5f;
    tuning.m_wheelFrictionCoefConcrete = 0.0f;
    tuning.m_wheelRestCoefConcrete = -0.8f;
    tuning.m_wheelFrictionCoefMetal = 0.0f;
    tuning.m_wheelRestCoefMetal = -0.8f;
    tuning.m_angularSpeedYImpulseScale = 1.0f;
    tuning.m_angularImpulseScale = 1.0f;
    tuning.m_angularSpeedClamp = 100.0f;
    tuning.m_linearSpeedSquaredPositiveDeltaMax = 10000.0f;
    tuning.m_lateralSlopeAdherenceMin = 0.3f;
    tuning.m_lateralSlopeAdherenceMax = 0.7f;
    tuning.m_axialSlopeAdherenceMin = 0.4f;
    tuning.m_axialSlopeAdherenceMax = 0.7f;
    InitCurve(
        WaterBumpSlowDownFromSpeedRatio, 4,
        WaterBumpSlowDownFromSpeedRatio_times,
        WaterBumpSlowDownFromSpeedRatio_values);
    InitCurve(
        WaterFrictionFromSpeed, 3,
        WaterFrictionFromSpeed_times,
        WaterFrictionFromSpeed_values);
    InitCurve(
        WaterReboundFromSpeedRatio, 4,
        WaterReboundFromSpeedRatio_times,
        WaterReboundFromSpeedRatio_values);
    tuning.m_waterBumpSlowDownFromSpeedRatio =
        &WaterBumpSlowDownFromSpeedRatio;
    tuning.m_waterFrictionFromSpeed = &WaterFrictionFromSpeed;
    tuning.m_waterReboundFromSpeedRatio = &WaterReboundFromSpeedRatio;
    g_tuning = &tuning;

    bool passed = true;
    passed &= Expect("freewheeling defaults off", car.m_freeWheeling == 0);
    passed &= Expect("grounded wheel override defaults off",
                     car.m_useGroundedWheelSpeedOverride == 0);
    passed &= Expect("wheel drive defaults enabled", car.m_wheelDriveDisabled == 0);
    passed &= Expect("applied impulse accumulator defaults to zero",
                     VecNear(car.m_appliedImpulseSum,
                             GmVec3(0.0f, 0.0f, 0.0f)));
    passed &= Expect("engine rpm resets to zero", car.m_engine.m_engineRpm == 0.0f);
    passed &= Expect("engine maximum defaults to native 11000 RPM",
                     car.m_engine.m_maxRpm ==
                         TmForeverPhysicsConstants::kDefaultEngineMaxRpm);
    passed &= Expect("engine constructor unit scalars",
                     car.m_engine.m_field_0x04 == 1.0f &&
                     car.m_engine.m_field_0x08 == 1.0f &&
                     car.m_engine.m_field_0x0c == 1.0f);
    passed &= Expect("engine reset clears native +0x14",
                     car.m_engine.m_field_0x14 == 0.0f);
    passed &= Expect("clutch rpm resets to zero", car.m_engine.m_clutchRpm == 0.0f);
    passed &= Expect("clutch ratio resets to one", car.m_engine.m_clutchRatio == 1.0f);
    passed &= Expect("forward gear resets to one", car.m_engine.m_currentGear == 1);
    passed &= Expect("smoothed steer defaults to zero", car.m_smoothedSteer == 0.0f);
    passed &= Expect("chassis up defaults to world up",
                     Near(car.m_chassisUp.x, 0.0f) &&
                     Near(car.m_chassisUp.y, 1.0f) &&
                     Near(car.m_chassisUp.z, 0.0f));
    passed &= Expect("loaded Stadium wheelbase",
                     car.m_field_0x840 == TmForeverPhysicsConstants::kStadiumWheelbase);
    passed &= Expect("four simulation wheels", car.m_wheels.GetCount() == 4);
    passed &= Expect("front-left wheel steerable", car.m_wheels[0].m_isSteerable == 1);
    passed &= Expect("front-right wheel steerable", car.m_wheels[1].m_isSteerable == 1);
    passed &= Expect("rear-right wheel fixed", car.m_wheels[2].m_isSteerable == 0);
    passed &= Expect("rear-left wheel fixed", car.m_wheels[3].m_isSteerable == 0);
    for (uint32_t i = 0; i < car.m_wheels.GetCount(); ++i) {
        passed &= Expect("Stadium wheel enabled", car.m_wheels[i].m_field_0x00 == 1);
        passed &= Expect("Stadium wheel radius",
                         car.m_wheels[i].m_radius ==
                             TmForeverPhysicsConstants::kStadiumWheelRadius);
        passed &= Expect("wheel slipping defaults off", car.m_wheels[i].m_isSlipping == 0);
        passed &= Expect("wheel surface longitudinal coordinate",
                         TmForeverPhysicsConstants::kStadiumWheelLocalZ[i] ==
                             (i < 2 ? TmForeverPhysicsConstants::kStadiumWheelFrontZ
                                    : TmForeverPhysicsConstants::kStadiumWheelRearZ));
    }

    // Stadium tuning 29's exact Model-6 engine block.
    tuning.m_steerModel = 5;
    tuning.m_m6MaxRpm = 11000.0f;
    tuning.m_m6GearRatios = {400.0f, 370.0f, 220.0f, 160.0f, 110.0f, 85.0f};
    tuning.m_m6MaxRpmRatios = {0.0f, 0.95f, 0.9f, 0.95f, 0.95f, 1.0f};
    tuning.m_m6MinRpmRatios = {0.0f, 0.0f, 0.5f, 0.57f, 0.55f, 0.6f};
    tuning.m_m6RpmDeltaOnGearUp.fill(0.0f);
    tuning.m_m6BurnoutRpmAcceleration = 6000.0f;
    tuning.m_m6AirRpmAcceleration = 6000.0f;
    tuning.m_m6AirRpmDeadening = 3000.0f;
    tuning.m_m6RpmLossOnGearUp = 17000.0f;
    tuning.m_m6RpmGainOnGearDown = 11500.0f;
    tuning.m_m6RpmGainOnTakeoff = 10000.0f;
    tuning.m_m6RpmLossOnTakeoffFinished = 4000.0f;
    tuning.m_m6PositiveTakeoffFrontSpeed = 3.0f;
    tuning.m_m6PositiveTakeoffRearSpeed = 2.0f;
    tuning.m_m6NegativeTakeoffFrontSpeed = -2.0f;
    tuning.m_m6NegativeTakeoffRearSpeed = -3.0f;

    CSceneVehicleCar engineCar;
    engineCar.EngineIntegrate(0.5f, 0.1f);
    passed &= Expect("airborne Model6 throttle raises RPM",
                     Near(engineCar.m_engine.m_engineRpm, 600.0f));
    engineCar.EngineIntegrate(0.0f, 0.1f);
    passed &= Expect("airborne Model6 coasting deadens RPM",
                     Near(engineCar.m_engine.m_engineRpm, 300.0f));

    engineCar.m_wheels[0].m_hasGroundContact = 1;
    engineCar.m_engine.m_engineRpm = 0.0f;
    engineCar.m_engine.m_gearShiftTimer = 0.05f;
    engineCar.EngineIntegrate(0.5f, 0.01f);
    passed &= Expect("active shift uses airborne RPM response",
                     Near(engineCar.m_engine.m_engineRpm, 60.0f) &&
                     Near(engineCar.m_engine.m_gearShiftTimer, 0.04f));

    engineCar.m_engine.m_gearShiftTimer = 0.0f;
    engineCar.m_engine.m_engineRpm = 3000.0f;
    engineCar.m_engine.m_currentGear = 1;
    engineCar.m_engineState = 0;
    engineCar.m_engineLocalVelocity = GmVec3(0.0f, 0.0f, 10.0f);
    engineCar.EngineIntegrate(0.5f, 0.1f);
    passed &= Expect("grounded Model6 catches engine up to clutch RPM",
                     Near(engineCar.m_engine.m_clutchRpm, 3700.0f) &&
                     Near(engineCar.m_engine.m_engineRpm, 4150.0f));

    engineCar.m_engine.m_engineRpm = 925.0f;
    engineCar.m_engine.m_currentGear = 1;
    engineCar.m_engineState = 0;
    engineCar.m_engineLocalVelocity.z = 2.5f;
    engineCar.EngineIntegrate(0.5f, 0.01f);
    passed &= Expect("positive speed window enters takeoff synchronizer",
                     engineCar.m_engineState == 2);
    engineCar.m_engine.m_engineRpm = 0.0f;
    engineCar.EngineIntegrate(0.5f, 0.05f);
    passed &= Expect("takeoff synchronizer clamps to clutch RPM",
                     Near(engineCar.m_engine.m_engineRpm, 925.0f) &&
                     engineCar.m_engineState == 2);

    engineCar.m_engine.m_engineRpm = 0.0f;
    engineCar.m_engine.m_currentGear = 1;
    engineCar.m_engine.m_gearShiftTimer = 0.0f;
    engineCar.m_engineState = 0;
    engineCar.m_engineLocalVelocity.z = 30.0f;
    engineCar.EngineIntegrate(0.5f, 0.1f);
    passed &= Expect("Model6 automatic upshift uses clutch RPM table",
                     engineCar.m_engine.m_currentGear == 2 &&
                     engineCar.m_engineState == 1 &&
                     Near(engineCar.m_engine.m_gearShiftTimer,
                          TmForeverPhysicsConstants::kM6ShiftDuration));

    engineCar.m_engine.m_engineRpm = 0.0f;
    engineCar.m_engine.m_currentGear = 1;
    engineCar.m_engine.m_gearShiftTimer = 0.0f;
    engineCar.m_engine.m_isReverse = 1;
    engineCar.m_engineState = 0;
    engineCar.m_engineLocalVelocity.z = -2.5f;
    engineCar.EngineIntegrate(0.5f, 0.01f);
    passed &= Expect("negative speed window enters reverse synchronizer",
                     engineCar.m_engineState == 3 &&
                     engineCar.m_engine.m_currentGear == 0 &&
                     Near(engineCar.m_engine.m_gearShiftTimer,
                          TmForeverPhysicsConstants::kM6ShiftDuration));

    engineCar.m_engine.m_isReverse = 0;
    engineCar.m_engine.m_currentGear = 1;
    engineCar.m_engine.m_gearShiftTimer = 0.0f;
    engineCar.m_engine.m_engineRpm = 0.0f;
    engineCar.m_engineState = 0;
    engineCar.m_engineTakeoffMode = 1;
    engineCar.m_engineLocalVelocity.z = 0.0f;
    engineCar.EngineIntegrate(0.5f, 0.1f);
    passed &= Expect("takeoff mode enters native engine state four",
                     engineCar.m_engineState == 4 &&
                     Near(engineCar.m_engine.m_engineRpm, 600.0f) &&
                     Near(engineCar.m_engine.m_clutchRpm, 11000.0f) &&
                     Near(engineCar.m_engine.m_clutchRatio,
                          TmForeverPhysicsConstants::kM6ClutchRatioTarget));

    engineCar.m_engineTakeoffMode = 0;
    engineCar.m_engineState = 0;
    engineCar.m_engineClutchBoost = 1;
    engineCar.m_engine.m_clutchRatio = 1.0f;
    engineCar.m_engine.m_engineRpm = 4000.0f;
    engineCar.m_engineLocalVelocity.z = 10.0f;
    engineCar.EngineIntegrate(0.5f, 0.1f);
    passed &= Expect("Model6 clutch boost uses native asymptotic response",
                     Near(engineCar.m_engine.m_clutchRatio, 1.0045f, 2.0e-6f));

    tuning.m_steerModel = 0;
    tuning.m_steerSlowDownFactor = 1.0f;
    for (uint32_t i = 0; i < engineCar.m_wheels.GetCount(); ++i) {
        engineCar.m_wheels[i].m_hasGroundContact = 0;
    }
    engineCar.m_engine.Reset();
    engineCar.EngineIntegrate(0.5f, 0.1f);
    passed &= Expect("legacy airborne engine targets absolute input",
                     Near(engineCar.m_engine.m_engineRpm, 1925.0f));

    tuning.m_steerModel = 5;
    CHmsItem engineItem;
    engineCar.m_hmsItem = &engineItem;
    engineCar.m_simulationFlags = 4;
    engineCar.m_freeWheeling = 1;
    engineCar.m_engine.m_engineRpm = 1234.0f;
    engineCar.IntegrateVehicle(&engineCar, 0.1f);
    passed &= Expect("IntegrateVehicle freewheel zeroes engine RPM",
                     engineCar.m_engine.m_engineRpm == 0.0f);
    engineCar.m_freeWheeling = 0;
    engineCar.m_engine.m_isReverse = 1;
    engineCar.m_inputGas = 1.0f;
    engineCar.m_inputBrake = 0.0f;
    engineCar.m_engine.m_engineRpm = 1000.0f;
    engineCar.IntegrateVehicle(&engineCar, 0.1f);
    passed &= Expect("IntegrateVehicle reverse selects brake input",
                     Near(engineCar.m_engine.m_engineRpm, 700.0f));

    CSceneVehicleCar::SSimulationWheel& wheel = car.m_wheels[0];
    wheel.m_realTimeState.m_rotationAngle =
        TmForeverPhysicsConstants::kWheelRotationAnglePeriod - 0.25f;
    wheel.m_realTimeState.m_angularVelocity = 1.0f;
    wheel.m_realTimeState.m_direction = GmVec3(0.0f, 2.0f, 0.0f);
    wheel.m_realTimeState.m_steeringAngle = 0.0f;
    wheel.m_realTimeState.m_targetSteeringAngle = 0.25f;
    wheel.m_realTimeState.Integrate(0.5f);
    GmMat3 identity;
    identity.SetIdentity();
    passed &= Expect("wheel angle wraps over native 256-turn period",
                     Near(wheel.m_realTimeState.m_rotationAngle, 0.25f));
    passed &= Expect("wheel direction is normalized",
                     VecNear(wheel.m_realTimeState.m_direction,
                             GmVec3(0.0f, 1.0f, 0.0f)));
    passed &= Expect("wheel direction rebuilds orientation basis",
                     MatNear(wheel.m_realTimeState.m_orientation.rot, identity));
    passed &= Expect("wheel steering interpolation clamps upward",
                     Near(wheel.m_realTimeState.m_steeringAngle, 0.25f));

    wheel.m_realTimeState.m_targetSteeringAngle = -0.25f;
    wheel.m_realTimeState.Integrate(0.1f);
    passed &= Expect("wheel steering interpolation moves downward",
                     Near(wheel.m_realTimeState.m_steeringAngle, 0.15f));
    wheel.m_realTimeState.Integrate(1.0f);
    passed &= Expect("wheel steering interpolation clamps downward",
                     Near(wheel.m_realTimeState.m_steeringAngle, -0.25f));

    wheel.m_realTimeState.m_rotationAngle = 0.0f;
    wheel.m_realTimeState.m_angularVelocity = 0.0f;
    wheel.m_realTimeState.m_direction = GmVec3(0.0f, 0.0f, 0.0f);
    wheel.m_realTimeState.m_steeringAngle = 0.0f;
    wheel.m_realTimeState.m_targetSteeringAngle = 0.0f;
    wheel.m_radius = 0.5f;
    wheel.m_hasGroundContact = 1;
    car.WheelUpdateSpeedFromVehicleSpeed(&wheel, 10.0f, 0.1f);
    passed &= Expect("grounded wheel follows local vehicle speed",
                     Near(wheel.m_realTimeState.m_angularVelocity, 20.0f));

    car.m_useGroundedWheelSpeedOverride = 1;
    car.m_groundedWheelAngularSpeedOverride = 37.0f;
    car.WheelUpdateSpeedFromVehicleSpeed(&wheel, 10.0f, 0.1f);
    passed &= Expect("grounded resource override sets angular speed",
                     wheel.m_realTimeState.m_angularVelocity == 37.0f);
    car.m_wheelDriveDisabled = 1;
    car.WheelUpdateSpeedFromVehicleSpeed(&wheel, 10.0f, 0.1f);
    passed &= Expect("disabled drive bypasses grounded override",
                     Near(wheel.m_realTimeState.m_angularVelocity, 20.0f));

    wheel.m_hasGroundContact = 0;
    car.m_useGroundedWheelSpeedOverride = 0;
    car.m_wheelDriveDisabled = 0;
    car.m_inputGas = 0.5f;
    car.m_inputBrake = 0.0f;
    wheel.m_realTimeState.m_angularVelocity = 0.0f;
    car.WheelUpdateSpeedFromVehicleSpeed(&wheel, 0.0f, 0.25f);
    passed &= Expect("airborne gas accelerates toward scaled target",
                     Near(wheel.m_realTimeState.m_angularVelocity, 25.0f));
    car.WheelUpdateSpeedFromVehicleSpeed(&wheel, 0.0f, 1.0f);
    passed &= Expect("airborne gas clamps at scaled target",
                     Near(wheel.m_realTimeState.m_angularVelocity, 100.0f));

    car.m_inputGas = 0.0f;
    car.m_inputBrake = 0.25f;
    wheel.m_realTimeState.m_angularVelocity = 10.0f;
    car.WheelUpdateSpeedFromVehicleSpeed(&wheel, 0.0f, 0.1f);
    passed &= Expect("airborne brake clamps at residual target",
                     Near(wheel.m_realTimeState.m_angularVelocity, 0.75f));

    car.m_inputBrake = 0.0f;
    wheel.m_realTimeState.m_angularVelocity = 100.0f;
    car.WheelUpdateSpeedFromVehicleSpeed(&wheel, 0.0f, 0.1f);
    passed &= Expect("airborne undriven wheel uses native decay",
                     Near(wheel.m_realTimeState.m_angularVelocity, 99.5f));

    car.m_inputGas = 0.5f;
    car.m_freeWheeling = 1;
    wheel.m_realTimeState.m_angularVelocity = 100.0f;
    car.WheelUpdateSpeedFromVehicleSpeed(&wheel, 0.0f, 0.1f);
    passed &= Expect("freewheeling suppresses airborne gas drive",
                     Near(wheel.m_realTimeState.m_angularVelocity, 99.5f));
    car.m_freeWheeling = 0;
    car.m_wheelDriveDisabled = 1;
    wheel.m_realTimeState.m_angularVelocity = 100.0f;
    car.WheelUpdateSpeedFromVehicleSpeed(&wheel, 0.0f, 0.1f);
    passed &= Expect("disabled drive suppresses airborne gas drive",
                     Near(wheel.m_realTimeState.m_angularVelocity, 99.5f));

    car.m_inputGas = 0.0f;
    car.m_wheelDriveDisabled = 0;
    wheel.m_radius = TmForeverPhysicsConstants::kStadiumWheelRadius;
    wheel.m_realTimeState.m_angularVelocity = 0.0f;

    CPlugTree wheelSurfaceTree;
    wheel.m_surfaceHandler.m_tree = &wheelSurfaceTree;
    wheel.m_surfaceHandler.m_baseLocation.SetIdentity();
    wheel.m_surfaceHandler.m_baseLocation.SetTranslation(
        GmVec3(1.0f, 2.0f, 3.0f));
    wheel.m_realTimeState.m_compression = 0.15f;
    wheel.m_realTimeState.m_absorbDelta = 0.05f;
    wheel.m_realTimeState.m_velocity = 0.5f;
    tuning.m_shockModel = 0;
    car.WheelIntegrate(&wheel, 0.1f);
    passed &= Expect("shock model zero spring-damper integration",
                     Near(wheel.m_realTimeState.m_compression, 0.185f) &&
                     Near(wheel.m_realTimeState.m_velocity, 0.85f) &&
                     wheel.m_realTimeState.m_absorbDelta == 0.0f);
    passed &= Expect("shock model zero updates wheel surface translation",
                     Near(wheelSurfaceTree.m_location.tX, 1.0f) &&
                     Near(wheelSurfaceTree.m_location.tY, 1.815f) &&
                     Near(wheelSurfaceTree.m_location.tZ, 3.0f));

    wheel.m_realTimeState.m_compression = 0.15f;
    wheel.m_realTimeState.m_absorbDelta = 0.05f;
    wheel.m_realTimeState.m_velocity = 2.0f;
    tuning.m_shockModel = 1;
    car.WheelIntegrate(&wheel, 0.05f);
    passed &= Expect("shock model one direct absorption integration",
                     Near(wheel.m_realTimeState.m_compression, 0.125f) &&
                     Near(wheel.m_realTimeState.m_velocity, -0.5f) &&
                     wheel.m_realTimeState.m_absorbDelta == 0.0f);
    passed &= Expect("shock model one updates wheel surface translation",
                     Near(wheelSurfaceTree.m_location.tY, 1.875f));

    wheel.m_surfaceHandler.m_tree = nullptr;
    wheel.m_surfaceHandler.m_baseLocation.SetIdentity();
    wheel.m_surfaceHandler.m_surfaceLocation.SetIdentity();
    wheel.m_realTimeState.m_compression = 0.0f;
    wheel.m_realTimeState.m_absorbDelta = 0.0f;
    wheel.m_realTimeState.m_velocity = 0.0f;
    tuning.m_shockModel = 2;
    car.WheelIntegrate(&wheel, 0.01f);
    passed &= Expect("Demo03 compression update", Near(wheel.m_realTimeState.m_compression, 0.01f));
    passed &= Expect("Demo03 compression velocity", Near(wheel.m_realTimeState.m_velocity, 1.0f));
    passed &= Expect("Demo03 clears absorbed delta", wheel.m_realTimeState.m_absorbDelta == 0.0f);
    passed &= Expect("no initial ground contact", car.IsGroundContact() == 0);

    CHmsItem suspensionItem;
    CHmsCorpus* suspensionCorpus = new CHmsCorpus();
    suspensionCorpus->m_dyna = new CHmsDyna();
    suspensionCorpus->m_item = &suspensionItem;
    suspensionItem.m_corpuses.Add(suspensionCorpus);
    CHmsDyna* suspensionDyna = suspensionCorpus->m_dyna;
    car.m_hmsItem = &suspensionItem;
    wheel.m_hasGroundContact = 1;
    wheel.m_realTimeState.m_compression = 0.15f;
    wheel.m_realTimeState.m_velocity = 0.5f;
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    wheel.m_localContactPosition = GmVec3(0.0f, 0.0f, 0.0f);
    car.WheelAddForceToVehicle(&wheel, 0.0f);
    passed &= Expect("Demo03 suspension spring-damper scalar",
                     Near(wheel.m_suspensionForce, 1.5f));
    passed &= Expect("Demo03 suspension acts on local up axis",
                     Near(suspensionDyna->Force().x, 0.0f) &&
                     Near(suspensionDyna->Force().y, 1.5f) &&
                     Near(suspensionDyna->Force().z, 0.0f));

    tuning.m_shockModel = 0;
    wheel.m_realTimeState.m_compression = 0.1f;
    wheel.m_realTimeState.m_velocity = 50.0f;
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    car.WheelAddForceToVehicle(&wheel, 123.0f);
    passed &= Expect("shock model zero uses extra force factor without damping",
                     Near(wheel.m_suspensionForce, 0.8f) &&
                     Near(suspensionDyna->Force().y, 0.8f));

    tuning.m_shockModel = 1;
    wheel.m_realTimeState.m_compression = 0.15f;
    wheel.m_realTimeState.m_velocity = 0.5f;
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    car.WheelAddForceToVehicle(&wheel, 123.0f);
    passed &= Expect("shock model one uses spring-damper force",
                     Near(wheel.m_suspensionForce, 1.5f) &&
                     Near(suspensionDyna->Force().y, 1.5f));

    tuning.m_shockModel = 2;
    wheel.m_hasGroundContact = 0;
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    car.WheelAddForceToVehicle(&wheel, 0.0f);
    passed &= Expect("suspension helper ignores uncontacted wheel",
                     Near(suspensionDyna->Force().x, 0.0f) &&
                     Near(suspensionDyna->Force().y, 0.0f) &&
                     Near(suspensionDyna->Force().z, 0.0f));

    // CHmsItem and the vehicle helpers expose the executable's local-space
    // API. CHmsDyna rotates those values through the complete body transform.
    constexpr float kSqrtHalf = 0.7071067811865475244f;
    constexpr float kSinPiOver8 = 0.3826834323650898f;
    constexpr float kCosPiOver8 = 0.9238795325112867f;
    suspensionDyna->CurrentState().m_rotation =
        GmQuat{kCosPiOver8, kSinPiOver8, 0.0f, 0.0f};
    suspensionDyna->CurrentState().m_rotationMatrix.Set(
        suspensionDyna->CurrentState().m_rotation);
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    const GmVec3 pitchedLocalForward(0.0f, 0.0f, 2.0f);
    car.AddVehicleCentralForce(
        &car,
        reinterpret_cast<CSceneVehicleCar*>(
            const_cast<GmVec3*>(&pitchedLocalForward)),
        nullptr);
    passed &= Expect("local force uses full chassis rotation",
                     Near(suspensionDyna->Force().x, 0.0f) &&
                     Near(suspensionDyna->Force().y, -2.0f * kSqrtHalf) &&
                     Near(suspensionDyna->Force().z, 2.0f * kSqrtHalf));

    suspensionDyna->CurrentState().m_rotation =
        GmQuat{0.5f, 0.5f, 0.5f, 0.5f};
    suspensionDyna->CurrentState().m_rotationMatrix.Set(
        suspensionDyna->CurrentState().m_rotation);
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    GmVec3 itemLocalForce(1.0f, 2.0f, 3.0f);
    suspensionItem.AddForce(&suspensionItem, &itemLocalForce, nullptr);
    GmVec3 itemRecovered;
    suspensionItem.GetForce(&suspensionItem, &itemRecovered);
    passed &= Expect("item force API stays local across full rotation",
                     VecNear(suspensionDyna->Force(),
                             GmVec3(3.0f, 1.0f, 2.0f)) &&
                     VecNear(itemRecovered, itemLocalForce));

    suspensionDyna->Torque() = GmVec3(0.0f, 0.0f, 0.0f);
    GmVec3 itemLocalTorque(-1.0f, 4.0f, 2.0f);
    suspensionItem.AddTorque(&suspensionItem, &itemLocalTorque);
    suspensionItem.GetAngularSpeed(&suspensionItem, &itemRecovered);
    passed &= Expect("item torque addition stays local",
                     VecNear(suspensionDyna->Torque(),
                             GmVec3(2.0f, -1.0f, 4.0f)));

    GmVec3 itemLocalSpeed(7.0f, 8.0f, 9.0f);
    suspensionItem.SetLinearSpeed(&suspensionItem, &itemLocalSpeed);
    suspensionItem.GetLinearSpeed(&suspensionItem, &itemRecovered);
    passed &= Expect("item linear-speed round trip stays local",
                     VecNear(suspensionDyna->CurrentState().m_linearSpeed,
                             GmVec3(9.0f, 7.0f, 8.0f)) &&
                     VecNear(itemRecovered, itemLocalSpeed));

    GmVec3 itemLocalAngularSpeed(4.0f, 5.0f, 6.0f);
    suspensionItem.SetAngularSpeed(
        &suspensionItem, &itemLocalAngularSpeed);
    suspensionItem.GetAngularSpeed(&suspensionItem, &itemRecovered);
    passed &= Expect("item angular-speed round trip stays local",
                     VecNear(suspensionDyna->AngularSpeed(),
                             GmVec3(6.0f, 4.0f, 5.0f)) &&
                     VecNear(itemRecovered, itemLocalAngularSpeed));

    suspensionDyna->CurrentState().m_linearSpeed =
        GmVec3(0.0f, 0.0f, 0.0f);
    GmVec3 itemLocalImpulse(2.0f, 4.0f, 6.0f);
    suspensionItem.AddImpulse(&suspensionItem, &itemLocalImpulse);
    suspensionItem.GetLinearSpeed(&suspensionItem, &itemRecovered);
    passed &= Expect("item impulse addition stays local",
                     VecNear(suspensionDyna->CurrentState().m_linearSpeed,
                             GmVec3(6.0f, 2.0f, 4.0f)) &&
                     VecNear(itemRecovered, itemLocalImpulse));

    // ApplyFrictionForces is a central-force helper over an already-local
    // velocity. Use an identity chassis transform so the accumulated world
    // force exposes its scalar branches directly.
    suspensionDyna->CurrentState().m_rotation.SetIdentity();
    suspensionDyna->CurrentState().m_rotationMatrix.SetIdentity();
    tuning.m_steerModel = 5;
    InitCurve(LateralContactSlowDown, 5,
              LateralContactSlowDown_times,
              LateralContactSlowDown_values);
    tuning.m_lateralContactSlowDown = &LateralContactSlowDown;
    tuning.m_groundSlowDownBase = 1.0f;
    tuning.m_linearFluidFrictionCoef = 0.03f;
    tuning.m_m5LateralConstantSlowDownDuration = 500u;
    car.m_inputGas = 0.0f;
    car.m_inputBrake = 0.0f;
    car.m_engine.m_isReverse = 0;
    car.m_freeWheeling = 0;
    car.m_hasBodyContact = 0;
    car.m_lastBodyContactTick = std::numeric_limits<uint32_t>::max();
    car.m_hasWaterContact = 0;
    for (uint32_t i = 0; i < car.m_wheels.GetCount(); ++i) {
        car.m_wheels[i].m_hasGroundContact = 0;
    }

    const GmVec3 frictionSpeed(3.0f, 4.0f, 0.0f);
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    car.ApplyFrictionForces(&frictionSpeed);
    passed &= Expect("friction combines constant and linear slowdown",
                     VecNear(suspensionDyna->Force(),
                             GmVec3(-0.69f, -0.92f, 0.0f)));

    car.m_freeWheeling = 1;
    car.m_inputGas = 1.0f;
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    car.ApplyFrictionForces(&frictionSpeed);
    passed &= Expect("freewheel retains only constant slowdown",
                     VecNear(suspensionDyna->Force(),
                             GmVec3(-0.6f, -0.8f, 0.0f)));

    car.m_hasWaterContact = 1;
    car.m_hasBodyContact = 1;
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    car.ApplyFrictionForces(&frictionSpeed);
    passed &= Expect("airborne water contact suppresses Model5 friction",
                     VecNear(suspensionDyna->Force(),
                             GmVec3(0.0f, 0.0f, 0.0f)));

    car.m_freeWheeling = 0;
    car.m_hasWaterContact = 0;
    car.m_inputGas = 1.0f;
    car.m_hasBodyContact = 1;
    car.m_frictionCurrentTick = 100u;
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    car.ApplyFrictionForces(&frictionSpeed);
    passed &= Expect("Model5 contact starts normalized slowdown window",
                     car.m_lastBodyContactTick == 100u &&
                     VecNear(suspensionDyna->Force(),
                             GmVec3(-2.592f, -3.456f, 0.0f)));

    car.m_hasBodyContact = 0;
    car.m_frictionCurrentTick = 599u;
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    car.ApplyFrictionForces(&frictionSpeed);
    passed &= Expect("Model5 contact slowdown remains active before cutoff",
                     VecNear(suspensionDyna->Force(),
                             GmVec3(-2.592f, -3.456f, 0.0f)));
    car.m_frictionCurrentTick = 600u;
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    car.ApplyFrictionForces(&frictionSpeed);
    passed &= Expect("Model5 contact slowdown cutoff is exclusive",
                     VecNear(suspensionDyna->Force(),
                             GmVec3(0.0f, 0.0f, 0.0f)));

    tuning.m_steerModel = 3;
    car.m_hasBodyContact = 1;
    const GmVec3 legacyContactSpeed(0.0f, 0.0f, 100.0f / 3.6f);
    suspensionDyna->Force() = GmVec3(0.0f, 0.0f, 0.0f);
    car.ApplyFrictionForces(&legacyContactSpeed);
    passed &= Expect("legacy contact slowdown uses signed forward speed",
                     VecNear(suspensionDyna->Force(),
                             GmVec3(0.0f, 0.0f,
                                    -24.0f * (100.0f / 3.6f))));
    car.m_hmsItem = nullptr;

    VehicleWheelGroundSample flatSupport[4]{};
    for (int i = 0; i < 4; ++i) {
        flatSupport[i].usable = true;
        flatSupport[i].groundPoint = GmVec3(
            TmForeverPhysicsConstants::kStadiumWheelLocalX[i],
            90.0f,
            TmForeverPhysicsConstants::kStadiumWheelLocalZ[i]);
        flatSupport[i].localWheelCenter = GmVec3(
            TmForeverPhysicsConstants::kStadiumWheelLocalX[i],
            TmForeverPhysicsConstants::kStadiumWheelLocalY[i],
            TmForeverPhysicsConstants::kStadiumWheelLocalZ[i]);
        flatSupport[i].radius = TmForeverPhysicsConstants::kStadiumWheelRadius;
    }
    const VehicleGroundSupportResult flatResult =
        ComputeVehicleGroundSupport(flatSupport, 4, 0.0f);
    passed &= Expect("flat four-wheel support is valid", flatResult.valid);
    passed &= Expect("flat support preserves world up",
                     Near(flatResult.basis.up.x, 0.0f) &&
                     Near(flatResult.basis.up.y, 1.0f) &&
                     Near(flatResult.basis.up.z, 0.0f));
    passed &= Expect("flat support reconstructs chassis root height",
                     Near(flatResult.rootY,
                          90.0f + TmForeverPhysicsConstants::kStadiumWheelRadius -
                              0.5f * (TmForeverPhysicsConstants::kStadiumWheelLocalY[0] +
                                      TmForeverPhysicsConstants::kStadiumWheelLocalY[2])));

    VehicleWheelGroundSample slopeSupport[4] = {
        flatSupport[0], flatSupport[1], flatSupport[2], flatSupport[3]};
    for (int i = 0; i < 4; ++i) {
        slopeSupport[i].groundPoint.x =
            TmForeverPhysicsConstants::kStadiumWheelLocalZ[i];
        slopeSupport[i].groundPoint.z =
            -TmForeverPhysicsConstants::kStadiumWheelLocalX[i];
    }
    slopeSupport[0].groundPoint.y = 89.837f;
    slopeSupport[1].groundPoint.y = 89.837f;
    const VehicleGroundSupportResult slopeResult =
        ComputeVehicleGroundSupport(slopeSupport, 4, 1.57079632679f);
    const float longitudinalSlope =
        (89.837f - 90.0f) / TmForeverPhysicsConstants::kStadiumWheelbase;
    const float slopeNormalScale =
        1.0f / std::sqrt(1.0f + longitudinalSlope * longitudinalSlope);
    passed &= Expect("split-axle support pitches toward descending road",
                     slopeResult.valid &&
                     Near(slopeResult.basis.up.x,
                          -longitudinalSlope * slopeNormalScale, 1.0e-4f) &&
                     Near(slopeResult.basis.up.y, slopeNormalScale, 1.0e-4f) &&
                     Near(slopeResult.basis.up.z, 0.0f, 1.0e-4f));
    slopeSupport[2].usable = false;
    slopeSupport[3].usable = false;
    passed &= Expect("single axle cannot define a support plane",
                     !ComputeVehicleGroundSupport(slopeSupport, 4, 0.0f).valid);

    const GmVec3 flatResolvedVelocity = RemoveInwardSupportVelocity(
        GmVec3(1.0f, -2.0f, 3.0f), GmVec3(0.0f, 1.0f, 0.0f));
    passed &= Expect("flat support removes only downward velocity",
                     Near(flatResolvedVelocity.x, 1.0f) &&
                     Near(flatResolvedVelocity.y, 0.0f) &&
                     Near(flatResolvedVelocity.z, 3.0f));

    GmVec3 slopeTangent(0.0f, -1.0f, 2.0f);
    GmVec3 slopeNormal(0.0f, 2.0f, 1.0f);
    const GmVec3 preservedSlopeTangent =
        RemoveInwardSupportVelocity(slopeTangent, slopeNormal);
    passed &= Expect("support preserves downhill tangent velocity",
                     GmVec3::Dot(slopeTangent, slopeNormal) == 0.0f &&
                     Near(preservedSlopeTangent.x, slopeTangent.x) &&
                     Near(preservedSlopeTangent.y, slopeTangent.y) &&
                     Near(preservedSlopeTangent.z, slopeTangent.z));
    const GmVec3 inwardVelocity = slopeTangent - slopeNormal * 3.0f;
    const GmVec3 slopeResolvedVelocity =
        RemoveInwardSupportVelocity(inwardVelocity, slopeNormal);
    passed &= Expect("support impulse removes only inward normal velocity",
                     Near(GmVec3::Dot(slopeResolvedVelocity, slopeNormal), 0.0f) &&
                     Near(slopeResolvedVelocity.x, slopeTangent.x) &&
                     Near(slopeResolvedVelocity.y, slopeTangent.y) &&
                     Near(slopeResolvedVelocity.z, slopeTangent.z));

    float lateralAdherence = 0.25f;
    float axialAdherence = 0.75f;
    car.GetSlopeAdherence(
        GmVec3(0.0f, 0.0f, 0.0f),
        &lateralAdherence, &axialAdherence);
    passed &= Expect("zero force preserves slope defaults",
                     Near(lateralAdherence, 0.25f) &&
                     Near(axialAdherence, 0.75f));
    car.GetSlopeAdherence(
        GmVec3(1.0f, 0.0f, 0.0f),
        &lateralAdherence, &axialAdherence);
    passed &= Expect("horizontal force has no slope adherence",
                     Near(lateralAdherence, 0.0f) &&
                     Near(axialAdherence, 0.0f));
    car.GetSlopeAdherence(
        GmVec3(0.0f, 1.0f, 0.0f),
        &lateralAdherence, &axialAdherence);
    passed &= Expect("vertical force has full slope adherence",
                     Near(lateralAdherence, 1.0f) &&
                     Near(axialAdherence, 1.0f));
    car.GetSlopeAdherence(
        GmVec3(std::sqrt(0.75f), 0.5f, 0.0f),
        &lateralAdherence, &axialAdherence);
    passed &= Expect("slope adherence cosine interpolation",
                     Near(lateralAdherence, 0.29289323f) &&
                     Near(axialAdherence, 0.13397460f));

    StadiumVehicleMaterials::GroundValues groundValues{42.0f, 42.0f, 42.0f, 42.0f};
    int hasGroundMaterial = 42;
    car.ComputeVehicleGroundMaterialVals(&groundValues, &hasGroundMaterial);
    passed &= Expect("no-contact material flag is zero", hasGroundMaterial == 0);
    passed &= Expect("no-contact material values are zero",
                     Near(groundValues.speed, 0.0f) &&
                     Near(groundValues.accelerationCoef, 0.0f) &&
                     Near(groundValues.brakeCoef, 0.0f) &&
                     Near(groundValues.grip, 0.0f));

    car.m_wheels[2].m_hasGroundContact = 1;
    passed &= Expect("ground contact scans every wheel", car.IsGroundContact() == 1);
    car.m_wheels[0].m_groundMaterial = 2;
    car.m_wheels[2].m_groundMaterial = 16;
    car.ComputeVehicleGroundMaterialVals(&groundValues, &hasGroundMaterial);
    passed &= Expect("contact material flag is boolean one", hasGroundMaterial == 1);
    passed &= Expect("runtime material ABI order",
                     Near(groundValues.speed, 0.5f) &&
                     Near(groundValues.accelerationCoef, 0.4f) &&
                     Near(groundValues.brakeCoef, 0.05f) &&
                     Near(groundValues.grip, 0.15f));

    car.m_wheels[3].m_hasGroundContact = 1;
    car.m_wheels[3].m_groundMaterial = 3;
    car.ComputeVehicleGroundMaterialVals(&groundValues, &hasGroundMaterial);
    passed &= Expect("ground material preserves executable wheel-zero quirk",
                     Near(groundValues.speed, 0.5f) &&
                     Near(groundValues.accelerationCoef, 0.4f) &&
                     Near(groundValues.brakeCoef, 0.05f) &&
                     Near(groundValues.grip, 0.15f));

    car.m_wheels[0].m_groundMaterial = 16;
    car.ComputeVehicleGroundMaterialVals(&groundValues, &hasGroundMaterial);
    passed &= Expect("A01 asphalt material is all ones",
                     Near(groundValues.speed, 1.0f) &&
                     Near(groundValues.accelerationCoef, 1.0f) &&
                     Near(groundValues.brakeCoef, 1.0f) &&
                     Near(groundValues.grip, 1.0f));

    car.m_wheels[2].m_hasGroundContact = 0;
    car.m_wheels[3].m_hasGroundContact = 0;

    car.VehicleFreeWheelingSet(1);
    passed &= Expect("freewheeling setter stores one", car.m_freeWheeling == 1);
    car.VehicleFreeWheelingSet(0);
    passed &= Expect("freewheeling setter stores zero", car.m_freeWheeling == 0);

    // IntegrateStep advances position with the old speed before force changes
    // velocity. This distinguishes the executable's explicit-Euler ordering
    // from the previously used symplectic update.
    CHmsDyna dyna;
    GmVec3 initialSpeed(2.0f, 0.0f, 0.0f);
    dyna.SetLinearSpeed(nullptr, &initialSpeed);
    dyna.Position() = GmVec3(0.0f, 0.0f, 0.0f);
    dyna.Force() = GmVec3(1.0f, 0.0f, 0.0f);
    dyna.Torque() = GmVec3(0.0f, 0.0f, 0.0f);
    dyna.Integrate(0.5f);
    dyna.Move(0.5f);
    GmVec3 integratedSpeed;
    dyna.GetLocalLinearSpeed(&integratedSpeed);
    passed &= Expect("explicit Euler uses pre-force speed for translation",
                     Near(dyna.Position().x, 1.0f));
    passed &= Expect("force still updates end-of-step speed",
                     Near(integratedSpeed.x, 2.5f));

    // 0x533510 integrates world angular velocity by left-multiplying the
    // orientation quaternion. A nonzero center of mass must remain fixed
    // relative to the translational step while the root rotates around it.
    CPlugPhysicalObject rotationalPhysical;
    rotationalPhysical.m_mass = 2.0f;
    rotationalPhysical.m_inverseInertia.SetIdentity();
    rotationalPhysical.m_inverseInertia.m00 = 2.0f;
    rotationalPhysical.m_inverseInertia.m11 = 3.0f;
    rotationalPhysical.m_inverseInertia.m22 = 4.0f;
    rotationalPhysical.m_centerOfMass = GmVec3(0.5f, -0.25f, 1.0f);

    CHmsDyna rotationalBody;
    rotationalBody.m_field_0x108 = &rotationalPhysical;
    rotationalBody.m_dynamicType = 1;
    passed &= Expect("native angular clamp defaults",
                     rotationalBody.m_field_0xc0 == 0 &&
                     Near(rotationalBody.m_field_0xc4, 10000.0f));

    CHmsDyna::CHmsStateDyna rotationalInput;
    CHmsDyna::CHmsStateDyna rotationalOutput;
    rotationalInput.Initialize();
    rotationalOutput.Initialize();
    rotationalInput.m_position = GmVec3(10.0f, 20.0f, 30.0f);
    rotationalInput.m_linearSpeed = GmVec3(1.0f, 2.0f, 3.0f);
    rotationalInput.m_additionalLinearSpeed = GmVec3(0.5f, -0.5f, 1.0f);
    rotationalInput.m_force = GmVec3(4.0f, 6.0f, 8.0f);
    rotationalInput.m_angularSpeed = GmVec3(1.0f, 2.0f, 3.0f);
    rotationalInput.m_torque = GmVec3(2.0f, 3.0f, 4.0f);
    rotationalInput.m_worldInverseInertia =
        rotationalPhysical.m_inverseInertia;
    constexpr float kRotationalDt = 0.1f;
    rotationalBody.IntegrateStep(
        &rotationalInput, &rotationalOutput, kRotationalDt);

    GmQuat expectedRotation{1.0f, 0.05f, 0.1f, 0.15f};
    expectedRotation.Normalize();
    GmMat3 expectedRotationMatrix;
    expectedRotationMatrix.Set(expectedRotation);
    passed &= Expect("world angular velocity left-multiplies quaternion",
                     Near(rotationalOutput.m_rotation.w, expectedRotation.w) &&
                     Near(rotationalOutput.m_rotation.x, expectedRotation.x) &&
                     Near(rotationalOutput.m_rotation.y, expectedRotation.y) &&
                     Near(rotationalOutput.m_rotation.z, expectedRotation.z) &&
                     MatNear(rotationalOutput.m_rotationMatrix,
                             expectedRotationMatrix));
    passed &= Expect("world inertia applies torque on all axes",
                     VecNear(rotationalOutput.m_angularSpeed,
                             GmVec3(1.4f, 2.9f, 4.6f)));
    passed &= Expect("physical mass drives linear acceleration",
                     VecNear(rotationalOutput.m_linearSpeed,
                             GmVec3(1.2f, 2.3f, 3.4f)) &&
                     VecNear(rotationalOutput.m_additionalLinearSpeed,
                             GmVec3(0.0f, 0.0f, 0.0f)));

    const GmVec3 expectedCenterOfMass =
        rotationalInput.m_position + rotationalPhysical.m_centerOfMass +
        (rotationalInput.m_linearSpeed +
         rotationalInput.m_additionalLinearSpeed) * kRotationalDt;
    const GmVec3 actualCenterOfMass =
        rotationalOutput.m_position + TransformVector(
            rotationalOutput.m_rotationMatrix,
            rotationalPhysical.m_centerOfMass);
    passed &= Expect("rotation preserves translated center of mass",
                     VecNear(actualCenterOfMass, expectedCenterOfMass));

    GmMat3 expectedWorldInverseInertia;
    expectedWorldInverseInertia.SetTranspose(expectedRotationMatrix);
    expectedWorldInverseInertia.Mult(
        rotationalPhysical.m_inverseInertia);
    expectedWorldInverseInertia.Mult(expectedRotationMatrix);
    passed &= Expect("world inverse inertia is R I R transpose",
                     MatNear(rotationalOutput.m_worldInverseInertia,
                             expectedWorldInverseInertia));

    rotationalBody.m_field_0xc0 = 1;
    rotationalBody.m_field_0xc4 = 2.0f;
    rotationalInput.m_angularSpeed = GmVec3(3.0f, 0.0f, 0.0f);
    rotationalInput.m_torque = GmVec3(0.0f, 0.0f, 0.0f);
    rotationalBody.IntegrateStep(
        &rotationalInput, &rotationalOutput, kRotationalDt);
    passed &= Expect("native optional angular speed clamp",
                     VecNear(rotationalOutput.m_angularSpeed,
                             GmVec3(2.0f, 0.0f, 0.0f)));

    CPlugPhysicalObject localApiPhysical;
    localApiPhysical.m_mass = 2.0f;
    CHmsDyna localApiBody;
    localApiBody.m_field_0x108 = &localApiPhysical;
    localApiBody.CurrentState().m_rotation =
        GmQuat{0.5f, 0.5f, 0.5f, 0.5f};
    localApiBody.CurrentState().m_rotationMatrix.Set(
        localApiBody.CurrentState().m_rotation);
    GmVec3 localVector{1.0f, 2.0f, 3.0f};
    localApiBody.SetLocalForce(&localVector);
    GmVec3 recoveredLocal;
    localApiBody.GetLocalForce(&recoveredLocal);
    passed &= Expect("local force uses full rotation and transpose",
                     VecNear(localApiBody.Force(),
                             GmVec3(3.0f, 1.0f, 2.0f)) &&
                     VecNear(recoveredLocal, localVector));
    localApiBody.AddLocalForce(&localVector);
    localApiBody.GetLocalForce(&recoveredLocal);
    passed &= Expect("local force addition uses full rotation",
                     VecNear(localApiBody.Force(),
                             GmVec3(6.0f, 2.0f, 4.0f)) &&
                     VecNear(recoveredLocal,
                             GmVec3(2.0f, 4.0f, 6.0f)));

    GmVec3 localTorque{-1.0f, 4.0f, 2.0f};
    localApiBody.SetLocalTorque(&localTorque);
    passed &= Expect("local torque uses full rotation",
                     VecNear(localApiBody.Torque(),
                             GmVec3(2.0f, -1.0f, 4.0f)));
    localApiBody.Torque() = GmVec3(0.0f, 0.0f, 0.0f);
    localApiBody.AddLocalTorque(&localTorque);
    passed &= Expect("local torque addition uses full rotation",
                     VecNear(localApiBody.Torque(),
                             GmVec3(2.0f, -1.0f, 4.0f)));

    GmVec3 localAngularSpeed{4.0f, 5.0f, 6.0f};
    localApiBody.SetLocalAngularSpeed(&localAngularSpeed);
    localApiBody.GetLocalAngularSpeed(&recoveredLocal);
    passed &= Expect("local angular-speed round trip",
                     VecNear(localApiBody.AngularSpeed(),
                             GmVec3(6.0f, 4.0f, 5.0f)) &&
                     VecNear(recoveredLocal, localAngularSpeed));

    GmVec3 localLinearSpeed{7.0f, 8.0f, 9.0f};
    localApiBody.SetLocalLinearSpeed(&localLinearSpeed);
    localApiBody.GetLocalLinearSpeed(&recoveredLocal);
    GmVec3 recoveredWorld;
    localApiBody.GetLinearSpeed(nullptr, &recoveredWorld);
    passed &= Expect("local linear-speed round trip",
                     VecNear(localApiBody.CurrentState().m_linearSpeed,
                             GmVec3(9.0f, 7.0f, 8.0f)) &&
                     VecNear(recoveredLocal, localLinearSpeed) &&
                     VecNear(recoveredWorld,
                             GmVec3(9.0f, 7.0f, 8.0f)));
    localApiBody.CurrentState().m_linearSpeed =
        GmVec3(0.0f, 0.0f, 0.0f);
    GmVec3 localImpulse{2.0f, 4.0f, 6.0f};
    localApiBody.AddLocalImpulse(&localImpulse);
    localApiBody.GetLocalLinearSpeed(&recoveredLocal);
    passed &= Expect("local impulse rotates before inverse mass",
                     VecNear(localApiBody.CurrentState().m_linearSpeed,
                             GmVec3(3.0f, 1.0f, 2.0f)) &&
                     VecNear(recoveredLocal,
                             GmVec3(1.0f, 2.0f, 3.0f)));

    CHmsDyna translationOnlyBody;
    CHmsDyna::CHmsStateDyna translationOnlyInput;
    CHmsDyna::CHmsStateDyna translationOnlyOutput;
    translationOnlyInput.Initialize();
    translationOnlyOutput.Initialize();
    translationOnlyInput.m_rotationMatrix.SetRotateQuarterY(1);
    translationOnlyInput.m_position = GmVec3(1.0f, 2.0f, 3.0f);
    translationOnlyInput.m_linearSpeed = GmVec3(4.0f, 5.0f, 6.0f);
    translationOnlyOutput.m_rotation = GmQuat{2.0f, 3.0f, 4.0f, 5.0f};
    translationOnlyOutput.m_angularSpeed = GmVec3(7.0f, 8.0f, 9.0f);
    translationOnlyBody.IntegrateStep(
        &translationOnlyInput, &translationOnlyOutput, 0.25f);
    passed &= Expect("translation-only integration copies only matrix",
                     MatNear(translationOnlyOutput.m_rotationMatrix,
                             translationOnlyInput.m_rotationMatrix) &&
                     Near(translationOnlyOutput.m_rotation.w, 2.0f) &&
                     VecNear(translationOnlyOutput.m_angularSpeed,
                             GmVec3(7.0f, 8.0f, 9.0f)) &&
                     VecNear(translationOnlyOutput.m_position,
                             GmVec3(2.0f, 3.25f, 4.5f)));

    translationOnlyBody.m_dynamicType = 2;
    translationOnlyInput.m_owner32 = 0x89abcdefu;
    translationOnlyOutput.m_owner32 = 0u;
    translationOnlyBody.IntegrateStep(
        &translationOnlyInput, &translationOnlyOutput, 42.0f);
    passed &= Expect("fixed integration copies all 0x2d native words",
                     std::memcmp(&translationOnlyInput,
                                 &translationOnlyOutput,
                                 sizeof(translationOnlyInput)) == 0);

    CPlugPhysicalObject zoneStepPhysical;
    zoneStepPhysical.m_mass = 2.0f;
    zoneStepPhysical.m_inverseInertia.SetIdentity();
    zoneStepPhysical.m_inverseInertia.m00 = 2.0f;
    zoneStepPhysical.m_inverseInertia.m11 = 3.0f;
    zoneStepPhysical.m_inverseInertia.m22 = 4.0f;
    CHmsItem zoneStepItem;
    CHmsCorpus* zoneStepCorpus = new CHmsCorpus();
    zoneStepCorpus->m_item = &zoneStepItem;
    zoneStepCorpus->m_dyna = new CHmsDyna();
    zoneStepItem.m_corpuses.Add(zoneStepCorpus);
    CHmsDyna& zoneStepDyna = *zoneStepCorpus->m_dyna;
    zoneStepDyna.m_field_0x108 = &zoneStepPhysical;
    zoneStepDyna.m_dynamicType = 1;
    zoneStepDyna.UpdateWorldInverseInertia();
    zoneStepDyna.Position() = GmVec3(1.0f, 2.0f, 3.0f);
    zoneStepDyna.CurrentState().m_linearSpeed =
        GmVec3(4.0f, 5.0f, 6.0f);
    zoneStepDyna.AngularSpeed() = GmVec3(0.0f, 1.0f, 0.0f);
    CHmsZoneDynamic zoneStep;
    zoneStep.m_dynamicCorpuses.Add(zoneStepCorpus);
    // Standalone callers may prepare the native base forces first and then
    // add an external force adapter before advancing the already-prepared
    // frame. PhysicsStep2 itself performs preparation when this is omitted.
    zoneStep.PrepareForPhysicsStep(0.01f);
    zoneStepDyna.Force() = GmVec3(2.0f, 4.0f, 6.0f);
    zoneStepDyna.Torque() = GmVec3(0.0f, 2.0f, 0.0f);
    zoneStep.PhysicsStep2(0.01f);
    passed &= Expect("zone step uses native pre-collision integrator",
                     VecNear(zoneStepDyna.Position(),
                             GmVec3(1.04f, 2.05f, 3.06f)) &&
                     VecNear(zoneStepDyna.CurrentState().m_linearSpeed,
                             GmVec3(4.01f, 5.02f, 6.03f)) &&
                     VecNear(zoneStepDyna.AngularSpeed(),
                             GmVec3(0.0f, 1.06f, 0.0f)) &&
                     !Near(zoneStepDyna.CurrentState().m_rotation.y, 0.0f));
    passed &= Expect("prepared zone step preserves adapter forces",
                     VecNear(zoneStepDyna.Force(),
                             GmVec3(2.0f, 4.0f, 6.0f)) &&
                     VecNear(zoneStepDyna.Torque(),
                             GmVec3(0.0f, 2.0f, 0.0f)));

    CHmsDyna independentBody;
    independentBody.Position() = GmVec3(50.0f, 60.0f, 70.0f);
    independentBody.Force() = GmVec3(4.0f, 5.0f, 6.0f);
    passed &= Expect("dynamic position is per body",
                     VecNear(independentBody.Position(),
                             GmVec3(50.0f, 60.0f, 70.0f)) &&
                     VecNear(dyna.Position(), GmVec3(1.0f, 0.0f, 0.0f)));
    passed &= Expect("dynamic force accumulator is per body",
                     VecNear(independentBody.Force(),
                             GmVec3(4.0f, 5.0f, 6.0f)) &&
                     VecNear(dyna.Force(), GmVec3(1.0f, 0.0f, 0.0f)));

    // CHmsStateDyna is a plain 0xB4-byte value in the executable. The working
    // state remains independent from the validated snapshot until the native
    // ValidateDynamicState copy boundary is crossed.
    independentBody.SetYaw(0.75f);
    independentBody.ValidateDynamicState();
    independentBody.Position().x = 80.0f;
    passed &= Expect("validated state is a distinct 0xB4 snapshot",
                     Near(independentBody.ValidatedState().m_position.x, 50.0f) &&
                     Near(independentBody.Position().x, 80.0f));
    independentBody.CopyStateToTemp();
    independentBody.Position().x = 90.0f;
    independentBody.CopyTempToState();
    passed &= Expect("state temporary copies all 0x2d native words",
                     Near(independentBody.ValidatedState().m_position.x, 80.0f) &&
                     Near(independentBody.Position().x, 90.0f));

    CHmsDyna::CHmsStateDyna resetState;
    resetState.Initialize();
    resetState.m_position = GmVec3(3.0f, 4.0f, 5.0f);
    resetState.m_linearSpeed = GmVec3(1.0f, 2.0f, 3.0f);
    resetState.m_additionalLinearSpeed = GmVec3(4.0f, 5.0f, 6.0f);
    resetState.m_angularSpeed = GmVec3(7.0f, 8.0f, 9.0f);
    resetState.m_force = GmVec3(10.0f, 11.0f, 12.0f);
    resetState.m_torque = GmVec3(13.0f, 14.0f, 15.0f);
    resetState.m_hasSavedLinearSpeed = 1;
    resetState.m_savedLinearSpeed = GmVec3(16.0f, 17.0f, 18.0f);
    resetState.Reset(nullptr);
    passed &= Expect("state reset preserves transform and clears dynamics",
                     VecNear(resetState.m_position, GmVec3(3.0f, 4.0f, 5.0f)) &&
                     VecNear(resetState.m_linearSpeed, GmVec3(0.0f, 0.0f, 0.0f)) &&
                     VecNear(resetState.m_additionalLinearSpeed,
                             GmVec3(0.0f, 0.0f, 0.0f)) &&
                     VecNear(resetState.m_angularSpeed, GmVec3(0.0f, 0.0f, 0.0f)) &&
                     VecNear(resetState.m_force, GmVec3(0.0f, 0.0f, 0.0f)) &&
                     VecNear(resetState.m_torque, GmVec3(0.0f, 0.0f, 0.0f)) &&
                     resetState.m_hasSavedLinearSpeed == 0 &&
                     VecNear(resetState.m_savedLinearSpeed,
                             GmVec3(0.0f, 0.0f, 0.0f)));

    CHmsDyna serializedBody;
    serializedBody.ValidatedState().m_position =
        GmVec3(1.0f, 2.0f, 3.0f);
    serializedBody.ValidatedState().m_rotation.SetIdentity();
    serializedBody.ValidatedState().m_rotationMatrix.SetIdentity();
    serializedBody.ValidatedState().m_linearSpeed =
        GmVec3(1.0f, 0.0f, 0.0f);
    serializedBody.ValidatedState().m_angularSpeed =
        GmVec3(0.0f, 0.0f, 1.0f);
    serializedBody.ValidatedState().m_hasSavedLinearSpeed = 1u;
    serializedBody.ValidatedState().m_savedLinearSpeed =
        GmVec3(0.0f, 1.0f, 0.0f);
    serializedBody.CurrentState().m_position =
        GmVec3(100.0f, 200.0f, 300.0f);

    CClassicBufferMemory compressedStateBuffer;
    serializedBody.SaveState(
        reinterpret_cast<CSceneToyBoat*>(&compressedStateBuffer),
        nullptr, nullptr, 0u);
    passed &= Expect("low-quality dynamic state is fifteen bytes",
                     compressedStateBuffer.m_size == 15u);

    CHmsDyna restoredBody;
    restoredBody.CurrentState().m_linearSpeed =
        GmVec3(7.0f, 8.0f, 9.0f);
    compressedStateBuffer.Reset();
    restoredBody.RestoreStaticState(
        reinterpret_cast<CSceneToyBoat*>(&compressedStateBuffer),
        nullptr, 0, 0u, 0u, 0);
    GmMat3 restoredIdentity;
    restoredIdentity.SetIdentity();
    passed &= Expect("low-quality restore targets current state only",
                     VecNear(restoredBody.CurrentState().m_position,
                             GmVec3(0.99800003f,
                                    1.99800003f,
                                    2.99800014f)) &&
                     VecNear(restoredBody.CurrentState().m_linearSpeed,
                             GmVec3(7.0f, 8.0f, 9.0f)) &&
                     VecNear(restoredBody.ValidatedState().m_position,
                             GmVec3(0.0f, 0.0f, 0.0f)) &&
                     MatNear(restoredBody.CurrentState().m_rotationMatrix,
                             restoredIdentity));

    compressedStateBuffer.Reset();
    restoredBody.RestoreStaticState(
        reinterpret_cast<CSceneToyBoat*>(&compressedStateBuffer),
        reinterpret_cast<CClassicBufferMemory*>(1),
        0, 0u, 0u, 0);
    passed &= Expect("nonzero restore selector targets validated state",
                     VecNear(restoredBody.ValidatedState().m_position,
                             GmVec3(0.99800003f,
                                    1.99800003f,
                                    2.99800014f)));

    CClassicBufferMemory fullStateBuffer;
    serializedBody.SaveState(
        reinterpret_cast<CSceneToyBoat*>(&fullStateBuffer),
        reinterpret_cast<CClassicBufferMemory*>(1), nullptr, 0u);
    passed &= Expect("full-quality dynamic state is twenty-six bytes",
                     fullStateBuffer.m_size == 26u);
    fullStateBuffer.Reset();
    restoredBody.RestoreStaticState(
        reinterpret_cast<CSceneToyBoat*>(&fullStateBuffer),
        nullptr, 1, 0u, 0u, 0);
    passed &= Expect("full restore uses validated saved linear speed",
                     VecNear(restoredBody.CurrentState().m_position,
                             GmVec3(1.0f, 2.0f, 3.0f)) &&
                     std::abs(restoredBody.CurrentState().m_linearSpeed.x) <
                         0.02f &&
                     restoredBody.CurrentState().m_linearSpeed.y > 0.99f &&
                     std::abs(restoredBody.CurrentState().m_linearSpeed.z) <
                         0.02f &&
                     std::abs(restoredBody.CurrentState().m_angularSpeed.x) <
                         0.02f &&
                     std::abs(restoredBody.CurrentState().m_angularSpeed.y) <
                         0.02f &&
                     restoredBody.CurrentState().m_angularSpeed.z > 0.99f);

    CHmsDyna differenceBody;
    GmIso4 comparisonLocation;
    comparisonLocation.SetIdentity();
    comparisonLocation.SetTranslation(GmVec3(3.0f, 4.0f, 5.0f));
    differenceBody.SetLocation(nullptr, &comparisonLocation);
    passed &= Expect("identical validated location is not different",
                     differenceBody.IsStateDifferentFrom(
                         nullptr, &comparisonLocation) == 0);
    comparisonLocation.tX += 0.003f;
    passed &= Expect("state difference uses squared 1e-5 threshold",
                     differenceBody.IsStateDifferentFrom(
                         nullptr, &comparisonLocation) == 0);
    comparisonLocation.tX += 0.0002f;
    passed &= Expect("translation beyond native threshold is different",
                     differenceBody.IsStateDifferentFrom(
                         nullptr, &comparisonLocation) == 1);
    comparisonLocation.SetTranslation(GmVec3(3.0f, 4.0f, 5.0f));
    comparisonLocation.m00 += 0.0032f;
    passed &= Expect("rotation row beyond native threshold is different",
                     differenceBody.IsStateDifferentFrom(
                         nullptr, &comparisonLocation) == 1);

    CHmsDyna rotateBody;
    rotateBody.Position() = GmVec3(7.0f, 8.0f, 9.0f);
    rotateBody.SetYaw(0.35f);
    const GmMat3 beforeRotation =
        rotateBody.CurrentState().m_rotationMatrix;
    GmQuat rotationDeltaQuat;
    rotationDeltaQuat.SetRotation(GmVec3(1.0f, 0.0f, 0.0f), 0.4f);
    GmMat3 rotationDelta;
    rotationDelta.Set(rotationDeltaQuat);
    GmMat3 expectedRotated;
    expectedRotated.SetMult(rotationDelta, beforeRotation);
    expectedRotated.OrthoNormalize();
    rotateBody.RotateOf(nullptr, &rotationDelta);
    passed &= Expect("RotateOf composes and updates both state snapshots",
                     MatNear(rotateBody.CurrentState().m_rotationMatrix,
                             expectedRotated) &&
                     MatNear(rotateBody.ValidatedState().m_rotationMatrix,
                             expectedRotated) &&
                     VecNear(rotateBody.Position(),
                             GmVec3(7.0f, 8.0f, 9.0f)));

    CHmsCorpus interpolatedCorpus;
    interpolatedCorpus.m_dyna = new CHmsDyna();
    CHmsDyna& interpolatedDyna = *interpolatedCorpus.m_dyna;
    interpolatedDyna.ValidatedState().m_rotationMatrix.SetIdentity();
    interpolatedDyna.ValidatedState().m_rotation.SetIdentity();
    interpolatedDyna.ValidatedState().m_position =
        GmVec3(0.0f, 2.0f, 4.0f);
    interpolatedDyna.CurrentState().m_rotationMatrix = expectedRotated;
    interpolatedDyna.CurrentState().m_rotation.Set(expectedRotated);
    interpolatedDyna.CurrentState().m_position =
        GmVec3(8.0f, 10.0f, 12.0f);
    GmIso4 validatedIso;
    validatedIso.rot =
        interpolatedDyna.ValidatedState().m_rotationMatrix;
    validatedIso.SetTranslation(
        interpolatedDyna.ValidatedState().m_position);
    GmIso4 currentIso;
    currentIso.rot = interpolatedDyna.CurrentState().m_rotationMatrix;
    currentIso.SetTranslation(interpolatedDyna.CurrentState().m_position);
    GmIso4 expectedInterpolatedIso;
    expectedInterpolatedIso.SetBlend(validatedIso, currentIso, 0.25f);
    interpolatedCorpus.ComputeCurrentState(nullptr, 0.25f);
    passed &= Expect("corpus current state blends full 3D transforms",
                     MatNear(interpolatedCorpus.m_location.rot,
                             expectedInterpolatedIso.rot) &&
                     Near(interpolatedCorpus.m_location.tX,
                          expectedInterpolatedIso.tX) &&
                     Near(interpolatedCorpus.m_location.tY,
                          expectedInterpolatedIso.tY) &&
                     Near(interpolatedCorpus.m_location.tZ,
                          expectedInterpolatedIso.tZ));

    CHmsCorpus staticRotatedCorpus;
    staticRotatedCorpus.m_location.SetIdentity();
    staticRotatedCorpus.m_location.SetTranslation(
        GmVec3(11.0f, 12.0f, 13.0f));
    staticRotatedCorpus.RotateOf(nullptr, &rotationDelta);
    passed &= Expect("static corpus RotateOf preserves translation",
                     MatNear(staticRotatedCorpus.m_location.rot,
                             rotationDelta) &&
                     Near(staticRotatedCorpus.m_location.tX, 11.0f) &&
                     Near(staticRotatedCorpus.m_location.tY, 12.0f) &&
                     Near(staticRotatedCorpus.m_location.tZ, 13.0f));

    // SDynaMath 0x7BD090 uses lever x normal and the point's rotational
    // response in its effective-mass denominator.
    GmMat3 impulseInverseInertia;
    impulseInverseInertia.SetIdentity();
    const GmVec3 impulseRelativeSpeed(0.0f, -4.0f, 0.0f);
    const GmVec3 impulseNormal(0.0f, 1.0f, 0.0f);
    const GmVec3 impulseLever(1.0f, 0.0f, 0.0f);
    GmVec3 computedImpulse;
    SDynaMath::ComputeImpulse(
        2.0f, &impulseInverseInertia, 0.5f,
        &impulseRelativeSpeed, &impulseNormal, &impulseLever,
        &computedImpulse);
    passed &= Expect("SDynaMath includes angular point response",
                     VecNear(computedImpulse,
                             GmVec3(0.0f, 4.0f / 3.0f, 0.0f)));

    CPlugPhysicalObject contactPhysical;
    contactPhysical.m_mass = 1.0f;
    contactPhysical.m_inverseInertia.SetIdentity();
    contactPhysical.m_centerOfMass = GmVec3(0.0f, 0.0f, 0.0f);
    CHmsCorpus* impulseCorpus = new CHmsCorpus();
    impulseCorpus->m_dyna = new CHmsDyna();
    impulseCorpus->m_dyna->m_field_0x108 = &contactPhysical;
    impulseCorpus->m_dyna->m_dynamicType = 1;
    impulseCorpus->m_dyna->CurrentState().m_worldInverseInertia.SetIdentity();
    CHmsItem impulseItem;
    impulseItem.m_corpuses.Add(impulseCorpus);
    CSceneVehicleCar impulseCar;
    impulseCar.m_hmsItem = &impulseItem;

    const GmVec3 contactLocalImpulse(0.0f, 3.0f, 0.0f);
    const GmVec3 localImpulsePoint(1.0f, 0.0f, 0.0f);
    impulseCar.AddVehicleImpulse(&contactLocalImpulse, &localImpulsePoint);
    passed &= Expect("vehicle local impulse updates linear and angular speed",
                     VecNear(impulseCorpus->m_dyna->CurrentState().m_linearSpeed,
                             GmVec3(0.0f, 3.0f, 0.0f)) &&
                     VecNear(impulseCorpus->m_dyna->CurrentState().m_angularSpeed,
                             GmVec3(0.0f, 0.0f, 3.0f)) &&
                     VecNear(impulseCar.m_appliedImpulseSum,
                             contactLocalImpulse));

    // GmMap2 0x4FF950 truncates toward zero before unsigned bounds checks.
    // This makes a point less than one cell below the origin select cell zero.
    GmMap2<uint8_t> truncationMap;
    truncationMap.Init(0.0f, 0.0f, 1.0f, 1.0f, 1u, 1u, 0u);
    passed &= Expect("water mask preserves native truncation at origin",
                     truncationMap.IsInside(-0.25f, -0.25f) &&
                     !truncationMap.IsInside(-1.25f, 0.0f));

    // ApplyWaterForces 0x7C2910 consumes the collision zone's byte mask and
    // transformed car AABB. Exercise both its continuous and impulse exits.
    CHmsZone waterZone;
    waterZone.m_waterCollisionMap.Init(
        -1.0f, -1.0f, 2.0f, 2.0f, 1u, 1u, 0u);
    waterZone.m_waterCollisionMap.SetValue(0u, 0u, 1u);
    waterZone.m_waterCollisionSurfaceHeight = 0.25f;
    waterZone.m_waterCollisionBottomHeight = -10.0f;
    impulseCorpus->m_zone = &waterZone;
    impulseCar.m_localBodyBounds.SetCenterHalfDiag(
        GmVec3(0.0f, 0.0f, 0.0f), GmVec3(0.5f, 0.5f, 1.0f));
    CHmsDyna::CHmsStateDyna& waterState =
        impulseCorpus->m_dyna->CurrentState();
    waterState.m_rotationMatrix.SetIdentity();
    waterState.m_position = GmVec3(0.0f, 0.0f, 0.0f);
    waterState.m_linearSpeed = GmVec3(1.0f, 0.0f, 0.0f);
    waterState.m_angularSpeed = GmVec3(0.0f, 2.0f, 0.0f);
    waterState.m_force = GmVec3(0.0f, -3.0f, 0.0f);
    waterState.m_torque = GmVec3(0.0f, 0.0f, 0.0f);
    impulseCar.m_hasAnyContact = 1;
    const GmVec3 accumulatedWaterForce(0.0f, -3.0f, 0.0f);
    const int continuousWater =
        impulseCar.ApplyWaterForces(&accumulatedWaterForce);
    const float expectedWaterDrag =
        0.2f + (1.6f / 48.0f) * 0.8f;
    passed &= Expect(
        "water contact replaces gravity and applies linear/angular drag",
        continuousWater == 1 &&
        VecNear(waterState.m_force,
                GmVec3(-expectedWaterDrag, -1.0f, 0.0f)) &&
        VecNear(waterState.m_torque, GmVec3(0.0f, -1.0f, 0.0f)) &&
        impulseCar.m_waterSplashCount == 0u);

    waterState.m_force = GmVec3(0.0f, 0.0f, 0.0f);
    waterState.m_torque = GmVec3(0.0f, 0.0f, 0.0f);
    waterZone.m_waterCollisionSurfaceHeight = 0.0f;
    const GmVec3 zeroAccumulatedForce(0.0f, 0.0f, 0.0f);
    passed &= Expect(
        "water depth threshold is strict at one half",
        impulseCar.ApplyWaterForces(&zeroAccumulatedForce) == 0 &&
        VecNear(waterState.m_force, GmVec3(0.0f, 0.0f, 0.0f)));

    waterZone.m_waterCollisionSurfaceHeight = 0.25f;
    waterState.m_linearSpeed = GmVec3(60.0f, -10.0f, 0.0f);
    waterState.m_angularSpeed = GmVec3(0.0f, 0.0f, 0.0f);
    impulseCar.m_hasAnyContact = 0;
    impulseCar.m_appliedCentralImpulseSum = GmVec3(0.0f, 0.0f, 0.0f);
    const int horizontalRebound =
        impulseCar.ApplyWaterForces(&zeroAccumulatedForce);
    passed &= Expect(
        "fast shallow water contact emits ratio rebound and no contact flag",
        horizontalRebound == 0 &&
        VecNear(impulseCar.m_appliedCentralImpulseSum,
                GmVec3(-90.0f, 6.0f, 0.0f)) &&
        VecNear(waterState.m_linearSpeed,
                GmVec3(-30.0f, -4.0f, 0.0f)) &&
        impulseCar.m_waterSplashCount == 1u &&
        VecNear(impulseCar.m_lastWaterSplashSpeed,
                GmVec3(60.0f, -10.0f, 0.0f)));

    waterState.m_linearSpeed = GmVec3(0.0f, -60.0f, 0.0f);
    impulseCar.m_appliedCentralImpulseSum = GmVec3(0.0f, 0.0f, 0.0f);
    const int verticalBump =
        impulseCar.ApplyWaterForces(&zeroAccumulatedForce);
    passed &= Expect(
        "low-horizontal high-speed water impact uses zero-ratio bump",
        verticalBump == 0 &&
        VecNear(impulseCar.m_appliedCentralImpulseSum,
                GmVec3(0.0f, 42.0f, 0.0f)) &&
        VecNear(waterState.m_linearSpeed,
                GmVec3(0.0f, -18.0f, 0.0f)) &&
        impulseCar.m_waterSplashCount == 2u);

    impulseCorpus->m_zone = nullptr;

    // The exact Model6 entry receives all eleven native stack arguments. Its
    // first grounded producer visits every wheel and applies suspension force
    // before the longitudinal/lateral tail; engine state two bypasses it.
    tuning.m_steerModel = 5;
    tuning.m_shockModel = 2;
    impulseCar.m_inputGas = 0.0f;
    impulseCar.m_inputBrake = 0.0f;
    impulseCar.m_field_0x600 = 0;
    impulseCar.m_freeWheeling = 0;
    impulseCar.m_engine.m_field_0x28 = 0;
    for (uint32_t index = 0u;
         index < impulseCar.m_wheels.GetCount(); ++index) {
        impulseCar.m_wheels[index].m_hasGroundContact = 0;
        impulseCar.m_wheels[index].m_isSlipping = 0;
    }
    CSceneVehicleCar::SSimulationWheel& model6SuspensionWheel =
        impulseCar.m_wheels[0];
    model6SuspensionWheel.m_hasGroundContact = 1;
    model6SuspensionWheel.m_realTimeState.m_compression = 0.15f;
    model6SuspensionWheel.m_realTimeState.m_velocity = 0.5f;
    model6SuspensionWheel.m_localContactPosition =
        GmVec3(0.0f, 0.0f, 0.0f);
    waterState.m_linearSpeed = GmVec3(0.0f, 0.0f, 0.0f);
    waterState.m_angularSpeed = GmVec3(0.0f, 0.0f, 0.0f);
    waterState.m_force = GmVec3(0.0f, 0.0f, 0.0f);
    waterState.m_torque = GmVec3(0.0f, 0.0f, 0.0f);
    StadiumVehicleMaterials::GroundValues model6Ground{
        1.0f, 1.0f, 1.0f, 1.0f};
    GmVec3 model6Snapshot(0.0f, 0.0f, 0.0f);
    GmVec3 model6LinearSpeed(0.0f, 0.0f, 0.0f);
    GmVec3 model6AngularSpeed(0.0f, 0.0f, 0.0f);
    int model6HasSlippingWheel = -1;
    float model6AxialBrakeForce = -1.0f;
    impulseCar.m_engineState = 0;
    impulseCar.ComputeForcesModel6(
        0.01f, &model6Snapshot, 1.0f, 1.0f,
        &model6LinearSpeed, &model6AngularSpeed, 0.0f, 1,
        &model6Ground, &model6HasSlippingWheel,
        &model6AxialBrakeForce);
    passed &= Expect(
        "Model6 applies grounded suspension before its force tail",
        Near(model6SuspensionWheel.m_suspensionForce, 1.5f) &&
        VecNear(waterState.m_force, GmVec3(0.0f, 1.5f, 0.0f)) &&
        model6HasSlippingWheel == 0 &&
        Near(model6AxialBrakeForce, 0.0f));

    waterState.m_force = GmVec3(0.0f, 0.0f, 0.0f);
    impulseCar.m_engineState = 2;
    impulseCar.ComputeForcesModel6(
        0.01f, &model6Snapshot, 1.0f, 1.0f,
        &model6LinearSpeed, &model6AngularSpeed, 0.0f, 1,
        &model6Ground, &model6HasSlippingWheel,
        &model6AxialBrakeForce);
    passed &= Expect(
        "Model6 engine state two bypasses wheel suspension",
        VecNear(waterState.m_force, GmVec3(0.0f, 0.0f, 0.0f)));
    impulseCar.m_engineState = 0;
    model6SuspensionWheel.m_hasGroundContact = 0;

    impulseCorpus->m_dyna->CurrentState().m_linearSpeed =
        GmVec3(0.0f, 0.0f, 0.0f);
    impulseCorpus->m_dyna->CurrentState().m_angularSpeed =
        GmVec3(0.0f, 0.0f, 0.0f);
    impulseCar.m_appliedImpulseSum = GmVec3(0.0f, 0.0f, 0.0f);
    CHmsPhysicalContact model2BodyContact{};
    model2BodyContact.m_collisionData = 0x12345678u;
    model2BodyContact.m_otherMaterialId = 9u;
    model2BodyContact.m_localNormal = GmVec3(0.0f, 1.0f, 0.0f);
    model2BodyContact.m_localPoint = GmVec3(0.0f, 0.0f, 0.0f);
    model2BodyContact.m_relativeSpeed = GmVec3(4.0f, -4.0f, 0.0f);
    model2BodyContact.m_isActive = 1u;
    impulseCar.AbsorbContact(&model2BodyContact);
    passed &= Expect("ShockModel2 chassis impulse limits tangent by body friction",
                     model2BodyContact.m_isActive == 0u &&
                     impulseCar.m_appliedImpulseSum.x < 0.0f &&
                     impulseCar.m_appliedImpulseSum.y > 0.0f &&
                     Near(impulseCar.m_appliedImpulseSum.x /
                              impulseCar.m_appliedImpulseSum.y,
                          -tuning.m_bodyFrictionCoef));

    impulseCorpus->m_dyna->CurrentState().m_linearSpeed =
        GmVec3(0.0f, 0.0f, 0.0f);
    impulseCorpus->m_dyna->CurrentState().m_angularSpeed =
        GmVec3(0.0f, 0.0f, 0.0f);
    impulseCar.m_appliedImpulseSum = GmVec3(0.0f, 0.0f, 0.0f);
    CSceneVehicleCar::SSimulationWheel model2Wheel;
    CHmsPhysicalContact directWheelContact{};
    directWheelContact.m_otherMaterialId = 9u;
    directWheelContact.m_localNormal = GmVec3(0.0f, 1.0f, 0.0f);
    directWheelContact.m_localPoint = GmVec3(0.0f, 0.0f, 0.0f);
    directWheelContact.m_relativeSpeed = GmVec3(0.0f, -2.0f, 0.0f);
    directWheelContact.m_replacement = GmVec3(0.0f, 0.0f, 0.0f);
    directWheelContact.m_isActive = 1u;
    impulseCar.WheelAbsorbContact(&model2Wheel, &directWheelContact);
    passed &= Expect("ShockModel2 grounded wheel applies concrete restitution",
                     directWheelContact.m_isActive == 0u &&
                     Near(impulseCar.m_appliedImpulseSum.y, 0.4f) &&
                     Near(impulseCorpus->m_dyna->CurrentState().m_linearSpeed.y,
                          0.4f));

    impulseCorpus->m_dyna->CurrentState().m_linearSpeed =
        GmVec3(0.0f, 0.0f, 0.0f);
    impulseCorpus->m_dyna->CurrentState().m_angularSpeed =
        GmVec3(0.0f, 0.0f, 0.0f);
    impulseCar.m_appliedImpulseSum = GmVec3(0.0f, 0.0f, 0.0f);
    model2Wheel.m_realTimeState.m_compression = 0.5f;
    model2Wheel.m_realTimeState.m_absorbDelta = 0.0f;
    model2Wheel.m_surfaceHandler.m_surfaceLocation.SetIdentity();
    model2Wheel.m_surfaceHandler.m_surfaceLocation.SetTranslation(
        GmVec3(2.0f, 0.0f, 0.0f));
    CHmsPhysicalContact absorbedWheelContact{};
    absorbedWheelContact.m_otherMaterialId = 9u;
    absorbedWheelContact.m_localNormal = GmVec3(0.6f, 0.8f, 0.0f);
    absorbedWheelContact.m_localPoint = GmVec3(0.0f, 0.0f, 0.0f);
    absorbedWheelContact.m_relativeSpeed = GmVec3(-1.2f, -1.6f, 0.0f);
    absorbedWheelContact.m_replacement = GmVec3(0.0f, 0.2f, 0.0f);
    absorbedWheelContact.m_isActive = 1u;
    impulseCar.WheelAbsorbContact(&model2Wheel, &absorbedWheelContact);
    passed &= Expect("ShockModel2 damper absorbs replacement at wheel surface",
                     Near(absorbedWheelContact.m_replacement.y, 0.0f) &&
                     Near(model2Wheel.m_realTimeState.m_absorbDelta, 0.2f) &&
                     impulseCorpus->m_dyna->CurrentState().m_angularSpeed.z >
                         0.0f);

    // WheelAbsorbContact 0x7C129C observes the other corpus's local +Z axis
    // in vehicle-local space and IsGroundContactId 0x7BF620 returns it with
    // the retained corpus. Exercise both rotations, not just token storage.
    GmMat3& vehicleRotation =
        impulseCorpus->m_dyna->CurrentState().m_rotationMatrix;
    vehicleRotation.m00 = 0.0f;
    vehicleRotation.m01 = -1.0f;
    vehicleRotation.m02 = 0.0f;
    vehicleRotation.m10 = 1.0f;
    vehicleRotation.m11 = 0.0f;
    vehicleRotation.m12 = 0.0f;
    vehicleRotation.m20 = 0.0f;
    vehicleRotation.m21 = 0.0f;
    vehicleRotation.m22 = 1.0f;
    CSceneVehicleCar::SSimulationWheel& observedWheel =
        impulseCar.m_wheels[0];
    uint32_t observedCorpusToken = 0u;
    {
        CHmsCorpus observedCorpus;
        observedCorpus.m_location.rot.m00 = 0.0f;
        observedCorpus.m_location.rot.m01 = 0.0f;
        observedCorpus.m_location.rot.m02 = 1.0f;
        observedCorpus.m_location.rot.m10 = 0.0f;
        observedCorpus.m_location.rot.m11 = 1.0f;
        observedCorpus.m_location.rot.m12 = 0.0f;
        observedCorpus.m_location.rot.m20 = -1.0f;
        observedCorpus.m_location.rot.m21 = 0.0f;
        observedCorpus.m_location.rot.m22 = 0.0f;
        observedCorpusToken = CHmsCorpus::PointerToken(&observedCorpus);
        passed &= Expect("live packed corpus token resolves safely",
                         CHmsCorpus::ResolvePointerToken(observedCorpusToken) ==
                             &observedCorpus);

        CHmsPhysicalContact observedContact{};
        observedContact.m_otherCorpus32 = observedCorpusToken;
        observedContact.m_otherMaterialId = 7u;
        observedContact.m_localNormal = GmVec3(0.0f, 1.0f, 0.0f);
        observedContact.m_relativeSpeed = GmVec3(0.0f, 0.0f, 0.0f);
        observedContact.m_isActive = 1u;
        impulseCar.WheelAbsorbContact(&observedWheel, &observedContact);

        GmVec3 queriedDirection;
        CHmsCorpus* queriedCorpus = nullptr;
        passed &= Expect(
            "wheel observes opposite +Z in vehicle-local space",
            observedContact.m_isActive == 0u &&
            VecNear(observedWheel.m_otherCorpusLocalDirection,
                    GmVec3(0.0f, -1.0f, 0.0f)) &&
            observedWheel.m_otherCorpusToken == observedCorpusToken &&
            impulseCar.IsGroundContactId(
                7u, &queriedDirection, &queriedCorpus) == 1 &&
            VecNear(queriedDirection, GmVec3(0.0f, -1.0f, 0.0f)) &&
            queriedCorpus == &observedCorpus);
    }
    passed &= Expect("expired packed corpus token does not dangle",
                     CHmsCorpus::ResolvePointerToken(observedCorpusToken) ==
                         nullptr);

    GmVec3 queuedBeforeReset{0.2f, 0.0f, 0.0f};
    rotateBody.AddReplacement(&queuedBeforeReset);
    rotateBody.Reset(nullptr);
    rotateBody.DoPostCollisionDynamic();
    passed &= Expect("dynamic reset clears queued replacements",
                     VecNear(rotateBody.Position(),
                             GmVec3(7.0f, 8.0f, 9.0f)) &&
                     rotateBody.m_field_0x4 == 0u &&
                     rotateBody.m_field_0x8 == 0u);

    CSceneVehicleCar contactCar;
    CHmsItem contactItem;
    contactCar.m_hmsItem = &contactItem;
    contactItem.m_sceneMobil = &contactCar;
    contactItem.CallbackSet(
        CB_ABSORB_CONTACT,
        CSceneMobilAbsorbContact::Instance());
    CPlugTree absorbWheelSurfaceTree;
    contactCar.m_wheels[0].m_surfaceHandler.m_tree =
        &absorbWheelSurfaceTree;

    CHmsPhysicalContact wheelContact{};
    wheelContact.m_collisionData = static_cast<uint32_t>(
        reinterpret_cast<uintptr_t>(&absorbWheelSurfaceTree));
    wheelContact.m_otherMaterialId = 7u;
    wheelContact.m_localNormal = GmVec3(0.0f, 1.0f, 0.0f);
    wheelContact.m_localPoint = GmVec3(1.0f, 2.0f, 3.0f);
    wheelContact.m_relativeSpeed = GmVec3(0.0f, -3.0f, 0.0f);
    wheelContact.m_isActive = 1u;
    contactItem.m_callbacks->m_callbacks[CB_ABSORB_CONTACT]->AbsorbContact(
        &contactItem, &wheelContact);
    passed &= Expect("vehicle absorb callback routes grounded wheel contact",
                     contactCar.m_hasAnyContact == 1 &&
                     contactCar.m_wheelContactCount == 1u &&
                     Near(contactCar.m_frontWheelImpact, 3.0f) &&
                     contactCar.m_wheelContactMaterial == 7u &&
                     contactCar.m_wheels[0].m_hasGroundContact == 1 &&
                     contactCar.m_wheels[0].m_groundContactCount == 1u &&
                     VecNear(
                         contactCar.m_wheels[0].m_groundContactNormalSum,
                         GmVec3(0.0f, 1.0f, 0.0f)) &&
                     contactCar.m_wheels[0].m_groundMaterial == 7u &&
                     VecNear(
                         contactCar.m_wheels[0].m_absorbContactPoint,
                         GmVec3(1.0f, 2.0f, 3.0f)) &&
                     wheelContact.m_isActive == 0u);

    CHmsPhysicalContact lateralWheelContact = wheelContact;
    lateralWheelContact.m_localNormal = GmVec3(1.0f, 0.0f, 0.0f);
    lateralWheelContact.m_localPoint = GmVec3(4.0f, 5.0f, 6.0f);
    lateralWheelContact.m_relativeSpeed = GmVec3(-2.0f, 0.0f, 0.0f);
    lateralWheelContact.m_isActive = 1u;
    contactCar.AbsorbContact(&lateralWheelContact);
    passed &= Expect("wheel absorb distinguishes lateral body contact",
                     contactCar.m_wheelContactCount == 2u &&
                     Near(contactCar.m_chassisImpact, 2.0f) &&
                     contactCar.m_hasBodyContact == 1 &&
                     contactCar.m_wheels[0].m_hasGroundContact == 0 &&
                     contactCar.m_wheels[0].m_hasLateralContact == 1 &&
                     VecNear(
                         contactCar.m_wheels[0].m_lateralContactPoint,
                         GmVec3(4.0f, 5.0f, 6.0f)) &&
                     lateralWheelContact.m_isActive == 0u);

    CHmsPhysicalContact chassisContact{};
    tuning.m_steerModel = 5;
    tuning.m_shockModel = 2;
    chassisContact.m_collisionData = 0x12345678u;
    chassisContact.m_otherMaterialId = 9u;
    chassisContact.m_localNormal = GmVec3(0.0f, -1.0f, 0.0f);
    chassisContact.m_localPoint = GmVec3(7.0f, 8.0f, 9.0f);
    chassisContact.m_relativeSpeed = GmVec3(0.0f, 4.0f, 0.0f);
    chassisContact.m_replacement = GmVec3(2.0f, 3.0f, 4.0f);
    chassisContact.m_isActive = 1u;
    contactCar.AbsorbContact(&chassisContact);
    passed &= Expect("chassis absorb accumulates and projects model-5 contact",
                     contactCar.m_hasChassisContact == 1 &&
                     contactCar.m_chassisContactCount == 1u &&
                     contactCar.m_chassisContactMaterial == 9u &&
                     Near(contactCar.m_chassisImpact, 6.0f) &&
                     VecNear(contactCar.m_chassisContactPointSum,
                             GmVec3(7.0f, 8.0f, 9.0f)) &&
                     VecNear(contactCar.m_chassisContactNormalSum,
                             GmVec3(0.0f, -1.0f, 0.0f)) &&
                     VecNear(chassisContact.m_replacement,
                             GmVec3(0.0f, 3.0f, 0.0f)) &&
                     chassisContact.m_isActive == 0u);

    CHmsPhysicalContact ignoredContact{};
    ignoredContact.m_otherMaterialId = 0x0du;
    ignoredContact.m_replacement = GmVec3(1.0f, 2.0f, 3.0f);
    ignoredContact.m_isActive = 1u;
    const uint32_t contactCountBeforeIgnore =
        contactCar.m_chassisContactCount + contactCar.m_wheelContactCount;
    contactCar.AbsorbContact(&ignoredContact);
    passed &= Expect("ignored vehicle material vetoes contact before counters",
                     VecNear(ignoredContact.m_replacement,
                             GmVec3(0.0f, 0.0f, 0.0f)) &&
                     ignoredContact.m_isActive == 0u &&
                     contactCar.m_chassisContactCount +
                         contactCar.m_wheelContactCount ==
                         contactCountBeforeIgnore);

    if (!passed) return 1;
    std::puts("vehicle state regression: PASS");
    return 0;
}
