#ifndef CFASTBUFFER_CLASS_GMNAT2__HPP
#define CFASTBUFFER_CLASS_GMNAT2__HPP

#include "typedefs.h"

struct CFastBuffer<class_GmNat2> {
    void** vftable; // accesses: 4
    int * field_0x4; // accesses: 2

    // Member Functions
    int __thiscall Find (void *this,CFastArray<class_GxTexCoordSet> *param_1,GxTexCoordSet *param_2);
    void __thiscall Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
    void __thiscall InsertElemAt (void *this,CFastBuffer<struct_CInputDevice::SRumble> *param_1,ulong param_2, SRumble *param_3);
};

#endif // CFASTBUFFER_CLASS_GMNAT2__HPP
