#ifndef GMSPRING_CLASS_GMVEC3__HPP
#define GMSPRING_CLASS_GMVEC3__HPP

#include "typedefs.h"

struct GmSpring<class_GmVec3> {

    // Member Functions
    float __thiscall GetCriticalKa(void *this,GmSpring<class_GmVec3> *param_1);
    void __thiscall ClearVals(void *this,GmSpring<float> *param_1);
    void __thiscall Integrate(void *this,SRealTimeState *param_1,float param_2);
};

#endif // GMSPRING_CLASS_GMVEC3__HPP
