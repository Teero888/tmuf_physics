#ifndef CHMSPACKLIGHTMAP_HPP
#define CHMSPACKLIGHTMAP_HPP

#include "typedefs.h"

struct CMwNod;

struct CHmsPackLightMap {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    byte _padding_0x1c[4];
    CMwNod * field_0x20; // accesses: 6
    byte _padding_0x24[8];
    undefined4 field_0x2c; // accesses: 2
    int field_0x30; // accesses: 1
    byte _padding_0x34[20];
    int field_0x48; // accesses: 6
    byte _padding_0x4c[368];
    CHmsPackLightMap * field_0x1bc; // accesses: 3
    byte _padding_0x1c0[4];
    undefined4 field_0x1c4; // accesses: 6

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
