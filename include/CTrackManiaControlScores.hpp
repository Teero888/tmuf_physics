#ifndef CTRACKMANIACONTROLSCORES_HPP
#define CTRACKMANIACONTROLSCORES_HPP

#include "typedefs.h"

struct CGameControlGridCard;
struct CGameCtnEditor;
struct CTrackManiaRaceScore;
struct ulong;

struct CTrackManiaControlScores {
    void** vftable; // accesses: 3
    byte _padding_0x4[16];
    int field_0x14; // accesses: 1
    int field_0x18; // accesses: 1
    byte _padding_0x1c[56];
    int field_0x54; // accesses: 2
    byte _padding_0x58[264];
    int field_0x160; // accesses: 2
    int field_0x164; // accesses: 2
    int field_0x168; // accesses: 1
    CTrackManiaControlScores * field_0x16c; // accesses: 2
    void * field_0x170; // accesses: 1
    int field_0x174; // accesses: 3
    undefined4 field_0x178; // accesses: 2
    byte _padding_0x17c[16];
    CGameCtnEditor * field_0x18c; // accesses: 5
    int * field_0x190; // accesses: 3
    CTrackManiaRaceScore * field_0x194; // accesses: 1
    ulong field_0x198; // accesses: 2
    byte _padding_0x19c[24];
    CGameCtnEditor * field_0x1b4; // accesses: 1
    CGameCtnEditor * field_0x1b8; // accesses: 1
    CGameCtnEditor * field_0x1bc; // accesses: 7
    CGameCtnEditor * field_0x1c0; // accesses: 7
    byte _padding_0x1c4[12];
    CGameControlGridCard * field_0x1d0; // accesses: 1
    CGameControlGridCard * field_0x1d4; // accesses: 2
    CGameControlGridCard * field_0x1d8; // accesses: 2

    // Member Functions
    int __thiscall CanTakeScore (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1, CTrackManiaRaceScore *param_2);
    int __thiscall CanTakeScore_Teams (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1, CTrackManiaRaceScore *param_2,uchar param_3);
    void __thiscall LoadGridPage (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1, CGameControlGridCard *param_2,ulong param_3);
    void __thiscall SaveGridPage (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1, CGameControlGridCard *param_2,ulong *param_3);
    void __thiscall SetFilteredScores (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1, CFastBuffer<class_CTrackManiaRaceScore*> *param_2);
    void __thiscall SetScores (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1, CFastBuffer<class_CTrackManiaRaceScore*> *param_2);
    void __thiscall SetTeamScores (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1, CTrackManiaRaceScore *param_2,CTrackManiaRaceScore *param_3);
    void __thiscall UpdateAsync(CTrackManiaControlScores *this,CInputPortDx8 *param_1);
    void __thiscall UpdateGrid(CTrackManiaControlScores *this,CGameCtnEditor *param_1);
    void __thiscall UpdateGridFocusedScore (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1);
};

#endif // CTRACKMANIACONTROLSCORES_HPP
