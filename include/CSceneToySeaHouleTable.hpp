#ifndef CSCENETOYSEAHOULETABLE_HPP
#define CSCENETOYSEAHOULETABLE_HPP

#include "typedefs.h"

struct GmField2;

struct CSceneToySeaHouleTable {
    void** vftable;
    byte _padding_0x4[108];
    void * field_0x70; // accesses: 6
    byte _padding_0x74[4];
    GmField2 * field_0x78; // accesses: 2
    int field_0x7c; // accesses: 4
    float field_0x80; // accesses: 3
    byte _final_padding[0x24]; // Total size: 0xa8

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetPointElevation (CSceneToySeaHouleTable *this,CSceneToySeaHouleFixe *param_1,float param_2,float param_3, float *param_4);
    void __thiscall GetPointElevationAssiette (CSceneToySeaHouleTable *this,CSceneToySeaHouleTable *param_1,float param_2,float param_3, float *param_4);
    void __thiscall SetSamplingTime (CSceneToySeaHouleTable *this,CSceneToySeaHouleTable *param_1,ulong param_2,int param_3);
};

#endif // CSCENETOYSEAHOULETABLE_HPP
