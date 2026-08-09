#include "../../Hms/CHmsCollisionManager.hpp"
#include "../../Hms/CHmsCollisionBuffer.hpp"
#include "../../Hms/CHmsCorpus.hpp"
#include "../../Hms/CHmsDyna.hpp"
#include "../../Hms/CHmsItem.hpp"
#include "../../Hms/CHmsZoneDynamic.hpp"
#include "../../Plug/CPlugPhysicalObject.hpp"
#include "../../Plug/CPlugSolid.hpp"
#include "../../Plug/CPlugSurface.hpp"
#include "../../Plug/CPlugSurfaceGeom.hpp"
#include "../../Plug/CPlugTree.hpp"

#include <cmath>
#include <cstdio>
#include <limits>

class CSceneVehicleCarTuning;
CSceneVehicleCarTuning* g_tuning = nullptr;

namespace {

bool Near(float actual, float expected, float epsilon = 1.0e-6f) {
    return std::fabs(actual - expected) <= epsilon;
}

bool VecNear(
    const GmVec3& actual,
    const GmVec3& expected,
    float epsilon = 1.0e-6f) {
    return Near(actual.x, expected.x, epsilon) &&
           Near(actual.y, expected.y, epsilon) &&
           Near(actual.z, expected.z, epsilon);
}

class CountingPhysicsCallback final : public CHmsItem::CCallback {
public:
    uint32_t calls = 0u;
    float totalDt = 0.0f;

    ECallback GetType() const override { return CB_PHYSICS; }
    void ComputeForces(CHmsItem*, float dt) override {
        ++calls;
        totalDt += dt;
    }
};

class CountingAfterContactsCallback final : public CHmsItem::CCallback {
public:
    uint32_t calls = 0u;
    CHmsItem* lastItem = nullptr;

    ECallback GetType() const override { return CB_AFTER_CONTACTS; }
    void AfterContacts(CHmsItem* item) override {
        ++calls;
        lastItem = item;
    }
};

class RecordingContactCallback final : public CHmsItem::CCallback {
public:
    uint32_t calls = 0u;
    CHmsItem* lastItem = nullptr;
    CHmsPhysicalContact contact{};

    ECallback GetType() const override { return CB_ABSORB_CONTACT; }
    void AbsorbContact(
        CHmsItem* item,
        CHmsPhysicalContact* value) override {
        ++calls;
        lastItem = item;
        if (value != nullptr) contact = *value;
    }
};

class VetoingContactCallback final : public CHmsItem::CCallback {
public:
    uint32_t calls = 0u;
    CHmsItem* lastItem = nullptr;
    CHmsPhysicalContact received{};

    ECallback GetType() const override { return CB_ABSORB_CONTACT; }
    void AbsorbContact(
        CHmsItem* item,
        CHmsPhysicalContact* contact) override {
        ++calls;
        lastItem = item;
        if (contact == nullptr) return;
        received = *contact;
        contact->m_replacement = GmVec3(0.0f, 0.0f, 0.0f);
        contact->m_isActive = 0u;
    }
};

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
        collisionBuffer.m_collisions[0].m_matId2 != 103u ||
        collisionBuffer.m_collisions[0].m_ptr48 !=
            againstSkipped.m_config) {
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

bool TestNativeTreeSurfaceExtraction() {
    CHmsCollisionManager manager;
    CHmsCollisionManager::SZone* zone = manager.AddZone(7u);

    CHmsItem firstItem;
    CHmsItem secondItem;
    firstItem.m_flags1 = 2u << 13u;
    secondItem.m_flags1 = 4u << 13u;

    GmSurfSphere firstSphere;
    GmSurfSphere secondSphere;
    firstSphere.m_radius = 1.0f;
    secondSphere.m_radius = 1.0f;
    // Plug surfaces interpret these as indices into their material buffers.
    firstSphere.m_flags = 0u;
    secondSphere.m_flags = 0u;

    CPlugSurfaceGeom firstGeom;
    CPlugSurfaceGeom secondGeom;
    firstGeom.SetGmSurf(&firstSphere);
    secondGeom.SetGmSurf(&secondSphere);
    CPlugSurface firstSurface;
    CPlugSurface secondSurface;
    firstSurface.m_geometry = &firstGeom;
    secondSurface.m_geometry = &secondGeom;
    firstSurface.m_materialIds.Add(201u);
    secondSurface.m_materialIds.Add(203u);

    CPlugTree firstRoot;
    CPlugTree firstLeaf;
    CPlugTree secondRoot;
    GmIso4 firstRootLocation;
    GmIso4 firstLeafLocation;
    GmIso4 secondRootLocation;
    firstRootLocation.SetIdentity();
    firstLeafLocation.SetIdentity();
    secondRootLocation.SetIdentity();
    firstRootLocation.tX = 1.0f;
    firstLeafLocation.tX = 1.0f;
    secondRootLocation.tX = 11.5f;
    secondRootLocation.tY = 7.0f;
    firstRoot.SetLocation(firstRootLocation);
    firstRoot.SetUseLocation(true);
    firstLeaf.SetLocation(firstLeafLocation);
    firstLeaf.SetUseLocation(true);
    secondRoot.SetLocation(secondRootLocation);
    secondRoot.SetUseLocation(true);
    firstLeaf.SetSurface(&firstSurface);
    secondRoot.SetSurface(&secondSurface);
    firstRoot.SetIsCollidable(true);
    firstLeaf.SetIsCollidable(true);
    secondRoot.SetIsCollidable(true);
    firstRoot.AddChild(&firstLeaf);

    GmIso4 firstLeafToRoot;
    firstLeaf.GetThisToRootTransfo(firstLeafToRoot);
    if (!Near(firstLeafToRoot.tX, 2.0f) ||
        !Near(firstLeafToRoot.tY, 0.0f)) {
        return false;
    }

    CPlugSolid firstSolid;
    CPlugSolid secondSolid;
    firstSolid.SetTree(&firstRoot);
    secondSolid.SetTree(&secondRoot);
    firstItem.m_solid = &firstSolid;
    secondItem.m_solid = &secondSolid;

    CHmsCorpus firstCorpus;
    CHmsCorpus secondCorpus;
    firstCorpus.m_item = &firstItem;
    secondCorpus.m_item = &secondItem;
    GmIso4 firstWorld;
    firstWorld.SetIdentity();
    firstWorld.m00 = 0.0f;
    firstWorld.m01 = -1.0f;
    firstWorld.m10 = 1.0f;
    firstWorld.m11 = 0.0f;
    firstWorld.tX = 10.0f;
    firstWorld.tY = 5.0f;
    firstCorpus.SetLocation(firstWorld);

    zone->AddCorpus(&firstCorpus);
    zone->AddCorpus(&secondCorpus);
    zone->PrepareCollisions();
    GmSurf::StaticInit();

    CHmsCollisionBuffer collisionBuffer;
    zone->DetectCollisionsCorpus(&collisionBuffer, &firstCorpus);
    if (collisionBuffer.GetCount() != 1u ||
        firstCorpus.m_collisionSurfaces.GetCount() != 1u ||
        secondCorpus.m_collisionSurfaces.GetCount() != 1u ||
        !Near(firstCorpus.m_collisionSurfaces[0]
                  .m_gmSurface.m_location.tX, 10.0f) ||
        !Near(firstCorpus.m_collisionSurfaces[0]
                  .m_gmSurface.m_location.tY, 7.0f) ||
        collisionBuffer.m_collisions[0].m_body1 != &firstCorpus ||
        collisionBuffer.m_collisions[0].m_body2 != &secondCorpus ||
        collisionBuffer.m_collisions[0].m_matId1 != 201u ||
        collisionBuffer.m_collisions[0].m_matId2 != 203u) {
        return false;
    }

    CHmsCollisionBuffer rootOnlyBuffer;
    zone->m_activeCollisionBuffer = &rootOnlyBuffer;
    SPlugTreeLocatedPair firstSubtreeAgainstSecondRoot{
        &firstRoot, &firstCorpus.m_location,
        &secondRoot, &secondCorpus.m_location};
    if (zone->ComputeCollisionTree2RootOnly(
            &firstSubtreeAgainstSecondRoot, nullptr) == 0 ||
        rootOnlyBuffer.GetCount() != 1u ||
        rootOnlyBuffer.m_collisions[0].m_matId1 != 201u ||
        rootOnlyBuffer.m_collisions[0].m_matId2 != 203u) {
        zone->m_activeCollisionBuffer = nullptr;
        return false;
    }
    rootOnlyBuffer.m_collisions.m_count = 0u;
    SPlugTreeLocatedPair secondRootAgainstFirstSubtree{
        &secondRoot, &secondCorpus.m_location,
        &firstRoot, &firstCorpus.m_location};
    if (zone->ComputeCollisionTree1RootOnly(
            &secondRootAgainstFirstSubtree, nullptr) == 0 ||
        rootOnlyBuffer.GetCount() != 1u ||
        rootOnlyBuffer.m_collisions[0].m_matId1 != 203u ||
        rootOnlyBuffer.m_collisions[0].m_matId2 != 201u) {
        zone->m_activeCollisionBuffer = nullptr;
        return false;
    }
    zone->m_activeCollisionBuffer = nullptr;

    // Collision traversal must rebuild the leaves from the current corpus
    // transform instead of retaining the first query's flattened locations.
    firstWorld.tX = 20.0f;
    firstCorpus.SetLocation(firstWorld);
    CHmsCollisionBuffer movedBuffer;
    zone->DetectCollisionsCorpus(&movedBuffer, &firstCorpus);
    if (movedBuffer.GetCount() != 0u ||
        !Near(firstCorpus.m_collisionSurfaces[0]
                  .m_gmSurface.m_location.tX, 20.0f)) {
        return false;
    }

    // Native dynamic traversal rejects a disabled node and its subtree.
    firstRoot.m_field_0x9c &= ~CPlugTree::kCollisionEnabled;
    firstWorld.tX = 10.0f;
    firstCorpus.SetLocation(firstWorld);
    CHmsCollisionBuffer disabledBuffer;
    zone->DetectCollisionsCorpus(&disabledBuffer, &firstCorpus);
    return disabledBuffer.GetCount() == 0u &&
           firstCorpus.m_collisionSurfaces.GetCount() == 0u;
}

bool TestStaticTreeSurfaceExtraction() {
    CHmsCollisionManager manager;
    CHmsCollisionManager::SZone* zone = manager.AddZone(9u);

    CHmsItem movingItem;
    CHmsItem fixedItem;
    movingItem.m_flags1 = 2u << 13u;
    fixedItem.m_flags1 = (4u << 13u) | 0x00080000u;

    GmSurfSphere movingSphere;
    GmSurfSphere fixedSphere;
    movingSphere.m_radius = 1.0f;
    fixedSphere.m_radius = 1.0f;
    movingSphere.m_flags = 0u;
    fixedSphere.m_flags = 0u;
    CPlugSurfaceGeom movingGeom;
    CPlugSurfaceGeom fixedGeom;
    movingGeom.SetGmSurf(&movingSphere);
    fixedGeom.SetGmSurf(&fixedSphere);
    CPlugSurface movingSurface;
    CPlugSurface fixedSurface;
    movingSurface.m_geometry = &movingGeom;
    fixedSurface.m_geometry = &fixedGeom;
    movingSurface.m_materialIds.Add(301u);
    fixedSurface.m_materialIds.Add(303u);

    CPlugTree movingRoot;
    CPlugTree fixedRoot;
    movingRoot.SetSurface(&movingSurface);
    fixedRoot.SetSurface(&fixedSurface);
    movingRoot.SetIsCollidable(true);
    fixedRoot.SetIsCollidable(true);
    CPlugSolid movingSolid;
    CPlugSolid fixedSolid;
    movingSolid.SetTree(&movingRoot);
    fixedSolid.SetTree(&fixedRoot);
    movingItem.m_solid = &movingSolid;
    fixedItem.m_solid = &fixedSolid;

    CHmsCorpus movingCorpus;
    CHmsCorpus fixedCorpus;
    movingCorpus.m_item = &movingItem;
    fixedCorpus.m_item = &fixedItem;
    GmIso4 fixedWorld;
    fixedWorld.SetIdentity();
    fixedWorld.tX = 1.5f;
    fixedCorpus.SetLocation(fixedWorld);

    zone->AddCorpus(&movingCorpus);
    zone->AddCorpus(&fixedCorpus);
    manager.UpdateStaticCollisionTrees();
    zone->PrepareCollisions();
    GmSurf::StaticInit();

    CHmsCollisionManager::SGroup& fixedGroup = zone->m_groups[3];
    if (fixedGroup.m_corpuses.GetCount() != 1u ||
        fixedGroup.m_nonStaticCorpuses.GetCount() != 0u ||
        fixedGroup.m_staticCollisionTreeData.GetCount() != 1u ||
        fixedCorpus.m_flags54 != std::numeric_limits<uint32_t>::max()) {
        return false;
    }

    CHmsCollisionBuffer collisionBuffer;
    zone->DetectCollisionsCorpus(&collisionBuffer, &movingCorpus);
    if (collisionBuffer.GetCount() != 1u ||
        collisionBuffer.m_collisions[0].m_body1 != &movingCorpus ||
        collisionBuffer.m_collisions[0].m_body2 != &fixedCorpus ||
        collisionBuffer.m_collisions[0].m_matId1 != 301u ||
        collisionBuffer.m_collisions[0].m_matId2 != 303u) {
        return false;
    }

    fixedWorld.tX = 10.0f;
    fixedCorpus.SetLocation(fixedWorld);
    manager.UpdateStaticCollisionTrees();
    CHmsCollisionBuffer movedBuffer;
    zone->DetectCollisionsCorpus(&movedBuffer, &movingCorpus);
    return movedBuffer.GetCount() == 0u &&
           fixedGroup.m_staticCollisionTreeData.GetCount() == 1u &&
           Near(fixedGroup.m_staticCollisionTreeData[0]
                    .m_location.tX, 10.0f);
}

void MakeTriangleMesh(GmSurfMesh& mesh) {
    mesh.m_vertices.SetCount(3u);
    mesh.m_vertices[0] = GmVec3(0.0f, 0.0f, 0.0f);
    mesh.m_vertices[1] = GmVec3(1.0f, 0.0f, 0.0f);
    mesh.m_vertices[2] = GmVec3(0.0f, 1.0f, 0.0f);
    mesh.m_triangles.SetCount(1u);
    mesh.m_triangles[0].indices[0] = 0u;
    mesh.m_triangles[0].indices[1] = 1u;
    mesh.m_triangles[0].indices[2] = 2u;
    mesh.m_triangles[0].planeNormal = GmVec3(0.0f, 0.0f, 1.0f);
    mesh.m_triangles[0].planeDist = 0.0f;
    mesh.m_triangles[0].materialId = 0u;
}

bool TestSegmentTreeQueries() {
    GmSurfSphere sphereProbe;
    sphereProbe.m_radius = 1.0f;
    sphereProbe.m_flags = 17u;
    GmIso4 sphereLocation;
    sphereLocation.SetIdentity();
    GmVec3 sphereRayPos(0.0f, 0.0f, 2.0f);
    GmVec3 sphereRayDir(0.0f, 0.0f, -4.0f);
    GmVec3 unusedNormal;
    float sphereT = 1.0f;
    uint16_t sphereId = 0u;
    GmSurf& sphereSurface = sphereProbe;
    if (sphereSurface.ClipSegment(
            sphereRayPos, sphereRayDir, sphereLocation,
            sphereT, unusedNormal) == 0 ||
        !Near(sphereT, 0.25f) ||
        sphereSurface.ClipSegment3(
            sphereRayPos, sphereRayDir, sphereLocation,
            sphereT, sphereId) == 0 ||
        sphereId != 17u ||
        sphereSurface.ClipSegment2(
            sphereRayPos, sphereRayDir, sphereLocation,
            sphereT, unusedNormal) != 0) {
        return false;
    }

    CHmsCollisionManager manager;
    CHmsCollisionManager::SZone* zone = manager.AddZone(11u);

    CHmsItem movingItem;
    CHmsItem fixedItem;
    movingItem.m_flags1 = 2u << 13u;
    fixedItem.m_flags1 = (2u << 13u) | 0x00080000u;

    GmSurfMesh movingMesh;
    GmSurfMesh fixedMesh;
    MakeTriangleMesh(movingMesh);
    MakeTriangleMesh(fixedMesh);
    CPlugSurfaceGeom movingGeom;
    CPlugSurfaceGeom fixedGeom;
    movingGeom.SetGmSurf(&movingMesh);
    fixedGeom.SetGmSurf(&fixedMesh);
    CPlugSurface movingSurface;
    CPlugSurface fixedSurface;
    movingSurface.m_geometry = &movingGeom;
    fixedSurface.m_geometry = &fixedGeom;
    movingSurface.m_materialIds.Add(401u);
    fixedSurface.m_materialIds.Add(403u);

    CPlugTree movingRoot;
    CPlugTree movingLeaf;
    CPlugTree fixedRoot;
    movingLeaf.SetSurface(&movingSurface);
    movingRoot.SetIsCollidable(true);
    movingLeaf.SetIsCollidable(true);
    fixedRoot.SetSurface(&fixedSurface);
    fixedRoot.SetIsCollidable(true);
    movingRoot.AddChild(&movingLeaf);
    CPlugSolid movingSolid;
    CPlugSolid fixedSolid;
    movingSolid.SetTree(&movingRoot);
    fixedSolid.SetTree(&fixedRoot);
    movingItem.m_solid = &movingSolid;
    fixedItem.m_solid = &fixedSolid;

    CHmsCorpus movingCorpus;
    CHmsCorpus fixedCorpus;
    movingCorpus.m_item = &movingItem;
    fixedCorpus.m_item = &fixedItem;
    GmIso4 fixedWorld;
    fixedWorld.SetIdentity();
    fixedWorld.tZ = -2.0f;
    fixedCorpus.SetLocation(fixedWorld);
    zone->AddCorpus(&movingCorpus);
    zone->AddCorpus(&fixedCorpus);
    manager.UpdateStaticCollisionTrees();

    GmVec3 rayPos(0.25f, 0.25f, 1.0f);
    GmVec3 rayDir(0.0f, 0.0f, -4.0f);
    float hitT = 0.0f;
    CPlugTree* hitTree = nullptr;
    if (zone->IntersectSegment(
            2, &rayPos, &rayDir, &hitT, &hitTree) == 0 ||
        !Near(hitT, 0.25f) || hitTree != &movingRoot) {
        return false;
    }

    GmVec3 hitNormal;
    if (zone->IntersectSegment2(
            2, &rayPos, &rayDir, 0, &hitT, &hitNormal) == 0 ||
        !Near(hitT, 0.25f) || !Near(hitNormal.x, 0.0f) ||
        !Near(hitNormal.y, 0.0f) || !Near(hitNormal.z, 1.0f)) {
        return false;
    }

    uint16_t materialId = 0u;
    if (zone->IntersectSegment3(
            2, &rayPos, &rayDir, &hitT, &materialId) == 0 ||
        !Near(hitT, 0.25f) || materialId != 401u) {
        return false;
    }

    movingRoot.SetIsCollidable(false);
    hitTree = nullptr;
    if (zone->IntersectSegment(
            2, &rayPos, &rayDir, &hitT, &hitTree) == 0 ||
        !Near(hitT, 0.75f) || hitTree != &fixedRoot) {
        return false;
    }
    if (zone->IntersectSegment3(
            2, &rayPos, &rayDir, &hitT, &materialId) == 0 ||
        !Near(hitT, 0.75f) || materialId != 403u) {
        return false;
    }
    return true;
}

bool TestZoneDynamicDetectionBoundary() {
    CHmsCollisionManager manager;
    CHmsCollisionManager::SZone* collisionZone = manager.AddZone(12u);

    CHmsItem movingItem;
    CHmsItem fixedItem;
    movingItem.m_flags1 = (3u << 13u) | (2u << 11u);
    fixedItem.m_flags1 =
        (3u << 13u) | 0x00080000u;

    GmSurfSphere movingSphere;
    GmSurfSphere fixedSphere;
    movingSphere.m_radius = 1.0f;
    fixedSphere.m_radius = 1.0f;
    movingSphere.m_flags = 0u;
    fixedSphere.m_flags = 0u;
    CPlugSurfaceGeom movingGeometry;
    CPlugSurfaceGeom fixedGeometry;
    movingGeometry.SetGmSurf(&movingSphere);
    fixedGeometry.SetGmSurf(&fixedSphere);
    CPlugSurface movingSurface;
    CPlugSurface fixedSurface;
    movingSurface.m_geometry = &movingGeometry;
    fixedSurface.m_geometry = &fixedGeometry;
    movingSurface.m_materialIds.Add(0u);
    fixedSurface.m_materialIds.Add(0u);

    CPlugTree movingTree;
    CPlugTree fixedTree;
    movingTree.SetSurface(&movingSurface);
    fixedTree.SetSurface(&fixedSurface);
    movingTree.SetIsCollidable(true);
    fixedTree.SetIsCollidable(true);
    CPlugSolid movingSolid;
    CPlugSolid fixedSolid;
    movingSolid.SetTree(&movingTree);
    fixedSolid.SetTree(&fixedTree);
    movingItem.m_solid = &movingSolid;
    fixedItem.m_solid = &fixedSolid;

    CPlugPhysicalObject movingPhysical;
    movingPhysical.m_mass = 1.0f;
    movingPhysical.m_inverseInertia.SetIdentity();
    CHmsCorpus* movingCorpus = new CHmsCorpus();
    movingCorpus->m_item = &movingItem;
    movingCorpus->m_dyna = new CHmsDyna();
    movingCorpus->m_dyna->m_field_0x108 = &movingPhysical;
    movingCorpus->m_dyna->m_dynamicType = 1;
    movingItem.m_corpuses.Add(movingCorpus);

    CHmsCorpus fixedCorpus;
    fixedCorpus.m_item = &fixedItem;
    GmIso4 fixedLocation;
    fixedLocation.SetIdentity();
    fixedLocation.tX = 1.5f;
    fixedCorpus.SetLocation(fixedLocation);

    collisionZone->AddCorpus(movingCorpus);
    collisionZone->AddCorpus(&fixedCorpus);
    manager.UpdateStaticCollisionTrees();
    GmSurf::StaticInit();

    CHmsZoneDynamic dynamicZone;
    dynamicZone.m_ptr168 = collisionZone;
    dynamicZone.m_dynamicCorpuses.Add(movingCorpus);
    dynamicZone.PhysicsStep2();

    return Near(movingCorpus->m_dyna->Position().x, -0.49f, 2.0e-6f) &&
           Near(movingCorpus->m_dyna->Position().y, 0.0f) &&
           Near(movingCorpus->m_dyna->Position().z, 0.0f) &&
           dynamicZone.m_collisions.GetCount() == 0u;
}

bool TestNativeCollisionResponseOrdering() {
    CHmsItem lowerCategoryItem;
    CHmsItem higherCategoryItem;
    lowerCategoryItem.m_flags1 &= ~0x1800u;
    higherCategoryItem.m_flags1 =
        (higherCategoryItem.m_flags1 & ~0x1800u) | (1u << 11u);

    CHmsCorpus lowerCategoryCorpus;
    lowerCategoryCorpus.m_item = &lowerCategoryItem;
    CHmsCorpus* higherCategoryCorpus = new CHmsCorpus();
    higherCategoryCorpus->m_item = &higherCategoryItem;
    higherCategoryCorpus->m_dyna = new CHmsDyna();
    higherCategoryItem.m_corpuses.Add(higherCategoryCorpus);

    SHmsPhysicalCollision lowerPoint{};
    lowerPoint.m_body1 = &lowerCategoryCorpus;
    lowerPoint.m_body2 = higherCategoryCorpus;
    lowerPoint.ContactPoint() = GmVec3(1.0f, 0.0f, 0.0f);
    lowerPoint.ContactNormal() = GmVec3(0.0f, 1.0f, 0.0f);
    lowerPoint.Replacement() = GmVec3(1.0f, 0.0f, 0.0f);

    SHmsPhysicalCollision higherPoint = lowerPoint;
    higherPoint.ContactPoint() = GmVec3(2.0f, 0.0f, 0.0f);
    higherPoint.Replacement() = GmVec3(0.0f, 1.0f, 0.0f);

    CHmsZoneDynamic zone;
    zone.m_collisions.Add(lowerPoint);
    zone.m_collisions.Add(higherPoint);
    zone.ComputeCollisionResponse();

    CHmsDyna& dyna = *higherCategoryCorpus->m_dyna;
    return dyna.m_replacements.GetCount() == 2u &&
           VecNear(dyna.m_replacements[0], higherPoint.Replacement()) &&
           VecNear(dyna.m_replacements[1], lowerPoint.Replacement());
}

bool TestNativeContactCallbackConstruction() {
    CHmsItem body1Item;
    CHmsItem body2Item;
    body1Item.m_flags1 = (2u << 13u) | (2u << 11u);
    body2Item.m_flags1 = (4u << 13u) | (2u << 11u);
    RecordingContactCallback body1Callback;
    RecordingContactCallback body2Callback;
    body1Item.CallbackSet(CB_ABSORB_CONTACT, &body1Callback);
    body2Item.CallbackSet(CB_ABSORB_CONTACT, &body2Callback);

    CPlugPhysicalObject physical;
    physical.m_mass = 1.0f;
    physical.m_inverseInertia.SetIdentity();
    CHmsCorpus body1;
    CHmsCorpus body2;
    body1.m_item = &body1Item;
    body2.m_item = &body2Item;
    body1.m_dyna = new CHmsDyna();
    body1.m_dyna->m_field_0x108 = &physical;
    body1.m_dyna->m_dynamicType = 1;
    body1.m_dyna->CurrentState().m_position =
        GmVec3(10.0f, 20.0f, 30.0f);
    body1.m_dyna->CurrentState().m_linearSpeed =
        GmVec3(3.0f, 4.0f, 5.0f);
    GmMat3& rotation = body1.m_dyna->CurrentState().m_rotationMatrix;
    rotation.m00 = 0.0f;
    rotation.m01 = -1.0f;
    rotation.m02 = 0.0f;
    rotation.m10 = 1.0f;
    rotation.m11 = 0.0f;
    rotation.m12 = 0.0f;
    rotation.m20 = 0.0f;
    rotation.m21 = 0.0f;
    rotation.m22 = 1.0f;
    body2.m_location.SetIdentity();
    body2.m_location.SetTranslation(GmVec3(1.0f, 2.0f, 3.0f));

    uint32_t pairConfig[5] = {2u, 4u, 0u, 1u, 1u};
    SHmsPhysicalCollision collision{};
    collision.m_body1 = &body1;
    collision.m_body2 = &body2;
    collision.m_value04 = 0x12345678u;
    collision.m_value0C = 0x9abcdef0u;
    collision.ContactNormal() = GmVec3(0.0f, 1.0f, 0.0f);
    collision.ContactPoint() = GmVec3(12.0f, 23.0f, 34.0f);
    collision.m_matId1 = 101u;
    collision.m_matId2 = 202u;
    collision.m_ptr48 = pairConfig;

    CHmsZoneDynamic zone;
    zone.m_collisions.Add(collision);
    zone.ComputeCollisionResponse();

    const uint32_t body1Token = CHmsCorpus::PointerToken(&body1);
    const uint32_t body2Token = CHmsCorpus::PointerToken(&body2);
    return body1Callback.calls == 1u &&
           CHmsCorpus::ResolvePointerToken(body1Token) == &body1 &&
           CHmsCorpus::ResolvePointerToken(body2Token) == &body2 &&
           body1Callback.lastItem == &body1Item &&
           body1Callback.contact.m_corpus32 == body1Token &&
           body1Callback.contact.m_collisionData == 0x9abcdef0u &&
           body1Callback.contact.m_materialId == 202u &&
           body1Callback.contact.m_otherCorpus32 == body2Token &&
           body1Callback.contact.m_otherCollisionData == 0x12345678u &&
           body1Callback.contact.m_otherMaterialId == 101u &&
           VecNear(
               body1Callback.contact.m_localNormal,
               GmVec3(1.0f, 0.0f, 0.0f)) &&
           VecNear(
               body1Callback.contact.m_localPoint,
               GmVec3(3.0f, -2.0f, 4.0f)) &&
           VecNear(
               body1Callback.contact.m_relativeSpeed,
               GmVec3(4.0f, -3.0f, 5.0f)) &&
           body1Callback.contact.m_isActive == 0u &&
           body2Callback.calls == 1u &&
           body2Callback.lastItem == &body2Item &&
           body2Callback.contact.m_corpus32 == body2Token &&
           body2Callback.contact.m_collisionData == 0x12345678u &&
           body2Callback.contact.m_materialId == 101u &&
           body2Callback.contact.m_otherCorpus32 == body1Token &&
           body2Callback.contact.m_otherCollisionData == 0x9abcdef0u &&
           body2Callback.contact.m_otherMaterialId == 202u &&
           VecNear(
               body2Callback.contact.m_localNormal,
               GmVec3(0.0f, 1.0f, 0.0f)) &&
           VecNear(
               body2Callback.contact.m_localPoint,
               GmVec3(11.0f, 21.0f, 31.0f)) &&
           VecNear(
               body2Callback.contact.m_relativeSpeed,
               GmVec3(-3.0f, -4.0f, -5.0f)) &&
           body2Callback.contact.m_isActive == 0u;
}

bool TestNativeCollisionSubstepSelection() {
    CHmsCollisionManager manager;
    CHmsCollisionManager::SZone* collisionZone = manager.AddZone(27u);
    CHmsItem item;
    item.m_flags1 = (item.m_flags1 & ~0x1e000u) | (1u << 13u);
    CountingPhysicsCallback callback;
    item.CallbackSet(CB_PHYSICS, &callback);
    CountingAfterContactsCallback afterContacts;
    item.CallbackSet(CB_AFTER_CONTACTS, &afterContacts);

    CPlugPhysicalObject physical;
    physical.m_mass = 1.0f;
    physical.m_linearDamping = 0.0f;
    physical.m_angularDampingX = 0.0f;
    physical.m_maxDistancePerStep = 0.3f;
    physical.m_inverseInertia.SetIdentity();

    CHmsCorpus* corpus = new CHmsCorpus();
    corpus->m_item = &item;
    corpus->m_dyna = new CHmsDyna();
    corpus->m_dyna->m_field_0x108 = &physical;
    corpus->m_dyna->m_dynamicType = 1;
    corpus->m_dyna->CurrentState().m_linearSpeed =
        GmVec3(45.0f, 0.0f, 0.0f);
    corpus->m_dyna->CurrentState().m_angularSpeed =
        GmVec3(0.0f, 30.0f, 0.0f);
    item.m_corpuses.Add(corpus);
    collisionZone->AddCorpus(corpus);

    CHmsZoneDynamic zone;
    zone.m_ptr168 = collisionZone;
    zone.m_dynamicCorpuses.Add(corpus);
    zone.PhysicsStep2(0.01f);

    // floor(0.01 * (45 + 30) / 0.3) + 1 = 3.
    return callback.calls == 3u && Near(callback.totalDt, 0.01f) &&
           afterContacts.calls == 1u && afterContacts.lastItem == &item &&
           Near(corpus->m_dyna->Position().x, 0.45f) &&
           Near(corpus->m_dyna->ValidatedState().m_position.x, 0.0f);
}

bool TestNativePhysicalContactRewriteAndVeto() {
    CHmsItem body1Item;
    CHmsItem body2Item;
    body1Item.m_flags1 = (3u << 13u) | (2u << 11u);
    body2Item.m_flags1 = (3u << 13u) | (2u << 11u);
    VetoingContactCallback body1Callback;
    VetoingContactCallback body2Callback;
    body1Item.CallbackSet(CB_ABSORB_CONTACT, &body1Callback);
    body2Item.CallbackSet(CB_ABSORB_CONTACT, &body2Callback);

    CPlugPhysicalObject body1Physical;
    CPlugPhysicalObject body2Physical;
    body1Physical.m_mass = 1.0f;
    body2Physical.m_mass = 1.0f;
    body1Physical.m_inverseInertia.SetIdentity();
    body2Physical.m_inverseInertia.SetIdentity();
    CHmsCorpus body1;
    CHmsCorpus body2;
    body1.m_item = &body1Item;
    body2.m_item = &body2Item;
    body1.m_dyna = new CHmsDyna();
    body2.m_dyna = new CHmsDyna();
    body1.m_dyna->m_field_0x108 = &body1Physical;
    body2.m_dyna->m_field_0x108 = &body2Physical;
    body1.m_dyna->m_dynamicType = 1;
    body2.m_dyna->m_dynamicType = 1;
    body1.m_dyna->CurrentState().m_linearSpeed =
        GmVec3(2.0f, 0.0f, 0.0f);
    body2.m_dyna->CurrentState().m_linearSpeed =
        GmVec3(-1.0f, 0.0f, 0.0f);

    uint32_t pairConfig[5] = {3u, 3u, 1u, 1u, 1u};
    SHmsPhysicalCollision collision{};
    collision.m_body1 = &body1;
    collision.m_body2 = &body2;
    collision.Replacement() = GmVec3(0.4f, 0.0f, 0.0f);
    collision.ContactNormal() = GmVec3(1.0f, 0.0f, 0.0f);
    collision.ContactPoint() = GmVec3(0.0f, 0.0f, 0.0f);
    collision.m_ptr48 = pairConfig;

    CHmsZoneDynamic zone;
    zone.m_collisions.Add(collision);
    zone.ComputeCollisionResponse();

    return body1Callback.calls == 1u &&
           body1Callback.lastItem == &body1Item &&
           body1Callback.received.m_isActive == 1u &&
           VecNear(
               body1Callback.received.m_relativeSpeed,
               GmVec3(-3.0f, 0.0f, 0.0f)) &&
           body2Callback.calls == 1u &&
           body2Callback.lastItem == &body2Item &&
           body2Callback.received.m_isActive == 1u &&
           VecNear(
               body2Callback.received.m_relativeSpeed,
               GmVec3(3.0f, 0.0f, 0.0f)) &&
           VecNear(
               body1.m_dyna->CurrentState().m_linearSpeed,
               GmVec3(2.0f, 0.0f, 0.0f)) &&
           VecNear(
               body2.m_dyna->CurrentState().m_linearSpeed,
               GmVec3(-1.0f, 0.0f, 0.0f)) &&
           body1.m_dyna->m_replacements.GetCount() == 1u &&
           body2.m_dyna->m_replacements.GetCount() == 1u &&
           VecNear(
               body1.m_dyna->m_replacements[0],
               GmVec3(0.0f, 0.0f, 0.0f)) &&
           VecNear(
               body2.m_dyna->m_replacements[0],
               GmVec3(0.0f, 0.0f, 0.0f));
}

} // namespace

int main() {
    if (!TestManagerZonesAndGroupPreparation()) {
        std::fputs(
            "collision manager regression: manager preparation FAIL\n",
            stderr);
        return 1;
    }
    if (!TestNativeTreeSurfaceExtraction()) {
        std::fputs(
            "collision manager regression: tree extraction FAIL\n",
            stderr);
        return 1;
    }
    if (!TestStaticTreeSurfaceExtraction()) {
        std::fputs(
            "collision manager regression: static tree extraction FAIL\n",
            stderr);
        return 1;
    }
    if (!TestSegmentTreeQueries()) {
        std::fputs(
            "collision manager regression: segment tree queries FAIL\n",
            stderr);
        return 1;
    }
    if (!TestZoneDynamicDetectionBoundary()) {
        std::fputs(
            "collision manager regression: zone dynamic detection FAIL\n",
            stderr);
        return 1;
    }
    if (!TestNativeCollisionResponseOrdering()) {
        std::fputs(
            "collision manager regression: response ordering FAIL\n",
            stderr);
        return 1;
    }
    if (!TestNativeContactCallbackConstruction()) {
        std::fputs(
            "collision manager regression: contact callback construction FAIL\n",
            stderr);
        return 1;
    }
    if (!TestNativePhysicalContactRewriteAndVeto()) {
        std::fputs(
            "collision manager regression: physical contact rewrite FAIL\n",
            stderr);
        return 1;
    }
    if (!TestNativeCollisionSubstepSelection()) {
        std::fputs(
            "collision manager regression: collision substeps FAIL\n",
            stderr);
        return 1;
    }
    std::puts("collision manager regression: PASS");
    return 0;
}
