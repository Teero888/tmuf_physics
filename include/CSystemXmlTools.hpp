#ifndef CSYSTEMXMLTOOLS_HPP
#define CSYSTEMXMLTOOLS_HPP

#include "typedefs.h"

struct CMwNod;
struct CMwParam;
struct CSystemFidFile;
struct SStringParam;
struct TiXmlElement;

struct CSystemXmlTools {
    byte _padding_0x0[4];
    EConvertMethod field_0x4; // accesses: 9
    CSystemFidFile * field_0x8; // accesses: 6
    byte _padding_0xc[4];
    TiXmlElement * field_0x10; // accesses: 4
    TiXmlElement * field_0x14; // accesses: 3
    uint field_0x18; // accesses: 13
    code * field_0x1c; // accesses: 1
    TiXmlElement * field_0x20; // accesses: 15
    void * field_0x24; // accesses: 3
    byte _padding_0x28[68];
    undefined4 * field_0x6c; // accesses: 6

    // Member Functions
    CMwNod * __cdecl XmlToNod(CSystemFid *param_1);
    int __cdecl NodParamToXml (CMwNod *param_1,SMwParamInfo *param_2,TiXmlNode *param_3,CFastStringInt *param_4);
    int __cdecl NodParamsToXml(CMwNod *param_1,TiXmlNode *param_2,CFastStringInt *param_3);
    int __cdecl NodToXml(CMwNod *param_1,CSystemFid *param_2);
    int __cdecl XmlToNodParam(TiXmlElement *param_1,CMwNod *param_2,CFastStringInt *param_3);
    int __cdecl XmlToNodParams(TiXmlElement *param_1,CMwNod *param_2,CFastStringInt *param_3);
    ulong __cdecl XmlToNodClassId(CSystemFid *param_1);
};

#endif // CSYSTEMXMLTOOLS_HPP
