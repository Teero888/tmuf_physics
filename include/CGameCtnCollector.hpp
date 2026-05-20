#ifndef CGAMECTNCOLLECTOR_HPP
#define CGAMECTNCOLLECTOR_HPP

#include "typedefs.h"

struct CGameCtnCollector {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    undefined * field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[12];
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    byte _padding_0x48[4];
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1

    // Member Functions
    void __thiscall CGameCtnCollector(CGameCtnCollector *this,CGameCtnCollector *param_1);
};

#endif // CGAMECTNCOLLECTOR_HPP
