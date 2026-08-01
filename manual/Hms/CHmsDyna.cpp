#include <cmath>
#include "CHmsDyna.hpp"
#include <cstdio>

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
extern float g_carYaw;

void CHmsDyna::AddLocalImpulse(GmVec3* param_2) {}
void CHmsDyna::AddLocalTorque(GmVec3* param_2) { g_stub_torques += *param_2; }
void CHmsDyna::GetLocalAngularSpeed(GmVec3* param_2) {
    *param_2 = g_stub_angVel;
}
void CHmsDyna::SetLocalAngularSpeed(GmVec3* param_2) {}
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
    float mass = 1.0f; // Trackmania uses mass=1
    float inertia = 2000.0f; // Approx moment of inertia

    GmVec3 acc = g_stub_forces / mass;
    *(float*)&m_field_0x3ac += acc.x * dt;
    *(float*)&m_field_0x3a8 += acc.y * dt;
    *(float*)&m_field_0x3a4 += acc.z * dt;
    
    GmVec3 angAcc = g_stub_torques / inertia;
    g_stub_angVel += angAcc * dt;

    // Apply angular drag so it doesn't spin forever
    g_stub_angVel = g_stub_angVel * 0.95f; 

    // No gravity to stop infinite falling
    // g_stub_forces.y += -9.81f * mass;

    g_stub_forces = GmVec3(0,0,0);
    g_stub_torques = GmVec3(0,0,0);
}

void CHmsDyna::Move(float dt) {
    // Update position (p = p0 + v*dt)
    // Velocity is stored in world space
    GmVec3 vel(*(float*)&m_field_0x3ac, *(float*)&m_field_0x3a8, *(float*)&m_field_0x3a4);
    printf("DYNA MOVE: vel=(%f, %f, %f) pos=(%f, %f, %f)\n", vel.x, vel.y, vel.z, g_stub_pos.x, g_stub_pos.y, g_stub_pos.z);
    g_stub_pos += vel * dt;
    g_carYaw += g_stub_angVel.y * dt;
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
