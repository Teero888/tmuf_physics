#ifndef CDX9TEXTUREKEEPER_HPP
#define CDX9TEXTUREKEEPER_HPP

#include "typedefs.h"

struct CPlugBitmap;
struct CPlugFileImg;
struct CSystemFidFile;
struct CVisionViewportDx9;
struct ulong;

struct CDx9TextureKeeper {
    void** vftable; // accesses: 11
    undefined4 field_0x4; // accesses: 3
    CPlugFileImg * field_0x8; // accesses: 7
    CPlugBitmap * field_0xc; // accesses: 11
    int field_0x10; // accesses: 5
    undefined4 field_0x14; // accesses: 4
    char field_0x18; // accesses: 2
    byte _padding_0x19[3];
    uint field_0x1c; // accesses: 2
    byte field_0x20; // accesses: 18
    byte _padding_0x21[3];
    CDx9TextureKeeper * field_0x24; // accesses: 7
    CDx9TextureKeeper * field_0x28; // accesses: 8
    uint field_0x2c; // accesses: 1
    int field_0x30; // accesses: 4
    byte _padding_0x34[20];
    CPlugFileImg * field_0x48; // accesses: 5
    uint field_0x4c; // accesses: 8
    CVisionViewportDx9 field_0x4d; // accesses: 1
    uint field_0x50; // accesses: 2
    byte _padding_0x54[32];
    ulong field_0x74; // accesses: 7
    ulong field_0x78; // accesses: 6
    ulong field_0x7c; // accesses: 2
    undefined4 field_0x80; // accesses: 3
    undefined4 field_0x84; // accesses: 3

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
