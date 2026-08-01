with open('Scene/CSceneVehicleCar.cpp', 'r') as f:
    code = f.read()

code = code.replace(
    "void CSceneVehicleCar::AddVehicleForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3, GmVec3 *param_4) {\n    if (this->m_hmsItem) {\n        this->m_hmsItem->AddForce(this->m_hmsItem, (GmVec3*)param_2, param_3);\n    }\n}",
    """void CSceneVehicleCar::AddVehicleForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3, GmVec3 *param_4) {
    if (this->m_hmsItem) {
        this->m_hmsItem->AddForce(this->m_hmsItem, (GmVec3*)param_2, param_3);
        if (param_3) {
            GmVec3 f = *(GmVec3*)param_2;
            GmVec3 p = *param_3;
            GmVec3 torque;
            torque.x = p.y * f.z - p.z * f.y;
            torque.y = p.z * f.x - p.x * f.z;
            torque.z = p.x * f.y - p.y * f.x;
            this->m_hmsItem->AddTorque(this->m_hmsItem, &torque);
        }
    }
}"""
)

with open('Scene/CSceneVehicleCar.cpp', 'w') as f:
    f.write(code)

