#ifndef TIXMLELEMENT_HPP
#define TIXMLELEMENT_HPP

#include "typedefs.h"

struct TiXmlElement {
    undefined ** field_0x0; // accesses: 2
    byte _padding_0x4[20];
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[44];
    TiXmlElement * field_0x4c; // accesses: 1

    // Member Functions
    char * __thiscall Attribute(TiXmlElement *this,TiXmlElement *param_1,char *param_2,int *param_3);
    int __thiscall QueryDoubleAttribute (TiXmlElement *this,TiXmlElement *param_1,char *param_2,double *param_3);
    int __thiscall QueryIntAttribute(TiXmlElement *this,TiXmlElement *param_1,char *param_2,int *param_3);
    void __thiscall ClearThis(TiXmlElement *this,TiXmlElement *param_1);
    void __thiscall TiXmlElement(TiXmlElement *this,TiXmlElement *param_1,char *param_2);
    void __thiscall ~TiXmlElement(TiXmlElement *this,TiXmlElement *param_1);
};

#endif // TIXMLELEMENT_HPP
