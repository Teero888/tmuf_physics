#ifndef CHMSDYNA_HPP
#define CHMSDYNA_HPP

#include "GmVec3.hpp"
#include "GmMat3.hpp"
#include "GmIso4.hpp"
#include "GmQuat.hpp"
#include "CFastBuffer.hpp"
#include <cstddef>
#include <cstdint>
#include <type_traits>

// Forward declarations
class CHmsItem;
class CClassicBufferMemory;
class GmFrustumIso4;
class CSceneToyBoat;
class CScenePoc;
class CHmsCorpus;
class CPlugTree;
class CPlugPhysicalObject;
struct SPredictionTypeVector;
enum EPredictionType : int;
struct SHistoryPoint;

class CHmsDyna {
public:
    struct CHmsStateDyna {
    public:
        GmQuat m_rotation;                 // 0x00
        GmMat3 m_rotationMatrix;           // 0x10
        GmVec3 m_position;                 // 0x34
        GmVec3 m_linearSpeed;              // 0x40
        GmVec3 m_additionalLinearSpeed;    // 0x4C
        GmVec3 m_angularSpeed;             // 0x58
        GmVec3 m_force;                    // 0x64
        GmVec3 m_torque;                   // 0x70
        GmMat3 m_worldInverseInertia;       // 0x7C
        uint32_t m_hasSavedLinearSpeed;     // 0xA0
        GmVec3 m_savedLinearSpeed;          // 0xA4
        uint32_t m_owner32;                 // 0xB0

        // Member Functions
        void OldRestoreState(CClassicBufferMemory* param_2, uint8_t param_3);
        void Reset(GmFrustumIso4* param_1);
        void RestoreState(CClassicBufferMemory* param_2, uint8_t param_3);
        void Initialize();
    };

    virtual ~CHmsDyna(); // 0x00
    uint32_t m_field_0x4;
    uint32_t m_field_0x8;
    CHmsStateDyna m_asyncState;             // native +0x00C
    uint32_t m_field_0xc0;
    float m_field_0xc4;
    uint8_t m_padding_0xc8[48];
    float m_field_0xf8;
    float m_field_0xfc;
    float m_field_0x100;
    uint32_t m_field_0x104;
    CPlugPhysicalObject* m_field_0x108;
    CHmsStateDyna m_validatedStateStorage;  // native +0x10C
    CHmsStateDyna m_currentStateStorage;    // native +0x1C0
    CHmsStateDyna m_tempState;              // native +0x274
    CHmsStateDyna* m_validatedState;        // native +0x328
    CHmsStateDyna* m_currentState;          // native +0x32C
    uint8_t m_padding_0x330[12];
    uint32_t m_field_0x33c;
    int m_dynamicType;                      // native +0x340
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
    // The executable stores this CFastBuffer<GmVec3> in the 12-byte region at
    // +0x330. Keep host-pointer storage out-of-line so the following native
    // field map is not shifted by 64-bit pointers.
    CFastBuffer<GmVec3> m_replacements;

    // Member Functions
    CHmsDyna();
    CHmsDyna(const CHmsDyna&) = delete;
    CHmsDyna& operator=(const CHmsDyna&) = delete;

    CHmsStateDyna& CurrentState() { return *m_currentState; }
    const CHmsStateDyna& CurrentState() const { return *m_currentState; }
    CHmsStateDyna& ValidatedState() { return *m_validatedState; }
    const CHmsStateDyna& ValidatedState() const { return *m_validatedState; }
    GmVec3& Position() { return m_currentState->m_position; }
    const GmVec3& Position() const { return m_currentState->m_position; }
    GmVec3& Force() { return m_currentState->m_force; }
    const GmVec3& Force() const { return m_currentState->m_force; }
    GmVec3& Torque() { return m_currentState->m_torque; }
    const GmVec3& Torque() const { return m_currentState->m_torque; }
    GmVec3& AngularSpeed() { return m_currentState->m_angularSpeed; }
    const GmVec3& AngularSpeed() const { return m_currentState->m_angularSpeed; }
    float GetMass() const;
    GmVec3 GetCenterOfMassWorld() const;
    void UpdateWorldInverseInertia();
    float GetYaw() const;
    void SetYaw(float yaw);

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
    void AddLocalForceAtPoint(
        const GmVec3* localForce, const GmVec3* localPoint);
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
    void GetSpeed(const GmVec3* point, GmVec3* speed);
    void AddImpulseAtPoint(const GmVec3* impulse, const GmVec3* point);
    
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

static_assert(sizeof(CHmsDyna::CHmsStateDyna) == 0xB4,
              "CHmsStateDyna must retain the native 0xB4-byte layout");
static_assert(std::is_standard_layout<CHmsDyna::CHmsStateDyna>::value);
static_assert(std::is_trivially_copyable<CHmsDyna::CHmsStateDyna>::value);
static_assert(offsetof(CHmsDyna::CHmsStateDyna, m_rotationMatrix) == 0x10);
static_assert(offsetof(CHmsDyna::CHmsStateDyna, m_position) == 0x34);
static_assert(offsetof(CHmsDyna::CHmsStateDyna, m_linearSpeed) == 0x40);
static_assert(offsetof(CHmsDyna::CHmsStateDyna, m_additionalLinearSpeed) == 0x4C);
static_assert(offsetof(CHmsDyna::CHmsStateDyna, m_angularSpeed) == 0x58);
static_assert(offsetof(CHmsDyna::CHmsStateDyna, m_force) == 0x64);
static_assert(offsetof(CHmsDyna::CHmsStateDyna, m_torque) == 0x70);
static_assert(offsetof(CHmsDyna::CHmsStateDyna, m_worldInverseInertia) == 0x7C);
static_assert(offsetof(CHmsDyna::CHmsStateDyna, m_hasSavedLinearSpeed) == 0xA0);
static_assert(offsetof(CHmsDyna::CHmsStateDyna, m_owner32) == 0xB0);

#endif // CHMSDYNA_HPP
