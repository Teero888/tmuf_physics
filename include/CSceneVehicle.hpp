#ifndef CSCENEVEHICLE_HPP
#define CSCENEVEHICLE_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CFuncKeysReal;
struct CHmsItem;
struct CMotionDayTime;
struct CMotionEmitterParticles;
struct CMwCmdBufferCore;
struct CMwNod;
struct CMwRefBuffer;
struct CMwStack;
struct CPlugFileSnd;
struct CPlugTreeVisualMip;
struct CPlugVisual;
struct CSceneMobil;
struct CSceneSoundSource;
struct CSceneToyCharacter;
struct CSceneVehicleGlider;
struct CSceneVehicleStruct;
struct CSystemFid;
struct GmMat3;
struct GmVec4;
struct GxLight;
struct SPlugFaceCull;

struct CSceneVehicle {
    struct SEnvironment {

        // Member Functions
        void __thiscall SEnvironment(void *this,SEnvironment *param_1);
        void __thiscall ~SEnvironment(void *this,SEnvironment *param_1);
    };

    struct SSurfaceHandler {

        // Member Functions
        void __thiscall Init (void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SSurfaceHandler(void *this,SSurfaceHandler *param_1);
        void __thiscall UpdateSurface(void *this,SSurfaceHandler *param_1);
    };

    struct SVehicleState {
        byte _padding_0x0[4];
        float field_0x4; // accesses: 3
        float field_0x8; // accesses: 3
        float field_0xc; // accesses: 3
        float field_0x10; // accesses: 3
        undefined4 field_0x14; // accesses: 2
        float field_0x18; // accesses: 3
        undefined4 field_0x1c; // accesses: 2
        float field_0x20; // accesses: 3
        float field_0x24; // accesses: 3
        float field_0x28; // accesses: 3
        float field_0x2c; // accesses: 3
        float field_0x30; // accesses: 3
        byte _padding_0x34[48];
        undefined4 field_0x64; // accesses: 2
        undefined4 field_0x68; // accesses: 2
        float field_0x6c; // accesses: 4
        float field_0x70; // accesses: 4
        float field_0x74; // accesses: 4
        float field_0x78; // accesses: 3
        float field_0x7c; // accesses: 3

        // Member Functions
        void __thiscall VehicleStateReset(void *this,SVehicleState *param_1);
        void __thiscall VehicleStateSet (void *this,SVehicleState *param_1,SVehicleState *param_2);
        void __thiscall VehicleStateSetBlend (void *this,SVehicleState *param_1,SVehicleState *param_2,SVehicleState *param_3, float param_4);
    };

    struct SVisualArm {

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SVisualArm(void *this,SVisualArm *param_1);
    };

    struct SVisualHandler {
        byte _padding_0x0[4];
        undefined4 field_0x4; // accesses: 1
        byte _padding_0x8[148];
        uint field_0x9c; // accesses: 3
        byte _padding_0xa0[4];
        void * field_0xa4; // accesses: 1

        // Member Functions
        int __thiscall IsInit(void *this,SVisualHandler *param_1);
        void __thiscall Init (void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SVisualHandler(void *this,SVisualHandler *param_1);
        void __thiscall UpdateVisual(void *this,SVisualHandler *param_1);
    };

    struct SVisualLight {

        // Member Functions
        void __thiscall SVisualLight(void *this,SVisualLight *param_1);
    };

    struct SVisualWheel {

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SVisualWheel(void *this,SVisualWheel *param_1);
    };

    byte _padding_0x0[4];
    int * field_0x4; // accesses: 11
    GmVec4 * field_0x8; // accesses: 21
    float field_0xc; // accesses: 3
    int field_0x10; // accesses: 4
    int field_0x14; // accesses: 7
    short field_0x16; // accesses: 1
    int field_0x18; // accesses: 14
    byte _padding_0x1c[4];
    undefined4 field_0x20; // accesses: 1
    CFuncKeysReal * field_0x24; // accesses: 5
    int field_0x28; // accesses: 12
    int field_0x2c; // accesses: 1
    SPlugFaceCull * field_0x30; // accesses: 26
    byte _padding_0x34[4];
    undefined4 field_0x38; // accesses: 3
    CMotionEmitterParticles * field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    int * field_0x48; // accesses: 20
    float field_0x4c; // accesses: 16
    int field_0x50; // accesses: 15
    float field_0x54; // accesses: 4
    int field_0x58; // accesses: 16
    int field_0x5c; // accesses: 10
    CMwNod * field_0x60; // accesses: 25
    CMwNod * field_0x64; // accesses: 24
    CMotionDayTime * field_0x68; // accesses: 23
    float field_0x6c; // accesses: 8
    int field_0x70; // accesses: 8
    int field_0x74; // accesses: 5
    int field_0x78; // accesses: 6
    int field_0x7c; // accesses: 7
    int field_0x80; // accesses: 3
    float field_0x84; // accesses: 3
    int field_0x88; // accesses: 3
    int field_0x8c; // accesses: 3
    CPlugVisual * field_0x90; // accesses: 6
    int field_0x94; // accesses: 6
    undefined4 field_0x98; // accesses: 5
    byte _padding_0x9c[4];
    code * field_0xa0; // accesses: 4
    CPlugTreeVisualMip * field_0xa4; // accesses: 5
    int field_0xa8; // accesses: 5
    undefined4 field_0xac; // accesses: 2
    int field_0xb0; // accesses: 3
    undefined4 field_0xb4; // accesses: 2
    int field_0xb8; // accesses: 4
    undefined4 field_0xbc; // accesses: 2
    undefined4 field_0xc0; // accesses: 2
    undefined4 field_0xc4; // accesses: 2
    undefined4 field_0xc8; // accesses: 2
    undefined4 field_0xcc; // accesses: 2
    float field_0xd0; // accesses: 2
    byte _padding_0xd4[132];
    float field_0x158; // accesses: 3
    float field_0x15c; // accesses: 2
    byte _padding_0x160[4];
    float field_0x164; // accesses: 2
    float field_0x168; // accesses: 1
    SVisualHandler * field_0x16c; // accesses: 1
    byte _padding_0x170[8];
    float field_0x178; // accesses: 1
    byte _padding_0x17c[120];
    float field_0x1f4; // accesses: 2
    int field_0x1f8; // accesses: 4
    uint field_0x1fc; // accesses: 2
    byte _padding_0x200[4];
    undefined4 field_0x204; // accesses: 2
    undefined4 field_0x208; // accesses: 2
    undefined4 field_0x20c; // accesses: 2
    int field_0x210; // accesses: 3
    byte _padding_0x214[40];
    undefined4 field_0x23c; // accesses: 1
    undefined4 field_0x240; // accesses: 1
    byte _padding_0x244[4];
    undefined4 field_0x248; // accesses: 3
    byte _padding_0x24c[20];
    int field_0x260; // accesses: 16
    int field_0x264; // accesses: 15
    int field_0x268; // accesses: 20
    int field_0x26c; // accesses: 16
    int field_0x270; // accesses: 18
    int field_0x274; // accesses: 16
    int field_0x278; // accesses: 18
    int field_0x27c; // accesses: 16
    int field_0x280; // accesses: 16
    int field_0x284; // accesses: 16
    int field_0x288; // accesses: 17
    int field_0x28c; // accesses: 7
    byte _padding_0x290[8];
    int field_0x298; // accesses: 7
    byte _padding_0x29c[8];
    int field_0x2a4; // accesses: 2
    int field_0x2a8; // accesses: 3
    byte _padding_0x2ac[36];
    CSceneVehicle * field_0x2d0; // accesses: 8
    undefined4 field_0x2d4; // accesses: 3
    CPlugBitmapRenderLightFromMap * field_0x2d8; // accesses: 12
    int field_0x2dc; // accesses: 4

    // Member Functions
    /* WARNING (jumptable): Unable to track spacebase fully for stack */ /* WARNING: Type propagation algorithm not settling */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CSceneVehicle::VisualUpdateAsync(CSceneVehicle *this,CSceneVehicle *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall VehicleStateComputeBlendVal(CSceneVehicle *this,CSceneVehicle *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall VehicleCurrentEnvironmentSet (CSceneVehicle *this,CSceneVehicle *param_1,int param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall VehicleHorn(CSceneVehicle *this,CSceneVehicle *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall VehicleUpdateAsync(CSceneVehicle *this,CSceneVehicleBall *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CSceneVehicle *this,CFuncSegment *param_1);
    CSceneMobil * __thiscall VehicleHelperNameGet(CSceneVehicle *this,CSceneVehicle *param_1);
    CSceneVehicleTuning * __thiscall GetVehicleTuning(CSceneVehicle *this,CSceneVehicle *param_1);
    GmVec3 * __thiscall WheelGetAsyncGroundContactPos (CSceneVehicle *this,CSceneVehicle *param_1,ulong param_2);
    float __thiscall VehicleInputSteerGet(CSceneVehicle *this,CSceneVehicleGlider *param_1);
    int __thiscall AllWheelsSliding(CSceneVehicle *this,CSceneVehicle *param_1);
    int __thiscall MwIsKindOf(CSceneVehicle *this,CMwCmdAffectParam *param_1,ulong param_2);
    int __thiscall UpdateEvent (CSceneVehicle *this,CSceneVehicle *param_1,EVehicleEvent param_2,ulong param_3);
    ulong __thiscall GetChunkInfo(CSceneVehicle *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CSceneVehicle *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex(CSceneVehicle *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall VirtualParam_Add (CSceneVehicle *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Get (CSceneVehicle *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    ulong __thiscall VirtualParam_Set (CSceneVehicle *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Sub (CSceneVehicle *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3);
    ushort __thiscall WheelGetContactMaterial(CSceneVehicle *this,CSceneVehicle *param_1,ulong param_2);
    void * __thiscall _scalar_deleting_destructor_(CSceneVehicle *this,CPfmHeap *param_1,uint param_2);
    void __thiscall AdjustSounds (CSceneVehicle *this,CSceneVehicle *param_1,float param_2,int param_3,int param_4, float param_5);
    void __thiscall BuildVehicleMaterialsRemap(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall CSceneVehicle(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall Chunk (CSceneVehicle *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall CreateDefaultData(CSceneVehicle *this,CCrystal *param_1);
    void __thiscall Hide(CSceneVehicle *this,CSceneToyMotorbike *param_1);
    void __thiscall InternalSoundRetrieve (CSceneVehicle *this,CSceneVehicle *param_1,CMwNodRef<class_CSceneSoundSource> *param_2, CMwId *param_3);
    void __thiscall OnEnterScene(CSceneVehicle *this,CSceneToyBroomstick *param_1);
    void __thiscall OnLeaveScene(CSceneVehicle *this,CSceneToyRock *param_1);
    void __thiscall OnNodLoaded(CSceneVehicle *this,CDx9DeviceCaps *param_1);
    void __thiscall ParticleQualitySet (CSceneVehicle *this,CSceneVehicle *param_1,ESceneVehicleParticleQuality param_2);
    void __thiscall PreloadResources(CSceneVehicle *this,CSceneVehicle *param_1,CHmsViewport *param_2);
    void __thiscall ReloadSoundsToApplyFidParams(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall RemoveEnvironments(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall ResetEnvironmentCacheTrees(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall RetrieveLoadedLinkedSounds(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall RetrieveSounds(CSceneVehicle *this,CSceneToyBoat *param_1);
    void __thiscall SetIsUpdateAsync(CSceneVehicle *this,CSceneVehicle *param_1,int param_2);
    void __thiscall SetQuality(CSceneVehicle *this,CPlugTreeVisualMip *param_1,ulong param_2);
    void __thiscall SetSolid(CSceneVehicle *this,CSceneToyMotorbike *param_1,CPlugSolid *param_2);
    void __thiscall Show(CSceneVehicle *this,CSceneToyMotorbike *param_1);
    void __thiscall SoundEnableSet(CSceneVehicle *this,CSceneVehicle *param_1,int param_2,ulong param_3);
    void __thiscall StartVehicleSounds(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall StopAllVehicleSounds(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall TuningsSet (CSceneVehicle *this,CSceneToyCharacter *param_1,CSceneToyCharacterTunings *param_2);
    void __thiscall VehicleAsyncWorldSpeedGet(CSceneVehicle *this,CSceneVehicle *param_1,GmVec3 *param_2);
    void __thiscall VehicleHelperNameSet(CSceneVehicle *this,CSceneVehicle *param_1,CSceneMobil *param_2);
    void __thiscall VehicleInitFromSolid(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall VehicleInputBrakeSet(CSceneVehicle *this,CSceneVehicleGlider *param_1,float param_2);
    void __thiscall VehicleInputGasSet(CSceneVehicle *this,CSceneVehicleGlider *param_1,float param_2);
    void __thiscall VehicleInputSteerSet(CSceneVehicle *this,CSceneVehicleGlider *param_1,float param_2);
    void __thiscall VehicleIsNetworkedSet(CSceneVehicle *this,CSceneVehicle *param_1,int param_2);
    void __thiscall VehicleReset(CSceneVehicle *this,CSceneVehicleBall *param_1);
    void __thiscall VisualEmittersInit(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall WaterSplash(CSceneVehicle *this,CSceneVehicle *param_1,GmVec3 *param_2);
    void __thiscall _vcall__372__flat______(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall _vcall__388__flat______(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall ~CSceneVehicle(CSceneVehicle *this,CSceneVehicle *param_1);
};

#endif // CSCENEVEHICLE_HPP
