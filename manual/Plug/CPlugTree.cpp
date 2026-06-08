#include "CPlugTree.hpp"

CPlugTree::CIteratorTree::~CIteratorTree() {}

CPlugTree::CPlugTree() : CMwNod(), m_solid(nullptr), m_parent(nullptr) {}
CPlugTree::~CPlugTree() {}

CMwNod* CPlugTree::MwNewCPlugTree() { return new CPlugTree(); }

void CPlugTree::SetLocation(CPlugTree* param_1, GmIso4* param_2) {}
void CPlugTree::SetTranslation(GmIso4* param_1, GmVec3* param_2) {}
void CPlugTree::SetRotation(GmMat2* param_1, float param_2) {}
void CPlugTree::SetIsVisible(CPlugTree* param_1, int param_2) {}

uint32_t CPlugTree::GetMwClassId() { return 0x09002000; }

void* CPlugTree::_scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2) {
    this->~CPlugTree();
    return this;
}

uint32_t CPlugTree::GetAllChildStart() { return 0; }
CPlugTree* CPlugTree::GetAllChildNext(CPlugTree* current) { return nullptr; }

#include "CClassicArchive.hpp"

void CPlugTree::Chunk(CFuncSegment* param_1, CClassicArchive* archive, uint32_t chunkId) {
    if (chunkId == 0x0904f010) {
        archive->DoNatural(&m_field_0x9c, 1);
        if (m_field_0x9c & 4) {
             float loc[12];
             archive->DoReal(loc, 12);
        }
    } else {
        CMwNod::Chunk(param_1, archive, chunkId);
    }
}
void CPlugTree::GetThisToRootTransfo(GmIso4* res, void* p, GmIso4* a, int i, CPlugTree* t) {}
GmIso4* CPlugTree::GetLocation() { return &m_location; }
