#ifndef CHMSZONEOVERLAY_HPP
#define CHMSZONEOVERLAY_HPP

#include "typedefs.h"

struct CHmsItem;

struct CHmsZoneOverlay {
    void** vftable; // accesses: 1
    byte _padding_0x4[20];
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[44];
    CHmsItem * field_0x48; // accesses: 2
    byte _padding_0x4c[236];
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    undefined4 field_0x15c; // accesses: 1
    undefined4 field_0x160; // accesses: 1
    undefined4 field_0x164; // accesses: 1
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 1
    undefined4 field_0x170; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CHmsZoneOverlay(CHmsZoneOverlay *this,CHmsZoneOverlay *param_1);
};

#endif // CHMSZONEOVERLAY_HPP
