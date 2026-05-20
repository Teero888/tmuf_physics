#ifndef CTRACKMANIAEDITORTERRAIN_HPP
#define CTRACKMANIAEDITORTERRAIN_HPP

#include "typedefs.h"

struct CGameCtnChallenge;

struct CTrackManiaEditorTerrain {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 8
    int field_0x8; // accesses: 2
    byte _padding_0xc[20];
    int field_0x20; // accesses: 4

    // Member Functions
    GmNat3 __thiscall GetCoordFromIndex (CTrackManiaEditorTerrain *this,CGameOutlineBox *param_1,ulong param_2,GmNat3 param_3);
    int __thiscall AdjustCursorHeight (CTrackManiaEditorTerrain *this,CTrackManiaEditorFree *param_1,GmNat3 *param_2);
    ulong __thiscall GetIndexFromCoord (CTrackManiaEditorTerrain *this,CGameOutlineBox *param_1,GmNat3 param_2,GmNat3 param_3);
};

#endif // CTRACKMANIAEDITORTERRAIN_HPP
