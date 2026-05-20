#ifndef CSCENETOYCHARACTER_HPP
#define CSCENETOYCHARACTER_HPP

#include "typedefs.h"

struct CHmsItem;
struct CMwNod;
struct GmQuat;

struct CSceneToyCharacter {
    void** vftable; // accesses: 2
    byte _padding_0x4[36];
    CHmsItem * field_0x28; // accesses: 7
    byte _padding_0x2c[76];
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
    undefined4 field_0xa4; // accesses: 2
    undefined4 field_0xa8; // accesses: 1
    float field_0xac; // accesses: 4
    float field_0xb0; // accesses: 4
    float field_0xb4; // accesses: 3
    int field_0xb8; // accesses: 4
    CSceneToyCharacter * field_0xbc; // accesses: 4
    undefined4 field_0xc0; // accesses: 3
    int field_0xc4; // accesses: 5
    int field_0xc8; // accesses: 3
    int field_0xcc; // accesses: 2
    byte _final_padding[0x4]; // Total size: 0xd4

    // Member Functions
    void __thiscall AbsorbContact (CSceneToyCharacter *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
    void __thiscall AfterContacts (CSceneToyCharacter *this,CCallbackSceneVehicleBallAfterContacts *param_1, CHmsItem *param_2);
    void __thiscall ComputeForces (CSceneToyCharacter *this,CCallbackSceneToyBroomStickComputeForces *param_1, CHmsItem *param_2,float param_3);
    void __thiscall SetIsOnGround(CSceneToyCharacter *this,CSceneToyCharacter *param_1,int param_2);
    void __thiscall TuningsSet (CSceneToyCharacter *this,CSceneToyCharacter *param_1,CSceneToyCharacterTunings *param_2);
};

#endif // CSCENETOYCHARACTER_HPP
