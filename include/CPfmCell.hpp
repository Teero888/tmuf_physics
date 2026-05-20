#ifndef CPFMCELL_HPP
#define CPFMCELL_HPP

#include "typedefs.h"

struct GmVec2;

struct CPfmCell {
    void** vftable; // accesses: 2
    byte _padding_0x4[28];
    undefined4 field_0x20; // accesses: 3
    float field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 5
    undefined4 field_0x2c; // accesses: 1
    float field_0x30; // accesses: 3
    undefined4 field_0x34; // accesses: 5
    undefined4 field_0x38; // accesses: 1
    float field_0x3c; // accesses: 4
    undefined4 field_0x40; // accesses: 6
    float field_0x44; // accesses: 1
    float field_0x48; // accesses: 1
    float field_0x4c; // accesses: 1
    byte _padding_0x50[4];
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    float field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    byte _padding_0x64[20];
    undefined4 field_0x78; // accesses: 1
    byte _padding_0x7c[4];
    float field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    float field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    byte _padding_0x90[20];
    undefined4 field_0xa4; // accesses: 1
    byte _padding_0xa8[4];
    float field_0xac; // accesses: 1
    undefined4 field_0xb0; // accesses: 1
    undefined4 field_0xb4; // accesses: 1
    undefined4 field_0xb8; // accesses: 1
    byte _padding_0xbc[20];
    undefined4 field_0xd0; // accesses: 1
    GmVec2 * field_0xd4; // accesses: 3
    undefined4 field_0xd8; // accesses: 3
    undefined4 field_0xdc; // accesses: 2
    int field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 1
    byte _padding_0xe8[12];
    undefined4 field_0xf4; // accesses: 1
    float field_0xf8; // accesses: 1
    float field_0xfc; // accesses: 1
    float field_0x100; // accesses: 1
    float field_0x104; // accesses: 1
    float field_0x108; // accesses: 1
    float field_0x10c; // accesses: 1
    float field_0x110; // accesses: 1
    float field_0x114; // accesses: 1
    float field_0x118; // accesses: 1
    float field_0x11c; // accesses: 1
    float field_0x120; // accesses: 1
    float field_0x124; // accesses: 1
    float field_0x128; // accesses: 1
    float field_0x12c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeCellData(void *this,CPfmCell *param_1);
    int __thiscall ForcePointToCellCollumn(void *this,CPfmCell *param_1,GmVec3 *param_2);
    int __thiscall RequestLink (void *this,CPfmCell *param_1,GmVec3 *param_2,GmVec3 *param_3,CPfmCell *param_4);
    void __thiscall CPfmCell(void *this,CPfmCell *param_1);
    void __thiscall Initialize(void *this,CPfmCell *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4);
    void __thiscall ~CPfmCell(void *this,CPfmCell *param_1);
};

#endif // CPFMCELL_HPP
