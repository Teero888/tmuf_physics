#include "CSceneVehicleCarTuning.hpp"
#include "CFuncKeysReal.hpp"
#include "GmFunc.hpp"
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
    // CFuncKeys::GetBoundingIndices (0x5914C0) returns the bracketing pair, and
    // collapses both indices onto the same key when x lands exactly on one. So
    // the lower index is the greatest key at or below x, not the first bracket
    // a scan happens to accept: at an exact key the two differ.
    uint32_t lower = 0;
    for (uint32_t i = 0; i + 1 < count; ++i) {
        if (curve->m_keys.m_data[i] <= x) lower = i;
    }

    // 0x585E70 picks its evaluator from the curve's own RealInterp mode before
    // touching the keys. Mode 1 is the stepped one: 0x585EE8 loads
    // values[lower] and stores it unblended. Only the other modes reach the
    // interpolating tail at 0x585EBE. Stadium's AccelCurve is the stepped
    // kind, which is why the car pulls a flat 16 m/s^2 all the way to
    // 101 km/h instead of decaying toward 11.
    if (curve->m_realInterp == CFuncKeysReal::kStepped) {
        return curve->m_values.m_data[lower];
    }

    const float span =
        curve->m_keys.m_data[lower + 1] - curve->m_keys.m_data[lower];
    const float t = (x - curve->m_keys.m_data[lower]) / span;
    return curve->m_values.m_data[lower] +
           t * (curve->m_values.m_data[lower + 1] -
                curve->m_values.m_data[lower]);
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
    return m_m5SlippingAccelCurveCoef *
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

float CSceneVehicleCarTuning::M6GetModulationFromDamperAbsorbVal(
    float absorbValue) {
    // TmForeverFixed.exe 0x7F3F80 normalizes the damper value so AbsorbingValMax
    // maps to zero and AbsorbingValMin maps to one before evaluating tuning
    // +0x224 (ModulationFromWheelCompression).
    float ratio = 0.0f;
    if (m_absorbingValMax != m_absorbingValMin) {
        ratio = (absorbValue - m_absorbingValMax) /
                (m_absorbingValMin - m_absorbingValMax);
    }
    return EvaluateCurve(
        SelectCurve(m_modulationFromWheelCompression,
                    ModulationFromWheelCompression),
        ratio);
}

float CSceneVehicleCarTuning::GetModel6ProcessedSteer(
    float smoothedSteer, float forwardSpeed) const {
    // TmForeverFixed.exe 0x7C6CB2..0x7C6D33. The local-speed vector begins at
    // stack +0x3C, so +0x44 is its forward (Z) component. Native x87 code
    // rounds the denominator to float before the comparison and safe arcsine.
    const float absoluteForwardSpeed = std::abs(forwardSpeed);
    const float denominator =
        m_steerRadiusMin + absoluteForwardSpeed * m_steerRadiusCoef;

    // `test ah, 5; jp` selects the reciprocal/safe-arcsine path for values at
    // or above epsilon and for unordered comparisons. Consequently only an
    // ordered value strictly below epsilon produces zero; NaNs propagate.
    if (denominator < TmForeverPhysicsConstants::kWheelInputEpsilon) {
        return 0.0f;
    }
    return -smoothedSteer * GmFunc::AsinSafe(1.0f / denominator);
}

float CSceneVehicleCarTuning::GetModel6WheelSideForce(
    float rawForce, float maxForce) const {
    // TmForeverFixed.exe 0x7C4F5F..0x7C4FD1: a wheel enters the slipping state
    // only above its per-wheel limit. Above the limit, tuning +0xB4 blends the
    // signed limit with the uncapped force.
    if (std::abs(rawForce) <= maxForce) return rawForce;
    const float signedLimit = std::signbit(rawForce) ? -maxForce : maxForce;
    return signedLimit * (1.0f - m_maxSideFrictionBlendCoef) +
           rawForce * m_maxSideFrictionBlendCoef;
}

float CSceneVehicleCarTuning::GetModel6SpeedLimitedAxialForce(
    float axialForce, float forwardSpeed, float materialSpeed) const {
    // TmForeverFixed.exe 0x7C667C..0x7C6737. Both terminal-speed comparisons
    // are strict. Once the forward limit is exceeded, a nonnegative force is
    // replaced by the negative correction; an already-negative force receives
    // an additional correction. The reverse branch is the sign mirror.
    if (m_maxSpeed * materialSpeed < forwardSpeed) {
        axialForce = axialForce < 0.0f
            ? axialForce - m_limitToMaxSpeedForce
            : -m_limitToMaxSpeedForce;
    }

    if (forwardSpeed < -m_reverseMaxSpeed * materialSpeed) {
        axialForce = axialForce > 0.0f
            ? axialForce + m_limitToMaxSpeedForce
            : m_limitToMaxSpeedForce;
    }
    return axialForce;
}

float CSceneVehicleCarTuning::GetModel6ForwardAxialBrakeForce(
    float forwardSpeed, float brakeInput, float materialBrakeCoef,
    float slippingModulation, bool hasSlippingWheel,
    bool* saturated) const {
    if (saturated != nullptr) *saturated = false;

    // TmForeverFixed.exe 0x7C6321..0x7C6461. Forward braking exists only for
    // an ordered speed above zero. Tuning +0x40/+0x44 forms the requested
    // speed-dependent force; +0x48/+0x4C selects the material-scaled cap from
    // the pre-braking slipping output. Saturation is strict and marks every
    // simulation wheel as slipping in the caller.
    if (!(0.0f < forwardSpeed)) return 0.0f;

    const float requestedForce =
        (m_brakeBase + m_brakeCoef * forwardSpeed) *
        brakeInput * slippingModulation;
    const float maximumForce =
        (hasSlippingWheel ? m_brakeMax : m_brakeMaxDynamic) *
        materialBrakeCoef;
    if (maximumForce < requestedForce) {
        if (saturated != nullptr) *saturated = true;
        return maximumForce;
    }
    return requestedForce;
}

float CSceneVehicleCarTuning::GetAirControlZCoefFromAngularSpeed(
    float angularSpeed) {
    return EvaluateCurve(
        SelectCurve(m_airControlZCoefFromAngularSpeed,
                    AirControlZCoefFromAngularSpeed),
        angularSpeed);
}

float CSceneVehicleCarTuning::GetModel6BackwardAxialBrakeForce(
    float forwardSpeed, float gasInput, float materialBrakeCoef,
    float slippingModulation, bool hasSlippingWheel,
    bool* saturated) const {
    if (saturated != nullptr) *saturated = false;

    // TmForeverFixed.exe 0x7C64FF..0x7C662F, the mirror of the forward block
    // at 0x7C638B. While the car rolls backwards the *gas* pedal is what slows
    // it, so 0x7C6590 multiplies by car +0x50 rather than +0x54, and the sign
    // of the speed term flips: 0x7C658E subtracts BrakeCoef * speed.z from
    // BrakeBase, which grows with the backward speed because that speed is
    // negative. The saturation cap also changes, to the Model-6 rear values at
    // tuning +0x248/+0x24C instead of the +0x48/+0x4C pair.
    if (!(forwardSpeed < 0.0f)) return 0.0f;

    const float requestedForce =
        (m_brakeBase - m_brakeCoef * forwardSpeed) *
        gasInput * slippingModulation;
    const float maximumForce =
        materialBrakeCoef *
        (hasSlippingWheel ? m_m6BrakeMaxRear : m_m6BrakeMaxDynamicRear);
    if (maximumForce < requestedForce) {
        if (saturated != nullptr) *saturated = true;
        return maximumForce;
    }
    return requestedForce;
}

float CSceneVehicleCarTuning::GetModel6AccelerationBlendFromLateralOverLimit(
    float appliedForceSum, float maximumForceSum) const {
    // TmForeverFixed.exe 0x7C5F36..0x7C5FB4. Tuning +0x200 scales the
    // relative excess above the accumulated side-force limit. Native code
    // clamps that excess to [0, 1] and subtracts it from the normal-curve
    // weight; a zero/near-zero maximum bypasses this block in the caller.
    const float excessRatio =
        ((appliedForceSum - maximumForceSum) / maximumForceSum) /
        m_m5AccelSlipCoefMax;
    return 1.0f - std::clamp(excessRatio, 0.0f, 1.0f);
}

float CSceneVehicleCarTuning::GetModel6EngineStateAccelerationModulation(
    int engineState, uint32_t elapsedMilliseconds) const {
    // TmForeverFixed.exe 0x7C60A5..0x7C61E0. Both timed phases store the
    // millisecond ratio as float before evaluating sin(pi * ratio), then
    // interpolate from one to the phase's configured acceleration factor.
    uint32_t duration = 0u;
    float modulation = 1.0f;
    if (engineState == 1) {
        duration = m_m6BurnoutDuration;
        modulation = m_m6BurnoutAccelerationModulation;
    } else if (engineState == 3) {
        duration = m_m6AfterBurnoutDuration;
        modulation = m_m6AfterBurnoutAccelerationModulation;
    } else {
        return 1.0f;
    }
    if (duration == 0u) return 1.0f;

    constexpr double kNativePhasePi = 3.1415927410125732421875;
    const float phase = static_cast<float>(
        static_cast<double>(elapsedMilliseconds) * kNativePhasePi /
        static_cast<double>(duration));
    return 1.0f + (modulation - 1.0f) * std::sin(phase);
}

float CSceneVehicleCarTuning::GetModel6EngineStateAxialImpulse(
    int engineState, uint32_t elapsedMilliseconds) const {
    // 0x7C61E9..0x7C623A performs an unsigned integer cycle division, shifts
    // the quotient by one, squares it, and scales +0x2B8. The state-3
    // lifetime gate normally keeps the quotient at zero, yielding the loaded
    // after-burnout impulse throughout that phase.
    if (engineState != 3 || m_m6AfterBurnoutDuration == 0u) return 0.0f;
    const uint32_t cycle =
        elapsedMilliseconds / m_m6AfterBurnoutDuration;
    const float centeredCycle = static_cast<float>(cycle) - 1.0f;
    return centeredCycle * centeredCycle * m_m6AfterBurnoutImpulse;
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
    m_centerOfMassAftFactor = 0.0f;
    m_centerOfMassVerticalOffset = 0.0f;
    m_gravityCoef = 1.0f;
    m_maxDistancePerStep =
        TmForeverPhysicsConstants::kDefaultVehicleMaxDistancePerStep;
    m_gravityCoefAir = 1.0f;
    m_angularFluidFrictionCoef1 = 0.4f;
    // Native constructor offsets +0x58, +0x5C, and +0x1E8.
    m_groundSlowDownBase = 1.0f;
    m_groundSlowDownCoef = 0.0f;
    m_angularFluidFrictionCoef2 = 0.0f;
    m_airControlDuration = 0u;
    m_maxAngularSpeedYAirControl = 0.0f;
    m_airControlZCoefFromAngularSpeed = nullptr;
    m_linearFluidFrictionCoef = 0.0f;
    // Native constructor 0x7F1C88: +0x2C/+0x30 use the base forward/reverse
    // speeds, while +0x60 is initialized from .rdata 0x00B36194 (10.0f).
    m_maxSpeed =
        TmForeverPhysicsConstants::kDefaultOldEngineSpeedDivisorBase;
    m_reverseMaxSpeed = 13.888889312744140625f;
    m_limitToMaxSpeedForce = 10.0f;
    // Native constructor values at +0x40..+0x4C.
    m_brakeBase = 20.0f;
    m_brakeCoef = 0.0f;
    m_brakeMax = 500.0f;
    m_brakeMaxDynamic = 500.0f;
    // Exact native constructor writes at tuning +0x6C and +0x70.
    m_steerRadiusMin = 1.0f;
    m_steerRadiusCoef = 0.5f;
    m_steerSpeed = 0.0f;
    m_steerModel = 0;
    m_steerLowSpeed = 0.0f;
    m_steerGroundTorque = 0.0f;
    m_steerGroundTorqueSlippingCoef = 1.0f;
    m_maxSideFrictionBlendCoef = 0.0f;
    m_maxSideFrictionSliding = 1.0f;
    m_sideFriction1 = 0.0f;
    m_maxSideFrictionOverLimitBlend = 1.0f;
    // +0x1E4 scales M5SlippingAccelCurve; +0x200 controls Model6's
    // over-limit interpolation back toward that slipping curve.
    m_m5SlippingAccelCurveCoef = 1.0f;
    m_m5AccelSlipCoefMax = 1.0f;
    m_m5LateralConstantSlowDownDuration = 500u;
    m_shockModel = 0;
    m_absorbingValKi = 0.0f;
    m_absorbingValKa = 0.0f;
    m_absorbingValMin = 0.0f;
    m_absorbingValMax = 0.0f;
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
    m_modulationFromWheelCompression = nullptr;
    // Native Model6 brake block defaults at +0x240/+0x244/+0x248/+0x24C.
    m_m6BrakeModulationWhenSlipping = 0.5f;
    m_m6FrictionModulationWhenSlipAndBrake = 1.0f;
    m_m6BrakeMaxRear = 100.0f;
    m_m6BrakeMaxDynamicRear = 50.0f;
    // Native +0x298/+0x29C/+0x2A8/+0x2AC/+0x2B8 defaults. These are also
    // the values present in the older generic vehicle tunings.
    m_m6BurnoutDuration = 1000u;
    m_m6BurnoutAccelerationModulation = 0.5f;
    m_m6AfterBurnoutDuration = 500u;
    m_m6AfterBurnoutAccelerationModulation = 4.0f;
    m_m6AfterBurnoutImpulse = 10.0f;
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
