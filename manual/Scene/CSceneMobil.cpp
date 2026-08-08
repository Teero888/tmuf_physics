#include "CSceneMobil.hpp"
#include "CHmsCorpus.hpp"
#include "CHmsDyna.hpp"
#include "CHmsItem.hpp"
#include "GmIso4.hpp"
#include "GmVec3.hpp"

CSceneMobil::CSceneMobil() : CMwNod(), m_hmsItem(nullptr), m_nod2c(nullptr), m_nod44(nullptr) {}
CSceneMobil::~CSceneMobil() {}

CMwNod* CSceneMobil::MwNewCSceneMobil() { return new CSceneMobil(); }
uint32_t CSceneMobil::GetMwClassId() { return 0x06003000; }

void* CSceneMobil::_scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2) {
    this->~CSceneMobil();
    return this;
}

void CSceneMobil::SetLocation(CPlugTree* tree, GmIso4* location) {
    if (m_hmsItem == nullptr || location == nullptr) return;
    for (uint32_t index = 0; index < m_hmsItem->m_corpuses.GetCount(); ++index) {
        CHmsCorpus* corpus = m_hmsItem->m_corpuses[index];
        if (corpus != nullptr && corpus->m_dyna != nullptr) {
            corpus->m_dyna->SetLocation(tree, location);
        }
    }
}

void CSceneMobil::SetTranslation(GmIso4* location, GmVec3* translation) {
    if (m_hmsItem == nullptr || translation == nullptr) return;
    for (uint32_t index = 0; index < m_hmsItem->m_corpuses.GetCount(); ++index) {
        CHmsCorpus* corpus = m_hmsItem->m_corpuses[index];
        if (corpus != nullptr && corpus->m_dyna != nullptr) {
            corpus->m_dyna->SetTranslation(location, translation);
        }
    }
}
