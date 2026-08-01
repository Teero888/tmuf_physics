#ifndef CSCENEVEHICLECARTUNING_HPP
#define CSCENEVEHICLECARTUNING_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CFuncKeysReal;
class CFuncSegment;
class CClassicArchive;
class CDx9DeviceCaps;
struct CPfmHeap;

class CSceneVehicleCarTuning : public CMwNod {
public:
    CFastBuffer<void*> m_field_14; // Just use void* to avoid CMwNodRef include issues
    uint8_t m_padding_0x24[0x28 - 0x24];

    CFuncKeysReal* m_steerSlowDown;             // 0x28
    float m_steerSlowDownFactor;               // 0x2C
    float m_steerDriveTorqueFactor;            // 0x30
    CFuncKeysReal* m_steerDriveTorque;         // 0x34
    uint32_t m_field_38;
    CFuncKeysReal* m_steerRadius;              // 0x3C
    CFuncKeysReal* m_steerSlowDown2;           // 0x40
    
    uint8_t m_padding_mid[0x68 - 0x44];
    CFuncKeysReal* m_lateralContactSlowDown;   // 0x68
    
    uint8_t m_padding_mid2[0xAC - 0x6C];
    CFuncKeysReal* m_maxSideFriction;          // 0xAC

    uint8_t m_padding_end[0x3A8 - 0xB0];

    CSceneVehicleCarTuning();
    virtual ~CSceneVehicleCarTuning();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCSceneVehicleCarTuning();
    
    uint32_t GetMwClassId();
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
    
    float EvaluateCurve(struct CFuncKeysReal* curve, float x);

    float GetLateralContactSlowDownFromSpeed(float speed);
    float GetMaxSideFrictionFromSpeed(float speed);
    float GetAccelFromSpeed(float speed);
    float GetSteerDriveTorqueFromSpeed(float speed);
    float GetRolloverLateralCoefFromAngle(float angle);
    float GetRolloverLateralFromSpeed(float speed);
    float GetSteerSlowDownFromSpeed(float speed);
};

#endif // CSCENEVEHICLECARTUNING_HPP
