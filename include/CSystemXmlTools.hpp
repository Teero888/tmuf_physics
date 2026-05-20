#ifndef CSYSTEMXMLTOOLS_HPP
#define CSYSTEMXMLTOOLS_HPP

#include "typedefs.h"

struct CSystemXmlTools {
    void** vftable; // accesses: 1
    byte _padding_0x4[20];
    int * field_0x18; // accesses: 3

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
