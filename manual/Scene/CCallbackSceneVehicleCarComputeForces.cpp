#include "CCallbackSceneVehicleCarComputeForces.hpp"
#include "CSceneVehicleCar.hpp"

CCallbackSceneVehicleCarComputeForces::~CCallbackSceneVehicleCarComputeForces() {}

void CCallbackSceneVehicleCarComputeForces::ComputeForces(CCallbackSceneToyBroomStickComputeForces* param_1, CHmsItem* param_2, float dt) {
    // In our manual structure, we'll assume the car logic is triggered correctly.
    // In the actual engine, this callback is attached to a car and calls its ComputeForces.
}
