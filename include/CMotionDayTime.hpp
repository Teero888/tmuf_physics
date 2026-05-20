#ifndef CMOTIONDAYTIME_HPP
#define CMOTIONDAYTIME_HPP

#include "typedefs.h"

struct CPlugMaterial;

struct CMotionDayTime {
    byte _padding_0x0[20];
    uint field_0x14; // accesses: 2
    byte _padding_0x18[12];
    CMotionDayTime * field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[104];
    CPlugMaterial * field_0x98; // accesses: 1
    uint field_0x9c; // accesses: 4

    // Member Functions
    void __thiscall CMotionDayTime(CMotionDayTime *this,CMotionDayTime *param_1);
    void __thiscall OnDayTimeChange (CMotionDayTime *this,CMotionWeather *param_1,CFuncWeather *param_2,EDayTime4 param_3);
    void __thiscall SetMaterialMode(CMotionDayTime *this,CMotionDayTime *param_1,EMaterialMode param_2);
};

#endif // CMOTIONDAYTIME_HPP
