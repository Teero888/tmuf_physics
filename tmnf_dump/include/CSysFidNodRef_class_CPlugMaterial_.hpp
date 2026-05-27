#ifndef CSYSFIDNODREF_CLASS_CPLUGMATERIAL__HPP
#define CSYSFIDNODREF_CLASS_CPLUGMATERIAL__HPP

#include "typedefs.h"

struct CMwNod;
struct CPlugMaterial;
struct CSystemFid;

struct CSysFidNodRef<class_CPlugMaterial> {
    void** vftable; // accesses: 2
    CMwNod * field_0x4; // accesses: 6

    // Member Functions
    CPlugMaterial * __thiscall GetNod(void *this,CSysFidNodRef<class_CPlugMaterial> *param_1);
};

#endif // CSYSFIDNODREF_CLASS_CPLUGMATERIAL__HPP
