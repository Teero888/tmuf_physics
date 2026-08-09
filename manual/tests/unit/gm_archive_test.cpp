#include "../../Classic/CClassicBufferMemory.hpp"
#include "../../Gm/GmArchive.hpp"

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>

class CSceneVehicleCarTuning;
CSceneVehicleCarTuning* g_tuning = nullptr;

namespace {

bool Expect(const char* name, bool condition) {
    if (condition) return true;
    std::fprintf(stderr, "%s: FAILED\n", name);
    return false;
}

bool BytesEqual(
    const CClassicBufferMemory& buffer,
    const uint8_t* expected,
    uint32_t size) {
    return buffer.m_size == size &&
           std::memcmp(buffer.m_data, expected, size) == 0;
}

float Length(const GmVec3& vector) {
    return std::sqrt(
        vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

} // namespace

int main() {
    bool passed = true;
    CClassicBufferMemory buffer;

    GmArchive::WriteReal_3(&buffer, 1.0f);
    const uint8_t positiveOne[] = {0x80, 0xf3, 0x01};
    passed &= Expect(
        "24-bit position uses native high-byte/low-word order",
        BytesEqual(buffer, positiveOne, sizeof(positiveOne)));
    buffer.Reset();
    float decodedReal = 0.0f;
    GmArchive::ReadReal_3(&buffer, &decodedReal);
    passed &= Expect(
        "24-bit position uses native 0.002 quantization",
        std::abs(decodedReal - 0.99800003f) < 1.0e-7f &&
        buffer.m_cursor == 3u);

    buffer.Empty();
    const GmVec3 position(1.0f, 0.0f, -1.0f);
    GmArchive::WriteVec3Pos_9(&buffer, &position);
    const uint8_t packedPosition[] = {
        0x80, 0xf3, 0x01,
        0x80, 0x00, 0x00,
        0x7f, 0x0d, 0xfe,
    };
    passed &= Expect(
        "compressed position occupies exactly nine bytes",
        BytesEqual(buffer, packedPosition, sizeof(packedPosition)));

    buffer.Empty();
    const GmVec3 positiveY(0.0f, 1.0f, 0.0f);
    GmArchive::WriteVec3Unit_4(&buffer, &positiveY);
    const uint8_t packedPositiveY[] = {0xff, 0x3f, 0x00, 0x00};
    passed &= Expect(
        "wide unit vector stores signed azimuth and elevation",
        BytesEqual(buffer, packedPositiveY, sizeof(packedPositiveY)));
    buffer.Reset();
    GmVec3 decodedDirection;
    GmArchive::ReadVec3Unit_4(&buffer, &decodedDirection);
    passed &= Expect(
        "wide unit-vector decoding reconstructs the sphere",
        std::abs(decodedDirection.x) < 6.0e-5f &&
        decodedDirection.y > 0.99999f &&
        std::abs(decodedDirection.z) < 1.0e-6f);

    buffer.Empty();
    GmQuat identity;
    identity.SetIdentity();
    GmArchive::WriteQuat_6(&buffer, &identity);
    const uint8_t packedIdentity[] = {0, 0, 0, 0, 0, 0};
    passed &= Expect(
        "identity quaternion occupies six zero bytes",
        BytesEqual(buffer, packedIdentity, sizeof(packedIdentity)));
    buffer.Reset();
    GmQuat decodedQuaternion;
    GmArchive::ReadQuat_6(&buffer, &decodedQuaternion);
    passed &= Expect(
        "quaternion reader consumes exactly six bytes",
        decodedQuaternion.w == 1.0f &&
        decodedQuaternion.x == 0.0f &&
        decodedQuaternion.y == 0.0f &&
        decodedQuaternion.z == 0.0f &&
        buffer.m_cursor == 6u);

    buffer.Empty();
    GmArchive::WriteVec3_4(&buffer, &positiveY);
    const uint8_t packedUnitMagnitudeY[] = {0x00, 0x00, 0x3f, 0x00};
    passed &= Expect(
        "log-magnitude vector occupies exactly four bytes",
        BytesEqual(
            buffer, packedUnitMagnitudeY, sizeof(packedUnitMagnitudeY)));
    buffer.Reset();
    GmVec3 decodedVector;
    GmArchive::ReadVec3_4(&buffer, &decodedVector);
    passed &= Expect(
        "four-byte vector reader consumes two signed direction bytes",
        buffer.m_cursor == 4u &&
        std::abs(Length(decodedVector) - 1.0f) < 1.0e-6f &&
        decodedVector.y > 0.9999f);

    buffer.Empty();
    const GmVec3 zero(0.0f, 0.0f, 0.0f);
    GmArchive::WriteVec3_4(&buffer, &zero);
    const uint8_t packedZero[] = {0x00, 0x80, 0x00, 0x00};
    passed &= Expect(
        "zero vector uses the reserved negative magnitude",
        BytesEqual(buffer, packedZero, sizeof(packedZero)));
    buffer.Reset();
    GmArchive::ReadVec3_4(&buffer, &decodedVector);
    passed &= Expect(
        "reserved vector magnitude decodes to zero",
        decodedVector.x == 0.0f && decodedVector.y == 0.0f &&
        decodedVector.z == 0.0f && buffer.m_cursor == 4u);

    if (!passed) return 1;
    std::puts("Gm archive regression: PASS");
    return 0;
}
