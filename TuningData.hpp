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

inline float MaxSideFrictionSliding = 0.6f;

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

    // Fill dummy wheel tuning with 100.0f
    for (int i = 0; i < 256; ++i) g_dummy_wheel_tuning[i] = 100.0f;
    // Offset 0 must be a pointer to valid data
    *(size_t*)&g_dummy_wheel_tuning[0] = (size_t)&g_dummy_wheel_tuning[0];

    for (int i = 0; i < 4; ++i) {
        tuning->m_field_14.Add((void*)g_dummy_wheel_tuning);
    }
}
