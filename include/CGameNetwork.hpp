#ifndef CGAMENETWORK_HPP
#define CGAMENETWORK_HPP

#include "typedefs.h"

struct CGameMasterServer;
struct CGameNetClient;
struct CGameNetServer;
struct CNetServer;

struct CGameNetwork {
    struct SBill {
        void** vftable; // accesses: 1
        undefined4 field_0x4; // accesses: 1
        undefined4 field_0x8; // accesses: 1
        undefined * field_0xc; // accesses: 1
        undefined4 field_0x10; // accesses: 1
        undefined4 field_0x14; // accesses: 1
        byte _padding_0x18[24];
        undefined4 field_0x30; // accesses: 1

        // Member Functions
        void __thiscall SBill (void *this,SBill *param_1,CFastString *param_2,CFastString *param_3, CFastStringInt *param_4,int param_5);
    };

    void** vftable; // accesses: 13
    byte _final_padding[0x28]; // Total size: 0x2c

    // Member Functions
    CGameNetPlayerInfo * __thiscall FindPlayerInfoFromLogin(CGameNetwork *this,CGameNetwork *param_1,CFastString *param_2);
    CGameNetPlayerInfo * __thiscall GetPlayerInfoFromUId(CGameNetwork *this,CGameNetwork *param_1,uchar param_2);
    CSystemData * __thiscall FindManiaNetData(CGameNetwork *this,CGameNetwork *param_1,CFastString *param_2);
    EState __thiscall GetState(CGameNetwork *this,CMwCmdFiber *param_1);
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
