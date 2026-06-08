#include "CHmsForceField.hpp"

CHmsForceField::CHmsForceField() : CMwNod(), m_zone(nullptr) {}
CHmsForceField::~CHmsForceField() {}

CMwClassInfo* CHmsForceField::MwGetClassInfo(CFuncSegment* param_1) { return nullptr; }
CMwNod* CHmsForceField::MwNewCHmsForceField() { return new CHmsForceField(); }
int CHmsForceField::MwIsKindOf(uint32_t classId) { return 0; }
uint32_t CHmsForceField::GetMwClassId() { return 0x06015000; }

void* CHmsForceField::_vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2) {
    this->~CHmsForceField();
    if ((param_2 & 1) != 0) {
        delete this;
    }
    return this;
}

void CHmsForceField::SetZone(CSceneSector* param_1, CHmsZone* param_2) {
    m_zone = param_2;
}
