#ifndef SSIMULATIONWHEEL_HPP
#define SSIMULATIONWHEEL_HPP

#include "typedefs.h"

struct SSimulationWheel {
    byte _padding_0x0[12];
    float field_0xc; // accesses: 1
    byte _padding_0x10[84];
    float field_0x64; // accesses: 6
    float field_0x68; // accesses: 5
    float field_0x6c; // accesses: 4
    byte _padding_0x70[68];
    float field_0xb4; // accesses: 9
    float field_0xb8; // accesses: 5
    float field_0xbc; // accesses: 4
    byte _padding_0xc0[100];
    int field_0x124; // accesses: 3
};

#endif // SSIMULATIONWHEEL_HPP
