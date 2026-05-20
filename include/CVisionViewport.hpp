#ifndef CVISIONVIEWPORT_HPP
#define CVISIONVIEWPORT_HPP

#include "typedefs.h"

struct CClassicBufferMemory;
struct CHmsViewport;
struct CVisionShaderKeeper;

struct CVisionViewport {
    struct SOccWheel {

        // Member Functions
        void __thiscall SOccWheel(void *this,SOccWheel *param_1);
    };

    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    int field_0x8; // accesses: 3
    byte _padding_0xc[4];
    uint field_0x10; // accesses: 3
    undefined4 field_0x14; // accesses: 7
    byte _padding_0x18[4];
    uint field_0x1c; // accesses: 1
    byte _padding_0x20[20];
    int field_0x34; // accesses: 1
    byte _padding_0x38[424];
    undefined4 field_0x1e0; // accesses: 1
    undefined4 field_0x1e4; // accesses: 1
    undefined4 field_0x1e8; // accesses: 1
    undefined4 field_0x1ec; // accesses: 1
    byte _padding_0x1f0[8];
    undefined4 field_0x1f8; // accesses: 1
    undefined4 field_0x1fc; // accesses: 1
    undefined4 field_0x200; // accesses: 1
    undefined4 field_0x204; // accesses: 1
    undefined4 field_0x208; // accesses: 1
    byte _padding_0x20c[4];
    undefined4 field_0x210; // accesses: 1
    byte _padding_0x214[8];
    undefined4 field_0x21c; // accesses: 1
    undefined4 field_0x220; // accesses: 1
    undefined4 field_0x224; // accesses: 1
    undefined4 field_0x228; // accesses: 1
    byte _padding_0x22c[204];
    int field_0x2f8; // accesses: 1
    byte _padding_0x2fc[632];
    undefined4 field_0x574; // accesses: 1
    byte _padding_0x578[160];
    undefined4 field_0x618; // accesses: 1
    byte _padding_0x61c[28];
    undefined4 field_0x638; // accesses: 1
    byte _padding_0x63c[12];
    undefined4 field_0x648; // accesses: 1
    byte _padding_0x64c[180];
    undefined4 field_0x700; // accesses: 1
    undefined4 field_0x704; // accesses: 1
    undefined4 field_0x708; // accesses: 1
    byte _padding_0x70c[212];
    undefined4 field_0x7e0; // accesses: 1
    undefined4 field_0x7e4; // accesses: 1
    undefined4 field_0x7e8; // accesses: 1
    undefined4 field_0x7ec; // accesses: 1
    undefined4 field_0x7f0; // accesses: 1
    undefined4 field_0x7f4; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CVisionViewport(CVisionViewport *this,CVisionViewport *param_1);
    CVisionShaderKeeper * __thiscall ShaderGetKeeper (CVisionViewport *this,CVisionViewport *param_1,CPlugShader *param_2);
    int __thiscall ForceDeviceSynchro(CVisionViewport *this,CVisionViewportDx9 *param_1);
    void __thiscall ShaderUndirtyAll(CVisionViewport *this,CVisionViewport *param_1,int param_2);
    void __thiscall ShaderUpdateSortIndexs(CVisionViewport *this,CVisionViewport *param_1);
};

#endif // CVISIONVIEWPORT_HPP
