#ifndef GMSPRING_FLOAT__HPP
#define GMSPRING_FLOAT__HPP

#include "typedefs.h"

struct GmSpring<float> {

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GmSpring<float>(void *this,GmSpring<float> *param_1);
    void __thiscall ClearVals(void *this,GmSpring<float> *param_1);
    void __thiscall Integrate(void *this,SRealTimeState *param_1,float param_2);
};

#endif // GMSPRING_FLOAT__HPP
