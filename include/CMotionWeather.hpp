#ifndef CMOTIONWEATHER_HPP
#define CMOTIONWEATHER_HPP

#include "typedefs.h"

struct CMwNod;
struct CSceneMobilClouds;
struct CSceneToySea;

struct CMotionWeather {
    byte _padding_0x0[24];
    CSceneToySea * field_0x18; // accesses: 2
    byte _padding_0x1c[20];
    int field_0x30; // accesses: 3
    int field_0x34; // accesses: 10
    byte _padding_0x38[28];
    CMwNod * field_0x54; // accesses: 4
    byte _padding_0x58[24];
    undefined4 field_0x70; // accesses: 1
    byte _padding_0x74[32];
    CSceneToySea * field_0x94; // accesses: 1
    byte _padding_0x98[4];
    int field_0x9c; // accesses: 1
    int field_0xa0; // accesses: 1
    byte _padding_0xa4[64];
    int field_0xe4; // accesses: 2

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
