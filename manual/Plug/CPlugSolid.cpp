#include "CPlugSolid.hpp"

CPlugSolid::CPlugSolid() : CMwNod(), m_model5c(nullptr), m_solid68(nullptr) {}
CPlugSolid::~CPlugSolid() {}

CMwNod* CPlugSolid::MwNewCPlugSolid() { return new CPlugSolid(); }

CPlugTree* CPlugSolid::GetPlugFromId(CPlugSolid* param_1, CMwId* param_2) { return nullptr; }
uint32_t CPlugSolid::GetMwClassId() { return 0x09005000; }

void* CPlugSolid::_scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2) {
    this->~CPlugSolid();
    return this;
}

void CPlugSolid::Chunk(CFuncSegment* param_1, CClassicArchive* archive, uint32_t chunkId) {
    if (chunkId == 0x0900500e) {
        archive->DoReal(&m_mass, 1);
        float dummy[4];
        archive->DoReal(dummy, 4);
        float mat[9];
        archive->DoReal(mat, 9);
        archive->DoReal((float*)&m_field_0x40, 1);
        archive->DoReal((float*)&m_field_0x44, 1);
        archive->DoReal((float*)&m_field_0x48, 1);
    } else {
        CMwNod::Chunk(param_1, archive, chunkId);
    }
}
void CPlugSolid::OnNodLoaded(CDx9DeviceCaps* param_1) {}
void CPlugSolid::SetTree(CPlugSolid* param_1, CPlugTree* param_2, int param_3) {}
