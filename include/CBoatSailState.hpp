#ifndef CBOATSAILSTATE_HPP
#define CBOATSAILSTATE_HPP

#include "typedefs.h"

struct CBoatSail;
struct CMwId;
struct CPlugTree;
struct CPlugVisual;

struct CBoatSailState {
    void** vftable;
    byte _padding_0x4[16];
    CBoatSail * field_0x14; // accesses: 43
    int * field_0x18; // accesses: 11
    CPlugTree * field_0x1c; // accesses: 4
    CPlugTree * field_0x20; // accesses: 4
    int * field_0x24; // accesses: 22
    int * field_0x28; // accesses: 13
    int * field_0x2c; // accesses: 2
    int field_0x30; // accesses: 1
    int field_0x34; // accesses: 1
    byte _padding_0x38[52];
    float field_0x6c; // accesses: 1
    int field_0x70; // accesses: 1
    float field_0x74; // accesses: 1
    int field_0x78; // accesses: 1
    CBoatSail * field_0x7c; // accesses: 2
    float field_0x80; // accesses: 8
    CMwId * field_0x84; // accesses: 10
    float field_0x88; // accesses: 3
    undefined4 field_0x8c; // accesses: 3
    float field_0x90; // accesses: 4
    byte _padding_0x94[4];
    undefined4 field_0x98; // accesses: 4
    CBoatSailState * field_0x9c; // accesses: 2
    float field_0xa0; // accesses: 1
    float field_0xa4; // accesses: 8
    CPlugVisual * field_0xa8; // accesses: 8
    float field_0xac; // accesses: 10

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall BSCoefSailTuningGet (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall OldHeelCoefGet (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SheetTargetNormedAngleSet (CBoatSailState *this,CBoatSailState *param_1,int param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateGeometrySpi (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateGeometrySpiAsym (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateHaulDownFrontSail (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateHaulDownSpi (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateHaulUpFrontSail (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateHaulUpSpi (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateRotationAsync (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateSailPhysics (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4, float param_5);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateShiverAndBulgeAsync (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4, float param_5);
    float __thiscall HeelGet (CBoatSailState *this,CBoatSail *param_1,float param_2,float param_3,float param_4, CMwId *param_5,float param_6);
    float __thiscall OptimalSailAngleGet (CBoatSailState *this,CBoatSail *param_1,float param_2,float param_3,CMwId *param_4);
    void __thiscall ShowVisibleTrees (CBoatSailState *this,CBoatSailState *param_1,int param_2,int param_3);
    void __thiscall UpdateAsync(CBoatSailState *this,CInputPortDx8 *param_1);
    void __thiscall UpdateGeometryFrontSail (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3);
    void __thiscall UpdateGeometryMainSail (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3);
};

#endif // CBOATSAILSTATE_HPP
