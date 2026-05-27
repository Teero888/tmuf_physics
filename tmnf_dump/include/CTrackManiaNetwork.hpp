#ifndef CTRACKMANIANETWORK_HPP
#define CTRACKMANIANETWORK_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CGameCtnApp;
struct CGameCtnGhost;
struct CGameDialogs;
struct CGameMasterServer;
struct CTrackMania;

struct CTrackManiaNetwork {
    void** vftable; // accesses: 4

    // Member Functions
    CTrackManiaMenus * __thiscall GetMenuManager(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1);
    CTrackManiaNetworkServerInfo * __thiscall GetServerInfo(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1);
    int __thiscall ForceEndRound (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CFastString *param_2);
    int __thiscall ForcePlayerTeam (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CGameNetPlayerInfo *param_2, ulong param_3,CFastString *param_4);
    int __thiscall ForceScores (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1, CFastBuffer<struct_CTrackManiaNetwork::SRpcForcedScores> *param_2,int param_3, CFastString *param_4);
    int __thiscall ForceSpectatorTarget (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CGameNetPlayerInfo *param_2, CGameNetPlayerInfo *param_3,ulong param_4,CFastString *param_5);
    int __thiscall GetForceShowAllOpponents (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,int *param_2,int *param_3, CFastString *param_4);
    int __thiscall GetRoundForcedLaps (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,ulong *param_2,ulong *param_3, CFastString *param_4);
    int __thiscall SetForceShowAllOpponents (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,int param_2,CFastString *param_3);
    int __thiscall SetRoundForcedLaps (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,ulong param_2,CFastString *param_3);
    void __thiscall ChallengeNetRoundsFinished (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,int param_2);
    void __thiscall Hack_ResetAfterValidation(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1);
    void __thiscall RefereeDoOneStep (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,SMwFiberContext **param_2, int *param_3);
    void __thiscall RefereeLog (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CFastStringInt *param_2,int param_3);
    void __thiscall SendInvalidReplay (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CFastString *param_2, CGameCtnReplayRecord *param_3,CFastStringInt *param_4);
    void __thiscall SendRefereePlayerScoreCheckResult (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,ulong param_2,CFastString *param_3, ulong param_4,ETmValidateResult param_5,ulong param_6);
    void __thiscall SendScores(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,uchar param_2);
    void __thiscall ValidateReplay (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,SMwFiberContext **param_2, CFastString *param_3,CFastStringInt *param_4,int param_5,CFastString *param_6, CMwNodRef<class_CGameCtnReplayRecord> *param_7,ulong param_8,ulong param_9);
};

#endif // CTRACKMANIANETWORK_HPP
