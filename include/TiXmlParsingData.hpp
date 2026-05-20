#ifndef TIXMLPARSINGDATA_HPP
#define TIXMLPARSINGDATA_HPP

#include "typedefs.h"

struct TiXmlParsingData {
    void** vftable; // accesses: 3
    undefined4 field_0x4; // accesses: 3
    TiXmlParsingData * field_0x8; // accesses: 2
    int field_0xc; // accesses: 3

    // Member Functions
    void __thiscall Stamp(void *this,TiXmlParsingData *param_1,char *param_2,TiXmlEncoding param_3);
};

#endif // TIXMLPARSINGDATA_HPP
