#ifndef SHEMIINFO_HPP
#define SHEMIINFO_HPP

#include "typedefs.h"

struct SHemiInfo {
    byte _padding_0x0[28];
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    float field_0x24; // accesses: 2
    byte _padding_0x28[48];
    float field_0x58; // accesses: 2
};

#endif // SHEMIINFO_HPP
