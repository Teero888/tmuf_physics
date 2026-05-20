#ifndef CMOTIONDAYTIME_HPP
#define CMOTIONDAYTIME_HPP

#include "typedefs.h"

struct CMotionDayTime {
    void** vftable; // accesses: 1
    byte _padding_0x4[32];
    undefined4 field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1

    // Member Functions
    void __thiscall CMotionDayTime(CMotionDayTime *this,CMotionDayTime *param_1);
    void __thiscall OnDayTimeChange (CMotionDayTime *this,CMotionWeather *param_1,CFuncWeather *param_2,EDayTime4 param_3);
    void __thiscall SetMaterialMode(CMotionDayTime *this,CMotionDayTime *param_1,EMaterialMode param_2);
};

#endif // CMOTIONDAYTIME_HPP
