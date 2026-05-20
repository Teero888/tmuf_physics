#ifndef CBOATSAIL_HPP
#define CBOATSAIL_HPP

#include "typedefs.h"

struct CFuncCurves2Real;
struct CFuncCurvesReal;
struct CFuncKeysReal;

struct CBoatSail {
    void** vftable;
    byte _padding_0x4[16];
    int field_0x14; // accesses: 5
    int field_0x18; // accesses: 1
    CFuncCurvesReal * field_0x1c; // accesses: 3
    byte _padding_0x20[24];
    CFuncCurvesReal * field_0x38; // accesses: 1
    CFuncCurvesReal * field_0x3c; // accesses: 1
    CFuncCurvesReal * field_0x40; // accesses: 1
    CFuncCurvesReal * field_0x44; // accesses: 1
    CFuncKeysReal * field_0x48; // accesses: 2
    CFuncCurvesReal * field_0x4c; // accesses: 2
    byte _padding_0x50[4];
    CFuncCurves2Real * field_0x54; // accesses: 2
    CFuncKeysReal * field_0x58; // accesses: 2
    float field_0x5c; // accesses: 1
    float field_0x60; // accesses: 2
    byte _padding_0x64[64];
    float field_0xa4; // accesses: 1
    byte _padding_0xa8[4];
    float field_0xac; // accesses: 2
    byte _final_padding[0x24]; // Total size: 0xd4

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall AccelerationGet(CBoatSail *this,CBoatSail *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall BSGet(CBoatSail *this,CBoatSail *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall BestVmgAngleGet(CBoatSail *this,CBoatSail *param_1,float param_2,int param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall BoomAngleGet(CBoatSail *this,CBoatSail *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall HeelGet(CBoatSail *this,CBoatSail *param_1,float param_2,float param_3,float param_4, CMwId *param_5,float param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall LuffAngleSpeedGet (CBoatSail *this,CBoatSail *param_1,float param_2,float param_3,float param_4, CMwId *param_5,float param_6,float param_7);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall OptimalSailAngleGet (CBoatSail *this,CBoatSail *param_1,float param_2,float param_3,CMwId *param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall RevolveAngleSpeedGet(CBoatSail *this,CBoatSail *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall ShiverAngleGet(CBoatSail *this,CBoatSail *param_1,float param_2);
    float __thiscall SheetAngleMaxGet(CBoatSail *this,CBoatSail *param_1,float param_2);
};

#endif // CBOATSAIL_HPP
