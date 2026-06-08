#include "CSceneVehicleStruct.hpp"

// SSimulationWheel
CSceneVehicleStruct::SSimulationWheel::~SSimulationWheel() {}

// SVisualArm
CSceneVehicleStruct::SVisualArm::~SVisualArm() {}

// SVisualWheel
CSceneVehicleStruct::SVisualWheel::~SVisualWheel() {}

// CSceneVehicleStruct
CSceneVehicleStruct::CSceneVehicleStruct() : CMwNod(), m_nod44(nullptr), m_nod48(nullptr), m_nod4c(nullptr) {}
CSceneVehicleStruct::~CSceneVehicleStruct() {}

CMwNod* CSceneVehicleStruct::MwNewCSceneVehicleStruct() { return new CSceneVehicleStruct(); }
uint32_t CSceneVehicleStruct::GetMwClassId() { return 0x0601C000; }
