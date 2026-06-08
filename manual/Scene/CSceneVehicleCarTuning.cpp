#include "CSceneVehicleCarTuning.hpp"
#include "CFuncKeysReal.hpp"

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




