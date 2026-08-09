#include "CSceneVehicleCarTuning.hpp"
#include "CFuncKeysReal.hpp"
#include "TmForeverPhysicsConstants.hpp"
#include "../TuningData.hpp"

#include <algorithm>
#include <cmath>

namespace {

CFuncKeysReal* SelectCurve(CFuncKeysReal* loadedCurve, CFuncKeysReal& extractedCurve) {
    return loadedCurve != nullptr ? loadedCurve : &extractedCurve;
}

} // namespace

float CSceneVehicleCarTuning::EvaluateCurve(struct CFuncKeysReal* curve, float x) {
    if (curve == nullptr) return 0.0f;

    const uint32_t count = std::min(curve->m_keys.m_count, curve->m_values.m_count);
    if (count == 0) return 0.0f;
    if (x <= curve->m_keys.m_data[0]) return curve->m_values.m_data[0];
    if (x >= curve->m_keys.m_data[count - 1]) return curve->m_values.m_data[count - 1];
    for (uint32_t i = 0; i < count - 1; ++i) {
        if (x >= curve->m_keys.m_data[i] && x <= curve->m_keys.m_data[i+1]) {
            float t = (x - curve->m_keys.m_data[i]) / (curve->m_keys.m_data[i+1] - curve->m_keys.m_data[i]);
            return curve->m_values.m_data[i] + t * (curve->m_values.m_data[i+1] - curve->m_values.m_data[i]);
        }
    }
    return 0.0f;
}

float CSceneVehicleCarTuning::GetLateralContactSlowDownFromSpeed(float speed) {
    return EvaluateCurve(SelectCurve(m_lateralContactSlowDown, LateralContactSlowDown),
                         speed * static_cast<float>(TmForeverPhysicsConstants::kSpeedCurveScale));
}

float CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(float speed) {
    return EvaluateCurve(SelectCurve(m_maxSideFriction, MaxSideFriction),
                         speed * static_cast<float>(TmForeverPhysicsConstants::kSpeedCurveScale));
}

float CSceneVehicleCarTuning::GetAccelFromSpeed(float speed) {
    return EvaluateCurve(&AccelCurve,
                         speed * static_cast<float>(TmForeverPhysicsConstants::kSpeedCurveScale));
}

float CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed(float speed) {
    return EvaluateCurve(SelectCurve(m_steerDriveTorque, SteerDriveTorque),
                         speed * static_cast<float>(TmForeverPhysicsConstants::kSpeedCurveScale));
}

float CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle(float angle) {
    return EvaluateCurve(&RolloverLateralFromAngle, angle);
}

float CSceneVehicleCarTuning::GetRolloverLateralFromSpeed(float speed) {
    return EvaluateCurve(&RolloverLateral,
                         speed * static_cast<float>(TmForeverPhysicsConstants::kSpeedCurveScale));
}

float CSceneVehicleCarTuning::GetSteerSlowDownFromSpeed(float speed) {
    return EvaluateCurve(SelectCurve(m_steerSlowDown, SteerSlowDown),
                         speed * static_cast<float>(TmForeverPhysicsConstants::kSpeedCurveScale));
}

float CSceneVehicleCarTuning::M5GetAccelFromSpeed(float speed) {
    // Fixed executable: this is the same +0x34 curve as GetAccelFromSpeed.
    return GetAccelFromSpeed(speed);
}

float CSceneVehicleCarTuning::M5GetLateralContactSlowDownFromSpeed(float speed) {
    // TmForeverFixed.exe 0x7F3F10 uses the same +0x68 curve as the legacy
    // helper, but calls the curve's direct-return entry point.
    return EvaluateCurve(SelectCurve(m_lateralContactSlowDown,
                                     LateralContactSlowDown),
                         speed * static_cast<float>(
                             TmForeverPhysicsConstants::kSpeedCurveScale));
}

float CSceneVehicleCarTuning::M5GetSlippingAccelFromSpeed(float speed) {
    return m_m5AccelSlipCoefMax *
           EvaluateCurve(&M5SlippingAccelCurve,
                         speed * static_cast<float>(TmForeverPhysicsConstants::kSpeedCurveScale));
}

float CSceneVehicleCarTuning::M5GetSteerSlowDownFromSpeed(float speed) {
    // Fixed executable: this is the same +0x78 curve as the Model3 getter.
    return GetSteerSlowDownFromSpeed(speed);
}

float CSceneVehicleCarTuning::M6GetRearGearAccelFromSpeed(float speed) {
    return EvaluateCurve(&AccelCurveRearGear,
                         speed * static_cast<float>(TmForeverPhysicsConstants::kSpeedCurveScale));
}

float CSceneVehicleCarTuning::GetWaterBumpSlowDownFromSpeedRatio(float ratio) {
    return EvaluateCurve(
        SelectCurve(m_waterBumpSlowDownFromSpeedRatio,
                    WaterBumpSlowDownFromSpeedRatio),
        ratio);
}

float CSceneVehicleCarTuning::GetWaterReboundFromSpeedRatio(float ratio) {
    return EvaluateCurve(
        SelectCurve(m_waterReboundFromSpeedRatio,
                    WaterReboundFromSpeedRatio),
        ratio);
}

float CSceneVehicleCarTuning::GetWaterFrictionFromSpeed(float speed) {
    // Fixed executable 0x7F3F40 applies the km/h conversion only to this
    // speed curve; the two rebound helpers consume an unscaled ratio.
    return EvaluateCurve(
        SelectCurve(m_waterFrictionFromSpeed, WaterFrictionFromSpeed),
        speed * static_cast<float>(
                    TmForeverPhysicsConstants::kSpeedCurveScale));
}

void CSceneVehicleCarTuning::M6InitRpmDeltas() {
    // Exact loop structure of TmForeverFixed.exe 0x7F4170. The first two
    // upshift deltas and both end downshift deltas remain zero.
    m_m6RpmDeltaOnGearUp.fill(0.0f);
    m_m6RpmDeltaOnGearDown.fill(0.0f);
    for (std::size_t gear = 2; gear < m_m6GearRatios.size(); ++gear) {
        const float ratio =
            m_m6GearRatios[gear] / m_m6GearRatios[gear - 1];
        m_m6RpmDeltaOnGearUp[gear] =
            m_m6RpmDeltaOnGearUp[gear - 1] * ratio +
            (m_m6RpmWantedOnGearUp[gear] -
             m_m6MaxRpmRatios[gear - 1] * ratio) *
                m_m6MaxRpm;
    }
    for (std::size_t gear = 1;
         gear + 1 < m_m6GearRatios.size(); ++gear) {
        if (m_m6MaxRpm == 0.0f) {
            m_m6RpmDeltaOnGearDown[gear] = 0.0f;
        } else {
            m_m6RpmDeltaOnGearDown[gear] =
                m_m6RpmDeltaOnGearUp[gear] / m_m6MaxRpm +
                (m_m6MinRpmRatios[gear + 1] -
                 m_m6RpmDeltaOnGearUp[gear + 1] / m_m6MaxRpm) *
                    m_m6GearRatios[gear] / m_m6GearRatios[gear + 1];
        }
    }
}

float CSceneVehicleCarTuning::GetModel6SteerSpeedFactor(float speed) const {
    // TmForeverFixed.exe 0x7C5C68..0x7C5CB8: the steering contribution ramps
    // as sin(pi/2 * speed/SteerLowSpeed), then remains one above that speed.
    const float absoluteSpeed = std::abs(speed);
    if (m_steerLowSpeed <= 0.0f || absoluteSpeed >= m_steerLowSpeed) return 1.0f;
    return std::sin(absoluteSpeed / m_steerLowSpeed *
                    static_cast<float>(TmForeverPhysicsConstants::kPi) * 0.5f);
}

float CSceneVehicleCarTuning::GetModel6SideForce(float rawForce, float maxForce) const {
    // Exact over-limit branch at 0x7C5D35..0x7C5DCA. The value at tuning
    // +0xE4 blends between the curve limit and the uncapped force; it is 1.0
    // for Stadium tuning 29, so exceeding the limit does not hard-clamp it.
    const float magnitude = std::abs(rawForce);
    if (magnitude <= maxForce) return rawForce;

    const float blendedMagnitude =
        maxForce * (1.0f - m_maxSideFrictionOverLimitBlend) +
        magnitude * m_maxSideFrictionOverLimitBlend;
    return std::signbit(rawForce) ? -blendedMagnitude : blendedMagnitude;
}

float CSceneVehicleCarTuning::GetYawInertia() const {
    // CPlugPhysicalObject::SetInertiaMatrixBox stores the inverse box tensor.
    // With half-extents h, Iy = mass/3 * (hx^2 + hz^2).
    return (m_inertiaMass / 3.0f) *
           (m_inertiaHalfDiagX * m_inertiaHalfDiagX +
            m_inertiaHalfDiagZ * m_inertiaHalfDiagZ);
}

CSceneVehicleCarTuning::CSceneVehicleCarTuning() : CMwNod() {
    m_steerSlowDown = nullptr;
    m_steerSlowDownFactor =
        TmForeverPhysicsConstants::kDefaultOldEngineSpeedDivisorBase;
    m_steerDriveTorqueFactor = 13.888889312744140625f;
    m_steerDriveTorque = nullptr;
    m_field_38 = 1;
    m_steerRadius = nullptr;
    m_steerSlowDown2 = nullptr;
    m_lateralContactSlowDown = nullptr;
    m_maxSideFriction = nullptr;
    m_mass = 1.0f;
    m_inertiaMass = 5.0f;
    m_inertiaHalfDiagX = 0.5f;
    m_inertiaHalfDiagY = 0.5f;
    m_inertiaHalfDiagZ = 1.0f;
    m_gravityCoef = 1.0f;
    m_gravityCoefAir = 1.0f;
    m_angularFluidFrictionCoef1 = 0.4f;
    // Native constructor offsets +0x58, +0x5C, and +0x1E8.
    m_groundSlowDownBase = 1.0f;
    m_linearFluidFrictionCoef = 0.0f;
    m_steerSpeed = 0.0f;
    m_steerModel = 0;
    m_steerLowSpeed = 0.0f;
    m_steerGroundTorque = 0.0f;
    m_steerGroundTorqueSlippingCoef = 1.0f;
    m_maxSideFrictionBlendCoef = 0.0f;
    m_maxSideFrictionSliding = 1.0f;
    m_sideFriction1 = 0.0f;
    m_maxSideFrictionOverLimitBlend = 1.0f;
    m_m5AccelSlipCoefMax = 1.0f;
    m_m5LateralConstantSlowDownDuration = 500u;
    m_shockModel = 0;
    m_absorbingValKi = 0.0f;
    m_absorbingValKa = 0.0f;
    m_absorbingValMin = 0.0f;
    m_absorbingValRest = 0.0f;
    m_shockModel0ForceFactor =
        TmForeverPhysicsConstants::kDefaultShockModel0ForceFactor;
    m_absorbTension = 0.0f;
    // Native constructor offsets +0x170..+0x18C and the impulse controls at
    // +0xE8/+0xEC/+0x14C/+0x150.
    m_bodyFrictionCoef = 0.800000011920928955078125f;
    m_bodyFrictionCoefMetal = 0.4000000059604644775390625f;
    m_bodyRestCoefMetal = 0.0f;
    m_bodyRestCoef = 0.0f;
    m_wheelFrictionCoefConcrete = 0.800000011920928955078125f;
    m_wheelRestCoefConcrete = 0.0f;
    m_wheelFrictionCoefMetal = 0.4000000059604644775390625f;
    m_wheelRestCoefMetal = 0.0f;
    m_angularSpeedYImpulseScale = 1.0f;
    m_angularImpulseScale = 1.0f;
    m_angularSpeedClamp = 100.0f;
    m_linearSpeedSquaredPositiveDeltaMax = 10000.0f;
    m_lateralSlopeAdherenceMin = 0.0f;
    m_lateralSlopeAdherenceMax = 0.0f;
    m_axialSlopeAdherenceMin = 0.0f;
    m_axialSlopeAdherenceMax = 0.0f;
    // Exact constructor writes at native tuning +0x204..+0x220.
    m_waterGravity = 1.0f;
    m_waterReboundMinHorizontalSpeed =
        TmForeverPhysicsConstants::kDefaultOldEngineSpeedDivisorBase;
    m_waterBumpMinSpeed = 50.0f;
    m_waterBumpSlowDownFromSpeedRatio = nullptr;
    m_waterReboundFromSpeedRatio = nullptr;
    m_waterFrictionFromSpeed = nullptr;
    m_waterAngularFriction = 0.100000001490116119140625f;
    m_waterAngularFrictionSq =
        TmForeverPhysicsConstants::kDefaultWaterAngularFrictionSq;
    m_m6MaxRpm = 0.800000011920928955078125f;
    m_m6GearRatios = {4.0f, 2.0f, 1.0f, 0.800000011920928955078125f,
                      0.5f, 0.300000011920928955078125f};
    m_m6MaxRpmRatios = {0.0f, 0.8125f, 0.8125f, 0.8125f, 0.8125f, 1.0f};
    m_m6MinRpmRatios = {0.0f, 0.0f, 0.375f, 0.53125f, 0.5625f, 0.625f};
    m_m6RpmWantedOnGearUp = {0.0f, 0.0f, 0.42850005626678466796875f,
                             0.333000004291534423828125f, 0.25f,
                             0.16600000858306884765625f};
    m_m6RpmDeltaOnGearUp.fill(0.0f);
    m_m6RpmDeltaOnGearDown.fill(0.0f);
    m_m6BurnoutRpmAcceleration = 5000.0f;
    m_m6AirRpmAcceleration = 5000.0f;
    m_m6AirRpmDeadening = 2500.0f;
    m_m6RpmLossOnGearUp = 5000.0f;
    m_m6RpmGainOnGearDown = 10000.0f;
    m_m6RpmGainOnTakeoff = 10000.0f;
    m_m6RpmLossOnTakeoffFinished = 4000.0f;
    m_m6PositiveTakeoffFrontSpeed = 3.0f;
    m_m6PositiveTakeoffRearSpeed = 2.0f;
    m_m6NegativeTakeoffFrontSpeed = -2.0f;
    m_m6NegativeTakeoffRearSpeed = -3.0f;
    M6InitRpmDeltas();
}

CSceneVehicleCarTuning::~CSceneVehicleCarTuning() {}

CMwNod* CSceneVehicleCarTuning::MwNewCSceneVehicleCarTuning() { return new CSceneVehicleCarTuning(); }
uint32_t CSceneVehicleCarTuning::GetMwClassId() { return 0x0601E000; }

void CSceneVehicleCarTuning::Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3) {}
