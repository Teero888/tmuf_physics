#ifndef TIXMLATTRIBUTE_HPP
#define TIXMLATTRIBUTE_HPP

#include "typedefs.h"

struct TiXmlAttribute {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 2

    // Member Functions
    int __thiscall QueryDoubleValue(TiXmlAttribute *this,TiXmlAttribute *param_1,double *param_2);
    int __thiscall QueryIntValue(TiXmlAttribute *this,TiXmlAttribute *param_1,int *param_2);
};

#endif // TIXMLATTRIBUTE_HPP
