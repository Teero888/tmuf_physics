#include "../../../TuningData.hpp"
#include "../../Scene/TmForeverPhysicsConstants.hpp"

#include <cmath>
#include <cstdio>
#include <limits>

// The current harness keeps these two process-wide integration values in
// main.cpp. Define inert versions for a library-only regression executable.
CSceneVehicleCarTuning* g_tuning = nullptr;

namespace {

bool ExpectNear(const char* name, float actual, float expected,
                float tolerance = 1.0e-4f) {
    if (std::fabs(actual - expected) <= tolerance) return true;

    std::fprintf(stderr, "%s: expected %.9g, got %.9g\n", name, expected, actual);
    return false;
}

bool ExpectNan(const char* name, float actual) {
    if (std::isnan(actual)) return true;

    std::fprintf(stderr, "%s: expected NaN, got %.9g\n", name, actual);
    return false;
}

} // namespace

int main() {
    CSceneVehicleCarTuning tuning;
    bool passed = true;
    passed &= ExpectNear("default minimum steering radius",
                         tuning.m_steerRadiusMin, 1.0f);
    passed &= ExpectNear("default steering radius coefficient",
                         tuning.m_steerRadiusCoef, 0.5f);
    passed &= ExpectNear("default maximum speed", tuning.m_maxSpeed,
                         TmForeverPhysicsConstants::
                             kDefaultOldEngineSpeedDivisorBase);
    passed &= ExpectNear("default reverse maximum speed",
                         tuning.m_reverseMaxSpeed,
                         13.888889312744140625f);
    passed &= ExpectNear("default maximum-speed correction",
                         tuning.m_limitToMaxSpeedForce, 10.0f);
    passed &= ExpectNear("default brake base", tuning.m_brakeBase, 20.0f);
    passed &= ExpectNear("default brake coefficient", tuning.m_brakeCoef, 0.0f);
    passed &= ExpectNear("default brake maximum", tuning.m_brakeMax, 500.0f);
    passed &= ExpectNear("default dynamic brake maximum",
                         tuning.m_brakeMaxDynamic, 500.0f);
    passed &= ExpectNear("default Model6 slipping brake modulation",
                         tuning.m_m6BrakeModulationWhenSlipping, 0.5f);
    passed &= ExpectNear("default Model6 rear brake maximum",
                         tuning.m_m6BrakeMaxRear, 100.0f);
    passed &= ExpectNear("default Model6 dynamic rear brake maximum",
                         tuning.m_m6BrakeMaxDynamicRear, 50.0f);
    passed &= ExpectNear("default Model6 burnout duration",
                         static_cast<float>(tuning.m_m6BurnoutDuration),
                         1000.0f);
    passed &= ExpectNear("default Model6 burnout acceleration modulation",
                         tuning.m_m6BurnoutAccelerationModulation, 0.5f);
    passed &= ExpectNear("default Model6 after-burnout duration",
                         static_cast<float>(
                             tuning.m_m6AfterBurnoutDuration),
                         500.0f);
    passed &= ExpectNear(
        "default Model6 after-burnout acceleration modulation",
        tuning.m_m6AfterBurnoutAccelerationModulation, 4.0f);
    passed &= ExpectNear("default Model6 after-burnout impulse",
                         tuning.m_m6AfterBurnoutImpulse, 10.0f);
    passed &= ExpectNear("default slipping acceleration curve coefficient",
                         tuning.m_m5SlippingAccelCurveCoef, 1.0f);
    passed &= ExpectNear("default acceleration slip excess scale",
                         tuning.m_m5AccelSlipCoefMax, 1.0f);
    InitTuningData(&tuning);

    passed &= ExpectNear("Stadium center-of-mass aft factor",
                         tuning.m_centerOfMassAftFactor,
                         StadiumCenterOfMassAftFactor);
    passed &= ExpectNear("Stadium center-of-mass vertical offset",
                         tuning.m_centerOfMassVerticalOffset,
                         StadiumCenterOfMassVerticalOffset);
    passed &= ExpectNear("Stadium ground gravity coefficient",
                         tuning.m_gravityCoef, StadiumGravityCoef);
    passed &= ExpectNear("Stadium maximum collision step distance",
                         tuning.m_maxDistancePerStep,
                         StadiumMaxDistancePerStep);
    passed &= ExpectNear("Stadium air gravity coefficient",
                         tuning.m_gravityCoefAir, StadiumGravityCoefAir);
    passed &= ExpectNear("Stadium constant ground slowdown",
                         tuning.m_groundSlowDownBase,
                         StadiumGroundSlowDownBase);
    passed &= ExpectNear("Stadium linear fluid friction",
                         tuning.m_linearFluidFrictionCoef,
                         StadiumLinearFluidFrictionCoef);
    passed &= ExpectNear("Stadium maximum speed", tuning.m_maxSpeed,
                         StadiumMaxSpeed);
    passed &= ExpectNear("Stadium reverse maximum speed",
                         tuning.m_reverseMaxSpeed,
                         StadiumReverseMaxSpeed);
    passed &= ExpectNear("Stadium maximum-speed correction",
                         tuning.m_limitToMaxSpeedForce,
                         StadiumLimitToMaxSpeedForce);
    passed &= ExpectNear("Stadium brake base", tuning.m_brakeBase,
                         StadiumBrakeBase);
    passed &= ExpectNear("Stadium brake coefficient", tuning.m_brakeCoef,
                         StadiumBrakeCoef);
    passed &= ExpectNear("Stadium brake maximum", tuning.m_brakeMax,
                         StadiumBrakeMax);
    passed &= ExpectNear("Stadium dynamic brake maximum",
                         tuning.m_brakeMaxDynamic,
                         StadiumBrakeMaxDynamic);
    passed &= ExpectNear("Stadium Model6 slipping brake modulation",
                         tuning.m_m6BrakeModulationWhenSlipping,
                         StadiumM6BrakeModulationWhenSlipping);
    passed &= ExpectNear("Stadium Model6 rear brake maximum",
                         tuning.m_m6BrakeMaxRear,
                         StadiumM6BrakeMaxRear);
    passed &= ExpectNear("Stadium Model6 dynamic rear brake maximum",
                         tuning.m_m6BrakeMaxDynamicRear,
                         StadiumM6BrakeMaxDynamicRear);
    passed &= ExpectNear("Stadium Model6 burnout duration",
                         static_cast<float>(tuning.m_m6BurnoutDuration),
                         static_cast<float>(StadiumM6BurnoutDuration));
    passed &= ExpectNear("Stadium Model6 burnout acceleration modulation",
                         tuning.m_m6BurnoutAccelerationModulation,
                         StadiumM6BurnoutAccelerationModulation);
    passed &= ExpectNear("Stadium Model6 after-burnout duration",
                         static_cast<float>(
                             tuning.m_m6AfterBurnoutDuration),
                         static_cast<float>(
                             StadiumM6AfterBurnoutDuration));
    passed &= ExpectNear(
        "Stadium Model6 after-burnout acceleration modulation",
        tuning.m_m6AfterBurnoutAccelerationModulation,
        StadiumM6AfterBurnoutAccelerationModulation);
    passed &= ExpectNear("Stadium Model6 after-burnout impulse",
                         tuning.m_m6AfterBurnoutImpulse,
                         StadiumM6AfterBurnoutImpulse);
    passed &= ExpectNear("Stadium slipping acceleration curve coefficient",
                         tuning.m_m5SlippingAccelCurveCoef,
                         StadiumM5SlippingAccelCurveCoef);
    passed &= ExpectNear("Stadium acceleration slip excess scale",
                         tuning.m_m5AccelSlipCoefMax,
                         StadiumM5AccelSlipCoefMax);
    passed &= ExpectNear("Stadium minimum steering radius",
                         tuning.m_steerRadiusMin,
                         StadiumSteerRadiusMin);
    passed &= ExpectNear("Stadium steering radius coefficient",
                         tuning.m_steerRadiusCoef,
                         StadiumSteerRadiusCoef);
    passed &= ExpectNear("Stadium M5 contact slowdown duration",
                         static_cast<float>(
                             tuning.m_m5LateralConstantSlowDownDuration),
                         static_cast<float>(
                             StadiumM5LateralConstantSlowDownDuration));
    passed &= ExpectNear("Stadium minimum absorbed replacement",
                         tuning.m_absorbingValMin,
                         StadiumAbsorbingValMin);
    passed &= ExpectNear("Stadium maximum absorbed replacement",
                         tuning.m_absorbingValMax,
                         StadiumAbsorbingValMax);
    passed &= ExpectNear("Stadium body contact friction",
                         tuning.m_bodyFrictionCoef,
                         StadiumBodyFrictionCoef);
    passed &= ExpectNear("Stadium metal body contact friction",
                         tuning.m_bodyFrictionCoefMetal,
                         StadiumBodyFrictionCoefMetal);
    passed &= ExpectNear("Stadium body restitution",
                         tuning.m_bodyRestCoef,
                         StadiumBodyRestCoef);
    passed &= ExpectNear("Stadium metal body restitution",
                         tuning.m_bodyRestCoefMetal,
                         StadiumBodyRestCoefMetal);
    passed &= ExpectNear("Stadium concrete wheel restitution",
                         tuning.m_wheelRestCoefConcrete,
                         StadiumWheelRestCoefConcrete);
    passed &= ExpectNear("Stadium metal wheel restitution",
                         tuning.m_wheelRestCoefMetal,
                         StadiumWheelRestCoefMetal);
    passed &= ExpectNear("Stadium angular impulse Y scale",
                         tuning.m_angularSpeedYImpulseScale,
                         StadiumAngularSpeedYImpulseScale);
    passed &= ExpectNear("Stadium angular speed clamp",
                         tuning.m_angularSpeedClamp,
                         StadiumAngularSpeedClamp);
    passed &= ExpectNear("Stadium positive linear-speed-squared delta clamp",
                         tuning.m_linearSpeedSquaredPositiveDeltaMax,
                         StadiumLinearSpeedSquaredPositiveDeltaMax);
    passed &= ExpectNear("Stadium water gravity",
                         tuning.m_waterGravity, StadiumWaterGravity);
    passed &= ExpectNear("Stadium water rebound horizontal threshold",
                         tuning.m_waterReboundMinHorizontalSpeed,
                         StadiumWaterReboundMinHorizontalSpeed);
    passed &= ExpectNear("Stadium water bump threshold",
                         tuning.m_waterBumpMinSpeed,
                         StadiumWaterBumpMinSpeed);
    passed &= ExpectNear("Stadium water angular friction",
                         tuning.m_waterAngularFriction,
                         StadiumWaterAngularFriction);
    passed &= ExpectNear("Stadium quadratic water angular friction",
                         tuning.m_waterAngularFrictionSq,
                         StadiumWaterAngularFrictionSq);
    passed &= ExpectNear("water slowdown at ratio 0.45",
                         tuning.GetWaterBumpSlowDownFromSpeedRatio(0.45f),
                         0.65f);
    passed &= ExpectNear("water rebound at ratio 0.45",
                         tuning.GetWaterReboundFromSpeedRatio(0.45f),
                         1.2f);
    passed &= ExpectNear("water friction at one metre per second",
                         tuning.GetWaterFrictionFromSpeed(1.0f),
                         0.2f + (1.6f / 48.0f) * 0.8f);
    passed &= ExpectNear("Model6 damper modulation at maximum absorption",
                         tuning.M6GetModulationFromDamperAbsorbVal(0.7f),
                         0.1f);
    passed &= ExpectNear("Model6 damper modulation at ratio 0.6",
                         tuning.M6GetModulationFromDamperAbsorbVal(0.28f),
                         0.3f);
    passed &= ExpectNear("Model6 damper modulation at minimum absorption",
                         tuning.M6GetModulationFromDamperAbsorbVal(0.0f),
                         1.0f);
    // Stadium's AccelCurve carries RealInterp mode 1, which TmForeverFixed.exe
    // evaluates as a step at 0x585EE8: the value of the greatest key at or
    // below the speed, with no blending. These two speeds sit inside the
    // 0..101 and 101..201 km/h spans, so they return those spans' lower keys
    // rather than anything interpolated. This is what makes the launch pull a
    // flat 16 m/s^2 up to 101 km/h.
    passed &= ExpectNear("accel at 100 km/h",
                         tuning.GetAccelFromSpeed(100.0f / 3.6f), 16.0f);
    passed &= ExpectNear("accel at 200 km/h",
                         tuning.GetAccelFromSpeed(200.0f / 3.6f), 11.0f);
    // Landing exactly on a key collapses both bounding indices onto it, so a
    // stepped curve returns that key's own value, not the previous span's.
    passed &= ExpectNear("accel exactly at the 101 km/h key",
                         tuning.GetAccelFromSpeed(101.0f / 3.6f), 11.0f);
    // An interpolated curve is unaffected by any of this.
    passed &= ExpectNear("rear-gear accel interpolates at -25 km/h",
                         tuning.M6GetRearGearAccelFromSpeed(-25.0f / 3.6f),
                         8.0f + 0.5f * (30.0f - 8.0f));
    passed &= ExpectNear("lateral slowdown at 100 km/h",
                         tuning.GetLateralContactSlowDownFromSpeed(100.0f / 3.6f),
                         24.0f);
    passed &= ExpectNear("M5 lateral slowdown at 100 km/h",
                         tuning.M5GetLateralContactSlowDownFromSpeed(
                             100.0f / 3.6f),
                         24.0f);
    passed &= ExpectNear("side friction at 250 km/h",
                         tuning.GetMaxSideFrictionFromSpeed(250.0f / 3.6f),
                         71.0f);
    passed &= ExpectNear("steer torque at 100 km/h",
                         tuning.GetSteerDriveTorqueFromSpeed(100.0f / 3.6f),
                         8.5f);
    passed &= ExpectNear("rollover coefficient at 0.6 rad",
                         tuning.GetRolloverLateralCoefFromAngle(0.6f),
                         0.6f);
    passed &= ExpectNear("Model6 steering ramp at half low speed",
                         tuning.GetModel6SteerSpeedFactor(15.0f),
                         std::sqrt(0.5f));
    passed &= ExpectNear("Model6 processed steering at rest",
                         tuning.GetModel6ProcessedSteer(0.5f, 0.0f),
                         -0.5f * std::asin(0.5f));
    passed &= ExpectNear("Model6 processed steering at forward speed",
                         tuning.GetModel6ProcessedSteer(0.5f, 100.0f),
                         -0.5f * std::asin(1.0f / 87.0f));
    passed &= ExpectNear("Model6 processed steering uses absolute speed",
                         tuning.GetModel6ProcessedSteer(0.5f, -100.0f),
                         -0.5f * std::asin(1.0f / 87.0f));
    tuning.m_steerRadiusMin = 0.0f;
    tuning.m_steerRadiusCoef = 0.0f;
    passed &= ExpectNear("Model6 processed steering below epsilon",
                         tuning.GetModel6ProcessedSteer(0.5f, 10.0f),
                         0.0f);
    tuning.m_steerRadiusMin =
        TmForeverPhysicsConstants::kWheelInputEpsilon;
    passed &= ExpectNear("Model6 processed steering at epsilon",
                         tuning.GetModel6ProcessedSteer(0.5f, 0.0f),
                         -0.5f * static_cast<float>(
                                     TmForeverPhysicsConstants::kPi * 0.5),
                         0.001f);
    tuning.m_steerRadiusMin = std::numeric_limits<float>::quiet_NaN();
    passed &= ExpectNan("Model6 processed steering propagates NaN",
                        tuning.GetModel6ProcessedSteer(0.5f, 0.0f));
    tuning.m_steerRadiusMin = StadiumSteerRadiusMin;
    tuning.m_steerRadiusCoef = StadiumSteerRadiusCoef;
    passed &= ExpectNear("Stadium Model6 over-limit side force",
                         tuning.GetModel6SideForce(-100.0f, 60.0f),
                         -100.0f);
    tuning.m_maxSideFrictionOverLimitBlend = 0.25f;
    passed &= ExpectNear("Model6 fractional over-limit blend",
                         tuning.GetModel6SideForce(100.0f, 60.0f),
                         70.0f);
    tuning.m_maxSideFrictionBlendCoef = 0.25f;
    passed &= ExpectNear("Model6 wheel side-force positive blend",
                         tuning.GetModel6WheelSideForce(100.0f, 60.0f),
                         70.0f);
    passed &= ExpectNear("Model6 wheel side-force negative blend",
                         tuning.GetModel6WheelSideForce(-100.0f, 60.0f),
                         -70.0f);
    tuning.m_maxSideFrictionBlendCoef = StadiumMaxSideFrictionBlendCoef;
    tuning.m_maxSpeed = 10.0f;
    tuning.m_reverseMaxSpeed = 5.0f;
    tuning.m_limitToMaxSpeedForce = 3.0f;
    passed &= ExpectNear("Model6 forward speed limit is strict",
                         tuning.GetModel6SpeedLimitedAxialForce(
                             7.0f, 20.0f, 2.0f),
                         7.0f);
    passed &= ExpectNear("Model6 forward limit replaces positive force",
                         tuning.GetModel6SpeedLimitedAxialForce(
                             7.0f, 20.01f, 2.0f),
                         -3.0f);
    passed &= ExpectNear("Model6 forward limit extends negative force",
                         tuning.GetModel6SpeedLimitedAxialForce(
                             -7.0f, 20.01f, 2.0f),
                         -10.0f);
    passed &= ExpectNear("Model6 reverse speed limit is strict",
                         tuning.GetModel6SpeedLimitedAxialForce(
                             -7.0f, -10.0f, 2.0f),
                         -7.0f);
    passed &= ExpectNear("Model6 reverse limit replaces negative force",
                         tuning.GetModel6SpeedLimitedAxialForce(
                             -7.0f, -10.01f, 2.0f),
                         3.0f);
    passed &= ExpectNear("Model6 reverse limit extends positive force",
                         tuning.GetModel6SpeedLimitedAxialForce(
                             7.0f, -10.01f, 2.0f),
                         10.0f);
    tuning.m_maxSpeed = StadiumMaxSpeed;
    tuning.m_reverseMaxSpeed = StadiumReverseMaxSpeed;
    tuning.m_limitToMaxSpeedForce = StadiumLimitToMaxSpeedForce;
    tuning.m_brakeBase = 1.0f;
    tuning.m_brakeCoef = 2.0f;
    tuning.m_brakeMax = 6.0f;
    tuning.m_brakeMaxDynamic = 4.0f;
    bool brakeSaturated = true;
    passed &= ExpectNear("Model6 forward brake rejects zero speed",
                         tuning.GetModel6ForwardAxialBrakeForce(
                             0.0f, 1.0f, 1.0f, 1.0f, false,
                             &brakeSaturated),
                         0.0f);
    passed &= ExpectNear("Model6 forward brake request",
                         tuning.GetModel6ForwardAxialBrakeForce(
                             2.0f, 0.5f, 1.0f, 1.0f, false,
                             &brakeSaturated),
                         2.5f);
    passed &= ExpectNear("Model6 forward dynamic brake cap",
                         tuning.GetModel6ForwardAxialBrakeForce(
                             2.0f, 1.0f, 1.0f, 1.0f, false,
                             &brakeSaturated),
                         4.0f);
    passed &= ExpectNear("Model6 forward slipping brake cap",
                         tuning.GetModel6ForwardAxialBrakeForce(
                             10.0f, 1.0f, 1.0f, 0.5f, true,
                             &brakeSaturated),
                         6.0f);
    passed &= ExpectNear("Model6 forward brake saturation flag",
                         brakeSaturated ? 1.0f : 0.0f, 1.0f);
    tuning.m_brakeBase = StadiumBrakeBase;
    tuning.m_brakeCoef = StadiumBrakeCoef;
    tuning.m_brakeMax = StadiumBrakeMax;
    tuning.m_brakeMaxDynamic = StadiumBrakeMaxDynamic;
    tuning.m_m5AccelSlipCoefMax = 0.5f;
    passed &= ExpectNear("Model6 lateral excess keeps normal acceleration",
                         tuning.GetModel6AccelerationBlendFromLateralOverLimit(
                             60.0f, 60.0f),
                         1.0f);
    passed &= ExpectNear("Model6 lateral excess blends acceleration curves",
                         tuning.GetModel6AccelerationBlendFromLateralOverLimit(
                             75.0f, 60.0f),
                         0.5f);
    passed &= ExpectNear("Model6 lateral excess clamps slipping acceleration",
                         tuning.GetModel6AccelerationBlendFromLateralOverLimit(
                             120.0f, 60.0f),
                         0.0f);
    tuning.m_m5AccelSlipCoefMax = StadiumM5AccelSlipCoefMax;
    tuning.m_m6BurnoutDuration = 1000u;
    tuning.m_m6BurnoutAccelerationModulation = 0.5f;
    tuning.m_m6AfterBurnoutDuration = 500u;
    tuning.m_m6AfterBurnoutAccelerationModulation = 4.0f;
    tuning.m_m6AfterBurnoutImpulse = 10.0f;
    passed &= ExpectNear("Model6 state-one midpoint acceleration modulation",
                         tuning.GetModel6EngineStateAccelerationModulation(
                             1, 500u),
                         0.5f);
    passed &= ExpectNear(
        "Model6 state-three midpoint acceleration modulation",
        tuning.GetModel6EngineStateAccelerationModulation(3, 250u),
        4.0f);
    passed &= ExpectNear("Model6 state-three active axial impulse",
                         tuning.GetModel6EngineStateAxialImpulse(3, 250u),
                         10.0f);
    passed &= ExpectNear("Model6 ordinary state acceleration modulation",
                         tuning.GetModel6EngineStateAccelerationModulation(
                             0, 250u),
                         1.0f);
    passed &= ExpectNear("Model6 ordinary state axial impulse",
                         tuning.GetModel6EngineStateAxialImpulse(0, 250u),
                         0.0f);
    tuning.m_m6BurnoutDuration = StadiumM6BurnoutDuration;
    tuning.m_m6BurnoutAccelerationModulation =
        StadiumM6BurnoutAccelerationModulation;
    tuning.m_m6AfterBurnoutDuration = StadiumM6AfterBurnoutDuration;
    tuning.m_m6AfterBurnoutAccelerationModulation =
        StadiumM6AfterBurnoutAccelerationModulation;
    tuning.m_m6AfterBurnoutImpulse = StadiumM6AfterBurnoutImpulse;
    tuning.m_m5SlippingAccelCurveCoef = 0.5f;
    passed &= ExpectNear("M5 slipping curve uses its distinct coefficient",
                         tuning.M5GetSlippingAccelFromSpeed(100.0f),
                         5.0f);
    tuning.m_m5SlippingAccelCurveCoef =
        StadiumM5SlippingAccelCurveCoef;
    passed &= ExpectNear("Stadium yaw inertia",
                         tuning.GetYawInertia(),
                         25.0f / 12.0f);
    passed &= ExpectNear("Stadium Model6 maximum RPM",
                         tuning.m_m6MaxRpm, 11000.0f);
    passed &= ExpectNear("Stadium Model6 reverse ratio",
                         tuning.m_m6GearRatios[0], 400.0f);
    passed &= ExpectNear("Stadium Model6 first ratio",
                         tuning.m_m6GearRatios[1], 370.0f);
    passed &= ExpectNear("Stadium Model6 sixth ratio",
                         tuning.m_m6GearRatios[5], 85.0f);
    passed &= ExpectNear("Stadium Model6 second-gear maximum",
                         tuning.m_m6MaxRpmRatios[2], 0.9f);
    passed &= ExpectNear("Stadium Model6 third-gear minimum",
                         tuning.m_m6MinRpmRatios[3], 0.57f);
    passed &= ExpectNear("Stadium Model6 wanted RPM",
                         tuning.m_m6RpmWantedOnGearUp[2], 0.628f);
    passed &= ExpectNear("Stadium Model6 first derived RPM delta",
                         tuning.m_m6RpmDeltaOnGearUp[2], 694.4865f, 0.02f);
    passed &= ExpectNear("Stadium Model6 airborne acceleration",
                         tuning.m_m6AirRpmAcceleration, 6000.0f);
    passed &= ExpectNear("Stadium Model6 airborne deadening",
                         tuning.m_m6AirRpmDeadening, 3000.0f);
    passed &= ExpectNear("Stadium Model6 upshift loss",
                         tuning.m_m6RpmLossOnGearUp, 17000.0f);
    passed &= ExpectNear("Stadium Model6 downshift gain",
                         tuning.m_m6RpmGainOnGearDown, 11500.0f);

    if (!passed) return 1;
    std::puts("tuning curve regression: PASS");
    return 0;
}
