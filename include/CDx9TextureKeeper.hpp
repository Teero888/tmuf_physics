#ifndef CDX9TEXTUREKEEPER_HPP
#define CDX9TEXTUREKEEPER_HPP

#include "typedefs.h"

struct CPlugFileImg;
struct CSystemFidFile;
struct CVisionViewportDx9;

struct CDx9TextureKeeper {
    byte _padding_0x0[2];
    ushort field_0x2; // accesses: 18
    undefined4 field_0x4; // accesses: 25
    ushort field_0x6; // accesses: 1
    float field_0x8; // accesses: 8
    undefined4 field_0xc; // accesses: 3
    int field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 3
    byte _padding_0x18[12];
    uint field_0x24; // accesses: 6
    byte _padding_0x28[32];
    int field_0x48; // accesses: 5
    uint field_0x4c; // accesses: 9
    CVisionViewportDx9 field_0x4d; // accesses: 1
    uint field_0x50; // accesses: 2
    byte _padding_0x54[32];
    int field_0x74; // accesses: 1
    byte _padding_0x78[388];
    int field_0x1fc; // accesses: 4
    undefined4 field_0x200; // accesses: 1
    undefined4 field_0x204; // accesses: 1
    byte _padding_0x208[8];
    int field_0x210; // accesses: 4
    byte _padding_0x214[44];
    int field_0x240; // accesses: 1
    byte _padding_0x244[788];
    uint field_0x558; // accesses: 1
    byte _padding_0x55c[372];
    int field_0x6d0; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl ResetCache(void);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpLoadTextureLevel (void *this,CDx9TextureKeeper *param_1,ulong param_2,ulong param_3, CVisionTexConverter *param_4,IDirect3DBaseTexture9 *param_5);
    IDirect3DSurface9 * __thiscall AutoGenMipMapGetSurface0(void *this,CDx9TextureKeeper *param_1);
    IDirect3DSurface9 * __thiscall RtWheelToCpuGetToRead(void *this,CDx9TextureKeeper *param_1);
    IDirect3DSurface9 * __thiscall RtWheelToCpuGetToWrite(void *this,CDx9TextureKeeper *param_1);
    int __thiscall RtWheelToCpuInit (void *this,CDx9TextureKeeper *param_1,GmNat2 *param_2,ulong param_3);
    int __thiscall RtWheelToCpuInitOne (void *this,CDx9TextureKeeper *param_1,SRtWheelToCpu *param_2,GmNat2 *param_3);
    int __thiscall UpLoadTexture(void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2);
    ulong __thiscall BiggerMipGetSizeToWin (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2,ulong *param_3);
    ulong __thiscall GetLevelByteSize (void *this,CDx9TextureKeeper *param_1,ulong param_2,ulong param_3);
    ulong __thiscall GetMipLevelSkipCountMax (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2);
    void __thiscall AddSkipLevelExtDelta (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2,int param_3,char *param_4);
    void __thiscall AutoGenMipMapSetDirty(void *this,CDx9TextureKeeper *param_1);
    void __thiscall BiggerMipLevelFree (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2,ulong param_3);
    void __thiscall RtWheelToCpuReleaseAll(void *this,CDx9TextureKeeper *param_1);
    void __thiscall RtWheelToCpusIssueQuery(void *this,CDx9TextureKeeper *param_1);
};

#endif // CDX9TEXTUREKEEPER_HPP
