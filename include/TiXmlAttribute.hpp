#ifndef TIXMLATTRIBUTE_HPP
#define TIXMLATTRIBUTE_HPP

#include "typedefs.h"

struct TiXmlAttribute {
    void** vftable; // accesses: 16
    undefined4 field_0x4; // accesses: 8
    undefined4 field_0x8; // accesses: 5
    undefined4 field_0xc; // accesses: 3
    undefined4 field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 1
    int field_0x18; // accesses: 2

    // Member Functions
    int __thiscall QueryDoubleValue(TiXmlAttribute *this,TiXmlAttribute *param_1,double *param_2);
    int __thiscall QueryIntValue(TiXmlAttribute *this,TiXmlAttribute *param_1,int *param_2);
};

#endif // TIXMLATTRIBUTE_HPP
