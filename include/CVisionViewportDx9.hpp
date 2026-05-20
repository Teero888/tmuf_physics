#ifndef CVISIONVIEWPORTDX9_HPP
#define CVISIONVIEWPORTDX9_HPP

#include "typedefs.h"

struct CHmsCamera;
struct CHmsViewport;
struct CMwId;
struct CMwNod;
struct CPlugFileGPUP;
struct CPlugFileGPUV;
struct CPlugShader;
struct CPlugShaderApply;
struct CPlugTree;
struct CPlugVisual;
struct CSystemConfig;
struct CVisionViewport;
struct GmBoxAligned;
struct GmFrustum;
struct GmIso4;
struct GmMat3;
struct SHmsRenderRect;
struct SPlugFaceCull;

struct CVisionViewportDx9 {

    struct CCameraFxDx9 {
        void** vftable;
        byte _padding_0x4[16];
        CVisionViewportDx9 * field_0x14; // accesses: 1
        byte _padding_0x18[12];
        int field_0x24; // accesses: 2

        // Member Functions
        void __thiscall CameraToTexture_ForceShader(CCameraFxDx9 *this,undefined4 param_1);
        void __thiscall ForceShadowVolumeUpdate(CCameraFxDx9 *this,CCameraFxDx9 *param_1);
    };

    void** vftable; // accesses: 65
    byte _padding_0x4[104];
    int field_0x6c; // accesses: 4
    byte _padding_0x70[16];
    int field_0x80; // accesses: 1
    int field_0x84; // accesses: 2
    byte _padding_0x88[28];
    int field_0xa4; // accesses: 2
    byte _padding_0xa8[116];
    float field_0x11c; // accesses: 1
    byte _padding_0x120[64];
    undefined4 field_0x160; // accesses: 1
    byte _padding_0x164[212];
    int field_0x238; // accesses: 2
    byte _padding_0x23c[12];
    int field_0x248; // accesses: 5
    CSystemConfig * field_0x24c; // accesses: 4
    byte _padding_0x250[84];
    int field_0x2a4; // accesses: 5
    int field_0x2a8; // accesses: 5
    byte _padding_0x2ac[12];
    int field_0x2b8; // accesses: 9
    byte _padding_0x2bc[60];
    int field_0x2f8; // accesses: 1
    byte _padding_0x2fc[24];
    int field_0x314; // accesses: 2
    undefined4 field_0x318; // accesses: 1
    byte _padding_0x31c[16];
    int field_0x32c; // accesses: 3
    byte _padding_0x330[32];
    CHmsCamera * field_0x350; // accesses: 2
    byte _padding_0x354[48];
    CPlugBitmap * field_0x384; // accesses: 14
    ushort field_0x386; // accesses: 12
    SCasterCat * field_0x388; // accesses: 26
    ushort field_0x38a; // accesses: 19
    undefined4 field_0x38c; // accesses: 2
    byte _padding_0x390[48];
    SRenderShaderParam * field_0x3c0; // accesses: 5
    byte _padding_0x3c4[80];
    uint field_0x414; // accesses: 41
    undefined4 field_0x418; // accesses: 2
    CVisionViewportDx9 * field_0x41c; // accesses: 6
    CPlugBitmap * field_0x420; // accesses: 4
    undefined4 field_0x424; // accesses: 5
    undefined4 field_0x428; // accesses: 4
    undefined4 field_0x42c; // accesses: 6
    undefined4 field_0x430; // accesses: 2
    undefined4 field_0x434; // accesses: 3
    uint field_0x438; // accesses: 1
    byte _padding_0x43c[12];
    CMwId * field_0x448; // accesses: 3
    CPlugShaderApply * field_0x44c; // accesses: 6
    CVisionViewportDx9 * field_0x450; // accesses: 5
    byte _padding_0x454[24];
    int field_0x46c; // accesses: 4
    byte _padding_0x470[664];
    int field_0x708; // accesses: 6
    byte _padding_0x70c[268];
    undefined4 field_0x818; // accesses: 1
    byte _padding_0x81c[4];
    undefined4 field_0x820; // accesses: 1
    undefined4 field_0x824; // accesses: 1
    byte _padding_0x828[12];
    undefined4 field_0x834; // accesses: 1
    undefined4 field_0x838; // accesses: 1
    undefined4 field_0x83c; // accesses: 1
    undefined4 field_0x840; // accesses: 1
    undefined4 field_0x844; // accesses: 1
    undefined4 field_0x848; // accesses: 1
    undefined4 field_0x84c; // accesses: 1
    undefined4 field_0x850; // accesses: 6
    undefined4 field_0x854; // accesses: 4
    undefined4 field_0x858; // accesses: 3
    SCasterCat * field_0x85c; // accesses: 3
    undefined4 field_0x860; // accesses: 3
    CPlugBitmapRender * field_0x864; // accesses: 2
    CMwNod * field_0x868; // accesses: 11
    byte _padding_0x86c[36];
    undefined4 field_0x890; // accesses: 1
    undefined4 field_0x894; // accesses: 1
    undefined4 field_0x898; // accesses: 1
    undefined4 field_0x89c; // accesses: 1
    undefined4 field_0x8a0; // accesses: 1
    undefined4 field_0x8a4; // accesses: 1
    undefined4 field_0x8a8; // accesses: 1
    undefined4 field_0x8ac; // accesses: 1
    undefined4 field_0x8b0; // accesses: 1
    undefined4 field_0x8b4; // accesses: 1
    byte _padding_0x8b8[16];
    undefined4 field_0x8c8; // accesses: 1
    byte _padding_0x8cc[24];
    SNewTriangleVert * field_0x8e4; // accesses: 12
    CMwId * field_0x8e8; // accesses: 9
    CVisionViewportDx9 * field_0x8ec; // accesses: 4
    byte _padding_0x8f0[20];
    SHmsRenderRect * field_0x904; // accesses: 8
    undefined4 field_0x908; // accesses: 1
    undefined4 field_0x90c; // accesses: 1
    undefined4 field_0x910; // accesses: 1
    undefined4 field_0x914; // accesses: 3
    undefined4 field_0x918; // accesses: 3
    ulong field_0x91c; // accesses: 12
    undefined4 field_0x920; // accesses: 7
    undefined4 field_0x924; // accesses: 1
    undefined4 field_0x928; // accesses: 1
    undefined4 * field_0x92c; // accesses: 1
    byte _padding_0x930[12];
    undefined4 field_0x93c; // accesses: 1
    undefined4 field_0x940; // accesses: 1
    undefined4 field_0x944; // accesses: 1
    undefined4 field_0x948; // accesses: 1
    byte _padding_0x94c[72];
    int field_0x994; // accesses: 1
    byte _padding_0x998[12];
    undefined4 field_0x9a4; // accesses: 1
    undefined4 field_0x9a8; // accesses: 1
    byte _padding_0x9ac[76];
    int * field_0x9f8; // accesses: 53
    byte _padding_0x9fc[60];
    undefined4 field_0xa38; // accesses: 1
    undefined4 field_0xa3c; // accesses: 1
    undefined4 field_0xa40; // accesses: 1
    undefined4 field_0xa44; // accesses: 1
    undefined4 field_0xa48; // accesses: 1
    int * field_0xa4c; // accesses: 5
    undefined4 field_0xa50; // accesses: 2
    uint field_0xa54; // accesses: 5
    undefined4 field_0xa58; // accesses: 3
    undefined4 field_0xa5c; // accesses: 4
    SRasterizeVertex * field_0xa60; // accesses: 8
    float field_0xa64; // accesses: 2
    float field_0xa68; // accesses: 5
    float field_0xa6c; // accesses: 5
    float field_0xa70; // accesses: 5
    byte _padding_0xa74[2084];
    CVisionViewportDx9 * field_0x1298; // accesses: 2
    byte _padding_0x129c[28];
    int field_0x12b8; // accesses: 2
    int field_0x12bc; // accesses: 2
    byte _padding_0x12c0[100];
    CVisionViewport * field_0x1324; // accesses: 2
    byte _padding_0x1328[4];
    CPlugShader * field_0x132c; // accesses: 2
    byte _padding_0x1330[324];
    CPlugFileGPUP * field_0x1474; // accesses: 1
    CPlugFileGPUP * field_0x1478; // accesses: 1
    CPlugFileGPUP * field_0x147c; // accesses: 1
    byte _padding_0x1480[32];
    CPlugFileGPUP * field_0x14a0; // accesses: 2
    CPlugFileGPUP * field_0x14a4; // accesses: 1
    CPlugFileGPUP * field_0x14a8; // accesses: 1
    byte _padding_0x14ac[64];
    CPlugFileGPUP * field_0x14ec; // accesses: 1
    byte _padding_0x14f0[16];
    CPlugFileGPUP * field_0x1500; // accesses: 1
    CPlugFileGPUP * field_0x1504; // accesses: 1
    CPlugFileGPUP * field_0x1508; // accesses: 1
    byte _padding_0x150c[16];
    CPlugShaderApply * field_0x151c; // accesses: 24
    byte _padding_0x1520[20];
    CPlugShaderApply * field_0x1534; // accesses: 3
    CPlugFileGPUV * field_0x1538; // accesses: 2
    byte _padding_0x153c[100];
    undefined4 field_0x15a0; // accesses: 1
    undefined4 field_0x15a4; // accesses: 4
    uint field_0x15a8; // accesses: 3
    undefined4 field_0x15ac; // accesses: 1
    byte _padding_0x15b0[36];
    CPlugTree * field_0x15d4; // accesses: 8
    byte _padding_0x15d8[12];
    undefined4 field_0x15e4; // accesses: 1
    byte _padding_0x15e8[8];
    undefined4 field_0x15f0; // accesses: 1
    undefined4 field_0x15f4; // accesses: 1
    undefined4 field_0x15f8; // accesses: 1
    undefined4 field_0x15fc; // accesses: 1
    undefined4 field_0x1600; // accesses: 1
    undefined4 field_0x1604; // accesses: 1
    undefined4 field_0x1608; // accesses: 1
    undefined4 field_0x160c; // accesses: 1
    undefined4 field_0x1610; // accesses: 1

    // Member Functions
    CPlugBitmap * __thiscall BitmapSpecularGetClose (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,float param_2,float param_3);
    CPlugBitmap * __thiscall BitmapSpecularsLAGetClose (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,float param_2,float param_3, float param_4);
    CPlugFileGPUV * __thiscall StdGpuVGet (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,EStdGpuV param_2,SStdGpuMask param_3 ,int param_4);
    CPlugFileGPUV * __thiscall StdGpuVLoad (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,EStdGpuV param_2,SStdGpuMask param_3 );
    CPlugShaderApply * __thiscall StdShaderGet (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,EStdShader2 param_2,ulong param_3);
    CPlugShaderApply * __thiscall StdShaderLoad (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,EStdShader2 param_2,ulong param_3);
    IDirect3DSurface9 * __thiscall SurfaceFind (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ESurface param_2,GmNat2 *param_3, _D3DFORMAT param_4,_D3DMULTISAMPLE_TYPE param_5);
    IDirect3DSurface9 * __thiscall SurfaceFindOrAdd (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ESurface param_2,GmNat2 *param_3, _D3DFORMAT param_4,_D3DMULTISAMPLE_TYPE param_5);
    SRasterizeVertex * __thiscall RasterizeQuadAdd (CVisionViewportDx9 *this,float param_1,float *param_3,float param_4,float param_5, float *param_6);
    int __thiscall ForceDeviceSynchro(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    int __thiscall RenderTargetPushEmpty(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    int __thiscall RenderTargetSet (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,IDirect3DSurface9 *param_2, IDirect3DSurface9 *param_3,CDx9TextureKeeper *param_4,CDx9TextureKeeper *param_5, ulong *param_6);
    int __thiscall Shadow_CanRenderInTexDepth(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    int __thiscall Shadow_ComputeFrustumLocation (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugVolumeShadow *param_2, ulong param_3);
    int __thiscall Shadow_ComputeWorldPrVolume (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugVolumeShadow *param_2, int param_3,GxLight *param_4,GmBoxAligned *param_5,SShadowCameraInter *param_6);
    int __thiscall TexRender_BlurHV (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2, CPlugBitmap *param_3,ulong *param_4,float param_5,float param_6,ulong param_7);
    int __thiscall TexRender_CubeBlur (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2, CPlugBitmap *param_3,ulong *param_4);
    int __thiscall TexRender_Gutter (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2, CPlugBitmap *param_3,ulong *param_4);
    int __thiscall TexRender_RenderTexture (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2, CPlugBitmapRender *param_3,CFixedArray<class_CPlugBitmap*,4,unsigned_long> *param_4);
    int __thiscall TexRender_UpdateTexture (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2);
    int __thiscall TextureMemoryMipFree (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ulong param_2,CPlugBitmap *param_3);
    void __thiscall BitmapStdInitAll(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    void __thiscall CVisionViewportDx9(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    void __thiscall ComputeAndSetCullMode (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,SHmsCameraLocation *param_2);
    void __thiscall NodBindFakeFid (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CMwNod *param_2, CFastStringInt *param_3);
    void __thiscall RasterizeConstruct(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    void __thiscall RasterizeQuadAlloc (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ulong param_2,int param_3);
    void __thiscall RasterizeQuadGetFullRect (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,GmRectAligned *param_2);
    void __thiscall RasterizeQuadSetUV1 (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,SRasterizeVertex *param_2, GmRectAligned *param_3);
    void __thiscall RasterizeQuads (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CDx9StateBlock *param_2);
    void __thiscall RenderShader (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugShader *param_2, CPlugVisual *param_3);
    void __thiscall RenderShaderOnFullQuad (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugShader *param_2, CPlugBitmap *param_3,SGxPixRect *param_4,CPlugVisual *param_5,SRenderShaderParam *param_6);
    void __thiscall RenderTargetClear (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ulong param_2,ulong param_3, float param_4,ulong param_5);
    void __thiscall RenderTargetExtraMrtSet (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ulong param_2, CDx9TextureKeeper *param_3);
    void __thiscall SetShaderForced (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugShader *param_2);
    void __thiscall SetStageTexture (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2,ulong param_3);
    void __thiscall Shadow_RenderCaster (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CHmsZone *param_2, CPlugVolumeShadow *param_3,ulong param_4,ulong param_5,GmBoxAligned *param_6, CPlugBitmapRenderShadow *param_7,GmVec4 *param_8,float *param_9);
    void __thiscall SyncGpuConstruct(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    void __thiscall TexRender_HemiAddQuad (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,SHemiInfo *param_2, GxLightNotAmbient *param_3,float param_4,GmVec3 *param_5);
    void __thiscall TexRender_Hemisphere (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2, CPlugBitmapRenderHemisphere *param_3);
    void __thiscall TexRender_LightFromMap (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2, CPlugBitmapRenderLightFromMap *param_3);
    void __thiscall TexRender_LightFromMap_Download (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2);
    void __thiscall TexRender_RasterizeLensFlares (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CHmsZone *param_2,GmMat4 *param_3, float param_4);
    void __thiscall TexRender_RenderTextureCube (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2);
    void __thiscall TexRender_UpdateTextures(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    void __thiscall TexRender_UpdateTextures_FromLastFrame_LightDepOnly (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    void __thiscall TexRender_Water_LDirSpecInA (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2, CPlugBitmapRenderWater *param_3,GmMat3 *param_4);
    void __thiscall TexRender_Water_PlaneR (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2, CPlugBitmapRender *param_3,GmVec4 *param_4,ulong param_5,int param_6);
    void __thiscall TextureBlitOnFullQuad (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2);
    void __thiscall TextureForcePixelUpdate (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugShader *param_2, CHmsCamera *param_3);
    void __thiscall TransformStackCameraPush (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CHmsCamera *param_2, CPlugBitmapRenderCamera *param_3,CPlugBitmapRenderVDepPlaneY *param_4);
    void __thiscall TriggerErrorOutOfMemory(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    void __thiscall ViewportSet (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,SHmsRenderRect *param_2);
    void __thiscall ViewportShrink1PixelBorder (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,float param_2,float param_3);
    void __thiscall VisibleZoneCleanShadowAndProjectors (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
    void __thiscall VisibleZonePrepareShadowAndProjectors (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1);
};

#endif // CVISIONVIEWPORTDX9_HPP
