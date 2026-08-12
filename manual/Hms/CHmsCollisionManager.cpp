#include "CHmsCollisionManager.hpp"
#include "CHmsCorpus.hpp"
#include "CHmsCollisionBuffer.hpp"
#include "CHmsDyna.hpp"
#include "CHmsItem.hpp"
#include "CPlugSolid.hpp"
#include "CPlugSurface.hpp"
#include "CPlugSurfaceGeom.hpp"
#include "CPlugTree.hpp"
#include "TmForeverPhysicsConstants.hpp"

#include <algorithm>
#include <cmath>
#include <limits>

namespace {

bool BoxesIntersect(
    const GmBoxAligned& first, const GmBoxAligned& second) {
    return std::fabs(first.center.x - second.center.x) <=
               first.extents.x + second.extents.x &&
           std::fabs(first.center.y - second.center.y) <=
               first.extents.y + second.extents.y &&
           std::fabs(first.center.z - second.center.z) <=
               first.extents.z + second.extents.z;
}

GmIso4 ComposePlugTreeLocation(
    const CPlugTree& tree, const GmIso4& parentToWorld) {
    GmIso4 nodeToWorld = parentToWorld;
    if (tree.UsesLocation()) {
        nodeToWorld.SetMult(tree.m_location, parentToWorld);
    }
    return nodeToWorld;
}

void CollectLocatedPlugSurfaces(
    CPlugTree* tree,
    const GmIso4& parentToWorld,
    std::vector<LocatedPlugSurface>& leaves) {
    if (tree == nullptr || !tree->IsCollisionEnabled()) return;
    const GmIso4 nodeToWorld =
        ComposePlugTreeLocation(*tree, parentToWorld);
    if (tree->m_surface != nullptr &&
        tree->m_surface->m_geometry != nullptr &&
        tree->m_surface->m_geometry->GetGmSurf() != nullptr) {
        leaves.push_back({tree->m_surface, nodeToWorld});
    }
    for (uint32_t index = 0; index < tree->GetChildCount(); ++index) {
        CollectLocatedPlugSurfaces(
            tree->GetChild(index), nodeToWorld, leaves);
    }
}

} // namespace

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

void CHmsCollisionManager::SGroup::AddStaticSurfacesFromTree(
    CHmsCorpus* corpus,
    CPlugTree* tree,
    const GmIso4* parentToWorld,
    void*) {
    if (corpus == nullptr || tree == nullptr || parentToWorld == nullptr ||
        !tree->IsCollisionEnabled()) {
        return;
    }

    GmIso4 nodeToWorld = *parentToWorld;
    if (tree->UsesLocation()) {
        nodeToWorld.SetMult(tree->m_location, *parentToWorld);
    }

    for (uint32_t index = 0; index < tree->GetChildCount(); ++index) {
        AddStaticSurfacesFromTree(
            corpus, tree->GetChild(index), &nodeToWorld, nullptr);
    }

    if (tree->m_surface == nullptr ||
        tree->m_surface->m_geometry == nullptr) {
        return;
    }
    GmSurf* gmSurface = tree->m_surface->m_geometry->GetGmSurf();
    if (gmSurface == nullptr) return;

    GmBoxAligned localBounds;
    localBounds.InitEmpty();
    gmSurface->GetBoundingBox(localBounds);
    if (localBounds.IsNull()) {
        localBounds = tree->m_surface->m_geometry->m_boundingBox;
    }
    if (localBounds.IsNull()) return;

    SStaticCollisionLeaf leaf{};
    leaf.m_worldBounds.SetMult(localBounds, nodeToWorld);
    leaf.m_location = nodeToWorld;
    leaf.m_surface = tree->m_surface;
    leaf.m_corpus = corpus;
    leaf.m_tree = tree;
    m_staticCollisionTreeData.Add(leaf);
}
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
void CHmsCollisionManager::SGroup::UpdateStaticCollisionTrees(
    CHmsCollisionManager*) {
    ClearAllStatic();
    for (uint32_t index = 0; index < m_corpuses.GetCount(); ++index) {
        CHmsCorpus* corpus = m_corpuses[index];
        if (corpus == nullptr || corpus->m_item == nullptr ||
            (corpus->m_item->m_flags1 & 0x00080000u) == 0u) {
            continue;
        }
        if (corpus->m_flags54 != std::numeric_limits<uint32_t>::max()) {
            RemoveNonStaticCorpus(corpus);
        }
        CPlugSolid* solid = corpus->m_item->m_solid;
        if (solid != nullptr && solid->m_tree != nullptr) {
            AddStaticSurfacesFromTree(
                corpus, solid->m_tree, &corpus->m_location, nullptr);
        }
    }
}

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
int CHmsCollisionManager::SZone::ComputeCollisionTree1RootOnly(
    SPlugTreeLocatedPair* pair, GmBoxAligned*) {
    if (pair == nullptr || pair->m_tree1 == nullptr ||
        pair->m_parentToWorld1 == nullptr || pair->m_tree2 == nullptr ||
        pair->m_parentToWorld2 == nullptr ||
        m_activeCollisionBuffer == nullptr ||
        !pair->m_tree1->IsCollisionEnabled() ||
        pair->m_tree1->m_surface == nullptr ||
        pair->m_tree1->m_surface->m_geometry == nullptr ||
        pair->m_tree1->m_surface->m_geometry->GetGmSurf() == nullptr) {
        return 0;
    }

    LocatedPlugSurface firstRoot{
        pair->m_tree1->m_surface,
        ComposePlugTreeLocation(
            *pair->m_tree1, *pair->m_parentToWorld1)};
    std::vector<LocatedPlugSurface> secondLeaves;
    CollectLocatedPlugSurfaces(
        pair->m_tree2, *pair->m_parentToWorld2, secondLeaves);
    bool hit = false;
    for (LocatedPlugSurface& secondLeaf : secondLeaves) {
        if (CPlugSurface::ComputeCollision(
                &firstRoot, &secondLeaf,
                m_activeCollisionBuffer) != 0) {
            hit = true;
        }
    }
    return hit ? 1 : 0;
}

int CHmsCollisionManager::SZone::ComputeCollisionTree2RootOnly(
    SPlugTreeLocatedPair* pair, GmBoxAligned*) {
    if (pair == nullptr || pair->m_tree1 == nullptr ||
        pair->m_parentToWorld1 == nullptr || pair->m_tree2 == nullptr ||
        pair->m_parentToWorld2 == nullptr ||
        m_activeCollisionBuffer == nullptr ||
        !pair->m_tree2->IsCollisionEnabled() ||
        pair->m_tree2->m_surface == nullptr ||
        pair->m_tree2->m_surface->m_geometry == nullptr ||
        pair->m_tree2->m_surface->m_geometry->GetGmSurf() == nullptr) {
        return 0;
    }

    std::vector<LocatedPlugSurface> firstLeaves;
    CollectLocatedPlugSurfaces(
        pair->m_tree1, *pair->m_parentToWorld1, firstLeaves);
    LocatedPlugSurface secondRoot{
        pair->m_tree2->m_surface,
        ComposePlugTreeLocation(
            *pair->m_tree2, *pair->m_parentToWorld2)};
    bool hit = false;
    for (LocatedPlugSurface& firstLeaf : firstLeaves) {
        if (CPlugSurface::ComputeCollision(
                &firstLeaf, &secondRoot,
                m_activeCollisionBuffer) != 0) {
            hit = true;
        }
    }
    return hit ? 1 : 0;
}
int CHmsCollisionManager::SZone::IntersectSegment(
    int groupNumber,
    GmVec3* rayPos,
    GmVec3* rayDir,
    float* outT,
    CPlugTree** outTree) {
    if (groupNumber < 1 || groupNumber > 5 || rayPos == nullptr ||
        rayDir == nullptr || outT == nullptr) {
        return 0;
    }
    *outT = std::numeric_limits<float>::max();
    if (outTree != nullptr) *outTree = nullptr;
    bool hit = false;
    SGroup& group = m_groups[static_cast<uint32_t>(groupNumber - 1)];
    const GmVec3 rayEnd = *rayPos + *rayDir;

    for (uint32_t index = 0;
         index < group.m_staticCollisionTreeData.GetCount(); ++index) {
        SGroup::SStaticCollisionLeaf& leaf =
            group.m_staticCollisionTreeData[index];
        if (leaf.m_surface == nullptr || leaf.m_surface->m_geometry == nullptr ||
            !leaf.m_worldBounds.TestInterSegment(*rayPos, rayEnd)) {
            continue;
        }
        GmSurf* surface = leaf.m_surface->m_geometry->GetGmSurf();
        if (surface == nullptr) continue;
        float candidateT = *outT;
        GmVec3 unusedNormal;
        if (surface->ClipSegment(
                *rayPos, *rayDir, leaf.m_location,
                candidateT, unusedNormal) != 0 && candidateT < *outT) {
            *outT = candidateT;
            hit = true;
            if (outTree != nullptr) *outTree = leaf.m_tree;
        }
    }

    for (uint32_t index = 0;
         index < group.m_nonStaticCorpuses.GetCount(); ++index) {
        CHmsCorpus* corpus = group.m_nonStaticCorpuses[index];
        if (corpus == nullptr || corpus->m_item == nullptr ||
            corpus->m_item->m_solid == nullptr ||
            corpus->m_item->m_solid->m_tree == nullptr) {
            continue;
        }
        float candidateT = *outT;
        CPlugTree* root = corpus->m_item->m_solid->m_tree;
        if (IntersectSegmentTree(
                rayPos, rayDir, root, &corpus->m_location,
                &candidateT) != 0 && candidateT < *outT) {
            *outT = candidateT;
            hit = true;
            if (outTree != nullptr) *outTree = root;
        }
    }
    return hit ? 1 : 0;
}

int CHmsCollisionManager::SZone::IntersectSegment2(
    int groupNumber,
    GmVec3* rayPos,
    GmVec3* rayDir,
    int flags,
    float* outT,
    GmVec3* outNormal) {
    if (groupNumber < 1 || groupNumber > 5 || rayPos == nullptr ||
        rayDir == nullptr || outT == nullptr || outNormal == nullptr) {
        return 0;
    }
    *outT = std::numeric_limits<float>::max();
    bool hit = false;
    SGroup& group = m_groups[static_cast<uint32_t>(groupNumber - 1)];
    const GmVec3 rayEnd = *rayPos + *rayDir;

    for (uint32_t index = 0;
         index < group.m_staticCollisionTreeData.GetCount(); ++index) {
        SGroup::SStaticCollisionLeaf& leaf =
            group.m_staticCollisionTreeData[index];
        if (leaf.m_surface == nullptr || leaf.m_surface->m_geometry == nullptr ||
            !leaf.m_worldBounds.TestInterSegment(*rayPos, rayEnd)) {
            continue;
        }
        GmSurf* surface = leaf.m_surface->m_geometry->GetGmSurf();
        if (surface == nullptr) continue;
        float candidateT = *outT;
        GmVec3 candidateNormal;
        if (surface->ClipSegment2(
                *rayPos, *rayDir, leaf.m_location,
                candidateT, candidateNormal) != 0 && candidateT < *outT) {
            *outT = candidateT;
            *outNormal = candidateNormal;
            hit = true;
        }
    }

    for (uint32_t index = 0;
         index < group.m_nonStaticCorpuses.GetCount(); ++index) {
        CHmsCorpus* corpus = group.m_nonStaticCorpuses[index];
        if (corpus == nullptr || corpus->m_item == nullptr ||
            corpus->m_item->m_solid == nullptr ||
            corpus->m_item->m_solid->m_tree == nullptr) {
            continue;
        }
        float candidateT = *outT;
        GmVec3 candidateNormal;
        if (IntersectSegmentTree2(
                rayPos, rayDir, flags,
                corpus->m_item->m_solid->m_tree,
                &corpus->m_location, &candidateT,
                &candidateNormal) != 0 && candidateT < *outT) {
            *outT = candidateT;
            *outNormal = candidateNormal;
            hit = true;
        }
    }
    return hit ? 1 : 0;
}

int CHmsCollisionManager::SZone::IntersectSegment3(
    int groupNumber,
    GmVec3* rayPos,
    GmVec3* rayDir,
    float* outT,
    uint16_t* outId) {
    if (groupNumber < 1 || groupNumber > 5 || rayPos == nullptr ||
        rayDir == nullptr || outT == nullptr || outId == nullptr) {
        return 0;
    }
    *outT = std::numeric_limits<float>::max();
    bool hit = false;
    SGroup& group = m_groups[static_cast<uint32_t>(groupNumber - 1)];
    const GmVec3 rayEnd = *rayPos + *rayDir;

    for (uint32_t index = 0;
         index < group.m_staticCollisionTreeData.GetCount(); ++index) {
        SGroup::SStaticCollisionLeaf& leaf =
            group.m_staticCollisionTreeData[index];
        if (leaf.m_surface == nullptr || leaf.m_surface->m_geometry == nullptr ||
            !leaf.m_worldBounds.TestInterSegment(*rayPos, rayEnd)) {
            continue;
        }
        GmSurf* surface = leaf.m_surface->m_geometry->GetGmSurf();
        if (surface == nullptr) continue;
        float candidateT = *outT;
        uint16_t candidateId = 0xffffu;
        GmVec3 unusedNormal;
        if (surface->ClipSegment3(
                *rayPos, *rayDir, leaf.m_location,
                candidateT, candidateId) != 0 && candidateT < *outT) {
            if (candidateId < leaf.m_surface->m_materialIds.GetCount()) {
                candidateId = leaf.m_surface->m_materialIds[candidateId];
            }
            *outT = candidateT;
            *outId = candidateId;
            hit = true;
        }
    }

    for (uint32_t index = 0;
         index < group.m_nonStaticCorpuses.GetCount(); ++index) {
        CHmsCorpus* corpus = group.m_nonStaticCorpuses[index];
        if (corpus == nullptr || corpus->m_item == nullptr ||
            corpus->m_item->m_solid == nullptr ||
            corpus->m_item->m_solid->m_tree == nullptr) {
            continue;
        }
        float candidateT = *outT;
        uint16_t candidateId = 0xffffu;
        if (IntersectSegmentTree3(
                rayPos, rayDir,
                corpus->m_item->m_solid->m_tree,
                &corpus->m_location, &candidateT,
                &candidateId) != 0 && candidateT < *outT) {
            *outT = candidateT;
            *outId = candidateId;
            hit = true;
        }
    }
    return hit ? 1 : 0;
}

int CHmsCollisionManager::SZone::IntersectSegmentTree(
    GmVec3* rayPos,
    GmVec3* rayDir,
    CPlugTree* tree,
    GmIso4* parentToWorld,
    float* outT) {
    if (rayPos == nullptr || rayDir == nullptr || tree == nullptr ||
        parentToWorld == nullptr || outT == nullptr ||
        !tree->IsCollisionEnabled()) {
        return 0;
    }

    if (!tree->m_boundingBox.IsNull()) {
        GmBoxAligned worldBounds;
        worldBounds.SetMult(tree->m_boundingBox, *parentToWorld);
        if (!worldBounds.TestInterSegment(*rayPos, *rayPos + *rayDir)) {
            return 0;
        }
    }

    GmIso4 nodeToWorld = *parentToWorld;
    if (tree->UsesLocation()) {
        nodeToWorld.SetMult(tree->m_location, *parentToWorld);
    }
    bool hit = false;
    if (tree->m_surface != nullptr &&
        tree->m_surface->m_geometry != nullptr) {
        GmSurf* surface = tree->m_surface->m_geometry->GetGmSurf();
        if (surface != nullptr) {
            float candidateT = *outT;
            GmVec3 unusedNormal;
            if (surface->ClipSegment(
                    *rayPos, *rayDir, nodeToWorld,
                    candidateT, unusedNormal) != 0 && candidateT < *outT) {
                *outT = candidateT;
                hit = true;
            }
        }
    }
    for (uint32_t index = 0; index < tree->GetChildCount(); ++index) {
        float candidateT = *outT;
        if (IntersectSegmentTree(
                rayPos, rayDir, tree->GetChild(index),
                &nodeToWorld, &candidateT) != 0 && candidateT < *outT) {
            *outT = candidateT;
            hit = true;
        }
    }
    return hit ? 1 : 0;
}

int CHmsCollisionManager::SZone::IntersectSegmentTree2(
    GmVec3* rayPos,
    GmVec3* rayDir,
    int flags,
    CPlugTree* tree,
    GmIso4* parentToWorld,
    float* outT,
    GmVec3* outNormal) {
    if (rayPos == nullptr || rayDir == nullptr || tree == nullptr ||
        parentToWorld == nullptr || outT == nullptr ||
        outNormal == nullptr || !tree->IsCollisionEnabled()) {
        return 0;
    }

    if (!tree->m_boundingBox.IsNull()) {
        GmBoxAligned worldBounds;
        worldBounds.SetMult(tree->m_boundingBox, *parentToWorld);
        if (!worldBounds.TestInterSegment(*rayPos, *rayPos + *rayDir)) {
            return 0;
        }
    }

    GmIso4 nodeToWorld = *parentToWorld;
    if (tree->UsesLocation()) {
        nodeToWorld.SetMult(tree->m_location, *parentToWorld);
    }
    bool hit = false;
    if (tree->m_surface != nullptr &&
        tree->m_surface->m_geometry != nullptr) {
        GmSurf* surface = tree->m_surface->m_geometry->GetGmSurf();
        if (surface != nullptr) {
            float candidateT = *outT;
            GmVec3 candidateNormal;
            if (surface->ClipSegment2(
                    *rayPos, *rayDir, nodeToWorld,
                    candidateT, candidateNormal) != 0 && candidateT < *outT) {
                *outT = candidateT;
                *outNormal = candidateNormal;
                hit = true;
            }
        }
    }
    for (uint32_t index = 0; index < tree->GetChildCount(); ++index) {
        float candidateT = *outT;
        GmVec3 candidateNormal;
        if (IntersectSegmentTree2(
                rayPos, rayDir, flags, tree->GetChild(index),
                &nodeToWorld, &candidateT,
                &candidateNormal) != 0 && candidateT < *outT) {
            *outT = candidateT;
            *outNormal = candidateNormal;
            hit = true;
        }
    }
    return hit ? 1 : 0;
}

int CHmsCollisionManager::SZone::IntersectSegmentTree3(
    GmVec3* rayPos,
    GmVec3* rayDir,
    CPlugTree* tree,
    GmIso4* parentToWorld,
    float* outT,
    uint16_t* outId) {
    if (rayPos == nullptr || rayDir == nullptr || tree == nullptr ||
        parentToWorld == nullptr || outT == nullptr || outId == nullptr ||
        !tree->IsCollisionEnabled()) {
        return 0;
    }

    if (!tree->m_boundingBox.IsNull()) {
        GmBoxAligned worldBounds;
        worldBounds.SetMult(tree->m_boundingBox, *parentToWorld);
        if (!worldBounds.TestInterSegment(*rayPos, *rayPos + *rayDir)) {
            return 0;
        }
    }

    GmIso4 nodeToWorld = *parentToWorld;
    if (tree->UsesLocation()) {
        nodeToWorld.SetMult(tree->m_location, *parentToWorld);
    }
    bool hit = false;
    if (tree->m_surface != nullptr &&
        tree->m_surface->m_geometry != nullptr) {
        GmSurf* surface = tree->m_surface->m_geometry->GetGmSurf();
        if (surface != nullptr) {
            float candidateT = *outT;
            uint16_t candidateId = 0xffffu;
            if (surface->ClipSegment3(
                    *rayPos, *rayDir, nodeToWorld,
                    candidateT, candidateId) != 0 && candidateT < *outT) {
                if (candidateId < tree->m_surface->m_materialIds.GetCount()) {
                    candidateId = tree->m_surface->m_materialIds[candidateId];
                }
                *outT = candidateT;
                *outId = candidateId;
                hit = true;
            }
        }
    }
    for (uint32_t index = 0; index < tree->GetChildCount(); ++index) {
        float candidateT = *outT;
        uint16_t candidateId = 0xffffu;
        if (IntersectSegmentTree3(
                rayPos, rayDir, tree->GetChild(index),
                &nodeToWorld, &candidateT,
                &candidateId) != 0 && candidateT < *outT) {
            *outT = candidateT;
            *outId = candidateId;
            hit = true;
        }
    }
    return hit ? 1 : 0;
}
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

    // Native traversal starts from each item's CPlugSolid root on every
    // query, combining the current corpus transform with node transforms.
    // Refreshing here preserves that behavior while retaining the flattened
    // typed leaf buffer used by the standalone collision dispatcher.
    first->RefreshCollisionSurfacesFromSolid();
    second->RefreshCollisionSurfacesFromSolid();

    for (uint32_t firstSurfaceIndex = 0;
         firstSurfaceIndex < first->m_collisionSurfaces.GetCount();
         ++firstSurfaceIndex) {
        CHmsCorpus::SCollisionSurface& firstSurface =
            first->m_collisionSurfaces[firstSurfaceIndex];
        for (uint32_t secondSurfaceIndex = 0;
             secondSurfaceIndex < second->m_collisionSurfaces.GetCount();
             ++secondSurfaceIndex) {
            CHmsCorpus::SCollisionSurface& secondSurface =
                second->m_collisionSurfaces[secondSurfaceIndex];
            const uint32_t firstNewCollision =
                m_activeCollisionBuffer->GetCount();
            int didCollide = 0;
            if (firstSurface.m_plugSurface != nullptr &&
                secondSurface.m_plugSurface != nullptr) {
                LocatedPlugSurface firstPlug{
                    firstSurface.m_plugSurface,
                    firstSurface.m_gmSurface.m_location};
                LocatedPlugSurface secondPlug{
                    secondSurface.m_plugSurface,
                    secondSurface.m_gmSurface.m_location};
                didCollide = CPlugSurface::ComputeCollision(
                    &firstPlug, &secondPlug, m_activeCollisionBuffer);
            } else {
                didCollide = ComputeCollision(
                    &firstSurface.m_gmSurface,
                    &secondSurface.m_gmSurface,
                    m_activeCollisionBuffer);
            }
            if (didCollide == 0) {
                continue;
            }
            const uint32_t collisionCount =
                m_activeCollisionBuffer->GetCount();
            for (uint32_t collisionIndex = firstNewCollision;
                 collisionIndex < collisionCount;
                 ++collisionIndex) {
                SHmsPhysicalCollision& collision =
                    m_activeCollisionBuffer->GetPhysicalCollision(
                        collisionIndex);
                collision.m_body1 = first;
                collision.m_body2 = second;
                collision.m_value04 = static_cast<uint32_t>(
                    reinterpret_cast<uintptr_t>(firstSurface.m_tree));
                collision.m_value0C = static_cast<uint32_t>(
                    reinterpret_cast<uintptr_t>(secondSurface.m_tree));
                collision.m_ptr48 = m_activeConfig;
            }
        }
    }
}
void CHmsCollisionManager::SZone::
DetectCollisionBetweenTreeAndStaticCollisionTree(
    GmIso4* parentToWorld, CPlugTree* tree) {
    if (parentToWorld == nullptr || tree == nullptr ||
        m_activeCollisionBuffer == nullptr ||
        m_activeStaticGroup == nullptr || m_corpus18c == nullptr ||
        !tree->IsCollisionEnabled()) {
        return;
    }

    // Native 0x53A120 composes this node first, recursively visits its
    // children, then tests this node's own surface against the leaves of the
    // active against-group static tree. Keeping that boundary is important:
    // the tree pointer written into the contact is how StadiumCar identifies
    // each of its four wheel collision ellipsoids.
    const GmIso4 nodeToWorld =
        ComposePlugTreeLocation(*tree, *parentToWorld);
    for (uint32_t childIndex = 0u;
         childIndex < tree->GetChildCount(); ++childIndex) {
        GmIso4 childParent = nodeToWorld;
        DetectCollisionBetweenTreeAndStaticCollisionTree(
            &childParent, tree->GetChild(childIndex));
    }

    if (tree->m_surface == nullptr ||
        tree->m_surface->m_geometry == nullptr) {
        return;
    }
    GmSurf* movingGmSurf =
        tree->m_surface->m_geometry->GetGmSurf();
    if (movingGmSurf == nullptr) return;

    GmBoxAligned movingLocalBounds;
    movingLocalBounds.InitEmpty();
    movingGmSurf->GetBoundingBox(movingLocalBounds);
    if (movingLocalBounds.IsNull()) {
        movingLocalBounds =
            tree->m_surface->m_geometry->m_boundingBox;
    }
    GmBoxAligned movingWorldBounds;
    const bool hasMovingBounds = !movingLocalBounds.IsNull();
    if (hasMovingBounds) {
        movingWorldBounds.SetMult(movingLocalBounds, nodeToWorld);
    }

    for (uint32_t staticIndex = 0u;
         staticIndex <
             m_activeStaticGroup->m_staticCollisionTreeData.GetCount();
         ++staticIndex) {
        const SGroup::SStaticCollisionLeaf& staticLeaf =
            m_activeStaticGroup->m_staticCollisionTreeData[staticIndex];
        if (staticLeaf.m_corpus == nullptr ||
            staticLeaf.m_corpus == m_corpus18c ||
            staticLeaf.m_surface == nullptr ||
            staticLeaf.m_surface->m_geometry == nullptr ||
            staticLeaf.m_surface->m_geometry->GetGmSurf() == nullptr ||
            (hasMovingBounds && !BoxesIntersect(
                movingWorldBounds, staticLeaf.m_worldBounds))) {
            continue;
        }

        const uint32_t firstNewCollision =
            m_activeCollisionBuffer->GetCount();
        LocatedPlugSurface movingPlug{tree->m_surface, nodeToWorld};
        LocatedPlugSurface fixedPlug{
            staticLeaf.m_surface, staticLeaf.m_location};
        if (CPlugSurface::ComputeCollision(
                &movingPlug, &fixedPlug,
                m_activeCollisionBuffer) == 0) {
            continue;
        }

        for (uint32_t collisionIndex = firstNewCollision;
             collisionIndex < m_activeCollisionBuffer->GetCount();
             ++collisionIndex) {
            SHmsPhysicalCollision& collision =
                m_activeCollisionBuffer->GetPhysicalCollision(
                    collisionIndex);
            collision.m_body1 = m_corpus18c;
            collision.m_body2 = staticLeaf.m_corpus;
            collision.m_value04 = static_cast<uint32_t>(
                reinterpret_cast<uintptr_t>(tree));
            collision.m_value0C = static_cast<uint32_t>(
                reinterpret_cast<uintptr_t>(staticLeaf.m_tree));
            collision.m_ptr48 = m_activeConfig;
        }
    }
}
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
    corpus->RefreshCollisionSurfacesFromSolid();

    CHmsCollisionBuffer* previousBuffer = m_activeCollisionBuffer;
    m_activeCollisionBuffer = buffer;
    m_corpus18c = corpus;
    for (SGroup::SAgainstGroup& against : group.m_againstGroups) {
        if (corpusIndex >= against.m_lineCount ||
            against.m_against == nullptr) {
            continue;
        }
        m_activeConfig = against.m_config;
        for (uint32_t targetIndex = 0;
             targetIndex < against.m_columnCount;
             ++targetIndex) {
            if (against.Get(corpusIndex, targetIndex) == 0u) continue;
            DetectCollisionBetween(
                corpus,
                against.m_against->m_nonStaticCorpuses[targetIndex]);
        }

        // Fixed corpuses are represented by leaves in the against group's
        // static collision tree. Enter the native recursive moving-tree
        // boundary instead of flattening away CPlugTree identity here.
        if (against.m_against->m_staticCollisionTreeData.GetCount() != 0u &&
            corpus->m_item->m_solid != nullptr &&
            corpus->m_item->m_solid->m_tree != nullptr) {
            GmIso4 corpusToWorld = corpus->m_location;
            if (corpus->m_dyna != nullptr) {
                corpusToWorld.rot =
                    corpus->m_dyna->CurrentState().m_rotationMatrix;
                corpusToWorld.SetTranslation(
                    corpus->m_dyna->CurrentState().m_position);
            }
            m_activeStaticGroup = against.m_against;
            DetectCollisionBetweenTreeAndStaticCollisionTree(
                &corpusToWorld, corpus->m_item->m_solid->m_tree);
            m_activeStaticGroup = nullptr;
        }
    }
    m_corpus18c = nullptr;
    m_activeConfig = nullptr;
    m_activeStaticGroup = nullptr;
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
    RebuildPairTables();
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
