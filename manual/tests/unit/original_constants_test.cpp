#include "../../Scene/TmForeverPhysicsConstants.hpp"

#include <cstdint>
#include <cstdio>
#include <fstream>

namespace {

template <typename T>
bool ExpectExecutableValue(std::ifstream& executable,
                           const char* name,
                           std::streamoff fileOffset,
                           T expected) {
    T actual{};
    executable.seekg(fileOffset);
    executable.read(reinterpret_cast<char*>(&actual), sizeof(actual));
    if (!executable || actual != expected) {
        std::fprintf(stderr, "%s: executable data mismatch at file offset 0x%llx\n",
                     name, static_cast<unsigned long long>(fileOffset));
        return false;
    }
    return true;
}

} // namespace

int main() {
    std::ifstream executable("../exe/TmForeverFixed.exe", std::ios::binary);
    if (!executable) {
        std::fputs("cannot open ../exe/TmForeverFixed.exe\n", stderr);
        return 1;
    }

    using namespace TmForeverPhysicsConstants;
    bool passed = true;
    passed &= ExpectExecutableValue(executable, "negative one", 0x72c060, kNegativeOne);
    passed &= ExpectExecutableValue(executable, "one half", 0x7313b8, kHalf);
    passed &= ExpectExecutableValue(executable, "pi", 0x736110, kPi);
    passed &= ExpectExecutableValue(executable, "input threshold", 0x7362c0, kInputThreshold);
    passed &= ExpectExecutableValue(executable, "normalization epsilon", 0x90ac60,
                                    kNormalizeSquaredEpsilon);
    passed &= ExpectExecutableValue(executable, "collision normalization epsilon", 0x91a938,
                                    kCollisionNormalizeSquaredEpsilon);
    passed &= ExpectExecutableValue(executable, "mesh transform normal epsilon", 0x91fb48,
                                    kMeshTransformNormalSquaredEpsilon);
    passed &= ExpectExecutableValue(executable, "polygon normal epsilon", 0x91fc38,
                                    kPolygonNormalSquaredEpsilon);
    passed &= ExpectExecutableValue(executable, "collision edge squared-distance epsilon", 0x7bdc5c,
                                    kCollisionEdgeSquaredDistanceEpsilon);
    passed &= ExpectExecutableValue(executable, "collision speed squared-difference epsilon", 0x755d98,
                                    kCollisionSpeedSquaredDifferenceEpsilon);
    passed &= ExpectExecutableValue(executable, "speed curve scale", 0x73d2a8,
                                    kSpeedCurveScale);
    passed &= ExpectExecutableValue<std::uint32_t>(executable, "zero scalar slot", 0x72c178, 0);
    passed &= ExpectExecutableValue(executable, "uniform gravity", 0x759790,
                                    kDefaultUniformGravity);
    passed &= ExpectExecutableValue(executable, "wheel input epsilon", 0x79ef4c,
                                    kWheelInputEpsilon);
    passed &= ExpectExecutableValue(executable, "water rebound maximum depth", 0x741ea8,
                                    kWaterReboundMaximumDepth);
    passed &= ExpectExecutableValue(executable, "water surface delta threshold", 0x8418e0,
                                    kWaterSurfaceDeltaThreshold);
    passed &= ExpectExecutableValue(executable, "water downward-speed threshold", 0x7574fc,
                                    kWaterDownwardSpeedThreshold);
    passed &= ExpectExecutableValue(executable, "default quadratic water angular friction", 0x733a54,
                                    kDefaultWaterAngularFrictionSq);
    passed &= ExpectExecutableValue(executable, "default collision water height", 0x755da4,
                                    kDefaultWaterCollisionHeight);
    passed &= ExpectExecutableValue(executable, "wheel gas angular-speed scale", 0x72f718,
                                    kWheelGasAngularSpeedScale);
    passed &= ExpectExecutableValue(executable, "wheel airborne angular decay", 0x79f1c0,
                                    kWheelAirborneAngularDecay);
    passed &= ExpectExecutableValue(executable, "wheel angular acceleration", 0x736adc,
                                    kWheelAngularAcceleration);
    passed &= ExpectExecutableValue(executable, "wheel angular deceleration", 0x736184,
                                    kWheelAngularDeceleration);
    passed &= ExpectExecutableValue(executable, "wheel rotation angle period", 0x79ef64,
                                    kWheelRotationAnglePeriod);
    passed &= ExpectExecutableValue(executable, "wheel direction squared epsilon", 0x906a80,
                                    kWheelDirectionSquaredEpsilon);
    passed &= ExpectExecutableValue(executable, "matrix basis squared epsilon", 0x91a840,
                                    kMatrixBasisSquaredEpsilon);
    passed &= ExpectExecutableValue(executable, "default shock-model-zero force factor", 0x733a54,
                                    kDefaultShockModel0ForceFactor);
    passed &= ExpectExecutableValue(executable, "default engine maximum RPM", 0x79efb0,
                                    kDefaultEngineMaxRpm);
    passed &= ExpectExecutableValue(executable, "Model6 shift duration", 0x79efc0,
                                    kM6ShiftDuration);
    passed &= ExpectExecutableValue(executable, "Model6 reverse takeoff shift duration", 0x7989dc,
                                    kM6ReverseTakeoffShiftDuration);
    passed &= ExpectExecutableValue(executable, "Model6 clutch ratio target", 0x79efd0,
                                    kM6ClutchRatioTarget);
    passed &= ExpectExecutableValue(executable, "Model6 widened clutch ratio target", 0x79efc8,
                                    kM6ClutchRatioTargetWide);
    passed &= ExpectExecutableValue(executable, "Model6 clutch ratio response", 0x75b8e0,
                                    kM6ClutchRatioResponse);
    passed &= ExpectExecutableValue(executable, "engine idle RPM", 0x8418d8,
                                    kEngineIdleRpm);
    passed &= ExpectExecutableValue(executable, "legacy engine shift duration", 0x780d18,
                                    kOldEngineShiftDuration);
    passed &= ExpectExecutableValue(executable, "legacy engine speed scale", 0x743310,
                                    kOldEngineSpeedScale);
    passed &= ExpectExecutableValue(executable, "legacy engine shift RPM loss", 0x79efb8,
                                    kOldEngineShiftRpmLoss);
    passed &= ExpectExecutableValue(executable, "legacy engine air response", 0x736ae8,
                                    kOldEngineAirResponse);
    passed &= ExpectExecutableValue(executable, "legacy engine ground response", 0x73d274,
                                    kOldEngineGroundResponse);
    passed &= ExpectExecutableValue(executable, "default legacy engine speed divisor", 0x7a3814,
                                    kDefaultOldEngineSpeedDivisorBase);
    passed &= ExpectExecutableValue(executable, "line intersection epsilon", 0x7785dc,
                                    kLineIntersectionEpsilon);
    passed &= ExpectExecutableValue(executable, "coincident surface epsilon", 0x7be3f8,
                                    kCoincidentSurfaceEpsilon);
    passed &= ExpectExecutableValue(executable, "plane normal squared epsilon", 0x91a8ac,
                                    kPlaneNormalSquaredEpsilon);
    passed &= ExpectExecutableValue(executable, "plane construction squared epsilon", 0x907588,
                                    kPlaneNormalSquaredEpsilon);
    passed &= ExpectExecutableValue(executable, "plane solve axis threshold", 0x731460,
                                    kPlaneSolveAxisThreshold);
    passed &= ExpectExecutableValue(executable, "plane normal dot threshold", 0x744a20,
                                    kPlaneNormalDotThreshold);

    // CHmsCollisionBuffer's native vtable is AddCollision, GetCollision,
    // GetCount. The constructor then reserves 0x32 physical contacts.
    passed &= ExpectExecutableValue<std::uint32_t>(
        executable, "collision buffer AddCollision vtable slot", 0x755e28, 0x005380f0u);
    passed &= ExpectExecutableValue<std::uint32_t>(
        executable, "collision buffer GetCollision vtable slot", 0x755e2c, 0x00537350u);
    passed &= ExpectExecutableValue<std::uint32_t>(
        executable, "collision buffer GetCount vtable slot", 0x755e30, 0x0073ac50u);
    passed &= ExpectExecutableValue<std::uint16_t>(
        executable, "collision buffer reserve-50 instruction", 0x1380c9, 0x326au);

    // ApplyWaterForces has one stack argument, consumes the exact +0x204 and
    // +0x220 tuning fields, and the two return sites both pop four bytes.
    passed &= ExpectExecutableValue<std::uint32_t>(
        executable, "ApplyWaterForces prologue", 0x3c2910, 0x537cec83u);
    passed &= ExpectExecutableValue<std::uint32_t>(
        executable, "ApplyWaterForces water gravity offset", 0x3c2d81, 0x204u);
    passed &= ExpectExecutableValue<std::uint32_t>(
        executable, "ApplyWaterForces angular-speed offset", 0x3c2d1f, 0x220u);
    passed &= ExpectExecutableValue<std::uint16_t>(
        executable, "ApplyWaterForces success ret4", 0x3c2e0a, 0x04c2u);
    passed &= ExpectExecutableValue<std::uint16_t>(
        executable, "ApplyWaterForces zero ret4", 0x3c2e82, 0x04c2u);
    passed &= ExpectExecutableValue<std::uint32_t>(
        executable, "GmMap2 truncation control word", 0x0ff965, 0x000c000du);

    if (!passed) return 1;
    std::puts("original executable constants regression: PASS");
    return 0;
}
