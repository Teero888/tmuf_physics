#ifndef CPLUGTREEVISUALMIP_HPP
#define CPLUGTREEVISUALMIP_HPP

#include "typedefs.h"

struct CPlugTreeVisualMip {
    void** vftable; // accesses: 6
    byte _padding_0x4[16];
    int field_0x14; // accesses: 1
    byte _padding_0x18[52];
    undefined4 field_0x4c; // accesses: 1
    byte _padding_0x50[64];
    int field_0x90; // accesses: 1
    byte _padding_0x94[8];
    uint field_0x9c; // accesses: 2
    byte _padding_0xa0[28];
    undefined4 field_0xbc; // accesses: 3
    byte _padding_0xc0[12];
    float field_0xcc; // accesses: 4
    float field_0xd0; // accesses: 4

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CPlugTreeVisualMip(CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetDistributionFromFarZs(CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1);
    void __thiscall AddLevel (CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1,CPlugTree *param_2,float param_3);
    void __thiscall DeleteAllChilds(CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1);
    void __thiscall GetMipOptimizedGroups (CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1,int param_2, CFastBuffer<struct_SPlugTreeOptimGroup*> *param_3,SPlugTreeOptimCriteria *param_4, SPlugTreeOptimTravel *param_5);
    void __thiscall SetLevelFarZ (CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1,ulong param_2,float param_3);
};

#endif // CPLUGTREEVISUALMIP_HPP
