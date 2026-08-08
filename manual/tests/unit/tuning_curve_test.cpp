#include "../../../TuningData.hpp"

#include <cmath>
#include <cstdio>

// The current harness keeps these two process-wide integration values in
// main.cpp. Define inert versions for a library-only regression executable.
CSceneVehicleCarTuning* g_tuning = nullptr;

namespace {

bool ExpectNear(const char* name, float actual, float expected) {
    constexpr float kTolerance = 1.0e-4f;
    if (std::fabs(actual - expected) <= kTolerance) return true;

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
    passed &= ExpectNear("accel at 100 km/h",
                         tuning.GetAccelFromSpeed(100.0f / 3.6f),
                         16.0f + (100.0f / 101.0f) * (11.0f - 16.0f));
    passed &= ExpectNear("accel at 200 km/h",
                         tuning.GetAccelFromSpeed(200.0f / 3.6f),
                         11.0f + (99.0f / 100.0f) * (7.0f - 11.0f));
    passed &= ExpectNear("lateral slowdown at 100 km/h",
                         tuning.GetLateralContactSlowDownFromSpeed(100.0f / 3.6f),
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

    if (!passed) return 1;
    std::puts("tuning curve regression: PASS");
    return 0;
}
