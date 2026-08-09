#pragma once
#include "Scene/CSceneVehicleCarTuning.hpp"
#include "Plug/CFuncKeysReal.hpp"

// We use CFastArray directly.
inline void InitCurve(CFuncKeysReal& curve, int count, float* times, float* values) {
    curve.m_keys.SetCount(count);
    curve.m_values.SetCount(count);
    for (int i = 0; i < count; ++i) {
        curve.m_keys.m_data[i] = times[i];
        curve.m_values.m_data[i] = values[i];
    }
}

inline float AccelCurve_times[] = { -1000.0f, -102.0f, -80.0f, -35.0f, 0.0f, 101.0f, 201.0f, 401.0f, 801.0f };
inline float AccelCurve_values[] = { 1.0f, 2.0f, 6.0f, 12.0f, 16.0f, 11.0f, 7.0f, 5.5f, 1.0f };
inline CFuncKeysReal AccelCurve;

inline float MaxSideFriction_times[] = { 0.0f, 100.0f, 200.0f, 300.0f, 400.0f, 500.0f };
inline float MaxSideFriction_values[] = { 80.0f, 80.0f, 75.0f, 67.0f, 60.0f, 55.0f };
inline CFuncKeysReal MaxSideFriction;

inline float RolloverLateral_times[] = { 0.0f };
inline float RolloverLateral_values[] = { 0.0f };
inline CFuncKeysReal RolloverLateral;

inline float LateralContactSlowDown_times[] = { 0.0f, 50.0f, 100.0f, 200.0f, 400.0f };
inline float LateralContactSlowDown_values[] = { 0.0f, 12.0f, 24.0f, 48.0f, 70.0f };
inline CFuncKeysReal LateralContactSlowDown;

inline float SteerSlowDown_times[] = { -50.0f, 0.0f, 50.0f, 100.0f, 200.0f, 300.0f };
inline float SteerSlowDown_values[] = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
inline CFuncKeysReal SteerSlowDown;

inline float RolloverLateralFromAngle_times[] = { 0.0f, 0.4f, 0.8f, 1.0f };
inline float RolloverLateralFromAngle_values[] = { 0.0f, 0.4f, 0.8f, 1.0f };
inline CFuncKeysReal RolloverLateralFromAngle;

inline float SteerDriveTorque_times[] = { -100.0f, 0.0f, 50.0f, 100.0f, 150.0f, 200.0f, 300.0f, 400.0f, 500.0f, 600.0f };
inline float SteerDriveTorque_values[] = { 7.0f, 16.0f, 10.4f, 8.5f, 6.8f, 5.5f, 4.25f, 4.0f, 3.75f, 3.75f };
inline CFuncKeysReal SteerDriveTorque;

inline float M4SteerRadiusFromSpeed_times[] = { 0.0f, 100.0f };
inline float M4SteerRadiusFromSpeed_values[] = { 10.0f, 20.0f };
inline CFuncKeysReal M4SteerRadiusFromSpeed;

inline float M4MaxFrictionTorqueFromSpeed_times[] = { 0.0f };
inline float M4MaxFrictionTorqueFromSpeed_values[] = { 100.0f };
inline CFuncKeysReal M4MaxFrictionTorqueFromSpeed;

inline float M4MaxFrictionForceFromSpeed_times[] = { 0.0f };
inline float M4MaxFrictionForceFromSpeed_values[] = { 40.0f };
inline CFuncKeysReal M4MaxFrictionForceFromSpeed;

inline float M5SlippingAccelCurve_times[] = { 0.0f };
inline float M5SlippingAccelCurve_values[] = { 10.0f };
inline CFuncKeysReal M5SlippingAccelCurve;

inline float M5SteerCoefFromSpeed_times[] = { 0.0f };
inline float M5SteerCoefFromSpeed_values[] = { 1.0f };
inline CFuncKeysReal M5SteerCoefFromSpeed;

inline float M5SmoothInputSteerDurationFromSpeed_times[] = { 0.0f };
inline float M5SmoothInputSteerDurationFromSpeed_values[] = { 0.0f };
inline CFuncKeysReal M5SmoothInputSteerDurationFromSpeed;

inline float WaterBumpSlowDownFromSpeedRatio_times[] = { 0.0f, 0.4f, 0.5f, 1.0f };
inline float WaterBumpSlowDownFromSpeedRatio_values[] = { 0.7f, 0.7f, 0.6f, 0.6f };
inline CFuncKeysReal WaterBumpSlowDownFromSpeedRatio;

inline float WaterFrictionFromSpeed_times[] = { 0.0f, 2.0f, 50.0f };
inline float WaterFrictionFromSpeed_values[] = { 0.0f, 0.2f, 1.0f };
inline CFuncKeysReal WaterFrictionFromSpeed;

inline float WaterReboundFromSpeedRatio_times[] = { 0.0f, 0.4f, 0.5f, 1.0f };
inline float WaterReboundFromSpeedRatio_values[] = { 0.9f, 0.9f, 1.5f, 1.5f };
inline CFuncKeysReal WaterReboundFromSpeedRatio;

inline float ModulationFromWheelCompression_times[] = { 0.0f, 0.6f, 0.975f, 1.0f };
inline float ModulationFromWheelCompression_values[] = { 0.1f, 0.3f, 1.0f, 1.0f };
inline CFuncKeysReal ModulationFromWheelCompression;

inline float M6BurnoutRadius_times[] = { 0.0f, 5.0f, 10.0f };
inline float M6BurnoutRadius_values[] = { 1.0f, 2.0f, 3.0f };
inline CFuncKeysReal M6BurnoutRadius;

inline float M6RolloverLateralFromSpeedRatio_times[] = { 0.0f, 1.0f, 10.0f, 20.0f, 30.0f };
inline float M6RolloverLateralFromSpeedRatio_values[] = { 0.0f, 0.8f, 1.0f, 1.0f, 1.0f };
inline CFuncKeysReal M6RolloverLateralFromSpeedRatio;

inline float BrakeHeatSpeedFromFBrake_times[] = { 0.0f, 20.0f };
inline float BrakeHeatSpeedFromFBrake_values[] = { 0.0f, 1.0f };
inline CFuncKeysReal BrakeHeatSpeedFromFBrake;

inline float AccelCurveRearGear_times[] = { -150.0f, -100.0f, -50.0f, 0.0f };
inline float AccelCurveRearGear_values[] = { 0.1f, 1.5f, 8.0f, 30.0f };
inline CFuncKeysReal AccelCurveRearGear;

inline float M6BurnoutLateralSpeed_times[] = { 0.0f, 1.0f, 10.0f };
inline float M6BurnoutLateralSpeed_values[] = { 0.0f, 30.0f, 30.0f };
inline CFuncKeysReal M6BurnoutLateralSpeed;

inline float M6BurnoutRolloverFromSpeed_times[] = { 0.0f, 10.0f, 50.0f };
inline float M6BurnoutRolloverFromSpeed_values[] = { 1.5f, 1.2f, 0.2f };
inline CFuncKeysReal M6BurnoutRolloverFromSpeed;

inline float M6DonutRolloverFromSpeed_times[] = { 0.0f, 10.0f, 20.0f };
inline float M6DonutRolloverFromSpeed_values[] = { 0.0f, 5.0f, 6.0f };
inline CFuncKeysReal M6DonutRolloverFromSpeed;

inline float AirControlZCoefFromAngularSpeed_times[] = { 0.0f };
inline float AirControlZCoefFromAngularSpeed_values[] = { 1.0f };
inline CFuncKeysReal AirControlZCoefFromAngularSpeed;

inline float VisualSteerAngleFromSpeed_times[] = { 0.0f, 100.0f };
inline float VisualSteerAngleFromSpeed_values[] = { 30.0f, 10.0f };
inline CFuncKeysReal VisualSteerAngleFromSpeed;

// Stadium tuning 29 ("20juin2006") scalar values, read from the original
// StadiumCar.VehicleTunings.Gbx. Keep these in the file's native units.
inline constexpr float StadiumMass = 1.0f;
inline constexpr float StadiumInertiaMass = 5.0f;
inline constexpr float StadiumInertiaHalfDiagX = 0.5f;
inline constexpr float StadiumInertiaHalfDiagY = 0.5f;
inline constexpr float StadiumInertiaHalfDiagZ = 1.0f;
inline constexpr float StadiumGravityCoef = 3.0f;
inline constexpr float StadiumGravityCoefAir = 2.5f;
inline constexpr float StadiumAngularFluidFrictionCoef1 = 0.4f;
inline constexpr float StadiumGroundSlowDownBase = 1.0f;
inline constexpr float StadiumLinearFluidFrictionCoef = 0.03f;
inline constexpr float StadiumMaxSpeed = 277.777801513671875f;
inline constexpr float StadiumReverseMaxSpeed = 138.611114501953125f;
inline constexpr float StadiumLimitToMaxSpeedForce = 10.0f;
inline constexpr float StadiumBrakeBase = 1.0f;
inline constexpr float StadiumBrakeCoef = 1.75f;
inline constexpr float StadiumBrakeMax = 60.0f;
inline constexpr float StadiumBrakeMaxDynamic = 30.0f;
inline constexpr float StadiumSteerRadiusMin = 2.0f;
inline constexpr float StadiumSteerRadiusCoef = 0.85f;
inline constexpr float StadiumSteerSpeed = 20.0f;
inline constexpr int StadiumSteerModel = 5; // Steer06
inline constexpr float StadiumSteerLowSpeed = 30.0f;
inline constexpr float StadiumSteerGroundTorque = 0.08f;
inline constexpr float StadiumSteerGroundTorqueSlippingCoef = 1.0f;
inline constexpr float StadiumMaxSideFrictionBlendCoef = 0.018f;
inline constexpr float MaxSideFrictionSliding = 0.35f;
inline constexpr float StadiumSideFriction1 = 40.0f;
inline constexpr float StadiumMaxSideFrictionOverLimitBlend = 1.0f;
inline constexpr float StadiumM5SlippingAccelCurveCoef = 1.0f;
inline constexpr float StadiumM5AccelSlipCoefMax = 1.0f;
inline constexpr uint32_t StadiumM5LateralConstantSlowDownDuration = 500u;
inline constexpr int StadiumShockModel = 2; // Demo03
inline constexpr float StadiumAbsorbingValKi = 40.0f;
inline constexpr float StadiumAbsorbingValKa = 1.0f;
inline constexpr float StadiumAbsorbingValMin = 0.0f;
inline constexpr float StadiumAbsorbingValMax = 0.7f;
inline constexpr float StadiumAbsorbingValRest = 0.2f;
inline constexpr float StadiumAbsorbTension = 5.0f;
inline constexpr float StadiumBodyFrictionCoef = 0.3f;
inline constexpr float StadiumBodyFrictionCoefMetal = 0.2f;
inline constexpr float StadiumBodyRestCoefMetal = -0.5f;
inline constexpr float StadiumBodyRestCoef = -0.5f;
inline constexpr float StadiumWheelFrictionCoefConcrete = 0.0f;
inline constexpr float StadiumWheelRestCoefConcrete = -0.8f;
inline constexpr float StadiumWheelFrictionCoefMetal = 0.0f;
inline constexpr float StadiumWheelRestCoefMetal = -0.8f;
inline constexpr float StadiumAngularSpeedYImpulseScale = 0.55f;
inline constexpr float StadiumAngularImpulseScale = 1.0f;
inline constexpr float StadiumAngularSpeedClamp = 100.0f;
inline constexpr float StadiumLinearSpeedSquaredPositiveDeltaMax = 10000.0f;
inline constexpr float StadiumLateralSlopeAdherenceMin = 0.3f;
inline constexpr float StadiumLateralSlopeAdherenceMax = 0.7f;
inline constexpr float StadiumAxialSlopeAdherenceMin = 0.4f;
inline constexpr float StadiumAxialSlopeAdherenceMax = 0.7f;
inline constexpr float StadiumM6FrictionModulationWhenSlipAndBrake = 0.2f;
inline constexpr float StadiumM6BrakeModulationWhenSlipping = 0.5f;
inline constexpr float StadiumM6BrakeMaxRear = 100.0f;
inline constexpr float StadiumM6BrakeMaxDynamicRear = 50.0f;
inline constexpr uint32_t StadiumM6BurnoutDuration = 500u;
inline constexpr float StadiumM6BurnoutAccelerationModulation = 0.5f;
inline constexpr uint32_t StadiumM6AfterBurnoutDuration = 150u;
inline constexpr float StadiumM6AfterBurnoutAccelerationModulation = 1.0f;
inline constexpr float StadiumM6AfterBurnoutImpulse = 0.0f;
inline constexpr float StadiumWaterGravity = 1.0f;
inline constexpr float StadiumWaterReboundMinHorizontalSpeed =
    55.5555572509765625f;
inline constexpr float StadiumWaterBumpMinSpeed = 50.0f;
inline constexpr float StadiumWaterAngularFriction =
    0.100000001490116119140625f;
inline constexpr float StadiumWaterAngularFrictionSq =
    0.20000000298023223876953125f;
inline constexpr float StadiumM6MaxRpm = 11000.0f;
inline constexpr std::array<float, 6> StadiumM6GearRatios = {
    400.0f, 370.0f, 220.0f, 160.0f, 110.0f, 85.0f};
inline constexpr std::array<float, 6> StadiumM6MaxRpmRatios = {
    0.0f, 0.95f, 0.9f, 0.95f, 0.95f, 1.0f};
inline constexpr std::array<float, 6> StadiumM6MinRpmRatios = {
    0.0f, 0.0f, 0.5f, 0.57f, 0.55f, 0.6f};
inline constexpr std::array<float, 6> StadiumM6RpmWantedOnGearUp = {
    0.0f, 0.0f, 0.628f, 0.7f, 0.7f, 0.72f};
inline constexpr float StadiumM6BurnoutRpmAcceleration = 6000.0f;
inline constexpr float StadiumM6AirRpmAcceleration = 6000.0f;
inline constexpr float StadiumM6AirRpmDeadening = 3000.0f;
inline constexpr float StadiumM6RpmLossOnGearUp = 17000.0f;
inline constexpr float StadiumM6RpmGainOnGearDown = 11500.0f;
inline constexpr float StadiumM6RpmGainOnTakeoff = 10000.0f;
inline constexpr float StadiumM6RpmLossOnTakeoffFinished = 4000.0f;
inline constexpr float StadiumM6PositiveTakeoffFrontSpeed = 3.0f;
inline constexpr float StadiumM6PositiveTakeoffRearSpeed = 2.0f;
inline constexpr float StadiumM6NegativeTakeoffFrontSpeed = -2.0f;
inline constexpr float StadiumM6NegativeTakeoffRearSpeed = -3.0f;

static float g_dummy_wheel_tuning[256];

inline void InitTuningData(CSceneVehicleCarTuning* tuning) {
    InitCurve(AccelCurve, 9, AccelCurve_times, AccelCurve_values);
    InitCurve(MaxSideFriction, 6, MaxSideFriction_times, MaxSideFriction_values);
    InitCurve(RolloverLateral, 1, RolloverLateral_times, RolloverLateral_values);
    InitCurve(LateralContactSlowDown, 5, LateralContactSlowDown_times, LateralContactSlowDown_values);
    InitCurve(SteerSlowDown, 6, SteerSlowDown_times, SteerSlowDown_values);
    InitCurve(RolloverLateralFromAngle, 4, RolloverLateralFromAngle_times, RolloverLateralFromAngle_values);
    InitCurve(SteerDriveTorque, 10, SteerDriveTorque_times, SteerDriveTorque_values);
    InitCurve(M4SteerRadiusFromSpeed, 2, M4SteerRadiusFromSpeed_times, M4SteerRadiusFromSpeed_values);
    InitCurve(M4MaxFrictionTorqueFromSpeed, 1, M4MaxFrictionTorqueFromSpeed_times, M4MaxFrictionTorqueFromSpeed_values);
    InitCurve(M4MaxFrictionForceFromSpeed, 1, M4MaxFrictionForceFromSpeed_times, M4MaxFrictionForceFromSpeed_values);
    InitCurve(M5SlippingAccelCurve, 1, M5SlippingAccelCurve_times, M5SlippingAccelCurve_values);
    InitCurve(M5SteerCoefFromSpeed, 1, M5SteerCoefFromSpeed_times, M5SteerCoefFromSpeed_values);
    InitCurve(M5SmoothInputSteerDurationFromSpeed, 1, M5SmoothInputSteerDurationFromSpeed_times, M5SmoothInputSteerDurationFromSpeed_values);
    InitCurve(WaterBumpSlowDownFromSpeedRatio, 4, WaterBumpSlowDownFromSpeedRatio_times, WaterBumpSlowDownFromSpeedRatio_values);
    InitCurve(WaterFrictionFromSpeed, 3, WaterFrictionFromSpeed_times, WaterFrictionFromSpeed_values);
    InitCurve(WaterReboundFromSpeedRatio, 4, WaterReboundFromSpeedRatio_times, WaterReboundFromSpeedRatio_values);
    InitCurve(ModulationFromWheelCompression, 4, ModulationFromWheelCompression_times, ModulationFromWheelCompression_values);
    InitCurve(M6BurnoutRadius, 3, M6BurnoutRadius_times, M6BurnoutRadius_values);
    InitCurve(M6RolloverLateralFromSpeedRatio, 5, M6RolloverLateralFromSpeedRatio_times, M6RolloverLateralFromSpeedRatio_values);
    InitCurve(BrakeHeatSpeedFromFBrake, 2, BrakeHeatSpeedFromFBrake_times, BrakeHeatSpeedFromFBrake_values);
    InitCurve(AccelCurveRearGear, 4, AccelCurveRearGear_times, AccelCurveRearGear_values);
    InitCurve(M6BurnoutLateralSpeed, 3, M6BurnoutLateralSpeed_times, M6BurnoutLateralSpeed_values);
    InitCurve(M6BurnoutRolloverFromSpeed, 3, M6BurnoutRolloverFromSpeed_times, M6BurnoutRolloverFromSpeed_values);
    InitCurve(M6DonutRolloverFromSpeed, 3, M6DonutRolloverFromSpeed_times, M6DonutRolloverFromSpeed_values);
    InitCurve(AirControlZCoefFromAngularSpeed, 1, AirControlZCoefFromAngularSpeed_times, AirControlZCoefFromAngularSpeed_values);
    InitCurve(VisualSteerAngleFromSpeed, 2, VisualSteerAngleFromSpeed_times, VisualSteerAngleFromSpeed_values);

    tuning->m_maxSideFriction = &MaxSideFriction;
    tuning->m_steerDriveTorque = &SteerDriveTorque;
    tuning->m_steerSlowDown = &SteerSlowDown;
    tuning->m_lateralContactSlowDown = &LateralContactSlowDown;

    tuning->m_mass = StadiumMass;
    tuning->m_inertiaMass = StadiumInertiaMass;
    tuning->m_inertiaHalfDiagX = StadiumInertiaHalfDiagX;
    tuning->m_inertiaHalfDiagY = StadiumInertiaHalfDiagY;
    tuning->m_inertiaHalfDiagZ = StadiumInertiaHalfDiagZ;
    tuning->m_gravityCoef = StadiumGravityCoef;
    tuning->m_gravityCoefAir = StadiumGravityCoefAir;
    tuning->m_angularFluidFrictionCoef1 = StadiumAngularFluidFrictionCoef1;
    tuning->m_groundSlowDownBase = StadiumGroundSlowDownBase;
    tuning->m_linearFluidFrictionCoef = StadiumLinearFluidFrictionCoef;
    tuning->m_maxSpeed = StadiumMaxSpeed;
    tuning->m_reverseMaxSpeed = StadiumReverseMaxSpeed;
    tuning->m_limitToMaxSpeedForce = StadiumLimitToMaxSpeedForce;
    tuning->m_brakeBase = StadiumBrakeBase;
    tuning->m_brakeCoef = StadiumBrakeCoef;
    tuning->m_brakeMax = StadiumBrakeMax;
    tuning->m_brakeMaxDynamic = StadiumBrakeMaxDynamic;
    tuning->m_steerRadiusMin = StadiumSteerRadiusMin;
    tuning->m_steerRadiusCoef = StadiumSteerRadiusCoef;
    tuning->m_steerSpeed = StadiumSteerSpeed;
    tuning->m_steerModel = StadiumSteerModel;
    tuning->m_steerLowSpeed = StadiumSteerLowSpeed;
    tuning->m_steerGroundTorque = StadiumSteerGroundTorque;
    tuning->m_steerGroundTorqueSlippingCoef = StadiumSteerGroundTorqueSlippingCoef;
    tuning->m_maxSideFrictionBlendCoef = StadiumMaxSideFrictionBlendCoef;
    tuning->m_maxSideFrictionSliding = MaxSideFrictionSliding;
    tuning->m_sideFriction1 = StadiumSideFriction1;
    tuning->m_maxSideFrictionOverLimitBlend = StadiumMaxSideFrictionOverLimitBlend;
    tuning->m_m5SlippingAccelCurveCoef =
        StadiumM5SlippingAccelCurveCoef;
    tuning->m_m5AccelSlipCoefMax = StadiumM5AccelSlipCoefMax;
    tuning->m_m5LateralConstantSlowDownDuration =
        StadiumM5LateralConstantSlowDownDuration;
    tuning->m_shockModel = StadiumShockModel;
    tuning->m_absorbingValKi = StadiumAbsorbingValKi;
    tuning->m_absorbingValKa = StadiumAbsorbingValKa;
    tuning->m_absorbingValMin = StadiumAbsorbingValMin;
    tuning->m_absorbingValMax = StadiumAbsorbingValMax;
    tuning->m_absorbingValRest = StadiumAbsorbingValRest;
    tuning->m_absorbTension = StadiumAbsorbTension;
    tuning->m_bodyFrictionCoef = StadiumBodyFrictionCoef;
    tuning->m_bodyFrictionCoefMetal = StadiumBodyFrictionCoefMetal;
    tuning->m_bodyRestCoefMetal = StadiumBodyRestCoefMetal;
    tuning->m_bodyRestCoef = StadiumBodyRestCoef;
    tuning->m_wheelFrictionCoefConcrete = StadiumWheelFrictionCoefConcrete;
    tuning->m_wheelRestCoefConcrete = StadiumWheelRestCoefConcrete;
    tuning->m_wheelFrictionCoefMetal = StadiumWheelFrictionCoefMetal;
    tuning->m_wheelRestCoefMetal = StadiumWheelRestCoefMetal;
    tuning->m_angularSpeedYImpulseScale =
        StadiumAngularSpeedYImpulseScale;
    tuning->m_angularImpulseScale = StadiumAngularImpulseScale;
    tuning->m_angularSpeedClamp = StadiumAngularSpeedClamp;
    tuning->m_linearSpeedSquaredPositiveDeltaMax =
        StadiumLinearSpeedSquaredPositiveDeltaMax;
    tuning->m_lateralSlopeAdherenceMin = StadiumLateralSlopeAdherenceMin;
    tuning->m_lateralSlopeAdherenceMax = StadiumLateralSlopeAdherenceMax;
    tuning->m_axialSlopeAdherenceMin = StadiumAxialSlopeAdherenceMin;
    tuning->m_axialSlopeAdherenceMax = StadiumAxialSlopeAdherenceMax;
    tuning->m_modulationFromWheelCompression =
        &ModulationFromWheelCompression;
    tuning->m_m6BrakeModulationWhenSlipping =
        StadiumM6BrakeModulationWhenSlipping;
    tuning->m_m6FrictionModulationWhenSlipAndBrake =
        StadiumM6FrictionModulationWhenSlipAndBrake;
    tuning->m_m6BrakeMaxRear = StadiumM6BrakeMaxRear;
    tuning->m_m6BrakeMaxDynamicRear = StadiumM6BrakeMaxDynamicRear;
    tuning->m_m6BurnoutDuration = StadiumM6BurnoutDuration;
    tuning->m_m6BurnoutAccelerationModulation =
        StadiumM6BurnoutAccelerationModulation;
    tuning->m_m6AfterBurnoutDuration = StadiumM6AfterBurnoutDuration;
    tuning->m_m6AfterBurnoutAccelerationModulation =
        StadiumM6AfterBurnoutAccelerationModulation;
    tuning->m_m6AfterBurnoutImpulse = StadiumM6AfterBurnoutImpulse;
    tuning->m_waterGravity = StadiumWaterGravity;
    tuning->m_waterReboundMinHorizontalSpeed =
        StadiumWaterReboundMinHorizontalSpeed;
    tuning->m_waterBumpMinSpeed = StadiumWaterBumpMinSpeed;
    tuning->m_waterBumpSlowDownFromSpeedRatio =
        &WaterBumpSlowDownFromSpeedRatio;
    tuning->m_waterReboundFromSpeedRatio = &WaterReboundFromSpeedRatio;
    tuning->m_waterFrictionFromSpeed = &WaterFrictionFromSpeed;
    tuning->m_waterAngularFriction = StadiumWaterAngularFriction;
    tuning->m_waterAngularFrictionSq = StadiumWaterAngularFrictionSq;
    tuning->m_m6MaxRpm = StadiumM6MaxRpm;
    tuning->m_m6GearRatios = StadiumM6GearRatios;
    tuning->m_m6MaxRpmRatios = StadiumM6MaxRpmRatios;
    tuning->m_m6MinRpmRatios = StadiumM6MinRpmRatios;
    tuning->m_m6RpmWantedOnGearUp = StadiumM6RpmWantedOnGearUp;
    tuning->m_m6BurnoutRpmAcceleration = StadiumM6BurnoutRpmAcceleration;
    tuning->m_m6AirRpmAcceleration = StadiumM6AirRpmAcceleration;
    tuning->m_m6AirRpmDeadening = StadiumM6AirRpmDeadening;
    tuning->m_m6RpmLossOnGearUp = StadiumM6RpmLossOnGearUp;
    tuning->m_m6RpmGainOnGearDown = StadiumM6RpmGainOnGearDown;
    tuning->m_m6RpmGainOnTakeoff = StadiumM6RpmGainOnTakeoff;
    tuning->m_m6RpmLossOnTakeoffFinished = StadiumM6RpmLossOnTakeoffFinished;
    tuning->m_m6PositiveTakeoffFrontSpeed = StadiumM6PositiveTakeoffFrontSpeed;
    tuning->m_m6PositiveTakeoffRearSpeed = StadiumM6PositiveTakeoffRearSpeed;
    tuning->m_m6NegativeTakeoffFrontSpeed = StadiumM6NegativeTakeoffFrontSpeed;
    tuning->m_m6NegativeTakeoffRearSpeed = StadiumM6NegativeTakeoffRearSpeed;
    tuning->M6InitRpmDeltas();

    // Fill dummy wheel tuning with 100.0f
    for (int i = 0; i < 256; ++i) g_dummy_wheel_tuning[i] = 100.0f;
    // Offset 0 must be a pointer to valid data
    *(size_t*)&g_dummy_wheel_tuning[0] = (size_t)&g_dummy_wheel_tuning[0];

    for (int i = 0; i < 4; ++i) {
        tuning->m_field_14.Add((void*)g_dummy_wheel_tuning);
    }
}
