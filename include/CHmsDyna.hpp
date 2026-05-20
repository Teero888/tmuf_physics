#ifndef CHMSDYNA_HPP
#define CHMSDYNA_HPP

#include "typedefs.h"

struct CPlugAudio;
struct GmIso4;
struct GmMat3;
struct GmVec3;

struct CHmsDyna {
    struct CHmsStateDyna {
        byte _padding_0x0[1];
        ushort field_0x1; // accesses: 1
        byte _padding_0x3[9];
        int field_0xc; // accesses: 1
        byte _padding_0x10[4];
        int field_0x14; // accesses: 1

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall OldRestoreState (void *this,CHmsStateDyna *param_1,CClassicBufferMemory *param_2,uchar param_3);
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall RestoreState (void *this,CHmsStateDyna *param_1,CClassicBufferMemory *param_2,uchar param_3);
    };

    byte _padding_0x0[4];
    SPredictionTypeVector * field_0x4; // accesses: 78
    SPredictionTypeVector * field_0x8; // accesses: 79
    float field_0xc; // accesses: 10
    float field_0x10; // accesses: 12
    float field_0x14; // accesses: 13
    float field_0x18; // accesses: 11
    float field_0x1c; // accesses: 7
    float field_0x20; // accesses: 7
    float field_0x24; // accesses: 6
    float field_0x28; // accesses: 5
    float field_0x2c; // accesses: 5
    float field_0x30; // accesses: 3
    float field_0x34; // accesses: 11
    float field_0x38; // accesses: 11
    float field_0x3c; // accesses: 11
    float field_0x40; // accesses: 8
    float field_0x44; // accesses: 8
    float field_0x48; // accesses: 10
    float field_0x4c; // accesses: 4
    float field_0x50; // accesses: 4
    float field_0x54; // accesses: 3
    float field_0x58; // accesses: 19
    float field_0x5c; // accesses: 19
    float field_0x60; // accesses: 20
    float field_0x64; // accesses: 8
    float field_0x68; // accesses: 8
    float field_0x6c; // accesses: 8
    float field_0x70; // accesses: 8
    float field_0x74; // accesses: 8
    float field_0x78; // accesses: 6
    byte _padding_0x7c[4];
    float field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 2
    undefined4 field_0x88; // accesses: 2
    undefined4 field_0x8c; // accesses: 2
    byte _padding_0x90[16];
    int field_0xa0; // accesses: 1
    byte _padding_0xa4[4];
    GmVec3 * field_0xa8; // accesses: 34
    int field_0xac; // accesses: 3
    SHistoryPoint * field_0xb0; // accesses: 4
    SHistoryPoint * field_0xb4; // accesses: 1
    SHistoryPoint * field_0xb8; // accesses: 1
    SHistoryPoint * field_0xbc; // accesses: 1
    SHistoryPoint * field_0xc0; // accesses: 1
    SHistoryPoint * field_0xc4; // accesses: 1
    byte _padding_0xc8[12];
    SHistoryPoint * field_0xd4; // accesses: 1
    SHistoryPoint * field_0xd8; // accesses: 1
    SHistoryPoint * field_0xdc; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall IsStateDifferentFrom(void *this,CHmsItem *param_1,GmIso4 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall IsTwoLastHistoryPointsDifferent(void *this,CHmsDyna *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall TestIfRespawn(void *this,CHmsDyna *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CHmsDyna(void *this,CHmsDyna *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeInterpolationConvergencePoint(void *this,CHmsDyna *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeInterpolationMethods(void *this,CHmsDyna *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeNextPosition (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4, ulong param_5,GmVec3 *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeNextSpeed (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4, GmVec3 *param_5);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeSpeedAndAccelerationAtTime2 (void *this,CHmsDyna *param_1,float *param_2,float *param_3,float param_4,float param_5, float param_6,ulong param_7,ulong param_8,ulong param_9);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeSynthetizedReplacement(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall IntegrateStep (void *this,CHmsDyna *param_1,CHmsStateDyna *param_2,CHmsStateDyna *param_3,float param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Interpolate (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,GmVec3 *param_4, GmMat3 *param_5,ulong param_6,SHistoryPoint *param_7,SHistoryPoint *param_8);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall PredictPointForInterpolation (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,ulong param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetAsyncPrevDeltaT_End(void *this,CHmsDyna *param_1,GmIso4 *param_2);
    SHistoryPoint * __thiscall AddHistoryPoint (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,ulong param_4);
    SHistoryPoint * __thiscall GetLastHistoryPointMinusOne(void *this,CHmsDyna *param_1);
    SHistoryPoint * __thiscall GetLastHistoryPointMinusTwo(void *this,CHmsDyna *param_1);
    float __thiscall ComputeEmbraceAngleForValue (void *this,CHmsDyna *param_1,float param_2,float param_3,float param_4,float param_5);
    ulong __thiscall GetTimeLastHistoryPointMinusOne(void *this,CHmsDyna *param_1);
    void __thiscall AddForce(void *this,CHmsItem *param_1,GmVec3 *param_2,GmVec3 *param_3);
    void __thiscall AddImpulse(void *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall AddLocalForce(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall AddLocalImpulse(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall AddLocalTorque(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall AddReplacement(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall AddStateForPrediction (void *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong param_3, ulong param_4);
    void __thiscall AddTorque(void *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall ApplyReplacement(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall ChooseInterpolationMethods (void *this,CHmsDyna *param_1,GmVec3 *param_2,SPredictionTypeVector *param_3, SPredictionTypeVector *param_4);
    void __thiscall ComputeEmbraceAngle (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4, float param_5,float param_6,float param_7,GmVec3 *param_8);
    void __thiscall ComputeInterpolationParameters (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3, SPredictionTypeVector *param_4,GmVec3 *param_5,GmVec3 *param_6,GmVec3 *param_7, ulong param_8,ulong param_9,ulong param_10);
    void __thiscall ComputeSpeed (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4, ulong param_5,ulong param_6);
    void __thiscall CopyStateToTemp(void *this,CHmsDyna *param_1);
    void __thiscall CopyTempToState(void *this,CHmsDyna *param_1);
    void __thiscall DoPHBInterpolation(void *this,CHmsDyna *param_1,ulong param_2,CHmsStateDyna *param_3);
    void __thiscall DoPostCollisionDynamic(void *this,CHmsDyna *param_1);
    void __thiscall DoPreCollisionDynamic(void *this,CHmsDyna *param_1,float param_2);
    void __thiscall GetAngularSpeed(void *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall GetForce(void *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall GetLinearSpeed(void *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall GetLocalAngularSpeed(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall GetLocalForce(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall GetLocalLinearSpeed(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall GetSpeed(void *this,CScenePoc *param_1,GmVec3 *param_2);
    void __thiscall OldRestoreStaticState (void *this,CHmsCorpus *param_1,CClassicBufferMemory *param_2,int param_3,uchar param_4, int param_5);
    void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    void __thiscall RestoreStaticState (void *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,int param_3,ulong param_4 ,ulong param_5,int param_6);
    void __thiscall RotateOf(void *this,CHmsCorpus *param_1,GmMat3 *param_2);
    void __thiscall SaveState(void *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong *param_3, ulong param_4);
    void __thiscall SetAllInterpolationConstant(void *this,CHmsDyna *param_1);
    void __thiscall SetAllInterpolationLinear(void *this,CHmsDyna *param_1);
    void __thiscall SetAllInterpolationMethods (void *this,CHmsDyna *param_1,SHistoryPoint *param_2,EPredictionType param_3);
    void __thiscall SetAngularSpeed(void *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall SetDynamicType(void *this,CHmsItem *param_1,EDynamicType param_2);
    void __thiscall SetForce(void *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall SetLastPrediction (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,GmVec3 *param_4, GmMat3 *param_5,ulong param_6);
    void __thiscall SetLinearSpeed(void *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall SetLocalAngularSpeed(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall SetLocalForce(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall SetLocalLinearSpeed(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall SetLocalTorque(void *this,CHmsDyna *param_1,GmVec3 *param_2);
    void __thiscall SetLocation(void *this,CPlugTree *param_1,GmIso4 *param_2);
    void __thiscall SetTorque(void *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall SetTranslation(void *this,GmIso4 *param_1,GmVec3 *param_2);
    void __thiscall UpdateHistory(void *this,CHmsDyna *param_1,ulong param_2);
    void __thiscall ValidateDynamicState(void *this,CHmsDyna *param_1);
    void __thiscall ~CHmsDyna(void *this,CHmsDyna *param_1);
};

#endif // CHMSDYNA_HPP
