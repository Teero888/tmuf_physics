#include "CSceneMobil.hpp"

CSceneMobil::CSceneMobil() : CMwNod(), m_hmsItem(nullptr), m_nod2c(nullptr), m_nod44(nullptr) {}
CSceneMobil::~CSceneMobil() {}

CMwNod* CSceneMobil::MwNewCSceneMobil() { return new CSceneMobil(); }
uint32_t CSceneMobil::GetMwClassId() { return 0x06003000; }

void* CSceneMobil::_scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2) {
    this->~CSceneMobil();
    return this;
}

void CSceneMobil::SetLocation(CPlugTree* tree, GmIso4* location) {}
void CSceneMobil::SetTranslation(GmIso4* location, GmVec3* translation) {}
