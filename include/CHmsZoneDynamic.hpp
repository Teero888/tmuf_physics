#ifndef CHMSZONEDYNAMIC_HPP
#define CHMSZONEDYNAMIC_HPP

#include "typedefs.h"

struct CSystemFileMemMapped;
struct GmMat3;

struct CHmsZoneDynamic {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    int * field_0x8; // accesses: 9
    int * field_0xc; // accesses: 5
    float field_0x10; // accesses: 2
    float field_0x14; // accesses: 9
    float field_0x18; // accesses: 6
    float field_0x1c; // accesses: 8
    float field_0x20; // accesses: 8
    int field_0x24; // accesses: 13
    float field_0x28; // accesses: 9
    float field_0x2c; // accesses: 11
    float field_0x30; // accesses: 4
    undefined2 field_0x34; // accesses: 12
    undefined2 field_0x36; // accesses: 4
    float field_0x38; // accesses: 8
    int field_0x3c; // accesses: 4
    byte _padding_0x40[8];
    ulong field_0x48; // accesses: 22
    byte _padding_0x4c[12];
    int field_0x58; // accesses: 11
    byte _padding_0x5c[172];
    float * field_0x108; // accesses: 2
    byte _padding_0x10c[16];
    float field_0x11c; // accesses: 1
    float field_0x120; // accesses: 1
    byte _padding_0x124[16];
    int * field_0x134; // accesses: 4
    int * field_0x138; // accesses: 3
    byte _padding_0x13c[28];
    int field_0x158; // accesses: 1
    byte _padding_0x15c[12];
    int field_0x168; // accesses: 10
    byte _padding_0x16c[448];
    int field_0x32c; // accesses: 3
    byte _padding_0x330[16];
    int field_0x340; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall PhysicsStep2(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SolveImpulse (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,SHmsPhysicalCollision *param_2, CHmsPhysicalContact *param_3,CHmsPhysicalContact *param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateCorpusFromDynamicState (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2, CClassicBufferMemory *param_3,ulong param_4,uchar param_5);
    /* WARNING: Removing unreachable block (ram,0x00549b89) */ /* WARNING: Removing unreachable block (ram,0x00549b9a) */ /* WARNING: Removing unreachable block (ram,0x00549bae) */ /* WARNING: Removing unreachable block (ram,0x00549ba3) */ /* WARNING: Removing unreachable block (ram,0x00549bb1) */ /* WARNING: Removing unreachable block (ram,0x00549bd4) */ void __thiscall CHmsZoneDynamic::ComputeCollisionResponse(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1);
    int __thiscall IsPhysics(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1);
    void __thiscall AfterCollisionGroupChange (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2);
    void __thiscall BeforeCollisionGroupChange (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2);
    void __thiscall ComputeCorpusForces (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2,float param_3);
    void __thiscall SetPhysics(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,int param_2);
};

#endif // CHMSZONEDYNAMIC_HPP
