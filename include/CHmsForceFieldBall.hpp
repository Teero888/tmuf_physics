#ifndef CHMSFORCEFIELDBALL_HPP
#define CHMSFORCEFIELDBALL_HPP

#include "typedefs.h"

struct CHmsForceFieldBall {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    float field_0x8; // accesses: 1
    byte _padding_0xc[4];
    int field_0x10; // accesses: 1
    byte _padding_0x14[4];
    int field_0x18; // accesses: 3
    byte _padding_0x1c[32];
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 1
    byte _padding_0x48[20];
    undefined4 field_0x5c; // accesses: 7
    undefined4 field_0x60; // accesses: 2
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ GmVec3 __thiscall GetValue(CHmsForceFieldBall *this,CFuncColorGradient *param_1,float param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CHmsForceFieldBall(CHmsForceFieldBall *this,CHmsForceFieldBall *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CHmsForceFieldBall *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCHmsForceFieldBall(void);
    int __thiscall MwIsKindOf(CHmsForceFieldBall *this,CMwCmdAffectParam *param_1,ulong param_2);
    int __thiscall TestBoxOverlap (CHmsForceFieldBall *this,CHmsForceFieldBall *param_1,GmBoxAligned *param_2);
    ulong __thiscall GetChunkInfo(CHmsForceFieldBall *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CHmsForceFieldBall *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex (CHmsForceFieldBall *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall VirtualParam_Set (CHmsForceFieldBall *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    void * __thiscall _scalar_deleting_destructor_ (CHmsForceFieldBall *this,CPfmHeap *param_1,uint param_2);
    void __thiscall Chunk (CHmsForceFieldBall *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall ComputeBoundingBox (CHmsForceFieldBall *this,CPlugVisualStrip *param_1,ulong param_2,ulong param_3);
    void __thiscall ~CHmsForceFieldBall(CHmsForceFieldBall *this,CHmsForceFieldBall *param_1);
};

#endif // CHMSFORCEFIELDBALL_HPP
