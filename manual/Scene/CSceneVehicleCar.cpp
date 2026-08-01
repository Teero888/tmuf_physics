#include <cstddef>
#include "CSceneVehicleCar.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include "TmForeverPhysicsConstants.hpp"
#include "VehicleGroundSupport.hpp"
#include "CHmsItem.hpp"
#include "GmMat3.hpp"
#include <cmath>
#include <algorithm>

extern float g_carYaw;
extern CSceneVehicleCarTuning* g_tuning;

namespace {

VehicleChassisBasis GetChassisBasis(const CSceneVehicleCar& car) {
    return BuildVehicleChassisBasis(car.m_chassisUp, g_carYaw);
}

GmVec3 LocalToWorld(const VehicleChassisBasis& basis, const GmVec3& local) {
    return basis.right * local.x +
           basis.up * local.y +
           basis.forward * local.z;
}

GmVec3 WorldToLocal(const VehicleChassisBasis& basis, const GmVec3& world) {
    return GmVec3(
        GmVec3::Dot(world, basis.right),
        GmVec3::Dot(world, basis.up),
        GmVec3::Dot(world, basis.forward));
}

} // namespace

// SDynaPart
CSceneVehicleCar::SDynaPart::~SDynaPart() {}

// SEngine
CSceneVehicleCar::SEngine::~SEngine() {}
void CSceneVehicleCar::SEngine::Reset() {
    // Exact writes performed by SEngine::Reset in TmForeverFixed.exe.
    // Constructor-owned throttle/scalar defaults deliberately survive Reset.
    m_field_0x10 = 0.0f;
    m_engineRpm = 0.0f;
    m_clutchRpm = 0.0f;
    m_clutchRatio = 1.0f;
    m_gearShiftTimer = 0.0f;
    m_field_0x28 = 0;
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
CSceneVehicleCar::SSimulationWheel::SSimulationWheel()
    : m_field_0x00(0),
      m_field_0x04(0),
      m_radius(1.0f),
      m_hasGroundContact(0),
      m_groundMaterial(0),
      m_isSlipping(0),
      m_suspensionForce(0.0f),
      m_field_0x15c(0.0f) {
    m_realTimeState.m_compression = 0.0f;
    m_realTimeState.m_velocity = 0.0f;
    m_realTimeState.m_absorbDelta = 0.0f;
    m_realTimeState.m_angularVelocity = 0.0f;
    m_realTimeState.m_axisX = 0.0f;
    m_realTimeState.m_axisY = 0.0f;
    m_realTimeState.m_rotationAngle = 0.0f;
    m_realTimeState.m_field_0xa0 = 0.0f;
    m_realTimeState.m_field_0xa4 = 0.0f;
}

CSceneVehicleCar::SSimulationWheel::~SSimulationWheel() {}

// SVehicleCarState
CSceneVehicleCar::SVehicleCarState::~SVehicleCarState() {}

// CSceneVehicleCar
CSceneVehicleCar::CSceneVehicleCar()
    : CSceneVehicle(), m_freeWheeling(0), m_chassisUp(0.0f, 1.0f, 0.0f) {
    m_simulationFlags = 0;
    m_smoothedSteer = 0.0f;
    m_field_0x5ec = 0.0f;
    m_field_0x5f0 = 0.0f;
    m_field_0x5f4 = 0.0f;
    m_field_0x5f8 = 0.0f;
    m_field_0x5fc = 0.0f;
    m_field_0x600 = 0;
    // Exact constructor default; UpdateParamsFromTuning later replaces this
    // with twice the longitudinal wheel extent when vehicle geometry exists.
    m_field_0x840 = 1.0f;

    // Exact SEngine constructor defaults before Reset.
    m_engine.m_throttle = 1.0f;
    m_engine.m_field_0x04 = 1.0f;
    m_engine.m_field_0x08 = 1.0f;
    m_engine.m_field_0x0c = 0.0f;
    m_engine.m_field_0x10 = 0.0f;
    m_engine.m_field_0x30 = 0.0f;
    m_engine.Reset();
    
    // Initialize 4 wheels for the Stadium car
    for (int i = 0; i < 4; ++i) {
        SSimulationWheel wheel;
        // Stadium's first two wheels are the steerable/front axle.  The
        // original force loops read this flag at wheel +0x04.
        // VehicleInitFromSolid copies U01/U02 from StadiumCar.VehicleStruct.
        // U01 is enabled on all wheels; U02 is enabled on the front pair.
        wheel.m_field_0x00 = 1u;
        wheel.m_isSteerable = i < 2 ? 1u : 0u;
        wheel.m_radius = TmForeverPhysicsConstants::kStadiumWheelRadius;
        wheel.m_hasGroundContact = 0;
        wheel.m_realTimeState.m_angularVelocity = 0.0f;
        wheel.m_realTimeState.m_rotationAngle = 0.0f;
        wheel.m_realTimeState.m_velocity = 0.0f;
        wheel.m_realTimeState.m_compression = 0.0f;
        wheel.m_realTimeState.m_absorbDelta = 0.0f;
        m_wheels.Add(wheel);
    }

    // The original constructor value above survives only until the loaded
    // wheel surfaces are scanned. Mirror the resulting Stadium runtime state.
    m_field_0x840 = TmForeverPhysicsConstants::kStadiumWheelbase;
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
    IntegrateVehicle(this, dt);
}

void CSceneVehicleCar::IntegrateVehicle(CSceneVehicleCar* pilot, float dt) {
    if (m_hmsItem == nullptr) return;

    // 1. Engine & Transmission update
    if ((m_simulationFlags & 4) != 0) {
        EngineIntegrate(pilot ? pilot : this, dt, 0.0f);
    }

    // 2. Wheel speed & rotation updates
    if ((m_simulationFlags & 1) != 0) {
        uint32_t wheelCount = m_wheels.GetCount();
        for (uint32_t i = 0; i < wheelCount; ++i) {
            SSimulationWheel& wheel = m_wheels[i];
            WheelUpdateSpeedFromVehicleSpeed(&wheel, pilot, dt, 0.0f);
            wheel.m_realTimeState.Integrate(dt);
        }
    }
    
    // 3. Physical integration (Forces)
    if ((m_simulationFlags & 2) != 0) {
        uint32_t wheelCount = m_wheels.GetCount();
        for (uint32_t i = 0; i < wheelCount; ++i) {
            WheelIntegrate(&m_wheels[i], dt);
        }
    }

    // ApplyFrictionForces(pilot, dt);

    // IntegrateVehicle in the fixed executable moves +0x5E8 toward the raw
    // steer input at Tuning::SteerSpeed units per second before force dispatch.
    const float steerSpeed = g_tuning != nullptr ? g_tuning->m_steerSpeed : 0.0f;
    const float steerDelta = m_inputSteer - m_smoothedSteer;
    const float maxSteerStep = steerSpeed * dt;
    if (std::abs(steerDelta) <= maxSteerStep || maxSteerStep <= 0.0f) {
        m_smoothedSteer = m_inputSteer;
    } else {
        m_smoothedSteer += std::copysign(maxSteerStep, steerDelta);
    }

    // Stadium tuning 29 is Steer06 (enum value 5), which the fixed executable
    // dispatches to ComputeForcesModel6 at 0x7C3E80.
    ComputeForcesModel6(pilot, dt);
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
    if (wheel == nullptr || g_tuning == nullptr || dt <= 0.0f) return;

    if (g_tuning->m_shockModel == 2) {
        // Exact Demo03 branch at 0x7BD42E..0x7BD505. Contact absorption is
        // accumulated in wheel +0xBC, subtracted once, then cleared. The
        // resulting compression moves toward AbsorbingValRest at
        // AbsorbTension units per second.
        const float previousCompression = wheel->m_realTimeState.m_compression;
        const float absorbedCompression =
            previousCompression - wheel->m_realTimeState.m_absorbDelta;
        const float compression =
            absorbedCompression +
            (g_tuning->m_absorbingValRest - absorbedCompression) *
                dt * g_tuning->m_absorbTension;

        wheel->m_realTimeState.m_velocity =
            (compression - previousCompression) / dt;
        wheel->m_realTimeState.m_compression = compression;
        wheel->m_realTimeState.m_absorbDelta = 0.0f;
        return;
    }

    // Other shock models have separate native branches and remain inert until
    // their tuning fields and contact-state transforms are represented.
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

    // Original +0x5E8 is smoothed steering, not engine torque.  Propulsion for
    // this physics generation comes from the tuning acceleration curves.
}

void CSceneVehicleCar::VehicleFreeWheelingSet(int enabled) {
    m_freeWheeling = enabled;
}

int CSceneVehicleCar::IsGroundContact() {
    // Exact control flow of TmForeverFixed.exe: return on the first wheel whose
    // +0x124 contact flag is non-zero.
    const uint32_t wheelCount = m_wheels.GetCount();
    for (uint32_t i = 0; i < wheelCount; ++i) {
        if (m_wheels[i].m_hasGroundContact != 0) return 1;
    }
    return 0;
}

void CSceneVehicleCar::ComputeVehicleGroundMaterialVals(
    StadiumVehicleMaterials::GroundValues* values,
    int* hasGroundContact) const {
    if (values == nullptr || hasGroundContact == nullptr) return;

    *values = {};
    *hasGroundContact = 0;

    const uint32_t wheelCount = m_wheels.GetCount();
    if (wheelCount == 0) return;

    uint32_t contactedWheelCount = 0;
    for (uint32_t i = 0; i < wheelCount; ++i) {
        if (m_wheels[i].m_hasGroundContact == 0) continue;

        // Exact 0x7C2800 behavior: every contacted wheel contributes the
        // material selected by wheel zero, rather than its own material.
        const StadiumVehicleMaterials::Material* material =
            StadiumVehicleMaterials::Find(m_wheels[0].m_groundMaterial);
        if (material != nullptr) {
            const StadiumVehicleMaterials::GroundValues contribution =
                StadiumVehicleMaterials::ToGroundValues(*material);
            values->speed += contribution.speed;
            values->accelerationCoef += contribution.accelerationCoef;
            values->brakeCoef += contribution.brakeCoef;
            values->grip += contribution.grip;
        }

        ++contactedWheelCount;
        *hasGroundContact = 1;
    }

    if (contactedWheelCount == 0) return;
    const float inverseCount = 1.0f / static_cast<float>(contactedWheelCount);
    values->speed *= inverseCount;
    values->accelerationCoef *= inverseCount;
    values->brakeCoef *= inverseCount;
    values->grip *= inverseCount;
}

void CSceneVehicleCar::GetSlopeAdherence(
    const GmVec3& force, float* lateralAdherence,
    float* axialAdherence) const {
    if (lateralAdherence == nullptr || axialAdherence == nullptr ||
        g_tuning == nullptr) {
        return;
    }

    const float squaredLength =
        force.x * force.x + force.y * force.y + force.z * force.z;
    // Exact 0x7BEB68 comparison: a degenerate force leaves both caller-owned
    // defaults untouched. ComputeForces initializes those defaults to one.
    if (squaredLength <= TmForeverPhysicsConstants::kNormalizeSquaredEpsilon) {
        return;
    }

    const float forceLength = std::sqrt(squaredLength);
    const float verticalRatio = std::abs(force.y / forceLength);
    const auto mapAdherence = [verticalRatio](float minimum, float maximum) {
        if (verticalRatio < minimum) return 0.0f;
        if (verticalRatio > maximum) return 1.0f;

        const float ratio =
            (verticalRatio - minimum) / (maximum - minimum);
        return 1.0f - std::cos(
            ratio * static_cast<float>(TmForeverPhysicsConstants::kPi) *
            0.5f);
    };

    *lateralAdherence = mapAdherence(
        g_tuning->m_lateralSlopeAdherenceMin,
        g_tuning->m_lateralSlopeAdherenceMax);
    *axialAdherence = mapAdherence(
        g_tuning->m_axialSlopeAdherenceMin,
        g_tuning->m_axialSlopeAdherenceMax);
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
    
    float p11_temp[4] = {1.0f, 1.0f, 1.0f, 1.0f}; // temp
    void* p10_temp = p11_temp; // temp
    float p12_temp[4] = {1.0f, 1.0f, 1.0f, 1.0f}; // temp
    
    ComputeForcesModel3_Exact(dt, &p3, this->m_inputGas, this->m_inputBrake, &p6, &p7, this->m_inputSteer, 1, p10_temp, (int*)p11_temp, p12_temp);
    
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

void CSceneVehicleCar::ComputeForcesModel6(CSceneVehicleCar* pilot, float dt) {
    if (m_hmsItem == nullptr || g_tuning == nullptr ||
        g_tuning->m_steerModel != 5 || !IsGroundContact()) {
        // Airborne, water, and non-Stadium paths have not yet been separated
        // from the old translation. Keep the prior behavior for those states
        // while the native Model6 port advances branch by branch.
        ComputeForcesModel3(pilot, dt);
        return;
    }

    GmVec3 linearSpeed(0.0f, 0.0f, 0.0f);
    m_hmsItem->GetLinearSpeed(m_hmsItem, &linearSpeed);

    const float c = std::cos(g_carYaw);
    const float s = std::sin(g_carYaw);
    const float localLateralSpeed = linearSpeed.x * c - linearSpeed.z * s;
    const float localForwardSpeed = linearSpeed.x * s + linearSpeed.z * c;

    bool hasSlippingWheel = false;
    for (uint32_t i = 0; i < m_wheels.GetCount(); ++i) {
        hasSlippingWheel |= m_wheels[i].m_isSlipping != 0;
    }

    StadiumVehicleMaterials::GroundValues groundMaterial{};
    int hasGroundMaterial = 0;
    ComputeVehicleGroundMaterialVals(&groundMaterial, &hasGroundMaterial);

    float lateralSlopeAdherence = 1.0f;
    float axialSlopeAdherence = 1.0f;
    GmVec3 worldForce(0.0f, 0.0f, 0.0f);
    m_hmsItem->GetForce(m_hmsItem, &worldForce);

    // CHmsItem::GetForce reaches CHmsDyna::GetLocalForce in the executable,
    // which rotates the raw dynamics force by the inverse chassis transform.
    // Reconstruct that direction basis from the harness's yaw and contact-up
    // state before passing the vector to the exact slope function.
    const VehicleChassisBasis chassisBasis = GetChassisBasis(*this);
    const GmVec3 localForce = WorldToLocal(chassisBasis, worldForce);
    GetSlopeAdherence(
        localForce, &lateralSlopeAdherence, &axialSlopeAdherence);

    // This is the currently ported ordinary-drive subset of the Model6 tail.
    // Its curve, material coefficient, gas multiplier, and axial slope input
    // now match the fixed executable; the other drive states remain below.
    const bool isOrdinaryForwardDrive =
        m_engine.m_field_0x28 == 0 &&
        m_inputBrake == 0.0f &&
        m_freeWheeling == 0 &&
        m_field_0x600 == 0 &&
        !hasSlippingWheel &&
        localForwardSpeed >= 0.0f;

    if (isOrdinaryForwardDrive) {
        const float longitudinalForce =
            g_tuning->M5GetAccelFromSpeed(localForwardSpeed) *
            m_inputGas * groundMaterial.accelerationCoef *
            axialSlopeAdherence;
        GmVec3 localDriveForce(0.0f, 0.0f, longitudinalForce);
        AddVehicleCentralForce(
            this, reinterpret_cast<CSceneVehicleCar*>(&localDriveForce), nullptr);
    } else {
        // Reverse selection, braking, freewheeling, wheel-slip blending, and
        // special burnout states still use the translated fallback.
        ComputeForcesModel3(pilot, dt);
    }

    GmVec3 angularSpeed(0.0f, 0.0f, 0.0f);
    m_hmsItem->GetAngularSpeed(m_hmsItem, &angularSpeed);

    // Exact normal-ground subset at 0x7C5BE5..0x7C5EF0. Model6 evaluates the
    // lateral velocity at each axle, including yaw velocity, and applies half
    // of SideFriction1 per wheel. The over-limit force blend is exact; its
    // aggregate state bookkeeping after the wheel loop remains to be ported.
    const float halfWheelbase = 0.5f * m_field_0x840;
    const float maxSideForce = g_tuning->GetMaxSideFrictionFromSpeed(localForwardSpeed);
    const float steerSpeedFactor = g_tuning->GetModel6SteerSpeedFactor(localForwardSpeed);
    const float driveTorque = g_tuning->GetSteerDriveTorqueFromSpeed(localForwardSpeed);
    const float reverseSign = m_engine.m_field_0x28 != 0 ? -1.0f : 1.0f;
    float lateralForceSum = 0.0f;
    float yawTorque = 0.0f;

    for (uint32_t i = 0; i < m_wheels.GetCount(); ++i) {
        const SSimulationWheel& wheel = m_wheels[i];
        const float axleOffset = wheel.m_isSteerable != 0 ? halfWheelbase : -halfWheelbase;
        const float axleLateralSpeed = localLateralSpeed + angularSpeed.y * axleOffset;
        const float rawLateralForce =
            -g_tuning->m_sideFriction1 * 0.5f * axleLateralSpeed;
        const float lateralForce =
            g_tuning->GetModel6SideForce(rawLateralForce, maxSideForce);
        lateralForceSum += lateralForce;

        float axleTorqueForce = g_tuning->m_steerGroundTorque * lateralForce;
        if (wheel.m_isSteerable != 0) {
            const float slippingCoef = wheel.m_isSlipping != 0
                ? g_tuning->m_steerGroundTorqueSlippingCoef
                : 1.0f;
            // Crucially, SteerGroundTorque does not multiply the commanded
            // steer term in the original instruction stream.
            axleTorqueForce -= steerSpeedFactor * m_smoothedSteer *
                               driveTorque * reverseSign * slippingCoef;
        }
        yawTorque += axleOffset * axleTorqueForce;
    }

    // The original obtains the translational side reaction through its wheel
    // contact path. Apply the equivalent aggregate force while that contact
    // projection is still represented semantically in the standalone build.
    GmVec3 localSideForce(lateralForceSum, 0.0f, 0.0f);
    AddVehicleCentralForce(this, reinterpret_cast<CSceneVehicleCar*>(&localSideForce), nullptr);
    GmVec3 localTorque(0.0f, yawTorque, 0.0f);
    AddVehicleTorque(this, reinterpret_cast<CSceneVehicleCar*>(&localTorque), nullptr);
}


void CSceneVehicleCar::WheelAddForceToVehicle(
    SSimulationWheel* wheel, const GmVec3* localContactPosition) {
    if (wheel == nullptr || localContactPosition == nullptr ||
        g_tuning == nullptr || wheel->m_hasGroundContact == 0) {
        return;
    }

    // Stadium uses ShockModel::Demo03 (2). At 0x7C184B..0x7C18D9 the fixed
    // executable evaluates the spring-damper scalar in this exact order and
    // applies it on local +Y at wheel +0xA8. The other shock-model branches
    // remain separate because model zero has an additional tuning factor.
    if (g_tuning->m_shockModel != 2) return;

    const float suspensionForce =
        (g_tuning->m_absorbingValRest -
         wheel->m_realTimeState.m_compression) *
            g_tuning->m_absorbingValKi -
        g_tuning->m_absorbingValKa *
            wheel->m_realTimeState.m_velocity;
    wheel->m_suspensionForce = suspensionForce;

    GmVec3 localForce(0.0f, suspensionForce, 0.0f);
    AddVehicleForce(
        this, reinterpret_cast<CSceneVehicleCar*>(&localForce),
        const_cast<GmVec3*>(localContactPosition), nullptr);
}

void CSceneVehicleCar::AddVehicleTorque(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3) {
    if (this->m_hmsItem) {
        const GmVec3* local_t = reinterpret_cast<const GmVec3*>(param_2);
        const GmVec3 global_t = LocalToWorld(GetChassisBasis(*this), *local_t);
        this->m_hmsItem->AddTorque(this->m_hmsItem, &global_t);
    }
}
extern float g_carYaw;
void CSceneVehicleCar::AddVehicleCentralForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3) {
    if (this->m_hmsItem) {
        const GmVec3* localForce = reinterpret_cast<const GmVec3*>(param_2);
        const GmVec3 globalForce =
            LocalToWorld(GetChassisBasis(*this), *localForce);
        this->m_hmsItem->AddForce(this->m_hmsItem, &globalForce, nullptr);
    }
}
void CSceneVehicleCar::AddVehicleForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3, GmVec3 *param_4) {
    if (this->m_hmsItem) {
        const GmVec3* local_f = reinterpret_cast<const GmVec3*>(param_2);
        const VehicleChassisBasis chassisBasis = GetChassisBasis(*this);
        const GmVec3 global_f = LocalToWorld(chassisBasis, *local_f);
        
        GmVec3* p = param_3;
        if (p) {
            const GmVec3 global_p = LocalToWorld(chassisBasis, *p);
            this->m_hmsItem->AddForce(this->m_hmsItem, &global_f, &global_p);
            
            GmVec3 local_torque;
            local_torque.x = p->y * local_f->z - p->z * local_f->y;
            local_torque.y = p->z * local_f->x - p->x * local_f->z;
            local_torque.z = p->x * local_f->y - p->y * local_f->x;
            
            const GmVec3 global_torque =
                LocalToWorld(chassisBasis, local_torque);
            this->m_hmsItem->AddTorque(this->m_hmsItem, &global_torque);
        } else {
            this->m_hmsItem->AddForce(this->m_hmsItem, &global_f, nullptr);
        }
    }
}
