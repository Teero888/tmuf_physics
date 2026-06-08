#include "CSceneVehicleBall.hpp"

// SVehicleBallState
CSceneVehicleBall::SVehicleBallState::~SVehicleBallState() {}

// CSceneVehicleBall
CSceneVehicleBall::CSceneVehicleBall() : CMwNod(), m_item(nullptr) {}
CSceneVehicleBall::~CSceneVehicleBall() {}

CMwNod* CSceneVehicleBall::MwNewCSceneVehicleBall() { return new CSceneVehicleBall(); }
uint32_t CSceneVehicleBall::GetMwClassId() { return 0x06001000; }
