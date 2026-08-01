with open('Hms/CHmsDyna.cpp', 'r') as f:
    code = f.read()

code = code.replace(
    "void CHmsDyna::AddLocalTorque(GmVec3* param_2) {}",
    "void CHmsDyna::AddLocalTorque(GmVec3* param_2) { g_stub_torques += *param_2; }"
)

code = code.replace(
    "static GmVec3 g_stub_forces(0,0,0);\nstatic GmVec3 g_stub_pos(0,0,0);",
    "static GmVec3 g_stub_forces(0,0,0);\nstatic GmVec3 g_stub_pos(0,0,0);\nGmVec3 g_stub_torques(0,0,0);\nGmVec3 g_stub_angVel(0,0,0);\nextern float g_carYaw;"
)

integrate_orig = """void CHmsDyna::Integrate(float dt) {
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
}"""

integrate_new = """void CHmsDyna::Integrate(float dt) {
    float mass = 1500.0f;
    float inertia = 2000.0f; // Approx moment of inertia

    GmVec3 acc = g_stub_forces / mass;
    *(float*)&m_field_0x3ac += acc.x * dt;
    *(float*)&m_field_0x3a8 += acc.y * dt;
    *(float*)&m_field_0x3a4 += acc.z * dt;
    
    GmVec3 angAcc = g_stub_torques / inertia;
    g_stub_angVel += angAcc * dt;

    // Apply angular drag so it doesn't spin forever
    g_stub_angVel = g_stub_angVel * 0.95f; 

    // Update global yaw (simplified 1D rotation for now)
    g_carYaw += g_stub_angVel.y * dt;

    g_stub_forces = GmVec3(0,0,0);
    g_stub_torques = GmVec3(0,0,0);
}"""

code = code.replace(integrate_orig, integrate_new)

with open('Hms/CHmsDyna.cpp', 'w') as f:
    f.write(code)

