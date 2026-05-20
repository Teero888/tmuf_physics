#ifndef CTRACKMANIARACENETLAPS_HPP
#define CTRACKMANIARACENETLAPS_HPP

#include "typedefs.h"

struct CPlugAudio;

struct CTrackManiaRaceNetLaps {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 1
    int * field_0x18; // accesses: 4
    byte _padding_0x1c[8];
    CTrackManiaRaceNetLaps field_0x24; // accesses: 1
    byte _padding_0x28[40];
    int field_0x50; // accesses: 1
    byte _padding_0x54[28];
    int field_0x70; // accesses: 4
    int field_0x74; // accesses: 5
    undefined4 field_0x78; // accesses: 1
    byte _padding_0x7c[28];
    int field_0x98; // accesses: 3
    byte _padding_0x9c[632];
    int field_0x314; // accesses: 1
    byte _padding_0x318[684];
    int field_0x5c4; // accesses: 2
    byte _padding_0x5c8[184];
    int field_0x680; // accesses: 2

    // Member Functions
    void __thiscall UpdateAsync(CTrackManiaRaceNetLaps *this,CInputPortDx8 *param_1);
};

#endif // CTRACKMANIARACENETLAPS_HPP
