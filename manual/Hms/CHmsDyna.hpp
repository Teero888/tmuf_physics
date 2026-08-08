#ifndef CHMSDYNA_HPP
#define CHMSDYNA_HPP

#include "GmVec3.hpp"
#include "GmMat3.hpp"
#include "GmIso4.hpp"
#include "GmQuat.hpp"
#include <cstdint>

// Temporary single-body state used by the standalone harnesses while the
// native per-corpus state layout is still being reconstructed.
extern GmVec3 g_stub_pos;
extern GmVec3 g_stub_forces;
extern GmVec3 g_stub_torques;
extern GmVec3 g_stub_angVel;

// Forward declarations
class CHmsItem;
class CClassicBufferMemory;
class GmFrustumIso4;
class CSceneToyBoat;
class CScenePoc;
class CHmsCorpus;
class CPlugTree;
struct SPredictionTypeVector;
enum EPredictionType : int;
struct SHistoryPoint;

class CHmsDyna {
public:
    class CHmsStateDyna {
    public:
        virtual ~CHmsStateDyna(); // vftable at 0x00
        int m_field_0x4;
        uint8_t m_padding_0x8[56];
        uint32_t m_field_0x40;
        uint32_t m_field_0x44;
        uint32_t m_field_0x48;
        uint32_t m_field_0x4c;
        uint32_t m_field_0x50;
        uint32_t m_field_0x54;
        uint32_t m_field_0x58;
        uint32_t m_field_0x5c;
        uint32_t m_field_0x60;
        uint32_t m_field_0x64;
        uint32_t m_field_0x68;
        uint32_t m_field_0x6c;
        uint32_t m_field_0x70;
        uint32_t m_field_0x74;
        uint32_t m_field_0x78;
        uint8_t m_padding_0x7c[36];
        uint32_t m_field_0xa0;
        uint32_t m_field_0xa4;
        uint32_t m_field_0xa8;
        uint32_t m_field_0xac;

        // Member Functions
        void OldRestoreState(CClassicBufferMemory* param_2, uint8_t param_3);
        void Reset(GmFrustumIso4* param_1);
        void RestoreState(CClassicBufferMemory* param_2, uint8_t param_3);
    };

    virtual ~CHmsDyna(); // 0x00
    uint32_t m_field_0x4;
    uint32_t m_field_0x8;
    uint8_t m_padding_0xc[180];
    uint32_t m_field_0xc0;
    uint32_t m_field_0xc4;
    uint8_t m_padding_0xc8[48];
    float m_field_0xf8;
    float m_field_0xfc;
    float m_field_0x100;
    uint32_t m_field_0x104;
    float* m_field_0x108;
    uint8_t m_padding_0x10c[176];
    void* m_field_0x1bc;
    uint8_t m_padding_0x1c0[176];
    void* m_field_0x270;
    uint8_t m_padding_0x274[180];
    GmQuat* m_field_0x328;
    CHmsStateDyna* m_field_0x32c;
    uint8_t m_padding_0x330[12];
    uint32_t m_field_0x33c;
    CHmsItem* m_field_0x340;
    uint8_t m_padding_0x344[4];
    int m_field_0x348;
    uint32_t m_field_0x34c;
    int m_field_0x350;
    uint8_t m_padding_0x354[4];
    uint32_t m_field_0x358;
    uint32_t m_field_0x35c;
    uint32_t m_field_0x360;
    uint32_t m_field_0x364;
    uint32_t m_field_0x368;
    uint32_t m_field_0x36c;
    uint8_t m_padding_0x370[12];
    uint32_t m_field_0x37c;
    uint32_t m_field_0x380;
    uint32_t m_field_0x384;
    uint32_t m_field_0x388;
    uint32_t m_field_0x38c;
    uint32_t m_field_0x390;
    uint32_t m_field_0x394;
    uint32_t m_field_0x398;
    uint32_t m_field_0x39c;
    uint32_t m_field_0x3a0;
    uint32_t m_field_0x3a4;
    uint32_t m_field_0x3a8;
    uint32_t m_field_0x3ac;
    uint32_t m_field_0x3b0;
    uint32_t m_field_0x3b4;
    uint32_t m_field_0x3b8;
    uint32_t m_field_0x3bc;
    uint32_t m_field_0x3c0;
    uint8_t m_padding_0x3c4[60];
    uint32_t m_field_0x400;
    uint8_t m_padding_0x404[52];
    uint32_t m_field_0x438;
    uint32_t m_field_0x43c;
    uint32_t m_field_0x440;
    uint32_t m_field_0x444;
    uint32_t m_field_0x448;
    uint32_t m_field_0x44c;
    uint8_t m_padding_0x450[12];
    uint32_t m_field_0x45c;
    uint32_t m_field_0x460;
    uint32_t m_field_0x464;
    uint32_t m_field_0x468;
    uint32_t m_field_0x46c;
    uint32_t m_field_0x470;
    uint32_t m_field_0x474;
    uint32_t m_field_0x478;
    uint32_t m_field_0x47c;
    uint32_t m_field_0x480;
    uint32_t m_field_0x484;
    uint32_t m_field_0x488;
    uint32_t m_field_0x48c;
    uint32_t m_field_0x490;
    uint32_t m_field_0x494;
    uint32_t m_field_0x498;
    uint32_t m_field_0x49c;
    uint32_t m_field_0x4a0;
    uint8_t m_padding_0x4a4[60];
    uint32_t m_field_0x4e0;
    uint8_t m_padding_0x4e4[52];
    int m_field_0x518;
    uint32_t m_field_0x51c;
    uint32_t m_field_0x520;
    uint32_t m_field_0x524;
    uint32_t m_field_0x528;
    uint32_t m_field_0x52c;
    uint32_t m_field_0x530;
    uint32_t m_field_0x534;
    uint8_t m_padding_0x538[36];
    uint32_t m_field_0x55c;
    uint32_t m_field_0x560;
    uint32_t m_field_0x564;
    uint8_t m_padding_0x568[36];
    GmMat3* m_field_0x58c;

    // Member Functions
    CHmsDyna();

    SHistoryPoint* AddHistoryPoint(GmVec3* param_2, GmMat3* param_3, uint32_t param_4);
    SHistoryPoint* GetLastHistoryPointMinusOne();
    SHistoryPoint* GetLastHistoryPointMinusTwo();
    float ComputeEmbraceAngleForValue(float param_2, float param_3, float param_4, float param_5);
    int IsStateDifferentFrom(CHmsItem* param_1, GmIso4* param_2);
    int IsTwoLastHistoryPointsDifferent();
    int TestIfRespawn();
    uint32_t GetTimeLastHistoryPointMinusOne();
    
    void AddForce(CHmsItem* param_1, GmVec3* param_2, GmVec3* param_3);
    void AddImpulse(CHmsItem* param_1, GmVec3* param_2);
    void AddLocalForce(GmVec3* param_2);
    void AddLocalImpulse(GmVec3* param_2);
    void AddLocalTorque(GmVec3* param_2);
    void AddReplacement(GmVec3* param_2);
    void AddStateForPrediction(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t param_3, uint32_t param_4);
    void AddTorque(CHmsItem* param_1, GmVec3* param_2);
    void ApplyReplacement(GmVec3* param_2);
    void ChooseInterpolationMethods(GmVec3* param_2, SPredictionTypeVector* param_3, SPredictionTypeVector* param_4);
    void ComputeEmbraceAngle(GmVec3* param_2, GmVec3* param_3, GmVec3* param_4, float param_5, float param_6, float param_7, GmVec3* param_8);
    void ComputeInterpolationConvergencePoint();
    void ComputeInterpolationMethods();
    void ComputeInterpolationParameters(GmVec3* param_2, GmVec3* param_3, SPredictionTypeVector* param_4, GmVec3* param_5, GmVec3* param_6, GmVec3* param_7, uint32_t param_8, uint32_t param_9, uint32_t param_10);
    void ComputeNextPosition(GmVec3* param_2, GmVec3* param_3, GmVec3* param_4, uint32_t param_5, GmVec3* param_6);
    void ComputeNextSpeed(GmVec3* param_2, GmVec3* param_3, uint32_t param_4, GmVec3* param_5);
    void ComputeSpeed(GmVec3* param_2, GmVec3* param_3, GmVec3* param_4, uint32_t param_5, uint32_t param_6);
    void ComputeSpeedAndAccelerationAtTime2(float* param_2, float* param_3, float param_4, float param_5, float param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9);
    void ComputeSynthetizedReplacement(GmVec3* param_2);
    void CopyStateToTemp();
    void CopyTempToState();
    void DoPHBInterpolation(uint32_t param_2, CHmsStateDyna* param_3);
    void DoPostCollisionDynamic();
    void DoPreCollisionDynamic(float param_2);
    
    void GetAngularSpeed(CHmsItem* param_1, GmVec3* param_2);
    void GetForce(CHmsItem* param_1, GmVec3* param_2);
    void GetLinearSpeed(CHmsItem* param_1, GmVec3* param_2);
    void GetLocalAngularSpeed(GmVec3* param_2);
    void GetLocalForce(GmVec3* param_2);
    void GetLocalLinearSpeed(GmVec3* param_2);
    void GetSpeed(CScenePoc* param_1, GmVec3* param_2);
    
    void IntegrateStep(CHmsStateDyna* param_2, CHmsStateDyna* param_3, float param_4);
    void Integrate(float dt);
    void Move(float dt);
    void Interpolate(GmVec3* param_2, GmMat3* param_3, GmVec3* param_4, GmMat3* param_5, uint32_t param_6, SHistoryPoint* param_7, SHistoryPoint* param_8);
    void OldRestoreStaticState(CHmsCorpus* param_1, CClassicBufferMemory* param_2, int param_3, uint8_t param_4, int param_5);
    void PredictPointForInterpolation(GmVec3* param_2, GmMat3* param_3, uint32_t param_4);
    void Reset(GmFrustumIso4* param_1);
    void RestoreStaticState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, int param_3, uint32_t param_4, uint32_t param_5, int param_6);
    void RotateOf(CHmsCorpus* param_1, GmMat3* param_2);
    void SaveState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t* param_3, uint32_t param_4);
    
    void SetAllInterpolationConstant();
    void SetAllInterpolationLinear();
    void SetAllInterpolationMethods(SHistoryPoint* param_2, EPredictionType param_3);
    void SetAngularSpeed(CHmsItem* param_1, GmVec3* param_2);
    void SetAsyncPrevDeltaT_End(GmIso4* param_2);
    void SetDynamicType(CHmsItem* param_1, int param_2); // Used EDynamicType originally
    void SetForce(CHmsItem* param_1, GmVec3* param_2);
    void SetLastPrediction(GmVec3* param_2, GmMat3* param_3, GmVec3* param_4, GmMat3* param_5, uint32_t param_6);
    void SetLinearSpeed(CHmsItem* param_1, GmVec3* param_2);
    void SetLocalAngularSpeed(GmVec3* param_2);
    void SetLocalForce(GmVec3* param_2);
    void SetLocalLinearSpeed(GmVec3* param_2);
    void SetLocalTorque(GmVec3* param_2);
    void SetLocation(CPlugTree* param_1, GmIso4* param_2);
    void SetTorque(CHmsItem* param_1, GmVec3* param_2);
    void SetTranslation(GmIso4* param_1, GmVec3* param_2);
    
    void UpdateHistory(uint32_t param_2);
    void ValidateDynamicState();
};

#endif // CHMSDYNA_HPP
