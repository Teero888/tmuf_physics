#ifndef CHMSVIEWPORT_HPP
#define CHMSVIEWPORT_HPP

#include "typedefs.h"

struct CHmsConfig;
struct CHmsCorpus;
struct CHmsPortal;
struct CMwCmd;
struct CMwNod;
struct GmFrustum;

struct CHmsViewport {
    struct SClippingFrustum {
        void** vftable;
        byte _padding_0x4[24];
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

    void** vftable; // accesses: 25
    byte _padding_0x4[28];
    undefined4 field_0x20; // accesses: 1
    int field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1

    // Member Functions
    CHmsViewport * __thiscall FindOrCreateViewport(CHmsViewport *this,CVisionEngine *param_1,CSystemWindow *param_2);
    int __thiscall OverlayRemove(CHmsViewport *this,CHmsViewport *param_1,CHmsZoneOverlay *param_2);
    int __thiscall RenderTree(CHmsViewport *this,CHmsViewport *param_1,CPlugTree *param_2);
    void __thiscall CHmsViewport(CHmsViewport *this,CHmsViewport *param_1);
    void __thiscall ConfigSet(CHmsViewport *this,CHmsViewport *param_1,CHmsConfig *param_2);
    void __thiscall LoadResourceCorpus(CHmsViewport *this,CHmsViewport *param_1,CHmsCorpus *param_2);
    void __thiscall LoadResourceZone(CHmsViewport *this,CHmsViewport *param_1,CHmsZone *param_2);
    void __thiscall OverlayAdd (CHmsViewport *this,CHmsViewport *param_1,CHmsZoneOverlay *param_2,ulong param_3);
    void __thiscall OverlaySetIndex (CHmsViewport *this,CHmsViewport *param_1,CHmsZoneOverlay *param_2,ulong param_3);
    void __thiscall PortalSetVisualLocation(CHmsViewport *this,CHmsViewport *param_1,CHmsPortal *param_2);
    void __thiscall RenderCorpus(CHmsViewport *this,CHmsViewport *param_1,CHmsCorpus *param_2);
    void __thiscall RenderPortal (CHmsViewport *this,CHmsViewport *param_1,CHmsPortal *param_2,GmFrustum *param_3, int param_4);
    void __thiscall RenderVisibleZone2ds (CHmsViewport *this,CHmsViewport *param_1,CFastBuffer<class_CHmsZoneOverlay*> *param_2, int param_3);
    void __thiscall RenderZone(CHmsViewport *this,CHmsViewport *param_1,CHmsZone *param_2);
    void __thiscall ResetShadowVolumes(CHmsViewport *this,CHmsViewport *param_1);
};

#endif // CHMSVIEWPORT_HPP
