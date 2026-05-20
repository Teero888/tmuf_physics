#ifndef CGAMECTNCHALLENGE_HPP
#define CGAMECTNCHALLENGE_HPP

#include "typedefs.h"

struct CGameCtnChapter;
struct CGameCtnCollection;

struct CGameCtnChallenge {
    struct SHeaderCommunity {
        void** vftable; // accesses: 1
        undefined * field_0x4; // accesses: 2

        // Member Functions
        void __thiscall ~SHeaderCommunity(void *this,SHeaderCommunity *param_1);
    };

    void** vftable; // accesses: 1
    byte _padding_0x4[32];
    int field_0x24; // accesses: 4
    byte _padding_0x28[56];
    uint field_0x60; // accesses: 1
    byte _padding_0x64[44];
    CGameCtnChapter * field_0x90; // accesses: 4
    byte _padding_0x94[20];
    CGameCtnChallenge * field_0xa8; // accesses: 1
    uint field_0xac; // accesses: 1
    uint field_0xb0; // accesses: 3
    byte _padding_0xb4[32];
    CGameCtnChallenge * field_0xd4; // accesses: 3
    int field_0xd8; // accesses: 3
    byte _padding_0xdc[204];
    int field_0x1a8; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetStartLight(CGameCtnChallenge *this,CGameCtnChallenge *param_1,ulong param_2);
    CGameCtnBlock * __thiscall GetBlockFromPlayField (CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2);
    CGameCtnBlock * __thiscall GetGroundBlock(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2);
    CGameCtnBlock * __thiscall GetStartLine(CGameCtnChallenge *this,CGameCtnChallenge *param_1,ulong param_2);
    CGameCtnBlockUnit * __thiscall GetBlockUnitFromPlayField (CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2);
    CGameCtnBlockUnitInfo * __thiscall GetBlockUnitInfoFromPlayField (CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2);
    CGameCtnFieldUnit * __thiscall GetFieldUnit(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2);
    CGameCtnZone * __thiscall GetRealZone(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2);
    CGameCtnZone * __thiscall GetZone(CGameCtnChallenge *this,CGameCtnCollection *param_1,CMwId *param_2);
    CMwId * __thiscall GetRealZoneId(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2);
    CMwId * __thiscall GetZoneId(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2);
    SGameCtnIdentifier * __thiscall GetVehicleIdent(CGameCtnChallenge *this,CGameCtnChallenge *param_1);
    int __thiscall IsCheckpointBlock (CGameCtnChallenge *this,CGameCtnChallenge *param_1,CGameCtnBlock *param_2);
    int __thiscall IsEditableCoord (CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2);
    int __thiscall IsStartBlock (CGameCtnChallenge *this,CGameCtnChallenge *param_1,CGameCtnBlock *param_2);
    int __thiscall IsStartFinishBlock (CGameCtnChallenge *this,CGameCtnChallenge *param_1,CGameCtnBlock *param_2);
    uchar __thiscall GetZoneHeight(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2);
    void __thiscall GetCoordFromPos (CGameCtnChallenge *this,GmField2Base *param_1,GmVec2 *param_2,GmNat2 *param_3);
    void __thiscall SetIsBlockHelpers (CGameCtnChallenge *this,CGameCtnChallenge *param_1,int param_2,int param_3);
};

#endif // CGAMECTNCHALLENGE_HPP
