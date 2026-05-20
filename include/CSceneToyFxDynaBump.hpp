#ifndef CSCENETOYFXDYNABUMP_HPP
#define CSCENETOYFXDYNABUMP_HPP

#include "typedefs.h"

struct CHmsItem;
struct GmVec4;

struct CSceneToyFxDynaBump {
    void** vftable; // accesses: 1
    byte _padding_0x4[36];
    CHmsItem * field_0x28; // accesses: 1
    byte _padding_0x2c[64];
    int field_0x6c; // accesses: 5
    float field_0x70; // accesses: 7
    float field_0x74; // accesses: 7
    float field_0x78; // accesses: 10
    float field_0x7c; // accesses: 10
    float field_0x80; // accesses: 10
    float field_0x84; // accesses: 4
    float field_0x88; // accesses: 4
    float field_0x8c; // accesses: 4
    int field_0x90; // accesses: 3
    CPlugMaterialFx * field_0x94; // accesses: 6
    byte _padding_0x98[4];
    float * field_0x9c; // accesses: 2
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
