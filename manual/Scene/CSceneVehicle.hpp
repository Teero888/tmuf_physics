#ifndef CSCENEVEHICLE_HPP
#define CSCENEVEHICLE_HPP

#include "CSceneMobil.hpp"
#include "CFastArray.hpp"
#include "GmIso4.hpp"
#include "GmVec3.hpp"
#include <cstdint>

class CFuncSegment;
class CClassicArchive;
class CHmsItem;
class CPlugTree;
struct CPfmHeap;

class CSceneVehicle : public CSceneMobil {
public:
    struct SEnvironment {
        virtual ~SEnvironment();
    };

    struct SSurfaceHandler {
        CPlugTree* m_tree;
        GmIso4 m_baseLocation;
        GmIso4 m_surfaceLocation;

        SSurfaceHandler();
        void Init(CPlugTree* tree);
        void Reset();
        void UpdateSurface();
    };

    struct SVehicleState {
        virtual ~SVehicleState();
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xc;
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1c;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2c;
        uint32_t field_0x30;
        uint8_t m_padding[48];
        uint32_t field_0x64;
        uint32_t field_0x68;
        float field_0x6c;
        float field_0x70;
        float field_0x74;
        uint32_t field_0x78;
        uint32_t field_0x7c;
    };

    struct SVisualArm {
        virtual ~SVisualArm();
    };

    struct SVisualHandler {
        virtual ~SVisualHandler();
    };

    struct SVisualLight {
        virtual ~SVisualLight();
    };

    struct SVisualWheel {
        virtual ~SVisualWheel();
    };

    // Body of CSceneVehicle
    // CSceneMobil is at least 0x48.
    
    uint32_t m_field_48;       // 0x48
    uint8_t m_padding_4c[4];   // 0x4C
    float m_inputGas;          // 0x50
    float m_inputBrake;        // 0x54
    float m_inputSteer;        // 0x58
    uint32_t m_field_5c;       // 0x5C
    uint32_t m_field_60;       // 0x60
    uint32_t m_field_64;       // 0x64
    uint32_t m_field_68;       // 0x68
    CFastArray<void*> m_manoeuvres; // 0x6C

    // Semantic host views of native WaterSplash state (+0xB8 and
    // +0x204..+0x20C). They live outside the declared 32-bit vehicle body.
    uint32_t m_waterSplashCount;
    GmVec3 m_lastWaterSplashSpeed;

    CSceneVehicle();
    virtual ~CSceneVehicle();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCSceneVehicle();
    
    uint32_t GetMwClassId();
    void* _scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2);
    
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);

    void VehicleInputGasSet(float gas);
    void VehicleInputBrakeSet(float brake);
    void VehicleInputSteerSet(float steer);
    float VehicleInputSteerGet() const;
    // Native 0x7C97A0 has one vector argument (`ret 0x04`).
    void WaterSplash(const GmVec3* worldSpeed);
};

#endif // CSCENEVEHICLE_HPP
