#ifndef CTRACKMANIA_HPP
#define CTRACKMANIA_HPP

#include "typedefs.h"

struct CHmsItem;
struct CTrackManiaEditor;

struct CTrackMania {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
    float field_0x8; // accesses: 1
    float field_0xc; // accesses: 1
    byte _padding_0x10[28];
    int field_0x2c; // accesses: 1
    int * field_0x30; // accesses: 1
    byte _padding_0x34[4];
    CHmsItem * field_0x38; // accesses: 1
    byte _padding_0x3c[28];
    int field_0x58; // accesses: 1
    byte _padding_0x5c[36];
    float field_0x80; // accesses: 1
    byte _padding_0x84[16];
    float field_0x94; // accesses: 1
    float field_0x98; // accesses: 1
    int field_0x9c; // accesses: 1
    float field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    byte _padding_0xa8[132];
    int field_0x12c; // accesses: 2
    byte _padding_0x130[56];
    CTrackManiaPlayerProfile * field_0x168; // accesses: 1
    byte _padding_0x16c[4];
    int field_0x170; // accesses: 1
    byte _padding_0x174[4];
    float field_0x178; // accesses: 1
    float field_0x17c; // accesses: 1
    undefined4 field_0x180; // accesses: 1
    byte _padding_0x184[20];
    int field_0x198; // accesses: 2
    byte _padding_0x19c[68];
    code * field_0x1e0; // accesses: 1
    byte _padding_0x1e4[132];
    undefined4 field_0x268; // accesses: 1
    byte _padding_0x26c[4];
    int field_0x270; // accesses: 1
    byte _padding_0x274[416];
    CTrackManiaEditor * field_0x414; // accesses: 3
    int field_0x418; // accesses: 5
    byte _padding_0x41c[232];
    ulong field_0x504; // accesses: 1
    CTrackMania * field_0x508; // accesses: 1
    byte _padding_0x50c[52];
    undefined4 field_0x540; // accesses: 2
    undefined2 * field_0x544; // accesses: 1
    undefined4 field_0x548; // accesses: 2
    undefined2 * field_0x54c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateWaterMap(CTrackMania *this,CTrackMania *param_1);
    CTrackManiaEditor * __thiscall GetTmBlockEditor(CTrackMania *this,CTrackMania *param_1);
    CTrackManiaNetworkServerInfo * __thiscall GetServerInfo(CTrackMania *this,CTrackManiaNetwork *param_1);
    CTrackManiaPlayerProfile * __thiscall GetTMCurrentProfile(CTrackMania *this,CTrackMania *param_1);
    int __thiscall GetPlayerInfo (CTrackMania *this,CTrackManiaNetwork *param_1,CFastString *param_2, SRpcPlayerInfo *param_3,CFastString *param_4);
    int __thiscall IsInHotSeatMode(CTrackMania *this,CTrackMania *param_1);
    int __thiscall IsInSoloMode(CTrackMania *this,CTrackMania *param_1);
    int __thiscall IsInStuntsMode(CTrackMania *this,CTrackMania *param_1);
    void __thiscall CancelOfficialRecord(CTrackMania *this,CTrackMania *param_1);
    void __thiscall DoStopOfficialRecord (CTrackMania *this,CTrackMania *param_1,ulong param_2,ulong param_3);
    void __thiscall SetChallengeType(CTrackMania *this,CTrackMania *param_1,EChallengeType param_2);
};

#endif // CTRACKMANIA_HPP
