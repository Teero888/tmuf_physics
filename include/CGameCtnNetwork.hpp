#ifndef CGAMECTNNETWORK_HPP
#define CGAMECTNNETWORK_HPP

#include "typedefs.h"

struct CNetMasterServer;

struct CGameCtnNetwork {
    void** vftable; // accesses: 1
    byte _final_padding[0x3]; // Total size: 0x7

    // Member Functions
    ulong __thiscall GetNbAutoSpectators(CGameCtnNetwork *this,CGameCtnNetwork *param_1);
    void __thiscall ForcedMods_Send (CGameCtnNetwork *this,CGameCtnNetwork *param_1,CGameNetPlayerInfo *param_2);
    void __thiscall ForcedMusic_Send (CGameCtnNetwork *this,CGameCtnNetwork *param_1,CGameNetPlayerInfo *param_2);
    void __thiscall PauseAllDataDownloads (CGameCtnNetwork *this,CGameCtnNetwork *param_1,ulong param_2,ulong param_3);
    void __thiscall PauseDataDownload (CGameCtnNetwork *this,CGameCtnNetwork *param_1,CGameNetDataDownload *param_2);
    void __thiscall SetForceSpectator(CGameCtnNetwork *this,CGameCtnNetwork *param_1,int param_2);
    void __thiscall UpdateSpectatorsCounts(CGameCtnNetwork *this,CGameCtnNetwork *param_1);
};

#endif // CGAMECTNNETWORK_HPP
