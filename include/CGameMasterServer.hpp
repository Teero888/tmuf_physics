#ifndef CGAMEMASTERSERVER_HPP
#define CGAMEMASTERSERVER_HPP

#include "typedefs.h"

struct CClassicBuffer;
struct CFastStringInt;
struct CSystemFid;
struct TiXmlElement;
struct TiXmlNode;
struct TiXmlText;

struct CGameMasterServer {
    struct SCriteria {

        // Member Functions
        void __thiscall ~SCriteria(void *this,SCriteria *param_1);
    };

    struct SLadderResult {

        // Member Functions
        void __thiscall SLadderResult(void *this,SLadderResult *param_1);
    };

    struct SLadderStats {

        // Member Functions
        void __thiscall SLadderStats(void *this,SLadderStats *param_1);
    };

    byte _padding_0x0[4];
    TiXmlText * field_0x4; // accesses: 3
    byte _padding_0x8[4];
    int field_0xc; // accesses: 1
    byte _padding_0x10[4];
    int field_0x14; // accesses: 1
    byte _padding_0x18[8];
    CFastStringInt * field_0x20; // accesses: 1
    TiXmlText * field_0x24; // accesses: 2
    char * field_0x28; // accesses: 1
    byte _padding_0x2c[8];
    undefined4 field_0x34; // accesses: 3
    TiXmlNode * field_0x38; // accesses: 2
    TiXmlElement * field_0x3c; // accesses: 2
    byte _padding_0x40[8];
    int field_0x48; // accesses: 3
    byte _padding_0x4c[300];
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
