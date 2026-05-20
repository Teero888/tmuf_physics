#ifndef CGAMECTNNETWORK_HPP
#define CGAMECTNNETWORK_HPP

#include "typedefs.h"

struct CNetMasterServer;

struct CGameCtnNetwork {
    byte _padding_0x0[36];
    CNetMasterServer * field_0x24; // accesses: 5
    CNetMasterServer * field_0x28; // accesses: 2
    byte _padding_0x2c[8];
    uint field_0x34; // accesses: 2
    byte _padding_0x38[8];
    int field_0x40; // accesses: 2
    int field_0x44; // accesses: 1
    byte _padding_0x48[36];
    int field_0x6c; // accesses: 1
    int field_0x70; // accesses: 1
    int field_0x74; // accesses: 1
    char field_0x78; // accesses: 3
    byte _padding_0x79[3];
    int field_0x7c; // accesses: 4
    undefined4 field_0x80; // accesses: 6
    byte _padding_0x84[4];
    int field_0x88; // accesses: 1
    byte _padding_0x8c[292];
    CNetMasterServer * field_0x1b0; // accesses: 2
    byte _padding_0x1b4[1092];
    int * field_0x5f8; // accesses: 9

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
