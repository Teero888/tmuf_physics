#ifndef CGAMEMASTERSERVER_HPP
#define CGAMEMASTERSERVER_HPP

#include "typedefs.h"

struct CNetConnection;
struct ulong;

struct CGameMasterServer {
    struct SCriteria {
        byte _padding_0x0[8];
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
        byte _padding_0x0[28];
        undefined4 field_0x1c; // accesses: 1
        undefined * field_0x20; // accesses: 1

        // Member Functions
        void __thiscall SLadderStats(void *this,SLadderStats *param_1);
    };

    void** vftable; // accesses: 1
    byte _padding_0x4[48];
    undefined4 field_0x34; // accesses: 3
    byte _padding_0x38[320];
    undefined4 field_0x178; // accesses: 2
    byte _padding_0x17c[8];
    int field_0x184; // accesses: 3
    byte _padding_0x188[56];
    int field_0x1c0; // accesses: 1
    byte _padding_0x1c4[12];
    void * field_0x1d0; // accesses: 1
    byte _padding_0x1d4[12];
    ulong field_0x1e0; // accesses: 1
    byte _padding_0x1e4[252];
    undefined2 * field_0x2e0; // accesses: 1

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
