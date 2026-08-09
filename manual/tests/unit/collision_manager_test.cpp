#include "../../Hms/CHmsCollisionManager.hpp"
#include "../../Hms/CHmsCollisionBuffer.hpp"
#include "../../Hms/CHmsCorpus.hpp"
#include "../../Hms/CHmsDyna.hpp"
#include "../../Hms/CHmsItem.hpp"

#include <cmath>
#include <cstdio>
#include <limits>

class CSceneVehicleCarTuning;
CSceneVehicleCarTuning* g_tuning = nullptr;

namespace {

bool Near(float actual, float expected, float epsilon = 1.0e-6f) {
    return std::fabs(actual - expected) <= epsilon;
}

bool TestManagerZonesAndGroupPreparation() {
    CHmsCollisionManager manager;
    if (manager.m_field_0x14 != 2u ||
        manager.GetMwClassId() != 0x06019000u ||
        manager.MwIsKindOf(0x06019000u) != 1 ||
        manager.MwIsKindOf(0x01001000u) != 1 ||
        manager.MwIsKindOf(0x06005000u) != 0) {
        return false;
    }

    CHmsCollisionManager::SZone* zone = manager.AddZone(0x1234u);
    if (zone == nullptr || manager.m_zones.GetCount() != 1u ||
        manager.m_zones[0] != zone || zone->m_zoneId != 0x1234u ||
        zone->m_manager != &manager) {
        return false;
    }
    for (uint32_t group = 0; group < 5u; ++group) {
        if (zone->m_groups[group].m_groupId != group) return false;
    }
    if (zone->m_groups[3].m_skipDynamicPairPreparation != 1u) {
        return false;
    }
    const std::size_t expectedAgainstCounts[5] = {2u, 1u, 3u, 2u, 1u};
    for (uint32_t group = 0; group < 5u; ++group) {
        if (zone->m_groups[group].m_againstGroups.size() !=
            expectedAgainstCounts[group]) {
            return false;
        }
    }

    CHmsItem firstItem;
    CHmsItem secondItem;
    CHmsItem skippedItem;
    firstItem.m_flags1 = 2u << 13u;
    secondItem.m_flags1 = 2u << 13u;
    skippedItem.m_flags1 = 4u << 13u;
    CHmsCorpus firstCorpus;
    CHmsCorpus secondCorpus;
    CHmsCorpus skippedCorpus;
    firstCorpus.m_item = &firstItem;
    secondCorpus.m_item = &secondItem;
    skippedCorpus.m_item = &skippedItem;
    firstCorpus.m_dyna = new CHmsDyna();
    secondCorpus.m_dyna = new CHmsDyna();
    skippedCorpus.m_dyna = new CHmsDyna();
    GmVec3 firstSpeed{3.0f, 4.0f, 12.0f};
    GmVec3 secondSpeed{1.0f, 2.0f, 2.0f};
    GmVec3 skippedSpeed{8.0f, 0.0f, 0.0f};
    firstCorpus.m_dyna->SetLocalLinearSpeed(&firstSpeed);
    secondCorpus.m_dyna->SetLocalLinearSpeed(&secondSpeed);
    skippedCorpus.m_dyna->SetLocalLinearSpeed(&skippedSpeed);

    zone->AddCorpus(&firstCorpus);
    zone->AddCorpus(&secondCorpus);
    zone->AddCorpus(&skippedCorpus);
    CHmsCollisionManager::SGroup& group = zone->m_groups[1];
    if (group.m_corpuses.GetCount() != 2u ||
        group.m_nonStaticCorpuses.GetCount() != 2u ||
        group.m_squaredLinearSpeeds.GetCount() != 2u ||
        firstCorpus.m_flags54 != 0u || secondCorpus.m_flags54 != 1u) {
        return false;
    }

    zone->PrepareCollisions();
    if (!Near(group.m_squaredLinearSpeeds[0], 169.0f) ||
        !Near(group.m_squaredLinearSpeeds[1], 9.0f)) {
        return false;
    }
    const CHmsCollisionManager::SGroup::SAgainstGroup& againstSkipped =
        group.m_againstGroups[0];
    if (againstSkipped.m_config[0] != 2u ||
        againstSkipped.m_config[1] != 4u ||
        againstSkipped.m_lineCount != 2u ||
        againstSkipped.m_columnCount != 1u ||
        againstSkipped.m_isToPerformCollision.size() != 2u ||
        againstSkipped.m_isToPerformCollision[0] != 1u ||
        againstSkipped.m_isToPerformCollision[1] != 1u ||
        !Near(zone->m_groups[3].m_squaredLinearSpeeds[0], 0.0f)) {
        return false;
    }

    // Exercise the typed standalone traversal boundary from group selection
    // through surface dispatch into physical-contact metadata.
    GmSurfSphere firstSphere;
    firstSphere.m_radius = 1.0f;
    firstSphere.m_flags = 101u;
    GmSurfSphere skippedSphere;
    skippedSphere.m_radius = 1.0f;
    skippedSphere.m_flags = 103u;
    GmIso4 firstLocation;
    GmIso4 skippedLocation;
    firstLocation.SetIdentity();
    skippedLocation.SetIdentity();
    skippedLocation.tX = 1.5f;
    firstCorpus.AddCollisionSurface(&firstSphere, firstLocation);
    skippedCorpus.AddCollisionSurface(&skippedSphere, skippedLocation);
    GmSurf::StaticInit();
    CHmsCollisionBuffer collisionBuffer;
    zone->DetectCollisionsCorpus(&collisionBuffer, &firstCorpus);
    if (collisionBuffer.GetCount() != 1u ||
        collisionBuffer.m_collisions[0].m_body1 != &firstCorpus ||
        collisionBuffer.m_collisions[0].m_body2 != &skippedCorpus ||
        collisionBuffer.m_collisions[0].m_matId1 != 101u ||
        collisionBuffer.m_collisions[0].m_matId2 != 103u) {
        return false;
    }

    zone->RemoveCorpus(nullptr, &firstCorpus);
    if (group.m_corpuses.GetCount() != 1u ||
        group.m_nonStaticCorpuses.GetCount() != 1u ||
        group.m_nonStaticCorpuses[0] != &secondCorpus ||
        group.m_squaredLinearSpeeds.GetCount() != 1u ||
        firstCorpus.m_flags54 != std::numeric_limits<uint32_t>::max() ||
        secondCorpus.m_flags54 != 0u) {
        return false;
    }
    zone->RemoveCorpus(nullptr, &secondCorpus);
    if (group.m_corpuses.GetCount() != 0u ||
        group.m_nonStaticCorpuses.GetCount() != 0u ||
        group.m_squaredLinearSpeeds.GetCount() != 0u ||
        secondCorpus.m_flags54 != std::numeric_limits<uint32_t>::max()) {
        return false;
    }

    zone->RemoveCorpus(nullptr, &skippedCorpus);
    if (zone->m_groups[3].m_corpuses.GetCount() != 0u ||
        skippedCorpus.m_flags54 != std::numeric_limits<uint32_t>::max()) {
        return false;
    }

    manager.RemoveZone(0x1234u);
    return manager.m_zones.GetCount() == 0u;
}

} // namespace

int main() {
    if (!TestManagerZonesAndGroupPreparation()) {
        std::fputs("collision manager regression: FAIL\n", stderr);
        return 1;
    }
    std::puts("collision manager regression: PASS");
    return 0;
}
