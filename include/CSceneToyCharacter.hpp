#ifndef CSCENETOYCHARACTER_HPP
#define CSCENETOYCHARACTER_HPP

#include "typedefs.h"

struct CHmsItem;
struct CMwNod;
struct GmQuat;

struct CSceneToyCharacter {
    byte _padding_0x0[12];
    float field_0xc; // accesses: 1
    byte _padding_0x10[4];
    void * field_0x14; // accesses: 3
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[4];
    int field_0x28; // accesses: 7
    byte _padding_0x2c[36];
    int field_0x50; // accesses: 2
    byte _padding_0x54[36];
    float field_0x78; // accesses: 1
    byte _padding_0x7c[4];
    CSceneToyCharacter * field_0x80; // accesses: 4
    byte _padding_0x84[8];
    int field_0x8c; // accesses: 1
    code * field_0x90; // accesses: 2
    float field_0x94; // accesses: 1
    float field_0x98; // accesses: 1
    GmQuat * field_0x9c; // accesses: 3
    undefined4 field_0xa0; // accesses: 1
    float field_0xa4; // accesses: 2
    undefined4 field_0xa8; // accesses: 1
    float field_0xac; // accesses: 4
    float field_0xb0; // accesses: 4
    float field_0xb4; // accesses: 3
    int field_0xb8; // accesses: 4
    CSceneToyCharacter * field_0xbc; // accesses: 4
    undefined4 field_0xc0; // accesses: 3
    ulong field_0xc4; // accesses: 5
    int field_0xc8; // accesses: 3
    int field_0xcc; // accesses: 2
    byte _padding_0xd0[156];
    char field_0x16c; // accesses: 1
    byte _padding_0x16d[11];
    float field_0x178; // accesses: 2
    float field_0x17c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeForces (CSceneToyCharacter *this,CCallbackSceneToyBroomStickComputeForces *param_1, CHmsItem *param_2,float param_3);
    void __thiscall AbsorbContact (CSceneToyCharacter *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
    void __thiscall AfterContacts (CSceneToyCharacter *this,CCallbackSceneVehicleBallAfterContacts *param_1, CHmsItem *param_2);
    void __thiscall SetIsOnGround(CSceneToyCharacter *this,CSceneToyCharacter *param_1,int param_2);
    void __thiscall TuningsSet (CSceneToyCharacter *this,CSceneToyCharacter *param_1,CSceneToyCharacterTunings *param_2);
};

#endif // CSCENETOYCHARACTER_HPP
