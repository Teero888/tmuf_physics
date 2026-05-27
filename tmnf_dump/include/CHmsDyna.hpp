#ifndef CHMSDYNA_HPP
#define CHMSDYNA_HPP

#include "typedefs.h"

struct CHmsItem;
struct GmMat3;
struct GmQuat;

struct CHmsDyna {
    struct CHmsStateDyna {
        void** vftable; // accesses: 2
        int field_0x4; // accesses: 2
        byte _padding_0x8[56];
        undefined4 field_0x40; // accesses: 1
        undefined4 field_0x44; // accesses: 1
        undefined4 field_0x48; // accesses: 1
        undefined4 field_0x4c; // accesses: 1
        undefined4 field_0x50; // accesses: 1
        undefined4 field_0x54; // accesses: 1
        undefined4 field_0x58; // accesses: 1
        undefined4 field_0x5c; // accesses: 1
        undefined4 field_0x60; // accesses: 1
        undefined4 field_0x64; // accesses: 1
        undefined4 field_0x68; // accesses: 1
        undefined4 field_0x6c; // accesses: 1
        undefined4 field_0x70; // accesses: 1
        undefined4 field_0x74; // accesses: 1
        undefined4 field_0x78; // accesses: 1
        byte _padding_0x7c[36];
        undefined4 field_0xa0; // accesses: 1
        undefined4 field_0xa4; // accesses: 1
        undefined4 field_0xa8; // accesses: 1
        undefined4 field_0xac; // accesses: 1

        // Member Functions
        void __thiscall OldRestoreState (void *this,CHmsStateDyna *param_1,CClassicBufferMemory *param_2,uchar param_3);
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall RestoreState (void *this,CHmsStateDyna *param_1,CClassicBufferMemory *param_2,uchar param_3);
    };

    void** vftable; // accesses: 1
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[180];
    undefined4 field_0xc0; // accesses: 2
    undefined4 field_0xc4; // accesses: 2
    byte _padding_0xc8[48];
    float field_0xf8; // accesses: 1
    float field_0xfc; // accesses: 1
    float field_0x100; // accesses: 1
    undefined4 field_0x104; // accesses: 1
    float * field_0x108; // accesses: 7
    byte _padding_0x10c[176];
    void * field_0x1bc; // accesses: 1
    byte _padding_0x1c0[176];
    void * field_0x270; // accesses: 1
    byte _padding_0x274[180];
    GmQuat * field_0x328; // accesses: 18
    CHmsStateDyna * field_0x32c; // accesses: 33
    byte _padding_0x330[12];
    undefined4 field_0x33c; // accesses: 5
    CHmsItem * field_0x340; // accesses: 7
    byte _padding_0x344[4];
    int field_0x348; // accesses: 31
    uint field_0x34c; // accesses: 49
    int field_0x350; // accesses: 30
    byte _padding_0x354[4];
    undefined4 field_0x358; // accesses: 2
    undefined4 field_0x35c; // accesses: 2
    undefined4 field_0x360; // accesses: 2
    undefined4 field_0x364; // accesses: 2
    undefined4 field_0x368; // accesses: 2
    undefined4 field_0x36c; // accesses: 2
    byte _padding_0x370[12];
    undefined4 field_0x37c; // accesses: 1
    undefined4 field_0x380; // accesses: 1
    undefined4 field_0x384; // accesses: 1
    undefined4 field_0x388; // accesses: 1
    undefined4 field_0x38c; // accesses: 1
    undefined4 field_0x390; // accesses: 1
    undefined4 field_0x394; // accesses: 1
    undefined4 field_0x398; // accesses: 1
    undefined4 field_0x39c; // accesses: 1
    undefined4 field_0x3a0; // accesses: 1
    undefined4 field_0x3a4; // accesses: 1
    undefined4 field_0x3a8; // accesses: 1
    undefined4 field_0x3ac; // accesses: 1
    undefined4 field_0x3b0; // accesses: 1
    undefined4 field_0x3b4; // accesses: 1
    undefined4 field_0x3b8; // accesses: 1
    undefined4 field_0x3bc; // accesses: 1
    undefined4 field_0x3c0; // accesses: 1
    byte _padding_0x3c4[60];
    undefined4 field_0x400; // accesses: 2
    byte _padding_0x404[52];
    undefined4 field_0x438; // accesses: 2
    undefined4 field_0x43c; // accesses: 2
    undefined4 field_0x440; // accesses: 2
    undefined4 field_0x444; // accesses: 2
    undefined4 field_0x448; // accesses: 2
    undefined4 field_0x44c; // accesses: 2
    byte _padding_0x450[12];
    undefined4 field_0x45c; // accesses: 1
    undefined4 field_0x460; // accesses: 1
    undefined4 field_0x464; // accesses: 1
    undefined4 field_0x468; // accesses: 1
    undefined4 field_0x46c; // accesses: 1
    undefined4 field_0x470; // accesses: 1
    undefined4 field_0x474; // accesses: 1
    undefined4 field_0x478; // accesses: 1
    undefined4 field_0x47c; // accesses: 1
    undefined4 field_0x480; // accesses: 1
    undefined4 field_0x484; // accesses: 1
    undefined4 field_0x488; // accesses: 1
    undefined4 field_0x48c; // accesses: 1
    undefined4 field_0x490; // accesses: 1
    undefined4 field_0x494; // accesses: 1
    undefined4 field_0x498; // accesses: 1
    undefined4 field_0x49c; // accesses: 1
    undefined4 field_0x4a0; // accesses: 1
    byte _padding_0x4a4[60];
    undefined4 field_0x4e0; // accesses: 4
    byte _padding_0x4e4[52];
    int field_0x518; // accesses: 13
    undefined4 field_0x51c; // accesses: 8
    undefined4 field_0x520; // accesses: 7
    undefined4 field_0x524; // accesses: 6
    undefined4 field_0x528; // accesses: 8
    undefined4 field_0x52c; // accesses: 2
    undefined4 field_0x530; // accesses: 2
    undefined4 field_0x534; // accesses: 2
    byte _padding_0x538[36];
    undefined4 field_0x55c; // accesses: 2
    undefined4 field_0x560; // accesses: 2
    undefined4 field_0x564; // accesses: 2
    byte _padding_0x568[36];
    GmMat3 * field_0x58c; // accesses: 3

    // Member Functions
    SHistoryPoint * __thiscall AddHistoryPoint (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,ulong param_4);
    SHistoryPoint * __thiscall GetLastHistoryPointMinusOne(void *this,CHmsDyna *param_1);
    SHistoryPoint * __thiscall GetLastHistoryPointMinusTwo(void *this,CHmsDyna *param_1);
    float __thiscall ComputeEmbraceAngleForValue (void *this,CHmsDyna *param_1,float param_2,float param_3,float param_4,float param_5);
    int __thiscall IsStateDifferentFrom(void *this,CHmsItem *param_1,GmIso4 *param_2);
    int __thiscall IsTwoLastHistoryPointsDifferent(void *this,CHmsDyna *param_1);
    int __thiscall TestIfRespawn(void *this,CHmsDyna *param_1);
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
    void __thiscall CHmsDyna(void *this,CHmsDyna *param_1);
    void __thiscall ChooseInterpolationMethods (void *this,CHmsDyna *param_1,GmVec3 *param_2,SPredictionTypeVector *param_3, SPredictionTypeVector *param_4);
    void __thiscall ComputeEmbraceAngle (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4, float param_5,float param_6,float param_7,GmVec3 *param_8);
    void __thiscall ComputeInterpolationConvergencePoint(void *this,CHmsDyna *param_1);
    void __thiscall ComputeInterpolationMethods(void *this,CHmsDyna *param_1);
    void __thiscall ComputeInterpolationParameters (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3, SPredictionTypeVector *param_4,GmVec3 *param_5,GmVec3 *param_6,GmVec3 *param_7, ulong param_8,ulong param_9,ulong param_10);
    void __thiscall ComputeNextPosition (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4, ulong param_5,GmVec3 *param_6);
    void __thiscall ComputeNextSpeed (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4, GmVec3 *param_5);
    void __thiscall ComputeSpeed (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4, ulong param_5,ulong param_6);
    void __thiscall ComputeSpeedAndAccelerationAtTime2 (void *this,CHmsDyna *param_1,float *param_2,float *param_3,float param_4,float param_5, float param_6,ulong param_7,ulong param_8,ulong param_9);
    void __thiscall ComputeSynthetizedReplacement(void *this,CHmsDyna *param_1,GmVec3 *param_2);
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
    void __thiscall IntegrateStep (void *this,CHmsDyna *param_1,CHmsStateDyna *param_2,CHmsStateDyna *param_3,float param_4);
    void __thiscall Interpolate (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,GmVec3 *param_4, GmMat3 *param_5,ulong param_6,SHistoryPoint *param_7,SHistoryPoint *param_8);
    void __thiscall OldRestoreStaticState (void *this,CHmsCorpus *param_1,CClassicBufferMemory *param_2,int param_3,uchar param_4, int param_5);
    void __thiscall PredictPointForInterpolation (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,ulong param_4);
    void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    void __thiscall RestoreStaticState (void *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,int param_3,ulong param_4 ,ulong param_5,int param_6);
    void __thiscall RotateOf(void *this,CHmsCorpus *param_1,GmMat3 *param_2);
    void __thiscall SaveState(void *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong *param_3, ulong param_4);
    void __thiscall SetAllInterpolationConstant(void *this,CHmsDyna *param_1);
    void __thiscall SetAllInterpolationLinear(void *this,CHmsDyna *param_1);
    void __thiscall SetAllInterpolationMethods (void *this,CHmsDyna *param_1,SHistoryPoint *param_2,EPredictionType param_3);
    void __thiscall SetAngularSpeed(void *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall SetAsyncPrevDeltaT_End(void *this,CHmsDyna *param_1,GmIso4 *param_2);
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
