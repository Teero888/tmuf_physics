#include <cmath>
#include "CHmsDyna.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include <cstdio>

extern CSceneVehicleCarTuning* g_tuning;

CHmsDyna::CHmsDyna() {
    *(float*)&m_field_0x3a4 = 0.0f;
    *(float*)&m_field_0x3a8 = 0.0f;
    *(float*)&m_field_0x3ac = 0.0f;
    m_position = GmVec3(0.0f, 0.0f, 0.0f);
    m_force = GmVec3(0.0f, 0.0f, 0.0f);
    m_torque = GmVec3(0.0f, 0.0f, 0.0f);
    m_angularSpeed = GmVec3(0.0f, 0.0f, 0.0f);
    m_preStepLinearSpeed = GmVec3(0.0f, 0.0f, 0.0f);
    m_preStepAngularSpeed = GmVec3(0.0f, 0.0f, 0.0f);
    m_yaw = 0.0f;
}

CHmsDyna::~CHmsDyna() {}

void CHmsDyna::GetLocalLinearSpeed(GmVec3* param_2) {
    param_2->x = *(float*)&m_field_0x3ac;
    param_2->y = *(float*)&m_field_0x3a8;
    param_2->z = *(float*)&m_field_0x3a4;
}

void CHmsDyna::GetSpeed(CScenePoc* param_1, GmVec3* param_2) {
    if (param_2) {
        param_2->x = *(float*)&m_field_0x3ac;
        param_2->y = *(float*)&m_field_0x3a8;
        param_2->z = *(float*)&m_field_0x3a4;
    }
}

void CHmsDyna::GetLinearSpeed(CHmsItem* param_1, GmVec3* param_2) {
    GetLocalLinearSpeed(param_2);
}

void CHmsDyna::GetAngularSpeed(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) *param_2 = m_angularSpeed;
}

void CHmsDyna::GetForce(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) *param_2 = m_force;
}

void CHmsDyna::SetLinearSpeed(CHmsItem* param_1, GmVec3* param_2) {
    *(float*)&m_field_0x3ac = param_2->x;
    *(float*)&m_field_0x3a8 = param_2->y;
    *(float*)&m_field_0x3a4 = param_2->z;
}

void CHmsDyna::SetAngularSpeed(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) m_angularSpeed = *param_2;
}

void CHmsDyna::SetForce(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) m_force = *param_2;
}

void CHmsDyna::SetTorque(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) m_torque = *param_2;
}

void CHmsDyna::SetTranslation(GmIso4* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) {
        m_position = *param_2;
    } else if (param_1 != nullptr) {
        m_position = GmVec3(param_1->tX, param_1->tY, param_1->tZ);
    }
}

void CHmsDyna::AddForce(
    CHmsItem* param_1, GmVec3* param_2, GmVec3* param_3) {
    if (param_2 != nullptr) m_force += *param_2;
}

void CHmsDyna::AddImpulse(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 == nullptr) return;
    const float mass = g_tuning != nullptr ? g_tuning->m_mass : 1.0f;
    GmVec3 speed;
    GetLocalLinearSpeed(&speed);
    speed += *param_2 / mass;
    SetLocalLinearSpeed(&speed);
}

void CHmsDyna::AddTorque(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) m_torque += *param_2;
}

void CHmsDyna::AddLocalImpulse(GmVec3* param_2) {
    AddImpulse(nullptr, param_2);
}
void CHmsDyna::AddLocalTorque(GmVec3* param_2) {
    if (param_2 != nullptr) m_torque += *param_2;
}
void CHmsDyna::GetLocalAngularSpeed(GmVec3* param_2) {
    if (param_2 != nullptr) *param_2 = m_angularSpeed;
}
void CHmsDyna::SetLocalAngularSpeed(GmVec3* param_2) {
    if (param_2 != nullptr) m_angularSpeed = *param_2;
}
void CHmsDyna::SetLocalLinearSpeed(GmVec3* param_2) {
    *(float*)&m_field_0x3ac = param_2->x;
    *(float*)&m_field_0x3a8 = param_2->y;
    *(float*)&m_field_0x3a4 = param_2->z;
}
void CHmsDyna::SetLocalTorque(GmVec3* param_2) {
    if (param_2 != nullptr) m_torque = *param_2;
}

int CHmsDyna::IsStateDifferentFrom(CHmsItem* param_1, GmIso4* param_2) { return 0; }
void CHmsDyna::AddStateForPrediction(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t param_3, uint32_t param_4) {}
void CHmsDyna::SaveState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t* param_3, uint32_t param_4) {}
void CHmsDyna::Reset(GmFrustumIso4* param_1) {
    GmVec3 zero(0.0f, 0.0f, 0.0f);
    SetLocalLinearSpeed(&zero);
    m_force = zero;
    m_torque = zero;
    m_angularSpeed = zero;
    m_preStepLinearSpeed = zero;
    m_preStepAngularSpeed = zero;
}
void CHmsDyna::OldRestoreStaticState(CHmsCorpus* param_1, CClassicBufferMemory* param_2, int param_3, uint8_t param_4, int param_5) {}
void CHmsDyna::RestoreStaticState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, int param_3, uint32_t param_4, uint32_t param_5, int param_6) {}
void CHmsDyna::RotateOf(CHmsCorpus* param_1, GmMat3* param_2) {}
void CHmsDyna::SetDynamicType(CHmsItem* param_1, int param_2) {}
void CHmsDyna::SetLocation(CPlugTree* param_1, GmIso4* param_2) {
    if (param_2 == nullptr) return;
    m_position = GmVec3(param_2->tX, param_2->tY, param_2->tZ);
    m_yaw = std::atan2(param_2->m02, param_2->m22);
}

void CHmsDyna::Integrate(float dt) {
    const float mass = g_tuning != nullptr ? g_tuning->m_mass : 1.0f;
    const float yawInertia = g_tuning != nullptr ? g_tuning->GetYawInertia() : (25.0f / 12.0f);

    // CHmsDyna::IntegrateStep at 0x533510 advances translation/orientation
    // from the old speeds before it integrates force and torque. Preserve
    // those pre-step values for Move instead of using symplectic Euler.
    m_preStepLinearSpeed = GmVec3(
        *(float*)&m_field_0x3ac,
        *(float*)&m_field_0x3a8,
        *(float*)&m_field_0x3a4);
    m_preStepAngularSpeed = m_angularSpeed;

    GmVec3 acc = m_force / mass;
    *(float*)&m_field_0x3ac += acc.x * dt;
    *(float*)&m_field_0x3a8 += acc.y * dt;
    *(float*)&m_field_0x3a4 += acc.z * dt;
    
    // The harness currently exposes yaw only. Use the exact Stadium box-tensor
    // component instead of treating InertiaMass as a scalar moment of inertia.
    m_angularSpeed.y += (m_torque.y / yawInertia) * dt;

    const float angularFluidFriction =
        g_tuning != nullptr ? g_tuning->m_angularFluidFrictionCoef1 : 0.4f;
    m_angularSpeed =
        m_angularSpeed * std::exp(-angularFluidFriction * dt);

    // No gravity to stop infinite falling
    // m_force.y += -9.81f * mass;

    m_force = GmVec3(0,0,0);
    m_torque = GmVec3(0,0,0);
}

void CHmsDyna::Move(float dt) {
    // IntegrateStep computes these transforms before the new velocities.
    m_position += m_preStepLinearSpeed * dt;
    m_yaw += m_preStepAngularSpeed.y * dt;
}

// In CHmsItem, we need to map to these globals for the simple manual test:
// Wait, actually CHmsItem AddForce maps to AddLocalForce here
void CHmsDyna::AddLocalForce(GmVec3* param_2) {
    if (param_2 == nullptr) return;
    float c = std::cos(m_yaw);
    float s = std::sin(m_yaw);
    GmVec3 globalForce(
        param_2->x * c - param_2->z * s,
        param_2->y,
        -param_2->x * s - param_2->z * c
    );
    m_force += globalForce;
}

void CHmsDyna::GetLocalForce(GmVec3* param_2) {
    if (param_2 != nullptr) *param_2 = m_force;
}

void CHmsDyna::SetLocalForce(GmVec3* param_2) {
    if (param_2 != nullptr) m_force = *param_2;
}
