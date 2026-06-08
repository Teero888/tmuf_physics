#include "CHmsCollisionManager.hpp"

// SGroup::SAgainstGroup
CHmsCollisionManager::SGroup::SAgainstGroup::~SAgainstGroup() {}

// SGroup
CHmsCollisionManager::SGroup::~SGroup() {}
void CHmsCollisionManager::SGroup::AddCorpus(CHmsZone* param_1, CHmsCorpus* param_2) {}
void CHmsCollisionManager::SGroup::AddNonStaticCorpus(CHmsCorpus* param_2) {}
void CHmsCollisionManager::SGroup::AddStaticSurfacesFromTree(CHmsCorpus* param_2, CPlugTree* param_3, GmIso4* param_4, void* param_5) {}
void CHmsCollisionManager::SGroup::ClearAllStatic() {}
void CHmsCollisionManager::SGroup::ComputeIsToPerformCollisions() {}
void CHmsCollisionManager::SGroup::ComputeNonStaticCorpusInfos() {}
void CHmsCollisionManager::SGroup::RemoveCorpus(CHmsZoneOverlay* param_1, CHmsCorpus* param_2) {}
void CHmsCollisionManager::SGroup::RemoveNonStaticCorpus(CHmsCorpus* param_2) {}
void CHmsCollisionManager::SGroup::UpdateStaticCollisionTrees(CHmsCollisionManager* param_1) {}

// SZone
CHmsCollisionManager::SZone::~SZone() {}
int CHmsCollisionManager::SZone::ComputeCollision(LocatedGmSurf* param_1, LocatedGmSurf* param_2, CGmCollisionBuffer* param_3) { return 0; }
int CHmsCollisionManager::SZone::ComputeCollisionTree1RootOnly(SPlugTreeLocatedPair* param_2, GmBoxAligned* param_3) { return 0; }
int CHmsCollisionManager::SZone::ComputeCollisionTree2RootOnly(SPlugTreeLocatedPair* param_2, GmBoxAligned* param_3) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegment(int param_2, GmVec3* param_3, GmVec3* param_4, float* param_5, CPlugTree** param_6) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegment2(int param_2, GmVec3* param_3, GmVec3* param_4, int param_5, float* param_6, GmVec3* param_7) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegment3(int param_2, GmVec3* param_3, GmVec3* param_4, float* param_5, uint16_t* param_6) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegmentTree(GmVec3* param_2, GmVec3* param_3, CPlugTree* param_4, GmIso4* param_5, float* param_6) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegmentTree2(GmVec3* param_2, GmVec3* param_3, int param_4, CPlugTree* param_5, GmIso4* param_6, float* param_7, GmVec3* param_8) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegmentTree3(GmVec3* param_2, GmVec3* param_3, CPlugTree* param_4, GmIso4* param_5, float* param_6, uint16_t* param_7) { return 0; }
void CHmsCollisionManager::SZone::AddCorpus(CHmsCorpus* param_2) {}
void CHmsCollisionManager::SZone::DetectCollisionBetween(CHmsCorpus* param_2, CHmsCorpus* param_3) {}
void CHmsCollisionManager::SZone::DetectCollisionBetweenTreeAndStaticCollisionTree(GmIso4* param_2, CPlugTree* param_3) {}
void CHmsCollisionManager::SZone::DetectCollisionsCorpus(CHmsCollisionBuffer* param_2, CHmsCorpus* param_3) {}
void CHmsCollisionManager::SZone::PrepareCollisions() {}
void CHmsCollisionManager::SZone::RemoveCorpus(CHmsZoneOverlay* param_1, CHmsCorpus* param_2) {}
void CHmsCollisionManager::SZone::UpdateStaticCollisionTrees(CHmsCollisionManager* param_1) {}

// CHmsCollisionManager
CHmsCollisionManager::CHmsCollisionManager() : CMwNod() {}
CHmsCollisionManager::~CHmsCollisionManager() {}

CMwClassInfo* CHmsCollisionManager::MwGetClassInfo(CFuncSegment* param_1) { return nullptr; }
CMwNod* CHmsCollisionManager::MwNewCHmsCollisionManager() { return new CHmsCollisionManager(); }
CHmsCollisionManager::SZone* CHmsCollisionManager::AddZone(uint32_t param_2) { return nullptr; }
int CHmsCollisionManager::MwIsKindOf(uint32_t classId) { return 0; }
uint32_t CHmsCollisionManager::GetMwClassId() { return 0x06005000; }

uint32_t CHmsCollisionManager::VirtualParam_Get(CPlugBlendShapes* param_1, CMwStack* param_2, CMwValueStd* param_3) { return 0; }
uint32_t CHmsCollisionManager::VirtualParam_Set(CSystemData* param_1, CMwStack* param_2, void* param_3) { return 0; }

void* CHmsCollisionManager::_vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2) {
    this->~CHmsCollisionManager();
    if ((param_2 & 1) != 0) {
        delete this;
    }
    return this;
}

void CHmsCollisionManager::StaticAddRef() {}
void CHmsCollisionManager::StaticRelease() {}
void CHmsCollisionManager::DisableStaticCollision() {}
void CHmsCollisionManager::MwIsKilled(CMwNod* param_2) {}
void CHmsCollisionManager::RemoveZone(uint32_t param_2) {}
void CHmsCollisionManager::UpdateStaticCollisionTrees() {}
