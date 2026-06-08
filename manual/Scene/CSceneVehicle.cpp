#include "CSceneVehicle.hpp"

// SEnvironment
CSceneVehicle::SEnvironment::~SEnvironment() {}

// SSurfaceHandler
CSceneVehicle::SSurfaceHandler::~SSurfaceHandler() {}

// SVehicleState
CSceneVehicle::SVehicleState::~SVehicleState() {}

// SVisualArm
CSceneVehicle::SVisualArm::~SVisualArm() {}

// SVisualHandler
CSceneVehicle::SVisualHandler::~SVisualHandler() {}

// SVisualLight
CSceneVehicle::SVisualLight::~SVisualLight() {}

// SVisualWheel
CSceneVehicle::SVisualWheel::~SVisualWheel() {}

// CSceneVehicle
CSceneVehicle::CSceneVehicle() : CSceneMobil() {
    m_inputGas = 0.0f;
    m_inputBrake = 0.0f;
    m_inputSteer = 0.0f;
    m_field_5c = 0;
    m_field_60 = 0;
    m_field_64 = 0;
    m_field_68 = 0;
}
CSceneVehicle::~CSceneVehicle() {}

CMwNod* CSceneVehicle::MwNewCSceneVehicle() { return new CSceneVehicle(); }
uint32_t CSceneVehicle::GetMwClassId() { return 0x06008000; }

void* CSceneVehicle::_scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2) {
    this->~CSceneVehicle();
    return this;
}

void CSceneVehicle::Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3) {}

void CSceneVehicle::VehicleInputGasSet(float gas) { m_inputGas = gas; }
void CSceneVehicle::VehicleInputBrakeSet(float brake) { m_inputBrake = brake; }
void CSceneVehicle::VehicleInputSteerSet(float steer) { m_inputSteer = steer; }
float CSceneVehicle::VehicleInputSteerGet() const { return m_inputSteer; }
