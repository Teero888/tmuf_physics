#ifndef CTRACKMANIA_HPP
#define CTRACKMANIA_HPP

#include "typedefs.h"

struct CTrackManiaEditor;

struct CTrackMania {
    void** vftable; // accesses: 2
    byte _padding_0x4[296];
    int field_0x12c; // accesses: 2
    byte _padding_0x130[56];
    CTrackManiaPlayerProfile * field_0x168; // accesses: 1
    byte _padding_0x16c[4];
    int field_0x170; // accesses: 1
    byte _padding_0x174[36];
    int field_0x198; // accesses: 2
    byte _padding_0x19c[204];
    undefined4 field_0x268; // accesses: 1
    byte _padding_0x26c[4];
    int field_0x270; // accesses: 1
    byte _padding_0x274[416];
    int * field_0x414; // accesses: 3
    CTrackMania * field_0x418; // accesses: 4
    byte _padding_0x41c[232];
    ulong field_0x504; // accesses: 1
    CTrackMania * field_0x508; // accesses: 1
    byte _padding_0x50c[52];
    int field_0x540; // accesses: 2
    undefined2 * field_0x544; // accesses: 1
    int field_0x548; // accesses: 2
    undefined2 * field_0x54c; // accesses: 1
    byte _final_padding[0x9c]; // Total size: 0x5ec

    // Member Functions
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
    void __thiscall UpdateWaterMap(CTrackMania *this,CTrackMania *param_1);
};

#endif // CTRACKMANIA_HPP
