#include "CPlugSurfaceMaterialData.hpp"
#include "CHmsCorpus.hpp"
#include "CHmsDyna.hpp"
#include "CHmsItem.hpp"
#include "CHmsZoneDynamic.hpp"
#include "CPlugPhysicalObject.hpp"

#include <cmath>
#include <cstdio>

class CSceneVehicleCarTuning;
CSceneVehicleCarTuning* g_tuning = nullptr;

namespace {

bool ExpectNear(const char* name, float actual, float expected) {
    if (std::fabs(actual - expected) <= 1.0e-6f) return true;
    std::fprintf(stderr, "%s: expected %.9g, got %.9g\n", name, expected, actual);
    return false;
}

bool ExpectMaterial(uint16_t id, float friction, float restitution) {
    const CPlugSurfaceMaterialData& material =
        CPlugSurfaceMaterialData::GetDefault(id);
    bool passed = true;
    passed &= ExpectNear("friction", material.m_friction, friction);
    passed &= ExpectNear("restitution", material.m_restitution, restitution);
    return passed;
}

bool ExpectVector(const char* name, const GmVec3& actual, const GmVec3& expected) {
    if (std::fabs(actual.x - expected.x) <= 1.0e-5f &&
        std::fabs(actual.y - expected.y) <= 1.0e-5f &&
        std::fabs(actual.z - expected.z) <= 1.0e-5f) return true;
    std::fprintf(stderr,
                 "%s: expected {%.9g, %.9g, %.9g}, got {%.9g, %.9g, %.9g}\n",
                 name, expected.x, expected.y, expected.z,
                 actual.x, actual.y, actual.z);
    return false;
}

bool TestStaticMaterialResponse(
    uint16_t movingMaterial,
    uint16_t fixedMaterial,
    GmVec3 expectedSpeed) {
    CHmsItem movingItem;
    CHmsItem fixedItem;
    CPlugPhysicalObject movingPhysical;
    movingItem.m_flags1 = 1u << 11u;
    fixedItem.m_flags1 = 0u;

    CHmsCorpus movingCorpus;
    CHmsCorpus fixedCorpus;
    movingCorpus.m_item = &movingItem;
    fixedCorpus.m_item = &fixedItem;
    movingCorpus.m_dyna = new CHmsDyna();
    movingPhysical.m_mass = 1.0f;
    movingCorpus.m_dyna->m_field_0x108 = &movingPhysical;
    movingCorpus.m_dyna->Position() = GmVec3{0.0f, 0.0f, 0.0f};
    GmVec3 speed{4.0f, -10.0f, 0.0f};
    movingCorpus.m_dyna->SetLocalLinearSpeed(&speed);

    SHmsPhysicalCollision collision{};
    collision.m_body1 = &movingCorpus;
    collision.m_body2 = &fixedCorpus;
    collision.Replacement() = GmVec3{0.0f, -0.2f, 0.0f};
    collision.ContactNormal() = GmVec3{0.0f, 1.0f, 0.0f};
    collision.ContactPoint() = GmVec3{0.0f, 0.0f, 0.0f};
    collision.m_matId1 = movingMaterial;
    collision.m_matId2 = fixedMaterial;

    CHmsZoneDynamic zone;
    zone.SolveImpulse(
        &collision,
        static_cast<CHmsPhysicalContact*>(nullptr),
        static_cast<CHmsPhysicalContact*>(nullptr));
    movingCorpus.m_dyna->DoPostCollisionDynamic();

    GmVec3 actualSpeed;
    movingCorpus.m_dyna->GetLocalLinearSpeed(&actualSpeed);
    bool passed = ExpectVector("static material response", actualSpeed, expectedSpeed);
    passed &= ExpectNear("replacement separation",
                         movingCorpus.m_dyna->Position().y, 0.19f);
    passed &= ExpectVector("collision normal negated for body one",
                           collision.ContactNormal(), GmVec3{0.0f, -1.0f, 0.0f});
    return passed;
}

bool TestCallbackOnlyResponseGate() {
    CHmsItem movingItem;
    CHmsItem fixedItem;
    CPlugPhysicalObject movingPhysical;
    movingItem.m_flags1 = 1u << 11u;

    CHmsCorpus movingCorpus;
    CHmsCorpus fixedCorpus;
    movingCorpus.m_item = &movingItem;
    fixedCorpus.m_item = &fixedItem;
    movingCorpus.m_dyna = new CHmsDyna();
    movingPhysical.m_mass = 1.0f;
    movingCorpus.m_dyna->m_field_0x108 = &movingPhysical;
    GmVec3 initialSpeed{0.0f, -10.0f, 0.0f};
    movingCorpus.m_dyna->SetLocalLinearSpeed(&initialSpeed);

    uint32_t pairConfig[5] = {0u, 0u, 0u, 0u, 0u};
    SHmsPhysicalCollision collision{};
    collision.m_body1 = &movingCorpus;
    collision.m_body2 = &fixedCorpus;
    collision.ContactNormal() = GmVec3{0.0f, 1.0f, 0.0f};
    collision.m_matId1 = 0u;
    collision.m_matId2 = 0u;
    collision.m_ptr48 = pairConfig;

    CHmsZoneDynamic zone;
    zone.m_collisions.Add(collision);
    zone.ComputeCollisionResponse();

    GmVec3 actualSpeed;
    movingCorpus.m_dyna->GetLocalLinearSpeed(&actualSpeed);
    bool passed = ExpectVector(
        "config zero selects callback-only response",
        actualSpeed, initialSpeed);
    passed &= zone.m_collisions.GetCount() == 0u;
    if (zone.m_collisions.GetCount() != 0u) {
        std::fprintf(stderr, "collision response buffer was not cleared\n");
    }
    return passed;
}

bool TestReplacementSynthesis() {
    CHmsDyna dyna;
    dyna.Position() = GmVec3{0.0f, 0.0f, 0.0f};
    GmVec3 first{0.2f, 0.0f, 0.0f};
    GmVec3 sameDirection{0.1f, 0.0f, 0.0f};
    dyna.AddReplacement(&first);
    dyna.AddReplacement(&sameDirection);
    dyna.DoPostCollisionDynamic();
    bool passed = ExpectVector(
        "same-direction replacements do not stack",
        dyna.Position(), GmVec3{0.19f, 0.0f, 0.0f});

    dyna.DoPreCollisionDynamic(0.0f);
    dyna.Position() = GmVec3{0.0f, 0.0f, 0.0f};
    dyna.AddReplacement(&first);
    dyna.DoPreCollisionDynamic(0.0f);
    dyna.DoPostCollisionDynamic();
    passed &= ExpectVector(
        "pre-collision step clears queued replacements",
        dyna.Position(), GmVec3{0.0f, 0.0f, 0.0f});
    return passed;
}

bool TestEqualCategoryReplacementShares() {
    CPlugPhysicalObject firstPhysical;
    CPlugPhysicalObject secondPhysical;
    firstPhysical.m_mass = 1.0f;
    secondPhysical.m_mass = 3.0f;

    CHmsItem firstItem;
    CHmsItem secondItem;
    CHmsCorpus firstCorpus;
    CHmsCorpus secondCorpus;
    firstCorpus.m_item = &firstItem;
    secondCorpus.m_item = &secondItem;
    firstCorpus.m_dyna = new CHmsDyna();
    secondCorpus.m_dyna = new CHmsDyna();
    firstCorpus.m_dyna->m_field_0x108 = &firstPhysical;
    secondCorpus.m_dyna->m_field_0x108 = &secondPhysical;

    SHmsPhysicalCollision collision{};
    collision.m_body1 = &firstCorpus;
    collision.m_body2 = &secondCorpus;
    collision.Replacement() = GmVec3{0.4f, 0.0f, 0.0f};
    collision.ContactNormal() = GmVec3{0.0f, 1.0f, 0.0f};
    collision.ContactPoint() = GmVec3{0.0f, 0.0f, 0.0f};

    CHmsZoneDynamic zone;
    zone.SolveImpulse(
        &collision,
        static_cast<CHmsPhysicalContact*>(nullptr),
        static_cast<CHmsPhysicalContact*>(nullptr));
    firstCorpus.m_dyna->DoPostCollisionDynamic();
    secondCorpus.m_dyna->DoPostCollisionDynamic();
    bool passed = ExpectVector(
        "first equal-category body receives negative other-mass share",
        firstCorpus.m_dyna->Position(), GmVec3{-0.29f, 0.0f, 0.0f});
    passed &= ExpectVector(
        "second equal-category body receives positive first-mass share",
        secondCorpus.m_dyna->Position(), GmVec3{0.09f, 0.0f, 0.0f});
    return passed;
}

} // namespace

int main() {
    bool passed = true;
    CPlugPhysicalObject physicalObject;
    passed &= ExpectNear("physical default mass", physicalObject.m_mass, 1.0f);
    passed &= ExpectNear(
        "physical default sphere inverse inertia",
        physicalObject.m_inverseInertia.m00,
        static_cast<float>(3.0 / 12.566370964050293));
    passed &= ExpectNear(
        "physical default linear damping", physicalObject.m_linearDamping, 0.1f);
    passed &= ExpectNear(
        "physical default angular damping X", physicalObject.m_angularDampingX, 0.3f);
    passed &= ExpectNear(
        "physical default collision substep distance",
        physicalObject.m_maxDistancePerStep, 0.3f);
    passed &= ExpectNear(
        "physical default inertia scale", physicalObject.m_inertiaScale, 1.0f);
    physicalObject.SetInertiaMatrixBox(2.0f, GmVec3{1.0f, 2.0f, 3.0f});
    passed &= ExpectNear(
        "box inverse inertia X", physicalObject.m_inverseInertia.m00, 6.0f / 52.0f);
    passed &= ExpectNear(
        "box inverse inertia Y", physicalObject.m_inverseInertia.m11, 6.0f / 40.0f);
    passed &= ExpectNear(
        "box inverse inertia Z", physicalObject.m_inverseInertia.m22, 6.0f / 20.0f);
    passed &= ExpectNear(
        "box inertia builder preserves stored mass", physicalObject.m_mass, 1.0f);

    passed &= ExpectMaterial(0, 1.0f, 0.5f);
    passed &= ExpectMaterial(3, 0.0f, 0.0f);
    passed &= ExpectMaterial(9, -0.5f, -0.5f);
    passed &= ExpectMaterial(10, -0.5f, -0.5f);
    passed &= ExpectMaterial(11, -0.5f, -0.5f);
    passed &= ExpectMaterial(23, 0.95f, 0.95f);
    passed &= ExpectMaterial(24, 0.8f, 0.8f);
    passed &= ExpectMaterial(25, 0.8f, 0.8f);
    passed &= ExpectMaterial(30, 1.0f, 0.5f);
    passed &= ExpectMaterial(31, 1.0f, 0.5f);

    const CPlugSurfaceMaterialData positiveA{0.0f, 0.5f};
    const CPlugSurfaceMaterialData positiveB{0.0f, 0.8f};
    const CPlugSurfaceMaterialData zero{0.0f, 0.0f};
    const CPlugSurfaceMaterialData negative{0.0f, -0.5f};
    passed &= ExpectNear("positive restitution product",
                         positiveA.GetRestitutionCoefWith(&positiveB), 0.4f);
    passed &= ExpectNear("zero restitution wins",
                         positiveA.GetRestitutionCoefWith(&zero), 0.0f);
    passed &= ExpectNear("negative restitution wins",
                         positiveA.GetRestitutionCoefWith(&negative), -0.5f);
    passed &= ExpectNear("two non-positive restitutions add",
                         negative.GetRestitutionCoefWith(&negative), -1.0f);
    passed &= TestStaticMaterialResponse(
        0u, 3u, GmVec3{4.0f, 0.0f, 0.0f});
    passed &= TestStaticMaterialResponse(
        0u, 0u,
        GmVec3{
            4.0f - 1.25f * 16.0f / std::sqrt(116.0f),
            2.5f,
            0.0f});
    passed &= TestStaticMaterialResponse(
        9u, 16u,
        GmVec3{
            4.0f + 0.5f * 8.0f / std::sqrt(116.0f),
            -5.0f,
            0.0f});
    passed &= TestCallbackOnlyResponseGate();
    passed &= TestReplacementSynthesis();
    passed &= TestEqualCategoryReplacementShares();

    if (!passed) return 1;
    std::puts("surface material regression: PASS");
    return 0;
}
