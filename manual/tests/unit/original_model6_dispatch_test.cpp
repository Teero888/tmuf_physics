#include <array>
#include <cstdint>
#include <cstdio>
#include <fstream>

namespace {

template <std::size_t N>
bool ExpectBytes(std::ifstream& executable,
                 const char* name,
                 std::streamoff fileOffset,
                 const std::array<std::uint8_t, N>& expected) {
    std::array<std::uint8_t, N> actual{};
    executable.clear();
    executable.seekg(fileOffset);
    executable.read(reinterpret_cast<char*>(actual.data()), actual.size());
    if (!executable || actual != expected) {
        std::fprintf(stderr, "%s: instruction mismatch at file offset 0x%llx\n",
                     name, static_cast<unsigned long long>(fileOffset));
        return false;
    }
    return true;
}

bool ExpectTuningOffset(std::ifstream& executable,
                        std::uint32_t parameterIndex,
                        std::uint32_t expectedObjectOffset) {
    constexpr std::streamoff kParameterPointerTable = 0x7a3438;
    constexpr std::uint32_t kImageBase = 0x400000;

    std::uint32_t descriptorVa = 0;
    executable.clear();
    executable.seekg(kParameterPointerTable + parameterIndex * sizeof(std::uint32_t));
    executable.read(reinterpret_cast<char*>(&descriptorVa), sizeof(descriptorVa));
    if (!executable || descriptorVa < kImageBase) return false;

    const std::streamoff descriptorOffset = descriptorVa - kImageBase;
    std::uint32_t parameterId = 0;
    std::uint32_t objectOffset = 0;
    executable.seekg(descriptorOffset + 4);
    executable.read(reinterpret_cast<char*>(&parameterId), sizeof(parameterId));
    executable.seekg(descriptorOffset + 12);
    executable.read(reinterpret_cast<char*>(&objectOffset), sizeof(objectOffset));

    const bool passed = executable && parameterId == 0x0a029000u + parameterIndex &&
                        objectOffset == expectedObjectOffset;
    if (!passed) {
        std::fprintf(stderr,
                     "tuning parameter 0x%03x: expected object offset 0x%x, got 0x%x\n",
                     parameterIndex, expectedObjectOffset, objectOffset);
    }
    return passed;
}

} // namespace

int main() {
    std::ifstream executable("../exe/TmForeverFixed.exe", std::ios::binary);
    if (!executable) {
        std::fputs("cannot open ../exe/TmForeverFixed.exe\n", stderr);
        return 1;
    }

    bool passed = true;

    // ComputeForces compares Tuning::SteerModel (+0x354) with 5, then calls
    // the fixed Model6 entry point at 0x7C3E80.
    passed &= ExpectBytes(executable, "Steer06 dispatch", 0x3c6e25,
                          std::array<std::uint8_t, 7>{0x83, 0xb9, 0x54, 0x03, 0x00, 0x00, 0x05});
    passed &= ExpectBytes(executable, "Model6 call", 0x3c6e77,
                          std::array<std::uint8_t, 5>{0xe8, 0x04, 0xd0, 0xff, 0xff});
    passed &= ExpectBytes(executable, "Model6 eleven-argument return", 0x3c6824,
                          std::array<std::uint8_t, 3>{0xc2, 0x2c, 0x00});

    // Runtime SMwParamInfo descriptors provide the exact 32-bit object
    // offsets used by both Model3 and Model6.
    passed &= ExpectTuningOffset(executable, 0x002, 0x034); // AccelCurve
    passed &= ExpectTuningOffset(executable, 0x01c, 0x094); // SteerSpeed
    passed &= ExpectTuningOffset(executable, 0x01d, 0x074); // SteerLowSpeed
    passed &= ExpectTuningOffset(executable, 0x01e, 0x098); // SteerGroundTorque
    passed &= ExpectTuningOffset(executable, 0x01f, 0x09c); // slipping coefficient
    passed &= ExpectTuningOffset(executable, 0x021, 0x0a4); // SideFriction1
    passed &= ExpectTuningOffset(executable, 0x023, 0x0ac); // MaxSideFriction curve
    passed &= ExpectTuningOffset(executable, 0x024, 0x0b0); // sliding coefficient
    passed &= ExpectTuningOffset(executable, 0x025, 0x0b4); // blend coefficient
    passed &= ExpectTuningOffset(executable, 0x030, 0x0e4); // legacy wheel blend
    passed &= ExpectTuningOffset(executable, 0x065, 0x354); // SteerModel

    if (!passed) return 1;
    std::puts("original Model6 dispatch/layout regression: PASS");
    return 0;
}
