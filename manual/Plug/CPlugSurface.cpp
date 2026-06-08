#include "CPlugSurface.hpp"

CPlugSurface::CPlugSurface() : CMwNod(), m_nod14(nullptr) {}
CPlugSurface::~CPlugSurface() {}

CMwClassInfo* CPlugSurface::MwGetClassInfo(CFuncSegment* param_1) { return nullptr; }
CMwNod* CPlugSurface::MwNewCPlugSurface() { return new CPlugSurface(); }

int CPlugSurface::ComputeCollision(LocatedGmSurf* param_1, LocatedGmSurf* param_2, CGmCollisionBuffer* param_3) {
    return 0;
}

int CPlugSurface::MwIsKindOf(uint32_t classId) { return 0; }
uint32_t CPlugSurface::GetChunkInfo(CFuncSegment* param_1, uint32_t param_2) { return 0; }
uint32_t CPlugSurface::GetMwClassId() { return 0x0900C000; }
uint32_t CPlugSurface::GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2) { return 0; }

void* CPlugSurface::_scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2) {
    this->~CPlugSurface();
    return this;
}

void CPlugSurface::StaticInit() {}
void CPlugSurface::StaticRelease() {}
#include "CClassicArchive.hpp"

void CPlugSurface::Chunk(CFuncSegment* param_1, CClassicArchive* archive, uint32_t chunkId) {
    if (chunkId == 0x0900c000) {
        uint32_t dummy;
        archive->DoNatural(&dummy, 1);
    } else {
        CMwNod::Chunk(param_1, archive, chunkId);
    }
}
