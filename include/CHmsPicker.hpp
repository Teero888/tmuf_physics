#ifndef CHMSPICKER_HPP
#define CHMSPICKER_HPP

#include "typedefs.h"

struct CHmsPicker {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    void * field_0x1c; // accesses: 2
    void * field_0x20; // accesses: 2
    void * field_0x24; // accesses: 2
    void * field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 2
    undefined4 field_0x40; // accesses: 2
    undefined4 field_0x44; // accesses: 2
    undefined4 field_0x48; // accesses: 2
    undefined4 field_0x4c; // accesses: 2
    undefined4 field_0x50; // accesses: 2
    undefined4 field_0x54; // accesses: 2
    undefined4 field_0x58; // accesses: 2
    undefined4 field_0x5c; // accesses: 2
    undefined4 field_0x60; // accesses: 2
    undefined4 field_0x64; // accesses: 2
    undefined4 field_0x68; // accesses: 2
    undefined4 field_0x6c; // accesses: 2
    undefined4 field_0x70; // accesses: 2
    undefined4 field_0x74; // accesses: 2
    undefined4 field_0x78; // accesses: 2
    undefined4 field_0x7c; // accesses: 2
    undefined4 field_0x80; // accesses: 2
    undefined4 field_0x84; // accesses: 2
    undefined4 field_0x88; // accesses: 2
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 1
    byte _padding_0x98[48];
    undefined4 field_0xc8; // accesses: 2
    undefined4 field_0xcc; // accesses: 2
    void * field_0xd0; // accesses: 2
    undefined4 field_0xd4; // accesses: 2
    undefined4 field_0xd8; // accesses: 2
    undefined4 field_0xdc; // accesses: 2
    undefined4 field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 1
    byte _final_padding[0x24]; // Total size: 0x10c

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CHmsPicker(CHmsPicker *this,CHmsPicker *param_1);
    void __thiscall CopyFromPicker(CHmsPicker *this,CHmsPicker *param_1,CHmsPicker *param_2);
};

#endif // CHMSPICKER_HPP
