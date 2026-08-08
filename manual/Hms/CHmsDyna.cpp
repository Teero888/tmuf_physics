#include <cmath>
#include "CHmsDyna.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include <cstdio>

extern CSceneVehicleCarTuning* g_tuning;

CHmsDyna::CHmsDyna() {
    *(float*)&m_field_0x3a4 = 0.0f;
    *(float*)&m_field_0x3a8 = 0.0f;
    *(float*)&m_field_0x3ac = 0.0f;
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

void CHmsDyna::SetLinearSpeed(CHmsItem* param_1, GmVec3* param_2) {
    *(float*)&m_field_0x3ac = param_2->x;
    *(float*)&m_field_0x3a8 = param_2->y;
    *(float*)&m_field_0x3a4 = param_2->z;
}

void CHmsDyna::SetTranslation(GmIso4* param_1, GmVec3* param_2) {
    // Offset mapping for translation in state or dyna
    // Usually dyna has the current physical pos.
}

// Custom stub logic for the manual physics harness
GmVec3 g_stub_forces(0,0,0);
GmVec3 g_stub_torques(0,0,0);
GmVec3 g_stub_pos(0,0,0);
GmVec3 g_stub_angVel(0,0,0);
static GmVec3 g_stub_preStepLinearSpeed(0,0,0);
static GmVec3 g_stub_preStepAngularSpeed(0,0,0);
extern float g_carYaw;

void CHmsDyna::AddLocalImpulse(GmVec3* param_2) {}
void CHmsDyna::AddLocalTorque(GmVec3* param_2) { g_stub_torques += *param_2; }
void CHmsDyna::GetLocalAngularSpeed(GmVec3* param_2) {
    *param_2 = g_stub_angVel;
}
void CHmsDyna::SetLocalAngularSpeed(GmVec3* param_2) {
    if (param_2 != nullptr) g_stub_angVel = *param_2;
}
void CHmsDyna::SetLocalLinearSpeed(GmVec3* param_2) {
    *(float*)&m_field_0x3ac = param_2->x;
    *(float*)&m_field_0x3a8 = param_2->y;
    *(float*)&m_field_0x3a4 = param_2->z;
}
void CHmsDyna::SetLocalTorque(GmVec3* param_2) {}

int CHmsDyna::IsStateDifferentFrom(CHmsItem* param_1, GmIso4* param_2) { return 0; }
void CHmsDyna::AddStateForPrediction(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t param_3, uint32_t param_4) {}
void CHmsDyna::SaveState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t* param_3, uint32_t param_4) {}
void CHmsDyna::Reset(GmFrustumIso4* param_1) {}
void CHmsDyna::OldRestoreStaticState(CHmsCorpus* param_1, CClassicBufferMemory* param_2, int param_3, uint8_t param_4, int param_5) {}
void CHmsDyna::RestoreStaticState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, int param_3, uint32_t param_4, uint32_t param_5, int param_6) {}
void CHmsDyna::RotateOf(CHmsCorpus* param_1, GmMat3* param_2) {}
void CHmsDyna::SetDynamicType(CHmsItem* param_1, int param_2) {}
void CHmsDyna::SetLocation(CPlugTree* param_1, GmIso4* param_2) {}

void CHmsDyna::Integrate(float dt) {
    const float mass = g_tuning != nullptr ? g_tuning->m_mass : 1.0f;
    const float yawInertia = g_tuning != nullptr ? g_tuning->GetYawInertia() : (25.0f / 12.0f);

    // CHmsDyna::IntegrateStep at 0x533510 advances translation/orientation
    // from the old speeds before it integrates force and torque. Preserve
    // those pre-step values for Move instead of using symplectic Euler.
    g_stub_preStepLinearSpeed = GmVec3(
        *(float*)&m_field_0x3ac,
        *(float*)&m_field_0x3a8,
        *(float*)&m_field_0x3a4);
    g_stub_preStepAngularSpeed = g_stub_angVel;

    GmVec3 acc = g_stub_forces / mass;
    *(float*)&m_field_0x3ac += acc.x * dt;
    *(float*)&m_field_0x3a8 += acc.y * dt;
    *(float*)&m_field_0x3a4 += acc.z * dt;
    
    // The harness currently exposes yaw only. Use the exact Stadium box-tensor
    // component instead of treating InertiaMass as a scalar moment of inertia.
    g_stub_angVel.y += (g_stub_torques.y / yawInertia) * dt;

    const float angularFluidFriction =
        g_tuning != nullptr ? g_tuning->m_angularFluidFrictionCoef1 : 0.4f;
    g_stub_angVel = g_stub_angVel * std::exp(-angularFluidFriction * dt);

    // No gravity to stop infinite falling
    // g_stub_forces.y += -9.81f * mass;

    g_stub_forces = GmVec3(0,0,0);
    g_stub_torques = GmVec3(0,0,0);
}

void CHmsDyna::Move(float dt) {
    // IntegrateStep computes these transforms before the new velocities.
    g_stub_pos += g_stub_preStepLinearSpeed * dt;
    g_carYaw += g_stub_preStepAngularSpeed.y * dt;
}

// In CHmsItem, we need to map to these globals for the simple manual test:
// Wait, actually CHmsItem AddForce maps to AddLocalForce here
void CHmsDyna::AddLocalForce(GmVec3* param_2) {
    float c = std::cos(g_carYaw);
    float s = std::sin(g_carYaw);
    GmVec3 globalForce(
        param_2->x * c - param_2->z * s,
        param_2->y,
        -param_2->x * s - param_2->z * c
    );
    g_stub_forces += globalForce;
}

void CHmsDyna::GetLocalForce(GmVec3* param_2) {
    *param_2 = g_stub_forces;
}

void CHmsDyna::SetLocalForce(GmVec3* param_2) {
    g_stub_forces = *param_2;
}
