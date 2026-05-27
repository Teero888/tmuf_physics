#ifndef TIXMLNODE_HPP
#define TIXMLNODE_HPP

#include "typedefs.h"

struct TiXmlNode {
    undefined ** field_0x0; // accesses: 5
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    TiXmlNode * field_0x10; // accesses: 2
    TiXmlNode * field_0x14; // accesses: 1
    TiXmlNode * field_0x18; // accesses: 6
    TiXmlNode * field_0x1c; // accesses: 7
    undefined4 * field_0x20; // accesses: 3
    undefined4 field_0x24; // accesses: 1
    TiXmlNode * field_0x28; // accesses: 2

    // Member Functions
    TiXmlDocument * __thiscall GetDocument(TiXmlNode *this,TiXmlNode *param_1);
    TiXmlElement * __thiscall FirstChildElement(TiXmlNode *this,TiXmlNode *param_1,char *param_2);
    TiXmlElement * __thiscall NextSiblingElement(TiXmlNode *this,TiXmlNode *param_1,char *param_2);
    TiXmlNode * __thiscall FirstChild(TiXmlNode *this,TiXmlNode *param_1,char *param_2);
    TiXmlNode * __thiscall Identify(TiXmlNode *this,TiXmlNode *param_1,char *param_2,TiXmlEncoding param_3);
    TiXmlNode * __thiscall InsertEndChild(TiXmlNode *this,TiXmlNode *param_1,TiXmlNode *param_2);
    TiXmlNode * __thiscall LinkEndChild(TiXmlNode *this,TiXmlNode *param_1,TiXmlNode *param_2);
    TiXmlNode * __thiscall NextSibling(TiXmlNode *this,TiXmlNode *param_1,char *param_2);
    void __thiscall Clear(TiXmlNode *this,TiXmlNode *param_1);
    void __thiscall TiXmlNode(TiXmlNode *this,TiXmlNode *param_1,NodeType param_2);
    void __thiscall ~TiXmlNode(TiXmlNode *this,TiXmlNode *param_1);
};

#endif // TIXMLNODE_HPP
