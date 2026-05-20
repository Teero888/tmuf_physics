#ifndef LOCATEDGMSURF_HPP
#define LOCATEDGMSURF_HPP

#include "typedefs.h"

struct CMwNod;
struct GmIso3;
struct SPlugFaceCull;

struct LocatedGmSurf {
    void** vftable; // accesses: 12
    GmIso3 * field_0x4; // accesses: 4
    int field_0x8; // accesses: 3
    GmIso3 * field_0xc; // accesses: 4
};

#endif // LOCATEDGMSURF_HPP
