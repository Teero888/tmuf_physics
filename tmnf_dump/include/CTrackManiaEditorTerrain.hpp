#ifndef CTRACKMANIAEDITORTERRAIN_HPP
#define CTRACKMANIAEDITORTERRAIN_HPP

#include "typedefs.h"

struct CGameCtnChallenge;

struct CTrackManiaEditorTerrain {
    void** vftable;
    byte _padding_0x4[28];
    CGameCtnChallenge * field_0x20; // accesses: 4
    byte _final_padding[0x528]; // Total size: 0x54c

    // Member Functions
    GmNat3 __thiscall GetCoordFromIndex (CTrackManiaEditorTerrain *this,CGameOutlineBox *param_1,ulong param_2,GmNat3 param_3);
    int __thiscall AdjustCursorHeight (CTrackManiaEditorTerrain *this,CTrackManiaEditorFree *param_1,GmNat3 *param_2);
    ulong __thiscall GetIndexFromCoord (CTrackManiaEditorTerrain *this,CGameOutlineBox *param_1,GmNat3 param_2,GmNat3 param_3);
};

#endif // CTRACKMANIAEDITORTERRAIN_HPP
