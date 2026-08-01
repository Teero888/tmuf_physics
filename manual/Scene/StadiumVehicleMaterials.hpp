#ifndef STADIUMVEHICLEMATERIALS_HPP
#define STADIUMVEHICLEMATERIALS_HPP

#include <array>
#include <cstddef>
#include <cstdint>

namespace StadiumVehicleMaterials {

// Logical property order serialized by
// Vehicles/RefBuffer/StadiumVehicleMaterials.RefBuffer.Gbx.
struct Material {
    uint16_t materialId;
    float speed;
    float grip;
    float accelerationCoef;
    float brakeCoef;
};

inline constexpr std::array<Material, 13> kMaterials{{
    { 0, 1.0f, 1.0f, 1.0f, 1.0f},
    { 2, 0.5f, 0.15f, 0.4f, 0.05f},
    { 8, 0.7f, 0.5f, 1.0f, 1.0f},
    { 5, 0.2f, 0.5f, 0.4f, 1.0f},
    {16, 1.0f, 1.0f, 1.0f, 1.0f},
    {20, 0.1f, 0.5f, 0.5f, 1.0f},
    {17, 0.9f, 1.0f, 1.0f, 1.0f},
    {19, 1.0f, 0.85f, 1.0f, 0.85f},
    {21, 0.2f, 0.1f, 0.6f, 0.1f},
    { 3, 1.0f, 0.0f, 0.1f, 0.0f},
    { 6, 0.9f, 0.25f, 0.9f, 0.4f},
    { 4, 1.0f, 1.0f, 1.0f, 1.0f},
    {14, 1.0f, 1.0f, 1.0f, 1.0f},
}};

constexpr const Material* Find(uint16_t materialId) {
    for (const Material& material : kMaterials) {
        if (material.materialId == materialId) return &material;
    }
    return nullptr;
}

// Runtime ABI produced by CSceneVehicleCar::ComputeVehicleGroundMaterialVals
// at 0x7C2800. Model6 consumes +0x00 as speed, +0x04 as acceleration,
// +0x08 as braking, and +0x0C as grip. This deliberately differs from the
// serialized property's presentation order above.
struct GroundValues {
    float speed;
    float accelerationCoef;
    float brakeCoef;
    float grip;
};

static_assert(sizeof(GroundValues) == 0x10);
static_assert(offsetof(GroundValues, speed) == 0x00);
static_assert(offsetof(GroundValues, accelerationCoef) == 0x04);
static_assert(offsetof(GroundValues, brakeCoef) == 0x08);
static_assert(offsetof(GroundValues, grip) == 0x0C);

constexpr GroundValues ToGroundValues(const Material& material) {
    return {
        material.speed,
        material.accelerationCoef,
        material.brakeCoef,
        material.grip,
    };
}

} // namespace StadiumVehicleMaterials

#endif // STADIUMVEHICLEMATERIALS_HPP
