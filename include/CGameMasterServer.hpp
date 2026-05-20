#ifndef CGAMEMASTERSERVER_HPP
#define CGAMEMASTERSERVER_HPP

#include "typedefs.h"

struct CGameMasterServer {
    struct SCriteria {
        void** vftable;
        byte _padding_0x4[4];
        undefined4 field_0x8; // accesses: 1
        undefined * field_0xc; // accesses: 2

        // Member Functions
        void __thiscall ~SCriteria(void *this,SCriteria *param_1);
    };

    struct SLadderResult {
        void** vftable; // accesses: 1
        undefined * field_0x4; // accesses: 1

        // Member Functions
        void __thiscall SLadderResult(void *this,SLadderResult *param_1);
    };

    struct SLadderStats {
        void** vftable;
        byte _padding_0x4[24];
        undefined4 field_0x1c; // accesses: 1
        undefined * field_0x20; // accesses: 1

        // Member Functions
        void __thiscall SLadderStats(void *this,SLadderStats *param_1);
    };

    void** vftable;
    byte _final_padding[0x28]; // Total size: 0x2c

    // Member Functions
    CNetMasterServerRequest * __thiscall AddAbuse (CGameMasterServer *this,CGameMasterServer *param_1,CFastString *param_2, CFastStringInt *param_3,CFastStringInt *param_4,CFastStringInt *param_5, CSystemPackDesc *param_6,CSystemPackDesc *param_7,CFastStringInt *param_8,CMwId *param_9);
    CNetMasterServerRequest * __thiscall IsCoppersTransactionPaid (CGameMasterServer *this,CGameMasterServer *param_1,ulong param_2);
    CNetMasterServerRequest * __thiscall ReportInvalidReplay (CGameMasterServer *this,CGameMasterServer *param_1,CFastString *param_2, CClassicBufferMemory *param_3,CFastStringInt *param_4);
    SFeature * __thiscall GetFeatureFromId (CGameMasterServer *this,CGameMasterServer *param_1,CMwId *param_2);
    SFeature * __thiscall GetFeatureFromName (CGameMasterServer *this,CGameMasterServer *param_1,char *param_2);
    int __thiscall IsPayingAccountConnected(CGameMasterServer *this,CGameMasterServer *param_1);
    int __thiscall ReadForceOffline (CGameMasterServer *this,CGameMasterServer *param_1,TiXmlElement *param_2);
    void __cdecl GetLadderRankAsStringInt(ulong param_1,ulong param_2,CFastStringInt *param_3);
    void __thiscall SimulateSendAliveUpdate(CGameMasterServer *this,CGameMasterServer *param_1);
};

#endif // CGAMEMASTERSERVER_HPP
