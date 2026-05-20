#ifndef SBUILDPAGEPARAMS_HPP
#define SBUILDPAGEPARAMS_HPP

#include "typedefs.h"

struct CControlStyleSheet;
struct SManialinkFormat;
struct TiXmlElement;
struct TiXmlNode;

struct SBuildPageParams {
    void** vftable; // accesses: 1
    SManialinkFormat * field_0x4; // accesses: 1
    TiXmlNode * field_0x8; // accesses: 4
    TiXmlNode * field_0xc; // accesses: 9
    int field_0x10; // accesses: 2
    byte _padding_0x14[8];
    TiXmlElement * field_0x1c; // accesses: 1
    SManialinkFormat * field_0x20; // accesses: 1
    int field_0x24; // accesses: 1
    byte _padding_0x28[12];
    float field_0x34; // accesses: 1
    float field_0x38; // accesses: 1
};

#endif // SBUILDPAGEPARAMS_HPP
