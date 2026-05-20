#ifndef CHMSVIEWPORT_HPP
#define CHMSVIEWPORT_HPP

#include "typedefs.h"

struct CHmsConfig;
struct CHmsCorpus;
struct CHmsPortal;
struct CMwCmd;
struct CMwNod;
struct CPlugTree;
struct GmFrustum;
struct SPlugFaceCull;
struct ulong;
struct ushort;

struct CHmsViewport {
    struct SClippingFrustum {
        byte _padding_0x0[28];
        undefined4 field_0x1c; // accesses: 2
        float field_0x20; // accesses: 2
        float field_0x24; // accesses: 2
        float field_0x28; // accesses: 2
        byte _padding_0x2c[4];
        float field_0x30; // accesses: 2
        float field_0x34; // accesses: 2
        float field_0x38; // accesses: 2
        byte _padding_0x3c[4];
        float field_0x40; // accesses: 2
        float field_0x44; // accesses: 2
        float field_0x48; // accesses: 2
        byte _padding_0x4c[4];
        float field_0x50; // accesses: 2
        float field_0x54; // accesses: 2
        float field_0x58; // accesses: 2
        byte _padding_0x5c[4];
        float field_0x60; // accesses: 2
        float field_0x64; // accesses: 2
        float field_0x68; // accesses: 2
        byte _padding_0x6c[4];
        float field_0x70; // accesses: 2
        float field_0x74; // accesses: 2
        float field_0x78; // accesses: 2
        byte _padding_0x7c[68];
        float field_0xc0; // accesses: 2
        float field_0xc4; // accesses: 2
        float field_0xc8; // accesses: 2
        float field_0xcc; // accesses: 2
        float field_0xd0; // accesses: 2
        float field_0xd4; // accesses: 2
        float field_0xd8; // accesses: 2
        float field_0xdc; // accesses: 2
        float field_0xe0; // accesses: 2
        float field_0xe4; // accesses: 2
        float field_0xe8; // accesses: 2
        float field_0xec; // accesses: 2
        float field_0xf0; // accesses: 2
        float field_0xf4; // accesses: 2
        float field_0xf8; // accesses: 2
        float field_0xfc; // accesses: 2
        float field_0x100; // accesses: 2
        float field_0x104; // accesses: 2

        // Member Functions
        void __thiscall ComputePlaneEqs (void *this,SClippingFrustum *param_1,GmIso4 *param_2);
        void __thiscall Set(void *this,CMwCmdScriptVarBool *param_1,int param_2);
    };

    struct SRenderInfo {
        void** vftable; // accesses: 1
        undefined * field_0x4; // accesses: 1
        undefined4 field_0x8; // accesses: 1
        byte _padding_0xc[28];
        undefined4 field_0x28; // accesses: 1
        undefined4 field_0x2c; // accesses: 1
        byte _padding_0x30[4];
        undefined4 field_0x34; // accesses: 1
        undefined4 field_0x38; // accesses: 1
        undefined4 field_0x3c; // accesses: 1
        byte _padding_0x40[12];
        undefined4 field_0x4c; // accesses: 1
        undefined4 field_0x50; // accesses: 1
        undefined4 field_0x54; // accesses: 1
        undefined4 field_0x58; // accesses: 1
        undefined4 field_0x5c; // accesses: 1
        undefined4 field_0x60; // accesses: 1
        undefined4 field_0x64; // accesses: 1
        undefined4 field_0x68; // accesses: 1
        undefined4 field_0x6c; // accesses: 1
        byte _padding_0x70[16];
        undefined4 field_0x80; // accesses: 1
        undefined4 field_0x84; // accesses: 1

        // Member Functions
        void __thiscall SRenderInfo(void *this,SRenderInfo *param_1);
    };

    void** vftable; // accesses: 33
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[8];
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    float field_0x38; // accesses: 3
    float field_0x3c; // accesses: 3
    float field_0x40; // accesses: 7
    float field_0x44; // accesses: 8
    float field_0x48; // accesses: 8
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 2
    undefined4 field_0x80; // accesses: 1
    CPlugTree * field_0x84; // accesses: 3
    undefined4 field_0x88; // accesses: 1
    int field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 2
    SPlugVisibleId * field_0x94; // accesses: 2
    byte _padding_0x98[4];
    CMwNod * field_0x9c; // accesses: 11
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    undefined4 field_0xac; // accesses: 1
    undefined4 field_0xb0; // accesses: 1
    byte _padding_0xb4[92];
    undefined4 field_0x110; // accesses: 1
    undefined4 field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    byte _padding_0x11c[4];
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    undefined * field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 1
    undefined4 field_0x130; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    undefined * field_0x15c; // accesses: 1
    undefined4 field_0x160; // accesses: 1
    byte _padding_0x164[168];
    undefined4 field_0x20c; // accesses: 1
    byte _padding_0x210[4];
    undefined4 field_0x214; // accesses: 1
    undefined4 field_0x218; // accesses: 1
    byte _padding_0x21c[16];
    undefined4 field_0x22c; // accesses: 1
    int field_0x230; // accesses: 1
    undefined4 field_0x234; // accesses: 5
    void * field_0x238; // accesses: 6
    undefined4 field_0x23c; // accesses: 1
    int field_0x240; // accesses: 2
    CHmsConfig * field_0x244; // accesses: 2
    undefined4 field_0x248; // accesses: 1
    undefined4 field_0x24c; // accesses: 1
    undefined4 field_0x250; // accesses: 1
    undefined4 field_0x254; // accesses: 1
    undefined4 field_0x258; // accesses: 1
    CMwNod * field_0x25c; // accesses: 2
    undefined4 field_0x260; // accesses: 1
    byte _padding_0x264[36];
    undefined4 field_0x288; // accesses: 1
    undefined4 field_0x28c; // accesses: 1
    undefined4 field_0x290; // accesses: 1
    byte _padding_0x294[8];
    int field_0x29c; // accesses: 1
    byte _padding_0x2a0[4];
    GmFrustum * field_0x2a4; // accesses: 8
    int field_0x2a8; // accesses: 8
    byte _padding_0x2ac[72];
    int field_0x2f4; // accesses: 1
    byte _padding_0x2f8[36];
    undefined4 * field_0x31c; // accesses: 9
    undefined4 field_0x320; // accesses: 1
    undefined4 field_0x324; // accesses: 1
    undefined4 field_0x328; // accesses: 1
    undefined4 field_0x32c; // accesses: 1
    undefined4 field_0x330; // accesses: 1
    undefined4 field_0x334; // accesses: 1
    undefined4 field_0x338; // accesses: 1
    ulong field_0x33c; // accesses: 3
    byte _padding_0x340[8];
    undefined4 field_0x348; // accesses: 1
    undefined4 field_0x34c; // accesses: 3
    int field_0x350; // accesses: 1
    undefined4 field_0x354; // accesses: 1
    undefined4 field_0x358; // accesses: 8
    undefined4 field_0x35c; // accesses: 12
    byte _padding_0x360[36];
    ushort field_0x384; // accesses: 3
    ushort field_0x386; // accesses: 2
    undefined2 field_0x388; // accesses: 1
    undefined2 field_0x38a; // accesses: 1
    int field_0x38c; // accesses: 20
    byte _padding_0x390[36];
    ulong field_0x3b4; // accesses: 4
    undefined4 field_0x3b8; // accesses: 1
    undefined4 field_0x3bc; // accesses: 1
    undefined4 field_0x3c0; // accesses: 5
    byte _padding_0x3c4[80];
    undefined4 field_0x414; // accesses: 4
    undefined4 field_0x418; // accesses: 3
    undefined4 field_0x41c; // accesses: 2
    undefined4 field_0x420; // accesses: 1
    undefined4 field_0x424; // accesses: 1
    undefined4 field_0x428; // accesses: 1
    undefined4 field_0x42c; // accesses: 1
    undefined4 field_0x430; // accesses: 12
    undefined4 field_0x434; // accesses: 1
    undefined4 field_0x438; // accesses: 1
    byte _padding_0x43c[12];
    undefined4 field_0x448; // accesses: 4
    undefined4 field_0x44c; // accesses: 1
    undefined4 field_0x450; // accesses: 1
    byte _padding_0x454[224];
    undefined4 field_0x534; // accesses: 1
    byte _padding_0x538[12];
    undefined4 field_0x544; // accesses: 1
    undefined4 field_0x548; // accesses: 1
    undefined4 field_0x54c; // accesses: 1
    undefined4 field_0x550; // accesses: 1
    undefined4 field_0x554; // accesses: 1
    undefined4 field_0x558; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall RenderTree(CHmsViewport *this,CHmsViewport *param_1,CPlugTree *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CHmsViewport(CHmsViewport *this,CHmsViewport *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RenderCorpus(CHmsViewport *this,CHmsViewport *param_1,CHmsCorpus *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RenderPortal (CHmsViewport *this,CHmsViewport *param_1,CHmsPortal *param_2,GmFrustum *param_3, int param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RenderVisibleZone2ds (CHmsViewport *this,CHmsViewport *param_1,CFastBuffer<class_CHmsZoneOverlay*> *param_2, int param_3);
    CHmsViewport * __thiscall FindOrCreateViewport(CHmsViewport *this,CVisionEngine *param_1,CSystemWindow *param_2);
    int __thiscall OverlayRemove(CHmsViewport *this,CHmsViewport *param_1,CHmsZoneOverlay *param_2);
    void __thiscall ConfigSet(CHmsViewport *this,CHmsViewport *param_1,CHmsConfig *param_2);
    void __thiscall LoadResourceCorpus(CHmsViewport *this,CHmsViewport *param_1,CHmsCorpus *param_2);
    void __thiscall LoadResourceZone(CHmsViewport *this,CHmsViewport *param_1,CHmsZone *param_2);
    void __thiscall OverlayAdd (CHmsViewport *this,CHmsViewport *param_1,CHmsZoneOverlay *param_2,ulong param_3);
    void __thiscall OverlaySetIndex (CHmsViewport *this,CHmsViewport *param_1,CHmsZoneOverlay *param_2,ulong param_3);
    void __thiscall PortalSetVisualLocation(CHmsViewport *this,CHmsViewport *param_1,CHmsPortal *param_2);
    void __thiscall RenderZone(CHmsViewport *this,CHmsViewport *param_1,CHmsZone *param_2);
    void __thiscall ResetShadowVolumes(CHmsViewport *this,CHmsViewport *param_1);
};

#endif // CHMSVIEWPORT_HPP
