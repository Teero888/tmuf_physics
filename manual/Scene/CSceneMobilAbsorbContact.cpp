#include "CSceneMobilAbsorbContact.hpp"
#include "CSceneMobil.hpp"

CSceneMobilAbsorbContact::~CSceneMobilAbsorbContact() = default;

void CSceneMobilAbsorbContact::AbsorbContact(
    CHmsItem* item,
    CHmsPhysicalContact* contact) {
    if (item == nullptr || item->m_sceneMobil == nullptr) return;
    static_cast<CSceneMobil*>(item->m_sceneMobil)->AbsorbContact(contact);
}

CSceneMobilAbsorbContact* CSceneMobilAbsorbContact::Instance() {
    static CSceneMobilAbsorbContact callback;
    return &callback;
}
