#ifndef CGAMECTNEDITORSCENEPOCLINK_HPP
#define CGAMECTNEDITORSCENEPOCLINK_HPP

#include "typedefs.h"

struct CMwNod;

struct CGameCtnEditorScenePocLink {
    void** vftable; // accesses: 12
    byte _padding_0x4[96];
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    byte _padding_0x6c[4];
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    float field_0x78; // accesses: 1
    float field_0x7c; // accesses: 12
    float field_0x80; // accesses: 2
    float field_0x84; // accesses: 1
    byte _padding_0x88[48];
    CGameCtnEditorScenePocLink * field_0xb8; // accesses: 5
    undefined4 field_0xbc; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ECardinalDir __thiscall GetForwardDirectionFromCurrentHAngle (CGameCtnEditorScenePocLink *this,CGameCtnEditorScenePocLink *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall IsHAngleNeedClamp (CGameCtnEditorScenePocLink *this,CGameCtnEditorScenePocLink *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CGameCtnEditorScenePocLink (CGameCtnEditorScenePocLink *this,CGameCtnEditorScenePocLink *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ClampHAngle (CGameCtnEditorScenePocLink *this,CGameCtnEditorScenePocLink *param_1,float *param_2);
    void __thiscall SetTarget (CGameCtnEditorScenePocLink *this,CGameCtnEditorScenePocLink *param_1,CSceneMobil *param_2 );
};

#endif // CGAMECTNEDITORSCENEPOCLINK_HPP
