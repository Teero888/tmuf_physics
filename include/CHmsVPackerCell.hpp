#ifndef CHMSVPACKERCELL_HPP
#define CHMSVPACKERCELL_HPP

#include "typedefs.h"

struct CHmsZoneVPacker;
struct CPlugTree;
struct CPlugTreeVisualMip;
struct GmBoxAligned;

struct CHmsVPackerCell {
    byte _padding_0x0[4];
    CPlugTreeVisualMip * field_0x4; // accesses: 4
    int field_0x8; // accesses: 4
    byte _padding_0xc[8];
    int field_0x14; // accesses: 2
    byte _padding_0x18[52];
    undefined4 field_0x4c; // accesses: 1
    byte _padding_0x50[8];
    CHmsZoneVPacker * field_0x58; // accesses: 6
    GmBoxAligned * field_0x5c; // accesses: 1
    CHmsVPackerCell * field_0x60; // accesses: 1
    ulong * field_0x64; // accesses: 1
    byte _padding_0x68[44];
    int field_0x94; // accesses: 1

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
