#include "CSceneVehicleCar.hpp"
#include "CHmsItem.hpp"
#include "GmMat3.hpp"
#include <cmath>
#include <algorithm>

// SDynaPart
CSceneVehicleCar::SDynaPart::~SDynaPart() {}

// SEngine
CSceneVehicleCar::SEngine::~SEngine() {}
void CSceneVehicleCar::SEngine::Reset() {
    m_throttle = 0.0f;
    m_engineRpm = 1000.0f;
    m_clutchRpm = 1000.0f;
    m_clutchRatio = 1.0f;
    m_gearShiftTimer = 0.0f;
    m_currentGear = 1;
}

// SSimulationWheel::SRealTimeState
CSceneVehicleCar::SSimulationWheel::SRealTimeState::~SRealTimeState() {}
void CSceneVehicleCar::SSimulationWheel::SRealTimeState::Integrate(float dt) {
    m_rotationAngle += m_angularVelocity * dt;
}

// SSimulationWheel::SState
CSceneVehicleCar::SSimulationWheel::SState::~SState() {}
void CSceneVehicleCar::SSimulationWheel::SState::Reset() {}

// SSimulationWheel
CSceneVehicleCar::SSimulationWheel::~SSimulationWheel() {}

// SVehicleCarState
CSceneVehicleCar::SVehicleCarState::~SVehicleCarState() {}

// CSceneVehicleCar
CSceneVehicleCar::CSceneVehicleCar() : CSceneVehicle(), m_pilotCar(nullptr) {
    m_simulationFlags = 0;
    m_engineForce = 0.0f;
    m_engine.Reset();
    
    // Initialize 4 wheels for the Stadium car
    for (int i = 0; i < 4; ++i) {
        SSimulationWheel wheel;
        wheel.m_radius = 0.35f;
        wheel.m_hasGroundContact = 0;
        wheel.m_realTimeState.m_angularVelocity = 0.0f;
        wheel.m_realTimeState.m_rotationAngle = 0.0f;
        wheel.m_realTimeState.m_velocity = 0.0f;
        wheel.m_realTimeState.m_compression = 0.0f;
        m_wheels.Add(wheel);
    }
}

CSceneVehicleCar::~CSceneVehicleCar() {}

CMwNod* CSceneVehicleCar::MwNewCSceneVehicleCar() { return new CSceneVehicleCar(); }
uint32_t CSceneVehicleCar::GetMwClassId() { return 0x0601D000; }

void* CSceneVehicleCar::_vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2) {
    this->~CSceneVehicleCar();
    if ((param_2 & 1) != 0) {
        delete this;
    }
    return this;
}

void CSceneVehicleCar::Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3) {}

void CSceneVehicleCar::ComputeForces(CCallbackSceneToyBroomStickComputeForces* param_1, CHmsItem* param_2, float dt) {
    IntegrateVehicle(m_pilotCar, dt);
}

void CSceneVehicleCar::IntegrateVehicle(CSceneVehicleCar* pilot, float dt) {
    if (m_hmsItem == nullptr) return;

    GmVec3 linSpeed(0,0,0);
    m_hmsItem->GetLinearSpeed(m_hmsItem, &linSpeed);

    // 1. Aerodynamics (Downforce & Drag)
    float speedSq = linSpeed.x*linSpeed.x + linSpeed.y*linSpeed.y + linSpeed.z*linSpeed.z;
    float speed = std::sqrt(speedSq);
    
    // Downforce = coeff * speed^2
    float downforceCoeff = 0.005f; // Placeholder Stadium value
    GmVec3 downforce(0, -downforceCoeff * speedSq, 0);
    m_hmsItem->AddForce(m_hmsItem, &downforce, nullptr);

    // 2. Engine & Transmission update
    if ((m_simulationFlags & 4) != 0) {
        EngineIntegrate(pilot ? pilot : this, dt, 0.0f);
    }

    // 3. Wheel speed & rotation updates
    if ((m_simulationFlags & 1) != 0) {
        uint32_t wheelCount = m_wheels.GetCount();
        for (uint32_t i = 0; i < wheelCount; ++i) {
            SSimulationWheel& wheel = m_wheels[i];
            WheelUpdateSpeedFromVehicleSpeed(&wheel, pilot, dt, 0.0f);
            wheel.m_realTimeState.Integrate(dt);
        }
    }
    
    // 4. Physical integration (Forces)
    if ((m_simulationFlags & 2) != 0) {
        uint32_t wheelCount = m_wheels.GetCount();
        for (uint32_t i = 0; i < wheelCount; ++i) {
            WheelIntegrate(&m_wheels[i], dt);
        }
    }

    // Call the specific Stadium Car physics model
    ComputeForcesModel3(pilot, dt);
}

void CSceneVehicleCar::WheelUpdateSpeedFromVehicleSpeed(SSimulationWheel* wheel, CSceneVehicleCar* pilot, float dt, float param_3) {
    if (wheel->m_radius < 0.0001f) return;

    GmVec3 linSpeed(0,0,0);
    m_hmsItem->GetLinearSpeed(m_hmsItem, &linSpeed);
    
    float forwardSpeed = linSpeed.z; 

    // Target angular velocity based on speed
    float targetOmega = forwardSpeed / wheel->m_radius;
    
    wheel->m_realTimeState.m_angularVelocity = targetOmega; 
}

void CSceneVehicleCar::WheelIntegrate(SSimulationWheel* wheel, float dt) {
    float targetCompression = 0.0f; 
    float stiffness = 50000.0f;     
    float damping = 2000.0f;        
    
    float force = (targetCompression - wheel->m_realTimeState.m_compression) * stiffness 
                - wheel->m_realTimeState.m_velocity * damping;
    
    wheel->m_realTimeState.m_velocity += force * dt;
    wheel->m_realTimeState.m_compression += wheel->m_realTimeState.m_velocity * dt;
    
    wheel->m_suspensionForce = -wheel->m_realTimeState.m_compression * stiffness;
}

void CSceneVehicleCar::EngineIntegrate(CSceneVehicleCar* pilot, float dt, float param_2) {
    const float gearRatios[] = { 0.0f, 15.0f, 10.0f, 7.5f, 5.5f, 4.0f };
    const float upshiftRPM = 10000.0f;
    const float downshiftRPM = 6000.0f;
    const float rpmResponse = 5.0f;

    m_engine.m_throttle = m_inputGas;

    GmVec3 linSpeed(0,0,0);
    m_hmsItem->GetLinearSpeed(m_hmsItem, &linSpeed);
    float speed = std::abs(linSpeed.z);

    // Ideal RPM for current speed
    float wheelRadius = 0.35f;
    float idealRPM = (speed / wheelRadius) * gearRatios[m_engine.m_currentGear] * (60.0f / (2.0f * 3.14159265f));
    
    if (idealRPM < 1000.0f) idealRPM = 1000.0f;

    // Automatic gear shifting
    if (m_engine.m_gearShiftTimer <= 0.0f) {
        if (idealRPM > upshiftRPM && m_engine.m_currentGear < 5) {
            m_engine.m_currentGear++;
            m_engine.m_gearShiftTimer = 0.3f;
        } else if (idealRPM < downshiftRPM && m_engine.m_currentGear > 1) {
            m_engine.m_currentGear--;
            m_engine.m_gearShiftTimer = 0.2f;
        }
    } else {
        m_engine.m_gearShiftTimer -= dt;
    }

    // Sync engine RPM
    m_engine.m_engineRpm += (idealRPM - m_engine.m_engineRpm) * rpmResponse * dt;

    // Torque curve
    float torque = 1000.0f;
    if (m_engine.m_engineRpm > 10000.0f) torque *= 0.5f;
    
    m_engineForce = torque * gearRatios[m_engine.m_currentGear] * m_engine.m_throttle;
}

int CSceneVehicleCar::IsGroundContact() { 
    return 0; 
}

void CSceneVehicleCar::ApplyFrictionForces(CSceneVehicleCar* pilot, float dt) {
    if (m_hmsItem == nullptr) return;
    
    GmVec3 linSpeed;
    m_hmsItem->GetLinearSpeed(m_hmsItem, &linSpeed);
    
    uint32_t wheelCount = m_wheels.GetCount();
    for (uint32_t i = 0; i < wheelCount; ++i) {
        SSimulationWheel& wheel = m_wheels[i];
        if (wheel.m_hasGroundContact) {
            // Placeholder: Lateral friction prevents side-slip
            // In Stadium car, side friction is extremely high on road.
            GmVec3 lateralForce(-linSpeed.x * 1000.0f, 0, 0); 
            m_hmsItem->AddForce(m_hmsItem, &lateralForce, nullptr);
            
            // Longitudinal friction (Braking/Acceleration)
            float slip = wheel.m_realTimeState.m_angularVelocity * wheel.m_radius - linSpeed.z;
            GmVec3 longForce(0, 0, slip * 500.0f);
            m_hmsItem->AddForce(m_hmsItem, &longForce, nullptr);
        }
    }
}

void CSceneVehicleCar::ComputeForcesModel3(CSceneVehicleCar* pilot, float dt) {
    if (m_hmsItem == nullptr) return;

    // Call the exact 1:1 float model translation
    // We provide dummy local variables for the stack pointers that Ghidra misidentified as parameters.
    GmVec3 p3(0,0,0);
    GmVec3 p6(0,0,0);
    GmVec3 p7(0,0,0);
    void* p10 = nullptr;
    int p11 = 0;
    float p12 = 0.0f;
    
    ComputeForcesModel3_Exact(pilot, dt, &p3, 0.0f, 0.0f, &p6, &p7, 0.0f, 0, p10, &p11, &p12);
}

