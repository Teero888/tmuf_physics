#ifndef CHMSSTATEDYNA_HPP
#define CHMSSTATEDYNA_HPP

#include "typedefs.h"

struct CMwCmdScriptVarBool;
struct GmIso4;

struct CHmsStateDyna {
    void** vftable; // accesses: 5
    float field_0x4; // accesses: 3
    GmIso4 * field_0x8; // accesses: 3
    GmIso4 * field_0xc; // accesses: 4
    byte _padding_0x10[4];
    int field_0x14; // accesses: 1
    byte _padding_0x18[28];
    float field_0x34; // accesses: 5
    float field_0x38; // accesses: 5
    float field_0x3c; // accesses: 5
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 1
    float field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
};

#endif // CHMSSTATEDYNA_HPP
