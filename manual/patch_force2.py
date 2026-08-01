import re

with open("Scene/CSceneVehicleCar.cpp", "r") as f:
    scenecar = f.read()

# Find the function and replace it
def repl(match):
    return """void CSceneVehicleCar::WheelAddForceToVehicle(CSceneVehicleCar *param_1, void *param_2_void, void *param_3_void, void *param_4) {
    SSimulationWheel* wheel = (SSimulationWheel*)param_2_void;
    GmVec3* normal = (GmVec3*)param_3_void;
    if (wheel == nullptr) return;
    
    int isContact = *(int*)((char*)wheel + 0x124);
    if (isContact != 0) {
        // Apply generic suspension force
        float forceMag = 15000.0f; // Approx weight of car
        GmVec3 f(0, forceMag, 0);
        GmVec3 pos(0,0,0);
        AddVehicleForce(this, (CSceneVehicleCar*)&f, &pos, nullptr);
    }
}"""

scenecar = re.sub(r'void CSceneVehicleCar::WheelAddForceToVehicle\(CSceneVehicleCar \*param_1, void \*param_2_void, void \*param_3_void, void \*param_4\) \{.*?\}\n', repl, scenecar, flags=re.DOTALL)

with open("Scene/CSceneVehicleCar.cpp", "w") as f:
    f.write(scenecar)

print("Patched")
