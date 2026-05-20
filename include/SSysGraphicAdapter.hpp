#ifndef SSYSGRAPHICADAPTER_HPP
#define SSYSGRAPHICADAPTER_HPP

#include "typedefs.h"

struct SSysGraphicAdapter {
    int field_0x0; // accesses: 3
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 2
    uint field_0xc; // accesses: 3
    undefined2 field_0x10; // accesses: 5
    undefined2 field_0x12; // accesses: 5
    ushort field_0x14; // accesses: 1
    ushort field_0x16; // accesses: 1
    ushort field_0x18; // accesses: 1
    byte _padding_0x1a[18];
    undefined4 field_0x2c; // accesses: 3
    undefined4 field_0x30; // accesses: 3
    undefined1 field_0x34; // accesses: 4
    byte field_0x35; // accesses: 19
    byte field_0x36; // accesses: 6

    // Member Functions
    int __thiscall IsDriverRecentOrEqual (void *this,SSysGraphicAdapter *param_1,ushort param_2,ushort param_3,ushort param_4, ushort param_5);
    void __thiscall CaptureInfoGpu(void *this,SSysGraphicAdapter *param_1,ulong param_2);
};

#endif // SSYSGRAPHICADAPTER_HPP
