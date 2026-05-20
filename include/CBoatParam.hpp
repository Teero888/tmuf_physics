#ifndef CBOATPARAM_HPP
#define CBOATPARAM_HPP

#include "typedefs.h"

struct CFuncCurvesReal;
struct CFuncKeysReal;

struct CBoatParam {
    void** vftable;
    byte _padding_0x4[52];
    CFuncCurvesReal * field_0x38; // accesses: 1
    CFuncCurvesReal * field_0x3c; // accesses: 2
    byte _padding_0x40[56];
    float field_0x78; // accesses: 3
    byte _padding_0x7c[4];
    float field_0x80; // accesses: 3
    byte _padding_0x84[4];
    CFuncKeysReal * field_0x88; // accesses: 2
    CFuncKeysReal * field_0x8c; // accesses: 1
    byte _padding_0x90[44];
    int field_0xbc; // accesses: 1
    CFuncKeysReal * field_0xc0; // accesses: 2
    byte _final_padding[0x68]; // Total size: 0x12c

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall BSCoefFromHeelGet(CBoatParam *this,CBoatParam *param_1,float param_2);
    /* WARNING: Removing unreachable block (ram,0x007ffe57) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall CBoatParam::OldHeelGet (CBoatParam *this,CBoatParam *param_1,CBoatSail *param_2,int param_3,float param_4, float param_5);
    float __thiscall DecelerationFromTillerGet (CBoatParam *this,CBoatParam *param_1,float param_2,float param_3,int param_4);
};

#endif // CBOATPARAM_HPP
