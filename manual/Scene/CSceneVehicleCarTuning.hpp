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

    // Standalone semantic view of the Stadium tuning.  These members are not
    // intended to reproduce the original 32-bit object layout; translated
    // force code should use them instead of dereferencing guessed offsets.
    float m_mass;
    float m_inertiaMass;
    float m_inertiaHalfDiagX;
    float m_inertiaHalfDiagY;
    float m_inertiaHalfDiagZ;
    float m_gravityCoef;
    float m_gravityCoefAir;
    float m_angularFluidFrictionCoef1;
    float m_steerSpeed;
    int m_steerModel;
    float m_steerLowSpeed;
    float m_steerGroundTorque;
    float m_steerGroundTorqueSlippingCoef;
    float m_maxSideFrictionBlendCoef;
    float m_maxSideFrictionSliding;
    float m_sideFriction1;
    float m_maxSideFrictionOverLimitBlend;
    float m_m5AccelSlipCoefMax;
    int m_shockModel;
    float m_absorbingValKi;
    float m_absorbingValKa;
    float m_absorbingValRest;
    float m_absorbTension;
    float m_lateralSlopeAdherenceMin;
    float m_lateralSlopeAdherenceMax;
    float m_axialSlopeAdherenceMin;
    float m_axialSlopeAdherenceMax;

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
    float M5GetAccelFromSpeed(float speed);
    float M5GetSlippingAccelFromSpeed(float speed);
    float M5GetSteerSlowDownFromSpeed(float speed);
    float M6GetRearGearAccelFromSpeed(float speed);
    float GetModel6SteerSpeedFactor(float speed) const;
    float GetModel6SideForce(float rawForce, float maxForce) const;
    float GetYawInertia() const;
};

#endif // CSCENEVEHICLECARTUNING_HPP
