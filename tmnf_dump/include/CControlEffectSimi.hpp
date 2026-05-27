#ifndef CCONTROLEFFECTSIMI_HPP
#define CCONTROLEFFECTSIMI_HPP

#include "typedefs.h"

struct CControlEffectSimi {
    void** vftable;
    byte _final_padding[0x34]; // Total size: 0x38

    // Member Functions
    GmVec3 __thiscall GetValue(CControlEffectSimi *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CCONTROLEFFECTSIMI_HPP
