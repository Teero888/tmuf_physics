#ifndef CHMSZONEDYNAMIC_HPP
#define CHMSZONEDYNAMIC_HPP

#include "typedefs.h"

struct CHmsZoneDynamic {
    void** vftable;
    byte _padding_0x4[280];
    float field_0x11c; // accesses: 1
    float field_0x120; // accesses: 1
    byte _padding_0x124[16];
    int * field_0x134; // accesses: 4
    int * field_0x138; // accesses: 3
    byte _padding_0x13c[28];
    int field_0x158; // accesses: 1
    byte _padding_0x15c[12];
    void * field_0x168; // accesses: 10
    byte _final_padding[0xc]; // Total size: 0x178

    // Member Functions
    int __thiscall IsPhysics(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1);
    void __thiscall AfterCollisionGroupChange (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2);
    void __thiscall BeforeCollisionGroupChange (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2);
    void __thiscall ComputeCollisionResponse(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1);
    void __thiscall ComputeCorpusForces (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2,float param_3);
    void __thiscall PhysicsStep2(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1);
    void __thiscall SetPhysics(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,int param_2);
    void __thiscall SolveImpulse (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,SHmsPhysicalCollision *param_2, CHmsPhysicalContact *param_3,CHmsPhysicalContact *param_4);
    void __thiscall UpdateCorpusFromDynamicState (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2, CClassicBufferMemory *param_3,ulong param_4,uchar param_5);
};

#endif // CHMSZONEDYNAMIC_HPP
