#include "CPlugSurfaceMaterialData.hpp"

float CPlugSurfaceMaterialData::GetRestitutionCoefWith(CPlugSurfaceMaterialData* other) {
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
