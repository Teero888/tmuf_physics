#ifndef CPLUGSURFACEMATERIALDATA_HPP
#define CPLUGSURFACEMATERIALDATA_HPP

#include <cstddef>
#include <cstdint>
#include <type_traits>

// Native collision-response value at 0xD6EEC0.  This is not a CMwNod: the
// executable indexes it with an eight-byte stride and reads two adjacent
// floats directly.
struct CPlugSurfaceMaterialData {
public:
    float m_friction = 0.0f;    // 0x00
    float m_restitution = 0.0f; // 0x04

    float GetRestitutionCoefWith(
        const CPlugSurfaceMaterialData* other) const;

    static constexpr uint16_t kDefaultMaterialCount = 31;
    static const CPlugSurfaceMaterialData& GetDefault(uint16_t materialId);
};

static_assert(sizeof(CPlugSurfaceMaterialData) == 0x08);
static_assert(offsetof(CPlugSurfaceMaterialData, m_friction) == 0x00);
static_assert(offsetof(CPlugSurfaceMaterialData, m_restitution) == 0x04);
static_assert(std::is_standard_layout<CPlugSurfaceMaterialData>::value);
static_assert(std::is_trivially_copyable<CPlugSurfaceMaterialData>::value);

#endif // CPLUGSURFACEMATERIALDATA_HPP
