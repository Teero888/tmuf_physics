#ifndef CPLUGGPUFXLOCATOR_HPP
#define CPLUGGPUFXLOCATOR_HPP

#include "typedefs.h"

struct CPlugGpuFxLocator {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1

    // Member Functions
    void __thiscall CPlugGpuFxLocator(CPlugGpuFxLocator *this,CPlugGpuFxLocator *param_1);
    void __thiscall Reset(CPlugGpuFxLocator *this,GmFrustumIso4 *param_1);
};

#endif // CPLUGGPUFXLOCATOR_HPP
