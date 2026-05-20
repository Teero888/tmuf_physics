#ifndef CSCENEVEHICLECAR_HPP
#define CSCENEVEHICLECAR_HPP

#include "typedefs.h"

struct CCallbackSceneVehicleBallAfterContacts;
struct CClassicArchive;
struct CHmsItem;
struct CMwNod;
struct CPlugShaderGeneric;
struct CSceneSoundSource;
struct CSceneVehicleCarTuning;
struct GmIso4;
struct GmVec3;
struct SVehicleCarState;
struct ulong;

struct CSceneVehicleCar {
    struct SDynaPart {
        byte _padding_0x0[28];
        undefined4 field_0x1c; // accesses: 1
        undefined4 field_0x20; // accesses: 1

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SDynaPart(void *this,SDynaPart *param_1);
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    struct SEngine {
        void** vftable; // accesses: 1
        undefined4 field_0x4; // accesses: 1
        undefined4 field_0x8; // accesses: 1
        undefined4 field_0xc; // accesses: 1
        undefined4 field_0x10; // accesses: 1
        undefined4 field_0x14; // accesses: 1
        undefined4 field_0x18; // accesses: 1
        undefined4 field_0x1c; // accesses: 1
        undefined4 field_0x20; // accesses: 1
        undefined4 field_0x24; // accesses: 1
        undefined4 field_0x28; // accesses: 1
        undefined4 field_0x2c; // accesses: 1

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SEngine(void *this,SEngine *param_1);
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    struct SSimulationWheel {
        struct SRealTimeState {
            byte _padding_0x0[108];
            float field_0x6c; // accesses: 1
            byte _padding_0x70[36];
            float field_0x94; // accesses: 6
            float field_0x98; // accesses: 6
            float field_0x9c; // accesses: 2
            float field_0xa0; // accesses: 7
            float field_0xa4; // accesses: 5

            // Member Functions
            /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Integrate (void *this,SRealTimeState *param_1,float param_2);
        };

        struct SState {
            void** vftable; // accesses: 2
            float field_0x4; // accesses: 2
            float field_0x8; // accesses: 2
            undefined2 field_0xc; // accesses: 2
            byte _padding_0xe[2];
            undefined4 field_0x10; // accesses: 2
            undefined4 field_0x14; // accesses: 3
            undefined4 field_0x18; // accesses: 1
            undefined4 field_0x1c; // accesses: 1
            undefined4 field_0x20; // accesses: 1
            undefined4 field_0x24; // accesses: 1
            undefined4 field_0x28; // accesses: 1
            undefined4 field_0x2c; // accesses: 1
            byte _padding_0x30[36];
            undefined4 field_0x54; // accesses: 1
            undefined4 field_0x58; // accesses: 1
            undefined4 field_0x5c; // accesses: 1
            undefined4 field_0x60; // accesses: 1

            // Member Functions
            /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetBlend (void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4);
            void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        };

        void** vftable; // accesses: 1
        undefined4 field_0x4; // accesses: 1
        undefined4 field_0x8; // accesses: 1
        byte _padding_0xc[148];
        undefined4 field_0xa0; // accesses: 1
        undefined4 field_0xa4; // accesses: 1
        undefined4 field_0xa8; // accesses: 1
        undefined4 field_0xac; // accesses: 1
        undefined4 field_0xb0; // accesses: 1

        // Member Functions
        void __thiscall SSimulationWheel(void *this,SSimulationWheel *param_1);
    };

    struct SVehicleCarState {
        byte _padding_0x0[128];
        float field_0x80; // accesses: 3
        undefined4 field_0x84; // accesses: 3
        undefined4 field_0x88; // accesses: 3
        undefined4 field_0x8c; // accesses: 3
        undefined4 field_0x90; // accesses: 3
        undefined4 field_0x94; // accesses: 3
        undefined4 field_0x98; // accesses: 3
        undefined4 field_0x9c; // accesses: 3
        undefined4 field_0xa0; // accesses: 3
        undefined4 field_0xa4; // accesses: 3

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
        void __thiscall SetBlend (void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4);
    };

    void** vftable; // accesses: 25
    float field_0x4; // accesses: 14
    float field_0x8; // accesses: 11
    float field_0xc; // accesses: 5
    byte _padding_0x10[24];
    CHmsItem * field_0x28; // accesses: 63
    byte _padding_0x2c[32];
    int field_0x4c; // accesses: 1
    float field_0x50; // accesses: 28
    float field_0x54; // accesses: 33
    float field_0x58; // accesses: 11
    float field_0x5c; // accesses: 1
    CMwNod * field_0x60; // accesses: 22
    CClassicArchive * field_0x64; // accesses: 179
    CSceneVehicleCar * field_0x68; // accesses: 8
    float field_0x6c; // accesses: 3
    byte _padding_0x70[8];
    int field_0x78; // accesses: 7
    int field_0x7c; // accesses: 1
    byte _padding_0x80[48];
    undefined4 field_0xb0; // accesses: 3
    float field_0xb4; // accesses: 2
    undefined4 field_0xb8; // accesses: 5
    CSceneVehicleCar * field_0xbc; // accesses: 6
    float field_0xc0; // accesses: 3
    ulong field_0xc4; // accesses: 3
    byte _padding_0xc8[64];
    undefined4 field_0x108; // accesses: 1
    undefined4 field_0x10c; // accesses: 1
    undefined4 field_0x110; // accesses: 1
    undefined4 field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 1
    float field_0x120; // accesses: 3
    int field_0x124; // accesses: 5
    undefined2 field_0x128; // accesses: 2
    byte _padding_0x12a[2];
    undefined4 field_0x12c; // accesses: 1
    float field_0x130; // accesses: 1
    float field_0x134; // accesses: 1
    CSceneVehicleCar * field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 3
    float field_0x144; // accesses: 3
    float field_0x148; // accesses: 3
    float field_0x14c; // accesses: 3
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    undefined4 field_0x15c; // accesses: 2
    undefined4 field_0x160; // accesses: 2
    undefined4 field_0x164; // accesses: 2
    undefined4 field_0x168; // accesses: 2
    byte _padding_0x16c[112];
    float field_0x1dc; // accesses: 2
    float field_0x1e0; // accesses: 2
    float field_0x1e4; // accesses: 2
    float field_0x1e8; // accesses: 3
    float field_0x1ec; // accesses: 2
    float field_0x1f0; // accesses: 2
    undefined4 field_0x1f4; // accesses: 2
    byte _padding_0x1f8[4];
    undefined4 field_0x1fc; // accesses: 12
    byte _padding_0x200[16];
    undefined4 field_0x210; // accesses: 1
    undefined4 field_0x214; // accesses: 1
    undefined4 field_0x218; // accesses: 1
    float field_0x21c; // accesses: 3
    byte _padding_0x220[4];
    float field_0x224; // accesses: 2
    undefined4 field_0x228; // accesses: 1
    undefined4 field_0x22c; // accesses: 1
    float field_0x230; // accesses: 3
    byte _padding_0x234[4];
    float field_0x238; // accesses: 2
    float field_0x23c; // accesses: 3
    float field_0x240; // accesses: 3
    float field_0x244; // accesses: 7
    byte _padding_0x248[4];
    float field_0x24c; // accesses: 7
    float field_0x250; // accesses: 5
    byte _padding_0x254[16];
    int field_0x264; // accesses: 8
    int field_0x268; // accesses: 2
    CSceneSoundSource * field_0x26c; // accesses: 2
    int field_0x270; // accesses: 7
    int * field_0x274; // accesses: 4
    int field_0x278; // accesses: 4
    CSceneSoundSource * field_0x27c; // accesses: 3
    CSceneSoundSource * field_0x280; // accesses: 2
    CSceneSoundSource * field_0x284; // accesses: 2
    int field_0x288; // accesses: 3
    byte _padding_0x28c[72];
    CPlugShaderGeneric * field_0x2d4; // accesses: 2
    byte _padding_0x2d8[8];
    float field_0x2e0; // accesses: 4
    undefined4 field_0x2e4; // accesses: 22
    byte _padding_0x2e8[12];
    uint field_0x2f4; // accesses: 8
    byte _padding_0x2f8[100];
    undefined4 field_0x35c; // accesses: 5
    undefined4 field_0x360; // accesses: 7
    undefined4 field_0x364; // accesses: 3
    undefined4 field_0x368; // accesses: 3
    undefined4 field_0x36c; // accesses: 3
    byte _padding_0x370[8];
    float field_0x378; // accesses: 4
    byte _padding_0x37c[36];
    float field_0x3a0; // accesses: 3
    float field_0x3a4; // accesses: 1
    undefined4 field_0x3a8; // accesses: 1
    undefined4 field_0x3ac; // accesses: 1
    undefined4 field_0x3b0; // accesses: 1
    uint field_0x3b4; // accesses: 1
    undefined4 field_0x3b8; // accesses: 1
    undefined4 field_0x3bc; // accesses: 1
    undefined4 field_0x3c0; // accesses: 1
    undefined4 field_0x3c4; // accesses: 1
    undefined4 field_0x3c8; // accesses: 1
    undefined4 field_0x3cc; // accesses: 1
    undefined4 field_0x3d0; // accesses: 1
    byte _padding_0x3d4[4];
    float field_0x3d8; // accesses: 2
    float field_0x3dc; // accesses: 2
    float field_0x3e0; // accesses: 2
    float field_0x3e4; // accesses: 2
    float field_0x3e8; // accesses: 2
    float field_0x3ec; // accesses: 2
    float field_0x3f0; // accesses: 2
    float field_0x3f4; // accesses: 2
    float field_0x3f8; // accesses: 1
    float field_0x3fc; // accesses: 1
    float field_0x400; // accesses: 1
    undefined4 field_0x404; // accesses: 2
    undefined4 field_0x408; // accesses: 2
    float field_0x40c; // accesses: 2
    float field_0x410; // accesses: 2
    float field_0x414; // accesses: 2
    float field_0x418; // accesses: 1
    byte _padding_0x41c[4];
    undefined4 field_0x420; // accesses: 1
    undefined4 field_0x424; // accesses: 1
    undefined4 field_0x428; // accesses: 1
    undefined4 field_0x42c; // accesses: 1
    uint field_0x430; // accesses: 1
    undefined4 field_0x434; // accesses: 2
    float field_0x438; // accesses: 2
    uint field_0x43c; // accesses: 1
    float field_0x440; // accesses: 2
    undefined4 field_0x444; // accesses: 1
    float field_0x448; // accesses: 1
    byte _padding_0x44c[16];
    int field_0x45c; // accesses: 1
    GmIso4 * field_0x460; // accesses: 1
    byte _padding_0x464[80];
    undefined4 field_0x4b4; // accesses: 1
    undefined4 field_0x4b8; // accesses: 1
    undefined4 field_0x4bc; // accesses: 1
    byte _padding_0x4c0[220];
    SVehicleCarState * field_0x59c; // accesses: 12
    undefined4 field_0x5a0; // accesses: 1
    undefined4 field_0x5a4; // accesses: 1
    float field_0x5a8; // accesses: 2
    float field_0x5ac; // accesses: 2
    float field_0x5b0; // accesses: 2
    float field_0x5b4; // accesses: 34
    float field_0x5b8; // accesses: 14
    float field_0x5bc; // accesses: 8
    float field_0x5c0; // accesses: 16
    undefined4 field_0x5c4; // accesses: 29
    undefined4 field_0x5c8; // accesses: 15
    float field_0x5cc; // accesses: 7
    int field_0x5d0; // accesses: 1
    undefined4 field_0x5d4; // accesses: 7
    undefined4 field_0x5d8; // accesses: 4
    undefined4 field_0x5dc; // accesses: 6
    int field_0x5e0; // accesses: 4
    undefined4 field_0x5e4; // accesses: 14
    float field_0x5e8; // accesses: 18
    byte _padding_0x5ec[4];
    float field_0x5f0; // accesses: 4
    float field_0x5f4; // accesses: 10
    CSceneVehicleCar * field_0x5f8; // accesses: 3
    CSceneVehicleCar * field_0x5fc; // accesses: 3
    float field_0x600; // accesses: 17
    undefined4 field_0x604; // accesses: 3
    float field_0x608; // accesses: 2
    CSceneVehicleCar * field_0x60c; // accesses: 29
    CSceneVehicleCar * field_0x610; // accesses: 3
    undefined4 field_0x614; // accesses: 3
    float field_0x618; // accesses: 6
    float field_0x61c; // accesses: 9
    undefined4 field_0x620; // accesses: 3
    float field_0x624; // accesses: 5
    float field_0x628; // accesses: 9
    undefined4 field_0x62c; // accesses: 3
    int field_0x630; // accesses: 4
    int field_0x634; // accesses: 2
    float field_0x638; // accesses: 10
    float field_0x63c; // accesses: 3
    undefined4 field_0x640; // accesses: 8
    undefined4 field_0x644; // accesses: 1
    undefined4 field_0x648; // accesses: 3
    float field_0x64c; // accesses: 2
    ulong field_0x650; // accesses: 6
    undefined4 field_0x654; // accesses: 12
    uint field_0x658; // accesses: 12
    undefined4 field_0x65c; // accesses: 3
    int field_0x660; // accesses: 5
    int field_0x664; // accesses: 5
    int field_0x668; // accesses: 5
    byte _padding_0x66c[4];
    float field_0x670; // accesses: 6
    float field_0x674; // accesses: 6
    float field_0x678; // accesses: 6
    undefined4 field_0x67c; // accesses: 5
    undefined4 field_0x680; // accesses: 7
    float field_0x684; // accesses: 6
    float field_0x688; // accesses: 6
    float field_0x68c; // accesses: 6
    float field_0x690; // accesses: 12
    float field_0x694; // accesses: 12
    float field_0x698; // accesses: 11
    undefined4 field_0x69c; // accesses: 30
    undefined4 field_0x6a0; // accesses: 8
    byte _padding_0x6a4[16];
    float field_0x6b4; // accesses: 1
    byte _padding_0x6b8[28];
    float field_0x6d4; // accesses: 2
    float field_0x6d8; // accesses: 4
    float field_0x6dc; // accesses: 4
    float field_0x6e0; // accesses: 3
    float field_0x6e4; // accesses: 3
    float field_0x6e8; // accesses: 3
    float field_0x6ec; // accesses: 4
    float field_0x6f0; // accesses: 2
    int field_0x6f4; // accesses: 5
    float field_0x6f8; // accesses: 5
    undefined4 field_0x6fc; // accesses: 1
    float field_0x700; // accesses: 13
    float field_0x704; // accesses: 11
    float field_0x708; // accesses: 1
    undefined4 field_0x70c; // accesses: 3
    ulong field_0x710; // accesses: 3
    float field_0x714; // accesses: 14
    undefined4 field_0x718; // accesses: 2
    undefined4 field_0x71c; // accesses: 2
    undefined4 field_0x720; // accesses: 2
    undefined4 field_0x724; // accesses: 2
    undefined4 field_0x728; // accesses: 2
    undefined4 field_0x72c; // accesses: 1
    undefined4 field_0x730; // accesses: 2
    undefined4 field_0x734; // accesses: 2
    undefined4 field_0x738; // accesses: 2
    undefined4 field_0x73c; // accesses: 3
    undefined4 field_0x740; // accesses: 1
    undefined4 field_0x744; // accesses: 12
    undefined4 field_0x748; // accesses: 5
    undefined4 field_0x74c; // accesses: 2
    byte _padding_0x750[192];
    undefined4 field_0x810; // accesses: 2
    undefined4 field_0x814; // accesses: 1
    float field_0x818; // accesses: 6
    CSceneVehicleCar * field_0x81c; // accesses: 7
    float field_0x820; // accesses: 7
    float field_0x824; // accesses: 5
    float field_0x828; // accesses: 5
    float field_0x82c; // accesses: 5
    byte _padding_0x830[4];
    undefined4 field_0x834; // accesses: 4
    undefined4 field_0x838; // accesses: 5
    undefined4 field_0x83c; // accesses: 5
    float field_0x840; // accesses: 8
    undefined4 field_0x844; // accesses: 2
    undefined4 field_0x848; // accesses: 1
    undefined4 field_0x84c; // accesses: 1
    undefined4 field_0x850; // accesses: 1
    undefined4 field_0x854; // accesses: 1
    undefined4 field_0x858; // accesses: 1
    undefined4 field_0x85c; // accesses: 1
    undefined4 field_0x860; // accesses: 1
    undefined4 field_0x864; // accesses: 1
    undefined4 field_0x868; // accesses: 1
    undefined4 field_0x86c; // accesses: 2
    undefined4 field_0x870; // accesses: 2
    undefined4 field_0x874; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __cdecl GetRouletteBoostFactorFromValue01(float param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __cdecl GetRouletteValue01(ulong param_1,ulong param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall GetMaxSpeed(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall ApplyWaterForces(CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall VirtualParam_Get (CSceneVehicleCar *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall VirtualParam_Set (CSceneVehicleCar *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall AbsorbContact (CSceneVehicleCar *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall AfterContacts (CSceneVehicleCar *this,CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ApplyFrictionForces (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CSceneVehicleCar(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeAirControl (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2,ulong param_3, int param_4,int param_5);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeAsyncState(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeForces (CSceneVehicleCar *this,CCallbackSceneToyBroomStickComputeForces *param_1, CHmsItem *param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeForcesModel3 (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3, float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9, SBlendableVals *param_10,int *param_11,float *param_12);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeForcesModel4 (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3, float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9, SBlendableVals *param_10,int *param_11,float *param_12);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeForcesModel5 (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3, float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9, SBlendableVals *param_10,int *param_11,float *param_12);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeForcesModel6 (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3, float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9, SBlendableVals *param_10,int *param_11,float *param_12);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeVehicleGroundMaterialVals (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SBlendableVals *param_2,int *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CreateFakeContacts(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall EngineIntegrate (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetLateralFriction (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2,GmVec3 *param_3, SBlendableVals *param_4,float param_5,int param_6,float *param_7,int *param_8);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetSlopeAdherence (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2,float *param_3, float *param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall IntegrateVehicle(CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall OnEnterScene(CSceneVehicleCar *this,CSceneToyBroomstick *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RestoreStaticState (CSceneVehicleCar *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,int param_3, ulong param_4,ulong param_5,int param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateParamsFromTuning(CSceneVehicleCar *this,CSceneToyCharacter *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateTurbo(CSceneVehicleCar *this,CSceneVehicleCar *param_1,ulong param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall VehicleUpdateAsync(CSceneVehicleCar *this,CSceneVehicleBall *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall WheelAbsorbContact (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2, CHmsPhysicalContact *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall WheelAddForceToVehicle (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2, GmVec3 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall WheelIntegrate (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall WheelReset (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall WheelUpdateSpeedFromVehicleSpeed (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2,float param_3, float param_4);
    CMwClassInfo * __thiscall MwGetClassInfo(CSceneVehicleCar *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCSceneVehicleCar(void);
    GmVec3 * __thiscall WheelGetAsyncGroundContactPos (CSceneVehicleCar *this,CSceneVehicle *param_1,ulong param_2);
    SVehicleState * __thiscall VehicleStateAsyncGet(CSceneVehicleCar *this,CSceneVehicleBall *param_1);
    SVehicleState * __thiscall VehicleStatePrevAsyncGet(CSceneVehicleCar *this,CSceneVehicleBall *param_1);
    float __thiscall GetRouletteCurrentBoostFactor(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    int __thiscall HasSavedStateChanged(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    int __thiscall IsAllWheelGroundContactId (CSceneVehicleCar *this,CSceneVehicleCar *param_1,uchar param_2);
    int __thiscall IsGroundContact(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    int __thiscall IsGroundContactId (CSceneVehicleCar *this,CSceneVehicleCar *param_1,uchar param_2,GmVec3 *param_3, ulong *param_4);
    int __thiscall IsRubberBall(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    int __thiscall MwIsKindOf(CSceneVehicleCar *this,CMwCmdAffectParam *param_1,ulong param_2);
    int __thiscall WheelIsSliding(CSceneVehicleCar *this,CSceneVehicleCar *param_1,ulong param_2);
    ulong __thiscall GetChunkInfo(CSceneVehicleCar *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CSceneVehicleCar *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex (CSceneVehicleCar *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall GetWheelFromSurfaceTree (CSceneVehicleCar *this,CSceneVehicleCar *param_1,CPlugTree *param_2);
    ulong __thiscall WheelGetCount(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    ushort __thiscall WheelGetContactMaterial (CSceneVehicleCar *this,CSceneVehicle *param_1,ulong param_2);
    void * __thiscall _vector_deleting_destructor_ (CSceneVehicleCar *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall AddStateForPrediction (CSceneVehicleCar *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong param_3 ,ulong param_4);
    void __thiscall AddVehicleCentralForce (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2);
    void __thiscall AddVehicleForce (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2,GmVec3 *param_3);
    void __thiscall AddVehicleImpulse (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2);
    void __thiscall AddVehicleTorque(CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2);
    void __thiscall Chunk (CSceneVehicleCar *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall CreateDefaultData(CSceneVehicleCar *this,CCrystal *param_1);
    void __thiscall CreateOldStruct(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    void __thiscall EnableTurbo (CSceneVehicleCar *this,CSceneVehicleCar *param_1,ulong param_2,ulong param_3, float param_4,ETurboType param_5,ulong param_6);
    void __thiscall NewSolidInstance(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
    void __thiscall OnNodLoaded(CSceneVehicleCar *this,CDx9DeviceCaps *param_1);
    void __thiscall SaveState (CSceneVehicleCar *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2, ulong *param_3,ulong param_4);
    void __thiscall SetVehicleAngularSpeed (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2);
    void __thiscall SetVehicleLinearSpeed (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2);
    void __thiscall VehicleAsyncWorldSpeedGet (CSceneVehicleCar *this,CSceneVehicle *param_1,GmVec3 *param_2);
    void __thiscall VehicleBlockSpeed2Set(CSceneVehicleCar *this,CSceneMobil *param_1,int param_2);
    void __thiscall VehicleBlockSpeedSet(CSceneVehicleCar *this,CSceneVehicleCar *param_1,int param_2);
    void __thiscall VehicleFreeWheelingSet (CSceneVehicleCar *this,CSceneVehicleCar *param_1,int param_2);
    void __thiscall VehicleInitFromSolid(CSceneVehicleCar *this,CSceneVehicle *param_1);
    void __thiscall VehicleReset(CSceneVehicleCar *this,CSceneVehicleBall *param_1);
    void __thiscall ~CSceneVehicleCar(CSceneVehicleCar *this,CSceneVehicleCar *param_1);
};

#endif // CSCENEVEHICLECAR_HPP
