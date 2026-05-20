#ifndef CGAMENETWORK_HPP
#define CGAMENETWORK_HPP

#include "typedefs.h"

struct CGameMasterServer;
struct CGameNetClient;
struct CGameNetServer;
struct CNetMasterServerRequest;
struct CNetServer;
struct SStringParam;

struct CGameNetwork {
    struct SBill {

        // Member Functions
        void __thiscall SBill (void *this,SBill *param_1,CFastString *param_2,CFastString *param_3, CFastStringInt *param_4,int param_5);
    };

    byte _padding_0x0[4];
    int * field_0x4; // accesses: 12
    byte _padding_0x8[8];
    SStringParam * field_0x10; // accesses: 5
    undefined4 field_0x14; // accesses: 2
    int field_0x18; // accesses: 1
    int field_0x1c; // accesses: 4
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[24];
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    byte _padding_0x58[4];
    undefined4 field_0x5c; // accesses: 1
    byte _padding_0x60[48];
    ulong field_0x90; // accesses: 1
    byte _padding_0x94[24];
    undefined4 field_0xac; // accesses: 1
    ushort field_0xb0; // accesses: 1
    byte _padding_0xb2[2];
    int field_0xb4; // accesses: 3
    byte _padding_0xb8[4];
    CGameNetwork * field_0xbc; // accesses: 1
    undefined1 * field_0xc0; // accesses: 1
    undefined4 field_0xc4; // accesses: 1
    byte _padding_0xc8[92];
    int field_0x124; // accesses: 1
    undefined4 field_0x128; // accesses: 1
    byte _padding_0x12c[28];
    EPlayerType field_0x148; // accesses: 1
    byte _padding_0x14c[24];
    ulong field_0x164; // accesses: 1
    byte _padding_0x168[12];
    int field_0x174; // accesses: 1
    byte _padding_0x178[4];
    int field_0x17c; // accesses: 1
    byte _padding_0x180[4];
    int field_0x184; // accesses: 1
    byte _padding_0x188[32];
    CGameNetClient * field_0x1a8; // accesses: 8
    CGameNetServer * field_0x1ac; // accesses: 10
    int field_0x1b0; // accesses: 3
    byte _padding_0x1b4[4];
    int field_0x1b8; // accesses: 8
    byte _padding_0x1bc[20];
    int field_0x1d0; // accesses: 11
    int field_0x1d4; // accesses: 5
    byte _padding_0x1d8[100];
    int * field_0x23c; // accesses: 15
    byte _padding_0x240[896];
    int field_0x5c0; // accesses: 2

    // Member Functions
    CGameNetPlayerInfo * __thiscall FindPlayerInfoFromLogin(CGameNetwork *this,CGameNetwork *param_1,CFastString *param_2);
    CGameNetPlayerInfo * __thiscall GetPlayerInfoFromUId(CGameNetwork *this,CGameNetwork *param_1,uchar param_2);
    CSystemData * __thiscall FindManiaNetData(CGameNetwork *this,CGameNetwork *param_1,CFastString *param_2);
    int __thiscall ChatSend (CGameNetwork *this,CGameNetwork *param_1,CFastStringInt *param_2,uchar param_3, uchar param_4,uchar param_5,uchar param_6,int param_7,int param_8);
    int __thiscall DisconnectPlayer (CGameNetwork *this,CGameNetwork *param_1,char *param_2,CFastStringInt *param_3, uchar param_4);
    int __thiscall IsChatCommand(CGameNetwork *this,CGameNetwork *param_1,CFastStringInt *param_2);
    int __thiscall IsConnected(CGameNetwork *this,CCrystalVertex *param_1);
    int __thiscall IsIgnored(CGameNetwork *this,CGameNetwork *param_1,CFastString *param_2);
    int __thiscall IsInternet(CGameNetwork *this,CGameNetwork *param_1);
    int __thiscall IsMasterServerConnected(CGameNetwork *this,CGameNetwork *param_1);
    int __thiscall UpdatePlayerInfo (CGameNetwork *this,CGameNetwork *param_1,CNetArchive *param_2,uchar param_3,int *param_4, EPlayerInfoArchiveState param_5,int param_6,CFastString *param_7);
    ulong __thiscall FindPlayerInfoFromUId(CGameNetwork *this,CGameNetwork *param_1,uchar param_2);
    void __cdecl SetPlayerInfoType(CGameNetPlayerInfo *param_1,EPlayerType param_2);
    void __thiscall AddManiaNetData(CGameNetwork *this,CGameNetwork *param_1,CSystemData *param_2);
    void __thiscall CopperTransaction_ChangeBillState (CGameNetwork *this,CGameNetwork *param_1,SBill *param_2,EBillState param_3, CFastString *param_4);
    void __thiscall CopperTransaction_OnFormReceived (CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2);
    void __thiscall CopperTransaction_ValidatePayement (CGameNetwork *this,CGameNetwork *param_1,ulong param_2);
    void __thiscall FormatChat (CGameNetwork *this,CGameNetwork *param_1,CFastStringInt *param_2,ulong param_3, char *param_4,char *param_5,char *param_6);
    void __thiscall OnChatReceived (CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2,int param_3);
    void __thiscall OnDisplayManialinkPageReceived (CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2);
    void __thiscall OnHideManialinkPageReceived(CGameNetwork *this,CGameNetwork *param_1);
    void __thiscall OnManialinkPageAnswerReceived (CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2);
    void __thiscall OnNetFormAdminReceived (CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2, CNetConnectedClient *param_3);
    void __thiscall RemovePlayerInfo(CGameNetwork *this,CGameNetwork *param_1,ulong param_2);
    void __thiscall Send(CGameNetwork *this,CNetConnectedClient *param_1,CNetNod *param_2);
    void __thiscall SendToServer(CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2);
    void __thiscall Sv_SendServerInfo (CGameNetwork *this,CGameNetwork *param_1,CNetConnectedClient *param_2,int param_3);
    void __thiscall WriteToGameLog (CGameNetwork *this,CGameNetwork *param_1,CGameNetPlayerInfo *param_2, CFastStringInt *param_3,char *param_4,int param_5,int param_6);
};

#endif // CGAMENETWORK_HPP
