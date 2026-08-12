#include "CCallbackSceneVehicleCarAfterContacts.hpp"
#include "CSceneVehicleCar.hpp"

CCallbackSceneVehicleCarAfterContacts::~CCallbackSceneVehicleCarAfterContacts() =
    default;

void CCallbackSceneVehicleCarAfterContacts::AfterContacts(CHmsItem* item) {
    if (item == nullptr || item->m_sceneMobil == nullptr) return;
    static_cast<CSceneVehicleCar*>(item->m_sceneMobil)->AfterContacts();
}

CCallbackSceneVehicleCarAfterContacts*
CCallbackSceneVehicleCarAfterContacts::Instance() {
    static CCallbackSceneVehicleCarAfterContacts callback;
    return &callback;
}
