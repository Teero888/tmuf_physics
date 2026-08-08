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
    passed &= ExpectExecutableValue(executable, "speed curve scale", 0x73d2a8,
                                    kSpeedCurveScale);
    passed &= ExpectExecutableValue<std::uint32_t>(executable, "zero scalar slot", 0x72c178, 0);
    passed &= ExpectExecutableValue(executable, "uniform gravity", 0x759790,
                                    kDefaultUniformGravity);
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

    if (!passed) return 1;
    std::puts("original executable constants regression: PASS");
    return 0;
}
