#ifndef CSCENETOYFXDYNABUMP_HPP
#define CSCENETOYFXDYNABUMP_HPP

#include "typedefs.h"

struct CHmsItem;
struct CPlugMaterial;
struct CPlugShader;
struct GmVec4;

struct CSceneToyFxDynaBump {
    byte _padding_0x0[28];
    int field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    float field_0x24; // accesses: 1
    CHmsItem * field_0x28; // accesses: 2
    float field_0x2c; // accesses: 1
    byte _padding_0x30[12];
    float field_0x3c; // accesses: 1
    int field_0x40; // accesses: 2
    float field_0x44; // accesses: 1
    byte _padding_0x48[5];
    char field_0x4d; // accesses: 1
    byte _padding_0x4e[30];
    undefined4 field_0x6c; // accesses: 5
    undefined4 field_0x70; // accesses: 7
    undefined4 field_0x74; // accesses: 8
    undefined4 field_0x78; // accesses: 10
    undefined4 field_0x7c; // accesses: 10
    undefined4 field_0x80; // accesses: 10
    undefined4 field_0x84; // accesses: 4
    undefined4 field_0x88; // accesses: 4
    undefined4 field_0x8c; // accesses: 4
    undefined4 field_0x90; // accesses: 3
    CPlugShader * field_0x94; // accesses: 7
    CPlugMaterial * field_0x98; // accesses: 1
    float * field_0x9c; // accesses: 4
    byte _padding_0xa0[4];
    float * field_0xa4; // accesses: 2
    byte _padding_0xa8[4];
    float * field_0xac; // accesses: 3
    byte _padding_0xb0[4];
    float * field_0xb4; // accesses: 3
    byte _padding_0xb8[4];
    float * field_0xbc; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateAsync(CSceneToyFxDynaBump *this,CInputPortDx8 *param_1);
    int __thiscall UpdateShaderLoadFxPtrs(CSceneToyFxDynaBump *this,CSceneToyFxDynaBump *param_1);
    void __thiscall AbsorbContact (CSceneToyFxDynaBump *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
    void __thiscall CSceneToyFxDynaBump(CSceneToyFxDynaBump *this,CSceneToyFxDynaBump *param_1);
    void __thiscall InitFromMaterialFx (CSceneToyFxDynaBump *this,CSceneToyFxDynaBump *param_1,CPlugTree *param_2);
};

#endif // CSCENETOYFXDYNABUMP_HPP
