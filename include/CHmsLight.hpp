#ifndef CHMSLIGHT_HPP
#define CHMSLIGHT_HPP

#include "typedefs.h"

struct CMwNod;

struct CHmsLight {
    void** vftable; // accesses: 1
    byte _padding_0x4[100];
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    CMwNod * field_0x70; // accesses: 5
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    CMwNod * field_0x88; // accesses: 5
    undefined4 field_0x8c; // accesses: 9

    // Member Functions
    void __thiscall CHmsLight(CHmsLight *this,CHmsLight *param_1);
    void __thiscall SetForceShadowGroup(CHmsLight *this,CHmsLight *param_1,int param_2,ulong param_3);
    void __thiscall SetGxLight(CHmsLight *this,CHmsLight *param_1,GxLight *param_2);
    void __thiscall SetProjectorBitmap(CHmsLight *this,CHmsLight *param_1,CPlugBitmap *param_2);
    void __thiscall SetReflectPlaneIsEnable(CHmsLight *this,CHmsLight *param_1,int param_2);
    void __thiscall SetUpdateType(CHmsLight *this,CHmsLight *param_1,ELightUpdate param_2);
};

#endif // CHMSLIGHT_HPP
