#ifndef CSCENETOYBOAT_HPP
#define CSCENETOYBOAT_HPP

#include "typedefs.h"

struct CBoatParam;
struct CBoatSail;
struct CBoatSailState;
struct CMwId;
struct CMwNod;
struct CScene;
struct CSceneMobil;
struct CSceneSoundSource;
struct GmMat2;
struct GmVec3;

struct CSceneToyBoat {
    struct SSailManoeuvre {
        void** vftable; // accesses: 2
        int field_0x4; // accesses: 1

        // Member Functions
        CManoeuvre * __thiscall ManoeuvreGet(void *this,SSailManoeuvre *param_1);
    };

    void** vftable; // accesses: 4
    byte _padding_0x4[16];
    int field_0x14; // accesses: 2
    byte _padding_0x18[16];
    int field_0x28; // accesses: 4
    byte _padding_0x2c[64];
    float field_0x6c; // accesses: 1
    float field_0x70; // accesses: 1
    float field_0x74; // accesses: 1
    float field_0x78; // accesses: 1
    float field_0x7c; // accesses: 1
    float field_0x80; // accesses: 1
    CBoatParam * field_0x84; // accesses: 17
    undefined4 field_0x88; // accesses: 1
    float field_0x8c; // accesses: 1
    float field_0x90; // accesses: 2
    undefined4 field_0x94; // accesses: 16
    GmVec3 * field_0x98; // accesses: 12
    undefined4 field_0x9c; // accesses: 1
    float field_0xa0; // accesses: 1
    float field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    float field_0xac; // accesses: 1
    float field_0xb0; // accesses: 10
    float field_0xb4; // accesses: 2
    undefined4 field_0xb8; // accesses: 2
    float field_0xbc; // accesses: 3
    byte _padding_0xc0[12];
    float field_0xcc; // accesses: 4
    float field_0xd0; // accesses: 4
    float field_0xd4; // accesses: 4
    float field_0xd8; // accesses: 9
    CBoatParam * field_0xdc; // accesses: 16
    undefined4 field_0xe0; // accesses: 2
    byte _padding_0xe4[4];
    int field_0xe8; // accesses: 3
    uint field_0xec; // accesses: 3
    int field_0xf0; // accesses: 2
    byte _padding_0xf4[4];
    float field_0xf8; // accesses: 5
    float field_0xfc; // accesses: 1
    float field_0x100; // accesses: 1
    float field_0x104; // accesses: 1
    undefined4 field_0x108; // accesses: 1
    float field_0x10c; // accesses: 6
    float field_0x110; // accesses: 2
    float field_0x114; // accesses: 2
    float field_0x118; // accesses: 8
    float field_0x11c; // accesses: 3
    float field_0x120; // accesses: 1
    byte _padding_0x124[12];
    ESailType field_0x130; // accesses: 20
    CBoatSailState * field_0x134; // accesses: 8
    undefined4 field_0x138; // accesses: 3
    float field_0x13c; // accesses: 3
    byte _padding_0x140[36];
    int field_0x164; // accesses: 2
    float * field_0x168; // accesses: 4
    byte _padding_0x16c[28];
    float field_0x188; // accesses: 1
    byte _padding_0x18c[12];
    float field_0x198; // accesses: 4
    byte _padding_0x19c[16];
    uint field_0x1ac; // accesses: 8
    uint field_0x1b0; // accesses: 1
    byte _padding_0x1b4[20];
    undefined4 field_0x1c8; // accesses: 10
    float field_0x1cc; // accesses: 10
    byte _padding_0x1d0[48];
    undefined4 field_0x200; // accesses: 3
    byte _padding_0x204[336];
    int field_0x354; // accesses: 1
    int field_0x358; // accesses: 1
    int field_0x35c; // accesses: 2
    byte _padding_0x360[44];
    CMwNod * field_0x38c; // accesses: 9
    CMwNod * field_0x390; // accesses: 8
    CMwNod * field_0x394; // accesses: 8
    CMwNod * field_0x398; // accesses: 8
    CMwNod * field_0x39c; // accesses: 8
    CMwNod * field_0x3a0; // accesses: 7
    CMwNod * field_0x3a4; // accesses: 12
    CMwNod * field_0x3a8; // accesses: 10
    CMwNod * field_0x3ac; // accesses: 7
    CMwNod * field_0x3b0; // accesses: 10
    CMwNod * field_0x3b4; // accesses: 10
    CMwNod * field_0x3b8; // accesses: 9
    CMwNod * field_0x3bc; // accesses: 8
    CMwNod * field_0x3c0; // accesses: 8
    CMwNod * field_0x3c4; // accesses: 9
    CMwNod * field_0x3c8; // accesses: 11
    byte _padding_0x3cc[12];
    float field_0x3d8; // accesses: 4
    float field_0x3dc; // accesses: 4
    float field_0x3e0; // accesses: 4
    float field_0x3e4; // accesses: 2
    float field_0x3e8; // accesses: 2
    float field_0x3ec; // accesses: 2
    byte _padding_0x3f0[4];
    undefined4 field_0x3f4; // accesses: 1
    CMwNod * field_0x3f8; // accesses: 4
    float field_0x3fc; // accesses: 2
    undefined4 field_0x400; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall BSCoefSurfGet(CSceneToyBoat *this,CSceneToyBoat *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall RotationRadiusGet(CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall TillerAngleNormedGet(CSceneToyBoat *this,CSceneToyBoat *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall IsOnTheWind(CSceneToyBoat *this,CSceneToyBoat *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl SolveContact (GmVec3 *param_1,GmVec3 *param_2,GmVec3 *param_3,CSceneMobil *param_4,CSceneMobil *param_5 );
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall AbsorbContact (CSceneToyBoat *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall DeltaMoveGet (CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2,float *param_3,GmVec3 *param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Move(CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2,GmIso4 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall OldComputeOptimalSailAngles (CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateBoatPhysics (CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2,GmIso4 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateHeel(CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2,GmIso4 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateNavValues(CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2);
    /* WARNING: Variable defined which should be unmapped: param_1 */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateSounds(CSceneToyBoat *this,CSceneToyBoat *param_1);
    CBoatSailState * __thiscall SailStateGet(CSceneToyBoat *this,CSceneToyBoat *param_1,ESailType param_2);
    ESailType __thiscall SailTypeAfterManoeuvresGet(CSceneToyBoat *this,CSceneToyBoat *param_1);
    ESailType __thiscall SailTypeCurGet(CSceneToyBoat *this,CSceneToyBoat *param_1);
    ESailType __thiscall SailTypeNextGet(CSceneToyBoat *this,CSceneToyBoat *param_1);
    SSailManoeuvre __thiscall SailManoeuvreGet(CSceneToyBoat *this,CSceneToyBoat *param_1);
    float __thiscall BSCoefGamePlayGet(CSceneToyBoat *this,CSceneToyBoat *param_1);
    int __thiscall SailSwitchTo(CSceneToyBoat *this,CSceneToyBoat *param_1,ESailType param_2);
    void __thiscall ComputeForces (CSceneToyBoat *this,CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2, float param_3);
    void __thiscall GlobalIsAutomaticSheetSet(CSceneToyBoat *this,CSceneToyBoat *param_1,int param_2);
    void __thiscall GlobalIsFullEaseOutSet(CSceneToyBoat *this,CSceneToyBoat *param_1,int param_2);
    void __thiscall GlobalSheetTargetNormedAngleSet (CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2);
    void __thiscall RetrieveSounds(CSceneToyBoat *this,CSceneToyBoat *param_1);
    void __thiscall SailManoeuvreStop(CSceneToyBoat *this,CSceneToyBoat *param_1);
    void __thiscall SailManoeuvreUpdate(CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2);
    void __thiscall UpdateFromDynamicState (CSceneToyBoat *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong param_3, ulong param_4);
};

#endif // CSCENETOYBOAT_HPP
