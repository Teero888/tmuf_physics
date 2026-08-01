#ifndef CSCENEVEHICLECAR_HPP
#define CSCENEVEHICLECAR_HPP

#include "CSceneVehicle.hpp"
#include "GmVec3.hpp"
#include "GmIso4.hpp"
#include "GmMat3.hpp"
#include "CFastBuffer.hpp"
#include <cstdint>

class CHmsItem;
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

    void WheelAddForceToVehicle(CSceneVehicleCar *param_1, void *param_2, void *param_3, void *param_4);
    void AddVehicleTorque(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3);
    void AddVehicleCentralForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3);
    void AddVehicleForce(CSceneVehicleCar *param_1, CSceneVehicleCar *param_2, GmVec3 *param_3, GmVec3 *param_4);

    struct SDynaPart {
        virtual ~SDynaPart();
        uint8_t m_padding[24];
        uint32_t field_0x1c;
        uint32_t field_0x20;
    };

    struct SEngine {
        float m_throttle;           // 0x00 (+0x59C)
        float m_field_0x04;         // 0x04
        float m_field_0x08;         // 0x08
        float m_field_0x0c;         // 0x0C
        float m_field_0x10;         // 0x10
        float m_engineRpm;          // 0x18 (+0x5B4)
        float m_clutchRpm;          // 0x1C (+0x5B8)
        float m_clutchRatio;        // 0x20 (+0x5BC)
        float m_gearShiftTimer;     // 0x24 (+0x5C0)
        int m_field_0x28;           // 0x28 (+0x5C4)
        int m_currentGear;          // 0x2C (+0x5C8)
        float m_field_0x30;

        virtual ~SEngine();
        void Reset();
    };

    struct SSimulationWheel {

        struct SRealTimeState {
            virtual ~SRealTimeState();
            float m_compression;         // 0x00 (Wheel + 0xB4)
            float m_velocity;            // 0x04 (Wheel + 0xB8)
            uint8_t m_padding[104];
            float m_angularVelocity;     // 0x6C (Wheel + 0x120)
            uint8_t m_padding2[36];
            float m_axisX;               // 0x94
            float m_axisY;               // 0x98
            float m_rotationAngle;       // 0x9C (Wheel + 0x150)
            float m_field_0xa0;
            float m_field_0xa4;
            
            void Integrate(float dt);
        };

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
        uint32_t m_field_0x04;        // 0x04
        float m_radius;               // 0x08
        SSurfaceHandler m_surfaceHandler; // 0x0C
        
        uint8_t m_padding_mid[0x124 - 0x10]; 
        int m_hasGroundContact;      // 0x124
        uint16_t m_groundMaterial;   // 0x128
        uint8_t m_padding_end[0x158 - 0x12A];
        
        SRealTimeState m_realTimeState; 
        
        float m_suspensionForce;        // 0x158
        float m_field_0x15c;

        virtual ~SSimulationWheel();
    };

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
    
    float m_engineForce;                   // 0x5E8
    float m_field_0x5ec;
    float m_field_0x5f0;
    float m_field_0x5f4;
    float m_field_0x5f8;
    float m_field_0x5fc;
    int m_field_0x600;
    
    uint8_t m_padding_final[0x840 - 0x604];
    float m_field_0x840;
    
    CSceneVehicleCar* m_pilotCar;          // 0x60C

    CSceneVehicleCar();
    virtual ~CSceneVehicleCar();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCSceneVehicleCar();
    
    uint32_t GetMwClassId();
    void* _vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2);
    
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
    
    void ComputeForces(CCallbackSceneToyBroomStickComputeForces* param_1, CHmsItem* param_2, float dt);
    void IntegrateVehicle(CSceneVehicleCar* pilot, float dt);
    void ApplyFrictionForces(CSceneVehicleCar* pilot, float dt);
    void WheelUpdateSpeedFromVehicleSpeed(SSimulationWheel* wheel, CSceneVehicleCar* pilot, float dt, float param_3);
    void WheelIntegrate(SSimulationWheel* wheel, float dt);
    void EngineIntegrate(CSceneVehicleCar* pilot, float dt, float param_2);
    void ComputeForcesModel3(CSceneVehicleCar* pilot, float dt);
    void ComputeForcesModel3_Exact(CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3, float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9, void *param_10,int *param_11,float *param_12);
    int IsGroundContact();
};

#endif // CSCENEVEHICLECAR_HPP
