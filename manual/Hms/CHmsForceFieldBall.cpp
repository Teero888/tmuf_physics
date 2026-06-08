#include "CHmsForceFieldBall.hpp"

CHmsForceFieldBall::CHmsForceFieldBall() : CHmsForceField() {
    m_pos[0] = 0;
    m_pos[1] = 0;
    m_pos[2] = 0;
}

CHmsForceFieldBall::~CHmsForceFieldBall() {}

GmVec3 CHmsForceFieldBall::GetValue(CFuncColorGradient* param_1, float param_2) {
    return GmVec3(0, 0, 0);
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
