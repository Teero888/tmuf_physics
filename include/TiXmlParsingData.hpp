#ifndef TIXMLPARSINGDATA_HPP
#define TIXMLPARSINGDATA_HPP

#include "typedefs.h"

struct TiXmlParsingData {
    int field_0x0; // accesses: 2
    int field_0x4; // accesses: 2
    TiXmlParsingData * field_0x8; // accesses: 2
    int field_0xc; // accesses: 3

    // Member Functions
    void __thiscall Stamp(void *this,TiXmlParsingData *param_1,char *param_2,TiXmlEncoding param_3);
};

#endif // TIXMLPARSINGDATA_HPP
