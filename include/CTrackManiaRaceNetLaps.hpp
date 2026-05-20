#ifndef CTRACKMANIARACENETLAPS_HPP
#define CTRACKMANIARACENETLAPS_HPP

#include "typedefs.h"

struct CTrackManiaRaceNetLaps {
    void** vftable; // accesses: 7
    byte _padding_0x4[20];
    int * field_0x18; // accesses: 4
    byte _padding_0x1c[52];
    int field_0x50; // accesses: 1
    byte _padding_0x54[32];
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    byte _padding_0x7c[28];
    int field_0x98; // accesses: 3
    byte _padding_0x9c[1320];
    int field_0x5c4; // accesses: 2
    byte _padding_0x5c8[184];
    int field_0x680; // accesses: 2
    byte _final_padding[0xc]; // Total size: 0x690

    // Member Functions
    void __thiscall UpdateAsync(CTrackManiaRaceNetLaps *this,CInputPortDx8 *param_1);
};

#endif // CTRACKMANIARACENETLAPS_HPP
