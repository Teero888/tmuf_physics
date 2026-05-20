#ifndef CHMSPACKLIGHTMAP_HPP
#define CHMSPACKLIGHTMAP_HPP

#include "typedefs.h"

struct CHmsCorpus;
struct CMwNod;

struct CHmsPackLightMap {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    ulong field_0x8; // accesses: 2
    CHmsPackLightMap * field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 7
    int field_0x24; // accesses: 1
    ushort field_0x28; // accesses: 2
    byte _padding_0x2a[2];
    undefined4 field_0x2c; // accesses: 4
    int field_0x30; // accesses: 1
    byte _padding_0x34[20];
    int field_0x48; // accesses: 7
    byte _padding_0x4c[12];
    int field_0x58; // accesses: 1
    byte _padding_0x5c[20];
    uint field_0x70; // accesses: 2
    byte _padding_0x74[328];
    int field_0x1bc; // accesses: 3
    byte _padding_0x1c0[4];
    int field_0x1c4; // accesses: 6

    // Member Functions
    EDbgLight __thiscall DynaDbgLightGet(CHmsPackLightMap *this,CHmsPackLightMap *param_1);
    int __cdecl LmUsageIsPotentiallySupported(void);
    int __thiscall BlockSkipLightMap (CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsCorpus *param_2);
    int __thiscall BlockSub_IsFound (CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsCorpus *param_2, CFastBuffer<struct_CHmsPackLightMap::SBlock> *param_3);
    int __thiscall LmUsageIsSupported (CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsZoneVPacker *param_2);
    ulong __thiscall Corpus_GetLightMapBlockCount (CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsCorpus *param_2);
    void __thiscall BlockAdd(CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsCorpus *param_2);
    void __thiscall BlockSub(CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsCorpus *param_2);
    void __thiscall SetPacker (CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsZoneVPacker *param_2);
};

#endif // CHMSPACKLIGHTMAP_HPP
