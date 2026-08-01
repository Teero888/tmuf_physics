with open('Hms/CHmsDyna.cpp', 'r') as f:
    code = f.read()

move_orig = """void CHmsDyna::Move(float dt) {
    // Update position (p = p0 + vt)
    GmVec3 vel(*(float*)&m_field_0x3ac, *(float*)&m_field_0x3a8, *(float*)&m_field_0x3a4);
    g_stub_pos += vel * dt;
}"""

move_new = """void CHmsDyna::Move(float dt) {
    // Update position (p = p0 + vt)
    GmVec3 vel(*(float*)&m_field_0x3ac, *(float*)&m_field_0x3a8, *(float*)&m_field_0x3a4);
    GmVec3 vel_global;
    #include <cmath>
    vel_global.x = vel.x * cos(g_carYaw) + vel.z * sin(g_carYaw);
    vel_global.y = vel.y;
    vel_global.z = -vel.x * sin(g_carYaw) + vel.z * cos(g_carYaw);
    g_stub_pos += vel_global * dt;
}"""

code = code.replace(move_orig, move_new)

with open('Hms/CHmsDyna.cpp', 'w') as f:
    f.write(code)

