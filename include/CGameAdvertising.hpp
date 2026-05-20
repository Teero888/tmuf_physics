#ifndef CGAMEADVERTISING_HPP
#define CGAMEADVERTISING_HPP

#include "typedefs.h"

struct CFastString;
struct CMwNod;
struct CSceneMobil;
struct CSceneObject;
struct GmIso3;

struct CGameAdvertising {
    void** vftable;
    byte _padding_0x4[36];
    CFastString * field_0x28; // accesses: 3
    byte _padding_0x2c[44];
    CGameAdvertisingRadial * field_0x58; // accesses: 1
    byte _padding_0x5c[40];
    int field_0x84; // accesses: 1
    byte _padding_0x88[64];
    int field_0xc8; // accesses: 3
    CMwNod * field_0xcc; // accesses: 17
    GmIso3 * field_0xd0; // accesses: 6
    byte _final_padding[0xc]; // Total size: 0xe0

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ImpressionHelpers_Update(CGameAdvertising *this,CGameAdvertising *param_1);
    int __thiscall IsInit(CGameAdvertising *this,SVisualHandler *param_1);
    void __thiscall SetAdvertisingZone (CGameAdvertising *this,CGameAdvertising *param_1,CFastString *param_2, CFastString *param_3,CFastString *param_4,CFastString *param_5,CFastString *param_6, CFastString *param_7,CFastString *param_8);
};

#endif // CGAMEADVERTISING_HPP
