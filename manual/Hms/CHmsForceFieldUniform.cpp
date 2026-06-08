#include "CHmsForceFieldUniform.hpp"

CHmsForceFieldUniform::CHmsForceFieldUniform() : CHmsForceField() {
    m_force[0] = 0;
    m_force[1] = 0;
    m_force[2] = 0;
}

CHmsForceFieldUniform::~CHmsForceFieldUniform() {}

GmVec3 CHmsForceFieldUniform::GetValue(CFuncColorGradient* param_1, float param_2) {
    return GmVec3(m_force[0], m_force[1], m_force[2]);
}

CMwClassInfo* CHmsForceFieldUniform::MwGetClassInfo(CFuncSegment* param_1) { return nullptr; }
CMwNod* CHmsForceFieldUniform::MwNewCHmsForceFieldUniform() { return new CHmsForceFieldUniform(); }
int CHmsForceFieldUniform::MwIsKindOf(uint32_t classId) { return 0; }
uint32_t CHmsForceFieldUniform::GetChunkInfo(CFuncSegment* param_1, uint32_t param_2) { return 0; }
uint32_t CHmsForceFieldUniform::GetMwClassId() { return 0x06016000; }
uint32_t CHmsForceFieldUniform::GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2) { return 0; }

void* CHmsForceFieldUniform::_scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2) {
    this->~CHmsForceFieldUniform();
    if ((param_2 & 1) != 0) {
        // delete this; // Need proper heap
    }
    return this;
}

void CHmsForceFieldUniform::Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3) {}
