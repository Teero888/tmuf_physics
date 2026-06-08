#include "CSceneToyBoat.hpp"

// SSailManoeuvre
CSceneToyBoat::SSailManoeuvre::~SSailManoeuvre() {}

// CSceneToyBoat
CSceneToyBoat::CSceneToyBoat() : CMwNod(), m_scene14(nullptr) {}
CSceneToyBoat::~CSceneToyBoat() {}

CMwNod* CSceneToyBoat::MwNewCSceneToyBoat() { return new CSceneToyBoat(); }
uint32_t CSceneToyBoat::GetMwClassId() { return 0x06002000; }
