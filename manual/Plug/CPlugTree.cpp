#include "CPlugTree.hpp"
#include "CPlugSurface.hpp"

CPlugTree::CIteratorTree::~CIteratorTree() {}

CPlugTree::CPlugTree()
    : CMwNod(),
      m_solid(nullptr),
      m_plugId(0u),
      m_nod1c(nullptr),
      m_nameId(0u),
      m_parent(nullptr),
      m_field_0x4c(0u),
      m_field_0x50(0u),
      m_field_0x54(0u),
      m_field_0x58(0u),
      m_surface(nullptr),
      m_ptr90(nullptr),
      m_nod94(nullptr),
      m_nod98(nullptr),
      m_field_0x9c(0x0001e80au),
      m_ptrA0(nullptr),
      m_ptrA4(nullptr),
      m_nodA8(nullptr) {
    m_location.SetIdentity();
    m_boundingBox.InitEmpty();
}
CPlugTree::~CPlugTree() {}

CMwNod* CPlugTree::MwNewCPlugTree() { return new CPlugTree(); }

void CPlugTree::AddChild(CPlugTree* child) {
    if (child == nullptr || child == this) return;
    for (uint32_t index = 0; index < m_children.GetCount(); ++index) {
        if (m_children[index] == child) return;
    }
    m_children.Add(child);
    child->m_parent = this;
    child->m_solid = m_solid;
}

uint32_t CPlugTree::GetChildCount() const {
    return m_children.GetCount();
}

CPlugTree* CPlugTree::GetChild(uint32_t index) const {
    return index < m_children.GetCount() ? m_children[index] : nullptr;
}

void CPlugTree::GetThisToRootTransfo(
    GmIso4& result, bool includeThis, const CPlugTree* stopBefore) const {
    if (m_parent != nullptr && m_parent != stopBefore) {
        m_parent->GetThisToRootTransfo(result, true, stopBefore);
    } else {
        result.SetIdentity();
    }
    if (includeThis && UsesLocation()) {
        const GmIso4 parentToRoot = result;
        result.SetMult(m_location, parentToRoot);
    }
}

void CPlugTree::SetLocation(const GmIso4& location) {
    m_location = location;
    m_field_0x9c |= kLocationDirty;
}

void CPlugTree::SetTranslation(const GmVec3& translation) {
    m_location.SetTranslation(translation);
    m_field_0x9c |= kLocationDirty;
}

void CPlugTree::SetRotation(const GmMat3& rotation) {
    m_location.rot = rotation;
    m_field_0x9c |= kLocationDirty;
}

void CPlugTree::SetIsVisible(bool visible) {
    m_field_0x9c = (m_field_0x9c & ~kVisible) |
                   (visible ? kVisible : 0u);
}

void CPlugTree::SetIsCollidable(bool collidable) {
    m_field_0x9c = (m_field_0x9c & ~kCollisionEnabled) |
                   (collidable ? kCollisionEnabled : 0u);
}

void CPlugTree::SetUseLocation(bool useLocation) {
    m_field_0x9c = (m_field_0x9c & ~kUseLocation) |
                   (useLocation ? kUseLocation : 0u);
}

void CPlugTree::SetSurface(CPlugSurface* surface) {
    m_surface = surface;
}

bool CPlugTree::UsesLocation() const {
    return (m_field_0x9c & kUseLocation) != 0u;
}

bool CPlugTree::IsCollisionEnabled() const {
    return (m_field_0x9c & kCollisionEnabled) != 0u;
}

uint32_t CPlugTree::GetMwClassId() { return 0x09002000; }

void* CPlugTree::_scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2) {
    this->~CPlugTree();
    return this;
}

uint32_t CPlugTree::GetAllChildStart() {
    return m_children.IsEmpty() ? 0xffffffffu : 0u;
}
CPlugTree* CPlugTree::GetAllChildNext(CPlugTree* current) {
    if (current == nullptr) return GetChild(0u);
    for (uint32_t index = 0; index < m_children.GetCount(); ++index) {
        if (m_children[index] == current) return GetChild(index + 1u);
    }
    return nullptr;
}

#include "CClassicArchive.hpp"

void CPlugTree::Chunk(CFuncSegment* param_1, CClassicArchive* archive, uint32_t chunkId) {
    if (chunkId == 0x0904f010) {
        archive->DoNatural(&m_field_0x9c, 1);
        if (m_field_0x9c & 4) {
             archive->DoReal(reinterpret_cast<float*>(&m_location), 12);
        }
    } else {
        CMwNod::Chunk(param_1, archive, chunkId);
    }
}
GmIso4* CPlugTree::GetLocation() { return &m_location; }
const GmIso4* CPlugTree::GetLocation() const { return &m_location; }
