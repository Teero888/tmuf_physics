with open('Scene/CSceneVehicleCar.cpp', 'r') as f:
    code = f.read()

code = code.replace(
    "void CSceneVehicleCar::AddVehicleTorque(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3) {\n    if (this->m_hmsItem) {\n        this->m_hmsItem->AddTorque(this->m_hmsItem, (GmVec3*)param_2);\n    }\n}",
    "void CSceneVehicleCar::AddVehicleTorque(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3) {\n    if (this->m_hmsItem) {\n        GmVec3* t = (GmVec3*)param_2;\n        if (t->x != 0 || t->y != 0 || t->z != 0) { printf(\"Torque: %f, %f, %f\\n\", t->x, t->y, t->z); }\n        this->m_hmsItem->AddTorque(this->m_hmsItem, (GmVec3*)param_2);\n    }\n}"
)

with open('Scene/CSceneVehicleCar.cpp', 'w') as f:
    f.write(code)

