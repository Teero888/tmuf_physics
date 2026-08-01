#include "CSceneVehicleCarTuning.hpp"
#include "CFuncKeysReal.hpp"
#include "../TuningData.hpp"

float CSceneVehicleCarTuning::EvaluateCurve(struct CFuncKeysReal* curve, float x) {
    if (!curve || curve->m_keys.m_count == 0) return 0.0f;
    if (x <= curve->m_keys.m_data[0]) return curve->m_values.m_data[0];
    if (x >= curve->m_keys.m_data[curve->m_keys.m_count - 1]) return curve->m_values.m_data[curve->m_keys.m_count - 1];
    for (uint32_t i = 0; i < curve->m_keys.m_count - 1; ++i) {
        if (x >= curve->m_keys.m_data[i] && x <= curve->m_keys.m_data[i+1]) {
            float t = (x - curve->m_keys.m_data[i]) / (curve->m_keys.m_data[i+1] - curve->m_keys.m_data[i]);
            return curve->m_values.m_data[i] + t * (curve->m_values.m_data[i+1] - curve->m_values.m_data[i]);
        }
    }
    return 0.0f;
}

float CSceneVehicleCarTuning::GetLateralContactSlowDownFromSpeed(float speed) { return EvaluateCurve(&LateralContactSlowDown, speed); }
float CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(float speed) { return EvaluateCurve(&MaxSideFriction, speed); }
float CSceneVehicleCarTuning::GetAccelFromSpeed(float speed) { return EvaluateCurve(&AccelCurve, speed); }
float CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed(float speed) { return EvaluateCurve(&SteerDriveTorque, speed); }
float CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle(float angle) { return 0.0f; } // Not extracted yet
float CSceneVehicleCarTuning::GetRolloverLateralFromSpeed(float speed) { return 0.0f; } // Not extracted yet
float CSceneVehicleCarTuning::GetSteerSlowDownFromSpeed(float speed) { return EvaluateCurve(&SteerSlowDown, speed); }

CSceneVehicleCarTuning::CSceneVehicleCarTuning() : CMwNod() {
    m_steerSlowDown = nullptr;
    m_steerDriveTorque = nullptr;
    m_steerRadius = nullptr;
    m_steerSlowDown2 = nullptr;
    m_lateralContactSlowDown = nullptr;
    m_maxSideFriction = nullptr;
}

CSceneVehicleCarTuning::~CSceneVehicleCarTuning() {}

CMwNod* CSceneVehicleCarTuning::MwNewCSceneVehicleCarTuning() { return new CSceneVehicleCarTuning(); }
uint32_t CSceneVehicleCarTuning::GetMwClassId() { return 0x0601E000; }

void CSceneVehicleCarTuning::Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3) {}




