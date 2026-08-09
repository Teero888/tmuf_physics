#include "CCallbackSceneVehicleCarComputeForces.hpp"
#include "CSceneVehicleCar.hpp"

CCallbackSceneVehicleCarComputeForces::~CCallbackSceneVehicleCarComputeForces() {}

void CCallbackSceneVehicleCarComputeForces::ComputeForces(
    CHmsItem* item, float dt) {
    if (item == nullptr || item->m_sceneMobil == nullptr) return;
    CSceneVehicleCar* car =
        static_cast<CSceneVehicleCar*>(item->m_sceneMobil);
    car->ComputeForces(nullptr, item, dt);
}

CCallbackSceneVehicleCarComputeForces*
CCallbackSceneVehicleCarComputeForces::Instance() {
    static CCallbackSceneVehicleCarComputeForces callback;
    return &callback;
}
