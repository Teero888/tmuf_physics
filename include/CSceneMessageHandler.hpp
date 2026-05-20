#ifndef CSCENEMESSAGEHANDLER_HPP
#define CSCENEMESSAGEHANDLER_HPP

#include "typedefs.h"

struct CMwCmdBlockMain;
struct CMwNod;
struct CSceneMobilAbsorbContact;
struct ulong;

struct CSceneMessageHandler {
    void** vftable; // accesses: 1
    byte _padding_0x4[20];
    uint field_0x18; // accesses: 1
    CMwCmdBlockMain * field_0x1c; // accesses: 2
    CMwCmdBlockMain * field_0x20; // accesses: 5
    byte _padding_0x24[4];
    CSceneMobilAbsorbContact * field_0x28; // accesses: 4
    ulong field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1

    // Member Functions
    void __thiscall AbsorbContact (CSceneMessageHandler *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
    void __thiscall OnStillFocus (CSceneMessageHandler *this,CSceneMessageHandler *param_1,CSceneMobil *param_2, CSceneInfoFocus *param_3,CSceneInfoFocus *param_4);
    void __thiscall SetOnContactScript (CSceneMessageHandler *this,CSceneMessageHandler *param_1,CMwCmdBlockMain *param_2);
};

#endif // CSCENEMESSAGEHANDLER_HPP
