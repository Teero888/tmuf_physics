#ifndef TIXMLATTRIBUTESET_HPP
#define TIXMLATTRIBUTESET_HPP

#include "typedefs.h"

struct TiXmlAttributeSet {
    byte _padding_0x0[28];
    undefined4 field_0x1c; // accesses: 3
    undefined4 field_0x20; // accesses: 3

    // Member Functions
    int __thiscall Find(void *this,CFastArray<class_GxTexCoordSet> *param_1,GxTexCoordSet *param_2);
    void __thiscall Remove (void *this,CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *param_1, ulong param_2);
    void __thiscall TiXmlAttributeSet(void *this,TiXmlAttributeSet *param_1);
    void __thiscall ~TiXmlAttributeSet(void *this,TiXmlAttributeSet *param_1);
};

#endif // TIXMLATTRIBUTESET_HPP
