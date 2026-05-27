#ifndef CDX9TEXTUREKEEPER_HPP
#define CDX9TEXTUREKEEPER_HPP

#include "typedefs.h"

struct CPlugFileImg;

struct CDx9TextureKeeper {
    void** vftable; // accesses: 10
    uint field_0x4; // accesses: 2
    CPlugFileImg * field_0x8; // accesses: 4
    int * field_0xc; // accesses: 11
    int field_0x10; // accesses: 5
    int field_0x14; // accesses: 4
    uint field_0x18; // accesses: 2
    uint field_0x1c; // accesses: 2
    uint field_0x20; // accesses: 18
    CDx9TextureKeeper * field_0x24; // accesses: 7
    CDx9TextureKeeper * field_0x28; // accesses: 8
    uint field_0x2c; // accesses: 1
    int field_0x30; // accesses: 4
    byte _padding_0x34[64];
    undefined4 field_0x74; // accesses: 6
    ulong field_0x78; // accesses: 6
    ulong field_0x7c; // accesses: 2
    undefined4 field_0x80; // accesses: 3
    undefined4 field_0x84; // accesses: 3

    // Member Functions
    IDirect3DSurface9 * __thiscall AutoGenMipMapGetSurface0(void *this,CDx9TextureKeeper *param_1);
    IDirect3DSurface9 * __thiscall RtWheelToCpuGetToRead(void *this,CDx9TextureKeeper *param_1);
    IDirect3DSurface9 * __thiscall RtWheelToCpuGetToWrite(void *this,CDx9TextureKeeper *param_1);
    int __thiscall RtWheelToCpuInit (void *this,CDx9TextureKeeper *param_1,GmNat2 *param_2,ulong param_3);
    int __thiscall RtWheelToCpuInitOne (void *this,CDx9TextureKeeper *param_1,SRtWheelToCpu *param_2,GmNat2 *param_3);
    int __thiscall UpLoadTexture(void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2);
    ulong __thiscall BiggerMipGetSizeToWin (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2,ulong *param_3);
    ulong __thiscall GetLevelByteSize (void *this,CDx9TextureKeeper *param_1,ulong param_2,ulong param_3);
    ulong __thiscall GetMipLevelSkipCountMax (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2);
    void __cdecl ResetCache(void);
    void __thiscall AddSkipLevelExtDelta (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2,int param_3,char *param_4);
    void __thiscall AutoGenMipMapSetDirty(void *this,CDx9TextureKeeper *param_1);
    void __thiscall BiggerMipLevelFree (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2,ulong param_3);
    void __thiscall RtWheelToCpuReleaseAll(void *this,CDx9TextureKeeper *param_1);
    void __thiscall RtWheelToCpusIssueQuery(void *this,CDx9TextureKeeper *param_1);
    void __thiscall UpLoadTextureLevel (void *this,CDx9TextureKeeper *param_1,ulong param_2,ulong param_3, CVisionTexConverter *param_4,IDirect3DBaseTexture9 *param_5);
};

#endif // CDX9TEXTUREKEEPER_HPP
