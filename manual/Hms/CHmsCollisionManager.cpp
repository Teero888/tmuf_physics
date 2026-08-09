#include "CHmsCollisionManager.hpp"
#include "CHmsCorpus.hpp"
#include "CHmsCollisionBuffer.hpp"
#include "CHmsDyna.hpp"
#include "CHmsItem.hpp"
#include "TmForeverPhysicsConstants.hpp"

#include <algorithm>
#include <cmath>
#include <limits>

// SGroup
void CHmsCollisionManager::SGroup::AddCorpus(
    CHmsZone*, CHmsCorpus* corpus) {
    if (corpus == nullptr) return;
    m_corpuses.Add(corpus);
    AddNonStaticCorpus(corpus);
}

void CHmsCollisionManager::SGroup::AddNonStaticCorpus(CHmsCorpus* corpus) {
    if (corpus == nullptr ||
        corpus->m_flags54 != std::numeric_limits<uint32_t>::max()) {
        return;
    }
    m_nonStaticCorpuses.Add(corpus);
    m_squaredLinearSpeeds.Add(0.0f);
    corpus->m_flags54 = m_nonStaticCorpuses.GetCount() - 1u;
}

void CHmsCollisionManager::SGroup::AddStaticSurfacesFromTree(CHmsCorpus* param_2, CPlugTree* param_3, GmIso4* param_4, void* param_5) {}
void CHmsCollisionManager::SGroup::ClearAllStatic() {
    for (uint32_t index = 0; index < m_corpuses.GetCount(); ++index) {
        CHmsCorpus* corpus = m_corpuses[index];
        if (corpus != nullptr &&
            corpus->m_flags54 == std::numeric_limits<uint32_t>::max()) {
            AddNonStaticCorpus(corpus);
        }
    }
    m_staticCollisionTreeData.m_count = 0;
}
void CHmsCollisionManager::SGroup::ComputeIsToPerformCollisions() {
    if (m_skipDynamicPairPreparation != 0u) return;
    for (SAgainstGroup& against : m_againstGroups) {
        if (against.m_against == nullptr) continue;
        if (against.m_against->m_skipDynamicPairPreparation != 0u) {
            std::fill(
                against.m_isToPerformCollision.begin(),
                against.m_isToPerformCollision.end(), 1u);
            continue;
        }

        for (uint32_t line = 0; line < against.m_lineCount; ++line) {
            for (uint32_t column = 0;
                 column < against.m_columnCount;
                 ++column) {
                const float difference =
                    m_squaredLinearSpeeds[line] -
                    against.m_against->m_squaredLinearSpeeds[column];
                uint32_t isToPerform = 0u;
                if (difference >
                    TmForeverPhysicsConstants::
                        kCollisionSpeedSquaredDifferenceEpsilon) {
                    isToPerform = 1u;
                } else if (!std::isnan(difference)) {
                    if (m_groupId == against.m_against->m_groupId) {
                        isToPerform = column != line ? 1u : 0u;
                    } else {
                        isToPerform =
                            m_groupId < against.m_against->m_groupId
                                ? 1u
                                : 0u;
                    }
                }
                against.Get(line, column) = isToPerform;
            }
        }
    }
}
void CHmsCollisionManager::SGroup::ComputeNonStaticCorpusInfos() {
    if (m_skipDynamicPairPreparation != 0u) return;
    for (uint32_t index = 0;
         index < m_nonStaticCorpuses.GetCount();
         ++index) {
        const CHmsCorpus* corpus = m_nonStaticCorpuses[index];
        GmVec3 linearSpeed{0.0f, 0.0f, 0.0f};
        if (corpus != nullptr && corpus->m_dyna != nullptr) {
            corpus->m_dyna->GetLinearSpeed(nullptr, &linearSpeed);
        }
        m_squaredLinearSpeeds[index] = GmVec3::Dot(
            linearSpeed, linearSpeed);
    }
}

void CHmsCollisionManager::SGroup::RemoveCorpus(
    CHmsZoneOverlay*, CHmsCorpus* corpus) {
    if (corpus == nullptr) return;
    m_corpuses.ReplaceByLast(corpus);
    if (corpus->m_flags54 != std::numeric_limits<uint32_t>::max()) {
        RemoveNonStaticCorpus(corpus);
    } else {
        ClearAllStatic();
    }
}

void CHmsCollisionManager::SGroup::RemoveNonStaticCorpus(
    CHmsCorpus* corpus) {
    if (corpus == nullptr) return;
    const uint32_t removedIndex = corpus->m_flags54;
    const uint32_t count = m_nonStaticCorpuses.GetCount();
    if (removedIndex >= count) return;

    CHmsCorpus* movedCorpus = m_nonStaticCorpuses[count - 1u];
    m_nonStaticCorpuses.RemoveAt(removedIndex);
    m_squaredLinearSpeeds.RemoveAt(removedIndex);
    corpus->m_flags54 = std::numeric_limits<uint32_t>::max();
    if (removedIndex + 1u < count && movedCorpus != nullptr) {
        movedCorpus->m_flags54 = removedIndex;
    }
}
void CHmsCollisionManager::SGroup::UpdateStaticCollisionTrees(CHmsCollisionManager* param_1) {}

// SZone
CHmsCollisionManager::SZone::SZone(
    uint32_t zoneId, CHmsCollisionManager* manager)
    : m_zoneId(zoneId), m_manager(manager) {
    for (uint32_t group = 0; group < 5u; ++group) {
        m_groups[group].m_groupId = group;
    }
    // Native constructor +0x10c: group index three (the fourth collision
    // group) bypasses dynamic speed/pair-table preparation.
    m_groups[3].m_skipDynamicPairPreparation = 1u;

    // CHmsItem::StaticInit builds these five native 20-byte relationship
    // records. SZone installs each relationship in both directions except
    // for the group-three self relationship.
    static constexpr uint32_t configurations[5][5] = {
        {3u, 1u, 0u, 0u, 1u},
        {2u, 4u, 0u, 1u, 0u},
        {3u, 3u, 1u, 1u, 1u},
        {3u, 4u, 1u, 1u, 1u},
        {1u, 5u, 0u, 1u, 0u},
    };
    for (const auto& configuration : configurations) {
        const uint32_t firstGroup = configuration[0] - 1u;
        const uint32_t secondGroup = configuration[1] - 1u;
        SGroup::SAgainstGroup firstAgainst{};
        firstAgainst.m_against = &m_groups[secondGroup];
        std::copy(
            configuration, configuration + 5u, firstAgainst.m_config);
        m_groups[firstGroup].m_againstGroups.push_back(firstAgainst);
        if (firstGroup != secondGroup) {
            SGroup::SAgainstGroup secondAgainst{};
            secondAgainst.m_against = &m_groups[firstGroup];
            std::copy(
                configuration, configuration + 5u,
                secondAgainst.m_config);
            m_groups[secondGroup].m_againstGroups.push_back(secondAgainst);
        }
    }
    RebuildPairTables();
}

void CHmsCollisionManager::SZone::RebuildPairTables() {
    for (SGroup& group : m_groups) {
        for (SGroup::SAgainstGroup& against : group.m_againstGroups) {
            against.m_lineCount = group.m_nonStaticCorpuses.GetCount();
            against.m_columnCount = against.m_against == nullptr
                ? 0u
                : against.m_against->m_nonStaticCorpuses.GetCount();
            against.m_isToPerformCollision.assign(
                against.m_lineCount * against.m_columnCount, 0u);
        }
    }
}

int CHmsCollisionManager::SZone::ComputeCollision(
    LocatedGmSurf* first,
    LocatedGmSurf* second,
    CGmCollisionBuffer* buffer) {
    return GmSurf::ComputeCollision(first, second, buffer);
}
int CHmsCollisionManager::SZone::ComputeCollisionTree1RootOnly(SPlugTreeLocatedPair* param_2, GmBoxAligned* param_3) { return 0; }
int CHmsCollisionManager::SZone::ComputeCollisionTree2RootOnly(SPlugTreeLocatedPair* param_2, GmBoxAligned* param_3) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegment(int param_2, GmVec3* param_3, GmVec3* param_4, float* param_5, CPlugTree** param_6) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegment2(int param_2, GmVec3* param_3, GmVec3* param_4, int param_5, float* param_6, GmVec3* param_7) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegment3(int param_2, GmVec3* param_3, GmVec3* param_4, float* param_5, uint16_t* param_6) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegmentTree(GmVec3* param_2, GmVec3* param_3, CPlugTree* param_4, GmIso4* param_5, float* param_6) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegmentTree2(GmVec3* param_2, GmVec3* param_3, int param_4, CPlugTree* param_5, GmIso4* param_6, float* param_7, GmVec3* param_8) { return 0; }
int CHmsCollisionManager::SZone::IntersectSegmentTree3(GmVec3* param_2, GmVec3* param_3, CPlugTree* param_4, GmIso4* param_5, float* param_6, uint16_t* param_7) { return 0; }
void CHmsCollisionManager::SZone::AddCorpus(CHmsCorpus* corpus) {
    if (corpus == nullptr || corpus->m_item == nullptr) return;
    const uint32_t group = (corpus->m_item->m_flags1 >> 13u) & 0xfu;
    if (group == 0u || group > 5u) return;
    m_groups[group - 1u].AddCorpus(nullptr, corpus);
    RebuildPairTables();
}
void CHmsCollisionManager::SZone::DetectCollisionBetween(
    CHmsCorpus* first, CHmsCorpus* second) {
    if (m_activeCollisionBuffer == nullptr || first == nullptr ||
        second == nullptr || first == second) {
        return;
    }

    for (uint32_t firstSurfaceIndex = 0;
         firstSurfaceIndex < first->m_collisionSurfaces.GetCount();
         ++firstSurfaceIndex) {
        LocatedGmSurf& firstSurface =
            first->m_collisionSurfaces[firstSurfaceIndex];
        for (uint32_t secondSurfaceIndex = 0;
             secondSurfaceIndex < second->m_collisionSurfaces.GetCount();
             ++secondSurfaceIndex) {
            LocatedGmSurf& secondSurface =
                second->m_collisionSurfaces[secondSurfaceIndex];
            const uint32_t firstNewCollision =
                m_activeCollisionBuffer->GetCount();
            if (ComputeCollision(
                    &firstSurface, &secondSurface,
                    m_activeCollisionBuffer) == 0) {
                continue;
            }
            const uint32_t collisionCount =
                m_activeCollisionBuffer->GetCount();
            for (uint32_t collisionIndex = firstNewCollision;
                 collisionIndex < collisionCount;
                 ++collisionIndex) {
                SHmsPhysicalCollision& collision =
                    m_activeCollisionBuffer->m_collisions[collisionIndex];
                collision.m_body1 = first;
                collision.m_body2 = second;
            }
        }
    }
}
void CHmsCollisionManager::SZone::DetectCollisionBetweenTreeAndStaticCollisionTree(GmIso4* param_2, CPlugTree* param_3) {}
void CHmsCollisionManager::SZone::DetectCollisionsCorpus(
    CHmsCollisionBuffer* buffer, CHmsCorpus* corpus) {
    if (buffer == nullptr || corpus == nullptr || corpus->m_item == nullptr) {
        return;
    }
    const uint32_t groupNumber =
        (corpus->m_item->m_flags1 >> 13u) & 0xfu;
    if (groupNumber == 0u || groupNumber > 5u) return;
    SGroup& group = m_groups[groupNumber - 1u];
    const uint32_t corpusIndex = corpus->m_flags54;
    if (corpusIndex >= group.m_nonStaticCorpuses.GetCount()) return;

    CHmsCollisionBuffer* previousBuffer = m_activeCollisionBuffer;
    m_activeCollisionBuffer = buffer;
    m_corpus18c = corpus;
    for (SGroup::SAgainstGroup& against : group.m_againstGroups) {
        if (corpusIndex >= against.m_lineCount ||
            against.m_against == nullptr) {
            continue;
        }
        for (uint32_t targetIndex = 0;
             targetIndex < against.m_columnCount;
             ++targetIndex) {
            if (against.Get(corpusIndex, targetIndex) == 0u) continue;
            DetectCollisionBetween(
                corpus,
                against.m_against->m_nonStaticCorpuses[targetIndex]);
        }
    }
    m_corpus18c = nullptr;
    m_activeCollisionBuffer = previousBuffer;
}
void CHmsCollisionManager::SZone::PrepareCollisions() {
    for (SGroup& group : m_groups) {
        group.ComputeNonStaticCorpusInfos();
    }
    for (SGroup& group : m_groups) {
        group.ComputeIsToPerformCollisions();
    }
}
void CHmsCollisionManager::SZone::RemoveCorpus(
    CHmsZoneOverlay* overlay, CHmsCorpus* corpus) {
    if (corpus == nullptr || corpus->m_item == nullptr) return;
    const uint32_t group = (corpus->m_item->m_flags1 >> 13u) & 0xfu;
    if (group == 0u || group > 5u) return;
    m_groups[group - 1u].RemoveCorpus(overlay, corpus);
    RebuildPairTables();
}
void CHmsCollisionManager::SZone::UpdateStaticCollisionTrees(
    CHmsCollisionManager* manager) {
    for (SGroup& group : m_groups) {
        group.UpdateStaticCollisionTrees(manager);
    }
}

// CHmsCollisionManager
CHmsCollisionManager::CHmsCollisionManager()
    : CMwNod(), m_field_0x14(2u) {}
CHmsCollisionManager::~CHmsCollisionManager() {
    m_zones.DeleteAll();
}

CMwClassInfo* CHmsCollisionManager::MwGetClassInfo(CFuncSegment* param_1) { return nullptr; }
CMwNod* CHmsCollisionManager::MwNewCHmsCollisionManager() { return new CHmsCollisionManager(); }
CHmsCollisionManager::SZone* CHmsCollisionManager::AddZone(uint32_t zoneId) {
    SZone* zone = new SZone(zoneId, this);
    m_zones.Add(zone);
    return zone;
}
int CHmsCollisionManager::MwIsKindOf(uint32_t classId) {
    return classId == 0x06019000u || classId == 0x01001000u;
}
uint32_t CHmsCollisionManager::GetMwClassId() { return 0x06019000; }

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
void CHmsCollisionManager::DisableStaticCollision() {
    for (uint32_t zoneIndex = 0;
         zoneIndex < m_zones.GetCount();
         ++zoneIndex) {
        SZone* zone = m_zones[zoneIndex];
        if (zone == nullptr) continue;
        for (SGroup& group : zone->m_groups) {
            group.ClearAllStatic();
        }
        zone->RebuildPairTables();
    }
}
void CHmsCollisionManager::MwIsKilled(CMwNod* param_2) {}
void CHmsCollisionManager::RemoveZone(uint32_t zoneId) {
    for (uint32_t zoneIndex = 0;
         zoneIndex < m_zones.GetCount();
         ++zoneIndex) {
        SZone* zone = m_zones[zoneIndex];
        if (zone != nullptr && zone->m_zoneId == zoneId) {
            delete zone;
            m_zones.RemoveAt(zoneIndex);
            return;
        }
    }
}
void CHmsCollisionManager::UpdateStaticCollisionTrees() {
    for (uint32_t zoneIndex = 0;
         zoneIndex < m_zones.GetCount();
         ++zoneIndex) {
        if (m_zones[zoneIndex] != nullptr) {
            m_zones[zoneIndex]->UpdateStaticCollisionTrees(this);
        }
    }
}
