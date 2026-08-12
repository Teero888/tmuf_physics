#include <cstddef>
#include "CSceneVehicleCar.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include "TmForeverPhysicsConstants.hpp"
#include "VehicleGroundSupport.hpp"
#include "CHmsCorpus.hpp"
#include "CHmsDyna.hpp"
#include "CHmsItem.hpp"
#include "CHmsPhysicalContact.hpp"
#include "CHmsZone.hpp"
#include "CPlugPhysicalObject.hpp"
#include "CPlugTree.hpp"
#include "GmMat3.hpp"
#include "GmFunc.hpp"
#include "SDynaMath.hpp"
#include <cmath>
#include <algorithm>
#include <limits>

extern CSceneVehicleCarTuning* g_tuning;

namespace {

GmVec3 TransformVector(const GmMat3& matrix, const GmVec3& vector) {
    return GmVec3{
        matrix.m00 * vector.x + matrix.m01 * vector.y + matrix.m02 * vector.z,
        matrix.m10 * vector.x + matrix.m11 * vector.y + matrix.m12 * vector.z,
        matrix.m20 * vector.x + matrix.m21 * vector.y + matrix.m22 * vector.z,
    };
}

CHmsDyna* GetVehicleDyna(CHmsItem* item) {
    if (item == nullptr) return nullptr;
    if (item->m_corpuses.GetCount() != 0u &&
        item->m_corpuses[0] != nullptr) {
        return item->m_corpuses[0]->m_dyna;
    }
    // The host declaration retains this convenience link outside the native
    // 32-bit item layout. It supports synthetic standalone callers that have
    // not materialized a corpus buffer.
    return item->m_dyna;
}

float SquaredLength(const GmVec3& vector) {
    return GmVec3::Dot(vector, vector);
}

} // namespace

// SDynaPart
CSceneVehicleCar::SDynaPart::~SDynaPart() {}

// SEngine
void CSceneVehicleCar::SEngine::Reset() {
    // Exact writes at TmForeverFixed.exe 0x7BC9A0. The five constructor-owned
    // scalars at +0x00..+0x10 deliberately survive Reset.
    m_field_0x28 = 0;
    m_engineRpm = 0.0f;
    m_currentGear = 1;
    m_clutchRpm = 0.0f;
    m_field_0x14 = 0.0f;
    m_gearShiftTimer = 0.0f;
    m_clutchRatio = 1.0f;
}

// SSimulationWheel::SRealTimeState
void CSceneVehicleCar::SSimulationWheel::SRealTimeState::Integrate(float dt) {
    using namespace TmForeverPhysicsConstants;

    m_rotationAngle = GmFunc::Mod(
        m_rotationAngle + m_angularVelocity * dt,
        0.0f, kWheelRotationAnglePeriod);

    const float directionSquaredLength =
        m_direction.x * m_direction.x +
        m_direction.y * m_direction.y +
        m_direction.z * m_direction.z;
    if (directionSquaredLength > kWheelDirectionSquaredEpsilon) {
        const float inverseLength = 1.0f / std::sqrt(directionSquaredLength);
        m_direction.x *= inverseLength;
        m_direction.y *= inverseLength;
        m_direction.z *= inverseLength;

        const GmVec3 directionOfView(
            0.0f, -m_direction.z, m_direction.y);
        m_orientation.rot.SetUpVandDOV(m_direction, directionOfView);
    }

    if (m_targetSteeringAngle <= m_steeringAngle) {
        m_steeringAngle -= dt;
        if (m_steeringAngle < m_targetSteeringAngle) {
            m_steeringAngle = m_targetSteeringAngle;
        }
    } else {
        m_steeringAngle += dt;
        if (m_steeringAngle > m_targetSteeringAngle) {
            m_steeringAngle = m_targetSteeringAngle;
        }
    }
}

// SSimulationWheel::SState
CSceneVehicleCar::SSimulationWheel::SState::~SState() {}
void CSceneVehicleCar::SSimulationWheel::SState::Reset() {}

// SSimulationWheel
CSceneVehicleCar::SSimulationWheel::SSimulationWheel()
    : m_field_0x00(0),
      m_field_0x04(0),
      m_radius(1.0f),
      m_hasGroundContact(0),
      m_groundMaterial(0),
      m_isSlipping(0),
      m_suspensionForce(0.0f),
      m_absorbContactPoint(0.0f, 0.0f, 0.0f),
      m_groundContactCount(0),
      m_groundContactNormalSum(0.0f, 0.0f, 0.0f),
      m_hasLateralContact(0),
      m_lateralContactPoint(0.0f, 0.0f, 0.0f),
      m_otherCorpusLocalDirection(0.0f, 0.0f, 0.0f),
      m_otherCorpusToken(0u),
      m_localContactPosition(0.0f, 0.0f, 0.0f) {
    m_realTimeState.m_compression = 0.0f;
    m_realTimeState.m_velocity = 0.0f;
    m_realTimeState.m_absorbDelta = 0.0f;
    m_realTimeState.m_orientation.SetIdentity();
    m_realTimeState.m_angularVelocity = 0.0f;
    m_realTimeState.m_direction = GmVec3(0.0f, 0.0f, 0.0f);
    m_realTimeState.m_rotationAngle = 0.0f;
    m_realTimeState.m_steeringAngle = 0.0f;
    m_realTimeState.m_targetSteeringAngle = 0.0f;
}

// SVehicleCarState
CSceneVehicleCar::SVehicleCarState::~SVehicleCarState() {}

// CSceneVehicleCar
CSceneVehicleCar::CSceneVehicleCar()
    : CSceneVehicle(),
      m_freeWheeling(0),
      m_chassisUp(0.0f, 1.0f, 0.0f),
      m_useGroundedWheelSpeedOverride(0),
      m_wheelDriveDisabled(0),
      m_groundedWheelAngularSpeedOverride(0.0f),
      m_engineState(0),
      m_engineClutchBoost(0),
      m_engineTakeoffMode(0),
      m_engineLocalVelocity(0.0f, 0.0f, 0.0f),
      m_engineOutsideTakeoffWindow(0),
      m_engineShiftDirection(0),
      m_hasBodyContact(0),
      m_lastBodyContactTick(std::numeric_limits<uint32_t>::max()),
      m_hasWaterContact(0),
      m_frictionCurrentTick(0),
      m_frictionTickFraction(0.0),
      m_model6LastLateralOverLimitTick(0),
      m_model6LateralOverLimitStartTick(0),
      m_model6LateralOverLimitDuration(0),
      m_model6EngineState1StartTick(0),
      m_model6EngineState3StartTick(0),
      m_hasAnyContact(0),
      m_hasChassisContact(0),
      m_chassisContactMaterial(0),
      m_wheelContactMaterial(0),
      m_frontWheelImpact(0.0f),
      m_rearWheelImpact(0.0f),
      m_chassisImpact(0.0f),
      m_wheelContactCount(0),
      m_chassisContactCount(0),
      m_lastWheelContactCount(0),
      m_lastChassisContactCount(0),
      m_chassisContactPointSum(0.0f, 0.0f, 0.0f),
      m_chassisContactNormalSum(0.0f, 0.0f, 0.0f),
      m_appliedImpulseSum(0.0f, 0.0f, 0.0f),
      m_appliedCentralImpulseSum(0.0f, 0.0f, 0.0f) {
    m_simulationFlags = 0;
    m_smoothedSteer = 0.0f;
    m_field_0x5ec = 0.0f;
    m_field_0x5f0 = 0.0f;
    m_field_0x5f4 = 0.0f;
    m_field_0x5f8 = 0.0f;
    m_field_0x5fc = 0.0f;
    m_field_0x600 = 0;
    // Exact constructor default; UpdateParamsFromTuning later replaces this
    // with twice the longitudinal wheel extent when vehicle geometry exists.
    m_field_0x840 = 1.0f;
    // Exact native constructor state at +0x1DC..+0x1F0.
    m_localBodyBounds.InitEmpty();

    // Exact SEngine constructor defaults before Reset.
    m_engine.m_maxRpm = TmForeverPhysicsConstants::kDefaultEngineMaxRpm;
    m_engine.m_field_0x04 = 1.0f;
    m_engine.m_field_0x08 = 1.0f;
    m_engine.m_field_0x0c = 1.0f;
    m_engine.m_field_0x10 = 0.0f;
    // Native constructor write to car +0x5CC, which is this field, from the
    // 10.0f at .rdata 0x00B36194. It is the forward-speed ceiling below which
    // the reverse selector may engage, so the brake pedal starts pulling the
    // car into reverse once it is rolling forward slower than 36 km/h.
    m_engine.m_field_0x30 =
        TmForeverPhysicsConstants::kDefaultReverseSpeedCeiling;
    m_engine.Reset();
    
    // Initialize 4 wheels for the Stadium car
    for (int i = 0; i < 4; ++i) {
        SSimulationWheel wheel;
        // Stadium's first two wheels are the steerable/front axle.  The
        // original force loops read this flag at wheel +0x04.
        // VehicleInitFromSolid copies U01/U02 from StadiumCar.VehicleStruct.
        // U01 is enabled on all wheels; U02 is enabled on the front pair.
        wheel.m_field_0x00 = 1u;
        wheel.m_isSteerable = i < 2 ? 1u : 0u;
        wheel.m_radius = TmForeverPhysicsConstants::kStadiumWheelRadius;
        wheel.m_hasGroundContact = 0;
        wheel.m_realTimeState.m_angularVelocity = 0.0f;
        wheel.m_realTimeState.m_rotationAngle = 0.0f;
        wheel.m_realTimeState.m_velocity = 0.0f;
        wheel.m_realTimeState.m_compression = 0.0f;
        wheel.m_realTimeState.m_absorbDelta = 0.0f;
        wheel.m_localContactPosition = GmVec3(
            TmForeverPhysicsConstants::kStadiumWheelLocalX[i],
            TmForeverPhysicsConstants::kStadiumWheelLocalY[i],
            TmForeverPhysicsConstants::kStadiumWheelLocalZ[i]);
        m_wheels.Add(wheel);
    }

    // The original constructor value above survives only until the loaded
    // wheel surfaces are scanned. Mirror the resulting Stadium runtime state.
    m_field_0x840 = TmForeverPhysicsConstants::kStadiumWheelbase;
}

CSceneVehicleCar::~CSceneVehicleCar() {}

CMwNod* CSceneVehicleCar::MwNewCSceneVehicleCar() { return new CSceneVehicleCar(); }
uint32_t CSceneVehicleCar::GetMwClassId() { return 0x0601D000; }

void CSceneVehicleCar::UpdateParamsFromTuning() {
    CHmsDyna* dyna = GetVehicleDyna(m_hmsItem);
    if (g_tuning == nullptr || dyna == nullptr ||
        dyna->m_field_0x108 == nullptr || m_wheels.GetCount() == 0u) {
        return;
    }

    // 0x7BFFE0..0x7C0157 builds a center/half-extent box from the wheel
    // attachment positions. The suspension reference height is accumulated
    // separately from (wheel Y - radius), rather than from the box center.
    GmVec3 minimum = m_wheels[0].m_localContactPosition;
    GmVec3 maximum = minimum;
    float lowerHeightSum =
        m_wheels[0].m_localContactPosition.y - m_wheels[0].m_radius;
    for (uint32_t index = 1u; index < m_wheels.GetCount(); ++index) {
        const SSimulationWheel& wheel = m_wheels[index];
        const GmVec3& position = wheel.m_localContactPosition;
        minimum.x = std::min(minimum.x, position.x);
        minimum.y = std::min(minimum.y, position.y);
        minimum.z = std::min(minimum.z, position.z);
        maximum.x = std::max(maximum.x, position.x);
        maximum.y = std::max(maximum.y, position.y);
        maximum.z = std::max(maximum.z, position.z);
        lowerHeightSum += position.y - wheel.m_radius;
    }

    const GmVec3 center = (minimum + maximum) * 0.5f;
    const GmVec3 halfExtents = (maximum - minimum) * 0.5f;
    m_field_0x840 = halfExtents.z + halfExtents.z;

    GmVec3 centerOfMass = center;
    centerOfMass.z +=
        g_tuning->m_centerOfMassAftFactor * halfExtents.z;
    centerOfMass.y =
        lowerHeightSum / static_cast<float>(m_wheels.GetCount()) +
        g_tuning->m_centerOfMassVerticalOffset;

    CPlugPhysicalObject& physical = *dyna->m_field_0x108;
    physical.m_mass = g_tuning->m_mass;
    physical.m_forceFieldCoef = g_tuning->m_gravityCoef;
    physical.m_linearDamping = 0.0f;
    physical.m_angularDampingX = 0.0f;
    physical.m_maxDistancePerStep = g_tuning->m_maxDistancePerStep;
    physical.SetCenterOfMass(centerOfMass);
    physical.SetInertiaMatrixBox(
        g_tuning->m_inertiaMass,
        GmVec3(g_tuning->m_inertiaHalfDiagX,
               g_tuning->m_inertiaHalfDiagY,
               g_tuning->m_inertiaHalfDiagZ));

    // 0x7C02F3..0x7C0307 copies the active Model-6 RPM ceiling into the
    // embedded engine after updating the physical object.
    m_engine.m_maxRpm = g_tuning->m_m6MaxRpm;
}

uint32_t CSceneVehicleCar::GetWheelFromSurfaceTree(
    uint32_t surfaceTreeToken) const {
    for (uint32_t index = 0; index < m_wheels.GetCount(); ++index) {
        const uint32_t wheelTreeToken = static_cast<uint32_t>(
            reinterpret_cast<uintptr_t>(
                m_wheels[index].m_surfaceHandler.m_tree));
        if (wheelTreeToken == surfaceTreeToken) return index;
    }
    return std::numeric_limits<uint32_t>::max();
}

void CSceneVehicleCar::WheelAbsorbContact(
    SSimulationWheel* wheel,
    CHmsPhysicalContact* contact) {
    if (wheel == nullptr || contact == nullptr) return;

    // 0x7C11F5 calls sin(pi/4) as a double and rounds the result to float
    // before the strict comparison. An unordered normal is not ground.
    constexpr double kGroundNormalAngle =
        0.785398185253143310546875;
    const float minimumGroundNormalX =
        static_cast<float>(std::sin(kGroundNormalAngle));
    wheel->m_hasGroundContact =
        std::abs(contact->m_localNormal.x) < minimumGroundNormalX ? 1 : 0;

    if (wheel->m_hasGroundContact == 0) {
        m_hasBodyContact = 1;
        wheel->m_lateralContactPoint = contact->m_localPoint;
        wheel->m_hasLateralContact = 1;
    } else {
        ++wheel->m_groundContactCount;
        wheel->m_groundContactNormalSum += contact->m_localNormal;
        wheel->m_groundMaterial = contact->m_otherMaterialId;
    }

    // Wheel contacts always suppress the generic Hms response before the
    // optional shock-model-2 impulse branch.
    contact->m_isActive = 0u;

    // 0x7C129C..0x7C130B observes the opposite corpus orientation. The
    // executable copies column 2 (its local +Z axis) from the opposite
    // corpus transform, retains the corpus pointer, then multiplies the
    // direction by the vehicle corpus rotation transpose. A packed token is
    // resolved through the live-corpus registry on 64-bit hosts.
    CHmsCorpus* otherCorpus =
        CHmsCorpus::ResolvePointerToken(contact->m_otherCorpus32);
    CHmsCorpus* vehicleCorpus =
        m_hmsItem != nullptr && m_hmsItem->m_corpuses.GetCount() != 0u
            ? m_hmsItem->m_corpuses[0]
            : nullptr;
    if (otherCorpus != nullptr && vehicleCorpus != nullptr) {
        const GmMat3& otherRotation = otherCorpus->CurrentRotation();
        GmVec3 localDirection(
            otherRotation.m02,
            otherRotation.m12,
            otherRotation.m22);
        localDirection.MultTranspose(vehicleCorpus->CurrentRotation());
        wheel->m_otherCorpusLocalDirection = localDirection;
        wheel->m_otherCorpusToken = contact->m_otherCorpus32;
    }

    wheel->m_absorbContactPoint = contact->m_localPoint;

    if (g_tuning == nullptr || g_tuning->m_shockModel != 2) return;

    // 0x7C134D..0x7C144A lets the damper absorb the contact replacement's
    // local +Y component. A non-positive replacement is already considered
    // absorbed; a positive one is limited by compression - AbsorbingValMin.
    int replacementWasLimited = 0;
    const float replacementY = contact->m_replacement.y;
    if (replacementY <= 0.0f) {
        replacementWasLimited = 1;
    } else {
        float absorbedReplacement = replacementY;
        if (g_tuning->m_absorbingValMin >=
            TmForeverPhysicsConstants::kNegativeAbsorbingValueEpsilon) {
            const float availableCompression =
                wheel->m_realTimeState.m_compression -
                g_tuning->m_absorbingValMin;
            if (availableCompression <= absorbedReplacement) {
                absorbedReplacement = availableCompression;
                replacementWasLimited = 1;
            }
        }
        if (absorbedReplacement > wheel->m_realTimeState.m_absorbDelta) {
            wheel->m_realTimeState.m_absorbDelta = absorbedReplacement;
        }
        contact->m_replacement.y -= absorbedReplacement;
    }

    CHmsDyna* dyna = GetVehicleDyna(m_hmsItem);
    if (dyna == nullptr || dyna->m_field_0x108 == nullptr) return;
    const CPlugPhysicalObject& physical = *dyna->m_field_0x108;

    const bool isMetal = contact->m_otherMaterialId == 4u;
    const float restitution = wheel->m_hasGroundContact != 0
        ? -(isMetal ? g_tuning->m_wheelRestCoefMetal
                    : g_tuning->m_wheelRestCoefConcrete)
        : -(isMetal ? g_tuning->m_bodyRestCoefMetal
                    : g_tuning->m_bodyRestCoef);
    const float speedAlongNormal =
        GmVec3::Dot(contact->m_localNormal, contact->m_relativeSpeed);
    if (!(speedAlongNormal < 0.0f)) return;

    const GmVec3* impulseSpeed = &contact->m_relativeSpeed;
    const GmVec3* applicationPoint = &contact->m_localPoint;
    GmVec3 adjustedSpeed;
    GmVec3 surfacePoint;
    if (wheel->m_hasGroundContact != 0) {
        const GmVec3 normalSpeed =
            contact->m_localNormal * speedAlongNormal;
        if (replacementWasLimited == 0 && normalSpeed.y < 0.0f) {
            // When the damper accepted a positive replacement and the normal
            // velocity points down, remove only that world-up component and
            // apply the response at the wheel surface rather than the raw
            // collision point.
            adjustedSpeed = contact->m_relativeSpeed;
            adjustedSpeed.y -= normalSpeed.y;
            if (!(GmVec3::Dot(contact->m_localNormal, adjustedSpeed) < 0.0f)) {
                return;
            }
            surfacePoint = GmVec3(
                wheel->m_surfaceHandler.m_surfaceLocation.tX,
                wheel->m_surfaceHandler.m_surfaceLocation.tY,
                wheel->m_surfaceHandler.m_surfaceLocation.tZ);
            impulseSpeed = &adjustedSpeed;
            applicationPoint = &surfacePoint;
        }
    }

    const GmVec3 lever = *applicationPoint - physical.m_centerOfMass;
    GmVec3 impulse;
    SDynaMath::ComputeImpulse(
        physical.m_mass, &physical.m_inverseInertia, restitution,
        impulseSpeed, &contact->m_localNormal, &lever, &impulse);
    AddVehicleImpulse(&impulse, applicationPoint);
}

void CSceneVehicleCar::AddVehicleImpulse(
    const GmVec3* localImpulse,
    const GmVec3* localPoint) {
    if (localImpulse == nullptr || localPoint == nullptr) return;

    CHmsDyna* dyna = GetVehicleDyna(m_hmsItem);
    if (dyna == nullptr || dyna->m_field_0x108 == nullptr) return;
    CPlugPhysicalObject& physical = *dyna->m_field_0x108;
    CHmsDyna::CHmsStateDyna& state = dyna->CurrentState();

    // 0x7BE3C0 and 0x7BE3D1 rotate the impulse and transform the point from
    // vehicle-local coordinates through the current dynamic state.
    const GmVec3 worldImpulse =
        TransformVector(state.m_rotationMatrix, *localImpulse);
    const GmVec3 worldPoint =
        state.m_position + TransformVector(state.m_rotationMatrix, *localPoint);

    GmVec3 nextLinearSpeed =
        state.m_linearSpeed + worldImpulse / physical.m_mass;
    const float oldLinearSpeedSquared = SquaredLength(state.m_linearSpeed);
    const float nextLinearSpeedSquared = SquaredLength(nextLinearSpeed);
    const float positiveDeltaLimit = g_tuning != nullptr
        ? g_tuning->m_linearSpeedSquaredPositiveDeltaMax
        : 10000.0f;
    if (oldLinearSpeedSquared < nextLinearSpeedSquared &&
        positiveDeltaLimit <
            nextLinearSpeedSquared - oldLinearSpeedSquared) {
        nextLinearSpeed = GmVec3(0.0f, 0.0f, 0.0f);
    }
    state.m_linearSpeed = nextLinearSpeed;

    const GmVec3 worldCenterOfMass =
        state.m_position + TransformVector(
            state.m_rotationMatrix, physical.m_centerOfMass);
    const GmVec3 lever = worldPoint - worldCenterOfMass;
    const GmVec3 angularImpulse = GmVec3::Cross(lever, worldImpulse);
    GmVec3 angularDelta =
        TransformVector(state.m_worldInverseInertia, angularImpulse);
    if (g_tuning != nullptr) {
        angularDelta *= g_tuning->m_angularImpulseScale;
        angularDelta.y *= g_tuning->m_angularSpeedYImpulseScale;
    }
    state.m_angularSpeed += angularDelta;

    const float angularSpeedClamp = g_tuning != nullptr
        ? g_tuning->m_angularSpeedClamp
        : 100.0f;
    const float angularSpeedSquared = SquaredLength(state.m_angularSpeed);
    if (angularSpeedClamp * angularSpeedClamp < angularSpeedSquared) {
        state.m_angularSpeed *=
            angularSpeedClamp / std::sqrt(angularSpeedSquared);
    }

    m_appliedImpulseSum += *localImpulse;
}

void CSceneVehicleCar::AddVehicleCentralImpulse(
    const GmVec3* localImpulse) {
    if (localImpulse == nullptr || m_hmsItem == nullptr) return;
    m_hmsItem->AddImpulse(
        m_hmsItem, const_cast<GmVec3*>(localImpulse));
    m_appliedCentralImpulseSum += *localImpulse;
}

void CSceneVehicleCar::AbsorbContact(CHmsPhysicalContact* contact) {
    if (contact == nullptr) return;

    // Native materials 13 and 23 are ignored completely by the car callback.
    if (contact->m_otherMaterialId == 0x0du ||
        contact->m_otherMaterialId == 0x17u) {
        contact->m_replacement = GmVec3(0.0f, 0.0f, 0.0f);
        contact->m_isActive = 0u;
        return;
    }

    m_hasAnyContact = 1;
    const uint32_t wheelIndex =
        GetWheelFromSurfaceTree(contact->m_collisionData);
    const bool hasWheel = wheelIndex !=
        std::numeric_limits<uint32_t>::max();
    const float impact = std::abs(
        GmVec3::Dot(contact->m_localNormal, contact->m_relativeSpeed));

    constexpr double kWheelImpactNormalY =
        0.20000000298023223876953125;
    if (!hasWheel ||
        !(contact->m_localNormal.y >
          static_cast<float>(kWheelImpactNormalY))) {
        m_chassisImpact += impact;
    } else if (m_wheels[wheelIndex].m_isSteerable != 0u) {
        m_frontWheelImpact += impact;
    } else {
        m_rearWheelImpact += impact;
    }

    if (hasWheel) {
        m_wheelContactMaterial =
            static_cast<uint8_t>(contact->m_otherMaterialId);
        WheelAbsorbContact(&m_wheels[wheelIndex], contact);
        ++m_wheelContactCount;
        return;
    }

    // Steer model 5 discards the tangential replacement component for steep
    // underside/body contacts. The comparison is strict at native -0.75f.
    if (g_tuning != nullptr && g_tuning->m_steerModel == 5 &&
        contact->m_localNormal.y < -0.75f) {
        contact->m_replacement = contact->m_localNormal *
            GmVec3::Dot(contact->m_localNormal, contact->m_replacement);
    }

    m_chassisContactPointSum += contact->m_localPoint;
    m_chassisContactNormalSum += contact->m_localNormal;
    ++m_chassisContactCount;
    m_hasChassisContact = 1;
    m_chassisContactMaterial =
        static_cast<uint8_t>(contact->m_otherMaterialId);

    // Shock model 2 owns the body-contact response and therefore disables the
    // generic solver after optionally applying its friction-limited impulse.
    if (g_tuning != nullptr && g_tuning->m_shockModel == 2) {
        const float speedAlongNormal =
            GmVec3::Dot(contact->m_localNormal, contact->m_relativeSpeed);
        CHmsDyna* dyna = GetVehicleDyna(m_hmsItem);
        if (speedAlongNormal < 0.0f && dyna != nullptr &&
            dyna->m_field_0x108 != nullptr) {
            const bool isMetal = contact->m_otherMaterialId == 4u;
            const float restitution =
                -(isMetal ? g_tuning->m_bodyRestCoefMetal
                          : g_tuning->m_bodyRestCoef);
            const float friction =
                isMetal ? g_tuning->m_bodyFrictionCoefMetal
                        : g_tuning->m_bodyFrictionCoef;

            const GmVec3 normalSpeed =
                contact->m_localNormal * speedAlongNormal;
            GmVec3 tangentSpeed =
                contact->m_relativeSpeed - normalSpeed;
            const float normalMagnitude =
                std::sqrt(SquaredLength(normalSpeed));
            const float tangentMagnitude =
                std::sqrt(SquaredLength(tangentSpeed));
            const float maximumTangentMagnitude =
                normalMagnitude * friction;
            if (maximumTangentMagnitude < tangentMagnitude) {
                tangentSpeed *=
                    maximumTangentMagnitude / tangentMagnitude;
            }

            GmVec3 impulseDirection = -(normalSpeed + tangentSpeed);
            const float directionMagnitude =
                std::sqrt(SquaredLength(impulseDirection));
            if (TmForeverPhysicsConstants::kImpulseDirectionEpsilon <
                directionMagnitude) {
                impulseDirection *= 1.0f / directionMagnitude;
                const CPlugPhysicalObject& physical =
                    *dyna->m_field_0x108;
                const GmVec3 lever =
                    contact->m_localPoint - physical.m_centerOfMass;
                GmVec3 impulse;
                SDynaMath::ComputeImpulse(
                    physical.m_mass, &physical.m_inverseInertia,
                    restitution, &contact->m_relativeSpeed,
                    &impulseDirection, &lever, &impulse);
                AddVehicleImpulse(&impulse, &contact->m_localPoint);
            }
        }
        contact->m_isActive = 0u;
    }
}

void CSceneVehicleCar::AfterContacts() {
    // Native 0x7C0A1C..0x7C0A50 clears the contact observations after first
    // copying them into the render/replay state. The standalone library does
    // not yet expose that presentation snapshot, but must retain the same
    // per-physics-pass lifetime for its live accumulators.
    m_lastWheelContactCount = m_wheelContactCount;
    m_lastChassisContactCount = m_chassisContactCount;
    m_wheelContactCount = 0u;
    m_chassisContactCount = 0u;
    m_chassisContactPointSum = GmVec3(0.0f, 0.0f, 0.0f);
    m_chassisContactNormalSum = GmVec3(0.0f, 0.0f, 0.0f);
}

void* CSceneVehicleCar::_vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2) {
    this->~CSceneVehicleCar();
    if ((param_2 & 1) != 0) {
        delete this;
    }
    return this;
}

void CSceneVehicleCar::Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3) {}

void CSceneVehicleCar::ComputeForces(CCallbackSceneToyBroomStickComputeForces* param_1, CHmsItem* param_2, float dt) {
    IntegrateVehicle(this, dt);

    // CMwTimerAdapter::GetTickTime supplies an integer millisecond clock to
    // the native friction helper. Preserve sub-millisecond frame fractions so
    // fixed and variable standalone steps reach the same duration boundary.
    if (dt > 0.0f) {
        const double elapsedMilliseconds =
            m_frictionTickFraction + static_cast<double>(dt) * 1000.0;
        const uint32_t wholeMilliseconds =
            static_cast<uint32_t>(elapsedMilliseconds);
        m_frictionCurrentTick += wholeMilliseconds;
        m_frictionTickFraction =
            elapsedMilliseconds - static_cast<double>(wholeMilliseconds);
    }

    // 0x7C6AB7..0x7C6B32. Ground contact re-selects two physical-object
    // properties every step, before the force models run. The gravity
    // coefficient at CPlugPhysicalObject +0x34 switches between the tuning's
    // grounded and airborne values, and the linear damping at +0x28 is zero on
    // the ground but becomes the tuning's fluid friction in the air. Neither is
    // a one-time constructor value, which is how the standalone build had been
    // treating them.
    if (g_tuning != nullptr) {
        CHmsDyna* dyna = GetVehicleDyna(m_hmsItem);
        if (dyna != nullptr && dyna->m_field_0x108 != nullptr) {
            const bool grounded = IsGroundContact() != 0;
            CPlugPhysicalObject& physical = *dyna->m_field_0x108;
            physical.m_forceFieldCoef = grounded
                ? g_tuning->m_gravityCoef
                : g_tuning->m_gravityCoefAir;
            physical.m_linearDamping = grounded
                ? 0.0f
                : g_tuning->m_linearFluidFrictionCoef;
        }
    }

    // Native ComputeForces 0x7C6B7A..0x7C6E77 owns friction and force-model
    // dispatch. IntegrateVehicle ends after updating steering state.
    if (m_hmsItem != nullptr && (m_simulationFlags & 2u) != 0u &&
        (m_simulationFlags & 8u) == 0u) {
        GmVec3 localLinearSpeed(0.0f, 0.0f, 0.0f);
        m_hmsItem->GetLinearSpeed(m_hmsItem, &localLinearSpeed);
        GmVec3 localAngularSpeed(0.0f, 0.0f, 0.0f);
        m_hmsItem->GetAngularSpeed(m_hmsItem, &localAngularSpeed);
        // 0x7C6B8A snapshots the force before the 0x7C6BA3 friction call.
        // Model6 later forwards that unchanged stack value to water handling,
        // so continuous water replaces the pre-friction force while retaining
        // the friction contribution added between those two calls.
        GmVec3 accumulatedLocalForce(0.0f, 0.0f, 0.0f);
        m_hmsItem->GetForce(m_hmsItem, &accumulatedLocalForce);
        ApplyFrictionForces(&localLinearSpeed);

        StadiumVehicleMaterials::GroundValues groundMaterial{};
        int hasGroundMaterial = 0;
        ComputeVehicleGroundMaterialVals(
            &groundMaterial, &hasGroundMaterial);
        float lateralSlopeAdherence = 1.0f;
        float axialSlopeAdherence = 1.0f;
        GetSlopeAdherence(
            accumulatedLocalForce,
            &lateralSlopeAdherence,
            &axialSlopeAdherence);

        int hasSlippingWheel = 0;
        float axialBrakeForce = 0.0f;
        const float processedSteer =
            g_tuning != nullptr
                ? g_tuning->GetModel6ProcessedSteer(
                      m_smoothedSteer, localLinearSpeed.z)
                : 0.0f;
        ComputeForcesModel6(
            dt, &accumulatedLocalForce,
            lateralSlopeAdherence, axialSlopeAdherence,
            &localLinearSpeed, &localAngularSpeed,
            processedSteer, hasGroundMaterial, &groundMaterial,
            &hasSlippingWheel, &axialBrakeForce);
    }

    // 0x7C6ECC..0x7C6F9F. The wheel loop that follows the force model builds
    // the flag ComputeAirControl treats as "really on the ground": a wheel
    // with contact whose +0x00 field is also set. That field has no identified
    // producer in the standalone build, so the flag is currently always false
    // and the air-control window is measured from the last reset rather than
    // the last ground contact. The `m_hasAnyContact` case below still ends air
    // control on any contact, which is what keeps this honest for a normal lap.
    if (m_hmsItem != nullptr) {
        int airControlContactFlag = 0;
        for (uint32_t index = 0u; index < m_wheels.GetCount(); ++index) {
            const SSimulationWheel& wheel = m_wheels[index];
            if (wheel.m_hasGroundContact != 0 && wheel.m_field_0x00 != 0) {
                airControlContactFlag = 1;
            }
        }
        GmVec3 localAngularSpeed(0.0f, 0.0f, 0.0f);
        m_hmsItem->GetAngularSpeed(m_hmsItem, &localAngularSpeed);
        ComputeAirControl(&localAngularSpeed, m_frictionCurrentTick,
                          IsGroundContact(), airControlContactFlag);
    }

    // 0x7C786E..0x7C78AD clears the per-pass contact observations after every
    // wheel/force consumer has run. Opposite-corpus +0x130..+0x13C and the
    // lateral point +0x160 deliberately persist, matching WheelReset.
    for (uint32_t index = 0u; index < m_wheels.GetCount(); ++index) {
        SSimulationWheel& wheel = m_wheels[index];
        wheel.m_hasGroundContact = 0;
        wheel.m_groundContactCount = 0u;
        wheel.m_absorbContactPoint = GmVec3(0.0f, 0.0f, 0.0f);
        wheel.m_groundContactNormalSum = GmVec3(0.0f, 0.0f, 0.0f);
        wheel.m_groundMaterial = 0u;
        wheel.m_hasLateralContact = 0;
    }
    m_frontWheelImpact = 0.0f;
    m_rearWheelImpact = 0.0f;
    m_chassisImpact = 0.0f;
    m_hasChassisContact = 0;
    m_hasAnyContact = 0;
    m_hasBodyContact = 0;
}

void CSceneVehicleCar::IntegrateVehicle(CSceneVehicleCar* pilot, float dt) {
    if (m_hmsItem == nullptr) return;

    // The native routine obtains this local-space vector before testing its
    // simulation flags and passes the Z component to each wheel.
    GmVec3 localVehicleSpeed(0.0f, 0.0f, 0.0f);
    m_hmsItem->GetLinearSpeed(m_hmsItem, &localVehicleSpeed);

    m_engineLocalVelocity = localVehicleSpeed;

    // 1. Wheel speed & rotation updates.
    if ((m_simulationFlags & 1) != 0) {
        // 0x7C3940 computes the steer radius once, from the same
        // SteerRadiusMin/SteerRadiusCoef pair the processed-steer producer
        // uses, and every wheel in the loop shares it.
        const float steerRadius = g_tuning != nullptr
            ? std::abs(localVehicleSpeed.z) * g_tuning->m_steerRadiusCoef +
                  g_tuning->m_steerRadiusMin
            : 0.0f;
        uint32_t wheelCount = m_wheels.GetCount();
        for (uint32_t i = 0; i < wheelCount; ++i) {
            SSimulationWheel& wheel = m_wheels[i];

            // 0x7C399A refreshes the wheel's steering frame from the surface
            // handler's base rotation before anything rotates it.
            wheel.m_realTimeState.m_steeringFrame =
                wheel.m_surfaceHandler.m_baseLocation.rot;

            // 0x7C399F..0x7C3A76: only a steerable wheel is rotated and only
            // it receives a visual steering target. The target is a plain
            // scaling of the smoothed input rather than the speed-dependent
            // processed steer the force model uses; SRealTimeState::Integrate
            // then walks m_steeringAngle toward it at one radian per second.
            if (wheel.m_isSteerable != 0u) {
                // 0x7C39A9 guards the divide with the shared +1e-5f epsilon.
                const float frameAngle =
                    steerRadius >=
                            TmForeverPhysicsConstants::kWheelInputEpsilon
                        ? -m_smoothedSteer / steerRadius
                        : 0.0f;
                // The native call rotates in place, reading each source
                // element before it overwrites it. Our RotateY writes through
                // *this, so it needs a distinct source to stay equivalent.
                const GmMat3 baseFrame = wheel.m_realTimeState.m_steeringFrame;
                wheel.m_realTimeState.m_steeringFrame.RotateY(
                    baseFrame, frameAngle);
                wheel.m_realTimeState.m_targetSteeringAngle =
                    -m_smoothedSteer *
                    TmForeverPhysicsConstants::kWheelVisualSteeringAngleMax;
            } else {
                wheel.m_realTimeState.m_targetSteeringAngle = 0.0f;
            }

            WheelUpdateSpeedFromVehicleSpeed(&wheel, localVehicleSpeed.z, dt);
            wheel.m_realTimeState.Integrate(dt);
        }
    }
    
    // 2. Suspension integration.
    if ((m_simulationFlags & 2) != 0) {
        uint32_t wheelCount = m_wheels.GetCount();
        for (uint32_t i = 0; i < wheelCount; ++i) {
            WheelIntegrate(&m_wheels[i], dt);
        }
    }

    // 3. Engine and transmission. The native caller selects brake while the
    // reverse flag is set and suppresses the engine completely in freewheel.
    //
    // m_isReverse never becomes non-zero in this build: its producer, the
    // state machine at 0x7C5A2E..0x7C5B14 in the ordinary Model-6 forward
    // branch, is not translated yet. Reverse is therefore unreachable and this
    // always selects gas. See PARITY_STATUS.md.
    if ((m_simulationFlags & 4) != 0) {
        if (m_freeWheeling != 0) {
            m_engine.m_engineRpm = 0.0f;
        } else {
            EngineIntegrate(
                m_engine.m_isReverse != 0 ? m_inputBrake : m_inputGas, dt);
        }
    }

    // IntegrateVehicle in the fixed executable moves +0x5E8 toward the raw
    // steer input at Tuning::SteerSpeed units per second before force dispatch.
    const float steerSpeed = g_tuning != nullptr ? g_tuning->m_steerSpeed : 0.0f;
    const float steerDelta = m_inputSteer - m_smoothedSteer;
    const float maxSteerStep = steerSpeed * dt;
    if (std::abs(steerDelta) <= maxSteerStep || maxSteerStep <= 0.0f) {
        m_smoothedSteer = m_inputSteer;
    } else {
        m_smoothedSteer += std::copysign(maxSteerStep, steerDelta);
    }

}

void CSceneVehicleCar::WheelUpdateSpeedFromVehicleSpeed(
    SSimulationWheel* wheel, float vehicleWheelSpeed, float dt) {
    using namespace TmForeverPhysicsConstants;

    if (wheel->m_hasGroundContact != 0) {
        if (m_useGroundedWheelSpeedOverride != 0 &&
            m_wheelDriveDisabled == 0) {
            wheel->m_realTimeState.m_angularVelocity =
                m_groundedWheelAngularSpeedOverride;
            return;
        }
        wheel->m_realTimeState.m_angularVelocity =
            vehicleWheelSpeed / wheel->m_radius;
        return;
    }

    float targetAngularSpeed = 0.0f;
    float angularAcceleration = 0.0f;
    if (m_inputBrake > kWheelInputEpsilon) {
        targetAngularSpeed = std::clamp(1.0f - m_inputBrake, 0.0f, 1.0f);
        angularAcceleration = kWheelAngularDeceleration;
    } else if (m_inputGas > kWheelInputEpsilon &&
               m_wheelDriveDisabled == 0 && m_freeWheeling == 0) {
        targetAngularSpeed = static_cast<float>(
            static_cast<double>(m_inputGas) * kWheelGasAngularSpeedScale);
        angularAcceleration = kWheelAngularAcceleration;
    } else {
        wheel->m_realTimeState.m_angularVelocity = static_cast<float>(
            static_cast<double>(wheel->m_realTimeState.m_angularVelocity) *
            kWheelAirborneAngularDecay);
    }

    if (std::abs(angularAcceleration) >= kWheelInputEpsilon) {
        const float candidate =
            wheel->m_realTimeState.m_angularVelocity +
            angularAcceleration * dt;
        wheel->m_realTimeState.m_angularVelocity = candidate;
        if (angularAcceleration > 0.0f && candidate > targetAngularSpeed) {
            wheel->m_realTimeState.m_angularVelocity = targetAngularSpeed;
        } else if (angularAcceleration < 0.0f &&
                   candidate < targetAngularSpeed) {
            wheel->m_realTimeState.m_angularVelocity = targetAngularSpeed;
        }
    }
}

void CSceneVehicleCar::WheelIntegrate(SSimulationWheel* wheel, float dt) {
    if (wheel == nullptr || g_tuning == nullptr) return;

    if (g_tuning->m_shockModel == 0) {
        wheel->m_realTimeState.m_compression -=
            wheel->m_realTimeState.m_absorbDelta;
        wheel->m_realTimeState.m_absorbDelta = 0.0f;
        wheel->m_surfaceHandler.Reset();

        const float compressionAcceleration =
            (g_tuning->m_absorbingValRest -
             wheel->m_realTimeState.m_compression) *
                g_tuning->m_absorbingValKi -
            g_tuning->m_absorbingValKa *
                wheel->m_realTimeState.m_velocity;
        wheel->m_realTimeState.m_velocity +=
            compressionAcceleration * dt;
        wheel->m_realTimeState.m_compression +=
            wheel->m_realTimeState.m_velocity * dt;
    } else if (g_tuning->m_shockModel == 1 ||
               g_tuning->m_shockModel == 2) {
        const float previousCompression = wheel->m_realTimeState.m_compression;
        const float absorbedCompression =
            previousCompression - wheel->m_realTimeState.m_absorbDelta;
        wheel->m_surfaceHandler.Reset();
        const float compression =
            absorbedCompression +
            (g_tuning->m_absorbingValRest - absorbedCompression) *
                dt * g_tuning->m_absorbTension;

        wheel->m_realTimeState.m_velocity =
            (compression - previousCompression) / dt;
        wheel->m_realTimeState.m_compression = compression;
        wheel->m_realTimeState.m_absorbDelta = 0.0f;
    }

    if (g_tuning->m_shockModel >= 0 && g_tuning->m_shockModel <= 2) {
        wheel->m_surfaceHandler.m_surfaceLocation.tY -=
            wheel->m_realTimeState.m_compression;
    }
    wheel->m_surfaceHandler.UpdateSurface();
}

void CSceneVehicleCar::WheelReset(SSimulationWheel* wheel) {
    if (wheel == nullptr || g_tuning == nullptr) return;

    // TmForeverFixed.exe 0x7BD1B0..0x7BD2BF. VehicleReset invokes this for
    // every wheel after the loaded solid and tuning are installed. In
    // particular, the native reset value is AbsorbingValRest, not zero.
    wheel->m_realTimeState.m_absorbDelta = 0.0f;
    wheel->m_realTimeState.m_velocity = 0.0f;
    wheel->m_realTimeState.m_compression =
        g_tuning->m_absorbingValRest;

    wheel->m_surfaceHandler.Reset();
    wheel->m_surfaceHandler.m_surfaceLocation.tY -=
        wheel->m_realTimeState.m_compression;
    wheel->m_surfaceHandler.UpdateSurface();

    wheel->m_hasGroundContact = 0;
    wheel->m_groundMaterial = 0;
    wheel->m_isSlipping = 0;
    wheel->m_suspensionForce = 0.0f;
    wheel->m_absorbContactPoint = GmVec3(0.0f, 0.0f, 0.0f);
    wheel->m_groundContactCount = 0u;
    wheel->m_groundContactNormalSum = GmVec3(0.0f, 0.0f, 0.0f);
    wheel->m_hasLateralContact = 0;
    wheel->m_lateralContactPoint = GmVec3(0.0f, 0.0f, 0.0f);

    wheel->m_realTimeState.m_orientation.SetIdentity();
    wheel->m_realTimeState.m_angularVelocity = 0.0f;
    wheel->m_realTimeState.m_direction = GmVec3(0.0f, 0.0f, 0.0f);
    wheel->m_realTimeState.m_rotationAngle = 0.0f;
    wheel->m_realTimeState.m_steeringAngle = 0.0f;
    wheel->m_realTimeState.m_targetSteeringAngle = 0.0f;
}

void CSceneVehicleCar::VehicleReset() {
    // Physics-relevant subset of native 0x7C0320..0x7C05EC. Presentation,
    // sound, and replay-state copies are intentionally outside this library,
    // but every live field consumed by the force/contact pipeline is reset.
    m_inputGas = 0.0f;
    m_inputBrake = 0.0f;
    m_inputSteer = 0.0f;
    m_smoothedSteer = 0.0f;
    m_field_0x5ec = 0.0f;
    m_field_0x5f0 = 0.0f;
    m_field_0x5f4 = 0.0f;
    m_field_0x5f8 = 0.0f;
    m_field_0x5fc = 0.0f;
    m_field_0x600 = 0;
    // 0x7C03B6..0x7C03CB clears the air-control origin and retained angular
    // speed alongside the rest of the control state.
    m_airControlReferenceTick = 0u;
    m_airControlAngularSpeed = GmVec3(0.0f, 0.0f, 0.0f);
    m_freeWheeling = 0;
    m_chassisUp = GmVec3(0.0f, 1.0f, 0.0f);

    m_useGroundedWheelSpeedOverride = 0;
    m_wheelDriveDisabled = 0;
    m_groundedWheelAngularSpeedOverride = 0.0f;
    m_engineState = 0;
    m_engineClutchBoost = 0;
    m_engineTakeoffMode = 0;
    m_engineLocalVelocity = GmVec3(0.0f, 0.0f, 0.0f);
    m_engineOutsideTakeoffWindow = 0;
    m_engineShiftDirection = 0;

    m_hasBodyContact = 0;
    m_lastBodyContactTick = std::numeric_limits<uint32_t>::max();
    m_hasWaterContact = 0;
    m_frictionCurrentTick = 0u;
    m_frictionTickFraction = 0.0;
    m_model6LastLateralOverLimitTick =
        std::numeric_limits<uint32_t>::max();
    m_model6LateralOverLimitStartTick =
        std::numeric_limits<uint32_t>::max();
    m_model6LateralOverLimitDuration = 0u;
    m_model6EngineState1StartTick =
        std::numeric_limits<uint32_t>::max();
    m_model6EngineState3StartTick =
        std::numeric_limits<uint32_t>::max();

    m_hasAnyContact = 0;
    m_hasChassisContact = 0;
    m_chassisContactMaterial = 0u;
    m_wheelContactMaterial = 0u;
    m_frontWheelImpact = 0.0f;
    m_rearWheelImpact = 0.0f;
    m_chassisImpact = 0.0f;
    m_wheelContactCount = 0u;
    m_chassisContactCount = 0u;
    m_lastWheelContactCount = 0u;
    m_lastChassisContactCount = 0u;
    m_chassisContactPointSum = GmVec3(0.0f, 0.0f, 0.0f);
    m_chassisContactNormalSum = GmVec3(0.0f, 0.0f, 0.0f);
    m_appliedImpulseSum = GmVec3(0.0f, 0.0f, 0.0f);
    m_appliedCentralImpulseSum = GmVec3(0.0f, 0.0f, 0.0f);

    for (uint32_t index = 0u; index < m_wheels.GetCount(); ++index) {
        WheelReset(&m_wheels[index]);
    }
    m_engine.Reset();
}

void CSceneVehicleCar::EngineIntegrate(float input, float dt) {
    using namespace TmForeverPhysicsConstants;

    if (g_tuning == nullptr) return;

    // Native +0x2E4 is the RPM/transmission synchronizer state. It is
    // separate from the burnout force state at +0x69C, which ComputeForces
    // owns. Conflating the two makes an ordinary straight launch enter the
    // force model's state-two burnout branch.
    const auto setTakeoffMode = [this](int state) {
        m_engineTakeoffMode = state;
    };

    const bool inputActive = input > static_cast<float>(kInputThreshold);
    bool airborne = true;
    for (uint32_t i = 0; i < m_wheels.GetCount(); ++i) {
        if (m_wheels[i].m_hasGroundContact != 0) {
            airborne = false;
            break;
        }
    }

    if (m_engine.m_gearShiftTimer > 0.0f) {
        m_engine.m_gearShiftTimer -= dt;
    }
    const bool airborneOrShifting =
        airborne || m_engine.m_gearShiftTimer > 0.0f;

    const auto clampEngineRpm = [this]() {
        // 0x7BE257..0x7BE2B7 retains NaN, clamps positive overflow to the
        // engine's own +0x00 maximum, and clamps negative values to zero.
        if (m_engine.m_engineRpm > m_engine.m_maxRpm) {
            m_engine.m_engineRpm = m_engine.m_maxRpm;
        } else if (m_engine.m_engineRpm < 0.0f) {
            m_engine.m_engineRpm = 0.0f;
        }
    };

    if (g_tuning->m_steerModel != 5) {
        // Exact legacy path at 0x7BE00B..0x7BE253. It uses the preceding gear
        // for gears 2..5 and a weighted magnitude of the native +0x70C local
        // velocity vector.
        const int gear = std::clamp(m_engine.m_currentGear, 0, 5);
        const int ratioIndex = gear < 2 ? 0 : gear - 1;
        const float maximumRatio = g_tuning->m_m6MaxRpmRatios[ratioIndex];
        const float minimumRatio = g_tuning->m_m6MinRpmRatios[ratioIndex];
        const float speedScale = static_cast<float>(
            static_cast<double>(g_tuning->m_steerSlowDownFactor) *
            kOldEngineSpeedScale);
        const float weightedSpeed = std::sqrt(
            m_engineLocalVelocity.z * m_engineLocalVelocity.z +
            static_cast<float>(kOldEngineLateralSpeedWeight) *
                m_engineLocalVelocity.x * m_engineLocalVelocity.x +
            static_cast<float>(kInputThreshold) *
                m_engineLocalVelocity.y * m_engineLocalVelocity.y);
        const float normalizedRpm =
            weightedSpeed / speedScale * g_tuning->m_m6GearRatios[ratioIndex];
        const bool groundedAndNotShifting = !airborneOrShifting;

        if (groundedAndNotShifting) {
            if (m_engine.m_isReverse != 0) {
                if (gear != 0) {
                    m_engine.m_currentGear = 0;
                    m_engine.m_gearShiftTimer = kOldEngineShiftDuration;
                }
            } else if (gear == 0) {
                m_engine.m_currentGear = 1;
                m_engine.m_gearShiftTimer = kOldEngineShiftDuration;
            } else {
                int nextGear = gear;
                if (normalizedRpm > maximumRatio && gear < 5) {
                    ++nextGear;
                } else if (normalizedRpm < minimumRatio && gear > 1) {
                    --nextGear;
                }
                if (nextGear != gear) {
                    m_engine.m_currentGear = nextGear;
                    m_engine.m_gearShiftTimer = kOldEngineShiftDuration;
                }
            }
        } else if (m_engine.m_gearShiftTimer > 0.0f &&
                   m_engine.m_gearShiftTimer <= dt + dt) {
            m_engine.m_engineRpm -=
                m_engine.m_maxRpm * dt *
                static_cast<float>(kOldEngineShiftRpmLoss);
        }

        // The airborne/active-shift path replaces the speed-derived target
        // with |input| at 0x7BE1FE; the grounded path keeps normalizedRpm.
        const float targetRpm = m_engine.m_maxRpm *
            (groundedAndNotShifting ? normalizedRpm : std::abs(input));
        const float response = groundedAndNotShifting
            ? kOldEngineGroundResponse
            : kOldEngineAirResponse;
        m_engine.m_engineRpm +=
            (targetRpm - m_engine.m_engineRpm) * dt * response;
        clampEngineRpm();
        return;
    }

    if (airborneOrShifting) {
        if (inputActive) {
            m_engine.m_engineRpm += g_tuning->m_m6AirRpmAcceleration * dt;
        } else {
            m_engine.m_engineRpm -= g_tuning->m_m6AirRpmDeadening * dt;
        }
        clampEngineRpm();
        return;
    }

    // 0x7BD825 reads +0x69C only to couple force states one/two into the
    // engine's state four. Every state dispatch and write after 0x7BD83D is
    // against the independent +0x2E4 field.
    const bool burnoutForceState =
        m_engineState == 1 || m_engineState == 2;
    if (burnoutForceState) {
        if (m_engine.m_currentGear != 0) setTakeoffMode(4);
    } else if (m_engineTakeoffMode == 4) {
        setTakeoffMode(0);
    }

    const float speed = m_engineLocalVelocity.z;
    const auto gearRatio = [this](int gear) {
        return g_tuning->m_m6GearRatios[std::clamp(gear, 0, 5)];
    };

    if (m_engineTakeoffMode == 2 || m_engineTakeoffMode == 3) {
        const bool forwardTakeoff = m_engineTakeoffMode == 2;
        const float lowSpeed = forwardTakeoff
            ? g_tuning->m_m6PositiveTakeoffRearSpeed
            : g_tuning->m_m6NegativeTakeoffRearSpeed;
        const float highSpeed = forwardTakeoff
            ? g_tuning->m_m6PositiveTakeoffFrontSpeed
            : g_tuning->m_m6NegativeTakeoffFrontSpeed;
        m_engineOutsideTakeoffWindow = forwardTakeoff
            ? (speed < lowSpeed || speed > highSpeed)
            : (speed < lowSpeed || speed > highSpeed);
        m_engine.m_clutchRatio = 1.0f;
        const int takeoffGear = forwardTakeoff ? 1 : 0;
        m_engine.m_clutchRpm =
            std::abs(speed) * gearRatio(takeoffGear) +
            g_tuning->m_m6RpmDeltaOnGearUp[takeoffGear] * kZero;

        if (m_engineOutsideTakeoffWindow == 0 && inputActive) {
            m_engine.m_engineRpm += g_tuning->m_m6RpmGainOnTakeoff * dt;
        } else {
            m_engine.m_engineRpm -=
                g_tuning->m_m6RpmLossOnTakeoffFinished * dt;
        }
        if (m_engine.m_engineRpm <= m_engine.m_clutchRpm) {
            m_engine.m_engineRpm = m_engine.m_clutchRpm;
            setTakeoffMode(0);
            m_engineOutsideTakeoffWindow = 0;
        }
    } else if (m_engineTakeoffMode == 4) {
        m_engine.m_clutchRpm = m_engine.m_maxRpm;
        m_engine.m_clutchRatio = kM6ClutchRatioTarget;
        if (m_engine.m_engineRpm < m_engine.m_maxRpm) {
            m_engine.m_engineRpm +=
                g_tuning->m_m6BurnoutRpmAcceleration * dt;
        } else if (m_engine.m_engineRpm > m_engine.m_maxRpm) {
            m_engine.m_engineRpm += g_tuning->m_m6AirRpmDeadening * dt;
        }
    } else {
        if (m_engineClutchBoost != 0 && inputActive) {
            if (m_engine.m_clutchRatio <= kM6ClutchRatioTarget) {
                m_engine.m_clutchRatio = static_cast<float>(
                    (kM6ClutchRatioTargetWide - m_engine.m_clutchRatio) *
                    kM6ClutchRatioResponse * dt +
                    m_engine.m_clutchRatio);
            } else {
                m_engine.m_clutchRatio = kM6ClutchRatioTarget;
            }
        } else {
            m_engine.m_clutchRatio = 1.0f;
        }

        const int gear = std::clamp(m_engine.m_currentGear, 0, 5);
        m_engine.m_clutchRpm =
            std::abs(speed * m_engine.m_clutchRatio) * gearRatio(gear);
        if ((m_engine.m_isReverse != 0 && gear != 0) ||
            (m_engine.m_isReverse == 0 && gear == 0)) {
            m_engine.m_clutchRpm = 0.0f;
        }

        if (m_engine.m_engineRpm < m_engine.m_clutchRpm) {
            m_engine.m_engineRpm +=
                g_tuning->m_m6RpmGainOnGearDown * dt;
            if (m_engine.m_engineRpm > m_engine.m_clutchRpm) {
                setTakeoffMode(0);
            }
        } else {
            float loss = g_tuning->m_m6RpmLossOnTakeoffFinished;
            if (inputActive) {
                loss = (m_engineClutchBoost != 0 && !burnoutForceState)
                    ? g_tuning->m_m6AirRpmDeadening
                    : g_tuning->m_m6RpmLossOnGearUp;
            }
            m_engine.m_engineRpm -= loss * dt;
            if (m_engine.m_engineRpm < m_engine.m_clutchRpm) {
                setTakeoffMode(0);
            }
        }
    }

    // Narrow speed windows initiate the forward/reverse takeoff synchronizers.
    if (speed > g_tuning->m_m6PositiveTakeoffRearSpeed &&
        speed < g_tuning->m_m6PositiveTakeoffFrontSpeed &&
        inputActive && m_engine.m_isReverse == 0 &&
        m_engineTakeoffMode == 0) {
        setTakeoffMode(2);
        m_engineOutsideTakeoffWindow = 0;
        if (m_engine.m_currentGear == 0) {
            m_engine.m_gearShiftTimer = kM6ShiftDuration;
            m_engine.m_currentGear = 1;
        }
    } else if (speed < g_tuning->m_m6NegativeTakeoffFrontSpeed &&
               speed > g_tuning->m_m6NegativeTakeoffRearSpeed &&
               inputActive && m_engine.m_isReverse != 0 &&
               m_engineTakeoffMode == 0) {
        setTakeoffMode(3);
        m_engineOutsideTakeoffWindow = 0;
        if (m_engine.m_currentGear != 0) {
            m_engine.m_currentGear = 0;
            m_engine.m_gearShiftTimer = kM6ShiftDuration;
        }
    }

    if (m_engineTakeoffMode == 0 || m_engineTakeoffMode == 1) {
        int gear = std::clamp(m_engine.m_currentGear, 0, 5);
        if (m_engine.m_isReverse == 0) {
            if (gear == 0) {
                setTakeoffMode(1);
                m_engineShiftDirection = 0;
                if (m_engine.m_engineRpm < static_cast<float>(kEngineIdleRpm)) {
                    m_engine.m_gearShiftTimer = kM6ShiftDuration;
                    m_engine.m_currentGear = 1;
                }
            } else if (m_engine.m_clutchRpm >
                           g_tuning->m_m6MaxRpmRatios[gear] *
                               m_engine.m_maxRpm &&
                       gear < 5) {
                m_engine.m_gearShiftTimer = kM6ShiftDuration;
                m_engine.m_currentGear = gear + 1;
                setTakeoffMode(1);
                m_engineShiftDirection = 0;
            } else if (m_engine.m_clutchRpm <
                           g_tuning->m_m6MinRpmRatios[gear] *
                               m_engine.m_maxRpm &&
                       gear > 1) {
                m_engine.m_gearShiftTimer = kM6ShiftDuration;
                m_engine.m_currentGear = gear - 1;
                setTakeoffMode(1);
                m_engineShiftDirection = 1;
            }
        } else if (gear != 0) {
            setTakeoffMode(1);
            m_engineShiftDirection = 1;
            if (m_engine.m_engineRpm < static_cast<float>(kEngineIdleRpm)) {
                m_engine.m_currentGear = 0;
                m_engine.m_gearShiftTimer = burnoutForceState
                    ? kM6ReverseTakeoffShiftDuration
                    : kM6ShiftDuration;
            }
        }
    }

    clampEngineRpm();
}

void CSceneVehicleCar::VehicleFreeWheelingSet(int enabled) {
    m_freeWheeling = enabled;
}

int CSceneVehicleCar::IsGroundContact() {
    // Exact control flow of TmForeverFixed.exe: return on the first wheel whose
    // +0x124 contact flag is non-zero.
    const uint32_t wheelCount = m_wheels.GetCount();
    for (uint32_t i = 0; i < wheelCount; ++i) {
        if (m_wheels[i].m_hasGroundContact != 0) return 1;
    }
    return 0;
}

int CSceneVehicleCar::IsGroundContactId(
    uint8_t materialId,
    GmVec3* otherCorpusLocalDirection,
    CHmsCorpus** otherCorpus) const {
    if (otherCorpusLocalDirection == nullptr || otherCorpus == nullptr) {
        return 0;
    }

    const uint32_t wheelCount = m_wheels.GetCount();
    for (uint32_t i = 0; i < wheelCount; ++i) {
        const SSimulationWheel& wheel = m_wheels[i];
        if (wheel.m_hasGroundContact == 0 ||
            wheel.m_groundMaterial != materialId) {
            continue;
        }

        *otherCorpusLocalDirection = wheel.m_otherCorpusLocalDirection;
        *otherCorpus =
            CHmsCorpus::ResolvePointerToken(wheel.m_otherCorpusToken);
        return 1;
    }
    return 0;
}

void CSceneVehicleCar::ComputeVehicleGroundMaterialVals(
    StadiumVehicleMaterials::GroundValues* values,
    int* hasGroundContact) const {
    if (values == nullptr || hasGroundContact == nullptr) return;

    *values = {};
    *hasGroundContact = 0;

    const uint32_t wheelCount = m_wheels.GetCount();
    if (wheelCount == 0) return;

    uint32_t contactedWheelCount = 0;
    for (uint32_t i = 0; i < wheelCount; ++i) {
        if (m_wheels[i].m_hasGroundContact == 0) continue;

        // Exact 0x7C2800 behavior: every contacted wheel contributes the
        // material selected by wheel zero, rather than its own material.
        const StadiumVehicleMaterials::Material* material =
            StadiumVehicleMaterials::Find(m_wheels[0].m_groundMaterial);
        if (material != nullptr) {
            const StadiumVehicleMaterials::GroundValues contribution =
                StadiumVehicleMaterials::ToGroundValues(*material);
            values->speed += contribution.speed;
            values->accelerationCoef += contribution.accelerationCoef;
            values->brakeCoef += contribution.brakeCoef;
            values->grip += contribution.grip;
        }

        ++contactedWheelCount;
        *hasGroundContact = 1;
    }

    if (contactedWheelCount == 0) return;
    const float inverseCount = 1.0f / static_cast<float>(contactedWheelCount);
    values->speed *= inverseCount;
    values->accelerationCoef *= inverseCount;
    values->brakeCoef *= inverseCount;
    values->grip *= inverseCount;
}

void CSceneVehicleCar::GetSlopeAdherence(
    const GmVec3& force, float* lateralAdherence,
    float* axialAdherence) const {
    if (lateralAdherence == nullptr || axialAdherence == nullptr ||
        g_tuning == nullptr) {
        return;
    }

    const float squaredLength =
        force.x * force.x + force.y * force.y + force.z * force.z;
    // Exact 0x7BEB68 comparison: a degenerate force leaves both caller-owned
    // defaults untouched. ComputeForces initializes those defaults to one.
    if (squaredLength <= TmForeverPhysicsConstants::kNormalizeSquaredEpsilon) {
        return;
    }

    const float forceLength = std::sqrt(squaredLength);
    const float verticalRatio = std::abs(force.y / forceLength);
    const auto mapAdherence = [verticalRatio](float minimum, float maximum) {
        if (verticalRatio < minimum) return 0.0f;
        if (verticalRatio > maximum) return 1.0f;

        const float ratio =
            (verticalRatio - minimum) / (maximum - minimum);
        return 1.0f - std::cos(
            ratio * static_cast<float>(TmForeverPhysicsConstants::kPi) *
            0.5f);
    };

    *lateralAdherence = mapAdherence(
        g_tuning->m_lateralSlopeAdherenceMin,
        g_tuning->m_lateralSlopeAdherenceMax);
    *axialAdherence = mapAdherence(
        g_tuning->m_axialSlopeAdherenceMin,
        g_tuning->m_axialSlopeAdherenceMax);
}

void CSceneVehicleCar::ComputeAirControl(
    const GmVec3* localAngularSpeed, uint32_t tick, int grounded,
    int contactFlag) {
    using namespace TmForeverPhysicsConstants;

    if (localAngularSpeed == nullptr || m_hmsItem == nullptr ||
        g_tuning == nullptr) {
        return;
    }

    // 0x7BF1E8..0x7BF20F. Model 4/5 in water leaves the whole routine.
    const int steerModel = g_tuning->m_steerModel;
    if ((steerModel == 4 || steerModel == 5) && m_hasWaterContact != 0) {
        return;
    }

    // 0x7BF21F. Everything below works on the negated angular speed, which is
    // what makes the tail's torque oppose the rotation.
    GmVec3 negated(-localAngularSpeed->x,
                   -localAngularSpeed->y,
                   -localAngularSpeed->z);

    // 0x7BF239 and 0x7BF264. While the car is on the ground the routine only
    // records state; only the third case actually steers in the air. The two
    // recording cases differ in that the first also restarts the window.
    if (contactFlag != 0) {
        m_airControlReferenceTick = tick;
        m_airControlAngularSpeed = *localAngularSpeed;
    } else if (m_hasAnyContact != 0) {
        m_airControlAngularSpeed = *localAngularSpeed;
    } else if (tick - m_airControlReferenceTick <
               g_tuning->m_airControlDuration) {
        // 0x7BF29C's window test is an unsigned compare, so a tick that has
        // wrapped behind the origin reads as an enormous elapsed time and ends
        // air control rather than extending it.
        GmVec3 target = *localAngularSpeed;
        const float steer = m_inputSteer;
        const float retainedYaw = m_airControlAngularSpeed.y;

        // 0x7BF2C7..0x7BF386 classifies the steering against the retained yaw
        // rate. Both epsilon comparisons are ordered and the negative epsilon
        // is its own float at .rdata 0x00B574FC.
        const bool steersPositive = kWheelInputEpsilon < steer;
        const bool steersNegative = -kWheelInputEpsilon > steer;
        const bool opposesRetainedYaw =
            (steersPositive && 0.0f > retainedYaw) ||
            (steersNegative && 0.0f < retainedYaw);

        bool applyDamping = false;
        if (opposesRetainedYaw) {
            // 0x7BF309. Counter-steering only damps once the yaw rate is
            // already past the tuning ceiling, and only then is the retained
            // value refreshed. Below the ceiling the retained yaw is held, so
            // the assignment below pulls the car back to it.
            applyDamping = g_tuning->m_maxAngularSpeedYAirControl <
                           std::abs(localAngularSpeed->y);
            if (applyDamping) {
                m_airControlAngularSpeed.y = localAngularSpeed->y;
            }
        } else {
            // 0x7BF342. Steering with the rotation always damps; a steering
            // input inside the dead zone does not. Either way the retained yaw
            // follows the current one.
            applyDamping =
                (steersPositive && 0.0f < retainedYaw) ||
                (steersNegative && 0.0f > retainedYaw);
            m_airControlAngularSpeed.y = localAngularSpeed->y;
        }
        target.y = m_airControlAngularSpeed.y;

        // 0x7BF3A9..0x7BF3F8. Model 4/5 additionally retains roll, and braking
        // while the retained roll is positive zeroes it instead of following.
        if (steerModel == 4 || steerModel == 5) {
            m_airControlAngularSpeed.x =
                (kWheelInputEpsilon < m_inputBrake &&
                 0.0f < m_airControlAngularSpeed.x)
                    ? 0.0f
                    : localAngularSpeed->x;
            target.x = m_airControlAngularSpeed.x;
        }

        // 0x7BF401 scales the drag direction, not the target.
        if (applyDamping) {
            negated.x = static_cast<float>(
                static_cast<double>(negated.x) * kAirControlDampingScale);
            negated.y = static_cast<float>(
                static_cast<double>(negated.y) * kAirControlDampingScale);
            negated.z = static_cast<float>(
                static_cast<double>(negated.z) * kAirControlDampingScale);
        }

        // 0x7BF425. The curve at tuning +0x36C consumes the raw absolute
        // angular speed with no km/h conversion.
        if (grounded == 0) {
            negated.z *= g_tuning->GetAirControlZCoefFromAngularSpeed(
                std::abs(localAngularSpeed->z));
        }

        SetVehicleAngularSpeed(&target);
    }

    // 0x7BF480. The quadratic angular drag is airborne-only and runs on every
    // path, including the two that only recorded state.
    if (grounded != 0) return;

    const float squaredLength = negated.x * negated.x +
                                negated.y * negated.y +
                                negated.z * negated.z;
    const float length = std::sqrt(squaredLength);
    if (length < kWheelInputEpsilon) return;

    const float inverseLength = 1.0f / length;
    const float scale =
        g_tuning->m_angularFluidFrictionCoef2 * length * length +
        g_tuning->m_angularFluidFrictionCoef1 * length;
    GmVec3 localTorque(negated.x * inverseLength * scale,
                       negated.y * inverseLength * scale,
                       negated.z * inverseLength * scale);
    AddVehicleTorque(
        this, reinterpret_cast<CSceneVehicleCar*>(&localTorque), nullptr);
}

void CSceneVehicleCar::ApplyFrictionForces(
    const GmVec3* localLinearSpeed) {
    using namespace TmForeverPhysicsConstants;

    if (localLinearSpeed == nullptr || m_hmsItem == nullptr ||
        g_tuning == nullptr) {
        return;
    }

    const int steerModel = g_tuning->m_steerModel;
    if ((steerModel == 4 || steerModel == 5) &&
        m_hasWaterContact != 0 && IsGroundContact() == 0) {
        return;
    }

    // 0x7BED65..0x7BEDA5. The throttle pedal is the gas while driving forwards
    // and the brake while reversing. Its comparison against the epsilon is the
    // strict ordered one the executable spells: an input exactly equal to the
    // epsilon leaves the coasting slowdown switched off.
    const float selectedInput =
        m_engine.m_isReverse == 0 ? m_inputGas : m_inputBrake;
    if (selectedInput < kWheelInputEpsilon || m_freeWheeling != 0) {
        const float squaredLength =
            localLinearSpeed->x * localLinearSpeed->x +
            localLinearSpeed->y * localLinearSpeed->y +
            localLinearSpeed->z * localLinearSpeed->z;
        if (kNormalizeSquaredEpsilon < squaredLength) {
            const float length = std::sqrt(squaredLength);
            const float inverseLength = 1.0f / length;
            const float constantScale =
                -g_tuning->m_groundSlowDownBase * inverseLength;
            GmVec3 localForce(
                localLinearSpeed->x * constantScale,
                localLinearSpeed->y * constantScale,
                localLinearSpeed->z * constantScale);
            if (m_freeWheeling == 0) {
                // 0x7BEE75 reads tuning +0x5C, GroundSlowDownCoef, not the
                // fluid friction at +0x154. Fluid friction is not a force here
                // at all: ComputeForces installs it as the body's linear
                // damping, and only while airborne.
                const float linearScale =
                    -g_tuning->m_groundSlowDownCoef;
                localForce.x += localLinearSpeed->x * linearScale;
                localForce.y += localLinearSpeed->y * linearScale;
                localForce.z += localLinearSpeed->z * linearScale;
            }
            AddVehicleCentralForce(
                this, reinterpret_cast<CSceneVehicleCar*>(&localForce),
                nullptr);
        }
    }

    if (steerModel < 4) {
        if (m_hasBodyContact != 0) {
            const float scale =
                -g_tuning->GetLateralContactSlowDownFromSpeed(
                    localLinearSpeed->z);
            GmVec3 localForce(
                localLinearSpeed->x * scale,
                localLinearSpeed->y * scale,
                localLinearSpeed->z * scale);
            AddVehicleCentralForce(
                this, reinterpret_cast<CSceneVehicleCar*>(&localForce),
                nullptr);
        }
        return;
    }

    const uint32_t currentTick = m_frictionCurrentTick;
    if (m_hasBodyContact != 0) m_lastBodyContactTick = currentTick;
    if (m_lastBodyContactTick > currentTick ||
        currentTick - m_lastBodyContactTick >=
            g_tuning->m_m5LateralConstantSlowDownDuration) {
        return;
    }

    const float squaredLength =
        localLinearSpeed->x * localLinearSpeed->x +
        localLinearSpeed->y * localLinearSpeed->y +
        localLinearSpeed->z * localLinearSpeed->z;
    const float length = std::sqrt(squaredLength);
    if (!(kWheelInputEpsilon < length)) return;

    const float inverseLength = 1.0f / length;
    const float scale =
        -g_tuning->M5GetLateralContactSlowDownFromSpeed(length);
    GmVec3 localForce(
        localLinearSpeed->x * inverseLength * scale,
        localLinearSpeed->y * inverseLength * scale,
        localLinearSpeed->z * inverseLength * scale);
    AddVehicleCentralForce(
        this, reinterpret_cast<CSceneVehicleCar*>(&localForce), nullptr);
}

int CSceneVehicleCar::ApplyWaterForces(
    const GmVec3* accumulatedLocalForce) {
    using namespace TmForeverPhysicsConstants;

    if (accumulatedLocalForce == nullptr || m_hmsItem == nullptr ||
        g_tuning == nullptr || m_localBodyBounds.IsNull() ||
        m_hmsItem->m_corpuses.GetCount() == 0u) {
        return 0;
    }

    CHmsCorpus* corpus = m_hmsItem->m_corpuses[0];
    if (corpus == nullptr || corpus->m_zone == nullptr) return 0;

    // Native corpus virtual +0x78 returns the current dynamic transform.
    // A static corpus retains its stored transform instead.
    GmIso4 vehicleTransform = corpus->m_location;
    if (corpus->m_dyna != nullptr) {
        const CHmsDyna::CHmsStateDyna& state =
            corpus->m_dyna->CurrentState();
        vehicleTransform.rot = state.m_rotationMatrix;
        vehicleTransform.SetTranslation(state.m_position);
    }

    GmBoxAligned worldBounds;
    worldBounds.SetMult(m_localBodyBounds, vehicleTransform);
    const float verticalExtent = std::abs(worldBounds.extents.y);
    const float minimumY = worldBounds.center.y - verticalExtent;
    const float maximumY = worldBounds.center.y + verticalExtent;

    CHmsZone& zone = *corpus->m_zone;
    const bool isInsideMap = zone.m_waterCollisionMap.IsInside(
        worldBounds.center.x, worldBounds.center.z);
    const float surfaceHeight = zone.m_waterCollisionSurfaceHeight;

    // An outside point may still use a default mask value of one. Inside
    // points, and all other outside points, take the full bottom/mask branch.
    const bool acceptedByOutsideDefault =
        !isInsideMap && zone.m_waterCollisionMap.m_defaultValue == 1u &&
        surfaceHeight > minimumY;
    if (!acceptedByOutsideDefault) {
        if (maximumY <= zone.m_waterCollisionBottomHeight ||
            surfaceHeight <= minimumY ||
            zone.m_waterCollisionMap.GetValue(
                worldBounds.center.x, worldBounds.center.z) != 1u) {
            return 0;
        }
    }

    const float depth = surfaceHeight - minimumY;
    if (!(depth > kWaterMinimumDepth)) return 0;

    GmVec3 localLinearSpeed(0.0f, 0.0f, 0.0f);
    m_hmsItem->GetLinearSpeed(m_hmsItem, &localLinearSpeed);
    const GmVec3 worldLinearSpeed =
        TransformVector(vehicleTransform.rot, localLinearSpeed);

    // The shallow, airborne, downward-moving branch produces an impulse and
    // deliberately reports no continuous water contact for this pass.
    if (m_hasAnyContact == 0 &&
        static_cast<double>(depth) < kWaterReboundMaximumDepth &&
        surfaceHeight - maximumY < kWaterSurfaceDeltaThreshold &&
        worldLinearSpeed.y < kWaterDownwardSpeedThreshold) {
        const float horizontalSpeedSquared =
            worldLinearSpeed.x * worldLinearSpeed.x +
            worldLinearSpeed.z * worldLinearSpeed.z;
        const float reboundMinimumSquared =
            g_tuning->m_waterReboundMinHorizontalSpeed *
            g_tuning->m_waterReboundMinHorizontalSpeed;

        float speedRatio = -1.0f;
        bool shouldRebound = false;
        if (horizontalSpeedSquared <= reboundMinimumSquared) {
            const float bumpMinimumSquared =
                g_tuning->m_waterBumpMinSpeed *
                g_tuning->m_waterBumpMinSpeed;
            if (SquaredLength(worldLinearSpeed) > bumpMinimumSquared) {
                speedRatio = 0.0f;
                shouldRebound = true;
            }
        } else {
            const float horizontalSpeed =
                std::sqrt(horizontalSpeedSquared);
            speedRatio = -horizontalSpeed / worldLinearSpeed.y;
            shouldRebound = !std::isnan(speedRatio) && speedRatio > 0.0f;
        }

        if (shouldRebound) {
            const float slowDown =
                g_tuning->GetWaterBumpSlowDownFromSpeedRatio(speedRatio);
            const float rebound =
                g_tuning->GetWaterReboundFromSpeedRatio(speedRatio);
            const GmVec3 worldImpulse(
                -rebound * worldLinearSpeed.x,
                -slowDown * worldLinearSpeed.y,
                -rebound * worldLinearSpeed.z);
            GmVec3 localImpulse;
            localImpulse.SetMultTranspose(
                worldImpulse, vehicleTransform.rot);
            WaterSplash(&worldLinearSpeed);
            AddVehicleCentralImpulse(&localImpulse);
            return 0;
        }
    }

    GmVec3 localDrag(0.0f, 0.0f, 0.0f);
    const float localSpeed = std::sqrt(SquaredLength(localLinearSpeed));
    if (kWheelInputEpsilon < localSpeed) {
        const float dragScale =
            -g_tuning->GetWaterFrictionFromSpeed(localSpeed);
        localDrag = localLinearSpeed * dragScale;
    }

    GmVec3 localAngularSpeed(0.0f, 0.0f, 0.0f);
    m_hmsItem->GetAngularSpeed(m_hmsItem, &localAngularSpeed);
    const float angularSpeed =
        std::sqrt(SquaredLength(localAngularSpeed));
    const float angularScale =
        -g_tuning->m_waterAngularFriction -
        g_tuning->m_waterAngularFrictionSq * angularSpeed;
    GmVec3 localTorque = localAngularSpeed * angularScale;

    GmVec3 localWaterGravity(0.0f, -g_tuning->m_waterGravity, 0.0f);
    localWaterGravity.MultTranspose(vehicleTransform.rot);
    GmVec3 localForce =
        localWaterGravity + localDrag - *accumulatedLocalForce;
    AddVehicleCentralForce(
        this, reinterpret_cast<CSceneVehicleCar*>(&localForce), nullptr);
    AddVehicleTorque(
        this, reinterpret_cast<CSceneVehicleCar*>(&localTorque), nullptr);
    return 1;
}

void CSceneVehicleCar::ComputeForcesModel3(CSceneVehicleCar* pilot, float dt) {
    if (m_hmsItem == nullptr) return;

    // Call the exact 1:1 float model translation
    // We provide dummy local variables for the stack pointers that Ghidra misidentified as parameters.
    GmVec3 p3(0,0,0);
    GmVec3 p6(0,0,0);
    
    GmVec3 linSpeed;
    m_hmsItem->GetLinearSpeed(m_hmsItem, &linSpeed);
    p6 = linSpeed;
    
    GmVec3 p7(0, 1.0f, 0); // Ground normal
    float p10[16] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    int p11[4] = {1, 1, 1, 1};
    float p12[16] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    
    float p11_temp[4] = {1.0f, 1.0f, 1.0f, 1.0f}; // temp
    void* p10_temp = p11_temp; // temp
    float p12_temp[4] = {1.0f, 1.0f, 1.0f, 1.0f}; // temp
    
    ComputeForcesModel3_Exact(dt, &p3, this->m_inputGas, this->m_inputBrake, &p6, &p7, this->m_inputSteer, 1, p10_temp, (int*)p11_temp, p12_temp);
    
    // Apply the returned force!
    if (p3.x != 0 || p3.y != 0 || p3.z != 0) {
        m_hmsItem->AddForce(m_hmsItem, &p3, nullptr);
    }
}

void CSceneVehicleCar::ComputeForcesModel6(
    float dt,
    GmVec3* accumulatedLocalForce,
    float lateralSlopeAdherence,
    float axialSlopeAdherence,
    GmVec3* localLinearSpeed,
    GmVec3* localAngularSpeed,
    float processedSteer,
    int hasGroundMaterial,
    StadiumVehicleMaterials::GroundValues* groundMaterial,
    int* hasSlippingWheel,
    float* axialBrakeForce) {
    if (hasSlippingWheel != nullptr) *hasSlippingWheel = 0;
    if (axialBrakeForce != nullptr) *axialBrakeForce = 0.0f;
    if (m_hmsItem == nullptr || g_tuning == nullptr ||
        accumulatedLocalForce == nullptr || localLinearSpeed == nullptr ||
        localAngularSpeed == nullptr || groundMaterial == nullptr) {
        return;
    }

    // ApplyWaterForces is the first force producer in the native Model6
    // entry, before suspension and the grounded/airborne branch split.
    m_hasWaterContact = ApplyWaterForces(accumulatedLocalForce);

    const uint32_t currentTick = m_frictionCurrentTick;
    bool engineStateKeepsClutchBoost = false;

    // 0x7C4839..0x7C48E9 advances the two timed engine-force phases before
    // suspension. State one remains active for +0x298 milliseconds and then
    // enters state three; state three marks every wheel as slipping until its
    // +0x2A8 lifetime expires.
    if (m_engineState == 1) {
        const bool tickPrecedesStart =
            currentTick < m_model6EngineState1StartTick;
        const uint32_t elapsed =
            currentTick - m_model6EngineState1StartTick;
        if (tickPrecedesStart || elapsed >= g_tuning->m_m6BurnoutDuration) {
            m_model6EngineState3StartTick = currentTick;
            m_engineState = 3;
        } else {
            engineStateKeepsClutchBoost = true;
        }
    }
    if (m_engineState == 3) {
        const bool tickPrecedesStart =
            currentTick < m_model6EngineState3StartTick;
        const uint32_t elapsed =
            currentTick - m_model6EngineState3StartTick;
        if (tickPrecedesStart ||
            elapsed >= g_tuning->m_m6AfterBurnoutDuration) {
            m_engineState = 0;
        } else {
            for (uint32_t index = 0u;
                 index < m_wheels.GetCount(); ++index) {
                m_wheels[index].m_isSlipping = 1;
            }
        }
    }

    // 0x7C48F6..0x7C4932 visits every wheel before the force-model tail. The
    // helper itself rejects uncontacted wheels. Engine state two is the sole
    // native bypass for this suspension-force pass.
    if (m_engineState != 2) {
        for (uint32_t index = 0u; index < m_wheels.GetCount(); ++index) {
            WheelAddForceToVehicle(&m_wheels[index], 0.0f);
        }
    }

    // 0x7C4962..0x7C5018 constructs each contacted wheel's lateral axis from
    // its accumulated ground normal, rotates the front pair by processed
    // steering, projects local speed onto that axis, and applies the baseline
    // tire reaction. Burnout/state-specific inertial terms remain separate.
    if (m_engineState == 0) {
        for (uint32_t index = 0u; index < m_wheels.GetCount(); ++index) {
            SSimulationWheel& wheel = m_wheels[index];
            if (wheel.m_hasGroundContact == 0) continue;

            const GmVec3 lateralDirection =
                GetModel6WheelLateralDirection(&wheel, processedSteer);
            const float lateralSpeed =
                GmVec3::Dot(*localLinearSpeed, lateralDirection);
            const float damperModulation =
                g_tuning->M6GetModulationFromDamperAbsorbVal(
                    wheel.m_realTimeState.m_compression);
            const float slidingModulation =
                wheel.m_isSlipping != 0
                    ? g_tuning->m_maxSideFrictionSliding
                    : 1.0f;
            const float slippingBrakeModulation =
                wheel.m_isSlipping != 0 && m_inputBrake > 0.0f
                    ? g_tuning->m_m6FrictionModulationWhenSlipAndBrake
                    : 1.0f;
            const float maxSideForce =
                g_tuning->GetMaxSideFrictionFromSpeed(localLinearSpeed->z) *
                groundMaterial->grip * lateralSlopeAdherence *
                slidingModulation * slippingBrakeModulation *
                damperModulation;
            const float rawSideForce =
                -0.5f * g_tuning->m_sideFriction1 * lateralSpeed;
            const bool isSlipping =
                std::abs(rawSideForce) > maxSideForce;
            wheel.m_isSlipping = isSlipping ? 1 : 0;
            const float sideForce =
                g_tuning->GetModel6WheelSideForce(
                    rawSideForce, maxSideForce);
            GmVec3 localTireForce = lateralDirection * sideForce;
            AddVehicleCentralForce(
                this,
                reinterpret_cast<CSceneVehicleCar*>(&localTireForce),
                nullptr);
        }
    }

    bool anySlippingWheel = false;
    for (uint32_t i = 0; i < m_wheels.GetCount(); ++i) {
        anySlippingWheel |= m_wheels[i].m_isSlipping != 0;
    }
    if (hasSlippingWheel != nullptr && anySlippingWheel) {
        *hasSlippingWheel = 1;
    }

    // 0x7C5A18..0x7C5B14 selects the reverse flag here, after the contacted
    // wheel consumer and before either force branch. The normal-ground subset
    // below reads it back at 0x7C5BE5 for its drive-torque sign, so this must
    // stay ahead of that.
    UpdateReverseState(*localLinearSpeed);

    if (g_tuning->m_steerModel != 5 || hasGroundMaterial == 0) {
        // Airborne, water, and non-Stadium paths have not yet been separated
        // from the old translation. Keep the prior behavior for those states
        // while the native Model6 port advances branch by branch.
        ComputeForcesModel3(this, dt);
        return;
    }

    const float localLateralSpeed = localLinearSpeed->x;
    const float localForwardSpeed = localLinearSpeed->z;

    // Exact normal-ground subset at 0x7C5BE5..0x7C5EF0. Model6 evaluates the
    // lateral velocity at each axle, including yaw velocity, and applies half
    // of SideFriction1 per wheel. The over-limit force blend is exact; its
    // aggregate state bookkeeping after the wheel loop remains to be ported.
    const float halfWheelbase = 0.5f * m_field_0x840;
    const float maxSideForce =
        g_tuning->GetMaxSideFrictionFromSpeed(localForwardSpeed) *
        groundMaterial->grip;
    const float steerSpeedFactor = g_tuning->GetModel6SteerSpeedFactor(localForwardSpeed);
    const float driveTorque = g_tuning->GetSteerDriveTorqueFromSpeed(localForwardSpeed);
    const float reverseSign = m_engine.m_field_0x28 != 0 ? -1.0f : 1.0f;
    float lateralForceSum = 0.0f;
    float yawTorque = 0.0f;
    float overLimitAppliedForceSum = 0.0f;
    float overLimitMaximumForceSum = 0.0f;
    bool hasLateralOverLimit = false;

    for (uint32_t i = 0; i < m_wheels.GetCount(); ++i) {
        const SSimulationWheel& wheel = m_wheels[i];
        const float axleOffset = wheel.m_isSteerable != 0 ? halfWheelbase : -halfWheelbase;
        const float axleLateralSpeed =
            localLateralSpeed + localAngularSpeed->y * axleOffset;
        const float rawLateralForce =
            -g_tuning->m_sideFriction1 * 0.5f * axleLateralSpeed;
        const float lateralForce =
            g_tuning->GetModel6SideForce(rawLateralForce, maxSideForce);
        if (maxSideForce < std::abs(rawLateralForce)) {
            hasLateralOverLimit = true;
            overLimitAppliedForceSum += std::abs(lateralForce);
            overLimitMaximumForceSum += maxSideForce;
        }
        lateralForceSum += lateralForce;

        float axleTorqueForce = g_tuning->m_steerGroundTorque * lateralForce;
        if (wheel.m_isSteerable != 0) {
            const float slippingCoef = wheel.m_isSlipping != 0
                ? g_tuning->m_steerGroundTorqueSlippingCoef
                : 1.0f;
            // Crucially, SteerGroundTorque does not multiply the commanded
            // steer term in the original instruction stream.
            axleTorqueForce -= steerSpeedFactor * m_smoothedSteer *
                               driveTorque * reverseSign * slippingCoef;
        }
        yawTorque += axleOffset * axleTorqueForce;
    }

    // The original obtains the translational side reaction through its wheel
    // contact path. Apply the equivalent aggregate force while that contact
    // projection is still represented semantically in the standalone build.
    GmVec3 localSideForce(lateralForceSum, 0.0f, 0.0f);
    AddVehicleCentralForce(this, reinterpret_cast<CSceneVehicleCar*>(&localSideForce), nullptr);
    GmVec3 localTorque(0.0f, yawTorque, 0.0f);
    AddVehicleTorque(this, reinterpret_cast<CSceneVehicleCar*>(&localTorque), nullptr);

    if (hasLateralOverLimit) {
        m_model6LastLateralOverLimitTick = currentTick;
        if (m_engineClutchBoost == 0) {
            m_model6LateralOverLimitStartTick = currentTick;
        }
        m_model6LateralOverLimitDuration =
            currentTick - m_model6LateralOverLimitStartTick;
    }

    float normalAccelerationWeight = 1.0f;
    if (currentTick == m_model6LastLateralOverLimitTick &&
        TmForeverPhysicsConstants::kWheelInputEpsilon <
            overLimitMaximumForceSum) {
        normalAccelerationWeight =
            g_tuning->GetModel6AccelerationBlendFromLateralOverLimit(
                overLimitAppliedForceSum,
                overLimitMaximumForceSum);
    }

    // This is the currently ported ordinary-drive subset of the Model6 tail,
    // which natively follows the normal-ground lateral/yaw block above. Its
    // curve, forward braking, material coefficients, terminal-speed
    // correction, and axial slope input now match the fixed executable.
    const bool isOrdinaryForwardDrive =
        m_engine.m_field_0x28 == 0 &&
        m_freeWheeling == 0 &&
        m_field_0x600 == 0;

    if (isOrdinaryForwardDrive) {
        // 0x7C6325 and 0x7C6463 split the braking source on the sign of the
        // forward speed alone: a strictly positive speed runs the forward
        // block off the brake pedal, a strictly negative one runs the mirrored
        // rolling-backwards block off the gas pedal, and an exactly zero speed
        // leaves the force at the zero both branches start from. The slipping
        // modulation loop is duplicated identically in the executable, so it is
        // shared here.
        bool brakeSaturated = false;
        float slippingBrakeModulation = 1.0f;
        for (uint32_t index = 0u;
             index < m_wheels.GetCount(); ++index) {
            if (m_wheels[index].m_isSlipping != 0) {
                slippingBrakeModulation *=
                    g_tuning->m_m6BrakeModulationWhenSlipping;
            }
        }
        const float forwardBrakeForce =
            localForwardSpeed < 0.0f
                ? g_tuning->GetModel6BackwardAxialBrakeForce(
                      localForwardSpeed, m_inputGas,
                      groundMaterial->brakeCoef,
                      slippingBrakeModulation, anySlippingWheel,
                      &brakeSaturated)
                : g_tuning->GetModel6ForwardAxialBrakeForce(
                      localForwardSpeed, m_inputBrake,
                      groundMaterial->brakeCoef,
                      slippingBrakeModulation, anySlippingWheel,
                      &brakeSaturated);
        if (axialBrakeForce != nullptr) {
            *axialBrakeForce = forwardBrakeForce;
        }
        if (brakeSaturated) {
            for (uint32_t index = 0u;
                 index < m_wheels.GetCount(); ++index) {
                m_wheels[index].m_isSlipping = 1;
            }
        }

        const float slippingAcceleration =
            g_tuning->M5GetSlippingAccelFromSpeed(localForwardSpeed);
        // 0x7C5FDB selects the drive curve on the reverse flag: forward reads
        // the tuning's +0x34 acceleration curve, reverse reads the +0x230
        // rear-gear curve. Only this term changes; the slipping curve above is
        // evaluated before the branch and used either way.
        const float normalAcceleration =
            m_engine.m_isReverse != 0
                ? g_tuning->M6GetRearGearAccelFromSpeed(localForwardSpeed)
                : g_tuning->M5GetAccelFromSpeed(localForwardSpeed);
        // 0x7C6020 tests the transmission/RPM state before the blend: while a
        // gear change is in progress (native +0x2E4 state one) the drive curve
        // is replaced by an outright zero rather than scaled, so neither the
        // slipping nor the normal curve contributes for the duration of the
        // shift.
        const float acceleration =
            m_engineTakeoffMode == 1
                ? 0.0f
                : slippingAcceleration * (1.0f - normalAccelerationWeight) +
                      normalAcceleration * normalAccelerationWeight;
        uint32_t engineStateElapsed = 0u;
        if (m_engineState == 1) {
            engineStateElapsed =
                currentTick - m_model6EngineState1StartTick;
        } else if (m_engineState == 3) {
            engineStateElapsed =
                currentTick - m_model6EngineState3StartTick;
        }
        const float engineStateAccelerationModulation =
            g_tuning->GetModel6EngineStateAccelerationModulation(
                m_engineState, engineStateElapsed);
        const float engineStateAxialImpulse =
            g_tuning->GetModel6EngineStateAxialImpulse(
                m_engineState, engineStateElapsed);
        // 0x7C623E..0x7C62AA builds the drive term from both pedals. The brake
        // side carries a direction that is -1 while reversing and 0 otherwise,
        // so the forward case reduces to the gas term alone while reverse
        // drives backwards off the brake pedal. The grouping below follows the
        // executable: each pedal is scaled by the ground material first, the
        // two are summed, and only then does the acceleration curve apply.
        const float brakeDriveDirection = m_engine.m_isReverse != 0
            ? TmForeverPhysicsConstants::kNegativeOne
            : 0.0f;
        const float driveInput =
            brakeDriveDirection * groundMaterial->accelerationCoef *
                m_inputBrake +
            m_inputGas * groundMaterial->accelerationCoef;
        // 0x7C62AA..0x7C62D8 assembles the drive term on its own: the pedal
        // sum drives the acceleration curve, the engine-state modulation
        // scales that product, and the state-three impulse is added last. The
        // native also subtracts a steering-slowdown term here
        // (0x7C608F: SteerSlowDownCoef * |car+0x5E8| * SteerSlowDown(speed.z),
        // times the reverse sign). Stadium's SteerSlowDown curve is zero for
        // every non-negative speed, so that term is left unwired rather than
        // guessed; see PARITY_STATUS.md.
        float driveTerm =
            driveInput * acceleration * engineStateAccelerationModulation +
            engineStateAxialImpulse;

        // 0x7C62DC..0x7C62E8. Water contact halves the assembled drive term
        // through a double-typed multiply, before braking is applied.
        if (m_hasWaterContact != 0) {
            driveTerm = static_cast<float>(
                static_cast<double>(driveTerm) *
                TmForeverPhysicsConstants::kHalf);
        }

        // 0x7C663E..0x7C6671. The braking force is subtracted only at the end,
        // signed by the raw sign bit of the forward speed rather than by an
        // ordered comparison, so a negative zero selects the reverse sign.
        const float forwardSpeedSign =
            std::signbit(localForwardSpeed) ? -1.0f : 1.0f;
        float longitudinalForce =
            driveTerm - forwardBrakeForce * forwardSpeedSign;

        // 0x7C667C..0x7C6737, then 0x7C6755's slope multiply. The terminal
        // speed correction runs on the braked force, not on the drive term.
        longitudinalForce =
            g_tuning->GetModel6SpeedLimitedAxialForce(
                longitudinalForce, localForwardSpeed,
                groundMaterial->speed);
        longitudinalForce *= axialSlopeAdherence;
        GmVec3 localDriveForce(0.0f, 0.0f, longitudinalForce);
        AddVehicleCentralForce(
            this, reinterpret_cast<CSceneVehicleCar*>(&localDriveForce), nullptr);
    } else {
        // Reverse selection, freewheeling, pre-existing wheel-slip blending,
        // state two, and the remaining special contacts still use the
        // translated fallback.
        ComputeForcesModel3(this, dt);
    }
    m_engineClutchBoost =
        engineStateKeepsClutchBoost || hasLateralOverLimit ? 1 : 0;
}

void CSceneVehicleCar::UpdateReverseState(const GmVec3& localLinearSpeed) {
    using namespace TmForeverPhysicsConstants;

    // 0x7C5A1E. Any burnout force state clears the flag and skips the rest.
    if (m_engineState != 0) {
        m_engine.m_isReverse = 0;
        return;
    }

    const float forwardSpeed = localLinearSpeed.z;
    const float lateralSpeed = std::abs(localLinearSpeed.x);
    const double gas = static_cast<double>(m_inputGas);
    const double brake = static_cast<double>(m_inputBrake);

    // 0x7C5A2A. Brake held, travelling slower than the engine's own ceiling,
    // and barely sliding sideways engages reverse. Every comparison here is
    // strict, and each one rejects an unordered operand, so a NaN speed leaves
    // the flag alone rather than engaging.
    if (brake > kInputThreshold &&
        forwardSpeed < m_engine.m_field_0x30 &&
        lateralSpeed < kReverseSpeedThreshold) {
        m_engine.m_isReverse = 1;
    }

    // 0x7C5A6D. Gas held while actually moving forward, or while sliding hard
    // enough sideways, cancels it again.
    if (gas > kInputThreshold &&
        (forwardSpeed > 0.0f || lateralSpeed > kReverseSpeedThreshold)) {
        m_engine.m_isReverse = 0;
    }

    // 0x7C5AA0. With neither pedal held the flag follows the direction of
    // travel, and only once the car is rolling backwards faster than the same
    // threshold. The executable's ordered tests put a NaN forward speed in the
    // reverse branch, which these comparisons reproduce.
    if (gas < kInputThreshold && brake < kInputThreshold) {
        if (forwardSpeed >= 0.0f) {
            m_engine.m_isReverse = 0;
        } else if (std::abs(forwardSpeed) < kReverseSpeedThreshold) {
            m_engine.m_isReverse = 0;
        } else {
            m_engine.m_isReverse = 1;
        }
    }

    // 0x7C5AF8. Moving forward with +0x600 set always clears.
    if (forwardSpeed > 0.0f && m_field_0x600 != 0) {
        m_engine.m_isReverse = 0;
    }
}

GmVec3 CSceneVehicleCar::GetModel6WheelLateralDirection(
    const SSimulationWheel* wheel, float processedSteer) const {
    if (wheel == nullptr) return GmVec3(1.0f, 0.0f, 0.0f);

    // 0x7C49E3 starts with groundNormal x +Z. With +Z fixed at (0,0,1),
    // this is (normal.y, -normal.x, 0). The native small-vector fallback is
    // +X; otherwise it normalizes using the shared wheel-direction epsilon.
    GmVec3 lateralDirection(
        wheel->m_groundContactNormalSum.y,
        -wheel->m_groundContactNormalSum.x,
        0.0f);
    const float squaredLength = GmVec3::Dot(
        lateralDirection, lateralDirection);
    if (squaredLength <=
        TmForeverPhysicsConstants::kWheelDirectionSquaredEpsilon) {
        lateralDirection = GmVec3(1.0f, 0.0f, 0.0f);
    } else {
        lateralDirection *= 1.0f / std::sqrt(squaredLength);
    }

    if (wheel->m_isSteerable != 0) {
        const float cosine = std::cos(processedSteer);
        const float negativeSine = -std::sin(processedSteer);
        lateralDirection.x *= cosine;
        lateralDirection.y *= cosine;
        lateralDirection.z =
            lateralDirection.z * cosine + negativeSine;
    }
    return lateralDirection;
}


void CSceneVehicleCar::WheelAddForceToVehicle(
    SSimulationWheel* wheel, float unusedForceModelScalar) {
    (void)unusedForceModelScalar;
    if (wheel == nullptr || g_tuning == nullptr ||
        wheel->m_hasGroundContact == 0) {
        return;
    }

    float suspensionForce = 0.0f;
    if (g_tuning->m_shockModel == 0) {
        suspensionForce =
            g_tuning->m_absorbingValKi *
            g_tuning->m_shockModel0ForceFactor *
            (g_tuning->m_absorbingValRest -
             wheel->m_realTimeState.m_compression);
    } else if (g_tuning->m_shockModel == 1 ||
               g_tuning->m_shockModel == 2) {
        suspensionForce =
            (g_tuning->m_absorbingValRest -
             wheel->m_realTimeState.m_compression) *
                g_tuning->m_absorbingValKi -
            g_tuning->m_absorbingValKa *
                wheel->m_realTimeState.m_velocity;
    } else {
        return;
    }
    wheel->m_suspensionForce = suspensionForce;

    GmVec3 localForce(0.0f, suspensionForce, 0.0f);
    AddVehicleForce(
        this, reinterpret_cast<CSceneVehicleCar*>(&localForce),
        &wheel->m_localContactPosition, nullptr);
}

void CSceneVehicleCar::AddVehicleTorque(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3) {
    if (this->m_hmsItem) {
        this->m_hmsItem->AddTorque(
            this->m_hmsItem, reinterpret_cast<GmVec3*>(param_2));
    }
}
void CSceneVehicleCar::SetVehicleAngularSpeed(GmVec3* localAngularSpeed) {
    if (this->m_hmsItem) {
        this->m_hmsItem->SetAngularSpeed(this->m_hmsItem, localAngularSpeed);
    }
}
void CSceneVehicleCar::AddVehicleCentralForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3) {
    if (this->m_hmsItem) {
        this->m_hmsItem->AddForce(
            this->m_hmsItem, reinterpret_cast<GmVec3*>(param_2), nullptr);
    }
}
void CSceneVehicleCar::AddVehicleForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3, GmVec3 *param_4) {
    if (this->m_hmsItem) {
        this->m_hmsItem->AddForce(
            this->m_hmsItem, reinterpret_cast<GmVec3*>(param_2), param_3);
    }
}
