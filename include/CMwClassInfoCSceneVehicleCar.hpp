#ifndef CMWCLASSINFOCSCENEVEHICLECAR_HPP
#define CMWCLASSINFOCSCENEVEHICLECAR_HPP

#include "typedefs.h"

struct CMwClassInfoCSceneVehicleCar {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 7
    byte _padding_0xc[12];
    code * field_0x18; // accesses: 1

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x007f31ae) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall CMwClassInfoCSceneVehicleCar::ArchiveStateBuffer_FixedTimeStep (CMwClassInfoCSceneVehicleCar *this,CMwClassInfoCSceneVehicleCar *param_1, CClassicArchive *param_2,CClassicBufferMemory *param_3,ulong param_4,ulong param_5);
};

#endif // CMWCLASSINFOCSCENEVEHICLECAR_HPP
