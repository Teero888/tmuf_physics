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

    // ComputeForces converts smoothed steering into the Model6 input with
    // -steer * AsinSafe(1 / (SteerRadiusMin +
    //                        abs(localSpeed.z) * SteerRadiusCoef)).
    // The local-speed vector starts at stack +0x3C, making +0x44 its Z value.
    passed &= ExpectBytes(executable, "processed-steer forward-speed load",
                          0x3c6cb2,
                          std::array<std::uint8_t, 8>{
                              0xd9, 0x44, 0x24, 0x44,
                              0x8b, 0x0b, 0xd9, 0xe1});
    passed &= ExpectBytes(executable, "processed-steer radius fields",
                          0x3c6cc0,
                          std::array<std::uint8_t, 10>{
                              0xd9, 0x44, 0x24, 0x2c,
                              0xd8, 0x49, 0x70,
                              0xd8, 0x42, 0x6c});
    passed &= ExpectBytes(executable, "processed-steer epsilon branch",
                          0x3c6cce,
                          std::array<std::uint8_t, 27>{
                              0xd9, 0x05, 0x4c, 0xef, 0xb9, 0x00,
                              0xd9, 0x44, 0x24, 0x2c,
                              0xd8, 0xd1, 0xdf, 0xe0, 0xdd, 0xd9,
                              0xf6, 0xc4, 0x05, 0x7a, 0x06,
                              0xdd, 0xd8, 0xd9, 0xee, 0xeb, 0x18});
    passed &= ExpectBytes(executable, "processed-steer reciprocal and safe arcsine",
                          0x3c6ce9,
                          std::array<std::uint8_t, 24>{
                              0xd9, 0xe8, 0x51, 0xde, 0xf1,
                              0xd9, 0x5c, 0x24, 0x30,
                              0xd9, 0x44, 0x24, 0x30,
                              0xd9, 0x1c, 0x24,
                              0xe8, 0xb2, 0x08, 0xc9, 0xff,
                              0x83, 0xc4, 0x04});
    passed &= ExpectBytes(executable, "processed-steer sign and scale",
                          0x3c6d09,
                          std::array<std::uint8_t, 20>{
                              0xd9, 0x86, 0xe8, 0x05, 0x00, 0x00,
                              0x8b, 0x4c, 0x24, 0x40,
                              0x8b, 0x54, 0x24, 0x44,
                              0xd9, 0xe0, 0xd8, 0x4c, 0x24, 0x2c});

    // EngineIntegrate is a two-stack-argument thiscall. IntegrateVehicle
    // checks freewheel and reverse itself, lays down input followed by dt, and
    // calls the sole engine entry point.
    passed &= ExpectBytes(executable, "EngineIntegrate two-argument return", 0x3be2a0,
                          std::array<std::uint8_t, 3>{0xc2, 0x08, 0x00});
    passed &= ExpectBytes(executable, "engine freewheel check", 0x3c3afc,
                          std::array<std::uint8_t, 7>{0x83, 0xbe, 0x0c, 0x06, 0x00, 0x00, 0x00});
    passed &= ExpectBytes(executable, "engine reverse-input check", 0x3c3b0f,
                          std::array<std::uint8_t, 7>{0x83, 0xbe, 0xc4, 0x05, 0x00, 0x00, 0x00});
    passed &= ExpectBytes(executable, "EngineIntegrate call", 0x3c3b38,
                          std::array<std::uint8_t, 5>{0xe8, 0xc3, 0x9b, 0xff, 0xff});
    // EngineIntegrate reads the force-model state at car +0x69C, but its
    // state dispatch and writes target the distinct RPM/transmission state at
    // car +0x2E4. This distinction is live during an ordinary launch.
    passed &= ExpectBytes(executable, "engine force-state read", 0x3bd825,
                          std::array<std::uint8_t, 20>{
                              0x8b, 0x86, 0x9c, 0x06, 0x00, 0x00,
                              0xbd, 0x01, 0x00, 0x00, 0x00,
                              0x3b, 0xc5, 0x74, 0x7b,
                              0x83, 0xf8, 0x02, 0x74, 0x76});
    passed &= ExpectBytes(executable, "engine synchronizer-state dispatch", 0x3bd83d,
                          std::array<std::uint8_t, 21>{
                              0x83, 0xbe, 0xe4, 0x02, 0x00, 0x00, 0x04,
                              0x75, 0x06,
                              0x89, 0x8e, 0xe4, 0x02, 0x00, 0x00,
                              0x8b, 0x86, 0xe4, 0x02, 0x00, 0x00});

    // ComputeForces passes its local-speed stack vector as the sole argument
    // to ApplyFrictionForces. Both native exits pop exactly that pointer.
    passed &= ExpectBytes(executable, "ApplyFrictionForces call", 0x3c6ba3,
                          std::array<std::uint8_t, 5>{0xe8, 0x68, 0x81, 0xff, 0xff});
    passed &= ExpectBytes(executable, "ApplyFrictionForces one-argument return",
                          0x3bef4d,
                          std::array<std::uint8_t, 3>{0xc2, 0x04, 0x00});
    passed &= ExpectBytes(executable, "ApplyFrictionForces second return",
                          0x3bf07d,
                          std::array<std::uint8_t, 3>{0xc2, 0x04, 0x00});

    // ComputeForces snapshots the accumulated local force before friction.
    // Model6 then loads that second formal argument and forwards it as the
    // sole stack argument to ApplyWaterForces.
    passed &= ExpectBytes(executable, "pre-friction force snapshot",
                          0x3c6b8a,
                          std::array<std::uint8_t, 10>{
                              0x8d, 0x44, 0x24, 0x48, 0x50,
                              0xe8, 0x4c, 0x50, 0xd7, 0xff});
    passed &= ExpectBytes(executable, "Model6 water-force argument load",
                          0x3c3eaa,
                          std::array<std::uint8_t, 7>{
                              0x8b, 0x84, 0x24, 0x48, 0x01, 0x00, 0x00});
    passed &= ExpectBytes(executable, "ApplyWaterForces call",
                          0x3c3ec4,
                          std::array<std::uint8_t, 8>{
                              0x50, 0x8b, 0xcb, 0xe8,
                              0x44, 0xea, 0xff, 0xff});
    passed &= ExpectBytes(executable, "Model6 wheel suspension call",
                          0x3c492d,
                          std::array<std::uint8_t, 5>{
                              0xe8, 0xde, 0xce, 0xff, 0xff});
    // CHmsItem's two-argument overload forwards a local force and local point
    // to CHmsDyna. That body entry rotates both values before the world-space
    // accumulator adds the force and its COM-relative cross-product torque.
    passed &= ExpectBytes(executable, "item local point-force dispatch",
                          0x13cf81,
                          std::array<std::uint8_t, 11>{
                              0x8b, 0x44, 0x24, 0x14,
                              0x55, 0x50,
                              0xe8, 0xd4, 0x6f, 0xff, 0xff});
    passed &= ExpectBytes(executable, "dynamic local point-force transform",
                          0x133f60,
                          std::array<std::uint8_t, 13>{
                              0x83, 0xec, 0x18,
                              0x8b, 0x81, 0x2c, 0x03, 0x00, 0x00,
                              0x8b, 0x54, 0x24, 0x1c});
    passed &= ExpectBytes(executable, "world point-force COM lookup",
                          0x133a70,
                          std::array<std::uint8_t, 27>{
                              0x83, 0xec, 0x18,
                              0x8b, 0x81, 0x2c, 0x03, 0x00, 0x00,
                              0x8b, 0x54, 0x24, 0x1c,
                              0xd9, 0x02,
                              0x8b, 0x89, 0x08, 0x01, 0x00, 0x00,
                              0xd8, 0x40, 0x64,
                              0x83, 0xc1, 0x38});
    passed &= ExpectBytes(executable, "Model6 processed-steer wheel cosine",
                          0x3c4a9f,
                          std::array<std::uint8_t, 12>{
                              0xd9, 0x84, 0x24, 0x5c, 0x01, 0x00, 0x00,
                              0xe8, 0x35, 0xd4, 0x1f, 0x00});
    passed &= ExpectBytes(executable, "Model6 processed-steer wheel sine",
                          0x3c4ae0,
                          std::array<std::uint8_t, 14>{
                              0xd9, 0x84, 0x24, 0x5c, 0x01, 0x00, 0x00,
                              0xe8, 0x24, 0xd5, 0x1f, 0x00,
                              0xd9, 0x5c});
    passed &= ExpectBytes(executable, "Model6 wheel side-force coefficient",
                          0x3c4f3b,
                          std::array<std::uint8_t, 20>{
                              0x8b, 0x08,
                              0xd9, 0x81, 0xa4, 0x00, 0x00, 0x00,
                              0xd9, 0xe0,
                              0xdc, 0x0d, 0xb8, 0x13, 0xb3, 0x00,
                              0xd8, 0x4c, 0x24, 0x1c});
    passed &= ExpectBytes(executable, "Model6 wheel slip state stores",
                          0x3c4fb3,
                          std::array<std::uint8_t, 8>{
                              0xc7, 0x86, 0x2c, 0x01,
                              0x00, 0x00, 0x01, 0x00});
    passed &= ExpectBytes(executable, "Model6 wheel slip clear",
                          0x3c50d5,
                          std::array<std::uint8_t, 12>{
                              0xd9, 0xee,
                              0xc7, 0x86, 0x2c, 0x01, 0x00, 0x00,
                              0x00, 0x00, 0x00, 0x00});
    passed &= ExpectBytes(executable, "Model6 terminal-speed tuning fields",
                          0x3c667c,
                          std::array<std::uint8_t, 12>{
                              0xd9, 0x41, 0x30,
                              0x8b, 0xac, 0x24, 0x64, 0x01, 0x00, 0x00,
                              0xd8, 0x4d});
    passed &= ExpectBytes(executable, "Model6 forward-speed limit field",
                          0x3c669b,
                          std::array<std::uint8_t, 9>{
                              0xd9, 0x47, 0x08,
                              0xd9, 0x40, 0x2c,
                              0xd8, 0x4d, 0x00});
    passed &= ExpectBytes(executable, "Model6 terminal correction field",
                          0x3c66ce,
                          std::array<std::uint8_t, 11>{
                              0xd9, 0x44, 0x24, 0x2c,
                              0x8b, 0x10,
                              0xd8, 0x62, 0x60,
                              0xeb, 0x13});
    passed &= ExpectBytes(executable, "Model6 forward brake request fields",
                          0x3c63ab,
                          std::array<std::uint8_t, 28>{
                              0xd9, 0x42, 0x44,
                              0x8b, 0x00,
                              0xd8, 0x4f, 0x08,
                              0x8b, 0x8c, 0x24, 0x68, 0x01, 0x00, 0x00,
                              0x83, 0x39, 0x00,
                              0xd8, 0x40, 0x40,
                              0xd8, 0x4b, 0x54,
                              0xd8, 0x4c, 0x24, 0x20});
    passed &= ExpectBytes(executable, "Model6 forward brake slip modulation",
                          0x3c6372,
                          std::array<std::uint8_t, 16>{
                              0x8b, 0x10,
                              0xd9, 0x82, 0x40, 0x02, 0x00, 0x00,
                              0xd8, 0x4c, 0x24, 0x20,
                              0xd9, 0x5c, 0x24, 0x20});
    passed &= ExpectBytes(executable, "Model6 axial brake output",
                          0x3c6631,
                          std::array<std::uint8_t, 13>{
                              0xd9, 0x44, 0x24, 0x28,
                              0x8b, 0x8c, 0x24, 0x6c, 0x01, 0x00, 0x00,
                              0xd9, 0x11});
    passed &= ExpectBytes(executable, "Model6 lateral-over-limit transition",
                          0x3c5f0c,
                          std::array<std::uint8_t, 40>{
                              0x39, 0x6c, 0x24, 0x4c,
                              0x8b, 0x44, 0x24, 0x2c,
                              0x74, 0x20,
                              0x39, 0x6c, 0x24, 0x38,
                              0x89, 0x83, 0x2c, 0x06, 0x00, 0x00,
                              0x75, 0x06,
                              0x89, 0x83, 0x30, 0x06, 0x00, 0x00,
                              0x8b, 0xc8,
                              0x2b, 0x8b, 0x30, 0x06, 0x00, 0x00,
                              0x89, 0x8b, 0x34, 0x06});
    passed &= ExpectBytes(executable, "Model6 lateral-excess acceleration blend",
                          0x3c5f64,
                          std::array<std::uint8_t, 30>{
                              0xd9, 0x44, 0x24, 0x20,
                              0xd9, 0x44, 0x24, 0x28,
                              0x8b, 0x00,
                              0xd9, 0xc0, 0xde, 0xea, 0xde, 0xf9,
                              0xd9, 0x5c, 0x24, 0x38,
                              0xd9, 0x44, 0x24, 0x38,
                              0xd8, 0xb0, 0x00, 0x02, 0x00, 0x00});
    passed &= ExpectBytes(executable, "M5 slipping acceleration coefficient",
                          0x3f3eb7,
                          std::array<std::uint8_t, 10>{
                              0xd9, 0x86, 0xe4, 0x01, 0x00, 0x00,
                              0xd8, 0x4c, 0x24, 0x0c});
    passed &= ExpectBytes(executable, "Model6 previous over-limit store",
                          0x3c67ef,
                          std::array<std::uint8_t, 10>{
                              0x8b, 0x44, 0x24, 0x4c,
                              0x89, 0x83, 0x28, 0x06, 0x00, 0x00});
    passed &= ExpectBytes(executable, "Model6 timed engine-state lifecycle",
                          0x3c4839,
                          std::array<std::uint8_t, 15>{
                              0x83, 0xbb, 0x9c, 0x06, 0x00, 0x00, 0x01,
                              0x8b, 0x30,
                              0x89, 0x74, 0x24, 0x2c,
                              0x75, 0x41});
    passed &= ExpectBytes(executable, "Model6 state-one phase origin",
                          0x3c60da,
                          std::array<std::uint8_t, 20>{
                              0x8b, 0x44, 0x24, 0x2c,
                              0x2b, 0x83, 0xf4, 0x06, 0x00, 0x00,
                              0x85, 0xc0,
                              0x89, 0x44, 0x24, 0x68,
                              0xdb, 0x44, 0x24, 0x68});
    passed &= ExpectBytes(executable, "Model6 state-one tuning fields",
                          0x3c6102,
                          std::array<std::uint8_t, 18>{
                              0x8b, 0x82, 0x98, 0x02, 0x00, 0x00,
                              0xdb, 0x82, 0x98, 0x02, 0x00, 0x00,
                              0x85, 0xc0, 0x7d, 0x06,
                              0xd8, 0x05});
    passed &= ExpectBytes(executable, "Model6 state-three tuning fields",
                          0x3c6198,
                          std::array<std::uint8_t, 12>{
                              0x8b, 0x82, 0xa8, 0x02, 0x00, 0x00,
                              0xdb, 0x82, 0xa8, 0x02, 0x00, 0x00});
    passed &= ExpectBytes(executable, "Model6 state-three axial impulse",
                          0x3c6230,
                          std::array<std::uint8_t, 16>{
                              0xd9, 0x44, 0x24, 0x38,
                              0xd8, 0x88, 0xb8, 0x02, 0x00, 0x00,
                              0xd9, 0x5c, 0x24, 0x60,
                              0xd9, 0xee});
    passed &= ExpectBytes(executable, "Model6 engine-state axial composition",
                          0x3c62c0,
                          std::array<std::uint8_t, 22>{
                              0xd9, 0x44, 0x24, 0x64,
                              0xde, 0xca,
                              0xd9, 0x44, 0x24, 0x14,
                              0xd8, 0x4c, 0x24, 0x24,
                              0xde, 0xea,
                              0xd9, 0x44, 0x24, 0x60,
                              0xde, 0xc2});
    passed &= ExpectBytes(executable, "Model6 damper modulation helper",
                          0x3f3f80,
                          std::array<std::uint8_t, 18>{
                              0x51,
                              0xd9, 0x81, 0x1c, 0x01, 0x00, 0x00,
                              0x8d, 0x54, 0x24, 0x08,
                              0xd9, 0x81, 0x20, 0x01, 0x00, 0x00,
                              0xc7});
    passed &= ExpectBytes(executable, "central vehicle impulse one-argument return",
                          0x3be6cf,
                          std::array<std::uint8_t, 3>{0xc2, 0x04, 0x00});

    // ComputeCollisionResponse builds 0x4C-byte contacts. The second corpus
    // is stored exactly +0x40 from the first record at stack +0x50, and its
    // material exactly +0x48 at stack +0x98.
    passed &= ExpectBytes(executable, "physical contact opposite corpus +0x40",
                          0x149879,
                          std::array<std::uint8_t, 11>{
                              0x89, 0x7c, 0x24, 0x50,
                              0x89, 0xac, 0x24, 0x90, 0x00, 0x00, 0x00});
    passed &= ExpectBytes(executable, "physical contact opposite material +0x48",
                          0x1498b8,
                          std::array<std::uint8_t, 9>{
                              0x66, 0x89, 0x94, 0x24, 0x98,
                              0x00, 0x00, 0x00, 0xd9});

    // The generic scene-mobil contact callback has two stack arguments; the
    // car virtual and wheel lookup have one, while WheelAbsorbContact has two.
    passed &= ExpectBytes(executable, "scene mobil absorb two-argument return",
                          0x3b3a06,
                          std::array<std::uint8_t, 3>{0xc2, 0x08, 0x00});
    passed &= ExpectBytes(executable, "vehicle absorb one-argument return",
                          0x3c38da,
                          std::array<std::uint8_t, 3>{0xc2, 0x04, 0x00});
    passed &= ExpectBytes(executable, "wheel lookup one-argument return",
                          0x3bd07b,
                          std::array<std::uint8_t, 3>{0xc2, 0x04, 0x00});
    passed &= ExpectBytes(executable, "wheel absorb two-argument return",
                          0x3c17f9,
                          std::array<std::uint8_t, 3>{0xc2, 0x08, 0x00});
    passed &= ExpectBytes(executable, "vehicle other-material access",
                          0x3c3419,
                          std::array<std::uint8_t, 4>{0x0f, 0xb7, 0x47, 0x48});
    passed &= ExpectBytes(executable, "SDynaMath plain seven-argument return",
                          0x3bd1dd,
                          std::array<std::uint8_t, 1>{0xc3});
    passed &= ExpectBytes(executable, "SDynaMath caller cleanup",
                          0x3c387b,
                          std::array<std::uint8_t, 3>{0x83, 0xc4, 0x1c});
    passed &= ExpectBytes(executable, "local point vehicle impulse return",
                          0x3be689,
                          std::array<std::uint8_t, 3>{0xc2, 0x08, 0x00});
    passed &= ExpectBytes(executable, "wheel opposite corpus token load",
                          0x3c129c,
                          std::array<std::uint8_t, 5>{
                              0x8b, 0x4f, 0x40, 0x85, 0xc9});
    passed &= ExpectBytes(executable, "wheel opposite +Z axis extraction",
                          0x3c12b1,
                          std::array<std::uint8_t, 6>{
                              0xd9, 0x40, 0x08, 0xd9, 0x5c, 0x24});
    passed &= ExpectBytes(executable, "wheel opposite corpus token retention",
                          0x3c12e4,
                          std::array<std::uint8_t, 9>{
                              0x8b, 0x4f, 0x40, 0x89, 0x8e,
                              0x3c, 0x01, 0x00, 0x00});
    passed &= ExpectBytes(executable, "ground contact id three-argument return",
                          0x3bf6a1,
                          std::array<std::uint8_t, 3>{0xc2, 0x0c, 0x00});

    // Runtime SMwParamInfo descriptors provide the exact 32-bit object
    // offsets used by both Model3 and Model6.
    passed &= ExpectTuningOffset(executable, 0x002, 0x034); // AccelCurve
    passed &= ExpectTuningOffset(executable, 0x004, 0x1e4); // slipping curve coefficient
    passed &= ExpectTuningOffset(executable, 0x006, 0x200); // slip excess scale
    passed &= ExpectTuningOffset(executable, 0x007, 0x040); // BrakeBase
    passed &= ExpectTuningOffset(executable, 0x008, 0x044); // BrakeCoef
    passed &= ExpectTuningOffset(executable, 0x009, 0x048); // BrakeMax
    passed &= ExpectTuningOffset(executable, 0x00a, 0x04c); // dynamic BrakeMax
    passed &= ExpectTuningOffset(executable, 0x00b, 0x058); // GroundSlowDownBase
    passed &= ExpectTuningOffset(executable, 0x00c, 0x05c); // LinearFluidFrictionCoef
    passed &= ExpectTuningOffset(executable, 0x00e, 0x1e8); // M5 contact duration
    passed &= ExpectTuningOffset(executable, 0x00f, 0x060); // speed-limit force
    passed &= ExpectTuningOffset(executable, 0x011, 0x06c); // SteerRadiusMin
    passed &= ExpectTuningOffset(executable, 0x012, 0x070); // SteerRadiusCoef
    passed &= ExpectTuningOffset(executable, 0x01c, 0x094); // SteerSpeed
    passed &= ExpectTuningOffset(executable, 0x01d, 0x074); // SteerLowSpeed
    passed &= ExpectTuningOffset(executable, 0x01e, 0x098); // SteerGroundTorque
    passed &= ExpectTuningOffset(executable, 0x01f, 0x09c); // slipping coefficient
    passed &= ExpectTuningOffset(executable, 0x021, 0x0a4); // SideFriction1
    passed &= ExpectTuningOffset(executable, 0x023, 0x0ac); // MaxSideFriction curve
    passed &= ExpectTuningOffset(executable, 0x024, 0x0b0); // sliding coefficient
    passed &= ExpectTuningOffset(executable, 0x025, 0x0b4); // blend coefficient
    passed &= ExpectTuningOffset(executable, 0x030, 0x0e4); // legacy wheel blend
    passed &= ExpectTuningOffset(executable, 0x03b, 0x204); // WaterGravity
    passed &= ExpectTuningOffset(executable, 0x03c, 0x208); // rebound minimum H speed
    passed &= ExpectTuningOffset(executable, 0x03d, 0x20c); // bump minimum speed
    passed &= ExpectTuningOffset(executable, 0x03e, 0x214); // bump slowdown curve
    passed &= ExpectTuningOffset(executable, 0x03f, 0x210); // rebound curve
    passed &= ExpectTuningOffset(executable, 0x040, 0x218); // water friction curve
    passed &= ExpectTuningOffset(executable, 0x041, 0x21c); // angular friction
    passed &= ExpectTuningOffset(executable, 0x042, 0x220); // angular friction squared
    passed &= ExpectTuningOffset(executable, 0x048, 0x0e8); // angular Y impulse scale
    passed &= ExpectTuningOffset(executable, 0x049, 0x0ec); // angular impulse scale
    passed &= ExpectTuningOffset(executable, 0x04a, 0x120); // AbsorbingValMax
    passed &= ExpectTuningOffset(executable, 0x04b, 0x11c); // AbsorbingValMin
    passed &= ExpectTuningOffset(executable, 0x04c, 0x124); // AbsorbingValRest
    passed &= ExpectTuningOffset(executable, 0x050, 0x14c); // angular speed clamp
    passed &= ExpectTuningOffset(executable, 0x051, 0x150); // linear speed^2 delta clamp
    passed &= ExpectTuningOffset(executable, 0x05a, 0x170); // body friction
    passed &= ExpectTuningOffset(executable, 0x05b, 0x17c); // body restitution
    passed &= ExpectTuningOffset(executable, 0x05c, 0x174); // metal body friction
    passed &= ExpectTuningOffset(executable, 0x05d, 0x178); // metal body restitution
    passed &= ExpectTuningOffset(executable, 0x05e, 0x180); // concrete wheel friction
    passed &= ExpectTuningOffset(executable, 0x05f, 0x184); // concrete wheel restitution
    passed &= ExpectTuningOffset(executable, 0x060, 0x188); // metal wheel friction
    passed &= ExpectTuningOffset(executable, 0x061, 0x18c); // metal wheel restitution
    passed &= ExpectTuningOffset(executable, 0x065, 0x354); // SteerModel
    passed &= ExpectTuningOffset(executable, 0x088, 0x224); // wheel-compression curve
    passed &= ExpectTuningOffset(executable, 0x08f, 0x240); // slipping brake modulation
    passed &= ExpectTuningOffset(executable, 0x090, 0x248); // rear brake maximum
    passed &= ExpectTuningOffset(executable, 0x091, 0x24c); // dynamic rear brake maximum
    passed &= ExpectTuningOffset(executable, 0x092, 0x244); // slip/brake friction modulation
    passed &= ExpectTuningOffset(executable, 0x0a6, 0x298); // burnout duration
    passed &= ExpectTuningOffset(executable, 0x0a7, 0x29c); // burnout acceleration modulation
    passed &= ExpectTuningOffset(executable, 0x0ad, 0x2a8); // after-burnout duration
    passed &= ExpectTuningOffset(executable, 0x0ae, 0x2ac); // after-burnout acceleration modulation
    passed &= ExpectTuningOffset(executable, 0x0af, 0x2b8); // after-burnout impulse
    passed &= ExpectTuningOffset(executable, 0x0b1, 0x2d4); // M6MaxRPM
    passed &= ExpectTuningOffset(executable, 0x0b2, 0x2e0); // M6MinRPM
    passed &= ExpectTuningOffset(executable, 0x0b3, 0x2c4); // M6GearRatio
    passed &= ExpectTuningOffset(executable, 0x0b4, 0x2f8); // M6RpmWantedOnGearUp
    passed &= ExpectTuningOffset(executable, 0x0bc, 0x32c); // positive front speed
    passed &= ExpectTuningOffset(executable, 0x0bd, 0x330); // positive rear speed
    passed &= ExpectTuningOffset(executable, 0x0be, 0x334); // negative front speed
    passed &= ExpectTuningOffset(executable, 0x0bf, 0x338); // negative rear speed

    if (!passed) return 1;
    std::puts("original Model6 dispatch/layout regression: PASS");
    return 0;
}
