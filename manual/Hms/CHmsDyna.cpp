#include "CHmsDyna.hpp"

CHmsDyna::CHmsDyna() {
    m_field_0x3a4 = 0;
    m_field_0x3a8 = 0;
    m_field_0x3ac = 0;
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

void CHmsDyna::AddLocalImpulse(GmVec3* param_2) {}
void CHmsDyna::AddLocalTorque(GmVec3* param_2) {}
void CHmsDyna::GetLocalAngularSpeed(GmVec3* param_2) {
    param_2->x = 0; param_2->y = 0; param_2->z = 0;
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

// Custom stub logic for the manual physics harness
static GmVec3 g_stub_forces(0,0,0);
static GmVec3 g_stub_pos(0,0,0);

void CHmsDyna::Integrate(float dt) {
    // F = m * a -> a = F / m
    // We assume m = 1500 for car for now
    float mass = 1500.0f;
    GmVec3 acc = g_stub_forces / mass;
    
    // Update velocity (v = v0 + at)
    *(float*)&m_field_0x3ac += acc.x * dt;
    *(float*)&m_field_0x3a8 += acc.y * dt;
    *(float*)&m_field_0x3a4 += acc.z * dt;
    
    // Clear forces
    g_stub_forces = GmVec3(0,0,0);
}

void CHmsDyna::Move(float dt) {
    // Update position (p = p0 + vt)
    GmVec3 vel(*(float*)&m_field_0x3ac, *(float*)&m_field_0x3a8, *(float*)&m_field_0x3a4);
    g_stub_pos += vel * dt;
}

// In CHmsItem, we need to map to these globals for the simple manual test:
// Wait, actually CHmsItem AddForce maps to AddLocalForce here
void CHmsDyna::AddLocalForce(GmVec3* param_2) {
    g_stub_forces += *param_2;
}

void CHmsDyna::GetLocalForce(GmVec3* param_2) {
    *param_2 = g_stub_forces;
}

void CHmsDyna::SetLocalForce(GmVec3* param_2) {
    g_stub_forces = *param_2;
}
