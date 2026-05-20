#ifndef SMWPARAMINFO_HPP
#define SMWPARAMINFO_HPP

#include "typedefs.h"

struct CMwParam;
struct SStringParam;
struct TiXmlElement;

struct SMwParamInfo {
    void** vftable; // accesses: 6
    undefined4 field_0x4; // accesses: 4
    undefined * field_0x8; // accesses: 9
    undefined4 field_0xc; // accesses: 4
    SStringParam * field_0x10; // accesses: 8
    undefined4 field_0x14; // accesses: 4
    undefined4 field_0x18; // accesses: 6
    undefined4 field_0x1c; // accesses: 1
    TiXmlElement * field_0x20; // accesses: 2
    int field_0x24; // accesses: 2
};

#endif // SMWPARAMINFO_HPP
