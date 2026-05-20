#ifndef CHMSVPACKERCELL_HPP
#define CHMSVPACKERCELL_HPP

#include "typedefs.h"

struct GmBoxAligned;
struct ulong;

struct CHmsVPackerCell {
    void** vftable; // accesses: 2
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 3
    float field_0x14; // accesses: 2
    byte _padding_0x18[12];
    undefined2 field_0x24; // accesses: 1
    byte _padding_0x26[2];
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 2
    byte _padding_0x30[24];
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[12];
    undefined4 field_0x58; // accesses: 3
    GmBoxAligned * field_0x5c; // accesses: 1
    CHmsVPackerCell * field_0x60; // accesses: 1
    ulong * field_0x64; // accesses: 1
    byte _padding_0x68[12];
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CHmsVPackerCell(void *this,CHmsVPackerCell *param_1);
    void __thiscall AddTreeMip (void *this,CHmsVPackerCell *param_1,SHmsVPackerObject *param_2,GmBoxAligned *param_3, ulong *param_4);
    void __thiscall BBoxHasChanged(void *this,CHmsVPackerCell *param_1);
    void __thiscall PrecalcLighting(void *this,CHmsZoneVPacker *param_1);
    void __thiscall PreloadVisionData (void *this,CHmsZoneVPacker *param_1,CHmsViewport *param_2,CHmsCamera *param_3);
    void __thiscall RemoveAllTreeMip(void *this,CHmsVPackerCell *param_1,CHmsCorpus *param_2);
    void __thiscall SubTreeMip (void *this,CHmsVPackerCell *param_1,CPlugTreeVisualMip *param_2,ulong *param_3);
    void __thiscall ~CHmsVPackerCell(void *this,CHmsVPackerCell *param_1);
};

#endif // CHMSVPACKERCELL_HPP
