#include "CPlugSurfaceMaterialData.hpp"

namespace {

// Recovered from the initializer at 0x8BD7F0.  The loop at 0x8BD823 fills all
// 31 entries with {1.0, 0.5}; the following stores apply these exceptions.
const CPlugSurfaceMaterialData kDefaultSurfaceMaterials[
    CPlugSurfaceMaterialData::kDefaultMaterialCount] = {
    { 1.00f,  0.50f}, //  0
    { 1.00f,  0.50f}, //  1
    { 1.00f,  0.50f}, //  2
    { 0.00f,  0.00f}, //  3
    { 1.00f,  0.50f}, //  4
    { 1.00f,  0.50f}, //  5
    { 1.00f,  0.50f}, //  6
    { 1.00f,  0.50f}, //  7
    { 1.00f,  0.50f}, //  8
    {-0.50f, -0.50f}, //  9
    {-0.50f, -0.50f}, // 10
    {-0.50f, -0.50f}, // 11
    { 1.00f,  0.50f}, // 12
    { 1.00f,  0.50f}, // 13
    { 1.00f,  0.50f}, // 14
    { 1.00f,  0.50f}, // 15
    { 1.00f,  0.50f}, // 16
    { 1.00f,  0.50f}, // 17
    { 1.00f,  0.50f}, // 18
    { 1.00f,  0.50f}, // 19
    { 1.00f,  0.50f}, // 20
    { 1.00f,  0.50f}, // 21
    { 1.00f,  0.50f}, // 22
    { 0.95f,  0.95f}, // 23
    { 0.80f,  0.80f}, // 24
    { 0.80f,  0.80f}, // 25
    { 1.00f,  0.50f}, // 26
    { 1.00f,  0.50f}, // 27
    { 1.00f,  0.50f}, // 28
    { 1.00f,  0.50f}, // 29
    { 1.00f,  0.50f}, // 30
};

} // namespace

float CPlugSurfaceMaterialData::GetRestitutionCoefWith(
    const CPlugSurfaceMaterialData* other) const {
    if (other == nullptr) return m_restitution;
    if (m_restitution <= 0.0f) {
        if (0.0f < other->m_restitution) {
            return m_restitution;
        }
        return other->m_restitution + m_restitution;
    }
    if (0.0f < other->m_restitution) {
        return other->m_restitution * m_restitution;
    }
    return other->m_restitution;
}

const CPlugSurfaceMaterialData& CPlugSurfaceMaterialData::GetDefault(
    uint16_t materialId) {
    if (materialId >= kDefaultMaterialCount) materialId = 0;
    return kDefaultSurfaceMaterials[materialId];
}
