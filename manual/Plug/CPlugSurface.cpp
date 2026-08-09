#include "CPlugSurface.hpp"
#include "CPlugSurfaceGeom.hpp"
#include "GmSurf.hpp"
#include "GmCollision.hpp"

CPlugSurface::CPlugSurface() : CMwNod(), m_geometry(nullptr) {}
CPlugSurface::~CPlugSurface() {}

CMwClassInfo* CPlugSurface::MwGetClassInfo(CFuncSegment* param_1) { return nullptr; }
CMwNod* CPlugSurface::MwNewCPlugSurface() { return new CPlugSurface(); }

int CPlugSurface::ComputeCollision(LocatedGmSurf* param_1, LocatedGmSurf* param_2, CGmCollisionBuffer* param_3) {
    return GmSurf::ComputeCollision(param_1, param_2, param_3);
}

int CPlugSurface::ComputeCollision(
    LocatedPlugSurface* first,
    LocatedPlugSurface* second,
    CGmCollisionBuffer* buffer) {
    if (first == nullptr || second == nullptr || buffer == nullptr ||
        first->m_surface == nullptr || second->m_surface == nullptr ||
        first->m_surface->m_geometry == nullptr ||
        second->m_surface->m_geometry == nullptr) {
        return 0;
    }
    GmSurf* firstGmSurf = first->m_surface->m_geometry->GetGmSurf();
    GmSurf* secondGmSurf = second->m_surface->m_geometry->GetGmSurf();
    if (firstGmSurf == nullptr || secondGmSurf == nullptr) return 0;

    LocatedGmSurf locatedFirst{firstGmSurf, first->m_location};
    LocatedGmSurf locatedSecond{secondGmSurf, second->m_location};
    const uint32_t firstNewCollision = buffer->GetCount();
    if (GmSurf::ComputeCollision(
            &locatedFirst, &locatedSecond, buffer) == 0) {
        return 0;
    }

    // This is the typed equivalent of native CPlugSurface::ComputeCollision
    // remapping collision IDs through each surface's material-ref buffer.
    for (uint32_t index = firstNewCollision;
         index < buffer->GetCount(); ++index) {
        GmCollision* collision = buffer->GetCollision(index);
        if (collision->m_id1 < first->m_surface->m_materialIds.GetCount()) {
            collision->m_id1 =
                first->m_surface->m_materialIds[collision->m_id1];
        }
        if (collision->m_id2 < second->m_surface->m_materialIds.GetCount()) {
            collision->m_id2 =
                second->m_surface->m_materialIds[collision->m_id2];
        }
    }
    return 1;
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
