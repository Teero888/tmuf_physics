#ifndef CSCENEMOBILABSORBCONTACT_HPP
#define CSCENEMOBILABSORBCONTACT_HPP

#include "typedefs.h"

struct CSceneVehicleCar;

struct CSceneMobilAbsorbContact {
    byte _padding_0x0[4];
    CSceneVehicleCar * field_0x4; // accesses: 1
    byte _padding_0x8[4];
    float field_0xc; // accesses: 9
    float field_0x10; // accesses: 18
    float field_0x14; // accesses: 16
    byte _padding_0x18[4];
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    float field_0x24; // accesses: 3
    float field_0x28; // accesses: 7
    float field_0x2c; // accesses: 7
    float field_0x30; // accesses: 4
    float field_0x34; // accesses: 4
    float field_0x38; // accesses: 4
    undefined4 field_0x3c; // accesses: 3
    int * field_0x40; // accesses: 6
    byte _padding_0x44[4];
    short field_0x48; // accesses: 6

    // Member Functions
    void __thiscall AbsorbContact (CSceneMobilAbsorbContact *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
};

#endif // CSCENEMOBILABSORBCONTACT_HPP
