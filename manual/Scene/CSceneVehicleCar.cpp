#include <cstddef>
#include "CSceneVehicleCar.hpp"
#include "CHmsItem.hpp"
#include "GmMat3.hpp"
#include <cmath>
#include <algorithm>

extern float g_carYaw;

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
CSceneVehicleCar::CSceneVehicleCar() : CSceneVehicle(), m_pilotCar(this) {
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

    // ApplyFrictionForces(pilot, dt);

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
    
    // Transform world velocity to local frame
    float c = std::cos(g_carYaw);
    float s = std::sin(g_carYaw);
    float localForwardSpeed = linSpeed.x * s + linSpeed.z * c; // forward = dot(vel, fwd)
    float speed = std::abs(localForwardSpeed);

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
    
    // Convert global velocity to local velocity
    float c = std::cos(g_carYaw);
    float s = std::sin(g_carYaw);
    
    // forward is along (sin(yaw), 0, cos(yaw))
    float localZ = linSpeed.x * s + linSpeed.z * c; // forward speed
    float localX = linSpeed.x * c - linSpeed.z * s; // lateral speed
    
    uint32_t wheelCount = m_wheels.GetCount();
    for (uint32_t i = 0; i < wheelCount; ++i) {
        SSimulationWheel& wheel = m_wheels[i];
        if (wheel.m_hasGroundContact) {
            // Lateral friction (prevent sliding) - per-wheel
            float lateralSlip = localX;
            float lateralForceMag = -lateralSlip * 1500.0f; // Strong cornering grip per wheel
            
            // Convert local forces back to global (only lateral for now)
            GmVec3 globalForce(
                lateralForceMag * c,
                0,
                -lateralForceMag * s
            );
            
            m_hmsItem->AddForce(m_hmsItem, &globalForce, nullptr);
        }
    }
    
    // Aerodynamic drag (proportional to speed^2, applied in global velocity direction)
    float speedSq = linSpeed.x * linSpeed.x + linSpeed.y * linSpeed.y + linSpeed.z * linSpeed.z;
    float speed = std::sqrt(speedSq);
    if (speed > 0.01f) {
        // Drag coefficient tuned so top speed ~320 km/h (88.9 m/s)
        // At top speed: drag = engine force
        // Engine force at top speed ~ 4000 N
        // drag = coeff * v^2 = coeff * 88.9^2 = coeff * 7903
        // coeff = 4000/7903 ≈ 0.506
        float dragCoeff = 0.5f;
        float dragMag = dragCoeff * speedSq;
        GmVec3 drag(
            -linSpeed.x / speed * dragMag,
            0, // No vertical drag
            -linSpeed.z / speed * dragMag
        );
        m_hmsItem->AddForce(m_hmsItem, &drag, nullptr);
    }
    
    // Rolling resistance (small constant opposing force)
    if (speed > 0.1f) {
        float rollingCoeff = 50.0f; // Low rolling resistance
        GmVec3 rolling(
            -linSpeed.x / speed * rollingCoeff,
            0,
            -linSpeed.z / speed * rollingCoeff
        );
        m_hmsItem->AddForce(m_hmsItem, &rolling, nullptr);
    }
}

void CSceneVehicleCar::ComputeForcesModel3(CSceneVehicleCar* pilot, float dt) {
    if (m_hmsItem == nullptr) return;

    // Call the exact 1:1 float model translation
    // We provide dummy local variables for the stack pointers that Ghidra misidentified as parameters.
    GmVec3 p3(0,0,0);
    GmVec3 p6(0,0,0);
    
    GmVec3 linSpeed;
    m_hmsItem->GetLinearSpeed(m_hmsItem, &linSpeed);
    
    // Convert global velocity to local velocity
    float c = std::cos(g_carYaw);
    float s = std::sin(g_carYaw);
    
    // forward is along (sin(yaw), 0, cos(yaw))
    p6.x = linSpeed.x * c - linSpeed.z * s;     // right
    p6.y = linSpeed.y;                          // up
    p6.z = linSpeed.z * c + linSpeed.x * s;     // forward
    
    GmVec3 p7(0, 1.0f, 0); // Ground normal
    float p10[16] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    int p11[4] = {1, 1, 1, 1};
    float p12[16] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    
    // 0x60c is likely has_ground_contact. Set to 1 for now.
    *(int*)((char*)this + 0x60c) = 1;
    this->m_field_0x600 = 0;
    this->m_field_0x5f4 = 1.0f;
    float p11_temp[4] = {1.0f, 1.0f, 1.0f, 1.0f}; // temp
    void* p10_temp = p11_temp; // temp
    float p12_temp[4] = {1.0f, 1.0f, 1.0f, 1.0f}; // temp
    
    printf("CALLING ComputeForcesModel3_Exact with m_inputGas=%f\n", this->m_inputGas); printf("sizeof(CSceneMobil)=%lu\n", sizeof(CSceneMobil)); printf("OFFSET m_inputGas=%lu\n", offsetof(CSceneVehicleCar, m_inputGas));
    ComputeForcesModel3_Exact(pilot, dt, &p3, this->m_inputGas, this->m_inputBrake, &p6, &p7, this->m_inputSteer, 1, p10_temp, (int*)p11_temp, p12_temp);
    
    printf("WRAPPER: p3=(%f, %f, %f)\n", p3.x, p3.y, p3.z);
    // Apply the returned force!
    if (p3.x != 0 || p3.y != 0 || p3.z != 0) {
        GmVec3 globalForce(
            p3.x * c + p3.z * s,
            p3.y,
            -p3.x * s + p3.z * c
        );
        m_hmsItem->AddForce(m_hmsItem, &globalForce, nullptr);
    }
}


// Function: CSceneVehicleCar::WheelAddForceToVehicle
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CSceneVehicleCar::WheelAddForceToVehicle(CSceneVehicleCar *param_1, void *param_2_void, void *param_3_void, void *param_4) {
    // Forward the precisely calculated forces from ComputeForcesModel3_Exact
    if (param_3_void && param_4) {
        GmVec3* f = (GmVec3*)param_3_void;
        if (f->x != 0 || f->y != 0 || f->z != 0) {
            // printf("WheelForce: %f, %f, %f\n", f->x, f->y, f->z);
        }
        AddVehicleForce(this, (CSceneVehicleCar*)param_3_void, (GmVec3*)param_4, nullptr);
    }
}

void CSceneVehicleCar::AddVehicleTorque(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3) {
    if (this->m_hmsItem) {
        GmVec3* local_t = (GmVec3*)param_2;
        if (local_t->x != 0 || local_t->y != 0 || local_t->z != 0) { printf("Torque: %f, %f, %f\n", local_t->x, local_t->y, local_t->z); }
        
        float c = std::cos(g_carYaw);
        float s = std::sin(g_carYaw);
        
        GmVec3 global_t(
            local_t->x * c + local_t->z * s,
            local_t->y,
            -local_t->x * s + local_t->z * c
        );
        this->m_hmsItem->AddTorque(this->m_hmsItem, &global_t);
    }
}
extern float g_carYaw;
void CSceneVehicleCar::AddVehicleCentralForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3) {
    if (this->m_hmsItem) {
        GmVec3* f = (GmVec3*)param_2;
        if (f->x != 0 || f->y != 0 || f->z != 0) { printf("CentralForce: %f, %f, %f\n", f->x, f->y, f->z); }
        float c = std::cos(g_carYaw);
        float s = std::sin(g_carYaw);
        GmVec3 globalForce(
            f->x * c + f->z * s,
            f->y,
            -f->x * s + f->z * c
        );
        this->m_hmsItem->AddForce(this->m_hmsItem, &globalForce, nullptr);
    }
}
void CSceneVehicleCar::AddVehicleForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3, GmVec3 *param_4) {
    if (this->m_hmsItem) {
        GmVec3* local_f = (GmVec3*)param_2;
        float c = std::cos(g_carYaw);
        float s = std::sin(g_carYaw);
        
        GmVec3 global_f(
            local_f->x * c + local_f->z * s,
            local_f->y,
            -local_f->x * s + local_f->z * c
        );
        
        GmVec3* p = param_3;
        if (p) {
            GmVec3 global_p(
                p->x * c + p->z * s,
                p->y,
                -p->x * s + p->z * c
            );
            this->m_hmsItem->AddForce(this->m_hmsItem, &global_f, &global_p);
            
            GmVec3 local_torque;
            local_torque.x = p->y * local_f->z - p->z * local_f->y;
            local_torque.y = p->z * local_f->x - p->x * local_f->z;
            local_torque.z = p->x * local_f->y - p->y * local_f->x;
            
            GmVec3 global_torque(
                local_torque.x * c + local_torque.z * s,
                local_torque.y,
                -local_torque.x * s + local_torque.z * c
            );
            this->m_hmsItem->AddTorque(this->m_hmsItem, &global_torque);
        } else {
            this->m_hmsItem->AddForce(this->m_hmsItem, &global_f, nullptr);
        }
    }
}
