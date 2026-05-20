#ifndef CHMSZONEVPACKER_HPP
#define CHMSZONEVPACKER_HPP

#include "typedefs.h"

struct CHmsCorpus;
struct CHmsItem;
struct CHmsPackLightMap;
struct CHmsVPackerCell;
struct CMwNod;
struct CSceneSector;
struct SHmsVPackerCreate;
struct ushort;

struct CHmsZoneVPacker {
    struct SLocationAlloc {
        void** vftable; // accesses: 2

        // Member Functions
        ulong __thiscall UseNew(void *this,SLocationAlloc *param_1);
        void __thiscall FreeAt(void *this,SLocationAlloc *param_1,ulong param_2);
    };

    void** vftable; // accesses: 7
    byte _padding_0x4[8];
    int field_0xc; // accesses: 2
    int field_0x10; // accesses: 1
    CHmsZoneVPacker * field_0x14; // accesses: 1
    CHmsPackLightMap * field_0x18; // accesses: 1
    SHmsVPackerCreate * field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    CHmsZoneVPacker * field_0x24; // accesses: 2
    byte _padding_0x28[32];
    CHmsItem * field_0x48; // accesses: 5
    byte _padding_0x4c[12];
    undefined4 field_0x58; // accesses: 2
    byte _padding_0x5c[4];
    CHmsZoneVPacker * field_0x60; // accesses: 4
    byte _padding_0x64[8];
    int field_0x6c; // accesses: 2
    byte _padding_0x70[4];
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    void * field_0x80; // accesses: 3
    byte _padding_0x84[24];
    ushort field_0x9c; // accesses: 1
    ushort field_0x9e; // accesses: 1
    byte _padding_0xa0[36];
    undefined4 field_0xc4; // accesses: 1
    undefined4 field_0xc8; // accesses: 1
    undefined4 field_0xcc; // accesses: 1
    undefined4 field_0xd0; // accesses: 1
    undefined4 field_0xd4; // accesses: 1
    undefined4 field_0xd8; // accesses: 1
    undefined4 field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 3
    undefined4 field_0xe8; // accesses: 2
    CHmsItem * field_0xec; // accesses: 8
    CHmsZoneVPacker * field_0xf0; // accesses: 13
    undefined4 field_0xf4; // accesses: 4
    undefined4 field_0xf8; // accesses: 27
    byte _padding_0xfc[40];
    CHmsZoneVPacker * field_0x124; // accesses: 4
    byte _padding_0x128[96];
    CHmsZoneVPacker * field_0x188; // accesses: 3
    void * field_0x18c; // accesses: 3
    void * field_0x190; // accesses: 2
    void * field_0x194; // accesses: 3
    void * field_0x198; // accesses: 2
    byte _padding_0x19c[4];
    uint * field_0x1a0; // accesses: 5
    int field_0x1a4; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall AddNewLight (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsCorpusLight *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Construct (CHmsZoneVPacker *this,CSceneToySeaHoule *param_1,CPlugBitmap *param_2,float param_3, float param_4,float param_5,float param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RemoveSolid(CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsCorpus *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetCreateParams (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,SHmsVPackerCreate *param_2);
    int __thiscall CheckDirty (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsViewport *param_2,CHmsCamera *param_3);
    void __cdecl ShadowCasterStateAdd(EShadowCaster *param_1,CHmsItem *param_2);
    void __thiscall AddInteractLights (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1, CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc> *param_2, CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc> *param_3,CHmsVPackerCell *param_4, SFlags *param_5,ERadius param_6);
    void __thiscall AddInteractLightsInternal(CHmsZoneVPacker *this,CHmsZoneVPacker *param_1);
    void __thiscall AddInteractLightsRecur (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,ulong param_2,ulong param_3,ulong param_4, ulong param_5);
    void __thiscall AddInteractLightsWithCell (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsVPackerCell *param_2);
    void __thiscall AddNewSolid(CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsCorpus *param_2);
    void __thiscall CHmsZoneVPacker(CHmsZoneVPacker *this,CHmsZoneVPacker *param_1);
    void __thiscall CellAndChildSetDirtyCV (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsVPackerCell *param_2, SUserData *param_3);
    void __thiscall LightBBoxSetDirtyCV (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,GmBoxAligned *param_2);
    void __thiscall LightBBoxSetDirtyCV_Recur (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,ulong param_2,ulong param_3,ulong param_4, ulong param_5,GmBoxAligned *param_6);
    void __thiscall PrecalcLighting(CHmsZoneVPacker *this,CHmsZoneVPacker *param_1);
    void __thiscall RemoveLight (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsCorpusLight *param_2);
    void __thiscall SetDayTimeFactor (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,float param_2,int param_3);
    void __thiscall SetPackLightMap (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsPackLightMap *param_2);
    void __thiscall SetZone(CHmsZoneVPacker *this,CSceneSector *param_1,CHmsZone *param_2);
};

#endif // CHMSZONEVPACKER_HPP
