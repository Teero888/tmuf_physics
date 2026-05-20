#ifndef CTRACKMANIAPLAYERINFO_HPP
#define CTRACKMANIAPLAYERINFO_HPP

#include "typedefs.h"

struct CTrackManiaPlayerInfo {
    struct SRpcPlayerQuickInfo {
        void** vftable; // accesses: 1
        undefined1 field_0x1; // accesses: 1
        undefined2 field_0x2; // accesses: 1
        byte _padding_0x4[16];
        undefined4 field_0x14; // accesses: 1
        undefined4 field_0x18; // accesses: 1

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    void** vftable; // accesses: 1
    byte _final_padding[0x20]; // Total size: 0x24

    // Member Functions
    int __thiscall IsPureSpectator(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall CTrackManiaPlayerInfo (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall ChangeRaceState (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1,ulong param_2, ERaceState param_3);
    void __thiscall InitBestCheckpoints (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall InitCheckpoints(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall ResetAverageRank(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall ResetPerformance(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1);
    void __thiscall SetNbCheckpoints (CTrackManiaPlayerInfo *this,CGameCtnGhost *param_1,ulong param_2);
    void __thiscall SetSpawnLoc (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1,GmIso4 *param_2,int param_3);
};

#endif // CTRACKMANIAPLAYERINFO_HPP
