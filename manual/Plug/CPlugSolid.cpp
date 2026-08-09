#include "CPlugSolid.hpp"
#include "CPlugTree.hpp"

namespace {

void ConnectTreeToSolid(CPlugTree* tree, CPlugSolid* solid) {
    if (tree == nullptr) return;
    tree->m_solid = solid;
    for (uint32_t index = 0; index < tree->GetChildCount(); ++index) {
        CPlugTree* child = tree->GetChild(index);
        if (child == nullptr) continue;
        child->m_parent = tree;
        ConnectTreeToSolid(child, solid);
    }
}

} // namespace

CPlugSolid::CPlugSolid()
    : CMwNod(),
      m_field_0x14(0u),
      m_field_0x60(1u),
      m_tree(nullptr),
      m_solid68(nullptr),
      m_field_0x6c(0.0f),
      m_field_0x70(1u) {}
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
        archive->DoReal(&m_physicalObject.m_mass, 1);
        archive->DoReal(&m_physicalObject.m_centerOfMass.x, 3);
        m_physicalObject.m_inverseInertia.ArchiveGmMat3(*archive);
        archive->DoReal(&m_physicalObject.m_linearDamping, 1);
        archive->DoReal(&m_physicalObject.m_angularDampingX, 1);
        archive->DoReal(&m_physicalObject.m_maxDistancePerStep, 1);
    } else {
        CMwNod::Chunk(param_1, archive, chunkId);
    }
}
void CPlugSolid::OnNodLoaded(CDx9DeviceCaps* param_1) {}
void CPlugSolid::SetTree(CPlugTree* tree, bool connectTree) {
    m_tree = tree;
    m_physicalObject.m_tree32 =
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(tree));
    if (tree != nullptr) {
        tree->m_parent = nullptr;
        if (connectTree) ConnectTreeToSolid(tree, this);
    }
}

void CPlugSolid::SetTree(
    CPlugSolid* param_1, CPlugTree* param_2, int param_3) {
    // Preserve the decompiler-shaped entry point: its first explicit
    // argument is the tree despite the recovered type name.
    SetTree(reinterpret_cast<CPlugTree*>(param_1), param_2 != nullptr);
}
