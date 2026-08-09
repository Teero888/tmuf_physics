#include "CHmsForceFieldBall.hpp"

#include <cstring>

CHmsForceFieldBall::CHmsForceFieldBall() : CHmsForceField() {
    m_pos[0] = 0.0f;
    m_pos[1] = 0.0f;
    m_pos[2] = 0.0f;
    // Exact constructor values at 0x55F700.
    m_field_0x5c = 0x40000000u; // radius = 2.0f
    m_field_0x60 = 0x3f800000u; // strength = 1.0f
}

CHmsForceFieldBall::~CHmsForceFieldBall() {}

bool CHmsForceFieldBall::GetValue(
    const GmVec3& position, GmVec3& value) const {
    const GmVec3 delta(
        m_pos[0] - position.x,
        m_pos[1] - position.y,
        m_pos[2] - position.z);
    const float distanceSquared = GmVec3::Dot(delta, delta);
    float radius;
    float strength;
    std::memcpy(&radius, &m_field_0x5c, sizeof(radius));
    std::memcpy(&strength, &m_field_0x60, sizeof(strength));
    constexpr float kDistanceSquaredEpsilon =
        9.99999943962492920972e-11f;
    if (distanceSquared >= radius * radius ||
        distanceSquared <= kDistanceSquaredEpsilon) {
        return false;
    }
    value = delta * (-strength / distanceSquared);
    return true;
}

CMwClassInfo* CHmsForceFieldBall::MwGetClassInfo(CFuncSegment* param_1) { return nullptr; }
CMwNod* CHmsForceFieldBall::MwNewCHmsForceFieldBall() { return new CHmsForceFieldBall(); }
int CHmsForceFieldBall::MwIsKindOf(uint32_t classId) { return 0; }
int CHmsForceFieldBall::TestBoxOverlap(GmBoxAligned* param_2) { return 0; }

uint32_t CHmsForceFieldBall::GetChunkInfo(CFuncSegment* param_1, uint32_t param_2) { return 0; }
uint32_t CHmsForceFieldBall::GetMwClassId() { return 0x06017000; }
uint32_t CHmsForceFieldBall::GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2) { return 0; }
uint32_t CHmsForceFieldBall::VirtualParam_Set(CSystemData* param_1, CMwStack* param_2, void* param_3) { return 0; }

void* CHmsForceFieldBall::_scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2) {
    this->~CHmsForceFieldBall();
    return this;
}

void CHmsForceFieldBall::Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3) {}
void CHmsForceFieldBall::ComputeBoundingBox(CPlugVisualStrip* param_1, uint32_t param_2, uint32_t param_3) {}
