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
    m_steerDriveTorque = nullptr;
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
    m_shockModel = 0;
    m_absorbingValKi = 0.0f;
    m_absorbingValKa = 0.0f;
    m_absorbingValRest = 0.0f;
    m_absorbTension = 0.0f;
    m_lateralSlopeAdherenceMin = 0.0f;
    m_lateralSlopeAdherenceMax = 0.0f;
    m_axialSlopeAdherenceMin = 0.0f;
    m_axialSlopeAdherenceMax = 0.0f;
}

CSceneVehicleCarTuning::~CSceneVehicleCarTuning() {}

CMwNod* CSceneVehicleCarTuning::MwNewCSceneVehicleCarTuning() { return new CSceneVehicleCarTuning(); }
uint32_t CSceneVehicleCarTuning::GetMwClassId() { return 0x0601E000; }

void CSceneVehicleCarTuning::Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3) {}
