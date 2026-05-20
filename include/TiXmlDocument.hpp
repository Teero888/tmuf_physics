#ifndef TIXMLDOCUMENT_HPP
#define TIXMLDOCUMENT_HPP

#include "typedefs.h"

struct TiXmlDocument {
    undefined ** field_0x0; // accesses: 3
    undefined4 field_0x4; // accesses: 6
    undefined4 field_0x8; // accesses: 6
    byte _padding_0xc[12];
    int field_0x18; // accesses: 1
    byte _padding_0x1c[20];
    TiXmlDocument * field_0x30; // accesses: 3
    undefined4 * field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 5
    undefined4 field_0x40; // accesses: 5

    // Member Functions
    bool __thiscall LoadFile_Gbx (TiXmlDocument *this,TiXmlDocument *param_1,CClassicBuffer *param_2,TiXmlEncoding param_3);
    bool __thiscall SaveFile_Gbx(TiXmlDocument *this,TiXmlDocument *param_1,CClassicBuffer *param_2);
    char * __thiscall Parse (TiXmlDocument *this,TiXmlDeclaration *param_1,char *param_2,TiXmlParsingData *param_3, TiXmlEncoding param_4);
    void __thiscall SetError (TiXmlDocument *this,TiXmlDocument *param_1,int param_2,char *param_3, TiXmlParsingData *param_4,TiXmlEncoding param_5);
    void __thiscall TiXmlDocument(TiXmlDocument *this,TiXmlDocument *param_1);
};

#endif // TIXMLDOCUMENT_HPP
