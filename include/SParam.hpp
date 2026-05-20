#ifndef SPARAM_HPP
#define SPARAM_HPP

#include "typedefs.h"

struct CHmsCorpus;
struct ulong;

struct SParam {
    void** vftable; // accesses: 11
    float field_0x4; // accesses: 10
    EParamType field_0x8; // accesses: 4
    ulong * field_0xc; // accesses: 4
    float field_0x10; // accesses: 1
    float field_0x14; // accesses: 1
    float field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    float field_0x24; // accesses: 4
    float field_0x28; // accesses: 4
    float field_0x2c; // accesses: 4
    byte _padding_0x30[80];
    float field_0x80; // accesses: 2
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 1
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
};

#endif // SPARAM_HPP
