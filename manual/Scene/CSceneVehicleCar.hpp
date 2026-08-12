#ifndef CSCENEVEHICLECAR_HPP
#define CSCENEVEHICLECAR_HPP

#include "CSceneVehicle.hpp"
#include "GmVec3.hpp"
#include "GmIso4.hpp"
#include "GmMat3.hpp"
#include "GmBoxAligned.hpp"
#include "CFastBuffer.hpp"
#include "StadiumVehicleMaterials.hpp"
#include <cstddef>
#include <cstdint>
#include <type_traits>

class CHmsItem;
class CHmsCorpus;
class CSceneVehicleCarTuning;
class CSceneSoundSource;
class CPlugShaderGeneric;
class CCallbackSceneVehicleBallAfterContacts;
class CClassicArchive;
class CFuncSegment;
class CControlStyle;
class CMwCmdExpIso4Ident;
class CPlugBlendShapes;
class CMwStack;
class CMwValueStd;
class CSystemData;
class CRpcCallInternal;
class CDx9DeviceCaps;
class CSceneVehicleBall;
class CSceneToyBoat;
class CSceneToyBroomstick;
class CSceneToyCharacter;
class CSceneMobilAbsorbContact;
class CHmsPhysicalContact;
class CCallbackSceneToyBroomStickComputeForces;
struct SBlendableVals;
struct GmFrustumIso4;
struct CPfmHeap;

enum EVehicleEvent {
    VE_NONE = 0
};

class CSceneVehicleCar : public CSceneVehicle {
public:
    void AddVehicleTorque(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3);
    // TmForeverFixed.exe 0x7BE380, a thin forward to the item's local
    // angular-speed setter.
    void SetVehicleAngularSpeed(GmVec3* localAngularSpeed);
    void AddVehicleCentralForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3);
    void AddVehicleForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3, GmVec3 *param_4);

    struct SDynaPart {
        virtual ~SDynaPart();
        uint8_t m_padding[24];
        uint32_t field_0x1c;
        uint32_t field_0x20;
    };

    struct SEngine {
        float m_maxRpm;             // 0x00 (+0x59C)
        float m_field_0x04;         // 0x04
        float m_field_0x08;         // 0x08
        float m_field_0x0c;         // 0x0C
        float m_field_0x10;         // 0x10
        float m_field_0x14;         // 0x14
        float m_engineRpm;          // 0x18 (+0x5B4)
        float m_clutchRpm;          // 0x1C (+0x5B8)
        float m_clutchRatio;        // 0x20 (+0x5BC)
        float m_gearShiftTimer;     // 0x24 (+0x5C0)
        union {
            int m_field_0x28;       // Original translated-code name.
            int m_isReverse;        // 0x28 (+0x5C4)
        };
        int m_currentGear;          // 0x2C (+0x5C8)
        float m_field_0x30;         // 0x30 (+0x5CC)

        void Reset();
    };

    static_assert(std::is_standard_layout_v<SEngine>);
    static_assert(sizeof(SEngine) == 0x34);
    static_assert(offsetof(SEngine, m_maxRpm) == 0x00);
    static_assert(offsetof(SEngine, m_field_0x14) == 0x14);
    static_assert(offsetof(SEngine, m_engineRpm) == 0x18);
    static_assert(offsetof(SEngine, m_clutchRpm) == 0x1C);
    static_assert(offsetof(SEngine, m_clutchRatio) == 0x20);
    static_assert(offsetof(SEngine, m_gearShiftTimer) == 0x24);
    static_assert(offsetof(SEngine, m_isReverse) == 0x28);
    static_assert(offsetof(SEngine, m_currentGear) == 0x2C);

    struct SSimulationWheel {

        struct SRealTimeState {
            float m_compression;         // 0x00 (Wheel + 0xB4)
            float m_velocity;            // 0x04 (Wheel + 0xB8)
            float m_absorbDelta;          // 0x08 (Wheel + 0xBC)
            // 0x0C (Wheel + 0xC0). IntegrateVehicle copies the surface
            // handler's base rotation here every step and then rotates a
            // steerable wheel about Y by the visual steering angle.
            GmMat3 m_steeringFrame;       // 0x0C
            GmIso4 m_orientation;         // 0x30 (Wheel + 0xE4)
            uint8_t m_padding_0x60[0x6C - 0x60];
            float m_angularVelocity;     // 0x6C (Wheel + 0x120)
            uint8_t m_padding_0x70[0x90 - 0x70];
            GmVec3 m_direction;           // 0x90 (Wheel + 0x144)
            float m_rotationAngle;       // 0x9C (Wheel + 0x150)
            float m_steeringAngle;        // 0xA0 (Wheel + 0x154)
            float m_targetSteeringAngle;  // 0xA4 (Wheel + 0x158)
            
            void Integrate(float dt);
        };

        static_assert(std::is_standard_layout_v<SRealTimeState>);
        static_assert(sizeof(SRealTimeState) == 0xA8);
        static_assert(offsetof(SRealTimeState, m_compression) == 0x00);
        static_assert(offsetof(SRealTimeState, m_steeringFrame) == 0x0C);
        static_assert(offsetof(SRealTimeState, m_orientation) == 0x30);
        static_assert(offsetof(SRealTimeState, m_angularVelocity) == 0x6C);
        static_assert(offsetof(SRealTimeState, m_direction) == 0x90);
        static_assert(offsetof(SRealTimeState, m_rotationAngle) == 0x9C);
        static_assert(offsetof(SRealTimeState, m_targetSteeringAngle) == 0xA4);

        struct SState {
            virtual ~SState();
            uint32_t m_field_0x4;
            uint32_t m_field_0x8;
            uint16_t m_field_0xc;
            uint8_t m_padding[2];
            uint32_t m_field_0x10;
            uint32_t m_field_0x14;
            uint32_t m_field_0x18;
            uint32_t m_field_0x1c;
            uint32_t m_field_0x20;
            uint32_t m_field_0x24;
            uint32_t m_field_0x28;
            uint32_t m_field_0x2c;
            uint8_t m_padding2[36];
            uint32_t m_field_0x54;
            uint32_t m_field_0x58;
            uint32_t m_field_0x5c;
            uint32_t m_field_0x60;
            
            void Reset();
        };

        uint32_t m_field_0x00;        // 0x00
        union {
            uint32_t m_field_0x04;    // Original field name retained for translated code.
            uint32_t m_isSteerable;   // 0x04: non-zero for the front axle.
        };
        float m_radius;               // 0x08
        SSurfaceHandler m_surfaceHandler; // 0x0C
        
        uint8_t m_padding_mid[0x124 - 0x10]; 
        int m_hasGroundContact;      // 0x124
        uint16_t m_groundMaterial;   // 0x128
        uint8_t m_padding_after_material[0x12C - 0x12A];
        int m_isSlipping;             // 0x12C; reset independently of +0x00.
        uint8_t m_padding_end[0x158 - 0x130];
        
        SRealTimeState m_realTimeState; 
        
        // Standalone observation of the most recently applied suspension
        // scalar; native WheelAddForceToVehicle keeps this value temporary.
        float m_suspensionForce;

        // Semantic host views of the contact accumulators at native wheel
        // +0x108, +0x140, +0x144, +0x15C, and +0x160. They live outside the
        // raw 32-bit layout because host pointers make the enclosing wheel a
        // different size in the standalone build.
        GmVec3 m_absorbContactPoint;
        uint32_t m_groundContactCount;
        GmVec3 m_groundContactNormalSum;
        int m_hasLateralContact;
        GmVec3 m_lateralContactPoint;

        // Semantic host views of native wheel +0x130..+0x13C. The direction
        // is the contacted corpus's local +Z axis expressed in vehicle-local
        // space; the corpus remains a packed native 32-bit token.
        GmVec3 m_otherCorpusLocalDirection;
        uint32_t m_otherCorpusToken;

        // Semantic host view of the native force-application point at wheel
        // +0xA8. It remains separate because the surrounding 64-bit wheel
        // declaration does not claim the original outer-object layout.
        GmVec3 m_localContactPosition;

        SSimulationWheel();
    };

    // Native 0x7BD250 constructs a plain wheel record with no vtable. Keeping
    // this trivially copyable also makes CFastBuffer's native-style raw record
    // relocation valid on the standalone host.
    static_assert(std::is_trivially_copyable_v<SSimulationWheel>);

    // Native 0x7C1810 helper. The executable has two stack arguments: the
    // simulation wheel and an unused force-model scalar. The force application
    // point is the wheel's embedded native +0xA8 vector.
    void WheelAddForceToVehicle(
        SSimulationWheel* wheel, float unusedForceModelScalar);
    GmVec3 GetModel6WheelLateralDirection(
        const SSimulationWheel* wheel, float processedSteer) const;

    struct SVehicleCarState {
        virtual ~SVehicleCarState();
        uint8_t m_padding[124];
        uint32_t field_0x80;
        uint32_t field_0x84;
        uint32_t field_0x88;
        uint32_t field_0x8c;
        uint32_t field_0x90;
        uint32_t field_0x94;
        uint32_t field_0x98;
        uint32_t field_0x9c;
        uint32_t field_0xa0;
        uint32_t field_0xa4;
    };

    // Body of CSceneVehicleCar
    // CSceneVehicle ends at 0x74.
    uint8_t m_padding_car_body_pre[0x2E8 - 0x74];
    
    CFastBuffer<SSimulationWheel> m_wheels; // 0x2E8
    uint32_t m_simulationFlags;            // 0x2F4
    
    uint8_t m_padding_engine[0x59C - 0x2F8];
    SEngine m_engine;                      // 0x59C
    
    union {
        float m_engineForce;               // Legacy translated-code name.
        float m_smoothedSteer;             // 0x5E8 in the original executable.
    };
    float m_field_0x5ec;
    float m_field_0x5f0;
    float m_field_0x5f4;
    float m_field_0x5f8;
    float m_field_0x5fc;
    int m_field_0x600;
    
    uint8_t m_padding_final[0x840 - 0x604];
    float m_field_0x840;
    
    // VehicleFreeWheelingSet writes the original 32-bit field at +0x60C.
    // Keep it typed because the standalone build has a different 64-bit
    // object layout and must never address it through a raw byte offset.
    int m_freeWheeling;

    // Semantic orientation state for the standalone dynamics adapter. The
    // native CHmsDyna::GetLocalForce rotates world force into the car frame;
    // the harness currently represents yaw separately, so it supplies the
    // chassis up axis from its wheel contacts here.
    GmVec3 m_chassisUp;

    // Typed standalone counterparts of the native car flags at +0x6A0 and
    // +0x73C. When the former is enabled for a grounded wheel, the executable
    // reads the angular speed from its loaded vehicle-struct resource. The
    // standalone build retains that resolved scalar directly.
    int m_useGroundedWheelSpeedOverride;
    int m_wheelDriveDisabled;
    float m_groundedWheelAngularSpeedOverride;

    // Typed standalone counterparts of the engine-state fields consumed by
    // native EngineIntegrate. The burnout force state at +0x69C and the
    // transmission/RPM synchronizer state at +0x2E4 are deliberately
    // distinct; EngineIntegrate only reads +0x69C to select its +0x2E4 state
    // four. The remaining fields map +0x628, +0x70C, +0x744, and +0x748.
    // They are semantic host state, not claims about this 64-bit class's
    // enclosing object offsets.
    int m_engineState;          // native +0x69C burnout-force state
    int m_engineClutchBoost;
    int m_engineTakeoffMode;    // native +0x2E4 RPM/transmission state
    GmVec3 m_engineLocalVelocity;
    int m_engineOutsideTakeoffWindow;
    int m_engineShiftDirection;

    // Typed standalone counterparts of the friction/contact fields consumed
    // by ApplyFrictionForces at native +0x5DC, +0x5E0, and +0x5E4. The fixed
    // executable obtains the current millisecond tick from CMwTimerAdapter;
    // the standalone callback advances the equivalent deterministic clock.
    int m_hasBodyContact;
    uint32_t m_lastBodyContactTick;
    int m_hasWaterContact;
    uint32_t m_frictionCurrentTick;
    double m_frictionTickFraction;

    // Native Model6 lateral-over-limit transition ticks at
    // +0x62C/+0x630/+0x634. The preceding +0x628 flag is the shared
    // m_engineClutchBoost field above, matching the executable's reuse.
    uint32_t m_model6LastLateralOverLimitTick;
    uint32_t m_model6LateralOverLimitStartTick;
    uint32_t m_model6LateralOverLimitDuration;

    // Native air-control state at car +0x614..+0x620. The tick is the origin
    // ComputeAirControl measures its window from, and the vector retains the
    // local angular speed the car had while it still had contact.
    uint32_t m_airControlReferenceTick;
    GmVec3 m_airControlAngularSpeed;

    // Native Model6 timed engine-force phase origins at +0x6F4/+0x6F8.
    // State one consumes the first tick and transitions into state three,
    // which consumes the second tick.
    uint32_t m_model6EngineState1StartTick;
    uint32_t m_model6EngineState3StartTick;

    // Semantic host views of native contact state +0x5D4/+0x5D8 and the
    // impact/contact accumulators at +0x670..+0x698.
    int m_hasAnyContact;
    int m_hasChassisContact;
    uint8_t m_chassisContactMaterial;
    uint8_t m_wheelContactMaterial;
    float m_frontWheelImpact;
    float m_rearWheelImpact;
    float m_chassisImpact;
    uint32_t m_wheelContactCount;
    uint32_t m_chassisContactCount;
    uint32_t m_lastWheelContactCount;
    uint32_t m_lastChassisContactCount;
    GmVec3 m_chassisContactPointSum;
    GmVec3 m_chassisContactNormalSum;
    GmVec3 m_appliedImpulseSum;

    // Semantic host views of native car +0x1DC and +0x824..+0x82C.
    // The body box remains empty until vehicle geometry supplies it.
    GmBoxAligned m_localBodyBounds;
    GmVec3 m_appliedCentralImpulseSum;

    CSceneVehicleCar();
    virtual ~CSceneVehicleCar();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCSceneVehicleCar();
    
    uint32_t GetMwClassId();
    // Native 0x7BFFA0. This scans the simulation-wheel geometry and applies
    // the active vehicle tuning to the attached physical object.
    void UpdateParamsFromTuning();
    void* _vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2);
    
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
    
    void ComputeForces(CCallbackSceneToyBroomStickComputeForces* param_1, CHmsItem* param_2, float dt);
    void IntegrateVehicle(CSceneVehicleCar* pilot, float dt);
    // TmForeverFixed.exe 0x7BED10 ends in `ret 0x04`; the sole stack argument
    // is the local-space vehicle velocity acquired by ComputeForces.
    void ApplyFrictionForces(const GmVec3* localLinearSpeed);
    // TmForeverFixed.exe 0x7C2910 ends in `ret 0x04`; its sole argument is
    // the local force already accumulated for the current model pass.
    int ApplyWaterForces(const GmVec3* accumulatedLocalForce);
    // Native virtual at 0x7C3410 has one stack argument (`ret 0x04`).
    void AbsorbContact(CHmsPhysicalContact* contact) override;
    void AfterContacts();
    // Native helpers at 0x7BD040 (`ret 0x04`) and 0x7C11D0 (`ret 0x08`).
    uint32_t GetWheelFromSurfaceTree(uint32_t surfaceTreeToken) const;
    void WheelAbsorbContact(
        SSimulationWheel* wheel,
        CHmsPhysicalContact* contact);
    // Native 0x7BE390 has two stack arguments: a local impulse followed by
    // its local application point (`ret 0x08`).
    void AddVehicleImpulse(
        const GmVec3* localImpulse,
        const GmVec3* localPoint);
    // Native 0x7BE690 is the central one-vector impulse helper (`ret 0x04`).
    void AddVehicleCentralImpulse(const GmVec3* localImpulse);
    // Native 0x7C0EC0 ends in `ret 0x0C`: wheel, local vehicle speed along Z,
    // and timestep are its three stack arguments.
    void WheelUpdateSpeedFromVehicleSpeed(
        SSimulationWheel* wheel, float vehicleWheelSpeed, float dt);
    // Native 0x7BD1B0 initializes the suspension at AbsorbingValRest and
    // applies that displacement to the wheel collision subtree.
    void WheelReset(SSimulationWheel* wheel);
    // Native 0x7C0320 resets the complete live vehicle-physics state while
    // preserving loaded geometry and tuning.
    void VehicleReset();
    void WheelIntegrate(SSimulationWheel* wheel, float dt);
    // TmForeverFixed.exe 0x7BD700 ends in `ret 0x08`: input and timestep are
    // the only two stack arguments.
    void EngineIntegrate(float input, float dt);
    void VehicleFreeWheelingSet(int enabled);
    // TmForeverFixed.exe 0x7BF1D0, called from ComputeForces at 0x7C6F9F on
    // every step. `contactFlag` is the wheel-loop result at 0x7C6EF0.
    void ComputeAirControl(const GmVec3* localAngularSpeed,
                           uint32_t tick,
                           int grounded,
                           int contactFlag);

    void ComputeForcesModel3(CSceneVehicleCar* pilot, float dt);
    // TmForeverFixed.exe 0x7C3E80 ends in `ret 0x2c`. The fixed caller lays
    // down these eleven arguments in this order after removing Ghidra's
    // spurious leading CSceneVehicleCar* parameter.
    void ComputeForcesModel6(
        float dt,
        GmVec3* accumulatedLocalForce,
        float lateralSlopeAdherence,
        float axialSlopeAdherence,
        GmVec3* localLinearSpeed,
        GmVec3* localAngularSpeed,
        float processedSteer,
        int hasGroundMaterial,
        StadiumVehicleMaterials::GroundValues* groundMaterial,
        int* hasSlippingWheel,
        float* axialBrakeForce);
    // The reverse selector at 0x7C5A18..0x7C5B14, on ComputeForcesModel6's
    // common path between the burnout force state update and the axial force
    // branch. Nothing later in Model 6 reads the flag; IntegrateVehicle and
    // ApplyFrictionForces consume it on the following step.
    void UpdateReverseState(const GmVec3& localLinearSpeed);
    // The fixed executable's implementation at 0x7FA770 ends in `ret 0x2c`,
    // proving that there are eleven 32-bit stack arguments. Ghidra had added a
    // spurious leading CSceneVehicleCar* parameter to this signature.
    void ComputeForcesModel3_Exact(float param_2,GmVec3 *param_3, float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9, void *param_10,int *param_11,float *param_12);
    void ComputeVehicleGroundMaterialVals(
        StadiumVehicleMaterials::GroundValues* values,
        int* hasGroundContact) const;
    void GetSlopeAdherence(
        const GmVec3& force, float* lateralAdherence,
        float* axialAdherence) const;
    int IsGroundContact();
    // Native 0x7BF620 has material, direction-out, and corpus-out arguments
    // and ends in `ret 0x0C`.
    int IsGroundContactId(
        uint8_t materialId,
        GmVec3* otherCorpusLocalDirection,
        CHmsCorpus** otherCorpus) const;
};

#endif // CSCENEVEHICLECAR_HPP
