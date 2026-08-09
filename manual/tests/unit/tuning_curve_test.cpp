#include "../../../TuningData.hpp"

#include <cmath>
#include <cstdio>

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

} // namespace

int main() {
    CSceneVehicleCarTuning tuning;
    InitTuningData(&tuning);

    bool passed = true;
    passed &= ExpectNear("Stadium ground gravity coefficient",
                         tuning.m_gravityCoef, StadiumGravityCoef);
    passed &= ExpectNear("Stadium air gravity coefficient",
                         tuning.m_gravityCoefAir, StadiumGravityCoefAir);
    passed &= ExpectNear("Stadium constant ground slowdown",
                         tuning.m_groundSlowDownBase,
                         StadiumGroundSlowDownBase);
    passed &= ExpectNear("Stadium linear fluid friction",
                         tuning.m_linearFluidFrictionCoef,
                         StadiumLinearFluidFrictionCoef);
    passed &= ExpectNear("Stadium M5 contact slowdown duration",
                         static_cast<float>(
                             tuning.m_m5LateralConstantSlowDownDuration),
                         static_cast<float>(
                             StadiumM5LateralConstantSlowDownDuration));
    passed &= ExpectNear("Stadium minimum absorbed replacement",
                         tuning.m_absorbingValMin,
                         StadiumAbsorbingValMin);
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
    passed &= ExpectNear("accel at 100 km/h",
                         tuning.GetAccelFromSpeed(100.0f / 3.6f),
                         16.0f + (100.0f / 101.0f) * (11.0f - 16.0f));
    passed &= ExpectNear("accel at 200 km/h",
                         tuning.GetAccelFromSpeed(200.0f / 3.6f),
                         11.0f + (99.0f / 100.0f) * (7.0f - 11.0f));
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
    passed &= ExpectNear("Stadium Model6 over-limit side force",
                         tuning.GetModel6SideForce(-100.0f, 60.0f),
                         -100.0f);
    tuning.m_maxSideFrictionOverLimitBlend = 0.25f;
    passed &= ExpectNear("Model6 fractional over-limit blend",
                         tuning.GetModel6SideForce(100.0f, 60.0f),
                         70.0f);
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
