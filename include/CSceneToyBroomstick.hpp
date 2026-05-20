#ifndef CSCENETOYBROOMSTICK_HPP
#define CSCENETOYBROOMSTICK_HPP

#include "typedefs.h"

struct CHmsItem;
struct CMwCmdBlockMain;
struct CPlugAudio;

struct CSceneToyBroomstick {
    byte _padding_0x0[12];
    float field_0xc; // accesses: 1
    float field_0x10; // accesses: 1
    void * field_0x14; // accesses: 3
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 5
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[164];
    CMwCmdBlockMain * field_0xd4; // accesses: 2
    byte _padding_0xd8[68];
    undefined4 field_0x11c; // accesses: 1
    byte _padding_0x120[24];
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    byte _padding_0x144[36];
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 1
    undefined4 field_0x170; // accesses: 1
    ulong field_0x174; // accesses: 2
    undefined4 field_0x178; // accesses: 3
    undefined4 field_0x17c; // accesses: 3
    undefined4 field_0x180; // accesses: 3

    // Member Functions
    void __thiscall AbsorbContact (CSceneToyBroomstick *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
    void __thiscall ComputeForces (CSceneToyBroomstick *this,CCallbackSceneToyBroomStickComputeForces *param_1, CHmsItem *param_2,float param_3);
    void __thiscall UpdateAsync(CSceneToyBroomstick *this,CInputPortDx8 *param_1);
};

#endif // CSCENETOYBROOMSTICK_HPP
