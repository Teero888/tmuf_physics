#ifndef CMOTIONWEATHER_HPP
#define CMOTIONWEATHER_HPP

#include "typedefs.h"

struct CSceneMobilClouds;
struct CSceneToySea;

struct CMotionWeather {
    void** vftable; // accesses: 2
    byte _padding_0x4[20];
    CSceneToySea * field_0x18; // accesses: 2
    byte _padding_0x1c[20];
    undefined4 field_0x30; // accesses: 3
    undefined4 field_0x34; // accesses: 10
    byte _padding_0x38[172];
    int field_0xe4; // accesses: 1

    // Member Functions
    int __thiscall GetSkyGradVBitmapAdr (CMotionWeather *this,CMotionWeather *param_1,CPlugBitmapAddress **param_2);
    int __thiscall GetTreeSea(CMotionWeather *this,CMotionWeather *param_1,CPlugTree **param_2);
    int __thiscall GetTreeStars(CMotionWeather *this,CMotionWeather *param_1,CPlugTree **param_2);
    void __cdecl ChangeClouds(CSceneMobilClouds *param_1,CFuncWeather *param_2);
    void __thiscall CMotionWeather(CMotionWeather *this,CMotionWeather *param_1);
    void __thiscall ChangeMaterial (CMotionWeather *this,CMotionWeather *param_1,CFuncWeather *param_2,EDayTime4 param_3);
    void __thiscall OnDayTimeChange (CMotionWeather *this,CMotionWeather *param_1,CFuncWeather *param_2,EDayTime4 param_3);
    void __thiscall OnWeatherChange (CMotionWeather *this,CMotionWeather *param_1,CFuncWeather *param_2,EDayTime4 param_3);
};

#endif // CMOTIONWEATHER_HPP
