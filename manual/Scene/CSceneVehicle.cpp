#include "CSceneVehicle.hpp"
#include "CPlugTree.hpp"

// SEnvironment
CSceneVehicle::SEnvironment::~SEnvironment() {}

// SSurfaceHandler
CSceneVehicle::SSurfaceHandler::SSurfaceHandler() : m_tree(nullptr) {
    m_baseLocation.SetIdentity();
    m_surfaceLocation.SetIdentity();
}

void CSceneVehicle::SSurfaceHandler::Reset() {
    m_surfaceLocation = m_baseLocation;
}

void CSceneVehicle::SSurfaceHandler::UpdateSurface() {
    if (m_tree != nullptr) {
        m_tree->SetLocation(m_surfaceLocation);
    }
}

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
    m_waterSplashCount = 0u;
    m_lastWaterSplashSpeed = GmVec3(0.0f, 0.0f, 0.0f);
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

void CSceneVehicle::WaterSplash(const GmVec3* worldSpeed) {
    if (worldSpeed == nullptr) return;
    ++m_waterSplashCount;
    m_lastWaterSplashSpeed = *worldSpeed;
}
