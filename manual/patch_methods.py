import re

with open('Scene/CSceneVehicleCar.hpp', 'r') as f:
    code = f.read()

decl = """
    void WheelAddForceToVehicle(CSceneVehicleCar *param_1, void *param_2, void *param_3, void *param_4);
    void AddVehicleTorque(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3);
    void AddVehicleCentralForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3);
    void AddVehicleForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3, GmVec3 *param_4);
"""

if "WheelAddForceToVehicle" not in code:
    code = code.replace("public:", "public:\n" + decl)
    with open('Scene/CSceneVehicleCar.hpp', 'w') as f:
        f.write(code)

with open('Scene/CSceneVehicleCar.cpp', 'r') as f:
    code2 = f.read()

impl = """
void CSceneVehicleCar::WheelAddForceToVehicle(CSceneVehicleCar *param_1, void *param_2, void *param_3, void *param_4) {}
void CSceneVehicleCar::AddVehicleTorque(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3) {
    if (this->m_hmsItem) {
        this->m_hmsItem->AddTorque(this->m_hmsItem, (GmVec3*)param_2);
    }
}
void CSceneVehicleCar::AddVehicleCentralForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3) {
    if (this->m_hmsItem) {
        this->m_hmsItem->AddForce(this->m_hmsItem, (GmVec3*)param_2, nullptr);
    }
}
void CSceneVehicleCar::AddVehicleForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3, GmVec3 *param_4) {
    if (this->m_hmsItem) {
        this->m_hmsItem->AddForce(this->m_hmsItem, (GmVec3*)param_2, param_3);
    }
}
"""

if "AddVehicleTorque" not in code2:
    code2 += impl
    with open('Scene/CSceneVehicleCar.cpp', 'w') as f:
        f.write(code2)
