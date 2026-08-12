#include "CHmsZoneDynamic.hpp"
#include "CHmsDyna.hpp"
#include "CHmsCorpus.hpp"
#include "CHmsItem.hpp"
#include "SHmsPhysicalCollision.hpp"
#include "CHmsPhysicalContact.hpp"
#include "CHmsCollisionBuffer.hpp"
#include "CHmsCollisionManager.hpp"
#include "CHmsForceField.hpp"
#include "CPlugSurfaceMaterialData.hpp"
#include "CPlugPhysicalObject.hpp"
#include "CPlugSolid.hpp"
#include "GmCollision.hpp"
#include <algorithm>
#include <cmath>

namespace {

float Length(const GmVec3& vector) {
    return std::sqrt(GmVec3::Dot(vector, vector));
}

GmVec3 TransformVector(const GmMat3& matrix, const GmVec3& vector) {
    return GmVec3{
        matrix.m00 * vector.x + matrix.m01 * vector.y + matrix.m02 * vector.z,
        matrix.m10 * vector.x + matrix.m11 * vector.y + matrix.m12 * vector.z,
        matrix.m20 * vector.x + matrix.m21 * vector.y + matrix.m22 * vector.z,
    };
}

uint32_t GetResponseCategory(const CHmsCorpus* corpus) {
    return corpus != nullptr && corpus->m_item != nullptr
        ? (corpus->m_item->m_flags1 >> 11u) & 3u
        : 0u;
}

const GmMat3& GetCorpusRotation(const CHmsCorpus& corpus) {
    return corpus.CurrentRotation();
}

GmVec3 GetCorpusPosition(const CHmsCorpus& corpus) {
    return corpus.m_dyna != nullptr
        ? corpus.m_dyna->CurrentState().m_position
        : GmVec3{
              corpus.m_location.tX,
              corpus.m_location.tY,
              corpus.m_location.tZ};
}

CHmsPhysicalContact BuildPhysicalContact(
    const SHmsPhysicalCollision& collision,
    CHmsCorpus& corpus,
    uint32_t collisionData,
    uint16_t materialId,
    CHmsCorpus& otherCorpus,
    uint32_t otherCollisionData,
    uint16_t otherMaterialId) {
    CHmsPhysicalContact contact{};
    contact.m_corpus32 = CHmsCorpus::PointerToken(&corpus);
    contact.m_collisionData = collisionData;
    contact.m_materialId = materialId;
    contact.m_otherCorpus32 = CHmsCorpus::PointerToken(&otherCorpus);
    contact.m_otherCollisionData = otherCollisionData;
    contact.m_otherMaterialId = otherMaterialId;

    // Response categories zero and one receive only identity/metadata. The
    // executable fills local geometry for categories two and three.
    if (GetResponseCategory(&corpus) > 1u) {
        contact.m_localNormal = collision.ContactNormal();
        contact.m_localNormal.MultTranspose(GetCorpusRotation(corpus));
        contact.m_localPoint =
            collision.ContactPoint() - GetCorpusPosition(corpus);
        contact.m_localPoint.MultTranspose(GetCorpusRotation(corpus));
    }
    return contact;
}

CHmsItem::CCallback* GetAbsorbContactCallback(CHmsCorpus* corpus) {
    CHmsItem* item = corpus != nullptr ? corpus->m_item : nullptr;
    return item != nullptr && item->m_callbacks != nullptr
        ? item->m_callbacks->m_callbacks[CB_ABSORB_CONTACT]
        : nullptr;
}

bool CollisionComesBefore(
    const SHmsPhysicalCollision& first,
    const SHmsPhysicalCollision& second) {
    // sCompareCollision at 0x547C80 orders these nine floats
    // lexicographically in descending order, then puts field38 == 0 first.
    const float firstValues[] = {
        first.ContactPoint().x,
        first.ContactPoint().y,
        first.ContactPoint().z,
        first.ContactNormal().x,
        first.ContactNormal().y,
        first.ContactNormal().z,
        first.Replacement().x,
        first.Replacement().y,
        first.Replacement().z,
    };
    const float secondValues[] = {
        second.ContactPoint().x,
        second.ContactPoint().y,
        second.ContactPoint().z,
        second.ContactNormal().x,
        second.ContactNormal().y,
        second.ContactNormal().z,
        second.Replacement().x,
        second.Replacement().y,
        second.Replacement().z,
    };
    for (uint32_t i = 0; i < 9u; ++i) {
        if (firstValues[i] > secondValues[i]) return true;
        if (firstValues[i] < secondValues[i]) return false;
    }
    if (first.m_field38 == 0u && second.m_field38 != 0u) return true;
    if (first.m_field38 != 0u && second.m_field38 == 0u) return false;
    return false;
}

uint32_t ComputeCollisionSubstepCount(const CHmsDyna& dyna, float dt) {
    if (dyna.m_field_0x108 == nullptr) return 1u;
    const float maxDistance =
        dyna.m_field_0x108->m_maxDistancePerStep;
    if (!(maxDistance > 0.0f)) return 1000u;
    const GmVec3& linearSpeed = dyna.CurrentState().m_linearSpeed;
    const GmVec3& angularSpeed = dyna.CurrentState().m_angularSpeed;
    const float speedMetric = Length(linearSpeed) + Length(angularSpeed);
    const float rawCount = dt * speedMetric / maxDistance;
    if (!(rawCount >= 0.0f)) return 1u;
    const double floored = std::floor(static_cast<double>(rawCount));
    if (floored >= 999.0) return 1000u;
    return static_cast<uint32_t>(floored) + 1u;
}

struct ReplacementShares {
    GmVec3 body1{0.0f, 0.0f, 0.0f};
    GmVec3 body2{0.0f, 0.0f, 0.0f};
};

ReplacementShares ComputeReplacementShares(
    const SHmsPhysicalCollision& collision) {
    CHmsDyna* first = collision.m_body1 != nullptr
        ? collision.m_body1->m_dyna
        : nullptr;
    CHmsDyna* second = collision.m_body2 != nullptr
        ? collision.m_body2->m_dyna
        : nullptr;
    const uint32_t firstCategory = GetResponseCategory(collision.m_body1);
    const uint32_t secondCategory = GetResponseCategory(collision.m_body2);

    ReplacementShares shares;
    if (secondCategory > firstCategory) {
        shares.body2 = collision.Replacement();
    } else if (secondCategory < firstCategory) {
        shares.body1 = -collision.Replacement();
    } else {
        const float firstMass = first != nullptr ? first->GetMass() : 1.0f;
        const float secondMass = second != nullptr ? second->GetMass() : 1.0f;
        const float totalMass = firstMass + secondMass;
        if (totalMass > 0.0f) {
            shares.body1 =
                collision.Replacement() * (-secondMass / totalMass);
            shares.body2 =
                collision.Replacement() * (firstMass / totalMass);
        }
    }
    return shares;
}

void RewritePhysicalContact(
    CHmsCorpus* corpus,
    CHmsPhysicalContact* contact,
    const GmVec3& corpusSpeed,
    const GmVec3& otherSpeed,
    GmVec3& corpusReplacement) {
    if (contact == nullptr || corpus == nullptr) return;

    // Native SolveImpulse presents each body with the contact record built
    // from that same body's tree/material token. Replacement and relative
    // speed use its local frame; the callback may rewrite or veto them.
    contact->m_isActive = 1u;
    const GmMat3& corpusRotation = GetCorpusRotation(*corpus);
    contact->m_replacement = corpusReplacement;
    contact->m_replacement.MultTranspose(corpusRotation);
    contact->m_relativeSpeed = corpusSpeed - otherSpeed;
    contact->m_relativeSpeed.MultTranspose(corpusRotation);

    CHmsItem::CCallback* callback =
        GetAbsorbContactCallback(corpus);
    if (callback != nullptr) {
        callback->AbsorbContact(corpus->m_item, contact);
    }
    corpusReplacement =
        TransformVector(corpusRotation, contact->m_replacement);
}

void ApplyCollisionImpulse(
    CHmsCorpus* corpus,
    const GmVec3& normal,
    const GmVec3& point,
    float friction,
    float restitution) {
    if (corpus == nullptr || corpus->m_dyna == nullptr) return;
    CHmsDyna& dyna = *corpus->m_dyna;

    GmVec3 pointSpeed;
    dyna.GetSpeed(&point, &pointSpeed);
    const float speedLength = Length(pointSpeed);
    const GmVec3 normalSpeed = normal * GmVec3::Dot(normal, pointSpeed);
    GmVec3 tangentSpeed = pointSpeed - normalSpeed;
    const float tangentLength = Length(tangentSpeed);
    const float maximumTangentCancellation = speedLength * friction;
    if (tangentLength > maximumTangentCancellation && tangentLength > 0.0f) {
        tangentSpeed *= maximumTangentCancellation / tangentLength;
    }

    const GmVec3 cancellation = -(normalSpeed + tangentSpeed);
    const float cancellationLength = Length(cancellation);
    constexpr float kImpulseLengthEpsilon = 1.0e-5f;
    if (cancellationLength < kImpulseLengthEpsilon) return;

    const GmVec3 direction = cancellation / cancellationLength;
    float denominator = 1.0f / dyna.GetMass();
    const bool useAngularResponse = dyna.m_dynamicType == 1 &&
        (corpus->m_item == nullptr ||
         (corpus->m_item->m_flags2 & 0x1000u) == 0u);
    if (useAngularResponse) {
        const GmVec3 lever = point - dyna.GetCenterOfMassWorld();
        const GmVec3 leverCrossDirection = GmVec3::Cross(lever, direction);
        const GmVec3 angularVelocity = TransformVector(
            dyna.CurrentState().m_worldInverseInertia,
            leverCrossDirection);
        denominator += GmVec3::Dot(
            GmVec3::Cross(angularVelocity, lever), direction);
    }
    if (denominator <= 0.0f) return;

    GmVec3 impulse = direction *
        ((1.0f + restitution) * cancellationLength / denominator);
    if (useAngularResponse) {
        dyna.AddImpulseAtPoint(&impulse, &point);
    } else {
        dyna.AddImpulse(nullptr, &impulse);
    }
}

} // namespace

CHmsZoneDynamic::CHmsZoneDynamic()
    : CMwNod(),
      m_ptr134(nullptr),
      m_ptr138(nullptr),
      m_manager158(nullptr),
      m_ptr168(nullptr),
      m_forcesPrepared(false) {
    // Exact constructor writes at 0x54A350..0x54A35F.
    m_field_0x11c = 1.0f;
    m_field_0x120 = 1.0f;
    m_collisions.SetSizeAtLeast(50u);
}
CHmsZoneDynamic::~CHmsZoneDynamic() {}

CMwNod* CHmsZoneDynamic::MwNewCHmsZoneDynamic() { return new CHmsZoneDynamic(); }
uint32_t CHmsZoneDynamic::GetMwClassId() { return 0x06004000; }

void CHmsZoneDynamic::AddForceField(CHmsForceField* field) {
    if (field != nullptr) m_forceFields.Add(field);
}

void CHmsZoneDynamic::RemoveForceField(CHmsForceField* field) {
    m_forceFields.ReplaceByLast(field);
}

void CHmsZoneDynamic::ComputeCorpusForces(CHmsCorpus* corpus, float dt) {
    if (corpus == nullptr || corpus->m_dyna == nullptr) return;
    CHmsDyna& dyna = *corpus->m_dyna;
    CPlugPhysicalObject* physicalObject = dyna.m_field_0x108;
    dyna.ValidateDynamicState();

    CHmsItem* item = corpus->m_item;
    GmVec3 zero(0.0f, 0.0f, 0.0f);
    if (item != nullptr && (item->m_flags1 & 0x100000u) != 0u) {
        dyna.SetForce(nullptr, &zero);
        dyna.SetTorque(nullptr, &zero);
        return;
    }

    GmVec3 force(0.0f, 0.0f, 0.0f);
    const float mass = physicalObject != nullptr
        ? physicalObject->m_mass
        : dyna.GetMass();
    const float forceFieldCoef = physicalObject != nullptr
        ? physicalObject->m_forceFieldCoef
        : 1.0f;
    for (uint32_t i = 0; i < m_forceFields.GetCount(); ++i) {
        CHmsForceField* field = m_forceFields[i];
        GmVec3 value;
        if (field != nullptr && field->GetValue(dyna.Position(), value)) {
            force += value * (mass * forceFieldCoef);
        }
    }

    GmVec3 linearSpeed;
    dyna.GetLinearSpeed(nullptr, &linearSpeed);
    const float linearDamping = physicalObject != nullptr
        ? physicalObject->m_linearDamping
        : 0.0f;
    force += linearSpeed * (-m_field_0x11c * linearDamping);
    dyna.SetForce(nullptr, &force);

    if (dyna.m_dynamicType == 1) {
        GmVec3 angularSpeed;
        dyna.GetAngularSpeed(nullptr, &angularSpeed);
        const float angularDamping = physicalObject != nullptr
            ? physicalObject->m_angularDampingX
            : 0.0f;
        GmVec3 torque = angularSpeed *
            (-m_field_0x120 * angularDamping);
        dyna.SetTorque(nullptr, &torque);
    }

    if (item != nullptr && item->m_callbacks != nullptr) {
        CHmsItem::CCallback* callback =
            item->m_callbacks->m_callbacks[CB_PHYSICS];
        if (callback != nullptr) callback->ComputeForces(item, dt);
    }
}

void CHmsZoneDynamic::PrepareForPhysicsStep(float dt) {
    for (uint32_t i = 0; i < m_dynamicCorpuses.GetCount(); ++i) {
        CHmsCorpus* corpus = m_dynamicCorpuses[i];
        CHmsItem* item = corpus != nullptr ? corpus->m_item : nullptr;
        if (corpus == nullptr || item == nullptr ||
            (item->m_flags1 & 0x1e000u) != 0u) {
            continue;
        }
        ComputeCorpusForces(corpus, dt);
    }
    m_forcesPrepared = true;
}

void CHmsZoneDynamic::PhysicsStep2(float dt) {
    if (!m_forcesPrepared) PrepareForPhysicsStep(dt);

    // Advance every dynamic corpus through the native pre-collision state
    // boundary after callers have accumulated the frame's forces.
    uint32_t count = m_dynamicCorpuses.GetCount();
    for (uint32_t i = 0; i < count; ++i) {
        CHmsCorpus* corpus = m_dynamicCorpuses[i];
        if (corpus != nullptr && corpus->m_dyna != nullptr &&
            corpus->m_item != nullptr &&
            (corpus->m_item->m_flags1 & 0x1e000u) == 0u) {
            corpus->m_dyna->DoPreCollisionDynamic(dt);
        }
    }
    
    // Native +0x140 is the dynamic path outside collision-manager groups.
    // Synthetic callers may still inject a response buffer for these bodies.
    CHmsCollisionManager::SZone* collisionZone =
        static_cast<CHmsCollisionManager::SZone*>(m_ptr168);
    if (collisionZone == nullptr) {
        ComputeCollisionResponse();
        for (uint32_t i = 0; i < count; ++i) {
            CHmsCorpus* corpus = m_dynamicCorpuses[i];
            if (corpus != nullptr && corpus->m_dyna != nullptr) {
                corpus->m_dyna->DoPostCollisionDynamic();
            }
        }
    } else {
        collisionZone->PrepareCollisions();
        CHmsCollisionBuffer collisionBuffer(&m_collisions);
        for (CHmsCollisionManager::SGroup& group : collisionZone->m_groups) {
            // Native PhysicsStep2 skips the group whose +0x40 flag is set.
            if (group.m_skipDynamicPairPreparation != 0u) continue;
            for (uint32_t corpusIndex = 0;
                 corpusIndex < group.m_corpuses.GetCount();
                 ++corpusIndex) {
                CHmsCorpus* corpus = group.m_corpuses[corpusIndex];
                if (corpus == nullptr) continue;
                CHmsDyna* dyna = corpus->m_dyna;
                if (dyna == nullptr) {
                    m_collisions.m_count = 0u;
                    collisionZone->DetectCollisionsCorpus(
                        &collisionBuffer, corpus);
                    ComputeCollisionResponse();
                    continue;
                }
                if (dyna->m_field_0x33c == 0u) continue;

                dyna->CopyStateToTemp();
                const uint32_t substepCount =
                    ComputeCollisionSubstepCount(*dyna, dt);
                const float substepDt =
                    dt / static_cast<float>(substepCount);
                float remainingDt = dt;
                for (uint32_t substep = 0;
                     substep < substepCount;
                     ++substep) {
                    const float currentDt = substep + 1u < substepCount
                        ? substepDt
                        : remainingDt;
                    ComputeCorpusForces(corpus, currentDt);
                    dyna->DoPreCollisionDynamic(currentDt);
                    m_collisions.m_count = 0u;
                    collisionZone->DetectCollisionsCorpus(
                        &collisionBuffer, corpus);
                    ComputeCollisionResponse();
                    dyna->DoPostCollisionDynamic();
                    remainingDt -= currentDt;
                }
                dyna->CopyTempToState();
            }
        }
    }

    // Native PhysicsStep2 invokes callback slot 4 once for every corpus in
    // the zone's dynamic-corpus buffer after all contact processing finishes.
    for (uint32_t i = 0; i < count; ++i) {
        CHmsCorpus* corpus = m_dynamicCorpuses[i];
        CHmsItem* item = corpus != nullptr ? corpus->m_item : nullptr;
        if (item == nullptr || item->m_callbacks == nullptr) continue;
        CHmsItem::CCallback* callback =
            item->m_callbacks->m_callbacks[CB_AFTER_CONTACTS];
        if (callback != nullptr) callback->AfterContacts(item);
    }
    m_forcesPrepared = false;
}

void CHmsZoneDynamic::ComputeCollisionResponse() {
    uint32_t count = m_collisions.GetCount();
    if (count > 1u) {
        std::sort(
            m_collisions.m_data,
            m_collisions.m_data + count,
            CollisionComesBefore);
    }
    for (uint32_t i = 0; i < count; ++i) {
        SHmsPhysicalCollision& col = m_collisions[i];

        // Native collisions always carry a five-word pair configuration. A
        // null config remains the standalone synthetic physical default.
        if (col.m_ptr48 == nullptr) {
            SolveImpulse(
                &col,
                static_cast<CHmsPhysicalContact*>(nullptr),
                static_cast<CHmsPhysicalContact*>(nullptr));
            continue;
        }

        CHmsCorpus* body2 = col.m_body2;
        CHmsCorpus* body1 = col.m_body1;
        const uint32_t body2Group =
            body2 != nullptr && body2->m_item != nullptr
                ? (body2->m_item->m_flags1 >> 13u) & 0xfu
                : 0u;
        const uint32_t body2Side = body2Group != col.m_ptr48[0] ? 1u : 0u;

        CHmsItem::CCallback* body2Callback =
            GetAbsorbContactCallback(body2);
        CHmsItem::CCallback* body1Callback =
            GetAbsorbContactCallback(body1);
        const bool buildBody2Contact =
            col.m_ptr48[3u + body2Side] != 0u &&
            body2Callback != nullptr && body2 != nullptr;
        const bool buildBody1Contact =
            col.m_ptr48[3u + (1u - body2Side)] != 0u &&
            body1Callback != nullptr && body1 != nullptr;

        CHmsPhysicalContact body2Contact{};
        CHmsPhysicalContact body1Contact{};
        CHmsPhysicalContact* body2ContactPtr = nullptr;
        CHmsPhysicalContact* body1ContactPtr = nullptr;
        if (buildBody2Contact) {
            body2Contact = BuildPhysicalContact(
                col, *body2, col.m_value0C, col.m_matId2,
                *body1, col.m_value04, col.m_matId1);
            body2ContactPtr = &body2Contact;
        }
        if (buildBody1Contact) {
            body1Contact = BuildPhysicalContact(
                col, *body1, col.m_value04, col.m_matId1,
                *body2, col.m_value0C, col.m_matId2);
            body1ContactPtr = &body1Contact;
        }

        // The executable tests config[2] at 0x549B00: nonzero dispatches the
        // physical solver; zero computes relative speed and calls slot 2.
        if (col.m_ptr48[2] != 0u) {
            SolveImpulse(&col, body1ContactPtr, body2ContactPtr);
            continue;
        }

        GmVec3 body2Speed{0.0f, 0.0f, 0.0f};
        GmVec3 body1Speed{0.0f, 0.0f, 0.0f};
        if (body2 != nullptr && body2->m_dyna != nullptr) {
            body2->m_dyna->GetSpeed(&col.ContactPoint(), &body2Speed);
        }
        if (body1 != nullptr && body1->m_dyna != nullptr) {
            body1->m_dyna->GetSpeed(&col.ContactPoint(), &body1Speed);
        }
        const GmVec3 body1RelativeSpeed = body1Speed - body2Speed;

        if (body2ContactPtr != nullptr) {
            if (GetResponseCategory(body2) > 1u) {
                body2Contact.m_relativeSpeed = -body1RelativeSpeed;
                body2Contact.m_relativeSpeed.MultTranspose(
                    GetCorpusRotation(*body2));
            }
            body2Callback->AbsorbContact(body2->m_item, body2ContactPtr);
        }
        if (body1ContactPtr != nullptr) {
            if (GetResponseCategory(body1) > 1u) {
                body1Contact.m_relativeSpeed = body1RelativeSpeed;
                body1Contact.m_relativeSpeed.MultTranspose(
                    GetCorpusRotation(*body1));
            }
            body1Callback->AbsorbContact(body1->m_item, body1ContactPtr);
        }
    }
    
    m_collisions.m_count = 0; // Clear for next frame
}

void CHmsZoneDynamic::SolveImpulse(
    SHmsPhysicalCollision* collision,
    CHmsPhysicalContact* body1Contact,
    CHmsPhysicalContact* body2Contact) {
    if (collision == nullptr || collision->m_body1 == nullptr ||
        collision->m_body2 == nullptr) return;

    const CPlugSurfaceMaterialData& firstMaterial =
        CPlugSurfaceMaterialData::GetDefault(collision->m_matId1);
    const CPlugSurfaceMaterialData& secondMaterial =
        CPlugSurfaceMaterialData::GetDefault(collision->m_matId2);
    const float restitution =
        firstMaterial.GetRestitutionCoefWith(&secondMaterial);
    const float friction =
        firstMaterial.m_friction * secondMaterial.m_friction;

    ReplacementShares shares = ComputeReplacementShares(*collision);
    GmVec3 body2Speed{0.0f, 0.0f, 0.0f};
    GmVec3 body1Speed{0.0f, 0.0f, 0.0f};
    if (collision->m_body2->m_dyna != nullptr) {
        collision->m_body2->m_dyna->GetSpeed(
            &collision->ContactPoint(), &body2Speed);
    }
    if (collision->m_body1->m_dyna != nullptr) {
        collision->m_body1->m_dyna->GetSpeed(
            &collision->ContactPoint(), &body1Speed);
    }

    RewritePhysicalContact(
        collision->m_body1,
        body1Contact,
        body1Speed,
        body2Speed,
        shares.body1);
    if (collision->m_body1->m_dyna != nullptr) {
        collision->m_body1->m_dyna->AddReplacement(&shares.body1);
    }

    RewritePhysicalContact(
        collision->m_body2,
        body2Contact,
        body2Speed,
        body1Speed,
        shares.body2);
    if (collision->m_body2->m_dyna != nullptr) {
        collision->m_body2->m_dyna->AddReplacement(&shares.body2);
    }

    // Either receiver may veto the shared impulse while retaining its
    // replacement rewrite. This branch precedes GmCollision::Neg natively.
    if ((body1Contact != nullptr && body1Contact->m_isActive == 0u) ||
        (body2Contact != nullptr && body2Contact->m_isActive == 0u)) {
        return;
    }

    ApplyCollisionImpulse(
        collision->m_body2,
        collision->ContactNormal(),
        collision->ContactPoint(),
        friction,
        restitution);

    // Native SolveImpulse calls GmCollision::Neg between the two bodies. This
    // negates the replacement/normal/feature normal and swaps material IDs.
    reinterpret_cast<GmCollision*>(&collision->m_normal)->Neg();

    ApplyCollisionImpulse(
        collision->m_body1,
        collision->ContactNormal(),
        collision->ContactPoint(),
        friction,
        restitution);
}
