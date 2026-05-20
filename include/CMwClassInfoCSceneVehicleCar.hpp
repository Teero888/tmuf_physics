#ifndef CMWCLASSINFOCSCENEVEHICLECAR_HPP
#define CMWCLASSINFOCSCENEVEHICLECAR_HPP

#include "typedefs.h"

struct CMwClassInfoCSceneVehicleCar {
    void** vftable; // accesses: 1
    byte _padding_0x4[4];
    int field_0x8; // accesses: 7

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x007f31ae) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall CMwClassInfoCSceneVehicleCar::ArchiveStateBuffer_FixedTimeStep (CMwClassInfoCSceneVehicleCar *this,CMwClassInfoCSceneVehicleCar *param_1, CClassicArchive *param_2,CClassicBufferMemory *param_3,ulong param_4,ulong param_5);
};

#endif // CMWCLASSINFOCSCENEVEHICLECAR_HPP
