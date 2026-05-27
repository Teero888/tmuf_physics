#ifndef CSCENEVEHICLE_HPP
#define CSCENEVEHICLE_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CHmsItem;
struct CMotionDayTime;
struct CMwNod;
struct CMwRefBuffer;
struct CMwStack;
struct CPlugTreeVisualMip;
struct CSceneMobil;
struct CSceneSoundSource;
struct CSceneToyCharacter;
struct CSceneVehicleGlider;
struct CSceneVehicleStruct;
struct GmMat3;

struct CSceneVehicle {
    struct CMwNod;

    struct SEnvironment {
        void** vftable; // accesses: 3

        // Member Functions
        void __thiscall SEnvironment(void *this,SEnvironment *param_1);
        void __thiscall ~SEnvironment(void *this,SEnvironment *param_1);
    };

    struct CPlugTree;

    struct SSurfaceHandler {
        void** vftable; // accesses: 5

        // Member Functions
        void __thiscall Init (void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SSurfaceHandler(void *this,SSurfaceHandler *param_1);
        void __thiscall UpdateSurface(void *this,SSurfaceHandler *param_1);
    };

    struct SVehicleState {
        void** vftable; // accesses: 3
        undefined4 field_0x4; // accesses: 3
        undefined4 field_0x8; // accesses: 3
        undefined4 field_0xc; // accesses: 3
        undefined4 field_0x10; // accesses: 3
        undefined4 field_0x14; // accesses: 3
        undefined4 field_0x18; // accesses: 3
        undefined4 field_0x1c; // accesses: 3
        undefined4 field_0x20; // accesses: 3
        undefined4 field_0x24; // accesses: 3
        undefined4 field_0x28; // accesses: 3
        undefined4 field_0x2c; // accesses: 3
        undefined4 field_0x30; // accesses: 3
        byte _padding_0x34[48];
        undefined4 field_0x64; // accesses: 3
        undefined4 field_0x68; // accesses: 3
        float field_0x6c; // accesses: 6
        float field_0x70; // accesses: 6
        float field_0x74; // accesses: 6
        undefined4 field_0x78; // accesses: 3
        undefined4 field_0x7c; // accesses: 3

        // Member Functions
        void __thiscall VehicleStateReset(void *this,SVehicleState *param_1);
        void __thiscall VehicleStateSet (void *this,SVehicleState *param_1,SVehicleState *param_2);
        void __thiscall VehicleStateSetBlend (void *this,SVehicleState *param_1,SVehicleState *param_2,SVehicleState *param_3, float param_4);
    };

    struct SVisualArm {
        void** vftable; // accesses: 1
        undefined4 field_0x4; // accesses: 1
        undefined4 field_0x8; // accesses: 1
        undefined4 field_0xc; // accesses: 1
        byte _padding_0x10[324];
        undefined4 field_0x154; // accesses: 1
        undefined4 field_0x158; // accesses: 1
        undefined4 field_0x15c; // accesses: 1
        undefined4 field_0x160; // accesses: 1
        undefined4 field_0x164; // accesses: 1
        undefined4 field_0x168; // accesses: 1
        undefined4 field_0x16c; // accesses: 1

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SVisualArm(void *this,SVisualArm *param_1);
    };

    struct CPlugTree;

    struct SVisualHandler {
        void** vftable; // accesses: 8
        int field_0x4; // accesses: 2
        byte _padding_0x8[96];
        undefined4 field_0x68; // accesses: 2

        // Member Functions
        int __thiscall IsInit(void *this,SVisualHandler *param_1);
        void __thiscall Init (void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SVisualHandler(void *this,SVisualHandler *param_1);
        void __thiscall UpdateVisual(void *this,SVisualHandler *param_1);
    };

    struct SVisualLight {
        void** vftable;

        // Member Functions
        void __thiscall SVisualLight(void *this,SVisualLight *param_1);
    };

    struct SVisualWheel {
        void** vftable; // accesses: 1

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SVisualWheel(void *this,SVisualWheel *param_1);
    };

    void** vftable; // accesses: 29
    byte _final_padding[0x8]; // Total size: 0xc

    // Member Functions
    /* WARNING (jumptable): Unable to track spacebase fully for stack */ void __thiscall CSceneVehicle::VisualUpdateAsync(CSceneVehicle *this,CSceneVehicle *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CSceneVehicle *this,CFuncSegment *param_1);
    CSceneMobil * __thiscall VehicleHelperNameGet(CSceneVehicle *this,CSceneVehicle *param_1);
    CSceneVehicleTuning * __thiscall GetVehicleTuning(CSceneVehicle *this,CSceneVehicle *param_1);
    GmVec3 * __thiscall WheelGetAsyncGroundContactPos (CSceneVehicle *this,CSceneVehicle *param_1,ulong param_2);
    float __thiscall VehicleInputSteerGet(CSceneVehicle *this,CSceneVehicleGlider *param_1);
    float __thiscall VehicleStateComputeBlendVal(CSceneVehicle *this,CSceneVehicle *param_1);
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
    void __thiscall VehicleCurrentEnvironmentSet (CSceneVehicle *this,CSceneVehicle *param_1,int param_2,float param_3);
    void __thiscall VehicleHelperNameSet(CSceneVehicle *this,CSceneVehicle *param_1,CSceneMobil *param_2);
    void __thiscall VehicleHorn(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall VehicleInitFromSolid(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall VehicleInputBrakeSet(CSceneVehicle *this,CSceneVehicleGlider *param_1,float param_2);
    void __thiscall VehicleInputGasSet(CSceneVehicle *this,CSceneVehicleGlider *param_1,float param_2);
    void __thiscall VehicleInputSteerSet(CSceneVehicle *this,CSceneVehicleGlider *param_1,float param_2);
    void __thiscall VehicleIsNetworkedSet(CSceneVehicle *this,CSceneVehicle *param_1,int param_2);
    void __thiscall VehicleReset(CSceneVehicle *this,CSceneVehicleBall *param_1);
    void __thiscall VehicleUpdateAsync(CSceneVehicle *this,CSceneVehicleBall *param_1);
    void __thiscall VisualEmittersInit(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall WaterSplash(CSceneVehicle *this,CSceneVehicle *param_1,GmVec3 *param_2);
    void __thiscall _vcall__372__flat______(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall _vcall__388__flat______(CSceneVehicle *this,CSceneVehicle *param_1);
    void __thiscall ~CSceneVehicle(CSceneVehicle *this,CSceneVehicle *param_1);
};

#endif // CSCENEVEHICLE_HPP
