#ifndef CPLUGSURFACEMATERIALDATA_HPP
#define CPLUGSURFACEMATERIALDATA_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CPlugSurfaceMaterialData : public CMwNod {
public:
    float m_restitution; // 0x14? Or 0x04 if not inherited?
    // Dump says void* vftable at 0x0, then field_0x4.
    // If it inherits from CMwNod, offset would be 0x14.
    // But dump struct doesn't show inheritance.
    // Let's assume it's a simple struct for now as per dump.

    CPlugSurfaceMaterialData() : m_restitution(0.0f) {}
    
    float GetRestitutionCoefWith(CPlugSurfaceMaterialData* other);
};

#endif // CPLUGSURFACEMATERIALDATA_HPP
