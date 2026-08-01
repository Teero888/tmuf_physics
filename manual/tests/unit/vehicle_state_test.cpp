#include "../../Scene/CSceneVehicleCar.hpp"
#include "../../Scene/CSceneVehicleCarTuning.hpp"
#include "../../Scene/TmForeverPhysicsConstants.hpp"
#include "../../Scene/VehicleGroundSupport.hpp"
#include "../../Hms/CHmsDyna.hpp"
#include "../../Hms/CHmsItem.hpp"

#include <cmath>
#include <cstdio>
#include <type_traits>

CSceneVehicleCarTuning* g_tuning = nullptr;
float g_carYaw = 0.0f;
extern GmVec3 g_stub_forces;
extern GmVec3 g_stub_torques;

using Model3Signature = void (CSceneVehicleCar::*)(
    float, GmVec3*, float, float, GmVec3*, GmVec3*, float, int, void*, int*, float*);
static_assert(std::is_same_v<decltype(&CSceneVehicleCar::ComputeForcesModel3_Exact), Model3Signature>,
              "ComputeForcesModel3 must keep the eleven-argument executable ABI");

namespace {

bool Expect(const char* name, bool condition) {
    if (condition) return true;
    std::fprintf(stderr, "%s: FAILED\n", name);
    return false;
}

bool Near(float actual, float expected, float tolerance = 1.0e-6f) {
    return std::abs(actual - expected) <= tolerance;
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
    tuning.m_absorbingValRest = 0.2f;
    tuning.m_absorbTension = 5.0f;
    tuning.m_lateralSlopeAdherenceMin = 0.3f;
    tuning.m_lateralSlopeAdherenceMax = 0.7f;
    tuning.m_axialSlopeAdherenceMin = 0.4f;
    tuning.m_axialSlopeAdherenceMax = 0.7f;
    g_tuning = &tuning;

    bool passed = true;
    passed &= Expect("freewheeling defaults off", car.m_freeWheeling == 0);
    passed &= Expect("engine rpm resets to zero", car.m_engine.m_engineRpm == 0.0f);
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

    CSceneVehicleCar::SSimulationWheel& wheel = car.m_wheels[0];
    car.WheelIntegrate(&wheel, 0.01f);
    passed &= Expect("Demo03 compression update", Near(wheel.m_realTimeState.m_compression, 0.01f));
    passed &= Expect("Demo03 compression velocity", Near(wheel.m_realTimeState.m_velocity, 1.0f));
    passed &= Expect("Demo03 clears absorbed delta", wheel.m_realTimeState.m_absorbDelta == 0.0f);
    passed &= Expect("no initial ground contact", car.IsGroundContact() == 0);

    CHmsItem suspensionItem;
    car.m_hmsItem = &suspensionItem;
    wheel.m_hasGroundContact = 1;
    wheel.m_realTimeState.m_compression = 0.15f;
    wheel.m_realTimeState.m_velocity = 0.5f;
    g_stub_forces = GmVec3(0.0f, 0.0f, 0.0f);
    const GmVec3 suspensionPoint(0.0f, 0.0f, 0.0f);
    car.WheelAddForceToVehicle(&wheel, &suspensionPoint);
    passed &= Expect("Demo03 suspension spring-damper scalar",
                     Near(wheel.m_suspensionForce, 1.5f));
    passed &= Expect("Demo03 suspension acts on local up axis",
                     Near(g_stub_forces.x, 0.0f) &&
                     Near(g_stub_forces.y, 1.5f) &&
                     Near(g_stub_forces.z, 0.0f));
    wheel.m_hasGroundContact = 0;
    g_stub_forces = GmVec3(0.0f, 0.0f, 0.0f);
    car.WheelAddForceToVehicle(&wheel, &suspensionPoint);
    passed &= Expect("suspension helper ignores uncontacted wheel",
                     Near(g_stub_forces.x, 0.0f) &&
                     Near(g_stub_forces.y, 0.0f) &&
                     Near(g_stub_forces.z, 0.0f));

    // CHmsDyna::AddLocalForce multiplies by the complete chassis rotation,
    // rather than applying yaw alone. A road normal tilted toward +Z makes
    // local forward point down the corresponding slope.
    constexpr float kSqrtHalf = 0.7071067811865475244f;
    car.m_chassisUp = GmVec3(0.0f, kSqrtHalf, kSqrtHalf);
    g_stub_forces = GmVec3(0.0f, 0.0f, 0.0f);
    const GmVec3 pitchedLocalForward(0.0f, 0.0f, 2.0f);
    car.AddVehicleCentralForce(
        &car,
        reinterpret_cast<CSceneVehicleCar*>(
            const_cast<GmVec3*>(&pitchedLocalForward)),
        nullptr);
    passed &= Expect("local force uses full chassis rotation",
                     Near(g_stub_forces.x, 0.0f) &&
                     Near(g_stub_forces.y, -2.0f * kSqrtHalf) &&
                     Near(g_stub_forces.z, 2.0f * kSqrtHalf));
    car.m_chassisUp = GmVec3(0.0f, 1.0f, 0.0f);
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
    g_stub_pos = GmVec3(0.0f, 0.0f, 0.0f);
    g_stub_forces = GmVec3(1.0f, 0.0f, 0.0f);
    g_stub_torques = GmVec3(0.0f, 0.0f, 0.0f);
    dyna.Integrate(0.5f);
    dyna.Move(0.5f);
    GmVec3 integratedSpeed;
    dyna.GetLocalLinearSpeed(&integratedSpeed);
    passed &= Expect("explicit Euler uses pre-force speed for translation",
                     Near(g_stub_pos.x, 1.0f));
    passed &= Expect("force still updates end-of-step speed",
                     Near(integratedSpeed.x, 2.5f));

    if (!passed) return 1;
    std::puts("vehicle state regression: PASS");
    return 0;
}
