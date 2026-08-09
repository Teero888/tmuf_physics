#include "GmArchive.hpp"
#include "CClassicArchive.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>

namespace {

// Exact values loaded by TmForeverFixed.exe. Several qwords contain values
// first rounded to single precision and then promoted to double.
constexpr double kPi = 3.1415927410125732;
constexpr double kHalfPi = 1.5707963705062866;
constexpr double kPositionStep = 0.0020000000949949026;
constexpr double kPositionDivisor = -0.0020000000949949026;
constexpr double kVectorLogScale = 1000.0;
constexpr float kDirectionEpsilon = 9.999999747378752e-6f;

template <typename Integer>
Integer QuantizeAngle(float angle, double scale, double range) {
    return static_cast<Integer>(
        static_cast<int>(static_cast<double>(angle) * scale / range));
}

void WriteUnitVector(
    CClassicBuffer* buffer, const GmVec3& vector, bool wide) {
    const float elevation = std::asin(vector.z);
    const float elevationCosine = std::cos(elevation);
    float azimuth = 0.0f;
    if (std::abs(elevationCosine) >= kDirectionEpsilon) {
        const float horizontalCosine = std::clamp(
            vector.x / elevationCosine, -1.0f, 1.0f);
        azimuth = std::acos(horizontalCosine);
        if (vector.y * elevationCosine < 0.0f) azimuth = -azimuth;
    }

    if (wide) {
        const int16_t packedAzimuth =
            QuantizeAngle<int16_t>(azimuth, 32767.0, kPi);
        const int16_t packedElevation =
            QuantizeAngle<int16_t>(elevation, 32767.0, kHalfPi);
        buffer->WriteAll(&packedAzimuth, sizeof(packedAzimuth));
        buffer->WriteAll(&packedElevation, sizeof(packedElevation));
    } else {
        const int8_t packedAzimuth =
            QuantizeAngle<int8_t>(azimuth, 127.0, kPi);
        const int8_t packedElevation =
            QuantizeAngle<int8_t>(elevation, 127.0, kHalfPi);
        buffer->WriteAll(&packedAzimuth, sizeof(packedAzimuth));
        buffer->WriteAll(&packedElevation, sizeof(packedElevation));
    }
}

void ReadUnitVector(CClassicBuffer* buffer, GmVec3* vector, bool wide) {
    float azimuth;
    float elevation;
    if (wide) {
        int16_t packedAzimuth = 0;
        int16_t packedElevation = 0;
        buffer->ReadAll(&packedAzimuth, sizeof(packedAzimuth));
        buffer->ReadAll(&packedElevation, sizeof(packedElevation));
        azimuth = static_cast<float>(
            static_cast<double>(packedAzimuth) * kPi / 32767.0);
        elevation = static_cast<float>(
            static_cast<double>(packedElevation) * kHalfPi / 32767.0);
    } else {
        int8_t packedAzimuth = 0;
        int8_t packedElevation = 0;
        buffer->ReadAll(&packedAzimuth, sizeof(packedAzimuth));
        buffer->ReadAll(&packedElevation, sizeof(packedElevation));
        azimuth = static_cast<float>(
            static_cast<double>(packedAzimuth) * kPi / 127.0);
        elevation = static_cast<float>(
            static_cast<double>(packedElevation) * kHalfPi / 127.0);
    }

    const float elevationCosine = std::cos(elevation);
    vector->x = std::cos(azimuth) * elevationCosine;
    vector->y = std::sin(azimuth) * elevationCosine;
    vector->z = std::sin(elevation);
}

} // namespace

void GmArchive::ReadVec3Pos_12(CClassicBuffer* buffer, GmVec3* vector) {
    buffer->ReadAll(&vector->x, sizeof(vector->x));
    buffer->ReadAll(&vector->y, sizeof(vector->y));
    buffer->ReadAll(&vector->z, sizeof(vector->z));
}

void GmArchive::WriteVec3Pos_12(
    CClassicBuffer* buffer, const GmVec3* vector) {
    buffer->WriteAll(&vector->x, sizeof(vector->x));
    buffer->WriteAll(&vector->y, sizeof(vector->y));
    buffer->WriteAll(&vector->z, sizeof(vector->z));
}

void GmArchive::ReadReal_3(CClassicBuffer* buffer, float* value) {
    uint8_t high = 0;
    uint16_t low = 0;
    buffer->ReadAll(&high, sizeof(high));
    buffer->ReadAll(&low, sizeof(low));
    const int32_t quantized =
        (static_cast<int32_t>(high) - 0x80) * 0x10000 + low;
    *value = static_cast<float>(
        static_cast<double>(quantized) * kPositionStep);
}

void GmArchive::WriteReal_3(CClassicBuffer* buffer, float value) {
    const int32_t quantized = static_cast<int32_t>(
        static_cast<double>(value) / kPositionDivisor);
    const uint32_t packed =
        static_cast<uint32_t>(0x800000 - quantized) & 0xffffffu;
    const uint8_t high = static_cast<uint8_t>(packed >> 16u);
    const uint16_t low = static_cast<uint16_t>(packed);
    buffer->WriteAll(&high, sizeof(high));
    buffer->WriteAll(&low, sizeof(low));
}

void GmArchive::ReadVec3Pos_9(CClassicBuffer* buffer, GmVec3* vector) {
    ReadReal_3(buffer, &vector->x);
    ReadReal_3(buffer, &vector->y);
    ReadReal_3(buffer, &vector->z);
}

void GmArchive::WriteVec3Pos_9(
    CClassicBuffer* buffer, const GmVec3* vector) {
    WriteReal_3(buffer, vector->x);
    WriteReal_3(buffer, vector->y);
    WriteReal_3(buffer, vector->z);
}

void GmArchive::ReadVec3Unit_4(CClassicBuffer* buffer, GmVec3* vector) {
    ReadUnitVector(buffer, vector, true);
}

void GmArchive::WriteVec3Unit_4(
    CClassicBuffer* buffer, const GmVec3* vector) {
    WriteUnitVector(buffer, *vector, true);
}

void GmArchive::WriteVec3Unit_2(
    CClassicBuffer* buffer, const GmVec3* vector) {
    WriteUnitVector(buffer, *vector, false);
}

void GmArchive::ReadQuat_6(CClassicBuffer* buffer, GmQuat* quaternion) {
    uint16_t packedAngle = 0;
    buffer->ReadAll(&packedAngle, sizeof(packedAngle));
    GmVec3 axis;
    ReadUnitVector(buffer, &axis, true);

    const float angle = static_cast<float>(
        static_cast<double>(packedAngle) * kPi / 65535.0);
    const float sine = std::sin(angle);
    quaternion->w = std::cos(angle);
    quaternion->x = axis.x * sine;
    quaternion->y = axis.y * sine;
    quaternion->z = axis.z * sine;
}

void GmArchive::WriteQuat_6(
    CClassicBuffer* buffer, const GmQuat* quaternion) {
    const float angle = std::acos(quaternion->w);
    const float axisLength = std::sqrt(
        quaternion->x * quaternion->x +
        quaternion->y * quaternion->y +
        quaternion->z * quaternion->z);
    GmVec3 axis(1.0f, 0.0f, 0.0f);
    if (axisLength >= kDirectionEpsilon) {
        const float inverseLength = 1.0f / axisLength;
        axis = GmVec3(
            quaternion->x * inverseLength,
            quaternion->y * inverseLength,
            quaternion->z * inverseLength);
    }

    const uint16_t packedAngle = static_cast<uint16_t>(
        static_cast<int>(static_cast<double>(angle) * 65535.0 / kPi));
    buffer->WriteAll(&packedAngle, sizeof(packedAngle));
    WriteUnitVector(buffer, axis, true);
}

void GmArchive::ReadVec3_4(CClassicBuffer* buffer, GmVec3* vector) {
    int16_t packedMagnitude = 0;
    buffer->ReadAll(&packedMagnitude, sizeof(packedMagnitude));
    const float magnitude = packedMagnitude == INT16_MIN
        ? 0.0f
        : std::exp(static_cast<float>(
              static_cast<double>(packedMagnitude) / kVectorLogScale));
    GmVec3 direction;
    ReadUnitVector(buffer, &direction, false);
    *vector = direction * magnitude;
}

void GmArchive::WriteVec3_4(
    CClassicBuffer* buffer, const GmVec3* vector) {
    const float length = std::sqrt(
        vector->x * vector->x +
        vector->y * vector->y +
        vector->z * vector->z);
    int16_t packedMagnitude = INT16_MIN;
    GmVec3 direction(1.0f, 0.0f, 0.0f);
    if (length >= kDirectionEpsilon) {
        direction = *vector * (1.0f / length);
        const float logMagnitude = std::clamp(
            static_cast<float>(std::log(length) * kVectorLogScale),
            -32768.0f, 32767.0f);
        packedMagnitude = static_cast<int16_t>(
            static_cast<int>(logMagnitude));
    }

    buffer->WriteAll(&packedMagnitude, sizeof(packedMagnitude));
    WriteUnitVector(buffer, direction, false);
}
