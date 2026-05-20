#ifndef CHMSPORTAL_HPP
#define CHMSPORTAL_HPP

#include "typedefs.h"

struct CMwNod;
struct CPlugTree;
struct CPlugVisual;
struct CVisionViewportDx9;
struct GmVec4;
struct SPlugFaceCull;

struct CHmsPortal {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    byte _padding_0x6c[12];
    int * field_0x78; // accesses: 5
    GmVec4 * field_0x7c; // accesses: 5
    undefined4 field_0x80; // accesses: 3
    CMwNod * field_0x84; // accesses: 12
    CMwNod * field_0x88; // accesses: 24
    byte _padding_0x8c[4];
    float field_0x90; // accesses: 1
    float field_0x94; // accesses: 1
    float field_0x98; // accesses: 1
    float field_0x9c; // accesses: 1
    float field_0xa0; // accesses: 1
    float field_0xa4; // accesses: 1
    float field_0xa8; // accesses: 1
    float field_0xac; // accesses: 1
    float field_0xb0; // accesses: 4
    float field_0xb4; // accesses: 4
    CHmsPortal * field_0xb8; // accesses: 4
    undefined4 field_0xbc; // accesses: 2
    undefined4 field_0xc0; // accesses: 2
    undefined4 field_0xc4; // accesses: 2
    undefined4 field_0xc8; // accesses: 2
    byte _padding_0xcc[48];
    uint field_0xfc; // accesses: 1
    float field_0x100; // accesses: 7
    float field_0x104; // accesses: 7

    // Member Functions
    CMwClassInfo * __thiscall MwGetClassInfo(CHmsPortal *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCHmsPortal(void);
    int __thiscall IsVisible(CHmsPortal *this,CPlugVisual *param_1,GmFrustum *param_2,GmIso4 *param_3);
    int __thiscall MwIsKindOf(CHmsPortal *this,CMwCmdAffectParam *param_1,ulong param_2);
    int __thiscall TransformView(CHmsPortal *this,CHmsPortal *param_1,GmIso4 *param_2,GmFrustum *param_3);
    ulong __thiscall GetChunkInfo(CHmsPortal *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CHmsPortal *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex(CHmsPortal *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    void * __thiscall _scalar_deleting_destructor_(CHmsPortal *this,CPfmHeap *param_1,uint param_2);
    void __cdecl LinkOneWay(CHmsPortal *param_1,CHmsPortal *param_2);
    void __cdecl LinkTwoWays(CHmsPortal *param_1,CHmsPortal *param_2);
    void __cdecl UpdateZoneTransfoOneWay(CHmsPortal *param_1,CHmsPortal *param_2);
    void __cdecl UpdateZoneTransfoTwoWays(CHmsPortal *param_1,CHmsPortal *param_2);
    void __thiscall BindToBuild(CHmsPortal *this,CHmsPortal *param_1,CHmsItem *param_2,CPlugTree *param_3);
    void __thiscall CHmsPortal(CHmsPortal *this,CHmsPortal *param_1);
    void __thiscall Chunk(CHmsPortal *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall ComputeVisualLocationFromVertices(CHmsPortal *this,CHmsPortal *param_1);
    void __thiscall GetPlaneEqInWorld(CHmsPortal *this,CHmsPortal *param_1,GmVec4 *param_2);
    void __thiscall MwIsKilled(CHmsPortal *this,CVisionViewportDx9 *param_1,CMwNod *param_2);
    void __thiscall MwIsUnreferenced(CHmsPortal *this,CVisionViewportDx9 *param_1,CMwNod *param_2);
    void __thiscall RefreshPortal(CHmsPortal *this,CHmsPortal *param_1);
    void __thiscall TransformLocation (CHmsPortal *this,CHmsPortal *param_1,SHmsCameraLocation *param_2, SHmsCameraLocation *param_3);
    void __thiscall UnbindFromBuild(CHmsPortal *this,CHmsPortal *param_1);
    void __thiscall ~CHmsPortal(CHmsPortal *this,CHmsPortal *param_1);
};

#endif // CHMSPORTAL_HPP
